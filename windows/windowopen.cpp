#include "windows/windowopen.h"
#include "ui_windowopen.h"

WindowOpen::WindowOpen(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowOpen)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->init();
}

WindowOpen::~WindowOpen()
{
    delete ui;
}

void WindowOpen::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowOpen::valuesTemp(){
    this->patternWindingNumber = 0;
    this->patternWindingName = "";
    this->frequency = 0.0;
    this->currentDensity = 0.0;
    this->compensation_power_state = true;
    this->compensation_power_value = 0.0;
    this->weightTurns = 0.0;
    this->turnsLoss = 0.0;
    this->averageTurnLength = 0.0;
    this->turnsArea = 0.0;
    this->magneticInduction = 0.0;
    this->densityAverageCurrent = 0.0;
    this->windowAreaPerSectionTurns = 0.0;
    this->ironWeight = 0.0;
    this->ironLoss = 0.0;
    this->totalLoss = 0.0;
    this->efficiency = 0.0;
    this->observation = "";

    this->powerInput = 0.0;
    this->voltageInput_1 = 0.0;
    this->voltageInput_2 = 0.0;
    this->currentInput_1 = 0.0;
    this->currentInput_2 = 0.0;
    this->densityCurrentInput_1 = 0.0;
    this->densityCurrentInput_2 = 0.0;
    this->wireIDInput_1 = 0;
    this->wireIDInput_2 = 0;
    this->wireTypeInput_1 = "";
    this->wireTypeInput_2 = "";
    this->wireAWGInput_1 = "";
    this->wireAWGInput_2 = "";
    this->wireDiameterInput_1 = 0.0;
    this->wireDiameterInput_2 = 0.0;
    this->wireAreaInput_1 = 0.0;
    this->wireAreaInput_2 = 0.0;
    this->wireMaterialInput_1 = "";
    this->wireMaterialInput_2 = "";
    this->turnsIN_1 = 0;
    this->turnsIN_2 = 0;

    this->powerOutput = 0.0;
    this->voltageOutput_1 = 0.0;
    this->voltageOutput_2 = 0.0;
    this->currentOutput_1 = 0.0;
    this->currentOutput_2 = 0.0;
    this->densityCurrentOutput_1 = 0.0;
    this->densityCurrentOutput_2 = 0.0;
    this->wireIDOutput_1 = 0;
    this->wireIDOutput_2 = 0;
    this->wireTypeOutput_1 = "";
    this->wireTypeOutput_2 = "";
    this->wireAWGOutput_1 = "";
    this->wireAWGOutput_2 = "";
    this->wireDiameterOutput_1 = 0.0;
    this->wireDiameterOutput_2 = 0.0;
    this->wireAreaOutput_1 = 0.0;
    this->wireAreaOutput_2 = 0.0;
    this->wireMaterialOutput_1 = "";
    this->wireMaterialOutput_2 = "";
    this->turnsOUT_1 = 0;
    this->turnsOUT_2 = 0;

    this->bobbinID = 0;
    this->bobbinType = "";
    this->bobbinCode = "";
    this->bobbinProvider = "";
    this->bobbinWidth = 0.0;
    this->bobbinLength = 0.0;
    this->bobbinHeight = 0.0;
    this->bobbinArea = 0.0;

    this->laminaID = 0;
    this->laminaType = "";
    this->laminaWidth = 0.0;
    this->laminaArea = 0.0;
    this->laminaWeight = 0.0;
    this->laminaCompensation_state = true;
    this->laminaCompensation_value = 0.0;
}

