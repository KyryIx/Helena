#include "windownew.h"
#include "ui_windownew.h"

WindowNew::WindowNew(QWidget *parent,  DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowNew)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->setStateSave( false );
    transformer = new Transformer( database );
}

WindowNew::~WindowNew()
{
    delete ui;
}

void WindowNew::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowNew::setStateSave( bool state ){
    this->stateSave = state;
}

bool WindowNew::getStateSave(){
    return this->stateSave;
}

void WindowNew::on_pushButton_calculate_clicked(){
    this->setStateSave( false );
    QMessageBox msgBox;
    unsigned int patternTransformer = 4;
    QString text   = ui->comboBox_patternWinding->currentText();
    if( text ==  "2 primários / 2 secundários" ){ patternTransformer = 3; }
    else if( text == "2 primários / 1 secundário" ){ patternTransformer = 2; }
    else if( text == "1 primário / 2 secundários" ){ patternTransformer = 1; }
    else{ patternTransformer = 0; /* patterText == "1 primário / 1 secundário" */ }
    double frequency         = ui->lineEdit_frequency->text().toDouble();
    double magneticInduction = ui->lineEdit_magneticInduction->text().toDouble();
    double currentDensity    = ui->lineEdit_currentDensity->text().toDouble();
    double compensationPower = 0.0;
    if( ui->checkBox_compensation_power->isChecked() ){ compensationPower = ui->lineEdit_compensation_power->text().toDouble(); }
    double accommodation     = ui->lineEdit_windowAreaPerSectionTurns->text().toDouble();

    double voltageIN         = ui->lineEdit_voltageInput->text().toDouble();
    double powerOUT          = ui->lineEdit_powerOutput->text().toDouble();
    double voltageOUT        = ui->lineEdit_voltageOutput->text().toDouble();
    std::string typeWireIN   = "";
    std::string typeWireOUT  = "";
    text = ui->comboBox_wireTypeInput->currentText();
    if( text == "redondo" ){ typeWireIN = "redondo"; }
    text = ui->comboBox_wireTypeOutput->currentText();
    if( text == "redondo" ){ typeWireOUT = "redondo"; }

    std::string typeLamina    = "";
    double compensationLamina = 0.0;
    text = ui->comboBox_laminaType->currentText();
    if( text == "padrao" ){ typeLamina = "padrao"; }
    if( text == "especial" ){ typeLamina = "especial"; }
    if( ui->checkBox_laminaCompensation->isChecked() ){
        compensationLamina = ui->lineEdit_laminaCompensation->text().toDouble();
    }
    std::string typeBobbin   = ui->lineEdit_bobbinType->text().toStdString();

    Wire* wireIN   = new Wire();
    Wire* wireOUT  = new Wire();
    Lamina* lamina = new Lamina();
    Bobbin* bobbin = new Bobbin();

    wireIN->setType( typeWireIN );
    wireOUT->setType( typeWireOUT );
    lamina->setType( typeLamina );
    lamina->setThicknessPercent( compensationLamina );
    bobbin->setType( typeBobbin );

    transformer->setPowerOUT( powerOUT );
    transformer->setVoltageOUT( voltageOUT );
    transformer->setVoltageIN( voltageIN );
    transformer->setFrequency( frequency );
    transformer->setMagneticInduction( magneticInduction );
    transformer->setCurrentDensity( currentDensity );
    transformer->setPatternTransformer( patternTransformer );
    transformer->setCompensationLossTransformer( compensationPower );
    transformer->setWindowAreaPerSectionCu( accommodation );
    transformer->setLamina( lamina );
    transformer->setBobbin( bobbin );
    transformer->setWireIN( wireIN );
    transformer->setWireOUT( wireOUT );
    std::string reportTEXT, reportHTML, reportSQL;
    if( transformer->calculate() ){
        std::string text = "";

        // general informations //
        text = std::to_string( transformer->getAverageCurrentDensity() );
        ui->lineEdit_densityAverageCurrent->setText( text.c_str() );
        text = std::to_string( transformer->getWeightCopper() );
        ui->lineEdit_weightTurns->setText( text.c_str() );
        text = std::to_string( transformer->getWeigthIron() );
        ui->lineEdit_ironWeight->setText( text.c_str() );
        text = std::to_string( transformer->getCopperLoss() );
        ui->lineEdit_TurnsLoss->setText( text.c_str() );
        text = std::to_string( transformer->getIronLoss() );
        ui->lineEdit_ironLoss->setText( text.c_str() );
        text = std::to_string( transformer->getTurnAverageLength() / 10.0 );
        ui->lineEdit_averageTurnLength->setText( text.c_str() );
        text = std::to_string( transformer->getTotalLoss() );
        ui->lineEdit_totalLoss->setText( text.c_str() );
        text = std::to_string( transformer->getCoilArea() );
        ui->lineEdit_turnsArea->setText( text.c_str() );
        text = std::to_string( transformer->getEfficiency() * 100.0 );
        ui->lineEdit_efficiency->setText( text.c_str() );

        // input/output informations //
        text = std::to_string( transformer->getPowerIN() );
        ui->lineEdit_powerInput->setText( text.c_str() );
        text = std::to_string( transformer->getCurrentIN() );
        ui->lineEdit_currentInput->setText( text.c_str() );
        text = std::to_string( transformer->getCurrentDensityIN() );
        ui->lineEdit_densityCurrentInput->setText( text.c_str() );
        text = std::to_string( transformer->getCurrentOUT() );
        ui->lineEdit_currentOutput->setText( text.c_str() );
        text = std::to_string( transformer->getCurrentDensityOUT() );
        ui->lineEdit_densityCurrentOutput->setText( text.c_str() );
        text = std::to_string( transformer->getWireIN()->getId() );
        ui->lineEdit_wireIDInput->setText( text.c_str() );
        ui->lineEdit_wireAWGInput->setText( transformer->getWireIN()->getAWG().c_str() );
        text = std::to_string( transformer->getWireIN()->getDiameter() );
        ui->lineEdit_wireDiameterInput->setText( text.c_str() );
        text = std::to_string( transformer->getWireIN()->getArea() );
        ui->lineEdit_wireAreaInput->setText( text.c_str() );
        ui->lineEdit_wireMaterialInput->setText( transformer->getWireIN()->getMaterial().c_str() );
        text = std::to_string( transformer->getWireTurnsIN() );
        ui->lineEdit_turnsIN->setText( text.c_str() );
        text = std::to_string( transformer->getWireOUT()->getId() );
        ui->lineEdit_wireIDOutput->setText( text.c_str() );
        ui->lineEdit_wireAWGOutput->setText( transformer->getWireOUT()->getAWG().c_str() );
        text = std::to_string( transformer->getWireOUT()->getDiameter() );
        ui->lineEdit_wireDiameterOutput->setText( text.c_str() );
        text = std::to_string( transformer->getWireOUT()->getArea() );
        ui->lineEdit_wireAreaOutput->setText( text.c_str() );
        ui->lineEdit_wireMaterialOutput->setText( transformer->getWireOUT()->getMaterial().c_str() );
        text = std::to_string( transformer->getWireTurnsOUT() );
        ui->lineEdit_turnsOUT->setText( text.c_str() );

        // lamina and bobbin informations //
        text = std::to_string( transformer->getLamina()->getId() );
        ui->lineEdit_laminaID->setText( text.c_str() );
        text = std::to_string( transformer->getLamina()->getWidth() );
        ui->lineEdit_laminaWidth->setText( text.c_str() );
        text = std::to_string( transformer->getLamina()->getWindowArea() );
        ui->lineEdit_laminaArea->setText( text.c_str() );
        text = std::to_string( transformer->getLamina()->getWeight() );
        ui->lineEdit_laminaWeight->setText( text.c_str() );
        text = std::to_string( transformer->getLamina()->getThicknessPercent() );
        ui->lineEdit_laminaCompensation->setText( text.c_str() );
        text = std::to_string( transformer->getBobbin()->getId() );
        ui->lineEdit_bobbinID->setText( text.c_str() );
        ui->lineEdit_bobbinCode->setText( transformer->getBobbin()->getCode().c_str() );
        ui->lineEdit_bobbinProvider->setText( transformer->getBobbin()->getProvider().c_str() );
        text = std::to_string( transformer->getBobbin()->getWidth() );
        ui->lineEdit_bobbinWidth->setText( text.c_str() );
        text = std::to_string( transformer->getBobbin()->getLength() );
        ui->lineEdit_bobbinLength->setText( text.c_str() );
        text = std::to_string( transformer->getBobbin()->getHeight() );
        ui->lineEdit_bobbinHeight->setText( text.c_str() );
        text = std::to_string( transformer->getBobbin()->getArea() );
        ui->lineEdit_bobbinArea->setText( text.c_str() );

        msgBox.setText( "Projeto calculado com sucesso." );
        msgBox.setIcon( QMessageBox::Information );
    }
    else {
        std::string text = "";
        text  = "Não houve sucesso no cálculo do transformador, onde\n";
        text += "           Tipo de lâmina: " + lamina->getType()  + "\n";
        text += "         Tipo de carretel: " + bobbin->getType()  + "\n";
        text += "  Tipo de fio do primário: " + wireIN->getType()  + "\n";
        text += "Tipo de fio do secundário: " + wireOUT->getType();
        msgBox.setText( text.c_str() );
        msgBox.setIcon( QMessageBox::Warning );
    }
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
    /*
    Wire* wireIN   = new Wire();
    Wire* wireOUT  = new Wire();
    Lamina* lamina = new Lamina();
    Bobbin* bobbin = new Bobbin();

    wireIN->setType( "redondo" );
    wireOUT->setType( "redondo" );
    lamina->setType( "padrao" );
    bobbin->setType( "STSR" );

    // #####################################
    // ## Current Density value by Power   #
    // ## +------------+-----------------+ #
    // ## |   Power    | Current Density | #
    // ## |    (VA)    |    (A/mm^2)     | #
    // ## +------------+-----------------+ #
    // ## |   0 ~ 500  |        3        | #
    // ## +------------+-----------------+ #
    // ## | 500 ~ 1000 |       2.5       | #
    // ## +------------+-----------------+ #
    // ## |1000 ~ 3000 |        2        | #
    // ## +------------+-----------------+ #
    // #####################################

    Transformer* transformer1 = new Transformer( this->database );
    transformer1->setPowerOUT( 300.0 );
    transformer1->setVoltageOUT( 220.0 );
    transformer1->setVoltageIN( 120.0 );
    transformer1->setFrequency( 50 );
    transformer1->setMagneticInduction( 11300.0 );
    transformer1->setCurrentDensity( 3.0 );
    transformer1->setPatternTransformer( 0 );
    transformer1->setLamina( lamina );
    transformer1->setBobbin( bobbin );
    transformer1->setWireIN( wireIN );
    transformer1->setWireOUT( wireOUT );
    std::string reportTEXT, reportHTML;
    if( transformer1->calculate() ){
        reportTEXT = transformer1->toString();
        reportHTML = transformer1->toHTML();
    }
    else {
        reportTEXT  = "Não houve sucesso no cálculo do transformador, onde\n";
        reportTEXT += "           Tipo de lâmina: " + lamina->getType()  + "\n";
        reportTEXT += "         Tipo de carretel: " + bobbin->getType()  + "\n";
        reportTEXT += "  Tipo de fio do primário: " + wireIN->getType()  + "\n";
        reportTEXT += "Tipo de fio do secundário: " + wireOUT->getType();

        reportHTML  = "<table align=\"center\">\n";
        reportHTML += "\t<tr><td align=\"center\" colspan=\"2\">Não houve sucesso no cálculo do transformador</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de lâmina:</td><td>" + lamina->getType() + "</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de carretel:</td><td>" + bobbin->getType() + "</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de fio do primário:</td><td>" + wireIN->getType() + "</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de fio do secundário:</td><td>" + wireIN->getType() + "</td></tr>\n";
        reportHTML += "</table>";
    }

    FILE* fp;
    fp = fopen( "example_1.txt", "w" );
    fputs( reportTEXT.c_str(), fp );
    fclose( fp );

    fp = fopen( "example_1.html", "w" );
    fputs( reportHTML.c_str(), fp );
    fclose( fp );

    // ###################################################
    // ###################################################
    Transformer* transformer2 = new Transformer( this->database );
    transformer2->setPowerOUT( 1000.0 );
    transformer2->setVoltageOUT( 24.0 );
    transformer2->setVoltageIN( 220.0 );
    transformer2->setFrequency( 50 );
    transformer2->setMagneticInduction( 11300.0 );
    transformer2->setCurrentDensity( 2.5 );
    transformer2->setPatternTransformer( 0 );
    transformer2->setLamina( lamina );
    transformer2->setBobbin( bobbin );
    transformer2->setWireIN( wireIN );
    transformer2->setWireOUT( wireOUT );
    if( transformer2->calculate() ){
        reportTEXT = transformer2->toString();
        reportHTML = transformer2->toHTML();
    }
    else{
        reportTEXT  = "Não houve sucesso no cálculo do transformador, onde\n";
        reportTEXT += "           Tipo de lâmina: " + lamina->getType()  + "\n";
        reportTEXT += "         Tipo de carretel: " + bobbin->getType()  + "\n";
        reportTEXT += "  Tipo de fio do primário: " + wireIN->getType()  + "\n";
        reportTEXT += "Tipo de fio do secundário: " + wireOUT->getType();

        reportHTML  = "<table align=\"center\">\n";
        reportHTML += "\t<tr><td align=\"center\" colspan=\"2\">Não houve sucesso no cálculo do transformador</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de lâmina:</td><td>" + lamina->getType() + "</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de carretel:</td><td>" + bobbin->getType() + "</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de fio do primário:</td><td>" + wireIN->getType() + "</td></tr>\n";
        reportHTML += "\t<tr><td align=\"right\">Tipo de fio do secundário:</td><td>" + wireIN->getType() + "</td></tr>\n";
        reportHTML += "</table>";
    }

    fp = fopen( "example_2.txt", "w" );
    fputs( reportTEXT.c_str(), fp );
    fclose( fp );

    fp = fopen( "example_2.html", "w" );
    fputs( reportHTML.c_str(), fp );
    fclose( fp );

    // refazer o exemplo dois do martignoni acima, abaixo com os dados lamina especial
    */
}

