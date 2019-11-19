#ifndef WIRES_H
#define WIRES_H

#include "components/wire.h"
#include "components/database.h"

class Wires{
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
            //         [field]
            // FROM
            //         wires
            // WHERE
            //         id=[index]
            std::string sql = "";
            sql = sql + "SELECT " + field + " ";
            sql = sql + "FROM wires ";
            sql = sql + "WHERE id=" + std::to_string( index );
            return sql;
        }

        std::string queryByTypeAndField( std::string type, std::string field, double value, char comparation, std::string order="ASC" ) const{
            // SELECT
            //          id
            // FROM
            //          wires
            // WHERE
            //          (type_wire='[type]')
            //          AND
            //          ([field][comparation][value])
            // ORDER BY
            //          [field] [order]
            // LIMIT 1
            std::string sql = "SELECT id ";
            sql = sql + "FROM wires ";
            sql = sql + "WHERE (type_wire='" + type + "') ";
            sql = sql + "AND ";
            sql = sql + "(" + field + this->comparation( comparation ) + std::to_string( value ) + ") ";
            sql = sql + "ORDER BY " + field + " " + order + " LIMIT 1";
            return sql;
        }

        std::vector< std::vector<double> > string2Vector( std::string text, char separator ) const{
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

	public:
        Wires( DataBase *database ){
            this->database = database;
        }

        void setDatabase( DataBase *database ){
            this->database = database;
        }

        std::string getType( unsigned int index ) const{
			std::string type_tmp = "";
            // SELECT type_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "type_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    type_tmp = this->database->returnValue( "type_wire" ).c_str();
                }
            }
			return type_tmp;
		}

        std::string getAWG( unsigned int index ) const{
			std::string awg = "";
            // SELECT awg_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "awg_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    awg = this->database->returnValue( "awg_wire" ).c_str();
                }
            }
			return awg;
		}

        double getDiameter( unsigned int index ) const{
			double diameter = 0.0;
            // SELECT diameter_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "diameter_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    diameter = atof( this->database->returnValue( "diameter_wire" ).c_str() );
                }
            }
			return diameter;
		}

        double getTurnsPerCm( unsigned int index ) const{
			double turnsPerCm = 0.0;
            // SELECT turnsPerCm_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "turnsPerCm_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    turnsPerCm = atof( this->database->returnValue( "turnsPerCm_wire" ).c_str() );
                }
            }
            return turnsPerCm;
		}

        double getArea( unsigned int index ) const{
			double area = 0.0;
            // SELECT area_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "area_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    area = atof( this->database->returnValue( "area_wire" ).c_str() );
                }
            }
			return area;
		}

        double getResistance( unsigned int index ) const{
			double resistance = 0.0;
            // SELECT resistance_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "resistance_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    resistance = atof( this->database->returnValue( "resistance_wire" ).c_str() );
                }
            }
			return resistance;
		}

        double getWeight( unsigned int index ) const{
			double weight = 0.0;
            // SELECT weight_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "weight_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    weight = atof( this->database->returnValue( "weight_wire" ).c_str() );
                }
            }
			return weight;
		}

        double getLength( unsigned int index ) const{
			double length = 0.0;
            // SELECT length_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "length_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    length = atof( this->database->returnValue( "length_wire" ).c_str() );
                }
            }
			return length;
		}

        double getFrequency( unsigned int index ) const{
            double frequency = 0.0;
            // SELECT frequency_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "frequency_wire" ).c_str() ) > -1 ){
                if( this->database->nextRegister() ){
                    frequency = atof( this->database->returnValue( "frequency_wire" ).c_str() );
                }
            }
            return frequency;
        }

        std::vector< std::vector<double> > getCurrentMax( unsigned int index ) const{
            std::vector< std::vector<double> >currentMax;
            // SELECT currentMaxPerDensity_wire FROM wires WHERE id=10 //
             if( this->database->executeSQL( this->queryByIndex( index, "currentMaxPerDensity_wire" ).c_str() ) > -1 ){
                if( this->database->nextRegister() ){
                    currentMax = string2Vector( this->database->returnValue( "currentMaxPerDensity_wire" ), ',' );
                }
            }
			return currentMax;
		}

        unsigned int findIndexByDiameter( double diameter, std::string type ) const{
			unsigned int index = 0;
            // SELECT id FROM wires WHERE (type_wire='redondo') AND (diameter_wire>=6) ORDER BY diameter_wire ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "diameter_wire", diameter, 'g', "ASC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByTurnsPerCm( double turnPerCm, std::string type ) const{
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (turnsPerCm_wire<=60) ORDER BY turnsPerCm_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "turnsPerCm_wire", turnPerCm, 'l', "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByArea( double area, std::string type ) const{
			unsigned int index = 0;
            // SELECT id FROM wires WHERE (type_wire='redondo') AND (area_wire>=0.92) ORDER BY area_wire ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "area_wire", area, 'g', "ASC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
        }

        unsigned int findIndexByResistance( double resistance, std::string type ) const{
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (resistance_wire<=60) ORDER BY resistance_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "resistance_wire", resistance, 'l', "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByWeight( double weight, std::string type ) const{
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (weight_wire<=60) ORDER BY weight_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "weight_wire", weight, 'l', "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByLength( double length, std::string type ) const{
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (length_wire<=60) ORDER BY length_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "length_wire", length, 'l', "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByFrequency( double frequency, std::string type ) const{
            unsigned int index = 0;
            // SELECT id FROM wires WHERE (type_wire='redondo') AND (frequency_wire>=60) ORDER BY frequency_wire ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "frequency_wire", frequency, 'g', "ASC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

// To Do - this->database->executeSQL( sql ) null
        unsigned int findIndexByCurrentMax( double currentMax, double density=3.0, std::string type="redondo" ) const{
            unsigned int index = 0;
            std::string sql = "";
            sql = sql + "SELECT id, currentMaxPerDensity_wire ";
            sql = sql + "FROM wires ";
            sql = sql + "type_wire='" + type + "'";
            // SELECT id, currentMaxPerDensity_wire FROM wires WHERE type_wire='redondo' //
            if( this->database->executeSQL( sql ) > -1 ){
                unsigned int indexTemp = 0;
                double currentMaxTemp  = 1E10;
                double densityTemp     = 1E10;
                std::vector< std::vector<double> > currentTemp;
                while( this->database->nextRegister() ){
                    currentTemp = string2Vector( this->database->returnValue( "currentMaxPerDensity_wire" ), ',' );
                    std::vector< std::vector<double> >::iterator it;
                    for( it=currentTemp.begin(); it != currentTemp.end(); it++ ){
                        if( ( (*it).at(1) >= currentMax ) && ( (*it).at(1) <= currentMaxTemp ) ){
                            if( ( (*it).at(0) >= density ) && ( (*it).at(0) <= densityTemp ) ){
                                indexTemp      = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                                currentMaxTemp = (*it).at(1);
                                densityTemp    = (*it).at(0);
                            }
                        }
                    }
                }
                if( indexTemp > 0 ){
                    index = indexTemp;
                }
            }
			return index;
		}

        Wire* getWire( unsigned int index ) const{
            Wire* wire = new Wire();
            std::string sql = "";
            sql = sql + "SELECT * ";
            sql = sql + "FROM wires ";
            sql = sql + "WHERE id=" + std::to_string(index);
            // SELECT * FROM wires WHERE id=10 //
            if( this->database->executeSQL( sql ) > -1 ){
                if( this->database->nextRegister() ){
                    wire->setId( index );
                    wire->setType( this->database->returnValue( "type_wire" )  );
                    wire->setAWG( this->database->returnValue( "awg_wire" ) );
                    wire->setMaterial( this->database->returnValue( "material_wire" ) );
                    wire->setProvider( this->database->returnValue( "provider_wire" ) );
                    wire->setDiameter( atof( this->database->returnValue( "diameter_wire" ).c_str() ) );
                    wire->setTurnsPerCm( atof( this->database->returnValue( "turnsPerCm_wire" ).c_str() ) );
                    wire->setArea( atof( this->database->returnValue( "area_wire" ).c_str() ) );
                    wire->setResistance( atof( this->database->returnValue( "resistance_wire" ).c_str() ) );
                    wire->setWeight( atof( this->database->returnValue( "weight_wire" ).c_str() ) );
                    wire->setLength( atof( this->database->returnValue( "length_wire" ).c_str() ) );
                    wire->setCurrentMax( string2Vector( this->database->returnValue( "currentMaxPerDensity_wire" ), ',' ) );
                    wire->setFrequency( atof( this->database->returnValue( "frequency_wire" ).c_str() ) );
                }
            }
            return wire;
		}
};

#endif // WIRES_H
