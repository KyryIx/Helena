#include "windows/windowbobbin.h"
#include "ui_windowbobbin.h"

#include <QMessageBox>

WindowBobbin::WindowBobbin(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowBobbin)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->init();
}

WindowBobbin::~WindowBobbin()
{
    delete ui;
}

void WindowBobbin::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowBobbin::clearFields(){
    ui->lineEdit_id->clear();
    ui->lineEdit_code->clear();
    ui->lineEdit_width->clear();
    ui->lineEdit_length->clear();
    ui->lineEdit_height->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_provider->clear();
}

void WindowBobbin::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_code->setText( this->database->returnValue( "code_bobbin" ).c_str() );
    ui->lineEdit_width->setText( this->database->returnValue( "width_bobbin" ).c_str() );
    ui->lineEdit_length->setText( this->database->returnValue( "length_bobbin" ).c_str() );
    ui->lineEdit_height->setText( this->database->returnValue( "height_bobbin" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_bobbin" ).c_str() );
    ui->lineEdit_provider->setText( this->database->returnValue( "provider_bobbin" ).c_str() );
}

void WindowBobbin::init(){
    this->clearFields();
    if( this->database->executeSQL( "SELECT * FROM bobbins ORDER BY id ASC" ) > -1 ){
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

void WindowBobbin::on_pushButton_before_clicked(){
    if( this->database->previousRegister() ){
        this->updateFields();
    }
}

void WindowBobbin::on_pushButton_after_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
    }
}

void WindowBobbin::on_pushButton_exit_clicked(){
    this->close();
}