void WindowNew::on_pushButton_save_clicked(){
    if( transformer->getAutomatic() == false ){
        transformer->setFrequency( atof( ui->lineEdit_frequency->text().toStdString().c_str() ) );
        transformer->setMagneticInduction( atof( ui->lineEdit_magneticInduction->text().toStdString().c_str() ) );
        transformer->setCurrentDensity( atof( ui->lineEdit_currentDensity->text().toStdString().c_str() ) );
        transformer->setAverageCurrentDensity( atof( ui->lineEdit_densityAverageCurrent->text().toStdString().c_str() ) );
        transformer->setWeigthIron( atof( ui->lineEdit_ironWeight->text().toStdString().c_str() ) );
        transformer->setWeightCopper( atof( ui->lineEdit_weightTurns->text().toStdString().c_str() ) );
        transformer->setTurnsAverageLength( atof( ui->lineEdit_averageTurnLength->text().toStdString().c_str() ) );
        transformer->setCoilArea( atof( ui->lineEdit_turnsArea->text().toStdString().c_str() ) );
        transformer->setIronLoss( atof( ui->lineEdit_ironLoss->text().toStdString().c_str() ) );
        transformer->setCopperLoss( atof( ui->lineEdit_totalLoss->text().toStdString().c_str() ) );
        transformer->setEfficiency( atof( ui->lineEdit_efficiency->text().toStdString().c_str() ) );

        QString text   = ui->comboBox_patternWinding->currentText();
        if( text ==  "2 primários / 2 secundários" ){
            transformer->setPatternTransformer( 3 );
        }
        else if( text == "2 primários / 1 secundário" ){
            transformer->setPatternTransformer( 2 );
        }
        else if( text == "1 primário / 2 secundários" ){
            transformer->setPatternTransformer( 1 );
        }
        else{ /* patterText == "1 primário / 1 secundário" */
            transformer->setPatternTransformer( 0 );
        }
        if( ui->checkBox_compensation_power->isChecked() ){
            transformer->setCompensationLossTransformer( atof( ui->lineEdit_compensation_power->text().toStdString().c_str() ) );
        }
        else{
            transformer->setCompensationLossTransformer( 0.0 );
        }

        transformer->setVoltageIN( atof( ui->lineEdit_voltageInput->text().toStdString().c_str() ) );
        transformer->setPowerIN( atof( ui->lineEdit_powerInput->text().toStdString().c_str() ) );
        transformer->setCurrentIN( atof( ui->lineEdit_currentInput->text().toStdString().c_str() ) );
        transformer->setCurrentDensityIN( atof( ui->lineEdit_densityCurrentInput->text().toStdString().c_str() ) );

        Wire* wireIN = new Wire();
        transformer->setWireTurnsIN( static_cast<unsigned int>( atoi( ui->lineEdit_turnsIN->text().toStdString().c_str() ) ) );
        wireIN->setId( static_cast<unsigned int>( atoi( ui->lineEdit_wireIDInput->text().toStdString().c_str() ) )  );
        wireIN->setAWG( ui->lineEdit_wireAWGInput->text().toStdString() );
        wireIN->setDiameter( atof( ui->lineEdit_wireDiameterInput->text().toStdString().c_str() ) );
        // falta: wire turn per cm IN";
        wireIN->setArea( atof( ui->lineEdit_wireAreaInput->text().toStdString().c_str() ) );
        // falta: wire resistance IN";
        // falta: wire weight IN";
        // falta: wire length IN";
        // falta: wire frequency IN";
        wireIN->setMaterial( ui->lineEdit_wireMaterialInput->text().toStdString() );
        transformer->setWireIN( wireIN );

        transformer->setVoltageOUT( atof( ui->lineEdit_voltageOutput->text().toStdString().c_str() ) );
        transformer->setPowerOUT( atof( ui->lineEdit_powerOutput->text().toStdString().c_str() ) );
        transformer->setCurrentOUT( atof( ui->lineEdit_currentOutput->text().toStdString().c_str() ) );
        transformer->setCurrentDensityOUT( atof( ui->lineEdit_densityCurrentOutput->text().toStdString().c_str() ) );

        Wire* wireOUT = new Wire();
        transformer->setWireTurnsOUT( static_cast<unsigned int>( atoi( ui->lineEdit_turnsOUT->text().toStdString().c_str() ) ) );
        wireOUT->setId( static_cast<unsigned int>( atoi( ui->lineEdit_wireIDOutput->text().toStdString().c_str() ) )  );
        wireOUT->setAWG( ui->lineEdit_wireAWGOutput->text().toStdString() );
        wireOUT->setDiameter( atof( ui->lineEdit_wireDiameterOutput->text().toStdString().c_str() ) );
        // falta: wire turn per cm OUT";
        wireOUT->setArea( atof( ui->lineEdit_wireAreaOutput->text().toStdString().c_str() ) );
        // falta: wire resistance OUT";
        // falta: wire weight OUT";
        // falta: wire length OUT";
        // falta: wire frequency OUT";
        wireOUT->setMaterial( ui->lineEdit_wireMaterialOutput->text().toStdString() );
        transformer->setWireIN( wireOUT );

        Lamina* lamina = new Lamina();
        lamina->setId( static_cast<unsigned int>( atoi( ui->lineEdit_laminaID->text().toStdString().c_str() ) ) );
        lamina->setType( ui->comboBox_laminaType->currentText().toStdString() );
        lamina->setWidth( atof( ui->lineEdit_laminaWidth->text().toStdString().c_str() ) );
        lamina->setWindowArea( atof( ui->lineEdit_laminaArea->text().toStdString().c_str() ) );
        lamina->setWeight( atof( ui->lineEdit_laminaWeight->text().toStdString().c_str() ) );
        if( ui->checkBox_laminaCompensation->isChecked() ){
            lamina->setThicknessPercent( atof( ui->lineEdit_laminaCompensation->text().toStdString().c_str() ) );
        }
        transformer->setLamina( lamina );

        Bobbin* bobbin = new Bobbin();
        bobbin->setId( static_cast<unsigned int>( atoi( ui->lineEdit_bobbinID->text().toStdString().c_str() ) ) );
        bobbin->setType( ui->lineEdit_bobbinType->text().toStdString() );
        bobbin->setCode( ui->lineEdit_bobbinCode->text().toStdString() );
        bobbin->setProvider( ui->lineEdit_bobbinProvider->text().toStdString() );
        bobbin->setWidth( atof( ui->lineEdit_bobbinWidth->text().toStdString().c_str() ) );
        bobbin->setLength( atof( ui->lineEdit_bobbinLength->text().toStdString().c_str() ) );
        bobbin->setHeight( atof( ui->lineEdit_bobbinHeight->text().toStdString().c_str() ) );
        transformer->setBobbin( bobbin );
    }

    QMessageBox msgBox;
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
    if( this->getStateSave() == false ){
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
}
