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
    this->stateInsert = 0;
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
    this->wire->setId( ui->lineEdit_id->text().toUInt() );
    this->wire->setType( ui->lineEdit_type->text().toStdString() );
    this->wire->setAWG( ui->lineEdit_awg->text().toStdString() );
    this->wire->setDiameter( ui->lineEdit_diameter->text().toDouble() );
    this->wire->setTurnsPerCm( ui->lineEdit_turnsPerCm->text().toDouble() );
    this->wire->setArea( ui->lineEdit_area->text().toDouble() );
    this->wire->setResistance( ui->lineEdit_resistance->text().toDouble() );
    this->wire->setWeight( ui->lineEdit_weight->text().toDouble() );
    this->wire->setLength( ui->lineEdit_length->text().toDouble() );
    this->wire->setFrequency( ui->lineEdit_frequency->text().toDouble() );
    this->wire->setMaterial( ui->lineEdit_material->text().toStdString() );
    this->wire->setProvider( ui->lineEdit_provider->text().toStdString() );
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
    this->wire->setCurrentMax( rows );
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

void WindowWire::on_pushButton_currentAddDown_clicked(){
    int currentRow = ui->tableWidget_currentMax->currentRow() + 1;
    ui->tableWidget_currentMax->insertRow(currentRow);
}

void WindowWire::on_pushButton_currentAddUp_clicked(){
    int currentRow = ui->tableWidget_currentMax->currentRow();
    ui->tableWidget_currentMax->insertRow(currentRow);
    int nRows = ui->tableWidget_currentMax->rowCount();
    for( int i=1; i<=nRows; i++ ){
        QTableWidgetItem* item = new QTableWidgetItem(QTableWidgetItem::Type);
        item->setText( std::to_string(i).c_str() );
        ui->tableWidget_currentMax->setVerticalHeaderItem( i-1, item );
    }
}

void WindowWire::on_pushButton_currentDelete_clicked(){
    int currentRow = ui->tableWidget_currentMax->currentRow();
    ui->tableWidget_currentMax->removeRow( currentRow );
}

void WindowWire::on_pushButton_first_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->firstRegister() ){
            this->updateFields();
            this->updateWire();
        }
    }
}

void WindowWire::on_pushButton_last_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->lastRegister() ){
            this->updateFields();
            this->updateWire();
        }
    }
}

void WindowWire::on_pushButton_before_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->previousRegister() ){
            this->updateFields();
            this->updateWire();
        }
    }
}

void WindowWire::on_pushButton_after_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->nextRegister() ){
            this->updateFields();
            this->updateWire();
        }
    }
}

