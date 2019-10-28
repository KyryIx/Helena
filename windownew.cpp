#include "windownew.h"
#include "ui_windownew.h"

#define precision 2

WindowNew::WindowNew(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowNew)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->transformer = new Transformer( database );
}

WindowNew::~WindowNew()
{
    delete ui;
}

void WindowNew::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowNew::clearFields(){
    ui->comboBox_patternWinding->setCurrentIndex( 0 );
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
    ui->lineEdit_laminaWidth->setText( "" );
    ui->lineEdit_laminaArea->setText( "" );
    ui->lineEdit_laminaWeight->setText( "" );
    //ui->checkBox_laminaCompensation->setText( "" );
    ui->lineEdit_laminaCompensation->setText( "" );

    ui->lineEdit_bobbinID->setText( "" );
    ui->lineEdit_bobbinType->setText( "" );
    ui->lineEdit_bobbinCode->setText( "" );
    ui->lineEdit_bobbinProvider->setText( "" );
    ui->lineEdit_bobbinWidth->setText( "" );
    ui->lineEdit_bobbinLength->setText( "" );
    ui->lineEdit_bobbinHeight->setText( "" );
    ui->lineEdit_bobbinArea->setText( "" );
}

void WindowNew::setTransformer(){
    double frequency                = ui->lineEdit_frequency->text().toDouble();
    double magneticInduction        = ui->lineEdit_magneticInduction->text().toDouble();
    double currentDensity           = ui->lineEdit_currentDensity->text().toDouble();
    double voltageIN_1              = ui->lineEdit_voltageInput_1->text().toDouble();
    double voltageIN_2              = ui->lineEdit_voltageInput_2->text().toDouble();
    double powerOUT                 = ui->lineEdit_powerOutput->text().toDouble();
    double voltageOUT_1             = ui->lineEdit_voltageOutput_1->text().toDouble();
    double voltageOUT_2             = ui->lineEdit_voltageOutput_2->text().toDouble();
    unsigned int patternTransformer = static_cast<unsigned int>( ui->comboBox_patternWinding->currentIndex() );
    double accommodation            = ui->lineEdit_windowAreaPerSectionTurns->text().toDouble();
    std::string typeWireIN_1        = ui->comboBox_wireTypeInput_1->currentText().toStdString();
    std::string typeWireIN_2        = ui->comboBox_wireTypeInput_2->currentText().toStdString();
    std::string typeWireOUT_1       = ui->comboBox_wireTypeOutput_1->currentText().toStdString();
    std::string typeWireOUT_2       = ui->comboBox_wireTypeOutput_2->currentText().toStdString();
    std::string typeLamina          = ui->comboBox_laminaType->currentText().toStdString();
    std::string typeBobbin          = ui->lineEdit_bobbinType->text().toStdString();
    Wire* wireIN_1                  = new Wire();
    Wire* wireIN_2                  = new Wire();
    Wire* wireOUT_1                 = new Wire();
    Wire* wireOUT_2                 = new Wire();
    Lamina* lamina                  = new Lamina();
    Bobbin* bobbin                  = new Bobbin();

    double compensationPower  = 0.0;
    if( ui->checkBox_compensation_power->isChecked() ){
        compensationPower = ui->lineEdit_compensation_power->text().toDouble();
        this->transformer->setApplyCompensationTransformer( true );
    }
    double compensationLamina = 0.0;
    if( ui->checkBox_laminaCompensation->isChecked() ){
        compensationLamina = ui->lineEdit_laminaCompensation->text().toDouble();
        this->transformer->setApplyCompensationLamina( true );
    }

    wireIN_1->setType( typeWireIN_1 );
    wireIN_2->setType( typeWireIN_2 );
    wireOUT_1->setType( typeWireOUT_1 );
    wireOUT_2->setType( typeWireOUT_2 );
    lamina->setType( typeLamina );
    lamina->setThicknessPercent( compensationLamina );
    bobbin->setType( typeBobbin );

    this->transformer->setPowerOUT( powerOUT );
    this->transformer->setVoltageOUT1( voltageOUT_1 );
    this->transformer->setVoltageOUT2( voltageOUT_2 );
    this->transformer->setVoltageIN1( voltageIN_1 );
    this->transformer->setVoltageIN2( voltageIN_2 );
    this->transformer->setFrequency( frequency );
    this->transformer->setMagneticInduction( magneticInduction );
    this->transformer->setCurrentDensity( currentDensity );
    this->transformer->setPatternTransformer( patternTransformer );
    this->transformer->setCompensationLossTransformer( compensationPower );
    this->transformer->setWindowAreaPerSectionCu( accommodation );
    this->transformer->setLamina( lamina );
    this->transformer->setBobbin( bobbin );
    this->transformer->setWireIN1( wireIN_1 );
    this->transformer->setWireIN2( wireIN_2 );
    this->transformer->setWireOUT1( wireOUT_1 );
    this->transformer->setWireOUT2( wireOUT_2 );
}

