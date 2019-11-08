#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "components/wire.h"
#include "components/lamina.h"
#include "components/bobbin.h"

#include "components/database.h"
#include "components/wires.h"
#include "components/bobbins.h"
#include "components/laminas.h"

#define PI 3.141592653589793238

class Transformer{

	private:
        DataBase* database;
        Wires* wires;
        Laminas* laminas;
        Bobbins* bobbins;

        unsigned int id;
        double frequency;                // Hz
        double magneticInduction;        // G
        double currentDensity;           // A/mm2
        double averageCurrentDensity;    // A/mm2
        double weigthIron;               // kg
        double weightCopper;             // kg
        double turnsAverageLength;       // mm
        double coilArea;                 // mm^2
        double ironLoss;                 // W
        double copperLoss;               // W
        double totalLoss;                // W
        double efficiency;               // %

        unsigned int patternTransformerNumber; // number: 0 -> name: 1 primary and 1 secondary
        std::string patternTransformerName;    // number: 1 -> name: 2 primaries and 1 secondary
                                               // number: 2 -> name: 1 primary and 2 secondaries
                                               // number: 3 -> name: 2 primaries and 2 secondaries
        bool applyCenterTap;
        bool applyCompensationTransformer;  // true to apply and false, otherwise
        double compensationLossTransformer; // 0 <= C.L.T. <= 100%;
        double windowAreaPerSectionCu;      // 3.0

        double voltageIN_1;              // V
        double voltageIN_2;              // V
        double powerIN;                  // W
        double currentIN_1;              // A
        double currentIN_2;              // A
        double currentDensityIN_1;       // A/mm2
        double currentDensityIN_2;       // A/mm2
        unsigned int wireTurnsIN_1;      // esp
        unsigned int wireTurnsIN_2;      // esp
        Wire* wireIN_1;
        Wire* wireIN_2;

        double voltageOUT_1;             // V
        double voltageOUT_2;             // V
        double powerOUT;                 // W
        double currentOUT_1;             // A
        double currentOUT_2;             // A
        double currentDensityOUT_1;      // A/mm2
        double currentDensityOUT_2;      // A/mm2
        unsigned int wireTurnsOUT_1;     // esp
        unsigned int wireTurnsOUT_2;     // esp
        Wire* wireOUT_1;
        Wire* wireOUT_2;

        double magneticSection;          // cm2
        double geometricSection;         // cm2

        bool applyCompensationLamina;    // true to apply and false, otherwise
        Lamina* lamina;
        Bobbin* bobbin;

        std::string observation;

        bool state;                      // true -> automatic and false -> manual

	public:
        Transformer( DataBase* database ){
            this->database                    = database;
            this->wires                       = new Wires( database );
            this->laminas                     = new Laminas( database );
            this->bobbins                     = new Bobbins( database );

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

            this->patternTransformerNumber    = 0;
            this->patternTransformerName      = "";
            this->applyCenterTap              = false;
            this->applyCompensationTransformer= true;
            this->compensationLossTransformer = 0.0;
            this->windowAreaPerSectionCu      = 3.0;

            this->voltageIN_1                 = 0.0;
            this->voltageIN_2                 = 0.0;
            this->powerIN                     = 0.0;
            this->currentIN_1                 = 0.0;
            this->currentIN_2                 = 0.0;
            this->currentDensityIN_1          = 0.0;
            this->currentDensityIN_2          = 0.0;
            this->wireTurnsIN_1               = 0;
            this->wireTurnsIN_2               = 0;
            this->wireIN_1                    = new Wire();
            this->wireIN_2                    = new Wire();

            this->voltageOUT_1                = 0.0;
            this->voltageOUT_2                = 0.0;
            this->powerOUT                    = 0.0;
            this->currentOUT_1                = 0.0;
            this->currentOUT_2                = 0.0;
            this->currentDensityOUT_1         = 0.0;
            this->currentDensityOUT_2         = 0.0;
            this->wireTurnsOUT_1              = 0;
            this->wireTurnsOUT_2              = 0;
            this->wireOUT_1                   = new Wire();
            this->wireOUT_2                   = new Wire();

            this->magneticSection             = 0.0;
            this->geometricSection            = 0.0;

            this->lamina                      = new Lamina();
            this->bobbin                      = new Bobbin();

            this->observation                 = "";

            this->state                       = false;
		}

        void setApplyCompensationLamina( bool state ){
            this->applyCompensationLamina = state;
        }

        bool getApplyCompensationLamina() const{
            return this->applyCompensationLamina;
        }

        void setDatabase( DataBase* database ){
            this->database = database;
        }

        void setID( unsigned int id ){
            this->id = id;
        }

        unsigned int getID() const{
            return this->id;
        }

        void setFrequency( double frequency ){
            this->frequency = frequency;
        }

        double getFrequency() const{
            return this->frequency;
        }

        void setMagneticInduction( double magneticInduction ){
            this->magneticInduction = magneticInduction;
        }

        double getMagneticInduction() const{
            return this->magneticInduction;
        }

        void setCurrentDensity( double currentDensity ){
            this->currentDensity = currentDensity;
        }

        double getCurrentDensity() const{
            return this->currentDensity;
        }

        void setAverageCurrentDensity( double averageCurrentDensity ){
            this->averageCurrentDensity = averageCurrentDensity;
        }

        double getAverageCurrentDensity() const{
            return this->averageCurrentDensity;
        }

        double getAverageCurrentDensityAuto() const{
            switch( this->getPatternTransformerNumber() ){
                case 0:
                    return (this->getCurrentDensityIN1() + this->getCurrentDensityOUT1()) / 2.0;
                case 1:
                    return (this->getCurrentDensityIN1() + this->getCurrentDensityOUT1() + this->getCurrentDensityOUT2()) / 3.0;
                case 2:
                    return (this->getCurrentDensityIN1() + this->getCurrentDensityIN2() + this->getCurrentDensityOUT1()) / 3.0;
                case 3:
                    return (this->getCurrentDensityIN1() + this->getCurrentDensityIN2() + this->getCurrentDensityOUT1() + this->getCurrentDensityOUT2()) / 4.0;
                default:
                    return 0.0;
            }
        }