void WindowOpen::clearFields(){
    ui->lineEdit_patternWindingNumber->setText( "" );
    ui->lineEdit_patternWindingName->setText( "" );
    ui->lineEdit_frequency->setText( "" );
    ui->lineEdit_currentDensity->setText( "" );
    ui->checkBox_compensation_power->setChecked( false );
    ui->lineEdit_compensation_power->setText( "" );
    ui->lineEdit_weightTurns->setText( "" );
    ui->lineEdit_turnsLoss->setText( "" );
    ui->lineEdit_averageTurnLength->setText( "" );
    ui->lineEdit_turnsArea->setText( "" );
    ui->lineEdit_magneticInduction->setText( "" );
    ui->lineEdit_densityAverageCurrent->setText( "" );
    ui->lineEdit_windowAreaPerSectionTurns->setText( "" );
    ui->lineEdit_ironWeight->setText( "" );
    ui->lineEdit_ironLoss->setText( "" );
    ui->lineEdit_totalLoss->setText( "" );
    ui->lineEdit_efficiency->setText( "" );
    ui->textEdit_observation->setText( "" );

    ui->lineEdit_powerInput->setText( "" );
    ui->lineEdit_voltageInput_1->setText( "" );
    ui->lineEdit_voltageInput_2->setText( "" );
    ui->lineEdit_currentInput_1->setText( "" );
    ui->lineEdit_currentInput_2->setText( "" );
    ui->lineEdit_densityCurrentInput_1->setText( "" );
    ui->lineEdit_densityCurrentInput_2->setText( "" );
    ui->lineEdit_wireIDInput_1->setText( "" );
    ui->lineEdit_wireIDInput_2->setText( "" );
    ui->lineEdit_wireTypeInput_1->setText( "" );
    ui->lineEdit_wireTypeInput_2->setText( "" );
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
    ui->lineEdit_wireTypeOutput_1->setText( "" );
    ui->lineEdit_wireTypeOutput_2->setText( "" );
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

    ui->lineEdit_bobbinID->setText( "" );
    ui->lineEdit_bobbinType->setText( "" );
    ui->lineEdit_bobbinCode->setText( "" );
    ui->lineEdit_bobbinProvider->setText( "" );
    ui->lineEdit_bobbinWidth->setText( "" );
    ui->lineEdit_bobbinLength->setText( "" );
    ui->lineEdit_bobbinHeight->setText( "" );
    ui->lineEdit_bobbinArea->setText( "" );

    ui->lineEdit_laminaID->setText( "" );
    ui->lineEdit_laminaType->setText( "" );
    ui->lineEdit_laminaWidth->setText( "" );
    ui->lineEdit_laminaArea->setText( "" );
    ui->lineEdit_laminaWeight->setText( "" );
    ui->checkBox_laminaCompensation->setChecked( false );
    ui->lineEdit_laminaCompensation->setText( "" );
}

