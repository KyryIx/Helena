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
		unsigned char style;   // 1 - 1 primary and 1 secondary
		                       // 2 - 2 primaries and 1 secondary or
		                       //     1 primary and 2 secondaries
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
			txt = txt + "   Transformer with: ";
            if( this->getStyle() == 1 ){
				txt = txt + "1 primary and 1 secondary\n";
			}
            else if( this->getStyle() == 2 ){
				txt = txt + "2 primaries and 1 secondary or 1 primary and 2 secondaries\n";
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
            txt = txt + "           Iron Loss: " + std::to_string( this->getLossIron() ) + " watts\n";
            txt = txt + "         Copper Loss: " + std::to_string( this->getLossCopper() ) + " Watts\n";
            txt = txt + "          Total Loss: " + std::to_string( this->getLossIron() + this->getLossCopper() ) + " Watts\n";
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

        bool calculate(){
            try{
                double currentOUT  = this->getPowerOUT() / this->getVoltageOUT();
                double powerIN     = this->getPowerOUT() * (1.0 + this->getCompensation());
                double currentIN   = powerIN / this->getVoltageIN();

                this->wires        = new Wires( this->database );
                this->wireIN       = new Wire();
                this->wireOUT      = new Wire();
			
                unsigned int index = 0;

                double section_wire_1 = currentIN / this->getCurrentDensity();
                index = this->wires->findIndexByArea( section_wire_1 );
                this->wireIN = this->wires->getWire( index );

                double section_wire_2 = currentOUT / this->getCurrentDensity();
                index = this->wires->findIndexByArea( section_wire_2 );
                this->wireOUT = this->wires->getWire( index );
			
                double section_magnetic = this->getPowerOUT() / this->getFrequency();
                double vStyle = 0.0;

                if( this->getStyle() == 0 ) // 1 primary and 1 secondary
                    vStyle = 1.00;
                if( (this->getStyle() == 1) || (this->getStyle() == 2) ) // 2 primaries and 1 secondary or 1 primary and 2 secondaries
                    vStyle = 1.25;
                if( this->getStyle() == 3 ) // 2 primaries and 2 secondaries
                    vStyle = 1.50;
			
                section_magnetic = sqrt( vStyle * section_magnetic ) * 100; // convert to mm^2 #

                if( this->getLamina()->getType() == "padrao" ) // standard laminas
                    section_magnetic = 7.5 * section_magnetic;
                if( this->getLamina()->getType() == "especial" ) // long laminas
                    section_magnetic = 6.0 * section_magnetic;

                double section_geometric = this->getPercentageLayer() * section_magnetic; // percentageLayer = 1.1;
                double width_lamina_min  = sqrt( section_geometric );
			
                double width_lamina_min_Temp = width_lamina_min;
                bool state = false;
                int i      = 0;
                int limit  = 1000;
			
                unsigned int N1 = 0;
                unsigned int N2 = 0;

                while( i < limit ){
                    i = i + 1;
                    index = this->laminas->findIndexByWidth( width_lamina_min_Temp );
                    if( index == 0 )
                        state = false;

                    this->lamina = this->laminas->getLamina( index );
                    width_lamina_min = this->lamina->getWidth();

                    index = this->bobbins->findIndexByWidthAndArea( width_lamina_min, section_magnetic );
                    if( index == 0 )
                        state = false;

                    this->bobbin = this->bobbins->getBobbin( index );
                    double length = this->bobbin->getLength();

                    section_geometric = width_lamina_min * length;
                    section_magnetic = (section_geometric / this->getPercentageLayer()) / 100.0; // convert to cm^2

                    N1 = static_cast<unsigned int>( ceil( (this->getVoltageIN() * 1e8) / (section_magnetic * 4.44 * this->getFlux() * this->getFrequency()) ) );
                    N2 = static_cast<unsigned int>( ceil( ((this->getVoltageOUT() * 1e8) / (section_magnetic * 4.44 * this->getFlux() * this->getFrequency())) * (1.0 + this->getCompensation()) ) );
                    double section_cu = N1 * this->wireIN->getArea() + N2 * this->wireOUT->getArea();

                    if( (this->lamina->getWindowArea() / section_cu) < 3 ){
                        // Recalculando o transformador para uma chapa com janela maior
                        width_lamina_min_Temp = width_lamina_min_Temp + 0.1;
                    }
                    else{
                        // Calculo correto //
                        this->setCurrentOUT( currentOUT );
                        this->setPowerIN( powerIN );
                        this->setCurrentIN( currentIN );
                        this->setWireIN( wireIN );
                        this->setWireOUT( wireOUT );
                        this->setTurnsIN( N1 );
                        this->setTurnsOUT( N2 );
                        this->setLamina( lamina );
                        this->setBobbin( bobbin );
                        state = false;
                        break;
                    }

                    return state;
                }
            }
            catch( ... ){
                // Divisao por zero
                return false;
            }

        }
};

#endif // TRANSFORMER_H
