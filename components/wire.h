#ifndef WIRE_H
#define WIRE_H

#include <string>
#include <vector>

class Wire{

	private:
		unsigned int id;
		std::string type;
		std::string awg;
        std::string material;
        std::string provider;
		double diameter;
        double area;
        double turnsPerCm;
        double resistance;
        double weight;
        double length;
        std::vector< std::vector<double> > currentMax;
        double frequency;
	
	public:
		Wire(){	
            this->id         = 0;
            this->type       = "";
            this->awg        = "";
            this->material   = "";
            this->provider   = "";
            this->diameter   = 0.0;
            this->area       = 0.0;
            this->turnsPerCm = 0.0;
            this->resistance = 0.0;
            this->weight     = 0.0;
            this->length     = 0.0;
			//this.currentMax;
            this->frequency  = 0.0;

		}

        void setId( unsigned int id ){
            this->id = id;
		}

        unsigned int getId() const{
            return this->id;
        }

        void setType( std::string type ){
            this->type = type;
		}

        std::string getType() const{
            return this->type;
        }

        void setAWG( std::string awg ){
            this->awg = awg;
		}

        std::string getAWG() const{
            return this->awg;
        }

        void setMaterial( std::string material ){
            this->material = material;
        }

        std::string getMaterial() const{
            return this->material;
        }

        void setProvider( std::string provider ){
            this->provider = provider;
        }

        std::string getProvider() const{
            return this->provider;
        }

        void setDiameter( double diameter ){
            this->diameter = diameter;
		}

        double getDiameter() const{
            return this->diameter;
        }

        void setTurnsPerCm( double turnsPerCm ){
            this->turnsPerCm = turnsPerCm;
        }

        double getTurnsPerCm() const{
            return this->turnsPerCm;
        }

        void setArea( double area ){
            this->area = area;
		}

        double getArea() const{
            return this->area;
        }

        void setResistance( double resistance ){
            this->resistance = resistance;
        }

        double getResistance() const{
            return this->resistance;
        }

        void setWeight( double weight ){
            this->weight = weight;
		}

        double getWeight() const{
            return this->weight;
        }

        void setLength( double length ){
            this->length = length;
		}

        double getLength() const{
            return this->length;
        }

        void setCurrentMax( std::vector< std::vector<double> > currentMax ){
            this->currentMax = currentMax;
		}

        std::vector< std::vector<double> > getCurrentMax() const{
            return this->currentMax;
        }

        void setFrequency( double frequency ){
            this->frequency = frequency;
		}

        double getFrequency() const{
            return this->frequency;
        }

        std::string toString() const{
            std::string txt = "";
            txt = txt + "Wire ID:          " + std::to_string( this->getId() )         + "\n";
            txt = txt + "Wire Type:        " + this->getType()                         + "\n";
            txt = txt + "Wire AWG:         " + this->getAWG()                          + "\n";
            txt = txt + "Wire Material:    " + this->getMaterial()                     + "\n";
            txt = txt + "Wire Provider:    " + this->getProvider()                     + "\n";
            txt = txt + "Wire Diameter:    " + std::to_string( this->getDiameter() )   + " mm\n";
            txt = txt + "Wire Area:        " + std::to_string( this->getArea() )       + " mm*mm\n";
            txt = txt + "Wire Turn per cm: " + std::to_string( this->getTurnsPerCm() ) + " esp/cm\n";
            txt = txt + "Wire Resistance:  " + std::to_string( this->getResistance() ) + " ohm/km\n";
            txt = txt + "Wire Weight:      " + std::to_string( this->getWeight() )     + " kg/km\n";
            txt = txt + "Wire Length:      " + std::to_string( this->getLength() )     + " m/kg\n";
            txt = txt + "Wire Frequency:   " + std::to_string( this->getFrequency() )  + " kHz\n";
            txt = txt + "Wire Current Max:\n";
            for( unsigned int i=0; i<this->getCurrentMax().size(); i++ ){
                txt = txt + "                  ";
                txt = txt + std::to_string( this->getCurrentMax().at(i).at(0) ) + " A/(mm*mm)";
                txt = txt + " => ";
                txt = txt + std::to_string( this->getCurrentMax().at(i).at(1) ) + " A\n";
            }

            return txt.substr(0, txt.size() - 1);
		}

