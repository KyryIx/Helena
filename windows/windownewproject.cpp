#include "windows/windownewproject.h"
#include "ui_windownewproject.h"

#include "components/wires.h"
#include "components/laminas.h"
#include "components/bobbins.h"

#define precision 2
#define table "transformers"

WindowNewProject::WindowNewProject(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowNewProject)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->transformer = new Transformer( database );
    this->transformer->setDatabaseName( table );
}

WindowNewProject::~WindowNewProject()
{
    delete ui;
}

void WindowNewProject::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowNewProject::clearFields(){
    ui->lineEdit_patternWindingNumber->setText( "0" );
    ui->comboBox_patternWindingName->setCurrentIndex( 0 );
    //ui->checkBox_centerTap->setChecked( false );
    ui->lineEdit_frequency->setText( QString::number( 60.0, 'f', precision ) );
    ui->lineEdit_magneticInduction->setText( QString::number( 11300, 'f', precision ) );
    ui->lineEdit_currentDensity->setText( QString::number( 3.0, 'f', precision ) );
    ui->lineEdit_densityAverageCurrent->setText( "" );
    ui->checkBox_compensation_power->setEnabled( true );
    ui->lineEdit_compensation_power->setText( QString::number( 10.0, 'f', precision ) );
    ui->lineEdit_windowAreaPerSectionTurns->setText( QString::number( 3.0, 'f', precision ) );
    ui->lineEdit_weightTurns->setText( "" );
    ui->lineEdit_ironWeight->setText( "" );
    ui->lineEdit_TurnsLoss->setText( "" );
    ui->lineEdit_ironLoss->setText( "" );
    ui->lineEdit_averageTurnLength->setText( "" );
    ui->lineEdit_totalLoss->setText( "" );
    ui->lineEdit_turnsArea->setText( "" );
    ui->lineEdit_efficiency->setText( "" );

    ui->lineEdit_powerInput->setText( "" );
    ui->lineEdit_voltageInput_1->setText( "" );
    ui->lineEdit_voltageInput_2->setText( "" );
    ui->lineEdit_currentInput_1->setText( "" );
    ui->lineEdit_currentInput_2->setText( "" );
    ui->lineEdit_densityCurrentInput_1->setText( "" );
    ui->lineEdit_densityCurrentInput_2->setText( "" );
    ui->lineEdit_wireIDInput_1->setText( "" );
    ui->lineEdit_wireIDInput_2->setText( "" );
    //ui->comboBox_wireTypeInput_1->setText( "" );
    //ui->comboBox_wireTypeInput_2->setText( "" );
    ui->lineEdit_wireAWGInput_1->setText( "" );
    ui->lineEdit_wireAWGInput_2->setText( "" );
    ui->lineEdit_wireProviderInput_1->setText( "" );
    ui->lineEdit_wireProviderInput_2->setText( "" );
    ui->lineEdit_wireDiameterInput_1->setText( "" );
    ui->lineEdit_wireDiameterInput_2->setText( "" );
    ui->lineEdit_wireAreaInput_1->setText( "" );
    ui->lineEdit_wireAreaInput_2->setText( "" );
    ui->lineEdit_wireMaterialInput_1->setText( "" );
    ui->lineEdit_wireMaterialInput_2->setText( "" );
    ui->lineEdit_turnsIN_1->setText( "" );
    ui->lineEdit_turnsIN_2->setText( "" );

    ui->lineEdit_powerOutput->setText( "" );
    ui->lineEdit_voltageOutput_1->setText( "" );
    ui->lineEdit_voltageOutput_2->setText( "" );
    ui->lineEdit_currentOutput_1->setText( "" );
    ui->lineEdit_currentOutput_2->setText( "" );
    ui->lineEdit_densityCurrentOutput_1->setText( "" );
    ui->lineEdit_densityCurrentOutput_2->setText( "" );
    ui->lineEdit_wireIDOutput_1->setText( "" );
    ui->lineEdit_wireIDOutput_2->setText( "" );
    //ui->comboBox_wireTypeOutput_1->setText( "" );
    //ui->comboBox_wireTypeOutput_2->setText( "" );
    ui->lineEdit_wireAWGOutput_1->setText( "" );
    ui->lineEdit_wireAWGOutput_2->setText( "" );
    ui->lineEdit_wireProviderOutput_1->setText( "" );
    ui->lineEdit_wireProviderOutput_2->setText( "" );
    ui->lineEdit_wireDiameterOutput_1->setText( "" );
    ui->lineEdit_wireDiameterOutput_2->setText( "" );
    ui->lineEdit_wireAreaOutput_1->setText( "" );
    ui->lineEdit_wireAreaOutput_2->setText( "" );
    ui->lineEdit_wireMaterialOutput_1->setText( "" );
    ui->lineEdit_wireMaterialOutput_2->setText( "" );
    ui->lineEdit_turnsOUT_1->setText( "" );
    ui->lineEdit_turnsOUT_2->setText( "" );

    ui->lineEdit_laminaID->setText( "" );
    //ui->comboBox_laminaType->setText( "" );
    ui->lineEdit_laminaProvider->setText( "" );
    ui->lineEdit_laminaWidth->setText( "" );
    ui->lineEdit_laminaArea->setText( "" );
    ui->lineEdit_laminaWeight->setText( "" );
    ui->comboBox_useMode->setCurrentIndex( 0 );
    ui->lineEdit_laminaCompensation->setText( QString::number( 10.0, 'f', precision ) );

    ui->lineEdit_bobbinID->setText( "" );
    ui->lineEdit_bobbinType->setText( "" );
    ui->lineEdit_bobbinCode->setText( "" );
    ui->lineEdit_bobbinProvider->setText( "" );
    ui->lineEdit_bobbinWidth->setText( "" );
    ui->lineEdit_bobbinLength->setText( "" );
    ui->lineEdit_bobbinHeight->setText( "" );
    ui->lineEdit_bobbinArea->setText( "" );

    ui->textEdit_observation->setText( "" );

    this->transformer = new Transformer( this->database );
}

