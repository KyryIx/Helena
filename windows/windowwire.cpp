#include "windows/windowwire.h"
#include "ui_windowwire.h"

#include <QMessageBox>

#define table "wires"

WindowWire::WindowWire(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowWire)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->wire = new Wire();
    this->init();
}

WindowWire::~WindowWire()
{
    delete ui;
}

void WindowWire::setDatabase( DataBase *database ){
    this->database = database;
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

void WindowWire::updateWire(){
    wire->setId( ui->lineEdit_id->text().toUInt() );
    wire->setType( ui->lineEdit_type->text().toStdString() );
    wire->setAWG( ui->lineEdit_awg->text().toStdString() );
    wire->setDiameter( ui->lineEdit_diameter->text().toDouble() );
    wire->setTurnsPerCm( ui->lineEdit_turnsPerCm->text().toDouble() );
    wire->setArea( ui->lineEdit_area->text().toDouble() );
    wire->setResistance( ui->lineEdit_resistance->text().toDouble() );
    wire->setWeight( ui->lineEdit_weight->text().toDouble() );
    wire->setLength( ui->lineEdit_length->text().toDouble() );
    wire->setFrequency( ui->lineEdit_frequency->text().toDouble() );
    wire->setMaterial( ui->lineEdit_material->text().toStdString() );
    wire->setProvider( ui->lineEdit_provider->text().toStdString() );
    int x = ui->tableWidget_currentMax->columnCount();
    int y = ui->tableWidget_currentMax->rowCount();
    std::vector< std::vector< double > > rows;
    for( int j=0; j<y; j++ ){
        std::vector< double > colums;
        for( int i=0; i<x; i++ ){
            colums.push_back( ui->tableWidget_currentMax->item( j, i )->text().toDouble() );
        }
        rows.push_back( colums );
    }
    wire->setCurrentMax( rows );
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
        this->updateWire();
    }
}

void WindowWire::on_pushButton_after_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
        this->updateWire();
    }
}

void WindowWire::on_pushButton_update_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente atualizar o fio aberto." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        std::string sql = "UPDATE ";
        sql += table;
        sql += " SET ";
        unsigned char size = static_cast<unsigned char>( sql.size() );
        const double precision = 1e-5;

        if( this->wire->getId() != ui->lineEdit_id->text().toUInt() ){
            return;
        }

        if( this->wire->getType() != ui->lineEdit_type->text().toStdString() ){
            sql += "type_wire='" + ui->lineEdit_type->text().toStdString() + "', ";
        }

        if( this->wire->getAWG() != ui->lineEdit_awg->text().toStdString() ){
            sql += "awg_wire='" + ui->lineEdit_awg->text().toStdString() + "', ";
        }

        if( fabs( this->wire->getDiameter() - ui->lineEdit_diameter->text().toDouble() ) >= precision ){
            sql += "diameter_wire=" + ui->lineEdit_diameter->text().toStdString() + ", ";
        }

        if( fabs( this->wire->getTurnsPerCm() - ui->lineEdit_turnsPerCm->text().toDouble() ) >= precision ){
            sql += "turnsPerCm_wire=" + ui->lineEdit_turnsPerCm->text().toStdString() + ", ";
        }

        if( fabs( this->wire->getArea() - ui->lineEdit_area->text().toDouble() ) >= precision ){
            sql += "area_wire=" + ui->lineEdit_area->text().toStdString() + ", ";
        }

        if( fabs( this->wire->getResistance() - ui->lineEdit_resistance->text().toDouble() ) >= precision ){
            sql += "resistance_wire=" + ui->lineEdit_resistance->text().toStdString() + ", ";
        }

        if( fabs( this->wire->getWeight() - ui->lineEdit_weight->text().toDouble() ) >= precision ){
            sql += "weight_wire=" + ui->lineEdit_weight->text().toStdString() + ", ";
        }

        if( fabs( this->wire->getFrequency() - ui->lineEdit_frequency->text().toDouble() ) >= precision ){
            sql += "frequency_wire=" + ui->lineEdit_frequency->text().toStdString() + ", ";
        }

        if( this->wire->getMaterial() != ui->lineEdit_material->text().toStdString() ){
            sql += "material_wire='" + ui->lineEdit_material->text().toStdString() + "', ";
        }

        if( this->wire->getProvider() != ui->lineEdit_provider->text().toStdString() ){
            sql += "provider_wire='" + ui->lineEdit_provider->text().toStdString() + "', ";
        }

        // implementar
        //if( fabs( this->wire->getCurrentMax() - ui->lineEdit_length->text().toDouble() ) >= precision ){
        //    sql += "currentMaxPerDensity_wire=" + ui->lineEdit_length->text().toStdString() + ", ";
        //}

        if( sql.size() > size ){
            sql = sql.substr( 0, sql.size()-2 );
            sql += " WHERE id=" + std::to_string( this->wire->getId() );

            if( this->database->executeSQL( sql ) > -1 ){
                msgBox.setInformativeText( "Atualização feita com sucesso." );
                msgBox.setIcon( QMessageBox::Information );
                this->init();
            }
            else{
                msgBox.setInformativeText( "Erro na consulta." );
                msgBox.setIcon( QMessageBox::Warning );
            }
        }
        else{
            msgBox.setInformativeText( "Os valores nos campos são idênticos aos armazenados na base de dados." );
            msgBox.setIcon( QMessageBox::Warning );
        }

        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowWire::on_pushButton_exit_clicked(){
    this->close();
}
