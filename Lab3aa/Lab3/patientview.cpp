#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"
#include <QMessageBox>

PatientView::PatientView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initPatientModel()) {
        ui->tableView->setModel(iDatabase.patientTabModel());
        ui->tableView->setSelectionModel(iDatabase.thePatientSelection());
    } else {
        QMessageBox::critical(this, "错误", "加载患者表失败！");
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentPatient();
}

void PatientView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewPatient();
    if (currow != -1) {
        emit goPatientEditView(currow);
    } else {
        QMessageBox::warning(this, "提示", "新增患者失败！");
    }
}

void PatientView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().thePatientSelection()->currentIndex();
    if (curIndex.isValid()) {
        emit goPatientEditView(curIndex.row());
    } else {
        QMessageBox::warning(this, "提示", "请先选中要编辑的患者！");
    }
}

void PatientView::on_btSearch_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchPatient(filter);
}
