#include "windows/windowabout.h"
#include "ui_windowabout.h"

WindowAbout::WindowAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowAbout)
{
    ui->setupUi(this);
}

WindowAbout::~WindowAbout()
{
    delete ui;
}