void WindowNewProject::setTransformer(){
    this->transformer->setOutputPower( ui->lineEdit_powerOutput->text().toDouble() );
    this->transformer->setOutputVoltage1( ui->lineEdit_voltageOutput_1->text().toDouble() );
    this->transformer->setOutputVoltage2( ui->lineEdit_voltageOutput_2->text().toDouble() );
    this->transformer->setInputVoltage1( ui->lineEdit_voltageInput_1->text().toDouble() );
    this->transformer->setInputVoltage2( ui->lineEdit_voltageInput_2->text().toDouble() );
    this->transformer->setFrequency( ui->lineEdit_frequency->text().toDouble() );
    this->transformer->setMagneticInduction( ui->lineEdit_magneticInduction->text().toDouble() );
    this->transformer->setCurrentDensity( ui->lineEdit_currentDensity->text().toDouble() );
    this->transformer->setTransformerPatternNumber( ui->lineEdit_patternWindingNumber->text().toUInt() );
    this->transformer->setTransformerPatternName( ui->comboBox_patternWindingName->currentText().toStdString() );
    this->transformer->setWindowAreaPerSectionCopper( ui->lineEdit_windowAreaPerSectionTurns->text().toDouble() );
    this->transformer->setObservation( ui->textEdit_observation->toPlainText().toStdString() );

    this->transformer->setApplyTransformerLossCompensation( ui->checkBox_compensation_power->isChecked() );
    this->transformer->setTransformerLossCompensation( ui->lineEdit_compensation_power->text().toDouble() );

    //this->transformer->setApplyCenterTap( ui->checkBox_centerTap->isChecked() );
    //this->transformer->setApplyCenterTap( false );

    switch( ui->comboBox_useMode->currentIndex() ) {
        case 0:
            transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::NotApplied );
            break;
        case 1:
            transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::LaminaCompensation );
            break;
        case 2:
            transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::FieldCompensation );
    }
    transformer->setLaminaLossCompensation( ui->lineEdit_laminaCompensation->text().toDouble() );

    Wire* wireIN_1 = new Wire();
    wireIN_1->setType( ui->comboBox_wireTypeInput_1->currentText().toStdString() );
    this->transformer->setInputWire1( wireIN_1 );

    Wire* wireIN_2 = new Wire();
    wireIN_2->setType( ui->comboBox_wireTypeInput_2->currentText().toStdString() );
    this->transformer->setInputWire2( wireIN_2 );

    Wire* wireOUT_1 = new Wire();
    wireOUT_1->setType( ui->comboBox_wireTypeOutput_1->currentText().toStdString() );
    this->transformer->setOutputWire1( wireOUT_1 );

    Wire* wireOUT_2 = new Wire();
    wireOUT_2->setType( ui->comboBox_wireTypeOutput_2->currentText().toStdString() );
    this->transformer->setOutputWire2( wireOUT_2 );

    Lamina* lamina = new Lamina();
    lamina->setType( ui->comboBox_laminaType->currentText().toStdString() );
    this->transformer->setLamina( lamina );

    Bobbin* bobbin = new Bobbin();
    bobbin->setType( ui->lineEdit_bobbinType->text().toStdString() );
    this->transformer->setBobbin( bobbin );
}

