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

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS transformer( id INTEGER PRIMARY KEY AUTOINCREMENT, frequency FLOAT, magneticInduction FLOAT, currentDensity FLOAT, averageCurrentDensity FLOAT, weigthIron FLOAT, weightCopper FLOAT, turnsAverageLength FLOAT, coilArea FLOAT, windowAreaPerSectionTurns FLOAT, ironLoss FLOAT, copperLoss FLOAT, totalLoss FLOAT, efficiency FLOAT, patternTransformer INTEGER, compensationLossTransformer FLOAT, powerIN FLOAT, voltageIN1 FLOAT, currentIN1 FLOAT, currentDensityIN1 FLOAT, wireIDIN1 INTEGER, wireTypeIN1 VARCHAR(16), wireAWGIN1 VARCHAR(5), wireTurnsIN1 INTEGER, wireDiameterIN1 FLOAT, wireTurnPerCmIN1 FLOAT, wireAreaIN1 FLOAT, wireResistanceIN1 FLOAT, wireWeightIN1 FLOAT, wireLengthIN1 FLOAT, wireFrequencyIN1 FLOAT, wireMaterialIN1 VARCHAR(64), voltageIN2 FLOAT, currentIN2 FLOAT, currentDensityIN2 FLOAT, wireIDIN2 INTEGER, wireTypeIN2 VARCHAR(16), wireAWGIN2 VARCHAR(5), wireTurnsIN2 INTEGER, wireDiameterIN2 FLOAT, wireTurnPerCmIN2 FLOAT, wireAreaIN2 FLOAT, wireResistanceIN2 FLOAT, wireWeightIN2 FLOAT, wireLengthIN2 FLOAT, wireFrequencyIN2 FLOAT, wireMaterialIN2 VARCHAR(64), powerOUT FLOAT, voltageOUT1 FLOAT, currentOUT1 FLOAT, currentDensityOUT1 FLOAT, wireIDOUT1 INTEGER, wireTypeOUT1 VARCHAR(16), wireAWGOUT1 VARCHAR(5), wireTurnsOUT1 INTEGER, wireDiameterOUT1 FLOAT, wireTurnPerCmOUT1 FLOAT, wireAreaOUT1 FLOAT, wireResistanceOUT1 FLOAT, wireWeightOUT1 FLOAT, wireLengthOUT1 FLOAT, wireFrequencyOUT1 FLOAT, wireMaterialOUT1 VARCHAR(64), voltageOUT2 FLOAT, currentOUT2 FLOAT, currentDensityOUT2 FLOAT, wireIDOUT2 INTEGER, wireTypeOUT2 VARCHAR(16), wireAWGOUT2 VARCHAR(5), wireTurnsOUT2 INTEGER, wireDiameterOUT2 FLOAT, wireTurnPerCmOUT2 FLOAT, wireAreaOUT2 FLOAT, wireResistanceOUT2 FLOAT, wireWeightOUT2 FLOAT, wireLengthOUT2 FLOAT, wireFrequencyOUT2 FLOAT, wireMaterialOUT2 VARCHAR(64), laminaID INTEGER, laminaType VARCHAR(64), laminaWidth FLOAT, laminaWindowArea FLOAT, laminaWeight FLOAT, laminaCompensation FLOAT, bobbinID INTEGER, bobbinType VARCHAR(64), bobbinCode VARCHAR(64), bobbinProvider VARCHAR(255), bobbinWidth FLOAT, bobbinLength FLOAT, bobbinHeight FLOAT, bobbinArea FLOAT )" ) == false ){
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