        void setWeigthIron( double weigthIron ){
            this->weigthIron = weigthIron;
        }

        double getWeigthIron() const{
            return this->weigthIron;
        }

        double getWeigthIronAuto() const{
            return (this->getBobbin()->getLength() / 10.0) * this->getLamina()->getWeight();
        }

        void setWeightCopper( double weightCopper ){
            this->weightCopper = weightCopper;
        }

        double getWeightCopper() const{
            return this->weightCopper;
        }

        double getWeightCopperAuto() const{
            return (this->getCoilArea()/100.0) * (this->getTurnAverageLength()/10.0) * 8.9 / 1000.0;
        }

        void setTurnsAverageLength( double turnsAverageLength ){
            this->turnsAverageLength = turnsAverageLength;
        }

        double getTurnAverageLength() const{
            return this->turnsAverageLength;
        }

        double getTurnAverageLengthAuto() const{
            return (2.0 + 0.5 * PI) * this->getLamina()->getWidth() + 2.0 * this->getBobbin()->getLength();
        }

        void setCoilArea( double coilArea ){
            this->coilArea = coilArea;
        }

        double getCoilArea() const{
            return this->coilArea;
        }

        double getCoilAreaAuto() const{
            switch( this->getPatternTransformerNumber() ){
                case 3:
                    return this->getWireTurnsIN1() * this->getWireIN1()->getArea() + this->getWireTurnsIN2() * this->getWireIN2()->getArea() + this->getWireTurnsOUT1() * this->getWireOUT1()->getArea() + this->getWireTurnsOUT2() * this->getWireOUT2()->getArea();
                case 2:
                    return this->getWireTurnsIN1() * this->getWireIN1()->getArea() + this->getWireTurnsIN2() * this->getWireIN2()->getArea() + this->getWireTurnsOUT1() * this->getWireOUT1()->getArea();
                case 1:
                    return this->getWireTurnsIN1() * this->getWireIN1()->getArea() + this->getWireTurnsOUT1() * this->getWireOUT1()->getArea() + this->getWireTurnsOUT2() * this->getWireOUT2()->getArea();
                case 0:
                    return this->getWireTurnsIN1() * this->getWireIN1()->getArea() + this->getWireTurnsOUT1() * this->getWireOUT1()->getArea();
                default:
                    return 0.0;
            }
        }

        void setIronLoss( double ironLoss ){
            this->ironLoss = ironLoss;
        }

        double getIronLoss() const{
            return this->ironLoss;
        }

        double getIronLossAuto() const{
            // to acesita 145, thickness of 0,5 mm and frequency 50 Hz
            double W_kg10 = 1.35;
            double wfe = W_kg10 * pow(this->getMagneticInduction() / 10000.0, 2.0);
            return 1.15 * wfe * this->getWeigthIron();
        }

        void setCopperLoss( double copperLoss ){
            this->copperLoss = copperLoss;
        }

        double getCopperLoss() const{
            return this->copperLoss;
        }

        double getCopperLossAuto() const{
            double rho = 0.0216; // to 75 degree //
            double wcu = pow(this->getAverageCurrentDensity(), 2.0) * (rho / 8.9) * 1e3;
            return wcu * this->getWeightCopper();
        }

        void setTotalLoss( double totalLoss ){
            this->totalLoss = totalLoss;
        }

        double getTotalLoss() const{
            return this->totalLoss;
        }

        double getTotalLossAuto() const{
            return this->getIronLoss() + this->getCopperLoss();
        }

        void setEfficiency( double efficiency ){
            this->efficiency = efficiency;
        }

        double getEfficiency() const{
            return this->efficiency;
        }