void WindowNewProject::updateTransformer(){
    this->transformer->setTransformerPatternNumber( ui->lineEdit_patternWindingNumber->text().toUInt() );
    this->transformer->setTransformerPatternName( ui->comboBox_patternWindingName->currentText().toStdString() );
    ////////////////// olhar aqui //////////////////
    //this->transformer->setApplyCenterTap( ui->checkBox_centerTap->isChecked() );
    //this->transformer->setApplyCenterTap( false );
    this->transformer->setFrequency( ui->lineEdit_frequency->text().toDouble() );
    this->transformer->setMagneticInduction( ui->lineEdit_magneticInduction->text().toDouble() );
    this->transformer->setCurrentDensity( ui->lineEdit_currentDensity->text().toDouble() );
    this->transformer->setAverageCurrentDensity( ui->lineEdit_densityAverageCurrent->text().toDouble() );
    this->transformer->setApplyTransformerLossCompensation( ui->checkBox_compensation_power->isChecked() );
    this->transformer->setTransformerLossCompensation( ui->lineEdit_compensation_power->text().toDouble() );
    this->transformer->setWindowAreaPerSectionCopper( ui->lineEdit_windowAreaPerSectionTurns->text().toDouble() );
    this->transformer->setWeightCopper( ui->lineEdit_weightTurns->text().toDouble() );
    this->transformer->setWeightIron( ui->lineEdit_ironWeight->text().toDouble() );
    this->transformer->setCopperLoss( ui->lineEdit_TurnsLoss->text().toDouble() );
    this->transformer->setIronLoss( ui->lineEdit_ironLoss->text().toDouble() );
    this->transformer->setAverageTurnLength( ui->lineEdit_averageTurnLength->text().toDouble() );
    this->transformer->setTotalLoss( ui->lineEdit_totalLoss->text().toDouble() );
    this->transformer->setCopperArea( ui->lineEdit_turnsArea->text().toDouble() );
    this->transformer->setEfficiency( ui->lineEdit_efficiency->text().toDouble() );
    this->transformer->setObservation( ui->textEdit_observation->toPlainText().toStdString() );

    Wires* wires = new Wires( database );

    this->transformer->setInputPower( ui->lineEdit_powerInput->text().toDouble() );
    this->transformer->setInputVoltage1( ui->lineEdit_voltageInput_1->text().toDouble() );
    this->transformer->setInputCurrent1( ui->lineEdit_currentInput_1->text().toDouble() );
    this->transformer->setInputCurrentDensity1( ui->lineEdit_densityCurrentInput_1->text().toDouble() );
    this->transformer->setInputWire1( wires->getWire( ui->lineEdit_wireIDInput_1->text().toUInt() ) );
    this->transformer->setInputWireTurns1( ui->lineEdit_turnsIN_1->text().toUInt() );
    this->transformer->setInputVoltage2( ui->lineEdit_voltageInput_2->text().toDouble() );
    this->transformer->setInputCurrent2( ui->lineEdit_currentInput_2->text().toDouble() );
    this->transformer->setInputCurrentDensity2( ui->lineEdit_densityCurrentInput_2->text().toDouble() );
    this->transformer->setInputWire2( wires->getWire( ui->lineEdit_wireIDInput_2->text().toUInt() ) );
    this->transformer->setInputWireTurns2( ui->lineEdit_turnsIN_2->text().toUInt() );

    this->transformer->setOutputPower( ui->lineEdit_powerOutput->text().toDouble() );
    this->transformer->setOutputVoltage1( ui->lineEdit_voltageOutput_1->text().toDouble() );
    this->transformer->setOutputCurrent1( ui->lineEdit_currentOutput_1->text().toDouble() );
    this->transformer->setOutputCurrentDensity1( ui->lineEdit_densityCurrentOutput_1->text().toDouble() );
    this->transformer->setOutputWire1( wires->getWire( ui->lineEdit_wireIDOutput_1->text().toUInt() ) );
    this->transformer->setOutputWireTurns1( ui->lineEdit_turnsOUT_1->text().toUInt() );
    this->transformer->setOutputVoltage2( ui->lineEdit_voltageOutput_2->text().toDouble() );
    this->transformer->setOutputCurrent2( ui->lineEdit_currentOutput_2->text().toDouble() );
    this->transformer->setOutputCurrentDensity2( ui->lineEdit_densityCurrentOutput_2->text().toDouble() );
    this->transformer->setOutputWire2( wires->getWire( ui->lineEdit_wireIDOutput_2->text().toUInt() ) );
    this->transformer->setOutputWireTurns2( ui->lineEdit_turnsOUT_2->text().toUInt() );

    Laminas* laminas = new Laminas( database );
    if( laminas->getId( ui->lineEdit_laminaID->text().toUInt() ) != 0 ){
        this->transformer->setLamina( laminas->getLamina( ui->lineEdit_laminaID->text().toUInt() ) );
    }
    else{
        Lamina* lamina = new Lamina();
        lamina->setType( ui->comboBox_laminaType->currentText().toStdString() );
        this->transformer->setLamina( lamina );
    }

    Bobbins* bobbins = new Bobbins( database );

    if( bobbins->getId( ui->lineEdit_bobbinID->text().toUInt() ) != 0 ){
        this->transformer->setBobbin( bobbins->getBobbin( ui->lineEdit_bobbinID->text().toUInt() ) );
    }
    else{
        Bobbin* bobbin = new Bobbin();
        bobbin->setType( ui->lineEdit_bobbinType->text().toStdString() );
        transformer->setBobbin( bobbin );
    }

    switch( ui->comboBox_useMode->currentIndex() ) {
        case 0:
            transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::NotApplied );
            break;
        case 1:
            transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::LaminaCompensation );
            break;
        case 2:
            transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::FieldCompensation );
    }
    transformer->setLaminaLossCompensation( ui->lineEdit_laminaCompensation->text().toDouble() );
}

