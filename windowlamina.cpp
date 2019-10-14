#include "windowlamina.h"
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
    ui->lineEdit__width->clear();
    ui->lineEdit_area->clear();
    ui->lineEdit_weight->clear();
    ui->lineEdit_type->clear();
    ui->textEdit_observation->clear();
}

void WindowLamina::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit__width->setText( this->database->returnValue( "width_lamina" ).c_str() );
    ui->lineEdit_area->setText( this->database->returnValue( "area_lamina" ).c_str() );
    ui->lineEdit_weight->setText( this->database->returnValue( "weight_lamina" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_lamina" ).c_str() );
    ui->lineEdit_thicknessPercent->setText( this->database->returnValue( "thicknessPercent_lamina" ).c_str() );
    //ui->textEdit_observation->setText( this->database->returnValue( "observation_lamina" ).c_str() );
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
