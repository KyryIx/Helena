#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "wire.h"
#include "lamina.h"
#include "bobbin.h"

#include "database.h"
#include "wires.h"
#include "bobbins.h"
#include "laminas.h"

#define PI 3.141592653589793238

class Transformer{

	private:
        bool automatic;
        DataBase* database;
        Wires* wires;
        Laminas* laminas;
        Bobbins* bobbins;

        Lamina* lamina;
        Bobbin* bobbin;

        unsigned int id;
        double frequency;                // Hz
        double magneticInduction;        // G
        double currentDensity;           // A/mm2
        double averageCurrentDensity;    // A/mm2
        double weigthIron;               // kg
        double weightCopper;             // kg
        double turnsAverageLength;       // cm
        double coilArea;                 // mm^2
        double ironLoss;                 // W
        double copperLoss;               // W
        double totalLoss;                // W
        double efficiency;               // %

        unsigned int patternTransformer; // 0 - 1 primary and 1 secondary
                                         // 1 - 2 primaries and 1 secondary
                                         // 2 - 1 primary and 2 secondaries
                                         // 3 - 2 primaries and 2 secondaries
        double compensationLossTransformer; // 0 <= C.L.T. <= 100%;
        double windowAreaPerSectionCu;      // 3.0

        double voltageIN;                // V
        double powerIN;                  // W
        double currentIN;                // A
        double currentDensityIN;         // A/mm2

        Wire* wireIN;
        //unsigned int wireIDIN;
        //std::string wireTypeIN;
        //std::string wireAWGIN;
        unsigned int wireTurnsIN;        // esp
        //double wireDiameterIN;           // mm
        //double wireTurnPerCmIN;          // esp/cm
        //double wireAreaIN;               // mm2
        //double wireResistanceIN;         // ohm/km
        //double wireWeightIN;             // kg/km
        //double wireLengthIN;             // m/kg
        //double wireFrequencyIN;          // kHz

        double voltageOUT;               // V
        double powerOUT;                 // W
        double currentOUT;               // A
        double currentDensityOUT;        // A/mm2

        Wire* wireOUT;
        //unsigned int wireIDOUT;
        //std::string wireTypeOUT;
        //std::string wireAWGOUT;
        unsigned int wireTurnsOUT;       // esp
        //double wireDiameterOUT;          // mm
        //double wireTurnPerCmOUT;         // esp/cm
        //double wireAreaOUT;              // mm2
        //double wireResistanceOUT;        // ohm/km
        //double wireWeightOUT;            // kg/km
        //double wireLengthOUT;            // m/kg
        //double wireFrequencyOUT;         // kHz

        //unsigned int laminaID;
        //std::string laminaType;
        //double laminaWidth;              // mm
        //double laminaWindowArea;         // mm^2
        //double laminaWeight;             // kg/cm
        //double laminaCompensation;       // 0 <= C.L.T. <= 100%;

        //unsigned int bobbinID;
        //std::string bobbinType;
        //std::string bobbinCode;
        //std::string bobbinProvider;
        //double bobbinWidth;              // mm
        //double bobbinLength;             // mm
        //double bobbinHeight;             // mm
        //double bobbinArea;               // mm^2
        //double bobbinVolume;             // mm^3

        void setAutomatic( bool state ){
            this->automatic = state;
        }

        bool getAutomatic(){
            return this->automatic;
        }

	public:
        Transformer( DataBase* database ){
            this->automatic                   = false;
            this->database                    = database;
            this->wires                       = new Wires( database );
            this->laminas                     = new Laminas( database );
            this->bobbins                     = new Bobbins( database );

            this->lamina                      = new Lamina();
            this->bobbin                      = new Bobbin();

            this->id                          = 0;
            this->frequency                   = 0.0;
            this->magneticInduction           = 0.0;
            this->currentDensity              = 0.0;
            this->averageCurrentDensity       = 0.0;
            this->weigthIron                  = 0.0;
            this->weightCopper                = 0.0;
            this->turnsAverageLength          = 0.0;
            this->coilArea                    = 0.0;
            this->ironLoss                    = 0.0;
            this->copperLoss                  = 0.0;
            this->totalLoss                   = 0.0;
            this->efficiency                  = 0.0;

            this->patternTransformer          = 0;
            this->compensationLossTransformer = 0.0;
            this->windowAreaPerSectionCu      = 3.0;

            this->voltageIN                   = 0.0;
            this->powerIN                     = 0.0;
            this->currentIN                   = 0.0;
            this->currentDensityIN            = 0.0;

            //this->wireIN                      = new Wire();
            //this->wireIDIN                    = 0;
            //this->wireTypeIN                  = "";
            //this->wireAWGIN                   = "";
            this->wireTurnsIN                 = 0;
            //this->wireDiameterIN              = 0.0;
            //this->wireTurnPerCmIN             = 0.0;
            //this->wireAreaIN                  = 0.0;
            //this->wireResistanceIN            = 0.0;
            //this->wireWeightIN                = 0.0;
            //this->wireLengthIN                = 0.0;
            //this->wireFrequencyIN             = 0.0;

            this->voltageOUT                  = 0.0;
            this->powerOUT                    = 0.0;
            this->currentOUT                  = 0.0;
            this->currentDensityOUT           = 0.0;

            this->wireOUT                     = new Wire();
            //this->wireIDOUT                   = 0;
            //this->wireTypeOUT                 = "";
            //this->wireAWGOUT                  = "";
            this->wireTurnsOUT                = 0;
            //this->wireDiameterOUT             = 0.0;
            //this->wireTurnPerCmOUT            = 0.0;
            //this->wireAreaOUT                 = 0.0;
            //this->wireResistanceOUT           = 0.0;
            //this->wireWeightOUT               = 0.0;
            //this->wireLengthOUT               = 0.0;
            //this->wireFrequencyOUT            = 0.0;

            //this->laminaID                    = 0;
            //this->laminaType                  = "";
            //this->laminaWidth                 = 0.0;
            //this->laminaWindowArea            = 0.0;
            //this->laminaWeight                = 0.0;
            //this->laminaCompensation          = 0.0;

            //this->bobbinID                    = 0;
            //this->bobbinType                  = "";
            //this->bobbinCode                  = "";
            //this->bobbinProvider              = "";
            //this->bobbinWidth                 = 0.0;
            //this->bobbinLength                = 0.0;
            //this->bobbinHeight                = 0.0;
            //this->bobbinArea                  = 0.0;
            //this->bobbinVolume                = 0.0;
		}

