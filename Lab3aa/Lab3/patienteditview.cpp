#include "patienteditview.h"
#include "ui_patienteditview.h"
#include "idatabase.h"
#include <QSqlTableModel>
#include <QMessageBox>

PatientEditView::PatientEditView(QWidget *parent, int index) :
    QWidget(parent),
    ui(new Ui::PatientEditView)
{
    ui->setupUi(this);
    dataMapper = new QDataWidgetMapper(this);

    IDatabase &db = IDatabase::getInstance();
    QSqlTableModel *tabModel = db.patientTabModel();
    if (!tabModel) {
        QMessageBox::critical(this, "错误", "患者模型未初始化！");
        return;
    }

    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);

    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditIDCard, tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->dbSpinHeight, tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->dbSpinWeight, tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbEditMobile, tabModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->dbDateEditDOB, tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->dbComboSex, tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->dbCreatedTimeStamp, tabModel->fieldIndex("CREATEDTIMESTAMP"));

    dataMapper->setCurrentIndex(index);
    ui->dbEditID->setEnabled(false);
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_pushButton_clicked()
{
    if (ui->dbEditName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "姓名不能为空！");
        return;
    }
    if (ui->dbEditIDCard->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "身份证号不能为空！");
        return;
    }

    dataMapper->submit();

    bool submitOk = IDatabase::getInstance().submitPatientEdit();
    if (submitOk) {
        emit goPreviousView();
    } else {
        QMessageBox::critical(this, "错误", "数据提交失败！请查看控制台日志。");
    }
}

void PatientEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertPatientEdit();
    emit goPreviousView();
}
