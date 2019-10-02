#include "windowwire.h"
#include "ui_windowwire.h"

#include <QMessageBox>

WindowWire::WindowWire(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowWire)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->init();
}

WindowWire::~WindowWire()
{
    delete ui;
}

void WindowWire::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowWire::clearFields(){
    ui->lineEdit_id->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_awg->clear();
    ui->lineEdit_diameter->clear();
    ui->lineEdit_turnsPerCm->clear();
    ui->lineEdit_area->clear();
    ui->lineEdit_resistance->clear();
    ui->lineEdit_weight->clear();
    ui->lineEdit_length->clear();
    ui->lineEdit_frequency->clear();
    ui->tableWidget_currentMax->setColumnWidth( 0, int(ui->tableWidget_currentMax->width() * 0.45) );
    ui->tableWidget_currentMax->setColumnWidth( 1, int(ui->tableWidget_currentMax->width() * 0.45) );
    while( ui->tableWidget_currentMax->rowCount() > 0 ){
        ui->tableWidget_currentMax->removeRow(0);
    }
}

void WindowWire::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_wire" ).c_str() );
    ui->lineEdit_awg->setText( this->database->returnValue( "awg_wire" ).c_str() );
    ui->lineEdit_diameter->setText( this->database->returnValue( "diameter_wire" ).c_str() );
    ui->lineEdit_turnsPerCm->setText( this->database->returnValue( "turnsPerCm_wire" ).c_str() );
    ui->lineEdit_area->setText( this->database->returnValue( "area_wire" ).c_str() );
    ui->lineEdit_resistance->setText( this->database->returnValue( "resistance_wire" ).c_str() );
    ui->lineEdit_weight->setText( this->database->returnValue( "weight_wire" ).c_str() );
    ui->lineEdit_length->setText( this->database->returnValue( "length_wire" ).c_str() );
    ui->lineEdit_frequency->setText( this->database->returnValue( "frequency_wire" ).c_str() );
    ui->lineEdit_material->setText( this->database->returnValue( "material_wire" ).c_str() );
    QStringList list = QString( this->database->returnValue( "currentMaxPerDensity_wire" ).c_str() ).split(';');
    for( int i=0; i<list.size(); i++ ){
        QStringList point = list.at(i).trimmed().split( "," );
        ui->tableWidget_currentMax->insertRow( i );
        for( int j=0; j<point.size(); j++ ){
            QTableWidgetItem* item = new QTableWidgetItem( point[j] );
            ui->tableWidget_currentMax->setItem( i, j, item );
        }
    }
}

void WindowWire::init(){
    this->clearFields();
    if( this->database->executeSQL( "SELECT * FROM wires ORDER BY id ASC" ) > -1 ){
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

void WindowWire::on_pushButton_before_clicked(){
    if( this->database->previousRegister() ){
        this->updateFields();
    }
}

void WindowWire::on_pushButton_after_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
    }
}

void WindowWire::on_pushButton_exit_clicked(){
    this->close();
}
