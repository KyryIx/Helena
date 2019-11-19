#include "windows/windowwire.h"
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
    ui->lineEdit_material->clear();
    ui->lineEdit_provider->clear();
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

std::vector< std::vector<double> > WindowWire::string2Vector( std::string text, char separator ){
    std::vector< std::vector<double> > values;
    std::size_t found1, found2;
    found1 = 0;
    found2 = text.find( separator );
    std::vector<double> value;
    while( found2 != std::string::npos ){
        value.push_back( atof( text.substr( found1, (found2-found1) ).c_str() ) );
        if( value.size() == 2 ){
            values.push_back( value );
            value.clear();
        }
        found1 = found2 + 1;
        found2 = text.find( separator, found1 );
    }
    value.push_back( atof( text.substr( found1 ).c_str() ) );
    values.push_back( value );
    return values;
}

void WindowWire::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_wire" ).c_str() );
    ui->lineEdit_material->setText( this->database->returnValue( "material_wire" ).c_str() );
    ui->lineEdit_provider->setText( this->database->returnValue( "provider_wire" ).c_str() );
    ui->lineEdit_awg->setText( this->database->returnValue( "awg_wire" ).c_str() );
    ui->lineEdit_diameter->setText( this->database->returnValue( "diameter_wire" ).c_str() );
    ui->lineEdit_turnsPerCm->setText( this->database->returnValue( "turnsPerCm_wire" ).c_str() );
    ui->lineEdit_area->setText( this->database->returnValue( "area_wire" ).c_str() );
    ui->lineEdit_resistance->setText( this->database->returnValue( "resistance_wire" ).c_str() );
    ui->lineEdit_weight->setText( this->database->returnValue( "weight_wire" ).c_str() );
    ui->lineEdit_length->setText( this->database->returnValue( "length_wire" ).c_str() );
    ui->lineEdit_frequency->setText( this->database->returnValue( "frequency_wire" ).c_str() );
    std::vector< std::vector<double> > currentMax = this->string2Vector( this->database->returnValue( "currentMaxPerDensity_wire" ), ',' );
    for( unsigned int i=0; i<currentMax.size(); i++ ){
        ui->tableWidget_currentMax->insertRow( static_cast<int>(i) );
        for( unsigned int j=0; j<currentMax.at(i).size(); j++ ){
            QTableWidgetItem* item = new QTableWidgetItem( std::to_string( currentMax.at(i).at(j) ).c_str() );
            ui->tableWidget_currentMax->setItem( static_cast<int>(i), static_cast<int>(j), item );
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