        void setDatabase( DataBase* database ){
            this->setAutomatic( false );
            this->database = database;
        }

        void setLamina( Lamina* lamina ){
            this->setAutomatic( false );
            this->lamina = lamina;
        }

        Lamina* getLamina(){
            return this->lamina;
        }

        void setBobbin( Bobbin* bobbin ){
            this->setAutomatic( false );
            this->bobbin = bobbin;
        }

        Bobbin* getBobbin(){
            return this->bobbin;
        }

        void setID( unsigned int id ){
            this->setAutomatic( false );
            this->id = id;
        }

        unsigned int getID(){
            return this->id;
        }

        void setFrequency( double frequency ){
            this->setAutomatic( false );
            this->frequency = frequency;
        }

        double getFrequency(){
            return this->frequency;
        }

        void setMagneticInduction( double magneticInduction ){
            this->setAutomatic( false );
            this->magneticInduction = magneticInduction;
        }

        double getMagneticInduction(){
            return this->magneticInduction;
        }

        void setCurrentDensity( double currentDensity ){
            this->setAutomatic( false );
            this->currentDensity = currentDensity;
        }

        double getCurrentDensity(){
            return this->currentDensity;
        }

        void setAverageCurrentDensity( double averageCurrentDensity ){
            this->setAutomatic( false );
            this->averageCurrentDensity = averageCurrentDensity;
        }

        double getAverageCurrentDensity(){
            if( this->getAutomatic() ){
                return (this->getCurrentDensityIN() + this->getCurrentDensityOUT()) / 2.0;
            }
            return this->averageCurrentDensity;
        }

        void setWeigthIron( double weigthIron ){
            this->setAutomatic( false );
            this->weigthIron = weigthIron;
        }

        double getWeigthIron(){
            if( this->getAutomatic() ){
                return (this->getBobbin()->getLength() / 10.0) * this->getLamina()->getWeight();
            }
            else{
                return this->weigthIron;
            }
        }

        void setWeightCopper( double weightCopper ){
            this->setAutomatic( false );
            this->weightCopper = weightCopper;
        }

        double getWeightCopper(){
            if( this->getAutomatic() ){
                return (this->getCoilArea()/100.0) * (this->getTurnAverageLength()/10.0) * 8.9 / 1000.0;
            }
            else{
                return this->weightCopper;
            }
        }

        void setTurnsAverageLength( double turnsAverageLength ){
            this->setAutomatic( false );
            this->turnsAverageLength = turnsAverageLength;
        }

        double getTurnAverageLength(){
            if( this->getAutomatic() ){
                return (2 + 0.5 * PI) * this->getLamina()->getWidth() + 2 * this->getBobbin()->getLength();
            }
            return this->turnsAverageLength;
        }

        void setCoilArea( double coilArea ){
            this->setAutomatic( false );
            this->coilArea = coilArea;
        }

        double getCoilArea(){
            if( this->getAutomatic() ){
                return this->getWireTurnsIN() * this->getWireIN()->getArea() + this->getWireTurnsOUT() * this->getWireOUT()->getArea();
            }
            else{
                return this->coilArea;
            }
        }

        void setIronLoss( double ironLoss ){
            this->setAutomatic( false );
            this->ironLoss = ironLoss;
        }

        double getIronLoss(){
            if( this->getAutomatic() ){
                // to acesita 145, thickness of 0,5 mm and frequency 50 Hz
                double W_kg10 = 1.35;
                double wfe = W_kg10 * pow(this->getMagneticInduction() / 10000.0, 2.0);
                return 1.15 * wfe * this->getWeigthIron();
            }
            return this->ironLoss;
        }

        void setCopperLoss( double copperLoss ){
            this->setAutomatic( false );
            this->copperLoss = copperLoss;
        }

        double getCopperLoss(){
            if( this->getAutomatic() ){
                double rho = 0.0216; // to 75 degree //
                double wcu = pow(this->getAverageCurrentDensity(), 2.0) * (rho / 8.9) * 1e3;
                return wcu * this->getWeightCopper();
            }
            return this->copperLoss;
        }

        void setTotalLoss( double totalLoss ){
            this->setAutomatic( false );
            this->totalLoss = totalLoss;
        }

