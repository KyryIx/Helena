#include "windowreport.h"
#include "ui_windowreport.h"

WindowReport::WindowReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowReport)
{
    ui->setupUi(this);
}

WindowReport::~WindowReport()
{
    delete ui;
}
