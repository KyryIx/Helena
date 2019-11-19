#include "windows/windowlamina.h"
#include "ui_windowlamina.h"

#include <QMessageBox>

WindowLamina::WindowLamina(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowLamina)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->init();
}

WindowLamina::~WindowLamina()
{
    delete ui;
}

void WindowLamina::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowLamina::clearFields(){
    ui->lineEdit_id->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_provider->clear();
    ui->lineEdit_width->clear();
    ui->lineEdit_weight->clear();
    ui->lineEdit_windowArea->clear();
    ui->lineEdit_thicknessPercent->clear();
}

void WindowLamina::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_lamina" ).c_str() );
    ui->lineEdit_provider->setText( this->database->returnValue( "provider_lamina" ).c_str() );
    ui->lineEdit_width->setText( this->database->returnValue( "width_lamina" ).c_str() );
    ui->lineEdit_weight->setText( this->database->returnValue( "weight_lamina" ).c_str() );
    ui->lineEdit_windowArea->setText( this->database->returnValue( "window_area_lamina" ).c_str() );
    ui->lineEdit_thicknessPercent->setText( this->database->returnValue( "thickness_percent_lamina" ).c_str() );
}

void WindowLamina::init(){
    this->clearFields();
    if( this->database->executeSQL( "SELECT * FROM laminas ORDER BY id ASC" ) > -1 ){
        this->on_pushButton_after_clicked();
    }
    else{
        QMessageBox msgBox;
        msgBox.setInformativeText( "Erro na consulta." );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowLamina::on_pushButton_before_clicked(){
    if( this->database->previousRegister() ){
        this->updateFields();
    }
}

void WindowLamina::on_pushButton_after_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
    }
}

void WindowLamina::on_pushButton_exit_clicked(){
    this->close();
}
