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
        QString sql = "SELECT * FROM Patient";
        if (!keyword.isEmpty()) {
            sql += QString(" WHERE NAME LIKE '%%1%'").arg(keyword);
        }
        setQuery(sql, DatabaseUtil::getInstance()->getDb());
        if (lastError().isValid()) {
            qDebug() << "查询失败：" << lastError().text();
        }
    }

    // 添加患者
    bool addPatient(const QString& id, const QString& idCard, const QString& name,
                    int sex, const QString& dob, double height, double weight,
                    const QString& mobilePhone, int age, const QString& createTime) {
        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO Patient(ID, ID_CARD, NAME, SEX, DOB, HEIGHT, WEIGHT, MOBILEPHONE, AGE, CREATEDTIMESTAMP)
            VALUES(:id, :idCard, :name, :sex, :dob, :height, :weight, :mobilePhone, :age, :createTime)
        )");
        query.bindValue(":id", id);
        query.bindValue(":idCard", idCard);
        query.bindValue(":name", name);
        query.bindValue(":sex", sex);
        query.bindValue(":dob", dob);
        query.bindValue(":height", height);
        query.bindValue(":weight", weight);
        query.bindValue(":mobilePhone", mobilePhone);
        query.bindValue(":age", age);
        query.bindValue(":createTime", createTime);
        bool ok = query.exec();
        if (ok) refreshData();
        return ok;
    }

    // 修改患者
    bool updatePatient(const QString& id, const QString& idCard, const QString& name,
                       int sex, const QString& dob, double height, double weight,
                       const QString& mobilePhone, int age) {
        QSqlQuery query;
        query.prepare(R"(
            UPDATE Patient SET ID_CARD=:idCard, NAME=:name, SEX=:sex, DOB=:dob,
            HEIGHT=:height, WEIGHT=:weight, MOBILEPHONE=:mobilePhone, AGE=:age WHERE ID=:id
        )");
        query.bindValue(":id", id);
        query.bindValue(":idCard", idCard);
        query.bindValue(":name", name);
        query.bindValue(":sex", sex);
        query.bindValue(":dob", dob);
        query.bindValue(":height", height);
        query.bindValue(":weight", weight);
        query.bindValue(":mobilePhone", mobilePhone);
        query.bindValue(":age", age);
        bool ok = query.exec();
        if (ok) refreshData();
        return ok;
    }

    // 删除患者
    bool deletePatient(const QString& id) {
        QSqlQuery query;
        query.prepare("DELETE FROM Patient WHERE ID=:id");
        query.bindValue(":id", id);
        bool ok = query.exec();
        if (ok) refreshData();
        return ok;
    }
};

#endif // PATIENTMODEL_H
