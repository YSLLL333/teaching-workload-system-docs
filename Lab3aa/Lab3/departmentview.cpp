#include "departmentview.h"
#include "ui_departmentview.h" // 关键：加载Ui::DepartmentView的完整定义

DepartmentView::DepartmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentView)
{
    ui->setupUi(this);
}

DepartmentView::~DepartmentView()
{
    delete ui;
}
