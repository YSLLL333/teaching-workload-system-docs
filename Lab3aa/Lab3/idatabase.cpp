#include "idatabase.h"

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    initDatabase();
}

void IDatabase::initDatabase()
{
    const QString connName = "PatientDB";
    if (QSqlDatabase::contains(connName)) {
        m_database = QSqlDatabase::database(connName);
    } else {
        m_database = QSqlDatabase::addDatabase("QSQLITE", connName);
    }

    QString dbPath = "D:/Lab3a.db";
    m_database.setDatabaseName(dbPath);

    if (!m_database.open()) {
        qCritical() << "[数据库错误] 打开失败：" << m_database.lastError().text()
                    << "路径：" << dbPath;
    } else {
        qInfo() << "[数据库成功] 已打开：" << connName << "路径：" << dbPath;
    }
}

bool IDatabase::initPatientModel()
{
    if (m_patientTabModel) {
        return true;
    }

    if (!m_database.isOpen()) {
        qCritical() << "[模型错误] 数据库未打开，无法初始化模型";
        return false;
    }

    m_patientTabModel = new QSqlTableModel(this, m_database);
    m_patientTabModel->setTable("patient");
    m_patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    int nameIdx = m_patientTabModel->fieldIndex("name");
    if (nameIdx != -1) {
        m_patientTabModel->setSort(nameIdx, Qt::AscendingOrder);
    }

    if (!m_patientTabModel->select()) {
        qCritical() << "[模型错误] 加载patient表失败：" << m_patientTabModel->lastError().text();
        delete m_patientTabModel;
        m_patientTabModel = nullptr;
        return false;
    }

    m_thePatientSelection = new QItemSelectionModel(m_patientTabModel);
    qInfo() << "[模型成功] 加载patient表，共" << m_patientTabModel->rowCount() << "行";
    return true;
}

int IDatabase::addNewPatient()
{
    if (!m_patientTabModel || !m_database.isOpen()) {
        qCritical() << "[新增错误] 模型/数据库未初始化";
        return -1;
    }

    int newRow = m_patientTabModel->rowCount();
    if (!m_patientTabModel->insertRow(newRow)) {
        qCritical() << "[新增错误] 插入行失败：" << m_patientTabModel->lastError().text();
        return -1;
    }

    int idColIndex = m_patientTabModel->fieldIndex("ID");
    int createTimeColIndex = m_patientTabModel->fieldIndex("CREATEDTIMESTAMP");
    int nameColIndex = m_patientTabModel->fieldIndex("NAME");
    int idCardColIndex = m_patientTabModel->fieldIndex("ID_CARD");

    if (idColIndex == -1) {
        qCritical() << "[新增错误] 未找到ID字段！请检查数据库表结构";
        m_patientTabModel->removeRow(newRow);
        return -1;
    }

    QString uniqueID = QUuid::createUuid().toString(QUuid::WithoutBraces);
    bool idSetOk = m_patientTabModel->setData(m_patientTabModel->index(newRow, idColIndex), uniqueID);
    if (!idSetOk) {
        qCritical() << "[新增错误] ID字段赋值失败：" << m_patientTabModel->lastError().text();
        m_patientTabModel->removeRow(newRow);
        return -1;
    }

    m_patientTabModel->setData(m_patientTabModel->index(newRow, createTimeColIndex),
                               QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    m_patientTabModel->setData(m_patientTabModel->index(newRow, nameColIndex), "");
    m_patientTabModel->setData(m_patientTabModel->index(newRow, idCardColIndex), "");

    QVariant idValue = m_patientTabModel->data(m_patientTabModel->index(newRow, idColIndex));
    if (idValue.isNull() || idValue.toString().isEmpty()) {
        qCritical() << "[新增错误] ID赋值后仍为空！字段名/表名不匹配";
        m_patientTabModel->removeRow(newRow);
        return -1;
    }
    qInfo() << "[新增成功] 内存中新增行，索引：" << newRow << "，ID：" << uniqueID;

    return newRow;
}

bool IDatabase::submitPatientEdit()
{
    if (!m_patientTabModel || !m_database.isOpen()) {
        qCritical() << "[提交错误] 模型/数据库未初始化";
        return false;
    }

    int idColIndex = m_patientTabModel->fieldIndex("ID");
    if (idColIndex == -1) {
        qCritical() << "[提交错误] 未找到ID字段";
        return false;
    }
    for (int i = 0; i < m_patientTabModel->rowCount(); i++) {
        QVariant idValue = m_patientTabModel->data(m_patientTabModel->index(i, idColIndex));
        if (idValue.isNull() || idValue.toString().trimmed().isEmpty()) {
            qCritical() << "[提交错误] 第" << i << "行ID为空，禁止提交";
            return false;
        }
    }

    bool ok = m_patientTabModel->submitAll();
    if (ok) {
        m_patientTabModel->select();
        qInfo() << "[提交成功] 数据已写入数据库";
    } else {
        QSqlError err = m_patientTabModel->lastError();
        qCritical() << "[提交失败] 错误文本：" << err.text()
                    << "驱动错误：" << err.driverText()
                    << "数据库错误：" << err.databaseText();
        m_patientTabModel->revertAll();
    }
    return ok;
}

void IDatabase::revertPatientEdit()
{
    if (m_patientTabModel) {
        m_patientTabModel->revertAll();
        qInfo() << "[回滚成功] 已撤销所有未提交修改";
    }
}

bool IDatabase::deleteCurrentPatient()
{
    if (!m_patientTabModel || !m_thePatientSelection || !m_database.isOpen()) {
        qCritical() << "[删除错误] 模型/选择模型/数据库未初始化";
        return false;
    }

    QModelIndex curIdx = m_thePatientSelection->currentIndex();
    if (!curIdx.isValid()) {
        qWarning() << "[删除错误] 未选中任何行";
        return false;
    }

    if (!m_patientTabModel->removeRow(curIdx.row())) {
        qCritical() << "[删除错误] 移除行失败：" << m_patientTabModel->lastError().text();
        return false;
    }

    bool ok = m_patientTabModel->submitAll();
    if (ok) {
        m_patientTabModel->select();
        qInfo() << "[删除成功] 已删除行：" << curIdx.row();
    } else {
        qCritical() << "[删除失败] 提交失败：" << m_patientTabModel->lastError().text();
        m_patientTabModel->revertAll(); // 回滚
    }
    return ok;
}

bool IDatabase::searchPatient(QString filter)
{
    if (!m_patientTabModel) return false;
    m_patientTabModel->setFilter(filter);
    bool ok = m_patientTabModel->select();
    if (!ok) {
        qCritical() << "[搜索错误] 筛选失败：" << m_patientTabModel->lastError().text();
    }
    return ok;
}

QString IDatabase::userLogin(QString userName, QString password)
{
    if (!m_database.isOpen()) {
        qCritical() << "[登录错误] 数据库未打开";
        return "dbError";
    }

    QSqlQuery query(m_database);
    query.prepare("SELECT username,password FROM user WHERE username=:USER");
    query.bindValue(":USER", userName);

    if (!query.exec()) {
        qCritical() << "[登录错误] 查询失败：" << query.lastError().text();
        return "queryError";
    }

    if (query.first() && query.value("username").isValid()) {
        QString pwd = query.value("password").toString();
        return (pwd == password) ? "loginOK" : "wrongPassword";
    } else {
        return "wrongUsername";
    }
}
