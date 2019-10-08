#ifndef TRANSFORMER_H
#define TRANSFORMER_H

//#include "wire.h"
//#include "lamina.h"
//#include "bobbin.h"

#include "database.h"
#include "wires.h"
#include "bobbins.h"
#include "laminas.h"

class Transformer{

	private:
        const double PI = 3.141592653589793238;
        DataBase* database;
        Wires* wires;
        Laminas* laminas;
        Bobbins* bobbins;

		double powerIN;        // in watts
		double voltageIN;      // in volts
		double currentIN;      // in amperes
		unsigned int turnsIN;  // number turns primary
        Wire* wireIN;
		
		double powerOUT;       // in watts
		double voltageOUT;     // in volts
		double currentOUT;     // in amperes
		unsigned int turnsOUT; // number turns secondary
        Wire* wireOUT;
		
        double frequency;      // in hertz
		double flux;           // in Gauss
        unsigned char style;   // 0 - 1 primary and 1 secondary
                               // 1 - 2 primaries and 1 secondary
                               // 2 - 1 primary and 2 secondaries
                               // 3 - 2 primaries and 2 secondaries
		
        double compensation;
        double percentageLayer;
		double currentDensity;
        Lamina* lamina;
        Bobbin* bobbin;
		
	public:
        Transformer( DataBase* database ){
            this->database        = database;
            this->wires           = new Wires( database );
            this->laminas         = new Laminas( database );
            this->bobbins         = new Bobbins( database );

            this->powerIN         = 0.0;
            this->voltageIN       = 0.0;
            this->currentIN       = 0.0;
            this->turnsIN         = 0;
            this->wireIN          = new Wire();
			
            this->powerOUT        = 0.0;
            this->voltageOUT      = 0.0;
            this->currentOUT      = 0.0;
            this->turnsOUT        = 0;
            this->wireOUT         = new Wire();

            this->frequency       = 0.0;
            this->flux            = 0.0;
            this->style           = 0;

            this->compensation    = 0.1;
            this->percentageLayer = 1.1;
            this->currentDensity  = 0.0;
            this->lamina          = new Lamina();
            this->bobbin          = new Bobbin();
		}

        void setDatabase( DataBase* database ){
            this->database = database;
        }

		double getPowerIN(){
            return this->powerIN;
		}

		void setPowerIN( double power ){
            this->powerIN = power;
		}

		double getVoltageIN(){
            return this->voltageIN;
		}

		void setVoltageIN( double voltage ){
            this->voltageIN = voltage;
		}

		double getCurrentIN(){
            return this->currentIN;
		}

		void setCurrentIN( double current ){
            this->currentIN = current;
		}

		unsigned int getTurnsIN(){
            return this->turnsIN;
		}

		void setTurnsIN( unsigned int turns ){
            this->turnsIN = turns;
		}

        Wire* getWireIN(){
            return this->wireIN;
		}

        void setWireIN( Wire* wire ){
            this->wireIN = wire;
		}

		double getPowerOUT(){
            return this->powerOUT;
		}

		void setPowerOUT( double power ){
            this->powerOUT = power;
		}

		double getVoltageOUT(){
            return this->voltageOUT;
		}

		void setVoltageOUT( double voltage ){
            this->voltageOUT = voltage;
		}

		double getCurrentOUT(){
            return this->currentOUT;
		}

		void setCurrentOUT( double current ){
            this->currentOUT = current;
		}

		unsigned int getTurnsOUT(){
            return this->turnsOUT;
		}

		void setTurnsOUT( unsigned int turns ){
            this->turnsOUT = turns;
		}

        Wire* getWireOUT(){
            return this->wireOUT;
		}

        void setWireOUT( Wire* wire ){
            this->wireOUT = wire;
		}

        double getFrequency(){
            return this->frequency;
		}

        void setFrequency( double frequency ){
            this->frequency = frequency;
		}

		double getFlux(){
            return this->flux;
		}

		void setFlux( double flux ){
            this->flux = flux;
		}

		unsigned char getStyle(){
            return this->style;
		}

		void setStyle( unsigned char style ){
            this->style = style;
		}

        double getCompensation(){
            return this->compensation;
        }

        void setCompensation( double compensation ){
            this->compensation = compensation;
        }

        double getPercentageLayer(){
            return this->percentageLayer;
        }

