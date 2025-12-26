#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include "DatabaseUtil.h"

class PatientModel : public QSqlQueryModel {
    Q_OBJECT
public:
    explicit PatientModel(QObject *parent = nullptr) : QSqlQueryModel(parent) {
        refreshData(); // 初始化加载数据
    }

    // 刷新患者列表
    void refreshData(const QString& keyword = "") {
        QString sql = "SELECT * FROM patient";
        if (!keyword.isEmpty()) {
            sql += QString(" WHERE name LIKE '%%1%'").arg(keyword);
        }
        setQuery(sql, DatabaseUtil::getInstance()->getDb());
        if (lastError().isValid()) {
            qDebug() << "查询失败：" << lastError().text();
        }
    }

    // 添加患者
    bool addPatient(const QString& name, const QString& idCard, const QString& gender,
                    const QString& birthDate, double height, double weight, const QString& phone) {
        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO patient(name, id_card, gender, birth_date, height, weight, phone)
            VALUES(:name, :idCard, :gender, :birthDate, :height, :weight, :phone)
        )");
        query.bindValue(":name", name);
        query.bindValue(":idCard", idCard);
        query.bindValue(":gender", gender);
        query.bindValue(":birthDate", birthDate);
        query.bindValue(":height", height);
        query.bindValue(":weight", weight);
        query.bindValue(":phone", phone);
        bool ok = query.exec();
        if (ok) refreshData();
        return ok;
    }

    // 修改患者
    bool updatePatient(int id, const QString& name, const QString& idCard, const QString& gender,
                       const QString& birthDate, double height, double weight, const QString& phone) {
        QSqlQuery query;
        query.prepare(R"(
            UPDATE patient SET name=:name, id_card=:idCard, gender=:gender, birth_date=:birthDate,
            height=:height, weight=:weight, phone=:phone WHERE id=:id
        )");
        query.bindValue(":id", id);
        query.bindValue(":name", name);
        query.bindValue(":idCard", idCard);
        query.bindValue(":gender", gender);
        query.bindValue(":birthDate", birthDate);
        query.bindValue(":height", height);
        query.bindValue(":weight", weight);
        query.bindValue(":phone", phone);
        bool ok = query.exec();
        if (ok) refreshData();
        return ok;
    }

    // 删除患者
    bool deletePatient(int id) {
        QSqlQuery query;
        query.prepare("DELETE FROM patient WHERE id=:id");
        query.bindValue(":id", id);
        bool ok = query.exec();
        if (ok) refreshData();
        return ok;
    }
};

#endif // PATIENTMODEL_H