void WindowNewProject::writeInput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned int type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageInput_1->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentInput_1->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentInput_1->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDInput_1->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeInput_1->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGInput_1->setText( awg );
    ui->lineEdit_wireProviderInput_1->setText( provider );
    ui->lineEdit_wireDiameterInput_1->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaInput_1->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialInput_1->setText( material );
    ui->lineEdit_turnsIN_1->setText( std::to_string( turns ).c_str() );
}

void WindowNewProject::writeInput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageInput_2->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentInput_2->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentInput_2->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDInput_2->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeInput_2->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGInput_2->setText( awg );
    ui->lineEdit_wireProviderInput_2->setText( provider );
    ui->lineEdit_wireDiameterInput_2->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaInput_2->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialInput_2->setText( material );
    ui->lineEdit_turnsIN_2->setText( std::to_string( turns ).c_str() );
}

void WindowNewProject::writeOutput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageOutput_1->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentOutput_1->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentOutput_1->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDOutput_1->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeOutput_1->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGOutput_1->setText( awg );
    ui->lineEdit_wireProviderOutput_1->setText( provider );
    ui->lineEdit_wireDiameterOutput_1->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaOutput_1->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialOutput_1->setText( material );
    ui->lineEdit_turnsOUT_1->setText( std::to_string( turns ).c_str() );
}

void WindowNewProject::writeOutput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageOutput_2->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentOutput_2->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentOutput_2->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDOutput_2->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeOutput_2->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGOutput_2->setText( awg );
    ui->lineEdit_wireProviderOutput_2->setText( provider );
    ui->lineEdit_wireDiameterOutput_2->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaOutput_2->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialOutput_2->setText( material );
    ui->lineEdit_turnsOUT_2->setText( std::to_string( turns ).c_str() );
}

void WindowNewProject::enableInput2( bool state ){
    ui->lineEdit_voltageInput_2->setEnabled( state );
    ui->lineEdit_currentInput_2->setEnabled( state );
    ui->lineEdit_densityCurrentInput_2->setEnabled( state );
    ui->lineEdit_wireIDInput_2->setEnabled( state );
    ui->comboBox_wireTypeInput_2->setEnabled( state );
    ui->lineEdit_wireAWGInput_2->setEnabled( state );
    ui->lineEdit_wireProviderInput_2->setEnabled( state );
    ui->lineEdit_wireDiameterInput_2->setEnabled( state );
    ui->lineEdit_wireAreaInput_2->setEnabled( state );
    ui->lineEdit_wireMaterialInput_2->setEnabled( state );
    ui->lineEdit_turnsIN_2->setEnabled( state );
}