        void setPercentageLayer( double percentageLayer ){
            this->percentageLayer = percentageLayer;
        }

		double getCurrentDensity(){
            return this->currentDensity;
		}

		void setCurrentDensity( double density ){
            this->currentDensity = density;
		}

        Lamina* getLamina(){
            return this->lamina;
		}

        void setLamina( Lamina* lamina ){
            this->lamina = lamina;
		}

        Bobbin* getBobbin(){
            return this->bobbin;
		}

        void setBobbin( Bobbin* bobbin ){
            this->bobbin = bobbin;
		}

		double getCurrentDensityIN(){
			try{
                return this->getCurrentIN() / this->getWireIN()->getArea();
			}
            catch( ... ){
				return 0.0;
			}
		}

		double getCurrentDensityOUT(){
			try{
                return this->getCurrentOUT() / this->getWireOUT()->getArea();
			}
            catch( ... ){
				return 0.0;
			}
		}

		double getAverageDensity(){
            return (this->getCurrentDensityIN() + this->getCurrentDensityOUT()) / 2.0;
		}

		double getAverageLengthTurn(){
            return (2 + 0.5 * this->PI) * this->getLamina()->getWidth() + 2 * this->getBobbin()->getLength();
		}

		double getCoilArea(){
            return this->getTurnsIN() * this->getWireIN()->getArea() + this->getTurnsOUT() * this->getWireOUT()->getArea();
		}

		double getWeigthIron(){
            return (this->getBobbin()->getLength() / 10.0) * this->getLamina()->getWeight();
		}

		double getWeightCopper(){
            return (this->getCoilArea()/100.0) * (this->getAverageLengthTurn()/10.0) * 8.9 / 1000.0;
		}

		double getLossIron(){
			// rever esses calculos //
            double wfe = 1.35 * pow(this->getFlux() / 10000.0, 2);
            return 1.15 * wfe * this->getWeightCopper();
		}

		double getLossCopper(){
            double wcu = 2.43 * pow(this->getAverageDensity(), 2);
            return wcu * this->getWeightCopper();
		}

		double getEfficiency(){
			try{
                return this->getPowerOUT() / (this->getPowerOUT() + this->getLossIron() + this->getLossCopper());
			}
            catch( ... ){
				return 0.0;
			}
		}

		std::string toString(){
			std::string txt = "";
            txt = txt + "    Transformer with: ";
            if( this->getStyle() == 0 ){
				txt = txt + "1 primary and 1 secondary\n";
			}
            else if( this->getStyle() == 1 ){
                txt = txt + "1 primary and 2 secondaries\n";
			}
            else if( this->getStyle() == 2 ){
                txt = txt + "2 primaries and 1 secondary\n";
            }
            else if( this->getStyle() == 3 ){
				txt = txt + "2 primaries and 2 secondaries\n";
			}
			else{
				txt = txt + "indefined type\n";
			}
            txt = txt + "           Frequency: " + std::to_string( this->getFrequency() ) + " Hz\n";
            txt = txt + "  Magnetic Induction: " + std::to_string( this->getFlux() ) + " G\n";
            txt = txt + "     Current Density: " + std::to_string( this->getCurrentDensity() ) + " A/mm^2\n";
            txt = txt + "   Mean Cur. Density: " + std::to_string( this->getAverageDensity() ) + " A/mm^2\n";
            txt = txt + "         Weigth Iron: " + std::to_string( this->getWeigthIron()*1000.0 ) + " g\n";
            txt = txt + "       Weight Copper: " + std::to_string( this->getWeightCopper()*1000.0 ) + " g\n";
            txt = txt + "Turns Average Length: " + std::to_string( this->getAverageLengthTurn()/10 ) + " cm\n";
            txt = txt + "           Coil Area: " + std::to_string( this->getCoilArea() ) + " mm^2\n";
            txt = txt + "           Iron Loss: " + std::to_string( this->getLossIron() ) + " W\n";
            txt = txt + "         Copper Loss: " + std::to_string( this->getLossCopper() ) + " W\n";
            txt = txt + "          Total Loss: " + std::to_string( this->getLossIron() + this->getLossCopper() ) + " W\n";
            txt = txt + "          Efficiency: " + std::to_string( this->getEfficiency()*100 ) + " %\n";
			txt = txt + "\n";
            txt = txt + "INPUT:\n";
            txt = txt + "             Voltage: " + std::to_string( this->getVoltageIN() ) + " V\n";
            txt = txt + "               Power: " + std::to_string( this->getPowerIN() ) + " W\n";
            txt = txt + "             Current: " + std::to_string( this->getCurrentIN() ) + " A\n";
            txt = txt + "            AWG wire: " + this->getWireIN()->getAWG() + "\n";
            txt = txt + "          Wire turns: " + std::to_string( this->getTurnsIN() ) + "\n";
            txt = txt + "     Current Density: " + std::to_string( this->getCurrentDensityIN() ) + " A/mm^2\n";
			txt = txt + "\n";
			txt = txt + "OUTPUT:\n";
            txt = txt + "             Voltage: " + std::to_string( this->getVoltageOUT() ) + "\n";
            txt = txt + "               Power: " + std::to_string( this->getPowerOUT() ) + "\n";
            txt = txt + "             Current: " + std::to_string( this->getCurrentOUT() ) + "\n";
            txt = txt + "            AWG wire: " + this->getWireOUT()->getAWG() + "\n";
            txt = txt + "          Wire turns: " + std::to_string( this->getTurnsOUT() ) + "\n";
            txt = txt + "     Current Density: " + std::to_string( this->getCurrentDensityOUT() ) + " A/mm^2";
			return txt;
		}

