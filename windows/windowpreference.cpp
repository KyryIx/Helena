#include "windows/windowpreference.h"
#include "ui_windowpreference.h"

#include <QDir>

WindowPreference::WindowPreference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowPreference)
{
    ui->setupUi(this);
    ui->lineEdit_pathDatabase->setText( QDir::currentPath() + "/helena.db3" );
    ui->lineEdit_tableTransformers->setText( "transformers" );
    ui->lineEdit_tableBobbins->setText( "bobbins" );
    ui->lineEdit_tableLaminas->setText( "laminas" );
    ui->lineEdit_tableWires->setText( "wires" );
}

WindowPreference::~WindowPreference()
{
    delete ui;
}

void WindowPreference::on_pushButton_ok_clicked(){
    this->close();
}
