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

enum MethodLaminaCompensation { NotApplied, LaminaCompensation, FieldCompensation };
// return 0     -> nenhum erro
 // return -1    -> erro relativo a nao encontrar o fio que cumpra o calculo //
 // return -2    -> erro relativo a nao encontrar o tipo de lamina que satisfaca o calculo //
 // return -3    -> erro relativo a nao encontrar o tipo de carretel que satisfaca o calculo //
 // return -4    -> erro relativo a alguma divisao por zero ou outro erro aritmetico //
 // return -10   -> erro relativo a não tratamento de calculo de outros tipos de transformadores //
 // return -100  -> erro devido a superar o limite de tentativas de solucao
enum ResultCalculus { CorrectResult, NotFoundWire, NotFoundLamina, NotFoundBobbin, ErrorAritmetic, NotTransformPatter, UnderflowTry };

class Transformer{

	private:
        DataBase* database;
        std::string databaseName;
        Wires* wires;
        Laminas* laminas;
        Bobbins* bobbins;

        unsigned int id;
        double frequency;                // Hz
        double magneticInduction;        // G
        double currentDensity;           // A/mm2
        double averageCurrentDensity;    // A/mm2
        double weightIron;               // kg
        double weightCopper;             // kg
        double averageTurnLength;        // mm
        double copperArea;               // mm^2
        double ironLoss;                 // W
        double copperLoss;               // W
        double totalLoss;                // W
        double efficiency;               // %

        unsigned int transformerPatternNumber; // number: 0 -> name: 1 primary and 1 secondary
        std::string transformerPatternName;    // number: 1 -> name: 2 primaries and 1 secondary
                                               // number: 2 -> name: 1 primary and 2 secondaries
                                               // number: 3 -> name: 2 primaries and 2 secondaries
        bool applyCenterTap;
        bool applyTransformerLossCompensation;  // true to apply and false, otherwise
        double transformerLossCompensation; // 0 <= C.L.T. <= 100%;
        double windowAreaPerSectionCopper;  // 3.0

        double inputPower;               // W
        double inputVoltage1;            // V
        double inputVoltage2;            // V
        double inputCurrent1;            // A
        double inputCurrent2;            // A
        double inputCurrentDensity1;     // A/mm2
        double inputCurrentDensity2;     // A/mm2
        unsigned int inputWireTurns1;    // esp
        unsigned int inputWireTurns2;    // esp

        Wire* inputWire1;
        Wire* inputWire2;

        double outputPower;              // W
        double outputVoltage1;           // V
        double outputVoltage2;           // V
        double outputCurrent1;           // A
        double outputCurrent2;           // A
        double outputCurrentDensity1;    // A/mm2
        double outputCurrentDensity2;    // A/mm2
        unsigned int outputWireTurns1;   // esp
        unsigned int outputWireTurns2;   // esp

        Wire* outputWire1;
        Wire* outputWire2;

        double magneticSection;          // cm2
        double geometricSection;         // cm2

        MethodLaminaCompensation methodLaminaLossCompensation;  // 0 - not applied
                                                                // 1 - using lamina compensation
                                                                // 2 - using field compensation
        double laminaLossCompensation;                          // 0 <= C.L.T. <= 100%;
        Lamina* lamina;
        Bobbin* bobbin;

        std::string observation;

	public:
        Transformer( DataBase* database ){
            this->database                    = database;
            this->databaseName                = "transformers";
            this->wires                       = new Wires( database );
            this->laminas                     = new Laminas( database );
            this->bobbins                     = new Bobbins( database );

            this->id                          = 0;
            this->frequency                   = 0.0;
            this->magneticInduction           = 0.0;
            this->currentDensity              = 0.0;
            this->averageCurrentDensity       = 0.0;
            this->weightIron                  = 0.0;
            this->weightCopper                = 0.0;
            this->averageTurnLength           = 0.0;
            this->copperArea                  = 0.0;
            this->ironLoss                    = 0.0;
            this->copperLoss                  = 0.0;
            this->totalLoss                   = 0.0;
            this->efficiency                  = 0.0;

            this->transformerPatternNumber    = 0;
            this->transformerPatternName      = "";
            this->applyCenterTap              = false;
            this->applyTransformerLossCompensation= true;
            this->transformerLossCompensation = 0.0;
            this->windowAreaPerSectionCopper  = 0.0;

            this->inputPower                  = 0.0;
            this->inputVoltage1               = 0.0;
            this->inputVoltage2               = 0.0;
            this->inputCurrent1               = 0.0;
            this->inputCurrent2               = 0.0;
            this->inputCurrentDensity1        = 0.0;
            this->inputCurrentDensity2        = 0.0;
            this->inputWireTurns1             = 0;
            this->inputWireTurns2             = 0;
            this->inputWire1                  = new Wire();
            this->inputWire2                  = new Wire();

            this->outputPower                 = 0.0;
            this->outputVoltage1              = 0.0;
            this->outputVoltage2              = 0.0;
            this->outputCurrent1              = 0.0;
            this->outputCurrent2              = 0.0;
            this->outputCurrentDensity1       = 0.0;
            this->outputCurrentDensity2       = 0.0;
            this->outputWireTurns1            = 0;
            this->outputWireTurns2            = 0;
            this->outputWire1                 = new Wire();
            this->outputWire2                 = new Wire();

            this->magneticSection             = 0.0;
            this->geometricSection            = 0.0;

            this->lamina                      = new Lamina();
            this->methodLaminaLossCompensation= MethodLaminaCompensation::NotApplied;
            this->laminaLossCompensation      = 0.0;
            this->bobbin                      = new Bobbin();

            this->observation                 = "";
		}

        void setDatabase( DataBase* database ){
            this->database = database;
        }

        void setDatabaseName( std::string name ){
            this->databaseName = name;
        }

        std::string getDatabaseName() const{
            return this->databaseName;
        }

        void setId( unsigned int id ){
            this->id = id;
        }

        unsigned int getId() const{
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
            switch( this->getTransformerPatternNumber() ){
                case 0:
                    return (this->getInputCurrentDensity1() + this->getOutputCurrentDensity1()) / 2.0;
                case 1:
                    return (this->getInputCurrentDensity1() + this->getOutputCurrentDensity1() + this->getOutputCurrentDensity2()) / 3.0;
                case 2:
                    return (this->getInputCurrentDensity1() + this->getInputCurrentDensity2() + this->getOutputCurrentDensity1()) / 3.0;
                case 3:
                    return (this->getInputCurrentDensity1() + this->getInputCurrentDensity2() + this->getOutputCurrentDensity1() + this->getOutputCurrentDensity2()) / 4.0;
                default:
                    return 0.0;
            }
        }

        void setWeightIron( double weigthIron ){
            this->weightIron = weigthIron;
        }