        double getTotalLoss(){
            if( this->automatic ){
                return this->getIronLoss() + this->getCopperLoss();
            }
            return this->totalLoss;
        }

        void setEfficiency( double efficiency ){
            this->setAutomatic( false );
            this->efficiency = efficiency;
        }

        double getEfficiency(){
            if( this->automatic ){
                try{
                    return this->getPowerOUT() / (this->getPowerOUT() + this->getIronLoss() + this->getCopperLoss());
                }
                catch( ... ){
                    return 0.0;
                }
            }
            else{
                return this->efficiency;
            }
        }

        void setPatternTransformer( unsigned int patternTransformer ){
            this->setAutomatic( false );
            this->patternTransformer = patternTransformer;
        }

        unsigned int getPatternTransformer(){
            return this->patternTransformer;
        }

        void setCompensationLossTransformer( double compensationLossTransformer ){
            this->setAutomatic( false );
            this->compensationLossTransformer = compensationLossTransformer;
        }

        double getCompensationLossTransformer(){
            return this->compensationLossTransformer;
        }

        void setWindowAreaPerSectionCu( double windowAreaPerSectionCu ){
            this->windowAreaPerSectionCu = windowAreaPerSectionCu;
        }

        double getWindowAreaPerSectionCu(){
            return this->windowAreaPerSectionCu;
        }

        void setVoltageIN( double voltage ){
            this->setAutomatic( false );
            this->voltageIN = voltage;
        }

        double getVoltageIN(){
            return this->voltageIN;
        }

        void setPowerIN( double power ){
            this->setAutomatic( false );
            this->powerIN = power;
        }

        double getPowerIN(){
            return this->powerIN;
        }

        void setCurrentIN( double current ){
            this->setAutomatic( false );
            this->currentIN = current;
        }

        double getCurrentIN(){
            return this->currentIN;
        }

        void setCurrentDensityIN( double currentDensity ){
            this->setAutomatic( false );
            this->currentDensityIN = currentDensity;
        }

        double getCurrentDensityIN(){
            double currentDensity = 0.0;

            if( this->automatic ){
                try{
                    currentDensity = this->getCurrentIN() / this->getWireIN()->getArea();
                }
                catch( ... ){
                    currentDensity = 0.0;
                }
            }
            else{
                currentDensity = this->currentDensityIN;
            }

            return currentDensity;
        }

        void setWireIN( Wire* wire ){
            this->setAutomatic( false );
            this->wireIN = wire;
        }

        Wire* getWireIN(){
            return this->wireIN;
        }

        /*
        void setWireIDIN( unsigned int id ){
            this->setAutomatic( false );
            this->wireIDIN = id;
        }

        unsigned int getWireIDIN(){
            return this->wireIDIN;
        }

        void setWireTypeIN( std::string type ){
            this->wireTypeIN = type;
        }

        std::string setWireTypeIN(){
            return this->wireTypeIN;
        }

        void setWireAWGIN( std::string awg ){
            this->setAutomatic( false );
            this->wireAWGIN = awg;
        }

        std::string getWireAWGIN(){
            return this->wireAWGIN;
        }
        */
        void setWireTurnsIN( unsigned int turns ){
            this->setAutomatic( false );
            this->wireTurnsIN = turns;
        }

        unsigned int getWireTurnsIN(){
            return this->wireTurnsIN;
        }
        /*
        void setWireDiameterIN( double diameter ){
            this->setAutomatic( false );
            this->wireDiameterIN = diameter;
        }

        double getWireDiameterIN(){
            return this->wireDiameterIN;
        }

        void setWireTurnPerCmIN( double turnPerCm ){
            this->setAutomatic( false );
            this->wireTurnPerCmIN = turnPerCm;
        }

        double getWireTurnPerCmIN(){
            return this->wireTurnPerCmIN;
        }

        void setWireAreaIN( double area ){
            this->setAutomatic( false );
            this->wireAreaIN = area;
        }

        double getWireAreaIN(){
            return this->wireAreaIN;
        }

        void setWireResistanceIN( double resistance ){
            this->setAutomatic( false );
            this->wireResistanceIN = resistance;
        }

        double getWireResistanceIN(){
            return this->wireResistanceIN;
        }

        void setWireWeightIN( double weight ){
            this->setAutomatic( false );
            this->wireWeightIN = weight;
        }

        double getWireWeightIN(){
            return this->wireWeightIN;
        }

        void setWireLengthIN( double length ){
            this->setAutomatic( false );
            this->wireLengthIN = length;
        }

        double getWireLengthIN(){
            return this->wireLengthIN;
        }

        void setWireFrequencyIN( double frequency ){
            this->setAutomatic( false );
            this->wireFrequencyIN = frequency;
        }

        double getWireFrequencyIN(){
            return this->wireFrequencyIN;
        }
        */
        void setVoltageOUT( double voltage ){
            this->setAutomatic( false );
            this->voltageOUT = voltage;
        }

        double getVoltageOUT(){
            return this->voltageOUT;
        }

        void setPowerOUT( double power ){
            this->setAutomatic( false );
            this->powerOUT = power;
        }

        double getPowerOUT(){
            return this->powerOUT;
        }

        void setCurrentOUT( double current ){
            this->setAutomatic( false );
            this->currentOUT = current;
        }

        double getCurrentOUT(){
            return this->currentOUT;
        }

        void setCurrentDensityOUT( double currentDensity ){
            this->setAutomatic( false );
            this->currentDensityOUT = currentDensity;
        }