        std::string toHTML(){
            std::string txt = "";
            txt = txt + "<table align=\"center\">\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">GENERAL INFORMATION</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Transformer with:</td><td><b>";
            if( this->getStyle() == 0 ){
                txt = txt + "1 primary and 1 secondary";
            }
            else if( this->getStyle() == 1 ){
                txt = txt + "1 primary and 2 secondaries";
            }
            else if( this->getStyle() == 2 ){
                txt = txt + "2 primaries and 1 secondary";
            }
            else if( this->getStyle() == 3 ){
                txt = txt + "2 primaries and 2 secondaries";
            }
            else{
                txt = txt + "indefined type";
            }
            txt = txt + "</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Frequency:</td><td><b>" + std::to_string( this->getFrequency() ) + " Hz</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Magnetic Induction:</td><td><b>" + std::to_string( this->getFlux() ) + " G</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensity() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Mean Cur. Density:</td><td><b>" + std::to_string( this->getAverageDensity() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Weigth Iron:</td><td><b>" + std::to_string( this->getWeigthIron()*1000.0 ) + " g</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Weight Copper:</td><td><b>" + std::to_string( this->getWeightCopper()*1000.0 ) + " g</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Turns Average Length:</td><td><b>" + std::to_string( this->getAverageLengthTurn()/10 ) + " cm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Coil Area:</td><td><b>" + std::to_string( this->getCoilArea() ) + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Iron Loss:</td><td><b>" + std::to_string( this->getLossIron() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Copper Loss:</td><td><b>" + std::to_string( this->getLossCopper() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Total Loss:</td><td><b>" + std::to_string( this->getLossIron() + this->getLossCopper() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Efficiency:</td><td><b>" + std::to_string( this->getEfficiency()*100 ) + " %</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">INPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage:</td><td><b>" + std::to_string( this->getVoltageIN() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getPowerIN() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current:</td><td><b>" + std::to_string( this->getCurrentIN() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire:</td><td><b>" + this->getWireIN()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns:</td><td><b>" + std::to_string( this->getTurnsIN() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensityIN() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">OUTPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage:</td><td><b>" + std::to_string( this->getVoltageOUT() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getPowerOUT() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current:</td><td><b>" + std::to_string( this->getCurrentOUT() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire:</td><td><b>" + this->getWireOUT()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns:</td><td><b>" + std::to_string( this->getTurnsOUT() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensityOUT() ) + " A/mm<sup>2</sup></b></td></tr>\n";

            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">LAMINA</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getLamina()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">BOBBIN</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getBobbin()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">WIRE IN</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getWireIN()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">WIRE OUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getWireOUT()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

            txt = txt + "</table>";
            return txt;
        }

        bool calculate(){
            try{
                this->setPowerIN( (1.0 + this->getCompensation()) * this->getPowerOUT() );
                this->setCurrentIN( this->getPowerIN() / this->getVoltageIN() );
                this->setCurrentOUT( this->getPowerOUT() / this->getVoltageOUT() );

                double sectionWireIN  = this->getCurrentIN() / this->getCurrentDensity();
                double sectionWireOUT = this->getCurrentOUT() / this->getCurrentDensity();

                unsigned int index = 0;
                std::string typeWireIN  = this->getWireIN()->getType();
                std::string typeWireOUT = this->getWireOUT()->getType();
                std::string typeLamina  = this->getLamina()->getType();
                std::string typeBobbin  = this->getBobbin()->getType();

                index = this->wires->findIndexByArea( sectionWireIN, typeWireIN );
                this->setWireIN( this->wires->getWire( index ) );
                index = this->wires->findIndexByArea( sectionWireOUT, typeWireOUT );
                this->setWireOUT( this->wires->getWire( index ) );

                double sectionMagnetic = this->getPowerOUT() / this->getFrequency();

                switch( this->getStyle() ){
                    case 0: // 1 primary and 1 secondary
                        sectionMagnetic *= 1.00;
                        break;
                    case 1: // 1 primary and 2 secondaries
                    case 2: // 2 primaries and 1 secondary
                        sectionMagnetic *= 1.25;
                        break;
                    case 3: // 2 primaries and 2 secondaries
                        sectionMagnetic *= 1.50;
                }

                sectionMagnetic = sqrt( sectionMagnetic ) * 100; // convert to mm^2 #

                if( this->getLamina()->getType() == "padrao" ){ // standard laminas
                        sectionMagnetic *= 7.5;
                }
                else if( this->getLamina()->getType() == "especial" ){ // long laminas
                        sectionMagnetic *= 6.0;
                }

                double sectionGeometric = this->getPercentageLayer() * sectionMagnetic; // percentageLayer = 1.1;
                double widthLaminaMin  = sqrt( sectionGeometric );

                double widthLaminaMinTemp = widthLaminaMin;
                double length = 0.0;
                bool state    = false;
                int i         = 0;
                int limit     = 1000;

                double section_cu = 0.0;
                double windowAreaPerSectionCu = 3.0;

                while( i < limit ){
                    i = i + 1;
                    index = this->laminas->findIndexByWidth( widthLaminaMinTemp, typeLamina );
                    if( index == 0 ){
                        widthLaminaMinTemp = widthLaminaMinTemp + 0.1;
                        continue;
                    }

                    this->setLamina( this->laminas->getLamina( index ) );
                    widthLaminaMin = this->getLamina()->getWidth();

                    index = this->bobbins->findIndexByWidthAndArea( widthLaminaMin, sectionGeometric, typeBobbin );
                    if( index == 0 ){
                        widthLaminaMinTemp = widthLaminaMinTemp + 0.1;
                        continue;
                    }

                    this->setBobbin( this->bobbins->getBobbin( index ) );
                    length = this->getBobbin()->getLength();

                    sectionGeometric = widthLaminaMin * length;
                    sectionMagnetic = (sectionGeometric / this->getPercentageLayer()) / 100.0; // convert to cm^2

                    this->setTurnsIN( static_cast<unsigned int>( ceil( (this->getVoltageIN() * 1e8) / (sectionMagnetic * 4.44 * this->getFlux() * this->getFrequency()) ) ) );
                    this->setTurnsOUT( static_cast<unsigned int>( ceil( ((this->getVoltageOUT() * 1e8) / (sectionMagnetic * 4.44 * this->getFlux() * this->getFrequency())) * (1.0 + this->getCompensation()) ) ) );
                    section_cu = this->getTurnsIN() * this->getWireIN()->getArea() + this->getTurnsOUT() * this->getWireOUT()->getArea();

////////////////////////////////////////////////////////////////////////////////////
                    if( (this->getLamina()->getWindowArea() / section_cu) < windowAreaPerSectionCu ){
                        //                                                             ^
                        //                                                             |
                        // ------------------------------------------------------------+
////////////////////////////////////////////////////////////////////////////////////
                        widthLaminaMinTemp = widthLaminaMinTemp + 0.1;
                        continue;
                    }

                    state = true;
                    break;
                }

                return state;
            }
            catch( ... ){
                return false;
            }

        }
};

#endif // TRANSFORMER_H
