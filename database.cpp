#include "database.h"

DataBase::DataBase()
{
    QString path = QCoreApplication::applicationDirPath() + QDir::separator() + "helena.db3";
    this->database = QSqlDatabase::addDatabase( "QSQLITE" );
    this->database.setDatabaseName( path );
    this->stateConnection = this->database.open();
    this->query = QSqlQuery( this->database );
}

bool DataBase::getStateConnection(){
    return this->stateConnection;
}

char DataBase::executeSQL( std::string sql ){
    if( this->getStateConnection() == false ){
        return -1;
    }

    this->query.clear();

    if( this->query.exec( "CREATE TABLE IF NOT EXISTS laminas( id INTEGER PRIMARY KEY AUTOINCREMENT, width_lamina DOUBLE, area_lamina DOUBLE, weight_lamina DOUBLE, type_lamina VARCHAR(64) )" ) == false ){
        return -2;
    }

    this->query.clear();

    if( this->query.exec( "CREATE TABLE IF NOT EXISTS bobbins( id INTEGER PRIMARY KEY AUTOINCREMENT, code_bobbin VARCHAR(64), width_bobbin DOUBLE, width_error_bobbin DOUBLE, length_bobbin DOUBLE, length_error_bobbin DOUBLE, height_bobbin DOUBLE, height_error_bobbin DOUBLE, type_bobbin VARCHAR(64), temperature_bobbin DOUBLE, provider_bobbin VARCHAR(255) )" ) == false ){
        return -3;
    }

    this->query.clear();

    if( this->query.exec( "CREATE TABLE IF NOT EXISTS wires ( id INTEGER PRIMARY KEY AUTOINCREMENT, type_wire VARCHAR(64), awg_wire VARCHAR(6), diameter_wire DOUBLE, turnsPerCm_wire DOUBLE, area_wire DOUBLE, resistance_wire DOUBLE, weight_wire DOUBLE, length_wire DOUBLE, currentMaxPerDensity_wire VARCHAR(255), frequency_wire DOUBLE, material_wire VARCHAR(64) )" ) == false ){
        return -4;
    }

    this->query.clear();

    if( this->query.exec( sql.c_str() ) == false ){
            return -4;
    }

    return 0;
}

int DataBase::numberRowsAffected(){
    return this->query.numRowsAffected();
}

int DataBase::numberRowsReturned(){
    return this->query.size();
}

bool DataBase::previousRegister(){
    return this->query.previous();
}

bool DataBase::nextRegister(){
    return this->query.next();
}

std::string DataBase::returnValue( std::string field ){
    return this->query.value( field.c_str() ).toString().toStdString();
}

void DataBase::clearQuery(){
    this->query.clear();
}

void DataBase::closeConnection(){
    this->database.close();
}