        double getCurrentDensityOUT(){
            double currentDensity = 0.0;

            if( this->automatic ){
                try{
                    currentDensity = this->getCurrentOUT() / this->getWireOUT()->getArea();
                }
                catch( ... ){
                    currentDensity = 0.0;
                }
            }
            else{
                currentDensity = this->currentDensityOUT;
            }

            return currentDensity;
        }

        void setWireOUT( Wire* wire ){
            this->setAutomatic( false );
            this->wireOUT = wire;
        }

        Wire* getWireOUT(){
            return this->wireOUT;
        }
        /*
        void setWireIDOUT( unsigned int id ){
            this->setAutomatic( false );
            this->wireIDOUT = id;
        }

        unsigned int getWireIDOUT(){
            return this->wireIDOUT;
        }

        void setWireTypeOUT( std::string type ){
            this->wireTypeOUT = type;
        }

        std::string setWireTypeOUT(){
            return this->wireTypeOUT;
        }

        void setWireAWGOUT( std::string awg ){
            this->setAutomatic( false );
            this->wireAWGOUT = awg;
        }

        std::string getWireAWGOUT(){
            return this->wireAWGOUT;
        }
        */
        void setWireTurnsOUT( unsigned int turns ){
            this->setAutomatic( false );
            this->wireTurnsOUT = turns;
        }