void WindowOpen::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_frequency->setText( this->database->returnValue( "frequency" ).c_str() );
    ui->lineEdit_magneticInduction->setText( this->database->returnValue( "magneticInduction" ).c_str() );
    ui->lineEdit_currentDensity->setText( this->database->returnValue( "currentDensity" ).c_str() );
    ui->lineEdit_densityAverageCurrent->setText( this->database->returnValue( "averageCurrentDensity" ).c_str() );
    ui->lineEdit_ironWeight->setText( this->database->returnValue( "weigthIron" ).c_str() );
    ui->lineEdit_weightTurns->setText( this->database->returnValue( "weightCopper" ).c_str() );
    ui->lineEdit_averageTurnLength->setText( this->database->returnValue( "turnsAverageLength" ).c_str() );
    ui->lineEdit_turnsArea->setText( this->database->returnValue( "coilArea" ).c_str() );
    ui->lineEdit_windowAreaPerSectionTurns->setText( this->database->returnValue( "windowAreaPerSectionTurns" ).c_str() );
    ui->lineEdit_ironLoss->setText( this->database->returnValue( "ironLoss" ).c_str() );
    ui->lineEdit_turnsLoss->setText( this->database->returnValue( "copperLoss" ).c_str() );
    ui->lineEdit_totalLoss->setText( this->database->returnValue( "totalLoss" ).c_str() );
    ui->lineEdit_efficiency->setText( this->database->returnValue( "efficiency" ).c_str() );
    ui->textEdit_observation->setText( this->database->returnValue( "observation" ).c_str() );

    ui->lineEdit_patternWindingNumber->setText( this->database->returnValue( "patternTransformerNumber" ).c_str() );
    ui->lineEdit_patternWindingName->setText( this->database->returnValue( "patternTransformerName" ).c_str() );
    double valueD = atof( this->database->returnValue( "compensationLossTransformer" ).c_str() );
    if( valueD != 0.0 ){ ui->checkBox_compensation_power->setChecked( true ); }
    else{ ui->checkBox_compensation_power->setChecked( false ); }
    ui->lineEdit_compensation_power->setText( this->database->returnValue( "compensationLossTransformer" ).c_str() );

    ui->lineEdit_powerInput->setText( this->database->returnValue( "powerIN" ).c_str() );

    ui->lineEdit_voltageInput_1->setText( this->database->returnValue( "voltageIN1" ).c_str() );
    ui->lineEdit_voltageInput_2->setText( this->database->returnValue( "voltageIN2" ).c_str() );
    ui->lineEdit_currentInput_1->setText( this->database->returnValue( "currentIN1" ).c_str() );
    ui->lineEdit_currentInput_2->setText( this->database->returnValue( "currentIN2" ).c_str() );
    ui->lineEdit_densityCurrentInput_1->setText( this->database->returnValue( "currentDensityIN1" ).c_str() );
    ui->lineEdit_densityCurrentInput_2->setText( this->database->returnValue( "currentDensityIN2" ).c_str() );
    ui->lineEdit_wireIDInput_1->setText( this->database->returnValue( "wireIDIN1" ).c_str() );
    ui->lineEdit_wireIDInput_2->setText( this->database->returnValue( "wireIDIN2" ).c_str() );
    ui->lineEdit_wireTypeInput_1->setText( this->database->returnValue( "wireTypeIN1" ).c_str() );
    ui->lineEdit_wireTypeInput_2->setText( this->database->returnValue( "wireTypeIN2" ).c_str() );
    ui->lineEdit_wireAWGInput_1->setText( this->database->returnValue( "wireAWGIN1" ).c_str() );
    ui->lineEdit_wireAWGInput_2->setText( this->database->returnValue( "wireAWGIN2" ).c_str() );
    ui->lineEdit_wireDiameterInput_1->setText( this->database->returnValue( "wireDiameterIN1" ).c_str() );
    ui->lineEdit_wireDiameterInput_2->setText( this->database->returnValue( "wireDiameterIN2" ).c_str() );
    ui->lineEdit_wireAreaInput_1->setText( this->database->returnValue( "wireAreaIN1" ).c_str() );
    ui->lineEdit_wireAreaInput_2->setText( this->database->returnValue( "wireAreaIN2" ).c_str() );
    ui->lineEdit_wireMaterialInput_1->setText( this->database->returnValue( "wireMaterialIN1" ).c_str() );
    ui->lineEdit_wireMaterialInput_2->setText( this->database->returnValue( "wireMaterialIN2" ).c_str() );
    ui->lineEdit_turnsIN_1->setText( this->database->returnValue( "wireTurnsIN1" ).c_str() );
    ui->lineEdit_turnsIN_2->setText( this->database->returnValue( "wireTurnsIN2" ).c_str() );

    ui->lineEdit_powerOutput->setText( this->database->returnValue( "powerOUT" ).c_str() );

    ui->lineEdit_voltageOutput_1->setText( this->database->returnValue( "voltageOUT1" ).c_str() );
    ui->lineEdit_voltageOutput_2->setText( this->database->returnValue( "voltageOUT2" ).c_str() );
    ui->lineEdit_currentOutput_1->setText( this->database->returnValue( "currentOUT1" ).c_str() );
    ui->lineEdit_currentOutput_2->setText( this->database->returnValue( "currentOUT2" ).c_str() );
    ui->lineEdit_densityCurrentOutput_1->setText( this->database->returnValue( "currentDensityOUT1" ).c_str() );
    ui->lineEdit_densityCurrentOutput_2->setText( this->database->returnValue( "currentDensityOUT2" ).c_str() );
    ui->lineEdit_wireIDOutput_1->setText( this->database->returnValue( "wireIDOUT1" ).c_str() );
    ui->lineEdit_wireIDOutput_2->setText( this->database->returnValue( "wireIDOUT2" ).c_str() );
    ui->lineEdit_wireTypeOutput_1->setText( this->database->returnValue( "wireTypeOUT1" ).c_str() );
    ui->lineEdit_wireTypeOutput_2->setText( this->database->returnValue( "wireTypeOUT2" ).c_str() );
    ui->lineEdit_wireAWGOutput_1->setText( this->database->returnValue( "wireAWGOUT1" ).c_str() );
    ui->lineEdit_wireAWGOutput_2->setText( this->database->returnValue( "wireAWGOUT2" ).c_str() );
    ui->lineEdit_wireDiameterOutput_1->setText( this->database->returnValue( "wireDiameterOUT1" ).c_str() );
    ui->lineEdit_wireDiameterOutput_2->setText( this->database->returnValue( "wireDiameterOUT2" ).c_str() );
    ui->lineEdit_wireAreaOutput_1->setText( this->database->returnValue( "wireAreaOUT1" ).c_str() );
    ui->lineEdit_wireAreaOutput_2->setText( this->database->returnValue( "wireAreaOUT2" ).c_str() );
    ui->lineEdit_wireMaterialOutput_1->setText( this->database->returnValue( "wireMaterialOUT1" ).c_str() );
    ui->lineEdit_wireMaterialOutput_2->setText( this->database->returnValue( "wireMaterialOUT2" ).c_str() );
    ui->lineEdit_turnsOUT_1->setText( this->database->returnValue( "wireTurnsOUT1" ).c_str() );
    ui->lineEdit_turnsOUT_2->setText( this->database->returnValue( "wireTurnsOUT2" ).c_str() );

    ui->lineEdit_bobbinID->setText( this->database->returnValue( "bobbinID" ).c_str() );
    ui->lineEdit_bobbinType->setText( this->database->returnValue( "bobbinType" ).c_str() );
    ui->lineEdit_bobbinCode->setText( this->database->returnValue( "bobbinCode" ).c_str() );
    ui->lineEdit_bobbinProvider->setText( this->database->returnValue( "bobbinProvider" ).c_str() );
    ui->lineEdit_bobbinWidth->setText( this->database->returnValue( "bobbinWidth" ).c_str() );
    ui->lineEdit_bobbinLength->setText( this->database->returnValue( "bobbinLength" ).c_str() );
    ui->lineEdit_bobbinHeight->setText( this->database->returnValue( "bobbinHeight" ).c_str() );
    ui->lineEdit_bobbinArea->setText( this->database->returnValue( "bobbinArea" ).c_str() );

    ui->lineEdit_laminaID->setText( this->database->returnValue( "laminaID" ).c_str() );
    ui->lineEdit_laminaType->setText( this->database->returnValue( "laminaType" ).c_str() );
    ui->lineEdit_laminaWidth->setText( this->database->returnValue( "laminaWidth" ).c_str() );
    ui->lineEdit_laminaArea->setText( this->database->returnValue( "laminaWindowArea" ).c_str() );
    ui->lineEdit_laminaWeight->setText( this->database->returnValue( "laminaWeight" ).c_str() );
    valueD = atof( this->database->returnValue( "laminaCompensation" ).c_str() );
    if( valueD != 0.0 ){ ui->checkBox_laminaCompensation->setChecked( true ); }
    else{ ui->checkBox_laminaCompensation->setChecked( false ); }
    ui->lineEdit_laminaCompensation->setText( this->database->returnValue( "laminaCompensation" ).c_str() );
}