        std::string toHTML() const{
            std::string txt = "";
            txt = txt + "<table align=\"center\" class=\"wire\" width=\"100%\">\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Wire ID:</td><td><b>" + std::to_string( this->getId() )                + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Type:</td><td><b>"             + this->getType()                                + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire AWG:</td><td><b>"              + this->getAWG()                                 + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Material:</td><td><b>"         + this->getMaterial()                            + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Provider:</td><td><b>"         + this->getProvider()                            + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Diameter:</td><td><b>"         + std::to_string( this->getDiameter() )          + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Area:</td><td><b>"             + std::to_string( this->getArea() )              + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Turn per cm:</td><td><b>"      + std::to_string( this->getTurnsPerCm() )        + " esp/cm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Resistance:</td><td><b>"       + std::to_string( this->getResistance() )        + " ohm/km</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Weight:</td><td><b>"           + std::to_string( this->getWeight() )            + " kg/km</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Length:</td><td><b>"           + std::to_string( this->getLength() )            + " m/kg</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Frequency:</td><td><b>"        + std::to_string( this->getFrequency() )         + " kHz</b></td></tr>\n";

            txt = txt + "\t<tr><td align=\"right\" valign=\"top\" rowspan=\""          + std::to_string( this->getCurrentMax().size() ) + "\">Wire Current Max:</td>";
            if( this->getCurrentMax().size() > 0 ){
                txt = txt + "<td><b>" + std::to_string( this->getCurrentMax().at(0).at(0) ) + " A/mm<sup>2</sup>";
                txt = txt + "=> ";
                txt = txt + std::to_string( this->getCurrentMax().at(0).at(1) ) + " A</b></td></tr>\n";
                for( unsigned int i=1; i<this->getCurrentMax().size(); i++ ){
                    txt = txt + "\t<tr><td><b>" + std::to_string( this->getCurrentMax().at(i).at(0) ) + " A/mm<sup>2</sup>";
                    txt = txt + " => ";
                    txt = txt + std::to_string( this->getCurrentMax().at(i).at(1) ) + " A</b></td></tr>\n";
                }
            }
            txt = txt + "</table>";

            return txt;
        }

        std::string toSQL() const{
            std::string txt = "";
            txt += "INSERT INTO wires (";
            txt += "type_wire, awg_wire, diameter_wire, turnsPerCm_wire, area_wire, resistance_wire, weight_wire, ";
            txt += "length_wire, currentMaxPerDensity_wire, frequency_wire, material_wire, provider_wire";
            txt += ") VALUES( ";
            txt += "'" + this->getType()                   + "', ";
            txt += "'" + this->getAWG()                    + "', ";
            txt += std::to_string( this->getDiameter() )   + ", ";
            txt += std::to_string( this->getTurnsPerCm() ) + ", ";
            txt += std::to_string( this->getArea() )       + ", ";
            txt += std::to_string( this->getResistance() ) + ", ";
            txt += std::to_string( this->getWeight() )     + ", ";
            txt += std::to_string( this->getLength() )     + ", ";
            txt += "'";
            if( this->getCurrentMax().size() > 0 ){
                for( std::vector< std::vector<double> >::iterator it; it != this->getCurrentMax().end(); it++ ){
                    txt += txt + std::to_string( it->at(0) ) + ", " + std::to_string( it->at(1) ) + ", ";
                }
                txt = txt.substr(0, txt.size() - 2);
            }
            txt += "', ";
            txt += std::to_string( this->getFrequency() )  + ", ";
            txt += "'" + this->getMaterial()               + "', ";
            txt += "'" + this->getProvider()               + "' )";

            return txt;
        }
};

#endif // WIRE_H
