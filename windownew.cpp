#include "windownew.h"
#include "ui_windownew.h"

WindowNew::WindowNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowNew)
{
    ui->setupUi(this);
}

WindowNew::~WindowNew()
{
    delete ui;
}
