#ifndef LAMINAS_H
#define LAMINAS_H

#include "lamina.h"
#include "database.h"

class Laminas{
    private:
        DataBase* database;

        std::string comparation( char option_comparation ){
            std::string str = "";
            switch( option_comparation ){
                case 'e': // equal //
                    str = "=";
                    break;
                case 'l': // less //
                    str = "<=";
                    break;
                case 'g': // greater //
                default:
                    str = ">=";
            }
            return str;
        }

        std::string queryByIndex( unsigned int index, std::string field ){
            // SELECT
            //         [field]
            // FROM
            //         laminas
            // WHERE
            //         id=[index]
            std::string sql = "";
            sql = sql + "SELECT " + field + " ";
            sql = sql + "FROM laminas ";
            sql = sql + "WHERE id=" + std::to_string( index );
            return sql;
        }

        std::string queryByTypeAndField( std::string type, std::string field, double value, char comparation, std::string order="ASC" ){
            // SELECT
            //          id
            // FROM
            //          laminas
            // WHERE
            //          (type_lamina='[type]')
            //          AND
            //          ([field][comparation][value])
            // ORDER BY
            //          [field] [order]
            // LIMIT 1
            std::string sql = "";
            sql = sql + "SELECT id ";
            sql = sql + "FROM laminas ";
            sql = sql + "WHERE (type_lamina='" + type + "') ";
            sql = sql + "AND ";
            sql = sql + "(" + field + this->comparation( comparation ) + std::to_string( value ) + ") ";
            sql = sql + "ORDER BY " + field + " " + order + " LIMIT 1";
            return sql;
        }

    public:
        Laminas( DataBase *database ){
            this->database = database;
        }

        void setDatabase( DataBase *database ){
            this->database = database;
        }

        std::string getType( unsigned int index ){
            std::string type_tmp = "";
            // SELECT type_lamina FROM laminas WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "type_lamina" ) ) > -1 ){
                if( this->database->nextRegister() ){
                        type_tmp = this->database->returnValue( "type_lamina" ).c_str();
                }
            }
            return type_tmp;
        }

        double getWidth( unsigned int index ){
            double thickness = 0.0;
            // SELECT width_lamina FROM laminas WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "width_lamina" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    thickness = atof( this->database->returnValue( "width_lamina" ).c_str() );
                }
            }
            return thickness;
        }

        double getWindowArea( unsigned int index ){
            double windowArea = 0.0;
            // SELECT area_lamina FROM laminas WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "area_lamina" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    windowArea = atof( this->database->returnValue( "area_lamina" ).c_str() );
                }
            }
            return windowArea;
        }

        double getWeight( unsigned int index ){
            double weight = 0.0;
            // SELECT weight_lamina FROM laminas WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index,"weight_lamina" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    weight = atof( this->database->returnValue( "weight_lamina" ).c_str() );
                }
            }
            return weight;
        }

        unsigned int findIndexByWidth( double width, std::string type="padrao" ){
            unsigned int index = 0;
            // SELECT id FROM laminas WHERE (type_lamina='padrao') AND (width_lamina>=6) ORDER BY width_lamina ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "width_lamina", width, 'g', "ASC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        unsigned int findIndexByWindowArea( double windowArea, std::string type="padrao" ){
            unsigned int index = 0;
            // SELECT id FROM laminas WHERE (type_lamina='padrao') AND (area_lamina>=6) ORDER BY area_lamina ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "area_lamina", windowArea, 'g', "ASC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        unsigned int findIndexByWeight( double weight, std::string type="padrao" ){
            unsigned int index = 0;
            // SELECT id FROM laminas WHERE (type_lamina='padrao') AND (weght_lamina<=6) ORDER BY weght_lamina DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "weight_lamina", weight, 'l', "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        Lamina* getLamina( unsigned int index ){
            Lamina* lamina = new Lamina();
            std::string sql = "";
            sql = sql + "SELECT * ";
            sql = sql + "FROM laminas ";
            sql = sql + "WHERE id=" + std::to_string(index);
            // SELECT * FROM laminas WHERE id=10 //
            if( this->database->executeSQL( sql ) > -1 ){
                if( this->database->nextRegister() ){
                    lamina->setId( index );
                    lamina->setType( this->database->returnValue( "type_lamina" ) );
                    lamina->setWidth( atof( this->database->returnValue( "width_lamina" ).c_str() ) );
                    lamina->setWindowArea( atof( this->database->returnValue( "area_lamina" ).c_str() ) );
                    lamina->setWeight( atof( this->database->returnValue( "weight_lamina" ).c_str() ) );
                }
            }
            return lamina;
        }
};

#endif // LAMINAS_H
