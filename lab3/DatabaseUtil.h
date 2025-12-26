#ifndef DATABASEUTIL_H
#define DATABASEUTIL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseUtil {
private:
    static DatabaseUtil* instance;
    QSqlDatabase db;

    // 私有构造函数（单例）
    DatabaseUtil() {

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:/lab3a.db");
        if (!db.open()) {
            qDebug() << "数据库打开失败：" << db.lastError().text();
        } else {
            qDebug() << "数据库连接成功";
            initTables(); // 初始化表（如果不存在）
        }
    };

    // 初始化表（患者、用户表）
void initTables() {
    QSqlQuery query;
    // 用户表（匹配User表结构）
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS User (
            ID TEXT PRIMARY KEY,
            FULLNAME TEXT,
            USERNAME TEXT UNIQUE NOT NULL,
            PASSWORD TEXT NOT NULL
        )
    )");
    // 患者表（匹配Patient表结构）
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS Patient (
            ID TEXT(32) PRIMARY KEY,
            ID_CARD TEXT(20) UNIQUE NOT NULL,
            NAME TEXT NOT NULL,
            SEX INTEGER,
            DOB TEXT,
            HEIGHT REAL,
            WEIGHT REAL,
            MOBILEPHONE TEXT,
            AGE INTEGER,
            CREATEDTIMESTAMP TEXT
        )
    )");
    // 操作记录表（History表）
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS History (
            ID TEXT PRIMARY KEY,
            USER_ID TEXT,
            EVENT TEXT,
            TIMESTAMP TEXT,
            FOREIGN KEY(USER_ID) REFERENCES User(ID)
        )
    )");
    // 科室表（Department表）
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS Department (
            ID TEXT PRIMARY KEY,
            NAME TEXT NOT NULL
        )
    )");
    // 医生表（Doctor表）
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS Doctor (
            ID TEXT PRIMARY KEY,
            EMPLOYEEENO TEXT,
            NAME TEXT NOT NULL,
            DEPARTMENT_ID TEXT,
            FOREIGN KEY(DEPARTMENT_ID) REFERENCES Department(ID)
        )
    )");
    // 初始化登录用户（匹配User表字段）
    query.exec("INSERT OR IGNORE INTO User(ID, FULLNAME, USERNAME, PASSWORD) VALUES('1', '管理员', 'admin', '123456')");
}

public:
    // 获取单例实例
    static DatabaseUtil* getInstance() {
        if (!instance) {
            instance = new DatabaseUtil();
        }
        return instance;
    }

    // 获取数据库连接
    QSqlDatabase getDb() {
        return db;
    }

    // 禁止拷贝
    DatabaseUtil(const DatabaseUtil&) = delete;
    void operator=(const DatabaseUtil&) = delete;
};

#endif // DATABASEUTIL_H
