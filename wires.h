#include "wire.h"
#include "database.h"

class Wires{
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
            //         wires
            // WHERE
            //         id=[index]
            std::string sql = "";
            sql = sql + "SELECT " + field + " ";
            sql = sql + "FROM wires ";
            sql = sql + "WHERE id=" + std::to_string( index );
            return sql;
        }

        std::string queryByTypeAndField( std::string type, std::string field, double value, char comparation, std::string order="ASC" ){
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

	public:
		Wires(){}

        void setDatabase( DataBase *database ){
            this->database = database;
        }

        std::string getType( unsigned int index ){
			std::string type_tmp = "";
            // SELECT type_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "type_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    type_tmp = this->database->returnValue( "type_wire" ).c_str();
                }
            }
			return type_tmp;
		}

        std::string getAWG( unsigned int index ){
			std::string awg = "";
            // SELECT awg_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "awg_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    awg = this->database->returnValue( "awg_wire" ).c_str();
                }
            }
			return awg;
		}

        double getDiameter( unsigned int index ){
			double diameter = 0.0;
            // SELECT diameter_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "diameter_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    diameter = atof( this->database->returnValue( "diameter_wire" ).c_str() );
                }
            }
			return diameter;
		}

        double getTurnsPerCm( unsigned int index ){
			double turnsPerCm = 0.0;
            // SELECT turnsPerCm_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "turnsPerCm_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    turnsPerCm = atof( this->database->returnValue( "turnsPerCm_wire" ).c_str() );
                }
            }
            return turnsPerCm;
		}

        double getArea( unsigned int index ){
			double area = 0.0;
            // SELECT area_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "area_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    area = atof( this->database->returnValue( "area_wire" ).c_str() );
                }
            }
			return area;
		}

        double getResistance( unsigned int index ){
			double resistance = 0.0;
            // SELECT resistance_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "resistance_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    resistance = atof( this->database->returnValue( "resistance_wire" ).c_str() );
                }
            }
			return resistance;
		}

        double getWeight( unsigned int index ){
			double weight = 0.0;
            // SELECT weight_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "weight_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    weight = atof( this->database->returnValue( "weight_wire" ).c_str() );
                }
            }
			return weight;
		}

        double getLength( unsigned int index ){
			double length = 0.0;
            // SELECT length_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "length_wire" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    length = atof( this->database->returnValue( "length_wire" ).c_str() );
                }
            }
			return length;
		}

        double getFrequency( unsigned int index ){
            double frequency = 0.0;
            // SELECT frequency_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "frequency_wire" ).c_str() ) > -1 ){
                if( this->database->nextRegister() ){
                    frequency = atof( this->database->returnValue( "frequency_wire" ).c_str() );
                }
            }
            return frequency;
        }

        std::vector< std::vector<double> > getString2CurrentMax( std::string str ){
            std::vector< std::vector<double> > currentTemp;
            std::string strTemp;
            std::size_t found1 = 0;
            std::size_t found2 = str.find( ";" );
            while( found2 != std::string::npos ){
                strTemp = str.substr( found1, (found2-found1) );
                found1 = found2 + 1;
                found2 = strTemp.find( "," );
                currentTemp.push_back( {
                                        atof( strTemp.substr( 0, found2 ).c_str() ),
                                        atof( strTemp.substr( found2+1, std::string::npos ).c_str() )
                                      } );
                found2 = str.find( ";", found1+1 );
            }
            strTemp = str.substr( found1, std::string::npos );
            found1 = 0;
            found2 = strTemp.find( "," );
            currentTemp.push_back( {
                                      atof( strTemp.substr( 0, found2 ).c_str() ),
                                      atof( strTemp.substr(found2+1,std::string::npos).c_str() )
                                  } );
            return currentTemp;
        }

        std::vector< std::vector<double> > getCurrentMax( unsigned int index ){
            std::vector< std::vector<double> >currentMax;
            // SELECT currentMaxPerDensity_wire FROM wires WHERE id=10 //
            if( this->database->executeSQL( this->queryByIndex( index, "currentMaxPerDensity_wire" ).c_str() ) > -1 ){
                if( this->database->nextRegister() ){
                    std::string result = this->database->returnValue( "currentMaxPerDensity_wire" ).c_str();
                    currentMax = getString2CurrentMax( result );
                }
            }
			return currentMax;
		}

        unsigned int findIndexByDiameter( double diameter, char comparation='g', std::string type="redondo" ){
			unsigned int index = 0;
            // SELECT id FROM wires WHERE (type_wire='redondo') AND (diameter_wire>=6) ORDER BY diameter_wire ASC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "diameter_wire", diameter, comparation, "ASC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByTurnsPerCm( double turnPerCm, char comparation='l', std::string type="redondo" ){
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (turnsPerCm_wire<=60) ORDER BY turnsPerCm_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "turnsPerCm_wire", turnPerCm, comparation, "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}
        unsigned int findIndexByArea( double area, char comparation='l', std::string type="redondo" ){
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (area_wire<=60) ORDER BY area_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "area_wire", area, comparation, "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}	
        unsigned int findIndexByResistance( double resistance, char comparation='l', std::string type="redondo" ){
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (resistance_wire<=60) ORDER BY resistance_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "resistance_wire", resistance, comparation, "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}
        unsigned int findIndexByWeight( double weight, char comparation='l', std::string type="redondo" ){
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (weight_wire<=60) ORDER BY weight_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "weight_wire", weight, comparation, "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}
        unsigned int findIndexByLength( double length, char comparation='l', std::string type="redondo" ){
			unsigned int index = 0;
			// SELECT id FROM wires WHERE (type_wire='redondo') AND (length_wire<=60) ORDER BY length_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "length_wire", length, comparation, "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
			return index;
		}

        unsigned int findIndexByFrequency( double frequency, char comparation='l', std::string type="redondo" ){
            unsigned int index = 0;
            // SELECT id FROM wires WHERE (type_wire='redondo') AND (frequency_wire<=60) ORDER BY frequency_wire DESC LIMIT 1 //
            if( this->database->executeSQL( this->queryByTypeAndField( type, "frequency_wire", frequency, comparation, "DESC" ) ) > -1 ){
                if( this->database->nextRegister() ){
                    index = static_cast<unsigned int>( atoi( this->database->returnValue( "id" ).c_str() ) );
                }
            }
            return index;
        }

        unsigned int findIndexByCurrentMax( double currentMax, double density=3.0, char comparation='l', std::string type="redondo" ){
            unsigned int index = 0;
//=> fazer o codigo abaixo ///////////////////////////////////////////////////////
            /*
			//std::string sql = "SELECT id FROM wires WHERE (type_wire='";
			//sql = sql + type;
			//sql = sql + "') AND (resistance_wire<=";
			//sql = sql + to_string(diameter);
			//sql = sql + ") ORDER BY resistance_wire DESC LIMIT 1";
			//// SELECT id FROM wires WHERE (type_wire='redondo') AND (currentMax_wire<=60) ORDER BY resistance_wire DESC LIMIT 1 //
			//for wire in wires:
			//	densities = wire.find('correnteMaxima').findall('densidade')
			//	density_last = -1e10
			//	currentMax_tmp = -1e10
			//	for densityObject in densities:
			//		density_tmp = float(densityObject.get('valor'))
			//		if (density >= density_tmp) and (density_tmp > density_last):
			//			density_last = density_tmp
			//			currentMax_tmp = float(densityObject.text)
			//	
			//	if (currentMax <= currentMax_tmp) and (currentMax_tmp < currentMax_last):
			//		currentMax_last = currentMax_tmp
			//		index = int(wire.attrib['numero'])
            */
			return index;
		}

        Wire* getWire( unsigned int index ){
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
                    wire->setDiameter( atof( this->database->returnValue( "diameter_wire" ).c_str() ) );
                    wire->setTurnsPerCm( atof( this->database->returnValue( "turnsPerCm_wire" ).c_str() ) );
                    wire->setArea( atof( this->database->returnValue( "area_wire" ).c_str() ) );
                    wire->setResistance( atof( this->database->returnValue( "resistance_wire" ).c_str() ) );
                    wire->setWeight( atof( this->database->returnValue( "weight_wire" ).c_str() ) );
                    wire->setLength( atof( this->database->returnValue( "length_wire" ).c_str() ) );
                    wire->setCurrentMax( getString2CurrentMax( this->database->returnValue( "currentMaxPerDensity_wire" ).c_str() ) );
                    wire->setFrequency( atof( this->database->returnValue( "frequency_wire" ).c_str() ) );
                }
            }
            return wire;
		}
};