void WindowOpen::init(){
    this->clearFields();
    if( this->database->executeSQL( "SELECT * FROM transformer ORDER BY id ASC" ) > -1 ){
        this->on_pushButton_next_clicked();
    }
    else{
        QMessageBox msgBox;
        msgBox.setInformativeText( "Erro na consulta." );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowOpen::on_pushButton_previous_clicked(){
    if( this->database->previousRegister() ){
        this->updateFields();
    }
}

void WindowOpen::on_pushButton_next_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
    }
}

void WindowOpen::on_pushButton_update_clicked(){
    //
}

void WindowOpen::on_pushButton_saveAs_clicked(){
    //
}

void WindowOpen::on_pushButton_validate_clicked(){
    //
}

void WindowOpen::on_pushButton_delete_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente excluir o projeto aberto." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        int id = ui->lineEdit_id->text().toInt();
        if( id > 0 ){
            std::string sql = "DELETE FROM transformer WHERE id=" + std::to_string(id);
            if( this->database->executeSQL( sql ) > -1 ){
                this->on_pushButton_next_clicked();
                msgBox.setInformativeText( "Exclusão feita com sucesso." );
                msgBox.setIcon( QMessageBox::Information );
                this->init();
            }
            else{
                msgBox.setInformativeText( "Erro na consulta." );
                msgBox.setIcon( QMessageBox::Warning );
            }
        }
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowOpen::on_pushButton_close_clicked(){
    this->close();
}