void WindowNewProject::enableOutput2( bool state ){
    ui->lineEdit_voltageOutput_2->setEnabled( state );
    ui->lineEdit_currentOutput_2->setEnabled( state );
    ui->lineEdit_densityCurrentOutput_2->setEnabled( state );
    ui->lineEdit_wireIDOutput_2->setEnabled( state );
    ui->comboBox_wireTypeOutput_2->setEnabled( state );
    ui->lineEdit_wireAWGOutput_2->setEnabled( state );
    ui->lineEdit_wireProviderOutput_2->setEnabled( state );
    ui->lineEdit_wireDiameterOutput_2->setEnabled( state );
    ui->lineEdit_wireAreaOutput_2->setEnabled( state );
    ui->lineEdit_wireMaterialOutput_2->setEnabled( state );
    ui->lineEdit_turnsOUT_2->setEnabled( state );
}

void WindowNewProject::on_lineEdit_patternWindingNumber_textChanged( const QString &text ){
    int patternNumber = text.toInt();
    if( (patternNumber >= 0) && (patternNumber <= 5) ){
        ui->comboBox_patternWindingName->setCurrentIndex( patternNumber );
    }
}

void  WindowNewProject::on_comboBox_patternWindingName_currentIndexChanged(int index){
    switch( index ){
        case 0:
            enableInput2( false );
            enableOutput2( false );
            //ui->checkBox_centerTap->setEnabled( true );
            ui->lineEdit_patternWindingNumber->setText( "0" );
            break;
        case 1:
            enableInput2( false );
            enableOutput2( true );
            ui->lineEdit_voltageOutput_2->setText(  QString::number( 2 * ui->lineEdit_voltageOutput_1->text().toDouble(), 'f', precision ) );
            //ui->checkBox_centerTap->setEnabled( false );
            //ui->checkBox_centerTap->setChecked( false );
            ui->lineEdit_patternWindingNumber->setText( "1" );
            break;
        case 2:
            enableInput2( true );
            enableOutput2( false );
            ui->lineEdit_voltageInput_2->setText(  QString::number( 2 * ui->lineEdit_voltageInput_1->text().toDouble(), 'f', precision ) );
            //ui->checkBox_centerTap->setEnabled( true );
            ui->lineEdit_patternWindingNumber->setText( "2" );
            break;
        case 3:
            enableInput2( true );
            enableOutput2( true );
            ui->lineEdit_voltageInput_2->setText(  QString::number( 2 * ui->lineEdit_voltageInput_1->text().toDouble(), 'f', precision ) );
            ui->lineEdit_voltageOutput_2->setText(  QString::number( 2 * ui->lineEdit_voltageOutput_1->text().toDouble(), 'f', precision ) );
            //ui->checkBox_centerTap->setEnabled( false );
            //ui->checkBox_centerTap->setChecked( false );
            ui->lineEdit_patternWindingNumber->setText( "3" );
            break;
        default:
            ui->lineEdit_patternWindingNumber->setText( "4" );
            break;
    }
}

void WindowNewProject::on_lineEdit_voltageInput_1_textChanged( const QString &text ){
    unsigned int pattern = ui->lineEdit_patternWindingNumber->text().toUInt();
    if( (pattern == 2) || (pattern == 3) ){
        ui->lineEdit_voltageInput_2->setText( QString::number( 2 * text.toDouble(), 'f', precision ) );
    }
}

void WindowNewProject::on_lineEdit_voltageOutput_1_textChanged( const QString &text ){
    unsigned int pattern = ui->lineEdit_patternWindingNumber->text().toUInt();
    if( (pattern == 1) || (pattern == 3) ){
        ui->lineEdit_voltageOutput_2->setText( QString::number( 2 * text.toDouble(), 'f', precision ) );
    }
}

