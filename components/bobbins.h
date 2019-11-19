#ifndef BOBBINS_H
#define BOBBINS_H

#include "components/bobbin.h"
#include "components/database.h"

class Bobbins{
    private:
        DataBase* database;

        std::string comparation( char option_comparation ) const{
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

        std::string queryByIndex( unsigned int index, std::string field ) const{
            // SELECT
            //          [field]
            // FROM
            //          bobbins
            // WHERE
            //          id=[index]
            std::string sql = "";
            sql = sql + "SELECT " + field + " ";
            sql = sql + "FROM bobbins ";
            sql = sql + "WHERE id=" + std::to_string( index );
            return sql;
        }

        std::string queryByField( std::string field, double value, char comparation, std::string type, std::string order="ASC" ) const{
            // SELECT
            //         id
            // FROM
            //          bobbins
            // WHERE
            //          (type_bobbin='[type]')
            //          AND
            //          ([field][comparation][value])
            // ORDER BY
            //          [field] [order]
            // LIMIT 1
            std::string sql = "";
            sql = sql + "SELECT id ";
            sql = sql + "FROM bobbins ";
            sql = sql + "WHERE (type_bobbin='" + type + "') ";
            sql = sql + "AND ";
            sql = sql + "(" + field + this->comparation( comparation ) + std::to_string( value ) + ") ";
            sql = sql + "ORDER BY " + field + " " + order + " LIMIT 1";
            return sql;
        }

	public:
        Bobbins( DataBase *database ){
            this->database = database;
        }

        void setDatabase( DataBase *database ){
            this->database = database;
        }

        unsigned int getId( unsigned int index ) const{
            unsigned int id_tmp = 0;
            // SELECT id FROM bobbins WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "id" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    id_tmp = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return id_tmp;
        }

        std::string getType( unsigned int index ) const{
            std::string type_tmp = "";
            // SELECT type_bobbin FROM bobbins WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "type_bobbin" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    type_tmp = this->database->returnValue( "type_bobbin" ).c_str();
                }
            }
            return type_tmp;
        }

        double getWidth( unsigned int index ) const{
            double width = 0.0;
            // SELECT width_bobbin FROM bobbins WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "width_bobbin" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    width = atof( this->database->returnValue( "width_bobbin" ).c_str()  );
                }
            }
            return width;
        }

        double getLength( unsigned int index ) const{
            double lenght = 0.0;
            // SELECT lenght_bobbin FROM bobbins WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "length_bobbin" ).c_str() ) > -1 ){
                if( this->database->nextRegister() ){
                    lenght = atof( this->database->returnValue( "length_bobbin" ).c_str() );
                }
            }
            return lenght;
        }

        double getHeight( unsigned int index ) const{
            double height = 0.0;
            // SELECT height_bobbin FROM bobbins WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "height_bobbin" ).c_str() ) > -1 ){
                if( this->database->nextRegister() ){
                    height = atof( this->database->returnValue( "height_bobbin" ).c_str() );
                }
            }
            return height;
        }

        unsigned int findIndexByWidth( double width, std::string type ) const{
            unsigned int index = 0;
            // SELECT id FROM bobbins WHERE (type_bobbin='STSR') AND width_bobbin>=6 ORDER BY width_bobbin ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByField( "width_bobbin", width, 'g', "ASC", type ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        unsigned int findIndexByWidthAndArea( double width, double area, std::string type ) const{
            unsigned int index = 0;
            std::string sql = "";
            sql = sql + "SELECT id ";
            sql = sql + "FROM bobbins ";
            sql = sql + "WHERE (type_bobbin='" + type + "') ";
            sql = sql + "AND ";
            sql = sql + "(width_bobbin" + comparation( 'g' ) + std::to_string(width) + ") ";
            sql = sql + "AND ";
            sql = sql + "((width_bobbin*length_bobbin)" + comparation( 'g' ) + std::to_string(area) + ") ";
            sql = sql + "ORDER BY ";
            sql = sql + "width_bobbin ASC, ";
            sql = sql + "(width_bobbin*length_bobbin) ASC ";
            sql = sql + "LIMIT 1";
            // SELECT id FROM bobbins WHERE (type_bobbin='padrao') AND (width_bobbin>=6) AND ((width_bobbin*length_bobbin)>=10) ORDER BY width_bobbin ASC, (width_bobbin*length_bobbin) ASC LIMIT 1 //
            if( this->database->executeSQL( sql ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        unsigned int findIndexByLength( double length, std::string type ) const{
            unsigned int index = 0;
            // SELECT id FROM bobbins WHERE (type_bobbin='padrao') AND (length_bobbin>=6) ORDER BY length_bobbin ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByField( "length_bobbin", length, 'g', "ASC", type ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        unsigned int findIndexByHeight( double height, std::string type ) const{
            unsigned int index = 0;
            // SELECT id FROM bobbins WHERE (type_bobbin='STSR') AND (height_bobbin>=6) ORDER BY height_bobbin ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByField( "height_bobbin", height, 'g', "ASC", type ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        Bobbin* getBobbin( unsigned int index ) const{
            Bobbin* bobbin = new Bobbin();
            std::string sql = "";
            sql = sql + "SELECT * ";
            sql = sql + "FROM bobbins ";
            sql = sql + "WHERE id=" + std::to_string(index);
            // SELECT * FROM bobbins WHERE id=10 //
            if( this->database->executeSQL( sql ) > -1 ){
                if( this->database->nextRegister() ){
                    bobbin->setId( index );
                    bobbin->setType( this->database->returnValue( "type_bobbin" ) );
                    bobbin->setCode( this->database->returnValue( "code_bobbin" ) );
                    bobbin->setProvider( this->database->returnValue( "provider_bobbin" ) );
                    bobbin->setWidth( atof( this->database->returnValue( "width_bobbin" ).c_str() ) );
                    bobbin->setLength( atof( this->database->returnValue( "length_bobbin" ).c_str() ) );
                    bobbin->setHeight( atof( this->database->returnValue( "height_bobbin" ).c_str() ) );
                }
            }
            return bobbin;
        }
};

#endif // BOBBINS_H