void WindowNew::writeInput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned int type, const char* awg, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageInput_1->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentInput_1->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentInput_1->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDInput_1->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeInput_1->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGInput_1->setText( awg );
    ui->lineEdit_wireDiameterInput_1->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaInput_1->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialInput_1->setText( material );
    ui->lineEdit_turnsIN_1->setText( std::to_string( turns ).c_str() );
}

void WindowNew::writeInput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageInput_2->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentInput_2->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentInput_2->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDInput_2->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeInput_2->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGInput_2->setText( awg );
    ui->lineEdit_wireDiameterInput_2->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaInput_2->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialInput_2->setText( material );
    ui->lineEdit_turnsIN_2->setText( std::to_string( turns ).c_str() );
}

void WindowNew::writeOutput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageOutput_1->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentOutput_1->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentOutput_1->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDOutput_1->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeOutput_1->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGOutput_1->setText( awg );
    ui->lineEdit_wireDiameterOutput_1->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaOutput_1->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialOutput_1->setText( material );
    ui->lineEdit_turnsOUT_1->setText( std::to_string( turns ).c_str() );
}

void WindowNew::writeOutput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns ){
    ui->lineEdit_voltageOutput_2->setText( QString::number( voltage, 'f', precision ) );
    ui->lineEdit_currentOutput_2->setText( QString::number( current, 'f', precision ) );
    ui->lineEdit_densityCurrentOutput_2->setText( QString::number( densityCurrent, 'f', precision ) );
    ui->lineEdit_wireIDOutput_2->setText( std::to_string( id ).c_str() );
    ui->comboBox_wireTypeOutput_2->setCurrentIndex( static_cast<int>( type ) );
    ui->lineEdit_wireAWGOutput_2->setText( awg );
    ui->lineEdit_wireDiameterOutput_2->setText( QString::number( diameter, 'f', precision ) );
    ui->lineEdit_wireAreaOutput_2->setText( QString::number( area, 'f', precision ) );
    ui->lineEdit_wireMaterialOutput_2->setText( material );
    ui->lineEdit_turnsOUT_2->setText( std::to_string( turns ).c_str() );
}

void WindowNew::enableInput2( bool state ){
    ui->lineEdit_voltageInput_2->setEnabled( state );
    ui->lineEdit_currentInput_2->setEnabled( state );
    ui->lineEdit_densityCurrentInput_2->setEnabled( state );
    ui->lineEdit_wireIDInput_2->setEnabled( state );
    ui->comboBox_wireTypeInput_2->setEnabled( state );
    ui->lineEdit_wireAWGInput_2->setEnabled( state );
    ui->lineEdit_wireDiameterInput_2->setEnabled( state );
    ui->lineEdit_wireAreaInput_2->setEnabled( state );
    ui->lineEdit_wireMaterialInput_2->setEnabled( state );
    ui->lineEdit_turnsIN_2->setEnabled( state );
}