        double getWeightIron() const{
            return this->weightIron;
        }

        double getWeightIronAuto() const{
            return (this->getBobbin()->getLength() / 10.0) * this->getLamina()->getWeight();
        }

        void setWeightCopper( double weightCopper ){
            this->weightCopper = weightCopper;
        }

        double getWeightCopper() const{
            return this->weightCopper;
        }

        double getWeightCopperAuto() const{
            return (this->getCopperArea()/100.0) * (this->getAverageTurnLength()/10.0) * 8.9 / 1000.0;
        }

        void setAverageTurnLength( double averageTurnLength ){
            this->averageTurnLength = averageTurnLength;
        }

        double getAverageTurnLength() const{
            return this->averageTurnLength;
        }

        double getTurnAverageLengthAuto() const{
            return (2.0 + 0.5 * PI) * this->getLamina()->getWidth() + 2.0 * this->getBobbin()->getLength();
        }

        void setCopperArea( double copperArea ){
            this->copperArea = copperArea;
        }

        double getCopperArea() const{
            return this->copperArea;
        }

        double getCopperAreaAuto() const{
            switch( this->getTransformerPatternNumber() ){
                case 0:
                    return this->getInputWireTurns1() * this->getInputWire1()->getArea() + this->getOutputWireTurns1() * this->getOutputWire1()->getArea();
                case 1:
                    return this->getInputWireTurns1() * this->getInputWire1()->getArea() + this->getOutputWireTurns1() * this->getOutputWire1()->getArea() + this->getOutputWireTurns2() * this->getOutputWire2()->getArea();
                case 2:
                    return this->getInputWireTurns1() * this->getInputWire1()->getArea() + this->getInputWireTurns2() * this->getInputWire2()->getArea() + this->getOutputWireTurns1() * this->getOutputWire1()->getArea();
                case 3:
                    return this->getInputWireTurns1() * this->getInputWire1()->getArea() + this->getInputWireTurns2() * this->getInputWire2()->getArea() + this->getOutputWireTurns1() * this->getOutputWire1()->getArea() + this->getOutputWireTurns2() * this->getOutputWire2()->getArea();

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
            return 1.15 * wfe * this->getWeightIron();
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
                return 100.0 * this->getOutputPower() / (this->getOutputPower() + this->getIronLoss() + this->getCopperLoss());
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setTransformerPatternNumber( unsigned int transformerPatternNumber ){
            this->transformerPatternNumber = transformerPatternNumber;
        }

        unsigned int getTransformerPatternNumber() const{
            return this->transformerPatternNumber;
        }

        void setTransformerPatternName( std::string transformerPatternName ){
            this->transformerPatternName = transformerPatternName;
        }

        std::string getTransformerPatternName() const{
            return this->transformerPatternName;
        }

        std::string getTransformerPatternNameAuto() const{
            std::string str;
            unsigned int patternNumber = this->getTransformerPatternNumber();
            if( patternNumber <= 3 ){
                switch( patternNumber ) {
                    case 0:
                        str = "1 primary and 1 secondary";
                        break;
                    case 1:
                        str = "1 primary and 2 secondaries";
                        break;
                    case 2:
                        str = "2 primaries and 1 secondary";
                        break;
                    case 3:
                        str = "2 primaries and 2 secondaries";
                }
            }
            else{
                str = "defined by user: " + this->getTransformerPatternName();
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

        void setApplyTransformerLossCompensation( bool state ){
            this->applyTransformerLossCompensation = state;
        }

        bool getApplyTransformerLossCompensation() const{
            return this->applyTransformerLossCompensation;
        }

        void setTransformerLossCompensation( double transformerLossCompensation ){
            this->transformerLossCompensation = transformerLossCompensation;
        }

        double getTransformerLossCompensation() const{
            return this->transformerLossCompensation;
        }

        void setWindowAreaPerSectionCopper( double windowAreaPerSectionCopper ){
            this->windowAreaPerSectionCopper = windowAreaPerSectionCopper;
        }

        double getWindowAreaPerSectionCopper() const{
            return this->windowAreaPerSectionCopper;
        }

        void setInputVoltage1( double voltage ){
            this->inputVoltage1 = voltage;
        }

        double getInputVoltage1() const{
            return this->inputVoltage1;
        }

        void setInputVoltage2( double voltage ){
            this->inputVoltage2 = voltage;
        }

        double getInputVoltage2() const{
            return this->inputVoltage2;
        }

        void setInputPower( double power ){
            this->inputPower = power;
        }

        double getInputPower() const{
            return this->inputPower;
        }

        double getInputPowerAuto() const{
            if( this->getApplyTransformerLossCompensation() ){
                return (1.0 + this->getTransformerLossCompensation()/100.0) * this->getOutputPower();
            }
            else{
                return this->getOutputPower();
            }
        }

        void setInputCurrent1( double current ){
            this->inputCurrent1 = current;
        }

        double getInputCurrent1() const{
            return this->inputCurrent1;
        }

        double getInputCurrent1Auto() const{
            try{
                return this->getInputPower() / this->getInputVoltage1();
            }
            catch(...){
                return 0.0;
            }
        }

        void setInputCurrent2( double current ){
            this->inputCurrent2 = current;
        }

        double getInputCurrent2() const{
            return this->inputCurrent2;
        }

        double getInputCurrent2Auto() const{
            try{
                return this->getInputPower() / this->getInputVoltage2();
            }
            catch(...){
                return 0.0;
            }
        }

        void setInputCurrentDensity1( double currentDensity ){
            this->inputCurrentDensity1 = currentDensity;
        }

        double getInputCurrentDensity1() const{
            return this->inputCurrentDensity1;
        }

        double getInputCurrentDensity1Auto() const{
            try{
                return this->getInputCurrent1() / this->getInputWire1()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setInputCurrentDensity2( double currentDensity ){
            this->inputCurrentDensity2 = currentDensity;
        }

        double getInputCurrentDensity2() const{
            return this->inputCurrentDensity2;
        }

        double getInputCurrentDensity2Auto() const{
            try{
                return this->getInputCurrent2() / this->getInputWire2()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setInputWire1( Wire* wire ){
            this->inputWire1 = wire;
        }

        Wire* getInputWire1() const{
            return this->inputWire1;
        }

        void setInputWire2( Wire* wire ){
            this->inputWire2 = wire;
        }

        Wire* getInputWire2() const{
            return this->inputWire2;
        }

        void setInputWireTurns1( unsigned int turns ){
            this->inputWireTurns1 = turns;
        }

        unsigned int getInputWireTurns1() const{
            return this->inputWireTurns1;
        }

        unsigned int getInputWireTurns1Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyTransformerLossCompensation ){
                    N = static_cast<unsigned int>( ceil( ( (this->getInputVoltage1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getTransformerLossCompensation()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getInputVoltage1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setInputWireTurns2( unsigned int turns ){
            this->inputWireTurns2 = turns;
        }

        unsigned int getInputWireTurns2() const{
            return this->inputWireTurns2;
        }

        unsigned int getInputWireTurns2Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyTransformerLossCompensation ){
                    N = static_cast<unsigned int>( ceil( ( (this->getInputVoltage2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getTransformerLossCompensation()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getInputVoltage2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setOutputVoltage1( double voltage ){
            this->outputVoltage1 = voltage;
        }

        double getOutputVoltage1() const{
            return this->outputVoltage1;
        }

        void setOutputVoltage2( double voltage ){
            this->outputVoltage2 = voltage;
        }

        double getOutputVoltage2() const{
            return this->outputVoltage2;
        }

        void setOutputPower( double power ){
            this->outputPower = power;
        }

        double getOutputPower() const{
            return this->outputPower;
        }

        void setOutputCurrent1( double current ){
            this->outputCurrent1 = current;
        }

        double getOutputCurrent1() const{
            return this->outputCurrent1;
        }

        double getOutputCurrent1Auto() const{
            try{
                return this->getOutputPower() / this->getOutputVoltage1();
            }
            catch(...){
                return 0.0;
            }
        }

        void setOutputCurrent2( double current ){
            this->outputCurrent2 = current;
        }

        double getOutputCurrent2() const{
            return this->outputCurrent2;
        }

        double getOutputCurrent2Auto() const{
            try{
                return this->getOutputPower() / this->getOutputVoltage2();
            }
            catch(...){
                return 0.0;
            }
        }

        void setOutputCurrentDensity1( double currentDensity ){
            this->outputCurrentDensity1 = currentDensity;
        }

        double getOutputCurrentDensity1() const{
            return outputCurrentDensity1;
        }

        double getOutputCurrentDensity1Auto() const{
            try{
                return this->getOutputCurrent1() / this->getOutputWire1()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setOutputCurrentDensity2( double currentDensity ){

            this->outputCurrentDensity2 = currentDensity;
        }

        double getOutputCurrentDensity2() const{
            return outputCurrentDensity2;
        }

        double getOutputCurrentDensity2Auto() const{
            try{
                return this->getOutputCurrent2() / this->getOutputWire2()->getArea();
            }
            catch( ... ){
                return 0.0;
            }
        }

        void setOutputWire1( Wire* wire ){
            this->outputWire1 = wire;
        }

        Wire* getOutputWire1() const{
            return this->outputWire1;
        }

        void setOutputWire2( Wire* wire ){
            this->outputWire2 = wire;
        }

        Wire* getOutputWire2() const{
            return this->outputWire2;
        }

        void setOutputWireTurns1( unsigned int turns ){
            this->outputWireTurns1 = turns;
        }

        unsigned int getOutputWireTurns1() const{
            return this->outputWireTurns1;
        }

        unsigned int getOutputWireTurns1Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyTransformerLossCompensation ){
                    N = static_cast<unsigned int>( ceil( ( (this->getOutputVoltage1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getTransformerLossCompensation()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getOutputVoltage1() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
                }
                return N;
            }
            catch(...){
                return 0;
            }
        }

        void setOutputWireTurns2( unsigned int turns ){
            this->outputWireTurns2 = turns;
        }

        unsigned int getOutputWireTurns2() const{
            return this->outputWireTurns2;
        }

        unsigned int getOutputWireTurns2Auto() const{
            try{
                unsigned int N = 0;
                if( this->applyTransformerLossCompensation ){
                    N = static_cast<unsigned int>( ceil( ( (this->getOutputVoltage2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) * (1.0 + this->getTransformerLossCompensation()/100.0) ) );
                }
                else{
                    N = static_cast<unsigned int>( ceil( (this->getOutputVoltage2() * 1e8) / (this->getMagneticSection() * 4.44 * this->getMagneticInduction() * this->getFrequency()) ) );
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
            double SM = this->getOutputPower() / this->getFrequency();

            switch( this->getTransformerPatternNumber() ){
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
            switch( this->getMethodLaminaLossCompensation() ){
                case MethodLaminaCompensation::NotApplied:
                    return this->getMagneticSectionAuto();

                case MethodLaminaCompensation::FieldCompensation:
                    return (1 + this->getLaminaLossCompensation()/100.0) * this->getMagneticSectionAuto();

                case MethodLaminaCompensation::LaminaCompensation:
                    return (1 + this->getLamina()->getThicknessPercent()/100.0) * this->getMagneticSectionAuto();
            }
            return 0.0;
        }

        void setMethodLaminaLossCompensation( MethodLaminaCompensation method ){
            this->methodLaminaLossCompensation = method;
        }

        MethodLaminaCompensation getMethodLaminaLossCompensation() const{
            return this->methodLaminaLossCompensation;
        }

        void setLaminaLossCompensation( double compensation ){
            this->laminaLossCompensation = compensation;
        }

        double getLaminaLossCompensation() const{
            return this->laminaLossCompensation;
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

        int calculate(){
            try{
                unsigned int index  = 0;

                if( this->getApplyCenterTap() ){
                    this->setOutputVoltage1( 2 * this->getOutputVoltage1() );
                }

                this->setInputPower( this->getInputPowerAuto() );
                this->setOutputCurrent1( this->getOutputCurrent1Auto() );
                this->setInputCurrent1( this->getInputCurrent1Auto() );

                double S21 = this->getOutputCurrent1() / this->getCurrentDensity();
                index   = this->wires->findIndexByArea( S21, this->getOutputWire1()->getType() );
                if( index == 0 ){
                    return ResultCalculus::NotFoundWire;
                }
                this->setOutputWire1( this->wires->getWire( index ) );

                double S11 = this->getInputCurrent1() / this->getCurrentDensity();
                index   = this->wires->findIndexByArea( S11, this->getInputWire1()->getType() );
                if( index == 0 ){
                    return ResultCalculus::NotFoundWire;
                }
                this->setInputWire1( this->wires->getWire( index ) );

                if( this->getTransformerPatternNumber() > 3 ){
                    return ResultCalculus::NotTransformPatter;
                }

                if( this->getTransformerPatternNumber() > 1 ){
                    this->setInputCurrent2( this->getInputCurrent2Auto() );
                    double S12 = this->getInputCurrent2() / this->getCurrentDensity();
                    index   = this->wires->findIndexByArea( S12, this->getInputWire2()->getType() );
                    if( index == 0 ){
                        return ResultCalculus::NotFoundWire;
                    }
                    this->setInputWire2( this->wires->getWire( index ) );
                }

                if( this->getTransformerPatternNumber() % 2 == 1 ){
                    this->setOutputCurrent2( this->getOutputCurrent2Auto() );
                    double S22 = this->getOutputCurrent2() / this->getCurrentDensity();
                    index   = this->wires->findIndexByArea( S22, this->getOutputWire2()->getType() );
                    if( index == 0 ){
                        return ResultCalculus::NotFoundWire;
                    }
                    this->setOutputWire2( this->wires->getWire( index ) );
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
                        return ResultCalculus::UnderflowTry;
                    }

                    index = this->laminas->findIndexByWidth( widthLaminaMin, this->getLamina()->getType() );
                    if( index == 0 ){
                        return ResultCalculus::NotFoundLamina;
                    }

                    this->setLamina( this->laminas->getLamina( index ) );

                    widthLaminaMin = this->getLamina()->getWidth();

                    index = this->bobbins->findIndexByWidthAndArea( widthLaminaMin, (SG * 100.0), this->getBobbin()->getType() );
                    if( index == 0 ){
                        return ResultCalculus::NotFoundBobbin;
                    }

                    this->setBobbin( this->bobbins->getBobbin( index ) );

                    SG = (widthLaminaMin * this->getBobbin()->getLength()) / 100.0; // convert to cm^2 //

                    SM = SG;

                    switch( this->getMethodLaminaLossCompensation() ) {
                        case MethodLaminaCompensation::NotApplied:
                            SM = SG;
                            break;
                        case MethodLaminaCompensation::FieldCompensation:
                            SM = SG / (1 + this->getLaminaLossCompensation()/100.0);
                            break;
                        case MethodLaminaCompensation::LaminaCompensation:
                            SM = SG / (1 + this->getLamina()->getThicknessPercent()/100.0);
                            break;
                    }

                    this->setGeometricSection( SG );
                    this->setMagneticSection( SM );

                    // turns = ceil( (this->getVoltageX() * 1e8) / (SM * 4.44 * this->getMagneticInduction() * this->getFrequency() ) ) //
                    this->setInputWireTurns1( this->getInputWireTurns1Auto() );
                    this->setOutputWireTurns1( this->getOutputWireTurns1Auto() );

                    if( this->getTransformerPatternNumber() > 1 ){
                        unsigned int N = this->getInputWireTurns2Auto() - this->getInputWireTurns1();
                        this->setInputWireTurns2( N );
                    }

                    if( this->getTransformerPatternNumber() % 2 == 1 ){
                        this->setOutputWireTurns2( this->getOutputWireTurns2Auto() - this->getOutputWireTurns1() );
                    }

                    this->setCopperArea( this->getCopperAreaAuto() );

                    if( (this->getLamina()->getWindowArea() / this->getCopperArea()) < this->getWindowAreaPerSectionCopper() ){
                        widthLaminaMin = widthLaminaMin + 0.1;
                        continue;
                    }

                    this->setInputCurrentDensity1( this->getInputCurrentDensity1Auto() );
                    this->setOutputCurrentDensity1( this->getOutputCurrentDensity1Auto() );
                    if( this->getTransformerPatternNumber() > 1 ){
                        this->setInputCurrentDensity2( this->getInputCurrentDensity2Auto() );
                    }
                    if( this->getTransformerPatternNumber() % 2 == 1 ){
                        this->setOutputCurrentDensity2( this->getOutputCurrentDensity2Auto() );
                    }

                    this->setAverageCurrentDensity( this->getAverageCurrentDensityAuto() );
                    this->setAverageTurnLength( this->getTurnAverageLengthAuto() );
                    this->setWeightCopper( this->getWeightCopperAuto() );
                    this->setCopperLoss( this->getCopperLossAuto() );
                    this->setWeightIron( this->getWeightIronAuto() );
                    this->setIronLoss( this->getIronLossAuto() );
                    this->setTotalLoss( this->getTotalLossAuto() );
                    this->setEfficiency( this->getEfficiencyAuto() );

                    if( (this->getTransformerPatternNumber() % 2 == 0) && this->getApplyCenterTap() ){
                        this->setOutputVoltage1( this->getOutputVoltage1() / 2.0 );
                        //this->setCurrentOUT1( this->getCurrentOUT1Auto() );
                        //this->setCurrentDensityOUT1( this->getCurrentDensityOUT1Auto() );
                        //this->setWireOUT1( this->wires->getWire( index ) );
                        this->setOutputWireTurns1( this->getOutputWireTurns1() / 2 );

                        this->setOutputVoltage2( this->getOutputVoltage1() );
                        this->setOutputCurrent2( this->getOutputCurrent1() );
                        this->setOutputCurrentDensity2( this->getOutputCurrentDensity1() );
                        this->setOutputWire2( this->getOutputWire1() );
                        //this->setWireTurnsOUT2( this->getWireTurnsOUT1() );
                    }

                    if( this->getMethodLaminaLossCompensation() == MethodLaminaCompensation::LaminaCompensation ) {
                        this->setLaminaLossCompensation( this->getLamina()->getThicknessPercent() );
                    }

                    return ResultCalculus::CorrectResult;
                }
            }
            catch( ... ){
                return ResultCalculus::ErrorAritmetic;
            }
        }

        int validate( double precision ){
            // 1 - relacao de entrada //
            try{
                // to do center tap //

                if( fabs(this->getInputPower() - (this->getInputVoltage1() * this->getInputCurrent1())) > precision ){
                    return 111;
                }

                if( fabs(this->getInputPower() - (this->getInputVoltage2() * this->getInputCurrent2())) > precision ){
                    return 111;
                }

                if( fabs(this->getInputWire1()->getArea()*this->getCurrentDensity() - this->getInputCurrent1()) > precision ){
                    return 111;
                }

                if( fabs(this->getInputWire2()->getArea()*this->getCurrentDensity() - this->getInputCurrent2()) > precision ){
                    return 111;
                }

                if( fabs(this->getInputPower() - (this->getOutputVoltage1() * this->getOutputCurrent1())) > precision ){
                    return 222;
                }

                if( fabs(this->getOutputPower() - (this->getOutputVoltage2() * this->getOutputCurrent2())) > precision ){
                    return 222;
                }

                if( fabs(this->getOutputWire1()->getArea()*this->getCurrentDensity() - this->getOutputCurrent1()) > precision ){
                    return 222;
                }

                if( fabs(this->getOutputWire2()->getArea()*this->getCurrentDensity() - this->getOutputCurrent2()) > precision ){
                    return 222;
                }


                /*
                 continuar correcao

                 https://help.github.com/en/github/administering-a-repository/creating-releases

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
                        return ResultCalculus::UnderflowTry;
                    }

                    index = this->laminas->findIndexByWidth( widthLaminaMin, this->getLamina()->getType() );
                    if( index == 0 ){
                        return ResultCalculus::NotFoundLamina;
                    }

                    this->setLamina( this->laminas->getLamina( index ) );

                    widthLaminaMin = this->getLamina()->getWidth();

                    index = this->bobbins->findIndexByWidthAndArea( widthLaminaMin, (SG * 100.0), this->getBobbin()->getType() );
                    if( index == 0 ){
                        return ResultCalculus::NotFoundBobbin;
                    }

                    this->setBobbin( this->bobbins->getBobbin( index ) );

                    SG = (widthLaminaMin * this->getBobbin()->getLength()) / 100.0; // convert to cm^2 //

                    SM = SG;

                    switch( this->getMethodLaminaLossCompensation() ) {
                        case MethodLaminaCompensation::NotApplied:
                            SM = SG;
                            break;
                        case MethodLaminaCompensation::FieldCompensation:
                            SM = SG / (1 + this->getLaminaLossCompensation()/100.0);
                            break;
                        case MethodLaminaCompensation::LaminaCompensation:
                            SM = SG / (1 + this->getLamina()->getThicknessPercent()/100.0);
                            break;
                    }

                    this->setGeometricSection( SG );
                    this->setMagneticSection( SM );

                    // turns = ceil( (this->getVoltageX() * 1e8) / (SM * 4.44 * this->getMagneticInduction() * this->getFrequency() ) ) //
                    this->setInputWireTurns1( this->getInputWireTurns1Auto() );
                    this->setOutputWireTurns1( this->getOutputWireTurns1Auto() );

                    if( this->getTransformerPatternNumber() > 1 ){
                        unsigned int N = this->getInputWireTurns2Auto() - this->getInputWireTurns1();
                        this->setInputWireTurns2( N );
                    }

                    if( this->getTransformerPatternNumber() % 2 == 1 ){
                        this->setOutputWireTurns2( this->getOutputWireTurns2Auto() - this->getOutputWireTurns1() );
                    }

                    this->setCopperArea( this->getCopperAreaAuto() );

                    if( (this->getLamina()->getWindowArea() / this->getCopperArea()) < this->getWindowAreaPerSectionCopper() ){
                        widthLaminaMin = widthLaminaMin + 0.1;
                        continue;
                    }

                    this->setInputCurrentDensity1( this->getInputCurrentDensity1Auto() );
                    this->setOutputCurrentDensity1( this->getOutputCurrentDensity1Auto() );
                    if( this->getTransformerPatternNumber() > 1 ){
                        this->setInputCurrentDensity2( this->getInputCurrentDensity2Auto() );
                    }
                    if( this->getTransformerPatternNumber() % 2 == 1 ){
                        this->setOutputCurrentDensity2( this->getOutputCurrentDensity2Auto() );
                    }

                    this->setAverageCurrentDensity( this->getAverageCurrentDensityAuto() );
                    this->setAverageTurnLength( this->getTurnAverageLengthAuto() );
                    this->setWeightCopper( this->getWeightCopperAuto() );
                    this->setCopperLoss( this->getCopperLossAuto() );
                    this->setWeightIron( this->getWeightIronAuto() );
                    this->setIronLoss( this->getIronLossAuto() );
                    this->setTotalLoss( this->getTotalLossAuto() );
                    this->setEfficiency( this->getEfficiencyAuto() );

                    if( (this->getTransformerPatternNumber() % 2 == 0) && this->getApplyCenterTap() ){
                        this->setOutputVoltage1( this->getOutputVoltage1() / 2.0 );
                        //this->setCurrentOUT1( this->getCurrentOUT1Auto() );
                        //this->setCurrentDensityOUT1( this->getCurrentDensityOUT1Auto() );
                        //this->setWireOUT1( this->wires->getWire( index ) );
                        this->setOutputWireTurns1( this->getOutputWireTurns1() / 2 );

                        this->setOutputVoltage2( this->getOutputVoltage1() );
                        this->setOutputCurrent2( this->getOutputCurrent1() );
                        this->setOutputCurrentDensity2( this->getOutputCurrentDensity1() );
                        this->setOutputWire2( this->getOutputWire1() );
                        //this->setWireTurnsOUT2( this->getWireTurnsOUT1() );
                    }

                    if( this->getMethodLaminaLossCompensation() == MethodLaminaCompensation::LaminaCompensation ) {
                        this->setLaminaLossCompensation( this->getLamina()->getThicknessPercent() );
                    }

                    return ResultCalculus::CorrectResult;

                    return 0;
                }
                */
            }
            catch( ... ){
                return ResultCalculus::ErrorAritmetic;
            }

            return 0;
        }

        std::string toString() const{
            std::string txt = "";
            txt = txt + "--------------------";
            txt = txt + "GENERAL INFORMATIONS";
            txt = txt + "--------------------\n";

            txt = txt + "Transformer with:     "
                    + std::to_string( this->getTransformerPatternNumber() ) + " ("
                    + this->getTransformerPatternNameAuto() + ")\n";

            txt = txt + "Frequency:            " + std::to_string( this->getFrequency() )             + " Hz\n";
            txt = txt + "Magnetic Induction:   " + std::to_string( this->getMagneticInduction() )     + " G\n";
            txt = txt + "Current Density:      " + std::to_string( this->getCurrentDensity() )        + " A/mm^2\n";
            txt = txt + "Average Cur. Density: " + std::to_string( this->getAverageCurrentDensity() ) + " A/mm^2\n";
            txt = txt + "Weigth Iron:          " + std::to_string( this->getWeightIron()*1000.0 )     + " g\n";
            txt = txt + "Weight Copper:        " + std::to_string( this->getWeightCopper()*1000.0 )   + " g\n";
            txt = txt + "Average Turn Length:  " + std::to_string( this->getAverageTurnLength()/10 )  + " cm\n";
            txt = txt + "Copper Area:          " + std::to_string( this->getCopperArea() )            + " mm^2\n";
            txt = txt + "Iron Loss:            " + std::to_string( this->getIronLoss() )              + " W\n";
            txt = txt + "Copper Loss:          " + std::to_string( this->getCopperLoss() )            + " W\n";
            txt = txt + "Total Loss:           " + std::to_string( this->getTotalLoss() )             + " W\n";
            txt = txt + "Efficiency:           " + std::to_string( this->getEfficiency() )            + " %\n";

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "INPUT";
            txt = txt + "--------------------\n";
            txt = txt + "Power:                " + std::to_string( this->getInputPower() )            + " W\n";
            txt = txt + "Voltage 1:            " + std::to_string( this->getInputVoltage1() )         + " V\n";
            txt = txt + "Current 1:            " + std::to_string( this->getInputCurrent1() )         + " A\n";
            txt = txt + "AWG wire 1:           " + this->getInputWire1()->getAWG()                    + "\n";
            txt = txt + "Wire turns 1:         " + std::to_string( this->getInputWireTurns1() )       + "\n";
            txt = txt + "Current Density 1:    " + std::to_string( this->getInputCurrentDensity1() )  + " A/mm^2\n";
            txt = txt + "\n";
            txt = txt + "--> WIRE 1\n";
            txt = txt + this->getInputWire1()->toString();
            txt = txt + "\n";
            if( this->getTransformerPatternNumber() > 1 ){
                txt = txt + "\n";
                txt = txt + "Voltage 2:            " + std::to_string( this->getInputVoltage2() )        + " V\n";
                txt = txt + "Current 2:            " + std::to_string( this->getInputCurrent2() )        + " A\n";
                txt = txt + "AWG wire 2:           " + this->getInputWire2()->getAWG()                   + "\n";
                txt = txt + "Wire turns 2:         " + std::to_string( this->getInputWireTurns2() )      + "\n";
                txt = txt + "Current Density 2:    " + std::to_string( this->getInputCurrentDensity2() ) + " A/mm^2\n";
                txt = txt + "\n";
                txt = txt + "--> WIRE 2\n";
                txt = txt + this->getInputWire2()->toString();
                txt = txt + "\n";
            }

            txt = txt + "\n";
            txt = txt + "--------------------";
            txt = txt + "OUTPUT";
            txt = txt + "--------------------\n";
            txt = txt + "Power:                " + std::to_string( this->getOutputPower() )           + " W\n";
            txt = txt + "Voltage 1:            " + std::to_string( this->getOutputVoltage1() )        + " V\n";
            txt = txt + "Current 1:            " + std::to_string( this->getOutputCurrent1() )        + " A\n";
            txt = txt + "AWG wire 1:           " + this->getOutputWire1()->getAWG()                   + "\n";
            txt = txt + "Wire turns 1:         " + std::to_string( this->getOutputWireTurns1() )      + "\n";
            txt = txt + "Current Density 1:    " + std::to_string( this->getOutputCurrentDensity1() ) + " A/mm^2\n";
            txt = txt + "\n";
            txt = txt + "--> WIRE 1\n";
            txt = txt + this->getOutputWire1()->toString();
            txt = txt + "\n";
            if( this->getTransformerPatternNumber() % 2 == 1 ){
                txt = txt + "\n";
                txt = txt + "Voltage 2:            " + std::to_string( this->getOutputVoltage2() )        + " V\n";
                txt = txt + "Power 2:              " + std::to_string( this->getOutputPower() )           + " W\n";
                txt = txt + "Current 2:            " + std::to_string( this->getOutputCurrent2() )        + " A\n";
                txt = txt + "AWG wire 2:           " + this->getOutputWire2()->getAWG()                   + "\n";
                txt = txt + "Wire turns 2:         " + std::to_string( this->getOutputWireTurns2() )      + "\n";
                txt = txt + "Current Density 2:    " + std::to_string( this->getOutputCurrentDensity2() ) + " A/mm^2\n";
                txt = txt + "\n";
                txt = txt + "--> WIRE 2\n";
                txt = txt + this->getOutputWire2()->toString();
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
            txt = txt + "\t<tr><td colspan=\"2\"><h1 align=\"center\">Datasheet</h1></td></tr>\n";
            txt = txt + "\t<tr><td>&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">GENERAL INFORMATION</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Transformer with: "
                    + std::to_string( this->getTransformerPatternNumber() ) + " ("
                    + this->getTransformerPatternNameAuto()  + ")</td><td><b>";

            txt = txt + "</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Frequency:</td><td><b>" + std::to_string( this->getFrequency() ) + " Hz</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Magnetic Induction:</td><td><b>" + std::to_string( this->getMagneticInduction() ) + " G</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density:</td><td><b>" + std::to_string( this->getCurrentDensity() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Average Cur. Density:</td><td><b>" + std::to_string( this->getAverageCurrentDensity() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Weigth Iron:</td><td><b>" + std::to_string( this->getWeightIron()*1000.0 ) + " g</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Weight Copper:</td><td><b>" + std::to_string( this->getWeightCopper()*1000.0 ) + " g</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Turns Average Length:</td><td><b>" + std::to_string( this->getAverageTurnLength()/10 ) + " cm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Coil Area:</td><td><b>" + std::to_string( this->getCopperArea() ) + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Iron Loss:</td><td><b>" + std::to_string( this->getIronLoss() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Copper Loss:</td><td><b>" + std::to_string( this->getCopperLoss() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Total Loss:</td><td><b>" + std::to_string( this->getTotalLoss() ) + " W</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Efficiency:</td><td><b>" + std::to_string( this->getEfficiency() ) + " %</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">INPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getInputPower() ) + " VA</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage 1:</td><td><b>" + std::to_string( this->getInputVoltage1() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current 1:</td><td><b>" + std::to_string( this->getInputCurrent1() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire 1:</td><td><b>" + this->getInputWire1()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns 1:</td><td><b>" + std::to_string( this->getInputWireTurns1() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density 1:</td><td><b>" + std::to_string( this->getInputCurrentDensity1() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getInputWire1()->toHTML();
            txt = txt + "\n\t</td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            if( this->getTransformerPatternNumber() > 1 ){
                txt = txt + "\t<tr><td align=\"right\">Voltage 2:</td><td><b>" + std::to_string( this->getInputVoltage2() ) + " V</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current 2:</td><td><b>" + std::to_string( this->getInputCurrent2() ) + " A</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">AWG wire 2:</td><td><b>" + this->getInputWire2()->getAWG() + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Wire turns 2:</td><td><b>" + std::to_string( this->getInputWireTurns2() ) + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current Density 2:</td><td><b>" + std::to_string( this->getInputCurrentDensity2() ) + " A/mm<sup>2</sup></b></td></tr>\n";
                txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

                txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
                txt = txt + this->getInputWire2()->toHTML();
                txt = txt + "\n\t</td></tr>\n";
                txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            }

            txt = txt + "\t<tr><td align=\"center\" colspan=\"2\" style=\"background-color:#ddd;\">OUTPUT</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Power:</td><td><b>" + std::to_string( this->getOutputPower() ) + " VA</b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Voltage 1:</td><td><b>" + std::to_string( this->getOutputVoltage1() ) + " V</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current 1:</td><td><b>" + std::to_string( this->getOutputCurrent1() ) + " A</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">AWG wire 1:</td><td><b>" + this->getOutputWire1()->getAWG() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Wire turns 1:</td><td><b>" + std::to_string( this->getOutputWireTurns1() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Current Density 1:</td><td><b>" + std::to_string( this->getOutputCurrentDensity1() ) + " A/mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

            txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
            txt = txt + this->getOutputWire1()->toHTML();
            txt = txt + "\n\t</td></tr>\n";

            if( this->getTransformerPatternNumber() % 2 == 1 ){
                txt = txt + "\t<tr><td align=\"right\">Voltage 2:</td><td><b>" + std::to_string( this->getOutputVoltage2() ) + " V</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current 2:</td><td><b>" + std::to_string( this->getOutputCurrent2() ) + " A</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">AWG wire 2:</td><td><b>" + this->getOutputWire2()->getAWG() + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Wire turns 2:</td><td><b>" + std::to_string( this->getOutputWireTurns2() ) + "</b></td></tr>\n";
                txt = txt + "\t<tr><td align=\"right\">Current Density 2:</td><td><b>" + std::to_string( this->getOutputCurrentDensity2() ) + " A/mm<sup>2</sup></b></td></tr>\n";
                txt = txt + "\t<tr><td colspan=\"2\">&nbsp;</td></tr>\n";

                txt = txt + "\t<tr><td align=\"center\"colspan=\"2\">\n";
                txt = txt + this->getOutputWire2()->toHTML();
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
            std::string sql = "INSERT INTO ";
            sql += this->getDatabaseName();
            sql += "(frequency, magnetic_induction, current_density, average_current_density, weight_iron, weight_copper, ";
            sql += "average_turn_length, copper_area, window_area_per_section_copper, iron_loss, copper_loss, total_loss, efficiency, ";
            sql += "transformer_pattern_number, transformer_pattern_name, apply_center_tap, apply_transformer_loss_compensation, transformer_loss_compensation, ";
            sql += "input_power, input_voltage_1, input_current_1, input_current_density_1, ";
            sql += "input_wire_id_1, input_wire_type_1, input_wire_awg_1, input_wire_turns_1, input_wire_diameter_1, input_wire_turn_per_cm_1, input_wire_area_1, ";
            sql += "input_wire_resistance_1, input_wire_weight_1, input_wire_length_1, input_wire_frequency_1, input_wire_material_1, input_wire_provider_1, ";
            sql += "input_voltage_2, input_current_2, input_current_density_2, ";
            sql += "input_wire_id_2, input_wire_type_2, input_wire_awg_2, input_wire_turns_2, input_wire_diameter_2, input_wire_turn_per_cm_2, input_wire_area_2, ";
            sql += "input_wire_resistance_2, input_wire_weight_2, input_wire_length_2, input_wire_frequency_2, input_wire_material_2, input_wire_provider_2, ";
            sql += "output_power, output_voltage_1, output_current_1, output_current_density_1, ";
            sql += "output_wire_id_1, output_wire_type_1, output_wire_awg_1, output_wire_turns_1, output_wire_diameter_1, output_wire_turn_per_cm_1, output_wire_area_1, ";
            sql += "output_wire_resistance_1, output_wire_weight_1, output_wire_length_1, output_wire_frequency_1, output_wire_material_1, output_wire_provider_1, ";
            sql += "output_voltage_2, output_current_2, output_current_density_2, ";
            sql += "output_wire_id_2, output_wire_type_2, output_wire_awg_2, output_wire_turns_2, output_wire_diameter_2, output_wire_turn_per_cm_2, output_wire_area_2, ";
            sql += "output_wire_resistance_2, output_wire_weight_2, output_wire_length_2, output_wire_frequency_2, output_wire_material_2, output_wire_provider_2, ";
            sql += "lamina_id, lamina_type, lamina_provider, lamina_width, lamina_window_area, lamina_weight, lamina_compensation_state, lamina_compensation_value, ";
            sql += "bobbin_id, bobbin_type, bobbin_code, bobbin_provider, bobbin_width, bobbin_length, bobbin_height, observation ) ";
            sql += "VALUES (";
            sql += std::to_string( this->getFrequency() ) + ", ";                   // frequency
            sql += std::to_string( this->getMagneticInduction() ) + ", ";           // magnetic induction
            sql += std::to_string( this->getCurrentDensity() ) + ", ";              // current density
            sql += std::to_string( this->getAverageCurrentDensity() ) + ", ";       // average current density
            sql += std::to_string( this->getWeightIron() ) + ", ";                  // weigth iron
            sql += std::to_string( this->getWeightCopper() ) + ", ";                // weight copper
            sql += std::to_string( this->getAverageTurnLength() ) + ", ";           // average turn length
            sql += std::to_string( this->getCopperArea() ) + ", ";                  // copper area
            sql += std::to_string( this->getWindowAreaPerSectionCopper() ) + ", ";  // window area per section copper
            sql += std::to_string( this->getIronLoss() ) + ", ";                    // iron loss
            sql += std::to_string( this->getCopperLoss() ) + ", ";                  // copper loss
            sql += std::to_string( this->getTotalLoss() ) + ", ";                   // total loss
            sql += std::to_string( this->getEfficiency() ) + ", ";                  // efficiency

            sql += std::to_string( this->getTransformerPatternNumber() ) + ", '";   // transformer pattern number
            sql += this->getTransformerPatternName() + "', ";                       // transformer pattern name
            if( this->getApplyCenterTap() ){
                sql += "TRUE, ";                                                    // center tap
            }
            else{
                sql += "FALSE, ";                                                   // center tap
            }
            if( this->getApplyTransformerLossCompensation() ){
                sql += "TRUE, ";                                                    // transformer loss compensation state
            }
            else{
                sql += "FALSE, ";                                                   // transformer loss compensation state
            }
            sql += std::to_string( this->getTransformerLossCompensation() ) + ", "; // transformer loss compensation value

            sql += std::to_string( this->getInputPower() ) + ", ";                     // input power

            sql += std::to_string( this->getInputVoltage1() ) + ",	";                 // input voltage 1
            sql += std::to_string( this->getInputCurrent1() ) + ", ";                  // input current 1
            sql += std::to_string( this->getInputCurrentDensity1() ) + ", ";           // input current density 1
            sql += std::to_string( this->getInputWire1()->getId() ) + ", ";            // input wire id 1
            sql += "'" + this->getInputWire1()->getType() + "', ";                     // input wire type 1
            sql += "'" + this->getInputWire1()->getAWG() + "', ";                      // input wire awg 1
            sql += std::to_string( this->getInputWireTurns1() ) + ", ";                // input wire turns 1
            sql += std::to_string( this->getInputWire1()->getDiameter() ) + ", ";      // input wire diameter 1
            sql += std::to_string( this->getInputWire1()->getTurnsPerCm() ) + ", ";    // input wire turn per cm 1
            sql += std::to_string( this->getInputWire1()->getArea() ) + ", ";          // input wire area 1
            sql += std::to_string( this->getInputWire1()->getResistance() ) + ", ";    // input wire resistance 1
            sql += std::to_string( this->getInputWire1()->getWeight() ) + ", ";        // input wire weight 1
            sql += std::to_string( this->getInputWire1()->getLength() ) + ", ";        // input wire length 1
            sql += std::to_string( this->getInputWire1()->getFrequency() ) + ", ";     // input wire frequency 1
            sql += "'" + this->getInputWire1()->getMaterial() + "', ";                 // input wire material 1
            sql += "'" + this->getInputWire1()->getProvider() + "', ";                 // input wire provider 1

            sql += std::to_string( this->getInputVoltage2() ) + ",	";                 // input voltage 2
            sql += std::to_string( this->getInputCurrent2() ) + ", ";                  // input current 2
            sql += std::to_string( this->getInputCurrentDensity2() ) + ", ";           // input current density 2
            sql += std::to_string( this->getInputWire2()->getId() ) + ", ";            // input wire id 2
            sql += "'" + this->getInputWire2()->getType() + "', ";                     // input wire type 2
            sql += "'" + this->getInputWire2()->getAWG() + "', ";                      // input wire awg 2
            sql += std::to_string( this->getInputWireTurns2() ) + ", ";                // input wire turns 2
            sql += std::to_string( this->getInputWire2()->getDiameter() ) + ", ";      // input wire diameter 2
            sql += std::to_string( this->getInputWire2()->getTurnsPerCm() ) + ", ";    // input wire turnPerCm 2
            sql += std::to_string( this->getInputWire2()->getArea() ) + ", ";          // input wire area 2
            sql += std::to_string( this->getInputWire2()->getResistance() ) + ", ";    // input wire resistance 2
            sql += std::to_string( this->getInputWire2()->getWeight() ) + ", ";        // input wire weight 2
            sql += std::to_string( this->getInputWire2()->getLength() ) + ", ";        // input wire length 2
            sql += std::to_string( this->getInputWire2()->getFrequency() ) + ", ";     // input wire frequency 2
            sql += "'" + this->getInputWire2()->getMaterial() + "', ";                 // input wire material 2
            sql += "'" + this->getInputWire2()->getProvider() + "', ";                 // input wire provider 2

            sql += std::to_string( this->getOutputPower() ) + ", ";                    // output power

            sql += std::to_string( this->getOutputVoltage1() ) + ",	";                 // output voltage 1
            sql += std::to_string( this->getOutputCurrent1() ) + ", ";                 // output current 1
            sql += std::to_string( this->getOutputCurrentDensity1() ) + ", ";          // output current density 1
            sql += std::to_string( this->getOutputWire1()->getId() ) + ", ";           // output wire id 1
            sql += "'" + this->getOutputWire1()->getType() + "', ";                    // output wire type 1
            sql += "'" + this->getOutputWire1()->getAWG() + "', ";                     // output wire awg 1
            sql += std::to_string( this->getOutputWireTurns1() ) + ", ";               // output wire turns 1
            sql += std::to_string( this->getOutputWire1()->getDiameter() ) + ", ";     // output wire diameter 1
            sql += std::to_string( this->getOutputWire1()->getTurnsPerCm() ) + ", ";   // output wire turnPerCm 1
            sql += std::to_string( this->getOutputWire1()->getArea() ) + ", ";         // output wire area 1
            sql += std::to_string( this->getOutputWire1()->getResistance() ) + ", ";   // output wire resistance 1
            sql += std::to_string( this->getOutputWire1()->getWeight() ) + ", ";       // output wire weight 1
            sql += std::to_string( this->getOutputWire1()->getLength() ) + ", ";       // output wire length 1
            sql += std::to_string( this->getOutputWire1()->getFrequency() ) + ", ";    // output wire frequency 1
            sql += "'" + this->getOutputWire1()->getMaterial() + "', ";                // output wire material 1
            sql += "'" + this->getOutputWire1()->getProvider() + "', ";                // output wire provider 1

            sql += std::to_string( this->getOutputVoltage2() ) + ",	";                 // output voltage 2
            sql += std::to_string( this->getOutputCurrent2() ) + ", ";                 // output current 2
            sql += std::to_string( this->getOutputCurrentDensity2() ) + ", ";          // output currentDensity 2
            sql += std::to_string( this->getOutputWire2()->getId() ) + ", ";           // output wireID 2
            sql += "'" + this->getOutputWire2()->getType() + "', ";                    // output wireType 2
            sql += "'" + this->getOutputWire2()->getAWG() + "', ";                     // output wireAWG 2
            sql += std::to_string( this->getOutputWireTurns2() ) + ", ";               // output wireTurns 2
            sql += std::to_string( this->getOutputWire2()->getDiameter() ) + ", ";     // output wireDiameter 2
            sql += std::to_string( this->getOutputWire2()->getTurnsPerCm() ) + ", ";   // output wireTurnPerCm 2
            sql += std::to_string( this->getOutputWire2()->getArea() ) + ", ";         // output wireArea 2
            sql += std::to_string( this->getOutputWire2()->getResistance() ) + ", ";   // output wireResistance 2
            sql += std::to_string( this->getOutputWire2()->getWeight() ) + ", ";       // output wireWeight 2
            sql += std::to_string( this->getOutputWire2()->getLength() ) + ", ";       // output wireLength 2
            sql += std::to_string( this->getOutputWire2()->getFrequency() ) + ", ";    // output wireFrequency 2
            sql += "'" + this->getOutputWire2()->getMaterial() + "', ";                // output wireMaterial 2
            sql += "'" + this->getOutputWire2()->getProvider() + "', ";                // output wire provider 2

            sql += std::to_string( this->getLamina()->getId() ) + ", ";                // lamina id
            sql += "'" + this->getLamina()->getType() + "', ";                         // lamina type
            sql += "'" + this->getLamina()->getProvider() + "', ";                     // lamina provider
            sql += std::to_string( this->getLamina()->getWidth() ) + ", ";             // lamina width
            sql += std::to_string( this->getLamina()->getWindowArea() ) + ", ";        // lamina window area
            sql += std::to_string( this->getLamina()->getWeight() ) + ", ";            // lamina weight
            sql += std::to_string( this->getMethodLaminaLossCompensation() ) + ", ";   // lamina compensation state
            sql += std::to_string( this->getLamina()->getThicknessPercent() ) + ", ";  // lamina compensation value

            sql += std::to_string( this->getBobbin()->getId() ) + ", ";                // bobbin id
            sql += "'" + this->getBobbin()->getType() + "', ";                         // bobbin type
            sql += "'" + this->getBobbin()->getCode() + "', ";                         // bobbin code
            sql += "'" + this->getBobbin()->getProvider() + "', ";                     // bobbin provider
            sql += std::to_string( this->getBobbin()->getWidth() ) + ", ";             // bobbin width
            sql += std::to_string( this->getBobbin()->getLength() ) + ", ";            // bobbin length
            sql += std::to_string( this->getBobbin()->getHeight() ) + ", ";            // bobbin height

            sql += "'" + this->getObservation() + "' )";                               // observation

            return sql;
        }
};

#endif // TRANSFORMER_H
