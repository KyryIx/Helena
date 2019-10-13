#ifndef DATABASE_H
#define DATABASE_H

// https://doc.qt.io/qt-5/qcoreapplication.html //
// https://doc.qt.io/qt-5/qdir.html //

// https://doc.qt.io/qt-5/qsqldatabase.html //
// https://doc.qt.io/qt-5/qsqlquery.html //
// https://doc.qt.io/qt-5/qsqlrecord.html //
// https://doc.qt.io/qt-5/qsqlresult.html //

// http://www.cplusplus.com/reference/string/string/ //

// https://katecpp.wordpress.com/2015/08/28/sqlite-with-qt/ //
// http://blog.davidecoppola.com/2016/11/howto-embed-database-in-application-with-sqlite-and-qt/ //

#include <QCoreApplication>
#include <QDir>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <string>

#include <QSqlResult>
#include <QSqlRecord>

#include <QVariant>

class DataBase
{
    public:
        DataBase(){
            QString path = QCoreApplication::applicationDirPath() + QDir::separator() + "helena.db3";
            this->database = QSqlDatabase::addDatabase( "QSQLITE" );
            this->database.setDatabaseName( path );
            this->stateConnection = this->database.open();
            this->query = QSqlQuery( this->database );
        }

        bool getStateConnection(){
            return this->stateConnection;
        }

        char executeSQL( std::string sql ){
            if( this->getStateConnection() == false ){
                return -1;
            }

            this->query.clear();

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS laminas( id INTEGER PRIMARY KEY AUTOINCREMENT, width_lamina DOUBLE, area_lamina DOUBLE, weight_lamina DOUBLE, thicknessPercent_lamina DOUBLE, type_lamina VARCHAR(64) )" ) == false ){
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

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS transformer( id INTEGER PRIMARY KEY AUTOINCREMENT, frequency FLOAT, magneticInduction FLOAT, currentDensity FLOAT, averageCurrentDensity FLOAT, weigthIron FLOAT, weightCopper FLOAT, turnsAverageLength FLOAT, coilArea FLOAT, ironLoss FLOAT, copperLoss FLOAT, totalLoss FLOAT, efficiency FLOAT, patternTransformer INTEGER, compensationLossTransformer FLOAT, voltageIN FLOAT, powerIN FLOAT, currentIN FLOAT, currentDensityIN FLOAT, wireIDIN INTEGER, wireAWGIN VARCHAR(5), wireTurnsIN INTEGER, wireDiameterIN FLOAT, wireTurnPerCmIN FLOAT, wireAreaIN FLOAT, wireResistanceIN FLOAT, wireWeightIN FLOAT, wireLengthIN FLOAT, wireFrequencyIN FLOAT, voltageOUT FLOAT, powerOUT FLOAT, currentOUT FLOAT, currentDensityOUT FLOAT, wireIDOUT INTEGER, wireAWGOUT VARCHAR(5), wireTurnsOUT INTEGER, wireDiameterOUT FLOAT, wireTurnPerCmOUT FLOAT, wireAreaOUT FLOAT, wireResistanceOUT FLOAT, wireWeightOUT FLOAT, wireLengthOUT FLOAT, wireFrequencyOUT FLOAT, laminaID INTEGER, laminaType VARCHAR(64), laminaWidth FLOAT, laminaWindowArea FLOAT, laminaWeight FLOAT, laminaCompensation FLOAT, bobbinID INTEGER, bobbinType VARCHAR(64), bobbinCode VARCHAR(64), bobbinProvider VARCHAR(255), bobbinWidth FLOAT, bobbinLength FLOAT, bobbinHeight FLOAT, bobbinArea FLOAT, bobbinVolume FLOAT, stateProject VARCHAR(64) )" ) == false ){
                return -5;
            }

            this->query.clear();

            if( this->query.exec( sql.c_str() ) == false ){
                    return -10;
            }

            return 0;
        }

        int numberRowsAffected(){
            return this->query.numRowsAffected();
        }

        int numberRowsReturned(){
            return this->query.size();
        }

        bool previousRegister(){
            return this->query.previous();
        }

        bool nextRegister(){
            return this->query.next();
        }

        std::string returnValue( std::string field ){
            return this->query.value( field.c_str() ).toString().toStdString();
        }

        void clearQuery(){
            this->query.clear();
        }

        void closeConnection(){
            this->database.close();
        }

    private:
        QSqlDatabase database;
        bool stateConnection;
        QSqlQuery query;
};

#endif // DATABASE_H