void WindowNew::enableOutput2( bool state ){
    ui->lineEdit_voltageOutput_2->setEnabled( state );
    ui->lineEdit_currentOutput_2->setEnabled( state );
    ui->lineEdit_densityCurrentOutput_2->setEnabled( state );
    ui->lineEdit_wireIDOutput_2->setEnabled( state );
    ui->comboBox_wireTypeOutput_2->setEnabled( state );
    ui->lineEdit_wireAWGOutput_2->setEnabled( state );
    ui->lineEdit_wireDiameterOutput_2->setEnabled( state );
    ui->lineEdit_wireAreaOutput_2->setEnabled( state );
    ui->lineEdit_wireMaterialOutput_2->setEnabled( state );
    ui->lineEdit_turnsOUT_2->setEnabled( state );
}

void  WindowNew::on_comboBox_patternWinding_currentIndexChanged(int index){
    switch( index ){
        case 0:
            enableInput2( false );
            enableOutput2( false );
            break;
        case 1:
            enableInput2( false );
            enableOutput2( true );
            ui->lineEdit_voltageOutput_2->setText(  QString::number( 2 * ui->lineEdit_voltageOutput_1->text().toDouble(), 'f', precision ) );
            break;
        case 2:
            enableInput2( true );
            enableOutput2( false );
            ui->lineEdit_voltageInput_2->setText(  QString::number( 2 * ui->lineEdit_voltageInput_1->text().toDouble(), 'f', precision ) );
            break;
        case 3:
            enableInput2( true );
            enableOutput2( true );
            ui->lineEdit_voltageInput_2->setText(  QString::number( 2 * ui->lineEdit_voltageInput_1->text().toDouble(), 'f', precision ) );
            ui->lineEdit_voltageOutput_2->setText(  QString::number( 2 * ui->lineEdit_voltageOutput_1->text().toDouble(), 'f', precision ) );
            break;
    }
}

void WindowNew::on_lineEdit_voltageInput_1_textChanged( const QString &text ){
    if( ui->comboBox_patternWinding->currentIndex() > 1 ){
        ui->lineEdit_voltageInput_2->setText( QString::number( 2 * text.toDouble(), 'f', precision ) );
    }
}

void WindowNew::on_lineEdit_voltageOutput_1_textChanged( const QString &text ){
    if( ui->comboBox_patternWinding->currentIndex() % 2 == 1 ){
        ui->lineEdit_voltageOutput_2->setText( QString::number( 2 * text.toDouble(), 'f', precision ) );
    }
}

