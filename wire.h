#ifndef WIRE_H
#define WIRE_H

#include <string>
#include <vector>

class Wire{

	private:
		unsigned int id;
		std::string type;
		std::string awg;
		double diameter;
		double turnsPerCm;
		double area;
		double resistance;
		double weight;
		double length;
        std::vector< std::vector<double> > currentMax;
		double frequency;
        std::string material;
	
	public:
		Wire(){	
            this->id         = 0;
            this->type       = "redondo";
            this->awg        = "-";
            this->diameter   = 0.0;
            this->turnsPerCm = 0.0;
            this->area       = 0.0;
            this->resistance = 0.0;
            this->weight     = 0.0;
            this->length     = 0.0;
			//this.currentMax;
            this->frequency  = 0.0;
            this->material   = "cobre";
		}

		unsigned int getId(){
            return this->id;
		}

		void setId( unsigned int id ){
            this->id = id;
		}

		std::string getType(){
            return this->type;
		}

		void setType( std::string type="redondo" ){
            this->type = type;
		}

		std::string getAWG(){
            return this->awg;
		}

		void setAWG( std::string awg ){
            this->awg = awg;
		}

		double getDiameter(){
            return this->diameter;
		}

		void setDiameter( double diameter ){
            this->diameter = diameter;
		}

		double getTurnsPerCm(){
            return this->turnsPerCm;
		}

		void setTurnsPerCm( double turnsPerCm ){
            this->turnsPerCm = turnsPerCm;
		}

		double getArea(){
            return this->area;
		}

		void setArea( double area ){
            this->area = area;
		}

		double getResistance(){
            return this->resistance;
		}

		void setResistance( double resistance ){
            this->resistance = resistance;
		}

		double getWeight(){
            return this->weight;
		}

		void setWeight( double weight ){
            this->weight = weight;
		}

		double getLength(){
            return this->length;
		}

		void setLength( double length ){
            this->length = length;
		}

        std::vector< std::vector<double> > getCurrentMax(){
            return this->currentMax;
		}

        void setCurrentMax( std::vector< std::vector<double> > currentMax ){
            this->currentMax = currentMax;
		}

		double getFrequency(){
            return this->frequency;
		}

		void setFrequency( double frequency ){
            this->frequency = frequency;
		}

        std::string getMaterial(){
            return this->material;
        }

        void setMaterial( std::string material ){
            this->material = material;
        }

		std::string toString(){
            std::string txt = "";
            txt = txt + "Wire ID: "          + std::to_string( this->getId() )         + "\n";
            txt = txt + "Wire Type: "        + this->getType()                         + "\n";
            txt = txt + "Wire AWG: "         + this->getAWG()                          + "\n";
            txt = txt + "Wire Diameter: "    + std::to_string( this->getDiameter() )   + " mm\n";
            txt = txt + "Wire Turn per cm: " + std::to_string( this->getTurnsPerCm() ) + " esp/cm\n";
            txt = txt + "Wire Area: "        + std::to_string( this->getArea() )       + " mm*mm\n";
            txt = txt + "Wire Resistance: "  + std::to_string( this->getResistance() ) + " ohm/km\n";
            txt = txt + "Wire Weight: "      + std::to_string( this->getWeight() )     + " kg/km\n";
            txt = txt + "Wire Length: "      + std::to_string( this->getLength() )     + " m/kg\n";
            txt = txt + "Wire Frequency: "   + std::to_string( this->getFrequency() )  + " kHz\n";
            txt = txt + "Wire Current Max:\n";
            for( unsigned int i=0; i<this->getCurrentMax().size(); i++ ){
                txt = txt + "                 ";
                txt = txt + std::to_string( this->getCurrentMax().at(i).at(0) ) + " A/(mm*mm)";
                txt = txt + " => ";
                txt = txt + std::to_string( this->getCurrentMax().at(i).at(1) ) + " A\n";
            }
            txt = txt + "Wire Material: "    + this->getMaterial();
			return txt;
		}

        std::string toHTML(){
            std::string txt = "";
            txt = txt + "<table align=\"center\" class=\"wire\" width=\"100%\">\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Wire ID:</td><td><b>" + std::to_string( this->getId() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Type:</td><td><b>" + this->getType() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire AWG:</td><td><b>" + this->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Diameter:</td><td><b>" + std::to_string( this->getDiameter() ) + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Turn per cm:</td><td><b>" + std::to_string( this->getTurnsPerCm() ) + " esp/cm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Area:</td><td><b>" + std::to_string( this->getArea() ) + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Resistance:</td><td><b>" + std::to_string( this->getResistance() ) + " ohm/km</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Weight:</td><td><b>" + std::to_string( this->getWeight() ) + " kg/km</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Length:</td><td><b>" + std::to_string( this->getLength() ) + " m/kg</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire Frequency:</td><td><b>" + std::to_string( this->getFrequency() ) + " kHz</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\" valign=\"top\" rowspan=\"" + std::to_string( this->getCurrentMax().size() ) + "\">Wire Current Max:</td>";
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
            txt = txt + "\t<tr><td align=\"right\">Wire Material:</td><td><b>" + this->getMaterial() + "</b></td></tr>\n";
            txt = txt + "</table>";
            return txt;
        }
};

#endif // WIRE_H