        double getEfficiencyAuto() const{
            try{
                return 100.0 * this->getPowerOUT() / (this->getPowerOUT() + this->getIronLoss() + this->getCopperLoss());
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setPatternTransformerNumber( unsigned int patternTransformerNumber ){
            this->patternTransformerNumber = patternTransformerNumber;
        }

        unsigned int getPatternTransformerNumber() const{
            return this->patternTransformerNumber;
        }

        void setPatternTransformerName( std::string patternTransformerName ){
            this->patternTransformerName = patternTransformerName;
        }

        std::string getPatternTransformerName() const{
            return this->patternTransformerName;
        }

        std::string getPatternTransformerNameAuto() const{
            std::string str;
            unsigned int patternNumber = this->getPatternTransformerNumber();
            if( patternNumber <= 3 ){
                switch( patternNumber ) {
                    case 1:
                        str = "1 primary and 1 secondary";
                        break;
                    case 2:
                        str = "1 primary and 2 secondaries";
                        break;
                    case 3:
                        str = "2 primaries and 1 secondary";
                        break;
                    case 4:
                        str = "2 primaries and 2 secondaries";
                }
            }
            else{
                str = "defined by user: " + this->getPatternTransformerName();
            }

            if( this->getApplyCenterTap() ){
                str += " with center tap";
            }

            return str;
        }

        void setApplyCenterTap( bool state ){
            this->applyCenterTap = state;
        }

        bool getApplyCenterTap() const{
            return this->applyCenterTap;
        }

        void setApplyCompensationTransformer( bool state ){
            this->applyCompensationTransformer = state;
        }

        bool getApplyCompensationTransformer() const{
            return this->applyCompensationTransformer;
        }

        void setCompensationLossTransformer( double compensationLossTransformer ){
            this->compensationLossTransformer = compensationLossTransformer;
        }

        double getCompensationLossTransformer() const{
            return this->compensationLossTransformer;
        }

        void setWindowAreaPerSectionCu( double windowAreaPerSectionCu ){
            this->windowAreaPerSectionCu = windowAreaPerSectionCu;
        }

        double getWindowAreaPerSectionCu() const{
            return this->windowAreaPerSectionCu;
        }

        void setVoltageIN1( double voltage ){
            this->voltageIN_1 = voltage;
        }

        double getVoltageIN1() const{
            return this->voltageIN_1;
        }

        void setVoltageIN2( double voltage ){
            this->voltageIN_2 = voltage;
        }

        double getVoltageIN2() const{
            return this->voltageIN_2;
        }

        void setPowerIN( double power ){
            this->powerIN = power;
        }

        double getPowerIN() const{
            return this->powerIN;
        }

        double getPowerINAuto() const{
            if( this->getApplyCompensationTransformer() ){
                return (1.0 + this->getCompensationLossTransformer()/100.0) * this->getPowerOUT();
            }
            else{
                return this->getPowerOUT();
            }
        }

        void setCurrentIN1( double current ){
            this->currentIN_1 = current;
        }

        double getCurrentIN1() const{
            return this->currentIN_1;
        }

        double getCurrentIN1Auto() const{
            try{
                return this->getPowerIN() / this->getVoltageIN1();
            }
            catch(...){
                return 0.0;
            }
        }

        void setCurrentIN2( double current ){
            this->currentIN_2 = current;
        }

        double getCurrentIN2() const{
            return this->currentIN_2;
        }

        double getCurrentIN2Auto() const{
            try{
                return this->getPowerIN() / this->getVoltageIN2();
            }
            catch(...){
                return 0.0;
            }
        }

        void setCurrentDensityIN1( double currentDensity ){
            this->currentDensityIN_1 = currentDensity;
        }

        double getCurrentDensityIN1() const{
            return this->currentDensityIN_1;
        }

        double getCurrentDensityIN1Auto() const{
            try{
                return this->getCurrentIN1() / this->getWireIN1()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setCurrentDensityIN2( double currentDensity ){
            this->currentDensityIN_2 = currentDensity;
        }

        double getCurrentDensityIN2() const{
            return this->currentDensityIN_2;
        }

        double getCurrentDensityIN2Auto() const{
            try{
                return this->getCurrentIN2() / this->getWireIN2()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setWireIN1( Wire* wire ){
            this->wireIN_1 = wire;
        }

        Wire* getWireIN1() const{
            return this->wireIN_1;
        }

        void setWireIN2( Wire* wire ){
            this->wireIN_2 = wire;
        }

        Wire* getWireIN2() const{
            return this->wireIN_2;
        }

        void setWireTurnsIN1( unsigned int turns ){
            this->wireTurnsIN_1 = turns;
        }

        unsigned int getWireTurnsIN1() const{
            return this->wireTurnsIN_1;
        }

        unsigned int getWireTurnsIN1Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyCompensationTransformer ){
                    N = static_cast<unsigned int>( ceil( ( (this->getVoltageIN1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getCompensationLossTransformer()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getVoltageIN1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setWireTurnsIN2( unsigned int turns ){
            this->wireTurnsIN_2 = turns;
        }

        unsigned int getWireTurnsIN2() const{
            return this->wireTurnsIN_2;
        }

        unsigned int getWireTurnsIN2Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyCompensationTransformer ){
                    N = static_cast<unsigned int>( ceil( ( (this->getVoltageIN2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getCompensationLossTransformer()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getVoltageIN2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setVoltageOUT1( double voltage ){
            this->voltageOUT_1 = voltage;
        }

        double getVoltageOUT1() const{
            return this->voltageOUT_1;
        }

        void setVoltageOUT2( double voltage ){
            this->voltageOUT_2 = voltage;
        }

        double getVoltageOUT2() const{
            return this->voltageOUT_2;
        }

        void setPowerOUT( double power ){
            this->powerOUT = power;
        }

        double getPowerOUT() const{
            return this->powerOUT;
        }

        void setCurrentOUT1( double current ){
            this->currentOUT_1 = current;
        }

        double getCurrentOUT1() const{
            return this->currentOUT_1;
        }

        double getCurrentOUT1Auto() const{
            try{
                return this->getPowerOUT() / this->getVoltageOUT1();
            }
            catch(...){
                return 0.0;
            }
        }

        void setCurrentOUT2( double current ){
            this->currentOUT_2 = current;
        }

        double getCurrentOUT2() const{
            return this->currentOUT_2;
        }

        double getCurrentOUT2Auto() const{
            try{
                return this->getPowerOUT() / this->getVoltageOUT2();
            }
            catch(...){
                return 0.0;
            }
        }

        void setCurrentDensityOUT1( double currentDensity ){
            this->currentDensityOUT_1 = currentDensity;
        }

        double getCurrentDensityOUT1() const{
            return currentDensityOUT_1;
        }

        double getCurrentDensityOUT1Auto() const{
            try{
                return this->getCurrentOUT1() / this->getWireOUT1()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setCurrentDensityOUT2( double currentDensity ){

            this->currentDensityOUT_2 = currentDensity;
        }

        double getCurrentDensityOUT2() const{
            return currentDensityOUT_2;
        }

        double getCurrentDensityOUT2Auto() const{
            try{
                return this->getCurrentOUT2() / this->getWireOUT2()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setWireOUT1( Wire* wire ){
            this->wireOUT_1 = wire;
        }

        Wire* getWireOUT1() const{
            return this->wireOUT_1;
        }

        void setWireOUT2( Wire* wire ){
            this->wireOUT_2 = wire;
        }

        Wire* getWireOUT2() const{
            return this->wireOUT_2;
        }

        void setWireTurnsOUT1( unsigned int turns ){
            this->wireTurnsOUT_1 = turns;
        }

        unsigned int getWireTurnsOUT1() const{
            return this->wireTurnsOUT_1;
        }

        unsigned int getWireTurnsOUT1Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyCompensationTransformer ){
                    N = static_cast<unsigned int>( ceil( ( (this->getVoltageOUT1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getCompensationLossTransformer()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getVoltageOUT1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setWireTurnsOUT2( unsigned int turns ){
            this->wireTurnsOUT_2 = turns;
        }

        unsigned int getWireTurnsOUT2() const{
            return this->wireTurnsOUT_2;
        }

        unsigned int getWireTurnsOUT2Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyCompensationTransformer ){
                    N = static_cast<unsigned int>( ceil( ( (this->getVoltageOUT2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getCompensationLossTransformer()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getVoltageOUT2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setMagneticSection( double magneticSection ){
            this->magneticSection = magneticSection;
        }

        double getMagneticSection() const{
            return this->magneticSection;
        }

        double getMagneticSectionAuto() const{
            double SM = this->getPowerOUT() / this->getFrequency();

            switch( this->getPatternTransformerNumber() ){
                case 0: // 1 primary and 1 secondary
                    SM *= 1.00;
                    break;
                case 1: // 1 primary and 2 secondaries
                case 2: // 2 primaries and 1 secondary
                    SM *= 1.25;
                    break;
                case 3: // 2 primaries and 2 secondaries
                    SM *= 1.50;
                    break;
                default:
                    SM *= 0.0;
            }

            SM = sqrt( SM );

            if( this->getLamina()->getType() == "padrao" ){ // standard laminas
                    SM *= 7.5;
            }
            else if( this->getLamina()->getType() == "compridas" ){ // long laminas
                    SM *= 6.0;
            }

            return SM;
        }

        void setGeometricSection( double geometricSection ){
            this->geometricSection = geometricSection;
        }

        double getGeometricSection() const{
            return this->geometricSection;
        }

        double getGeometricSectionAuto() const{
            if( this->getApplyCompensationLamina() ){
                return (1 + this->getLamina()->getThicknessPercent()/100.0) * this->getMagneticSectionAuto();
            }
            return 0.0;
        }

        void setLamina( Lamina* lamina ){
            this->lamina = lamina;
        }

        Lamina* getLamina() const{
            return this->lamina;
        }

        void setBobbin( Bobbin* bobbin ){
            this->bobbin = bobbin;
        }

        Bobbin* getBobbin() const{
            return this->bobbin;
        }

        void setObservation( std::string observation ){
            this->observation = observation;
        }

        std::string getObservation() const{
            return this->observation;
        }

        void setState( bool state ){
            this->state = state;
        }

        bool getState() const{
            return this->state;
        }

        int calculate(){
            // return -1    -> erro relativo a nao encontrar o fio que cumpra o calculo //
            // return -2    -> erro relativo a nao encontrar o tipo de lamina que satisfaca o calculo //
            // return -3    -> erro relativo a nao encontrar o tipo de carretel que satisfaca o calculo //
            // return -4    -> erro relativo a alguma divisao por zero ou outro erro aritmetico //
            // return -100  -> erro devido a superar o limite de tentativas de solucao
            try{
                this->setState( false );
                unsigned int index  = 0;

                if( this->getApplyCenterTap() ){
                    this->setVoltageOUT1( 2 * this->getVoltageOUT1() );
                }

                this->setPowerIN( this->getPowerINAuto() );
                this->setCurrentOUT1( this->getCurrentOUT1Auto() );
                this->setCurrentIN1( this->getCurrentIN1Auto() );

                double S21 = this->getCurrentOUT1() / this->getCurrentDensity();
                index   = this->wires->findIndexByArea( S21, this->getWireOUT1()->getType() );
                if( index == 0 ){
                    return -1;
                }
                this->setWireOUT1( this->wires->getWire( index ) );

                double S11 = this->getCurrentIN1() / this->getCurrentDensity();
                index   = this->wires->findIndexByArea( S11, this->getWireIN1()->getType() );
                if( index == 0 ){
                    return -1;
                }
                this->setWireIN1( this->wires->getWire( index ) );

                if( this->getPatternTransformerNumber() > 1 ){
                    this->setCurrentIN2( this->getCurrentIN2Auto() );
                    double S12 = this->getCurrentIN2() / this->getCurrentDensity();
                    index   = this->wires->findIndexByArea( S12, this->getWireIN2()->getType() );
                    if( index == 0 ){
                        return -1;
                    }
                    this->setWireIN2( this->wires->getWire( index ) );
                }

                if( this->getPatternTransformerNumber() % 2 == 1 ){
                    this->setCurrentOUT2( this->getCurrentOUT2Auto() );
                    double S22 = this->getCurrentOUT2() / this->getCurrentDensity();
                    index   = this->wires->findIndexByArea( S22, this->getWireOUT2()->getType() );
                    if( index == 0 ){
                        return -1;
                    }
                    this->setWireOUT2( this->wires->getWire( index ) );
                }

                double SM             = this->getMagneticSectionAuto();
                this->setMagneticSection( SM );

                double SG             = this->getGeometricSectionAuto();
                this->setGeometricSection( SG );

                double widthLaminaMin = sqrt( SG ) * 10.0; // convert to mm //

                int i                 = 0;
                int limit             = 1000;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////// rever como melhorar o processo de repetição ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                while( true ){
                    i = i + 1;

                    if( i > limit ){
                        return -100;
                    }

                    index = this->laminas->findIndexByWidth( widthLaminaMin, this->getLamina()->getType() );
                    if( index == 0 ){
                        return -2;
                    }

                    this->setLamina( this->laminas->getLamina( index ) );

                    widthLaminaMin = this->getLamina()->getWidth();

                    index = this->bobbins->findIndexByWidthAndArea( widthLaminaMin, (SG * 100.0), this->getBobbin()->getType() );
                    if( index == 0 ){
                        return -3;
                    }

                    this->setBobbin( this->bobbins->getBobbin( index ) );

                    SG = (widthLaminaMin * this->getBobbin()->getLength()) / 100.0; // convert to cm^2 //

                    SM = SG;

                    if( this->getApplyCompensationLamina() ){
                        SM = SG / (1 + this->getLamina()->getThicknessPercent()/100.0);
                    }

                    this->setGeometricSection( SG );
                    this->setMagneticSection( SM );

                    // turns = ceil( (this->getVoltageX() * 1e8) / (SM * 4.44 * this->getMagneticInduction() * this->getFrequency() ) ) //
                    this->setWireTurnsIN1( this->getWireTurnsIN1Auto() );
                    this->setWireTurnsOUT1( this->getWireTurnsOUT1Auto() );

                    if( this->getPatternTransformerNumber() > 1 ){
                        unsigned int N = this->getWireTurnsIN2Auto() - this->getWireTurnsIN1();
                        this->setWireTurnsIN2( N );
                    }

                    if( this->getPatternTransformerNumber() % 2 == 1 ){
                        this->setWireTurnsOUT2( this->getWireTurnsOUT2Auto() - this->getWireTurnsOUT1() );
                    }

                    this->setCoilArea( this->getCoilAreaAuto() );

                    if( (this->getLamina()->getWindowArea() / this->getCoilArea()) < this->getWindowAreaPerSectionCu() ){
                        widthLaminaMin = widthLaminaMin + 0.1;
                        continue;
                    }

                    this->setCurrentDensityIN1( this->getCurrentDensityIN1Auto() );
                    this->setCurrentDensityOUT1( this->getCurrentDensityOUT1Auto() );
                    if( this->getPatternTransformerNumber() > 1 ){
                        this->setCurrentDensityIN2( this->getCurrentDensityIN2Auto() );
                    }
                    if( this->getPatternTransformerNumber() % 2 == 1 ){
                        this->setCurrentDensityOUT2( this->getCurrentDensityOUT2Auto() );
                    }

                    this->setAverageCurrentDensity( this->getAverageCurrentDensityAuto() );
                    this->setTurnsAverageLength( this->getTurnAverageLengthAuto() );
                    this->setWeightCopper( this->getWeightCopperAuto() );
                    this->setCopperLoss( this->getCopperLossAuto() );
                    this->setWeigthIron( this->getWeigthIronAuto() );
                    this->setIronLoss( this->getIronLossAuto() );
                    this->setTotalLoss( this->getTotalLossAuto() );
                    this->setEfficiency( this->getEfficiencyAuto() );

                    if( (this->getPatternTransformerNumber() % 2 == 0) && this->getApplyCenterTap() ){
                        this->setVoltageOUT1( this->getVoltageOUT1() / 2.0 );
                        //this->setCurrentOUT1( this->getCurrentOUT1Auto() );
                        //this->setCurrentDensityOUT1( this->getCurrentDensityOUT1Auto() );
                        //this->setWireOUT1( this->wires->getWire( index ) );
                        this->setWireTurnsOUT1( this->getWireTurnsOUT1() / 2 );

                        this->setVoltageOUT2( this->getVoltageOUT1() );
                        this->setCurrentOUT2( this->getCurrentOUT1() );
                        this->setCurrentDensityOUT2( this->getCurrentDensityOUT1() );
                        this->setWireOUT2( this->getWireOUT1() );
                        //this->setWireTurnsOUT2( this->getWireTurnsOUT1() );
                    }

                    this->setState( true );

                    return 0;
                }
            }
            catch( ... ){
                return -4;
            }
        }

        std::string toString() const{
            std::string txt = "";
            txt = txt + "--------------------";
            txt = txt + "GENERAL INFORMATIONS";
            txt = txt + "--------------------\n";

            txt = txt + "Transformer with:     "
                    + std::to_string( this->getPatternTransformerNumber() ) + " ("
                    + this->getPatternTransformerNameAuto() + ")\n";

            txt = txt + "Frequency:            " + std::to_string( this->getFrequency() )             + " Hz\n";
            txt = txt + "Magnetic Induction:   " + std::to_string( this->getMagneticInduction() )     + " G\n";
            txt = txt + "Current Density:      " + std::to_string( this->getCurrentDensity() )        + " A/mm^2\n";
            txt = txt + "Average Cur. Density: " + std::to_string( this->getAverageCurrentDensity() ) + " A/mm^2\n";
            txt = txt + "Weigth Iron:          " + std::to_string( this->getWeigthIron()*1000.0 )     + " g\n";
            txt = txt + "Weight Copper:        " + std::to_string( this->getWeightCopper()*1000.0 )   + " g\n";
            txt = txt + "Turns Average Length: " + std::to_string( this->getTurnAverageLength()/10 )  + " cm\n";
            txt = txt + "Coil Area:            " + std::to_string( this->getCoilArea() )              + " mm^2\n";
            txt = txt + "Iron Loss:            " + std::to_string( this->getIronLoss() )              + " W\n";
            txt = txt + "Copper Loss:          " + std::to_string( this->getCopperLoss() )            + " W\n";
            txt = txt + "Total Loss:           " + std::to_string( this->getTotalLoss() )             + " W\n";
            txt = txt + "Efficiency:           " + std::to_string( this->getEfficiency()*100 )        + " %\n";

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "INPUT";
            txt = txt + "--------------------\n";
            txt = txt + "Power:                " + std::to_string( this->getPowerIN() )             + " W\n";
            txt = txt + "Voltage 1:            " + std::to_string( this->getVoltageIN1() )          + " V\n";
            txt = txt + "Current 1:            " + std::to_string( this->getCurrentIN1() )          + " A\n";
            txt = txt + "AWG wire 1:           " + this->getWireIN1()->getAWG()                     + "\n";
            txt = txt + "Wire turns 1:         " + std::to_string( this->getWireTurnsIN1() )        + "\n";
            txt = txt + "Current Density 1:    " + std::to_string( this->getCurrentDensityIN1() )   + " A/mm^2\n";
            txt = txt + "\n";
            txt = txt + "--> WIRE 1\n";
            txt = txt + this->getWireIN1()->toString();
            txt = txt + "\n";
            if( this->getPatternTransformerNumber() > 1 ){
                txt = txt + "\n";
                txt = txt + "Voltage 2:            " + std::to_string( this->getVoltageIN2() )        + " V\n";
                txt = txt + "Current 2:            " + std::to_string( this->getCurrentIN2() )        + " A\n";
                txt = txt + "AWG wire 2:           " + this->getWireIN2()->getAWG()                   + "\n";
                txt = txt + "Wire turns 2:         " + std::to_string( this->getWireTurnsIN2() )      + "\n";
                txt = txt + "Current Density 2:    " + std::to_string( this->getCurrentDensityIN2() ) + " A/mm^2\n";
                txt = txt + "\n";
                txt = txt + "--> WIRE 2\n";
                txt = txt + this->getWireIN2()->toString();
                txt = txt + "\n";
            }

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "OUTPUT";
            txt = txt + "--------------------\n";
            txt = txt + "Power:                " + std::to_string( this->getPowerOUT() )           + " W\n";
            txt = txt + "Voltage 1:            " + std::to_string( this->getVoltageOUT1() )        + " V\n";
            txt = txt + "Current 1:            " + std::to_string( this->getCurrentOUT1() )        + " A\n";
            txt = txt + "AWG wire 1:           " + this->getWireOUT1()->getAWG()                   + "\n";
            txt = txt + "Wire turns 1:         " + std::to_string( this->getWireTurnsOUT1() )      + "\n";
            txt = txt + "Current Density 1:    " + std::to_string( this->getCurrentDensityOUT1() ) + " A/mm^2\n";
            txt = txt + "\n";
            txt = txt + "--> WIRE 1\n";
            txt = txt + this->getWireOUT1()->toString();
            txt = txt + "\n";
            if( this->getPatternTransformerNumber() % 2 == 1 ){
                txt = txt + "\n";
                txt = txt + "Voltage 2:            " + std::to_string( this->getVoltageOUT2() )        + " V\n";
                txt = txt + "Power 2:              " + std::to_string( this->getPowerOUT() )           + " W\n";
                txt = txt + "Current 2:            " + std::to_string( this->getCurrentOUT2() )        + " A\n";
                txt = txt + "AWG wire 2:           " + this->getWireOUT2()->getAWG()                   + "\n";
                txt = txt + "Wire turns 2:         " + std::to_string( this->getWireTurnsOUT2() )      + "\n";
                txt = txt + "Current Density 2:    " + std::to_string( this->getCurrentDensityOUT2() ) + " A/mm^2\n";
                txt = txt + "\n";
                txt = txt + "--> WIRE 2\n";
                txt = txt + this->getWireOUT2()->toString();
                txt = txt + "\n";
            }

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "LAMINA";
            txt = txt + "--------------------\n";
            txt = txt + this->getLamina()->toString();
            txt = txt + "\n";

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "BOBBIN";
            txt = txt + "--------------------\n";
            txt = txt + this->getBobbin()->toString();
            txt = txt + "\n";

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "OBSERVATIONS:";
            txt = txt + "--------------------\n";
            txt = txt + this->getObservation();

            return txt;
        }

        std::string toHTML() const{
            std::string txt = "";
            txt = txt + "<table align=\"center\" class=\"transformer\" width=\"100%\">\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">GENERAL INFORMATION</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Transformer with: "
                    + std::to_string( this->getPatternTransformerNumber() ) + "("
                    + this->getPatternTransformerNameAuto()  + ")</td><td><b>";

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
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getPowerIN() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage 1:</td><td><b>" + std::to_string( this->getVoltageIN1() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current 1:</td><td><b>" + std::to_string( this->getCurrentIN1() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire 1:</td><td><b>" + this->getWireIN1()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns 1:</td><td><b>" + std::to_string( this->getWireTurnsIN1() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density 1:</td><td><b>" + std::to_string( this->getCurrentDensityIN1() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getWireIN1()->toHTML();
            txt = txt + "\n\t</td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            if( this->getPatternTransformerNumber() > 1 ){
                txt = txt + "\t<tr><td align=\"right\">Voltage 2:</td><td><b>" + std::to_string( this->getVoltageIN2() ) + " V</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current 2:</td><td><b>" + std::to_string( this->getCurrentIN2() ) + " A</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">AWG wire 2:</td><td><b>" + this->getWireIN2()->getAWG() + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Wire turns 2:</td><td><b>" + std::to_string( this->getWireTurnsIN2() ) + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current Density 2:</td><td><b>" + std::to_string( this->getCurrentDensityIN2() ) + " A/mm<sup>2</sup></b></td></tr>\n";
                txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

                txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
                txt = txt + this->getWireIN2()->toHTML();
                txt = txt + "\n\t</td></tr>\n";
                txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            }

            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">OUTPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getPowerOUT() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage 1:</td><td><b>" + std::to_string( this->getVoltageOUT1() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current 1:</td><td><b>" + std::to_string( this->getCurrentOUT1() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire 1:</td><td><b>" + this->getWireOUT1()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns 1:</td><td><b>" + std::to_string( this->getWireTurnsOUT1() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density 1:</td><td><b>" + std::to_string( this->getCurrentDensityOUT1() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getWireOUT1()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

            if( this->getPatternTransformerNumber() % 2 == 1 ){
                txt = txt + "\t<tr><td align=\"right\">Voltage 2:</td><td><b>" + std::to_string( this->getVoltageOUT2() ) + " V</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current 2:</td><td><b>" + std::to_string( this->getCurrentOUT2() ) + " A</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">AWG wire 2:</td><td><b>" + this->getWireOUT2()->getAWG() + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Wire turns 2:</td><td><b>" + std::to_string( this->getWireTurnsOUT2() ) + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current Density 2:</td><td><b>" + std::to_string( this->getCurrentDensityOUT2() ) + " A/mm<sup>2</sup></b></td></tr>\n";
                txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

                txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
                txt = txt + this->getWireOUT2()->toHTML();
                txt = txt + "\n\t</td></tr>\n";
            }

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
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">OBSERVATIONS</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getObservation();
            txt = txt + "\n\t</td></tr>\n";

            txt = txt + "</table>";

            return txt;
        }

        std::string toSQL() const{
            std::string sql = "INSERT INTO transformer";
            sql += "(frequency, magneticInduction, currentDensity, averageCurrentDensity, weigthIron, weightCopper, ";
            sql += "turnsAverageLength, coilArea, windowAreaPerSectionTurns, ironLoss, copperLoss, totalLoss, efficiency, ";
            sql += "patternTransformerNumber, patternTransformerName, centerTap, compensationLossTransformer, ";
            sql += "powerIN, voltageIN1, currentIN1, currentDensityIN1, ";
            sql += "wireIDIN1, wireTypeIN1, wireAWGIN1, wireTurnsIN1, wireDiameterIN1, wireTurnPerCmIN1, wireAreaIN1, ";
            sql += "wireResistanceIN1, wireWeightIN1, wireLengthIN1, wireFrequencyIN1, wireMaterialIN1, ";
            sql += "voltageIN2, currentIN2, currentDensityIN2, ";
            sql += "wireIDIN2, wireTypeIN2, wireAWGIN2, wireTurnsIN2, wireDiameterIN2, wireTurnPerCmIN2, wireAreaIN2, ";
            sql += "wireResistanceIN2, wireWeightIN2, wireLengthIN2, wireFrequencyIN2, wireMaterialIN2, ";
            sql += "powerOUT, voltageOUT1, currentOUT1, currentDensityOUT1, ";
            sql += "wireIDOUT1, wireTypeOUT1, wireAWGOUT1, wireTurnsOUT1, wireDiameterOUT1, wireTurnPerCmOUT1, wireAreaOUT1, ";
            sql += "wireResistanceOUT1, wireWeightOUT1, wireLengthOUT1, wireFrequencyOUT1, wireMaterialOUT1, ";
            sql += "voltageOUT2, currentOUT2, currentDensityOUT2, ";
            sql += "wireIDOUT2, wireTypeOUT2, wireAWGOUT2, wireTurnsOUT2, wireDiameterOUT2, wireTurnPerCmOUT2, wireAreaOUT2, ";
            sql += "wireResistanceOUT2, wireWeightOUT2, wireLengthOUT2, wireFrequencyOUT2, wireMaterialOUT2, ";
            sql += "laminaID, laminaType, laminaWidth, laminaWindowArea, laminaWeight, laminaCompensation, ";
            sql += "bobbinID, bobbinType, bobbinCode, bobbinProvider, bobbinWidth, bobbinLength, bobbinHeight, bobbinArea, observation ) ";
            sql += "VALUES (";
            sql += std::to_string( this->getFrequency() ) + ", ";                   // frequency
            sql += std::to_string( this->getMagneticInduction() ) + ", ";           // magneticInduction
            sql += std::to_string( this->getCurrentDensity() ) + ", ";              // currentDensity
            sql += std::to_string( this->getAverageCurrentDensity() ) + ", ";       // averageCurrentDensity
            sql += std::to_string( this->getWeigthIron() ) + ", ";                  // weigthIron
            sql += std::to_string( this->getWeightCopper() ) + ", ";                // weightCopper
            sql += std::to_string( this->getTurnAverageLength() ) + ", ";           // turnsAverageLength
            sql += std::to_string( this->getCoilArea() ) + ", ";                    // coilArea
            sql += std::to_string( this->getWindowAreaPerSectionCu() ) + ", ";      // windowAreaPerSectionTurns
            sql += std::to_string( this->getIronLoss() ) + ", ";                    // ironLoss
            sql += std::to_string( this->getCopperLoss() ) + ", ";                  // copperLoss
            sql += std::to_string( this->getTotalLoss() ) + ", ";                   // totalLoss
            sql += std::to_string( this->getEfficiency() ) + ", ";                  // efficiency

            sql += std::to_string( this->getPatternTransformerNumber() ) + ", '";   // patternTransformerNumber
            sql += this->getPatternTransformerName() + "', ";                       // patternTransformerName
            if( this->getApplyCenterTap() ){
                sql += "TRUE, ";
            }
            else{
                sql += "FALSE, ";
            }
            if( this->getApplyCompensationTransformer() ){
                sql += std::to_string( this->getCompensationLossTransformer() ) + ", "; //compensationLossTransformer
            }
            else{
                sql += "0.0, "; // compensationLossTransformer,
            }
            sql += std::to_string( this->getPowerIN() ) + ", ";                     // powerIN

            sql += std::to_string( this->getVoltageIN1() ) + ",	";                  // voltageIN1
            sql += std::to_string( this->getCurrentIN1() ) + ", ";                  // currentIN1
            sql += std::to_string( this->getCurrentDensityIN1() ) + ", ";           // currentDensityIN1
            sql += std::to_string( this->getWireIN1()->getId() ) + ", ";            // wireIDIN1
            sql += "'" + this->getWireIN1()->getType() + "', ";                     // wireTypeIN1
            sql += "'" + this->getWireIN1()->getAWG() + "', ";                      // wireAWGIN1
            sql += std::to_string( this->getWireTurnsIN1() ) + ", ";                // wireTurnsIN1
            sql += std::to_string( this->getWireIN1()->getDiameter() ) + ", ";      // wireDiameterIN1
            sql += std::to_string( this->getWireIN1()->getTurnsPerCm() ) + ", ";    // wireTurnPerCmIN1
            sql += std::to_string( this->getWireIN1()->getArea() ) + ", ";          // wireAreaIN1
            sql += std::to_string( this->getWireIN1()->getResistance() ) + ", ";    // wireResistanceIN1
            sql += std::to_string( this->getWireIN1()->getWeight() ) + ", ";        // wireWeightIN1
            sql += std::to_string( this->getWireIN1()->getLength() ) + ", ";        // wireLengthIN1
            sql += std::to_string( this->getWireIN1()->getFrequency() ) + ", ";     // wireFrequencyIN1
            sql += "'" + this->getWireIN1()->getMaterial() + "', ";                 // wireMaterialIN1

            sql += std::to_string( this->getVoltageIN2() ) + ",	";                  // voltageIN2
            sql += std::to_string( this->getCurrentIN2() ) + ", ";                  // currentIN2
            sql += std::to_string( this->getCurrentDensityIN2() ) + ", ";           // currentDensityIN2
            sql += std::to_string( this->getWireIN2()->getId() ) + ", ";            // wireIDIN2
            sql += "'" + this->getWireIN2()->getType() + "', ";                     // wireTypeIN2
            sql += "'" + this->getWireIN2()->getAWG() + "', ";                      // wireAWGIN2
            sql += std::to_string( this->getWireTurnsIN2() ) + ", ";                // wireTurnsIN2
            sql += std::to_string( this->getWireIN2()->getDiameter() ) + ", ";      // wireDiameterIN2
            sql += std::to_string( this->getWireIN2()->getTurnsPerCm() ) + ", ";    // wireTurnPerCmIN2
            sql += std::to_string( this->getWireIN2()->getArea() ) + ", ";          // wireAreaIN2
            sql += std::to_string( this->getWireIN2()->getResistance() ) + ", ";    // wireResistanceIN2
            sql += std::to_string( this->getWireIN2()->getWeight() ) + ", ";        // wireWeightIN2
            sql += std::to_string( this->getWireIN2()->getLength() ) + ", ";        // wireLengthIN2
            sql += std::to_string( this->getWireIN2()->getFrequency() ) + ", ";     // wireFrequencyIN2
            sql += "'" + this->getWireIN2()->getMaterial() + "', ";                 // wireMaterialIN2

            sql += std::to_string( this->getPowerOUT() ) + ", ";                    // powerOUT

            sql += std::to_string( this->getVoltageOUT1() ) + ",	";              // voltageOUT1
            sql += std::to_string( this->getCurrentOUT1() ) + ", ";                 // currentOUT1
            sql += std::to_string( this->getCurrentDensityOUT1() ) + ", ";          // currentDensityOUT1
            sql += std::to_string( this->getWireOUT1()->getId() ) + ", ";           // wireIDOUT1
            sql += "'" + this->getWireOUT1()->getType() + "', ";                    // wireTypeOUT1
            sql += "'" + this->getWireOUT1()->getAWG() + "', ";                     // wireAWGOUT1
            sql += std::to_string( this->getWireTurnsOUT1() ) + ", ";               // wireTurnsOUT1
            sql += std::to_string( this->getWireOUT1()->getDiameter() ) + ", ";     // wireDiameterOUT1
            sql += std::to_string( this->getWireOUT1()->getTurnsPerCm() ) + ", ";   // wireTurnPerCmOUT1
            sql += std::to_string( this->getWireOUT1()->getArea() ) + ", ";         // wireAreaOUT1
            sql += std::to_string( this->getWireOUT1()->getResistance() ) + ", ";   // wireResistanceOUT1
            sql += std::to_string( this->getWireOUT1()->getWeight() ) + ", ";       // wireWeightOUT1
            sql += std::to_string( this->getWireOUT1()->getLength() ) + ", ";       // wireLengthOUT1
            sql += std::to_string( this->getWireOUT1()->getFrequency() ) + ", ";    // wireFrequencyOUT1
            sql += "'" + this->getWireOUT1()->getMaterial() + "', ";                // wireMaterialOUT1

            sql += std::to_string( this->getVoltageOUT2() ) + ",	";              // voltageOUT2
            sql += std::to_string( this->getCurrentOUT2() ) + ", ";                 // currentOUT2
            sql += std::to_string( this->getCurrentDensityOUT2() ) + ", ";          // currentDensityOUT2
            sql += std::to_string( this->getWireOUT2()->getId() ) + ", ";           // wireIDOUT2
            sql += "'" + this->getWireOUT2()->getType() + "', ";                    // wireTypeOUT2
            sql += "'" + this->getWireOUT2()->getAWG() + "', ";                     // wireAWGOUT2
            sql += std::to_string( this->getWireTurnsOUT2() ) + ", ";               // wireTurnsOUT2
            sql += std::to_string( this->getWireOUT2()->getDiameter() ) + ", ";     // wireDiameterOUT2
            sql += std::to_string( this->getWireOUT2()->getTurnsPerCm() ) + ", ";   // wireTurnPerCmOUT2
            sql += std::to_string( this->getWireOUT2()->getArea() ) + ", ";         // wireAreaOUT2
            sql += std::to_string( this->getWireOUT2()->getResistance() ) + ", ";   // wireResistanceOUT2
            sql += std::to_string( this->getWireOUT2()->getWeight() ) + ", ";       // wireWeightOUT2
            sql += std::to_string( this->getWireOUT2()->getLength() ) + ", ";       // wireLengthOUT2
            sql += std::to_string( this->getWireOUT2()->getFrequency() ) + ", ";    // wireFrequencyOUT2
            sql += "'" + this->getWireOUT2()->getMaterial() + "', ";                // wireMaterialOUT2

            sql += std::to_string( this->getLamina()->getId() ) + ", ";             // laminaID
            sql += "'" + this->getLamina()->getType() + "', ";                       // laminaType
            sql += std::to_string( this->getLamina()->getWidth() ) + ", ";           // laminaWidth
            sql += std::to_string( this->getLamina()->getWindowArea() ) + ", ";      // laminaWindowArea
            sql += std::to_string( this->getLamina()->getWeight() ) + ", ";          // laminaWeight
            if( this->getApplyCompensationLamina() ){
                sql += std::to_string( this->getLamina()->getThicknessPercent() ) + ", ";// laminaCompensation
            }
            else{
                sql += "0.0, "; // laminaCompensation,
            }

            sql += std::to_string( this->getBobbin()->getId() ) + ", ";              // bobbinID
            sql += "'" + this->getBobbin()->getType() + "', ";                       // bobbinType
            sql += "'" + this->getBobbin()->getCode() + "', ";                       // bobbinCode
            sql += "'" + this->getBobbin()->getProvider() + "', ";                   // bobbinProvider
            sql += std::to_string( this->getBobbin()->getWidth() ) + ", ";           // bobbinWidth
            sql += std::to_string( this->getBobbin()->getLength() ) + ", ";          // bobbinLength
            sql += std::to_string( this->getBobbin()->getHeight() ) + ", ";          // bobbinHeight
            sql += std::to_string( this->getBobbin()->getArea() ) + ", ";            // bobbinArea

            sql += "'" + this->getObservation() + "' )";                             // observation

            return sql;
        }
};

#endif // TRANSFORMER_H