void WindowNewProject::on_pushButton_calculate_clicked(){
    QMessageBox msgBox;
    std::string text;

    this->setTransformer();
    int option = transformer->calculate();

    switch( option ){
        case ResultCalculus::CorrectResult:
        {
            // general informations //
            ui->lineEdit_densityAverageCurrent->setText( QString::number( transformer->getAverageCurrentDensity(), 'f', precision ) );
            ui->lineEdit_weightTurns->setText( QString::number( transformer->getWeightCopper(), 'f', precision ) );
            ui->lineEdit_ironWeight->setText( QString::number( transformer->getWeightIron(), 'f', precision ) );
            ui->lineEdit_TurnsLoss->setText( QString::number( transformer->getCopperLoss(), 'f', precision ) );
            ui->lineEdit_ironLoss->setText( QString::number( transformer->getIronLoss(), 'f', precision ) );
            ui->lineEdit_averageTurnLength->setText( QString::number( transformer->getAverageTurnLength() / 10.0, 'f', precision ) );
            ui->lineEdit_totalLoss->setText( QString::number( transformer->getTotalLoss(), 'f', precision ) );
            ui->lineEdit_turnsArea->setText( QString::number( transformer->getCopperArea(), 'f', precision ) );
            ui->lineEdit_efficiency->setText( QString::number( transformer->getEfficiency(), 'f', precision ) );

            // input/output informations ONE //
            ui->lineEdit_powerInput->setText( QString::number( transformer->getInputPower(), 'f', precision ) );

            this->writeInput1(
                        transformer->getInputVoltage1(),
                        transformer->getInputCurrent1(),
                        transformer->getInputCurrentDensity1(),
                        transformer->getInputWire1()->getId(),
                        0, //transformer->getWireIN1()->getType(),
                        transformer->getInputWire1()->getAWG().c_str(),
                        transformer->getInputWire1()->getProvider().c_str(),
                        transformer->getInputWire1()->getDiameter(),
                        transformer->getInputWire1()->getArea(),
                        transformer->getInputWire1()->getMaterial().c_str(),
                        transformer->getInputWireTurns1()
            );

            this->writeOutput1(
                        transformer->getOutputVoltage1(),
                        transformer->getOutputCurrent1(),
                        transformer->getOutputCurrentDensity1(),
                        transformer->getOutputWire1()->getId(),
                        0, //transformer->getWireOUT1()->getType(),
                        transformer->getOutputWire1()->getAWG().c_str(),
                        transformer->getOutputWire1()->getProvider().c_str(),
                        transformer->getOutputWire1()->getDiameter(),
                        transformer->getOutputWire1()->getArea(),
                        transformer->getOutputWire1()->getMaterial().c_str(),
                        transformer->getOutputWireTurns1()
            );

            // input/output informations TWO //

            this->writeInput2( 0.0, 0.0, 0.0, 0, 0, "-", "-", 0.0, 0.0, "-", 0 );
            this->writeOutput2( 0.0, 0.0, 0.0, 0, 0, "-", "-", 0.0, 0.0, "-", 0 );
            this->enableInput2( false );
            this->enableOutput2( false );

            unsigned int pattern = this->transformer->getTransformerPatternNumber();
            if( (pattern == 2) || (pattern == 3) ){
                this->writeInput2(
                            transformer->getInputVoltage2(),
                            transformer->getInputCurrent2(),
                            transformer->getInputCurrentDensity2(),
                            transformer->getInputWire2()->getId(),
                            0, //transformer->getWireIN2()->getType(),
                            transformer->getInputWire2()->getAWG().c_str(),
                            transformer->getInputWire2()->getProvider().c_str(),
                            transformer->getInputWire2()->getDiameter(),
                            transformer->getInputWire2()->getArea(),
                            transformer->getInputWire2()->getMaterial().c_str(),
                            transformer->getInputWireTurns2()
                );
                this->enableInput2( true );
            }

            if( (pattern == 1) || (pattern == 3) || (this->transformer->getApplyCenterTap()) ){
                this->writeOutput2(
                            transformer->getOutputVoltage2(),
                            transformer->getOutputCurrent2(),
                            transformer->getOutputCurrentDensity2(),
                            transformer->getOutputWire2()->getId(),
                            0, //transformer->getWireOUT2()->getType(),
                            transformer->getOutputWire2()->getAWG().c_str(),
                            transformer->getOutputWire2()->getProvider().c_str(),
                            transformer->getOutputWire2()->getDiameter(),
                            transformer->getOutputWire2()->getArea(),
                            transformer->getOutputWire2()->getMaterial().c_str(),
                            transformer->getOutputWireTurns2()
                );
                this->enableOutput2( true );
            }

            // lamina and bobbin informations //
            ui->lineEdit_laminaID->setText( std::to_string( transformer->getLamina()->getId() ).c_str() );
            ui->lineEdit_laminaProvider->setText( transformer->getLamina()->getProvider().c_str() );
            ui->lineEdit_laminaWidth->setText( QString::number( transformer->getLamina()->getWidth(), 'f', precision ) );
            ui->lineEdit_laminaArea->setText( QString::number( transformer->getLamina()->getWindowArea(), 'f', precision ) );
            ui->lineEdit_laminaWeight->setText( QString::number( transformer->getLamina()->getWeight(), 'f', precision ) );
            ui->lineEdit_laminaCompensation->setText( QString::number( transformer->getLamina()->getCompensationPercent(), 'f', precision ) );

            ui->lineEdit_bobbinID->setText( std::to_string( transformer->getBobbin()->getId() ).c_str() );
            ui->lineEdit_bobbinCode->setText( transformer->getBobbin()->getCode().c_str() );
            ui->lineEdit_bobbinProvider->setText( transformer->getBobbin()->getProvider().c_str() );
            ui->lineEdit_bobbinWidth->setText( QString::number( transformer->getBobbin()->getWidth(), 'f', precision ) );
            ui->lineEdit_bobbinLength->setText( QString::number( transformer->getBobbin()->getLength(), 'f', precision ) );
            ui->lineEdit_bobbinHeight->setText( QString::number( transformer->getBobbin()->getHeight(), 'f', precision ) );
            ui->lineEdit_bobbinArea->setText( QString::number( transformer->getBobbin()->getArea(), 'f', precision ) );

            text = "Projeto calculado com sucesso.";
            msgBox.setIcon( QMessageBox::Information );
            break;
        }

        case ResultCalculus::NotFoundWire:
        {
            text = "Não houve sucesso no cálculo do transformador, nao encontrou-se o fio que cumpra o calculo\n";
            msgBox.setIcon( QMessageBox::Warning );
            break;
        }

        case ResultCalculus::NotFoundLamina:
        {
            text = "Não houve sucesso no cálculo do transformador, nao encontrou-se a lamina que cumpra o calculo\n";
            msgBox.setIcon( QMessageBox::Warning );
            break;
        }

        case ResultCalculus::NotFoundBobbin:
        {
            text = "Não houve sucesso no cálculo do transformador, nao encontrou-se o carretel que cumpra o calculo\n";
            msgBox.setIcon( QMessageBox::Warning );
            break;
        }

        case ResultCalculus::ErrorAritmetic:
        {
            text = "Não houve sucesso no cálculo do transformador, pois algum dado de preenchimento gerou um erro aritmetico\n";
            msgBox.setIcon( QMessageBox::Warning );
            break;
        }

        case ResultCalculus::NotTransformPatter:
        {
            text = "Tipo definido pelo usuario, logo o processo de cálculo automático não está definido para este tipo de projeto\n";
            msgBox.setIcon( QMessageBox::Warning );
            break;
        }

        case ResultCalculus::UnderflowTry:
        {
            text = "O processo superou o limite de tentativas de solucao, e nao resultou em resultado valido\n";
            msgBox.setIcon( QMessageBox::Warning );
            break;
        }

        default:
        {
            text = "O processo gerou um erro desconhecido\n";
            msgBox.setIcon( QMessageBox::Critical );
            break;
        }
    }

    msgBox.setText( text.c_str() );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
}

void WindowNewProject::on_pushButton_clear_clicked(){
    QMessageBox msgBox;
    msgBox.setText( "Deseja limpar dados de projeto?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        this->clearFields();
    }
}

void WindowNewProject::on_pushButton_save_clicked(){
    QMessageBox msgBox;
    msgBox.setText( "Deseja salvar este projeto?" );
    msgBox.setIcon( QMessageBox::Information );
    msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        this->updateTransformer();
        if( this->database->executeSQL( transformer->toSQL() ) == 0 ){
            msgBox.setText( "Projeto salvo com sucesso." );
            msgBox.setIcon( QMessageBox::Information );
        }
        else{
            msgBox.setText( "Projeto não foi salvo. Erros ocorreram." );
            msgBox.setIcon( QMessageBox::Warning );
        }
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowNewProject::on_pushButton_close_clicked(){
    QMessageBox msgBox;
    msgBox.setText( "Deseja sair do formulário de criação de projeto?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        this->close();
    }
}