void WindowWire::on_pushButton_update_clicked(){
    this->setStateInsert( 0 );
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
            msgBox.setInformativeText( "Dados em branco. Use a opção de \"Inserir Novo\"" );
            msgBox.setStandardButtons( QMessageBox::Ok );
            msgBox.exec();
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

        size_t numberRows = static_cast<size_t>( ui->tableWidget_currentMax->rowCount() );
        std::vector< std::vector<double> > currentMax;
        for( size_t i=0; i<numberRows; i++ ){
            QTableWidgetItem* density = ui->tableWidget_currentMax->item( int(i), 0 );
            if( density->text().trimmed() == "" ){
                msgBox.setInformativeText( "Campo(s) de densidade de corrente em branco(s)." );
                msgBox.setIcon( QMessageBox::Warning );
                msgBox.setStandardButtons( QMessageBox::Ok );
                msgBox.exec();
                return;
            }

            QTableWidgetItem* current = ui->tableWidget_currentMax->item( int(i), 1 );
            if( current->text().trimmed() == "" ){
                msgBox.setInformativeText( "Campo(s) de corrente em branco(s)." );
                msgBox.setIcon( QMessageBox::Warning );
                msgBox.setStandardButtons( QMessageBox::Ok );
                msgBox.exec();
                return;
            }

            std::vector<double> values;
            values.push_back( density->text().toDouble() );
            values.push_back( current->text().toDouble() );
            currentMax.push_back( values );
        }
        if( this->wire->getCurrentMax() != currentMax ){
            sql += "currentMaxPerDensity_wire='";
            size_t sizeTemp = sql.size();
            for( size_t i=0; i<numberRows; i++ ){
                sql += std::to_string( currentMax.at(i).at(0) ) + "," + std::to_string( currentMax.at(i).at(1) ) + ", ";
            }
            if( sql.size() > sizeTemp ){
                sql = sql.substr( 0, sql.size()-2 );
            }

            sql += "', ";
        }

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

void WindowWire::setStateInsert( unsigned char state ){
    switch( state ){
        case 0:
            ui->pushButton_insert->setText( "Inserir Novo" );
            this->stateInsert = 0;
            break;

        case 1:
            ui->pushButton_insert->setText( "Salvar" );
            this->stateInsert = 1;
            break;
    }
}

void WindowWire::on_pushButton_insert_clicked(){
    switch( this->stateInsert ){
        case 0:
        {
            QMessageBox msgBox;
            msgBox.setInformativeText( "Deseja campos em branco?" );
            msgBox.setIcon( QMessageBox::Warning );
            msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
            if( msgBox.exec() == QMessageBox::Ok ){
                this->clearFields();
            }
            this->setStateInsert( 1 );
            break;
        }

        case 1:
        {
            QMessageBox msgBox;
            msgBox.setInformativeText( "Deseja salvar mesmo?" );
            msgBox.setIcon( QMessageBox::Warning );
            msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
            if( msgBox.exec() == QMessageBox::Ok ){
                msgBox.setIcon( QMessageBox::Warning );
                msgBox.setStandardButtons( QMessageBox::Ok );

                Wire* wire = new Wire();
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
                int numberRows = ui->tableWidget_currentMax->rowCount();
                std::vector< std::vector<double> > currentMax;
                for( int i=0; i<numberRows; i++ ){
                    QTableWidgetItem* density = ui->tableWidget_currentMax->item( i, 0 );
                    if( density->text().trimmed() == "" ){
                        msgBox.setInformativeText( "Campo(s) de densidade de corrente em branco(s)." );
                        msgBox.exec();
                        return;
                    }

                    QTableWidgetItem* current = ui->tableWidget_currentMax->item( i, 1 );
                    if( current->text().trimmed() == "" ){
                        msgBox.setInformativeText( "Campo(s) de corrente em branco(s)." );
                        msgBox.exec();
                        return;
                    }

                    std::vector<double> values;
                    values.push_back( density->text().toDouble() );
                    values.push_back( current->text().toDouble() );
                    currentMax.push_back( values );
                }
                wire->setCurrentMax( currentMax );

                if( this->database->executeSQL( wire->toSQL() ) > -1 ){
                    this->on_pushButton_after_clicked();
                    msgBox.setInformativeText( "Salvamento feito com sucesso." );
                    msgBox.setIcon( QMessageBox::Information );
                    this->init();
                }
                else{
                    msgBox.setInformativeText( "Erro na consulta." );
                }

                msgBox.exec();
            }
            this->setStateInsert( 0 );
            break;
        }
    }
}

void WindowWire::on_pushButton_delete_clicked(){
    this->setStateInsert( 0 );
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente excluir o fio aberto?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        int id = ui->lineEdit_id->text().toInt();
        if( id > 0 ){
            std::string sql = "DELETE FROM ";
            sql += table;
            sql += " WHERE id=" + std::to_string(id);
            if( this->database->executeSQL( sql ) > -1 ){
                this->on_pushButton_after_clicked();
                msgBox.setInformativeText( "Exclusão feita com sucesso." );
                msgBox.setIcon( QMessageBox::Information );
                this->init();
            }
            else{
                msgBox.setInformativeText( "Erro na consulta." );
                msgBox.setIcon( QMessageBox::Warning );
            }
        }
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowWire::on_pushButton_exit_clicked(){
    this->setStateInsert( 0 );
    this->close();
}
