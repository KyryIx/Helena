#include "windows/windowpreference.h"
#include "ui_windowpreference.h"

#include <QMessageBox>

WindowPreference::WindowPreference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowPreference)
{
    ui->setupUi(this);
}

WindowPreference::~WindowPreference()
{
    delete ui;
}

void WindowPreference::on_pushButton_save_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Salvamento OK." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
    this->close();
}

void WindowPreference::on_pushButton_cancel_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Cancelamento OK." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
    this->close();
}
