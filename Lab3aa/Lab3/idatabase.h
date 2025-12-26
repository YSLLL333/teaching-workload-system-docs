#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QDataWidgetMapper>
#include <QDateTime>
#include <QUuid>
#include <QDebug>

class IDatabase : public QObject
{
    Q_OBJECT
    // 私有构造：确保单例唯一
    explicit IDatabase(QObject *parent = nullptr);
    // 禁止拷贝/赋值
    IDatabase(const IDatabase &) = delete;
    IDatabase &operator=(const IDatabase &) = delete;

public:
    static IDatabase &getInstance()
    {
        static IDatabase instance;
        return instance;
    }

    // 对外核心接口
    QString userLogin(QString userName, QString password);
    bool initPatientModel();
    int addNewPatient();
    bool searchPatient(QString filter);
    bool deleteCurrentPatient();
    bool submitPatientEdit();
    void revertPatientEdit();

private:
    void initDatabase();

    QSqlDatabase m_database;
    QSqlTableModel *m_patientTabModel = nullptr;
    QItemSelectionModel *m_thePatientSelection = nullptr;

public:
    QSqlTableModel *patientTabModel() const
    {
        return m_patientTabModel;
    }
    QItemSelectionModel *thePatientSelection() const
    {
        return m_thePatientSelection;
    }
};

#endif // IDATABASE_H