void WindowNew::on_pushButton_calculate_clicked(){
    QMessageBox msgBox;
    std::string text;
    msgBox.setIcon( QMessageBox::Warning );

    this->setTransformer();
    int option = transformer->calculate();

    if( option == 0 ){
        // general informations //
        ui->lineEdit_densityAverageCurrent->setText( QString::number( transformer->getAverageCurrentDensity(), 'f', precision ) );
        ui->lineEdit_weightTurns->setText( QString::number( transformer->getWeightCopper(), 'f', precision ) );
        ui->lineEdit_ironWeight->setText( QString::number( transformer->getWeigthIron(), 'f', precision ) );
        ui->lineEdit_TurnsLoss->setText( QString::number( transformer->getCopperLoss(), 'f', precision ) );
        ui->lineEdit_ironLoss->setText( QString::number( transformer->getIronLoss(), 'f', precision ) );
        ui->lineEdit_averageTurnLength->setText( QString::number( transformer->getTurnAverageLength() / 10.0, 'f', precision ) );
        ui->lineEdit_totalLoss->setText( QString::number( transformer->getTotalLoss(), 'f', precision ) );
        ui->lineEdit_turnsArea->setText( QString::number( transformer->getCoilArea(), 'f', precision ) );
        ui->lineEdit_efficiency->setText( QString::number( transformer->getEfficiency() * 100.0, 'f', precision ) );

        // input/output informations //
        ui->lineEdit_powerInput->setText( std::to_string( transformer->getPowerIN() ).c_str() );

        this->writeInput1(
                    transformer->getVoltageIN1(),
                    transformer->getCurrentIN1(),
                    transformer->getCurrentDensityIN1(),
                    transformer->getWireIN1()->getId(),
                    0, //transformer->getWireIN1()->getType(),
                    transformer->getWireIN1()->getAWG().c_str(),
                    transformer->getWireIN1()->getDiameter(),
                    transformer->getWireIN1()->getArea(),
                    transformer->getWireIN1()->getMaterial().c_str(),
                    transformer->getWireTurnsIN1()
        );

        this->writeOutput1(
                    transformer->getVoltageOUT1(),
                    transformer->getCurrentOUT1(),
                    transformer->getCurrentDensityOUT1(),
                    transformer->getWireOUT1()->getId(),
                    0, //transformer->getWireOUT1()->getType(),
                    transformer->getWireOUT1()->getAWG().c_str(),
                    transformer->getWireOUT1()->getDiameter(),
                    transformer->getWireOUT1()->getArea(),
                    transformer->getWireOUT1()->getMaterial().c_str(),
                    transformer->getWireTurnsOUT1()
        );

        this->writeInput2( 0.0, 0.0, 0.0, 0, 0, "-", 0.0, 0.0, "-", 0 );
        this->writeOutput2( 0.0, 0.0, 0.0, 0, 0, "-", 0.0, 0.0, "-", 0 );
        this->enableInput2( false );
        this->enableOutput2( false );

        if( this->transformer->getPatternTransformer() > 1 ){
            this->writeInput2(
                        transformer->getVoltageIN2(),
                        transformer->getCurrentIN2(),
                        transformer->getCurrentDensityIN2(),
                        transformer->getWireIN2()->getId(),
                        0, //transformer->getWireIN2()->getType(),
                        transformer->getWireIN2()->getAWG().c_str(),
                        transformer->getWireIN2()->getDiameter(),
                        transformer->getWireIN2()->getArea(),
                        transformer->getWireIN2()->getMaterial().c_str(),
                        transformer->getWireTurnsIN2()
            );
            this->enableInput2( true );
        }

        if( this->transformer->getPatternTransformer() % 2 == 1 ){
            this->writeOutput2(
                        transformer->getVoltageOUT2(),
                        transformer->getCurrentOUT2(),
                        transformer->getCurrentDensityOUT2(),
                        transformer->getWireOUT2()->getId(),
                        0, //transformer->getWireOUT2()->getType(),
                        transformer->getWireOUT2()->getAWG().c_str(),
                        transformer->getWireOUT2()->getDiameter(),
                        transformer->getWireOUT2()->getArea(),
                        transformer->getWireOUT2()->getMaterial().c_str(),
                        transformer->getWireTurnsOUT2()
            );
            this->enableOutput2( true );
        }

        // lamina and bobbin informations //
        ui->lineEdit_laminaID->setText( std::to_string( transformer->getLamina()->getId() ).c_str() );
        ui->lineEdit_laminaWidth->setText( QString::number( transformer->getLamina()->getWidth(), 'f', precision ) );
        ui->lineEdit_laminaArea->setText( QString::number( transformer->getLamina()->getWindowArea(), 'f', precision ) );
        ui->lineEdit_laminaWeight->setText( QString::number( transformer->getLamina()->getWeight(), 'f', precision ) );
        ui->lineEdit_laminaCompensation->setText( QString::number( transformer->getLamina()->getThicknessPercent(), 'f', precision ) );
        ui->lineEdit_bobbinID->setText( std::to_string( transformer->getBobbin()->getId() ).c_str() );
        ui->lineEdit_bobbinCode->setText( transformer->getBobbin()->getCode().c_str() );
        ui->lineEdit_bobbinProvider->setText( transformer->getBobbin()->getProvider().c_str() );
        ui->lineEdit_bobbinWidth->setText( QString::number( transformer->getBobbin()->getWidth(), 'f', precision ) );
        ui->lineEdit_bobbinLength->setText( QString::number( transformer->getBobbin()->getLength(), 'f', precision ) );
        ui->lineEdit_bobbinHeight->setText( QString::number( transformer->getBobbin()->getHeight(), 'f', precision ) );
        ui->lineEdit_bobbinArea->setText( QString::number( transformer->getBobbin()->getArea(), 'f', precision ) );

        FILE* fp1 = fopen( "example.txt", "w" );
        FILE* fp2 = fopen( "example.html", "w" );
        FILE* fp3 = fopen( "example.sql", "w" );
        fputs( transformer->toString().c_str(), fp1 );
        fputs( transformer->toHTML().c_str(), fp2 );
        fputs( transformer->toSQL().c_str(), fp3 );
        fclose( fp1 );
        fclose( fp2 );
        fclose( fp3 );

        text = "Projeto calculado com sucesso.";
        msgBox.setIcon( QMessageBox::Information );
    }
    else{
        text  = "Não houve sucesso no cálculo do transformador\n";
        text += " pois ";
        switch( option ) {
            case -1:
                text += "nao encontrou-se o fio que cumpra o calculo\n";
                break;
            case -2:
                text += "nao encontrou-se o lamina que cumpra o calculo\n";
                break;
            case -3:
                text += "nao encontrou-se o carretel que cumpra o calculo\n";
                break;
            case -4:
                text += "pois houve divisao por zero ou outro erro aritmetico\n";
                break;
            case -100:
                text += "pois superou o limite de tentativas de solucao\n";
                break;
        }
        text += "onde\n";
        text += "Tipo de lâmina: " + ui->comboBox_laminaType->currentText().toStdString() + "\n";
        text += "Tipo de carretel: " + ui->lineEdit_bobbinType->text().toStdString()  + "\n";
        switch( transformer->getPatternTransformer() ) {
            case 0:
                text += "Tipo de fio do primário: " + ui->comboBox_wireTypeInput_1->currentText().toStdString() + "\n";
                text += "Tipo de fio do secundário: " + ui->comboBox_wireTypeOutput_1->currentText().toStdString();
                break;
            case 1:
                text += "Tipo de fio do primário: " + ui->comboBox_wireTypeInput_1->currentText().toStdString() + "\n";
                text += "Tipo de fio do secundários: " + ui->comboBox_wireTypeOutput_1->currentText().toStdString() + "/" + ui->comboBox_wireTypeOutput_2->currentText().toStdString();
                break;
            case 2:
                text += "Tipo de fio do primários: " + ui->comboBox_wireTypeInput_1->currentText().toStdString() + "/" + ui->comboBox_wireTypeInput_2->currentText().toStdString() + "\n";
                text += "Tipo de fio do secundário: " + ui->comboBox_wireTypeOutput_1->currentText().toStdString();
                break;
            case 3:
                text += "Tipo de fio do primários: " + ui->comboBox_wireTypeInput_1->currentText().toStdString() + "/" + ui->comboBox_wireTypeInput_2->currentText().toStdString() + "\n";
                text += "Tipo de fio do secundários: " + ui->comboBox_wireTypeOutput_1->currentText().toStdString() + "/" + ui->comboBox_wireTypeOutput_2->currentText().toStdString();
            break;
        }

        msgBox.setIcon( QMessageBox::Warning );
    }

    msgBox.setText( text.c_str() );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
}

void WindowNew::on_pushButton_clear_clicked(){
    this->clearFields();
}

void WindowNew::on_pushButton_save_clicked(){
    QMessageBox msgBox;

    if( this->transformer->getState() == false ){
        this->setTransformer();
    }

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

void WindowNew::on_pushButton_close_clicked(){
    this->close();
    //if( this->getStateSave() == false ){
    /*
    if( false ){
        QMessageBox msgBox;
        msgBox.setText( "Deseja sair sem salvar o projeto" );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::No );
        int result = msgBox.exec();
        switch( result ){
            case QMessageBox::Ok:
                this->close();
                break;
            case QMessageBox::No:
            default:
                break;
        }
    }
    else{
        this->close();
    }
    */
}