        unsigned int getWireTurnsOUT(){
            return this->wireTurnsOUT;
        }
        /*
        void setWireDiameterOUT( double diameter ){
            this->setAutomatic( false );
            this->wireDiameterOUT = diameter;
        }

        double getWireDiameterOUT(){
            return this->wireDiameterOUT;
        }

        void setWireTurnPerCmOUT( double turnPerCm ){
            this->setAutomatic( false );
            this->wireTurnPerCmOUT = turnPerCm;
        }

        double getWireTurnPerCmOUT(){
            return this->wireTurnPerCmOUT;
        }

        void setWireAreaOUT( double area ){
            this->setAutomatic( false );
            this->wireAreaOUT = area;
        }

        double getWireAreaOUT(){
            return this->wireAreaOUT;
        }

        void setWireResistanceOUT( double resistance ){
            this->setAutomatic( false );
            this->wireResistanceOUT = resistance;
        }

        double getWireResistanceOUT(){
            return this->wireResistanceOUT;
        }

        void setWireWeightOUT( double weight ){
            this->setAutomatic( false );
            this->wireWeightOUT = weight;
        }

        double getWireWeightOUT(){
            return this->wireWeightOUT;
        }

        void setWireLengthOUT( double length ){
            this->setAutomatic( false );
            this->wireLengthOUT = length;
        }

        double getWireLengthOUT(){
            return this->wireLengthOUT;
        }

        void setWireFrequencyOUT( double frequency ){
            this->setAutomatic( false );
            this->wireFrequencyOUT = frequency;
        }

        double getWireFrequencyOUT(){
            return this->wireFrequencyOUT;
        }

        void setLaminaID( unsigned int id ){
            this->setAutomatic( false );
            this->laminaID = id;
        }

        unsigned int getLaminaID(){
            return this->laminaID;
        }

        void setLaminaType( std::string type ){
            this->setAutomatic( false );
            this->laminaType = type;
        }

        std::string getLaminaType(){
            return this->laminaType;
        }

        void setLaminaWidth( double width ){
            this->setAutomatic( false );
            this->laminaWidth = width;
        }

        double getLaminaWidth(){
            return this->laminaWidth;
        }

        void setLaminaWindowArea( double windowArea ){
            this->setAutomatic( false );
            this->laminaWindowArea = windowArea;
        }

        double getLaminaWindowArea(){
            return this->laminaWindowArea;
        }

        void setLaminaWeight( double weight ){
            this->setAutomatic( false );
            this->laminaWeight = weight;
        }

        double getLaminaWeight(){
            return this->laminaWeight;
        }

        void setLaminaCompensation( double compensation ){
            this->setAutomatic( false );
            this->laminaCompensation = compensation;
        }

        double getLaminaCompensation(){
            return this->laminaCompensation;
        }

        void setBobbinID( unsigned int id ){
            this->setAutomatic( false );
            this->bobbinID = id;
        }

        unsigned int getBobbinID(){
            return this->bobbinID;
        }

        void setBobbinType( std::string type ){
            this->setAutomatic( false );
            this->bobbinType = type;
        }

        std::string getBobbinType(){
            return this->bobbinType;
        }

        void setBobbinCode( std::string code ){
            this->setAutomatic( false );
            this->bobbinCode = code;
        }

        std::string getBobbinCode(){
            return this->bobbinCode;
        }

        void setBobbinProvider( std::string provider ){
            this->setAutomatic( false );
            this->bobbinProvider = provider;
        }

        std::string getBobbinProvider(){
            return this->bobbinProvider;
        }

        void setBobbinWidth( double width ){
            this->setAutomatic( false );
            this->bobbinWidth = width;
        }

        double getBobbinWidth(){
            return this->bobbinWidth;
        }

        void setBobbinLength( double length ){
            this->setAutomatic( false );
            this->bobbinLength = length;
        }

        double getBobbinLength(){
            return this->bobbinLength;
        }

        void setBobbinHeight( double height ){
            this->setAutomatic( false );
            this->bobbinHeight = height;
        }

        double getBobbinHeight(){
            return this->bobbinHeight;
        }

        void setBobbinArea( double area ){
            this->setAutomatic( false );
            this->bobbinArea = area;
        }

        double getBobbinArea(){
            return this->bobbinArea;
        }

        void setBobbinVolume( double volume ){
            this->setAutomatic( false );
            this->bobbinVolume = volume;
        }

        double getBobbinVolume(){
            return this->bobbinVolume;
        }
        */
        bool calculate(){
            try{
                this->setCurrentOUT( this->getPowerOUT() / this->getVoltageOUT() );

                this->setPowerIN( (1.0 + this->getCompensationLossTransformer()/100.0) * this->getPowerOUT() );
                this->setCurrentIN( this->getPowerIN() / this->getVoltageIN() );

                unsigned int index = 0;
                double S1          = 0;
                double S2          = 0;
                //double d1          = 0;
                //double d2          = 0;

                S2 = this->getCurrentOUT() / this->getCurrentDensity();
                index   = this->wires->findIndexByArea( S2, this->getWireOUT()->getType() );
                this->setWireOUT( this->wires->getWire( index ) );
                //d2 = this->getCurrentOUT() / this->getWireOUT()->getArea();

                S1 = this->getCurrentIN() / this->getCurrentDensity();
                index   = this->wires->findIndexByArea( S1, this->getWireIN()->getType() );
                this->setWireIN( this->wires->getWire( index ) );
                //d1 = this->getCurrentIN() / this->getWireIN()->getArea();

                double SM = this->getPowerOUT() / this->getFrequency();

                switch( this->getPatternTransformer() ){
                    case 0: // 1 primary and 1 secondary
                        SM *= 1.00;
                        break;
                    case 1: // 1 primary and 2 secondaries
                    case 2: // 2 primaries and 1 secondary
                        SM *= 1.25;
                        break;
                    case 3: // 2 primaries and 2 secondaries
                        SM *= 1.50;
                }

                SM = sqrt( SM ) * 100; // convert to mm^2 #

                if( this->getLamina()->getType() == "padrao" ) // standard laminas
                        SM *= 7.5;
                else if( this->getLamina()->getType() == "especial" ) // long laminas
                        SM *= 6.0;

                double SG             = (1 + this->getLamina()->getThicknessPercent()/100.0) * SM;
                double widthLaminaMin = sqrt( SG );

                int i                 = 0;
                int limit             = 1000;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////// rever como melhorar o processo de repetição ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                while( true ){
                    i = i + 1;

                    if( i > limit ){
                        this->setAutomatic( false );
                        break;
                    }

                    index = this->laminas->findIndexByWidth( widthLaminaMin, this->getLamina()->getType() );
                    if( index == 0 ){
                        this->setAutomatic( false );
                        break;
                    }

                    this->setLamina( this->laminas->getLamina( index ) );
                    widthLaminaMin = this->getLamina()->getWidth();

                    index = this->bobbins->findIndexByWidthAndArea( widthLaminaMin, SG, this->getBobbin()->getType() );
                    if( index == 0 ){
                        this->setAutomatic( false );
                        break;
                    }

                    this->setBobbin( this->bobbins->getBobbin( index ) );

                    SG = widthLaminaMin * this->getBobbin()->getLength();
                    SM = (SG / (1 + this->getLamina()->getThicknessPercent()/100.0)) / 100.0; // convert to cm^2

                    unsigned int N2 = static_cast<unsigned int>( ceil( ((this->getVoltageOUT() * 1e8) / (SM * 4.44 * this->getMagneticInduction() * this->getFrequency())) * (1.0 + this->getCompensationLossTransformer()/100.0) ) );
                    this->setWireTurnsOUT( N2 );

                    unsigned int N1 = static_cast<unsigned int>( ceil( (this->getVoltageIN() * 1e8) / (SM * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                    this->setWireTurnsIN( N1 );

                    this->setCoilArea( this->getWireTurnsIN() * this->getWireIN()->getArea() + this->getWireTurnsOUT() * this->getWireOUT()->getArea() );

                    this->setAutomatic( true );
                    if( (this->getLamina()->getWindowArea() / this->getCoilArea()) < this->getWindowAreaPerSectionCu() ){
                        widthLaminaMin = widthLaminaMin + 0.1;
                        continue;
                    }

                    //this->setWireIDIN( this->getWireIN()->getId() );
                    //this->setWireTypeIN( this->getWireIN()->getType() );
                    //this->setWireAWGIN( this->getWireIN()->getAWG() );
                    //this->setWireDiameterIN( this->getWireIN()->getDiameter() );
                    //this->setWireTurnPerCmIN( this->getWireIN()->getTurnsPerCm() );
                    //this->setWireAreaIN( this->getWireIN()->getArea() );
                    //this->setWireResistanceIN( this->getWireIN()->getResistance() );
                    //this->setWireWeightIN( this->getWireIN()->getWeight() );
                    //this->setWireLengthIN( this->getWireIN()->getLength() );
                    //this->setWireFrequencyIN( this->getWireIN()->getFrequency() );

                    //this->setWireIDOUT( this->getWireOUT()->getId() );
                    //this->setWireTypeOUT( this->getWireOUT()->getType() );
                    //this->setWireAWGOUT( this->getWireOUT()->getAWG() );
                    //this->setWireDiameterOUT( this->getWireOUT()->getDiameter() );
                    //this->setWireTurnPerCmOUT( this->getWireOUT()->getTurnsPerCm() );
                    //this->setWireAreaOUT( this->getWireOUT()->getArea() );
                    //this->setWireResistanceOUT( this->getWireOUT()->getResistance() );
                    //this->setWireWeightOUT( this->getWireOUT()->getWeight() );
                    //this->setWireLengthOUT( this->getWireOUT()->getLength() );
                    //this->setWireFrequencyOUT( this->getWireOUT()->getFrequency() );

                    //this->setLaminaID( this->getLamina()->getId() );
                    //this->setLaminaType( this->getLamina()->getType() );
                    //this->setLaminaWidth( this->getLamina()->getWidth() );
                    //this->setLaminaWindowArea( this->getLamina()->getWindowArea() );
                    //this->setLaminaWeight( this->getLamina()->getWeight() );

                    //this->setBobbinID( this->getBobbin()-> getId() );
                    //this->setBobbinType( this->getBobbin()->getType() );
                    //this->setBobbinCode( this->getBobbin()->getCode() );
                    //this->setBobbinProvider( this->getBobbin()->getProvider() );
                    //this->setBobbinWidth( this->getBobbin()->getWidth() );
                    //this->setBobbinLength( this->getBobbin()->getLength() );
                    //this->setBobbinHeight( this->getBobbin()->getHeight() );
                    //this->setBobbinArea( this->getBobbin()->getArea() );
                    //this->setBobbinVolume( this->getBobbin()->getVolume() );

                    //this->setAutomatic( true );
                    break;
                }
            }
            catch( ... ){
                this->setAutomatic( false );
            }
            return this->getAutomatic();
        }

        std::string toString(){
            std::string txt = "";
            txt = txt + "    Transformer with: ";
            if( this->getPatternTransformer() == 0 )
                txt = txt + "1 primary and 1 secondary\n";
            else if( this->getPatternTransformer() == 1 )
                txt = txt + "1 primary and 2 secondaries\n";
            else if( this->getPatternTransformer() == 2 )
                txt = txt + "2 primaries and 1 secondary\n";
            else if( this->getPatternTransformer() == 3 )
                txt = txt + "2 primaries and 2 secondaries\n";
            else
                txt = txt + "indefined type\n";

            txt = txt + "           Frequency: " + std::to_string( this->getFrequency() ) + " Hz\n";
            txt = txt + "  Magnetic Induction: " + std::to_string( this->getMagneticInduction() ) + " G\n";
            txt = txt + "     Current Density: " + std::to_string( this->getCurrentDensity() ) + " A/mm^2\n";
            txt = txt + "Average Cur. Density: " + std::to_string( this->getAverageCurrentDensity() ) + " A/mm^2\n";
            txt = txt + "         Weigth Iron: " + std::to_string( this->getWeigthIron()*1000.0 ) + " g\n";
            txt = txt + "       Weight Copper: " + std::to_string( this->getWeightCopper()*1000.0 ) + " g\n";
            txt = txt + "Turns Average Length: " + std::to_string( this->getTurnAverageLength()/10 ) + " cm\n";
            txt = txt + "           Coil Area: " + std::to_string( this->getCoilArea() ) + " mm^2\n";
            txt = txt + "           Iron Loss: " + std::to_string( this->getIronLoss() ) + " W\n";
            txt = txt + "         Copper Loss: " + std::to_string( this->getCopperLoss() ) + " W\n";
            txt = txt + "          Total Loss: " + std::to_string( this->getTotalLoss() ) + " W\n";
            txt = txt + "          Efficiency: " + std::to_string( this->getEfficiency()*100 ) + " %\n";

            txt = txt + "\n";
            txt = txt + "\tINPUT\n";
            txt = txt + "             Voltage: " + std::to_string( this->getVoltageIN() ) + " V\n";
            txt = txt + "               Power: " + std::to_string( this->getPowerIN() ) + " W\n";
            txt = txt + "             Current: " + std::to_string( this->getCurrentIN() ) + " A\n";
            txt = txt + "            AWG wire: " + this->getWireIN()->getAWG() + "\n";
            txt = txt + "          Wire turns: " + std::to_string( this->getWireTurnsIN() ) + "\n";
            txt = txt + "     Current Density: " + std::to_string( this->getCurrentDensityIN() ) + " A/mm^2\n";

            txt = txt + "\n";
            txt = txt + "\tWIRE IN\n";
            txt = txt + this->getWireIN()->toString();
            txt = txt + "\n";

            txt = txt + "\n";
            txt = txt + "\tOUTPUT\n";
            txt = txt + "             Voltage: " + std::to_string( this->getVoltageOUT() ) + " V\n";
            txt = txt + "               Power: " + std::to_string( this->getPowerOUT() ) + " W\n";
            txt = txt + "             Current: " + std::to_string( this->getCurrentOUT() ) + " A\n";
            txt = txt + "            AWG wire: " + this->getWireOUT()->getAWG() + "\n";
            txt = txt + "          Wire turns: " + std::to_string( this->getWireTurnsOUT() ) + "\n";
            txt = txt + "     Current Density: " + std::to_string( this->getCurrentDensityOUT() ) + " A/mm^2\n";

            txt = txt + "\n";
            txt = txt + "\tWIRE OUT\n";
            txt = txt + this->getWireOUT()->toString();
            txt = txt + "\n";

            txt = txt + "\n";
            txt = txt + "\tLAMINA\n";
            txt = txt + this->getLamina()->toString();
            txt = txt + "\n";

            txt = txt + "\n";
            txt = txt + "\tBOBBIN\n";
            txt = txt + this->getBobbin()->toString();
            txt = txt + "\n";

            return txt;
        }

        std::string toHTML(){
            std::string txt = "";
            txt = txt + "<table align=\"center\" class=\"transformer\" width=\"100%\">\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">GENERAL INFORMATION</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Transformer with:</td><td><b>";
            if( this->getPatternTransformer() == 0 )
                txt = txt + "1 primary and 1 secondary";
            else if( this->getPatternTransformer() == 1 )
                txt = txt + "1 primary and 2 secondaries";
            else if( this->getPatternTransformer() == 2 )
                txt = txt + "2 primaries and 1 secondary";
            else if( this->getPatternTransformer() == 3 )
                txt = txt + "2 primaries and 2 secondaries";
            else
                txt = txt + "indefined type";

            txt = txt + "</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Frequency:</td><td><b>" + std::to_string( this->getFrequency() ) + " Hz</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Magnetic Induction:</td><td><b>" + std::to_string( this->getMagneticInduction() ) + " G</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensity() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Average Cur. Density:</td><td><b>" + std::to_string( this->getAverageCurrentDensity() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Weigth Iron:</td><td><b>" + std::to_string( this->getWeigthIron()*1000.0 ) + " g</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Weight Copper:</td><td><b>" + std::to_string( this->getWeightCopper()*1000.0 ) + " g</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Turns Average Length:</td><td><b>" + std::to_string( this->getTurnAverageLength()/10 ) + " cm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Coil Area:</td><td><b>" + std::to_string( this->getCoilArea() ) + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Iron Loss:</td><td><b>" + std::to_string( this->getIronLoss() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Copper Loss:</td><td><b>" + std::to_string( this->getCopperLoss() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Total Loss:</td><td><b>" + std::to_string( this->getTotalLoss() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Efficiency:</td><td><b>" + std::to_string( this->getEfficiency()*100 ) + " %</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">INPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage:</td><td><b>" + std::to_string( this->getVoltageIN() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getPowerIN() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current:</td><td><b>" + std::to_string( this->getCurrentIN() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire:</td><td><b>" + this->getWireIN()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns:</td><td><b>" + std::to_string( this->getWireTurnsIN() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensityIN() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getWireIN()->toHTML();
            txt = txt + "\n\t</td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">OUTPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage:</td><td><b>" + std::to_string( this->getVoltageOUT() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getPowerOUT() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current:</td><td><b>" + std::to_string( this->getCurrentOUT() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire:</td><td><b>" + this->getWireOUT()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns:</td><td><b>" + std::to_string( this->getWireTurnsOUT() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensityOUT() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getWireOUT()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

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

            txt = txt + "</table>";
            return txt;
        }

        std::string toSQL(){
            std::string sql = "INSERT INTO transformer";
            sql = sql + "( \n\tfrequency, \n\tmagneticInduction, \n\tcurrentDensity, \n\taverageCurrentDensity, \n\tweigthIron, ";
            sql = sql + "\n\tweightCopper, \n\tturnsAverageLength, \n\tcoilArea, \n\tironLoss, \n\tcopperLoss, \n\ttotalLoss, \n\tefficiency, ";

            sql = sql + "\n\tpatternTransformer, \n\tcompensationLossTransformer, ";

            sql = sql + "\n\tvoltageIN, \n\tpowerIN, \n\tcurrentIN, \n\tcurrentDensityIN, ";

            sql = sql + "\n\twireIDIN, \n\twireAWGIN, \n\twireTurnsIN, \n\twireDiameterIN, \n\twireTurnPerCmIN, \n\twireAreaIN, ";
            sql = sql + "\n\twireResistanceIN, \n\twireWeightIN, \n\twireLengthIN, \n\twireFrequencyIN, ";

            sql = sql + "\n\tvoltageOUT, \n\tpowerOUT, \n\tcurrentOUT, \n\tcurrentDensityOUT, ";

            sql = sql + "\n\twireIDOUT, \n\twireAWGOUT, \n\twireTurnsOUT, \n\twireDiameterOUT, \n\twireTurnPerCmOUT, \n\twireAreaOUT, ";
            sql = sql + "\n\twireResistanceOUT, \n\twireWeightOUT, \n\twireLengthOUT, \n\twireFrequencyOUT, ";

            sql = sql + "\n\tlaminaID, \n\tlaminaType, \n\tlaminaWidth, \n\tlaminaWindowArea, \n\tlaminaWeight, \n\tlaminaCompensation, ";

            sql = sql + "\n\tbobbinID, \n\tbobbinType, \n\tbobbinCode, \n\tbobbinProvider, \n\tbobbinWidth, \n\tbobbinLength, ";
            sql = sql + "\n\tbobbinHeight, \n\tbobbinArea, \n\tbobbinVolume, ";

            sql = sql + "\n\tstateProject \n) ";

            sql = sql + "\nVALUES";

            sql = sql + "(\n\t" + std::to_string( this->getFrequency() ) + ", -- frequency";
            sql = sql + "\n\t" + std::to_string( this->getMagneticInduction() ) + ", -- magnetic induction";
            sql = sql + "\n\t" + std::to_string( this->getCurrentDensity() ) + ", -- current density";
            sql = sql + "\n\t" + std::to_string( this->getAverageCurrentDensity() ) + ", -- average current density";
            sql = sql + "\n\t" + std::to_string( this->getWeigthIron() ) + ", -- weigth iron";
            sql = sql + "\n\t" + std::to_string( this->getWeightCopper() ) + ", -- weight copper";
            sql = sql + "\n\t" + std::to_string( this->getTurnAverageLength() ) + ", -- turn average length";
            sql = sql + "\n\t" + std::to_string( this->getCoilArea() ) + ", -- coil area";
            sql = sql + "\n\t" + std::to_string( this->getIronLoss() ) + ", -- iron loss";
            sql = sql + "\n\t" + std::to_string( this->getCopperLoss() ) + ", -- copper loss";
            sql = sql + "\n\t" + std::to_string( this->getTotalLoss() ) + ", -- total loss";
            sql = sql + "\n\t" + std::to_string( this->getEfficiency() ) + ", -- efficiency";

            sql = sql + "\n\t" + std::to_string( this->getPatternTransformer() ) + ", -- pattern transformer";
            sql = sql + "\n\t" + std::to_string( this->getCompensationLossTransformer() ) + ", -- compensation loss transformer";

            sql = sql + "\n\t" + std::to_string( this->getVoltageIN() ) + ", -- voltage IN";
            sql = sql + "\n\t" + std::to_string( this->getPowerIN() ) + ", -- power IN";
            sql = sql + "\n\t" + std::to_string( this->getCurrentIN() ) + ", -- current IN";
            sql = sql + "\n\t" + std::to_string( this->getCurrentDensityIN() ) + ", -- current density IN";

            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getId() ) + ", -- wire ID IN";
            sql = sql + "\n\t'" + this->getWireIN()->getAWG() + "', -- wire AWG IN";
            sql = sql + "\n\t" + std::to_string( this->getWireTurnsIN() ) + ", -- wire turns IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getDiameter() ) + ", -- wire diameter IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getTurnsPerCm() ) + ", -- wire turn per cm IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getArea() ) + ", -- wire area IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getResistance() ) + ", -- wire resistance IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getWeight() ) + ", -- wire weight IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getLength() ) + ", -- wire length IN";
            sql = sql + "\n\t" + std::to_string( this->getWireIN()->getFrequency() ) + ", -- wire frequency IN";

            sql = sql + "\n\t" + std::to_string( this->getVoltageIN() ) + ", -- voltage  IN";
            sql = sql + "\n\t" + std::to_string( this->getPowerIN() ) + ", -- power IN";
            sql = sql + "\n\t" + std::to_string( this->getCurrentIN() ) + ", -- current IN";
            sql = sql + "\n\t" + std::to_string( this->getCurrentDensityIN() ) + ", -- current density IN";

            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getId() ) + ", -- wire ID OUT";
            sql = sql + "\n\t'" + this->getWireOUT()->getAWG() + "', -- wire AWG OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireTurnsOUT() ) + ", -- wire turns OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getDiameter() ) + ", -- wire diameter OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getTurnsPerCm() ) + ", -- wire turn per cm OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getArea() ) + ", -- wire area OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getResistance() ) + ", -- wire resistance OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getWeight() ) + ", -- wire weight OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getLength() ) + ", -- wire length OUT";
            sql = sql + "\n\t" + std::to_string( this->getWireOUT()->getFrequency() ) + ", -- wire frequency OUT";

            sql = sql + "\n\t" + std::to_string( this->getLamina()->getId() ) + ", -- lamina ID";
            sql = sql + "\n\t'" + this->getLamina()->getType() + "', -- lamina type";
            sql = sql + "\n\t" + std::to_string( this->getLamina()->getWidth() ) + ", -- lamina width";
            sql = sql + "\n\t" + std::to_string( this->getLamina()->getWindowArea() ) + ", -- lamina window area";
            sql = sql + "\n\t" + std::to_string( this->getLamina()->getWeight() ) + ", -- lamina weight";
            sql = sql + "\n\t" + std::to_string( this->getLamina()->getThicknessPercent() ) + ", -- lamina compensation";

            sql = sql + "\n\t" + std::to_string( this->getBobbin()->getId() ) + ", -- bobbin ID";
            sql = sql + "\n\t'" + this->getBobbin()->getType() + "', -- bobbin type";
            sql = sql + "\n\t'" + this->getBobbin()->getCode() + "', -- bobbin code";
            sql = sql + "\n\t'" + this->getBobbin()->getProvider() + "', -- bobbin provider";
            sql = sql + "\n\t" + std::to_string( this->getBobbin()->getWidth() ) + ", -- bobbin width";
            sql = sql + "\n\t" + std::to_string( this->getBobbin()->getLength() ) + ", -- bobbin length";
            sql = sql + "\n\t" + std::to_string( this->getBobbin()->getHeight() ) + ", -- bobbin height";
            sql = sql + "\n\t" + std::to_string( this->getBobbin()->getArea() ) + ", -- bobbin area";
            sql = sql + "\n\t" + std::to_string( this->getBobbin()->getVolume() ) + ", -- bobbin volume";

            sql = sql + "\n\t'" + (this->getAutomatic() ? "automatic" : "manual") +  "' -- project create";
            sql = sql + "\n);";

            return sql;
        }
};

#endif // TRANSFORMER_H
