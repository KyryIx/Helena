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

        bool getStateConnection() const{
            return this->stateConnection;
        }

        char executeSQL( std::string sql ){
            if( this->getStateConnection() == false ){
                return -1;
            }

            this->query.clear();

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS laminas( id INTEGER PRIMARY KEY AUTOINCREMENT, width_lamina DOUBLE, window_area_lamina DOUBLE, weight_lamina DOUBLE, compensation_percent_lamina DOUBLE, type_lamina VARCHAR(64), provider_lamina VARCHAR(255) )" ) == false ){
                return -2;
            }

            this->query.clear();

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS bobbins( id INTEGER PRIMARY KEY AUTOINCREMENT, code_bobbin VARCHAR(64), width_bobbin DOUBLE, length_bobbin DOUBLE, height_bobbin DOUBLE, type_bobbin VARCHAR(64), provider_bobbin VARCHAR(255) )" ) == false ){
                return -3;
            }

            this->query.clear();

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS wires( id INTEGER PRIMARY KEY AUTOINCREMENT, type_wire VARCHAR(64), awg_wire VARCHAR(6), diameter_wire DOUBLE, turnsPerCm_wire DOUBLE, area_wire DOUBLE, resistance_wire DOUBLE, weight_wire DOUBLE, length_wire DOUBLE, currentMaxPerDensity_wire VARCHAR(255), frequency_wire DOUBLE, material_wire VARCHAR(64), provider_wire VARCHAR(255) )" ) == false ){
                return -4;
            }

            if( this->query.exec( "CREATE TABLE IF NOT EXISTS transformers( id INTEGER PRIMARY KEY AUTOINCREMENT, frequency FLOAT, magnetic_induction FLOAT, current_density FLOAT, average_current_density FLOAT, weight_iron FLOAT, weight_copper FLOAT, average_turn_length FLOAT, copper_area FLOAT, window_area_per_section_copper FLOAT, iron_loss FLOAT, copper_loss FLOAT, total_loss FLOAT, efficiency FLOAT, transformer_pattern_number INTEGER, transformer_pattern_name VARCHAR(255), apply_center_tap BOOLEAN, apply_transformer_loss_compensation BOOLEAN, transformer_loss_compensation FLOAT, input_power FLOAT, input_voltage_1 FLOAT, input_current_1 FLOAT, input_current_density_1 FLOAT, input_wire_id_1 INTEGER, input_wire_type_1 VARCHAR(16), input_wire_awg_1 VARCHAR(5), input_wire_turns_1 INTEGER, input_wire_diameter_1 FLOAT, input_wire_turn_per_cm_1 FLOAT, input_wire_area_1 FLOAT, input_wire_resistance_1 FLOAT, input_wire_weight_1 FLOAT, input_wire_length_1 FLOAT, input_wire_frequency_1 FLOAT, input_wire_material_1 VARCHAR(64), input_wire_provider_1 VARCHAR(255), input_voltage_2 FLOAT, input_current_2 FLOAT, input_current_density_2 FLOAT, input_wire_id_2 INTEGER, input_wire_type_2 VARCHAR(16), input_wire_awg_2 VARCHAR(5), input_wire_turns_2 INTEGER, input_wire_diameter_2 FLOAT, input_wire_turn_per_cm_2 FLOAT, input_wire_area_2 FLOAT, input_wire_resistance_2 FLOAT, input_wire_weight_2 FLOAT, input_wire_length_2 FLOAT, input_wire_frequency_2 FLOAT, input_wire_material_2 VARCHAR(64), input_wire_provider_2 VARCHAR(255), output_power FLOAT, output_voltage_1 FLOAT, output_current_1 FLOAT, output_current_density_1 FLOAT, output_wire_id_1 INTEGER, output_wire_type_1 VARCHAR(16), output_wire_awg_1 VARCHAR(5), output_wire_turns_1 INTEGER, output_wire_diameter_1 FLOAT, output_wire_turn_per_cm_1 FLOAT, output_wire_area_1 FLOAT, output_wire_resistance_1 FLOAT, output_wire_weight_1 FLOAT, output_wire_length_1 FLOAT, output_wire_frequency_1 FLOAT, output_wire_material_1 VARCHAR(64), output_wire_provider_1 VARCHAR(255), output_voltage_2 FLOAT, output_current_2 FLOAT, output_current_density_2 FLOAT, output_wire_id_2 INTEGER, output_wire_type_2 VARCHAR(16), output_wire_awg_2 VARCHAR(5), output_wire_turns_2 INTEGER, output_wire_diameter_2 FLOAT, output_wire_turn_per_cm_2 FLOAT, output_wire_area_2 FLOAT, output_wire_resistance_2 FLOAT, output_wire_weight_2 FLOAT, output_wire_length_2 FLOAT, output_wire_frequency_2 FLOAT, output_wire_material_2 VARCHAR(64), output_wire_provider_2 VARCHAR(255), lamina_id INTEGER, lamina_type VARCHAR(64), lamina_provider VARCHAR(255), lamina_width FLOAT, lamina_window_area FLOAT, lamina_weight FLOAT, lamina_compensation_state BOOLEAN, lamina_compensation_value FLOAT, bobbin_id INTEGER, bobbin_type VARCHAR(64), bobbin_code VARCHAR(64), bobbin_provider VARCHAR(255), bobbin_width FLOAT, bobbin_length FLOAT, bobbin_height FLOAT, observation TEXT )" ) == false ){
                return -5;
            }

            this->query.clear();

            if( this->query.exec( sql.c_str() ) == false ){
                    return -10;
            }

            return 0;
        }

        int numberRowsAffected() const{
            return this->query.numRowsAffected();
        }

        int numberRowsReturned() const{
            return this->query.size();
        }

        bool queryIsValid() const{
            return this->query.isValid();
        }

        bool queryIsActive() const{
            return this->query.isActive();
        }

        bool firstRegister(){
            return this->query.first();
        }

        bool lastRegister(){
            return this->query.last();
        }

        bool previousRegister(){
            return this->query.previous();
        }

        bool nextRegister(){
            return this->query.next();
        }

        std::string returnValue( std::string field ) const{
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
