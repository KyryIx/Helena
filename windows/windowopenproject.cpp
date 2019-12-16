#include "windows/windowopenproject.h"
#include "ui_windowopenproject.h"

#define table "transformers"

#include<QFileDialog>
#include<QtPrintSupport/QPrinter>

WindowOpenProject::WindowOpenProject(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowOpenProject)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->transformer = new Transformer( database );
    this->init();
}

WindowOpenProject::~WindowOpenProject()
{
    delete ui;
}

void WindowOpenProject::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowOpenProject::updateFieldsWithResultQuery(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_frequency->setText( this->database->returnValue( "frequency" ).c_str() );
    ui->lineEdit_magneticInduction->setText( this->database->returnValue( "magnetic_induction" ).c_str() );
    ui->lineEdit_currentDensity->setText( this->database->returnValue( "current_density" ).c_str() );
    ui->lineEdit_densityAverageCurrent->setText( this->database->returnValue( "average_current_density" ).c_str() );
    ui->lineEdit_ironWeight->setText( this->database->returnValue( "weight_Iron" ).c_str() );
    ui->lineEdit_weightTurns->setText( this->database->returnValue( "weight_copper" ).c_str() );
    ui->lineEdit_averageTurnLength->setText( this->database->returnValue( "average_turn_length" ).c_str() );
    ui->lineEdit_turnsArea->setText( this->database->returnValue( "copper_area" ).c_str() );
    ui->lineEdit_windowAreaPerSectionTurns->setText( this->database->returnValue( "window_area_per_section_copper" ).c_str() );
    ui->lineEdit_ironLoss->setText( this->database->returnValue( "iron_loss" ).c_str() );
    ui->lineEdit_turnsLoss->setText( this->database->returnValue( "copper_loss" ).c_str() );
    ui->lineEdit_totalLoss->setText( this->database->returnValue( "total_loss" ).c_str() );
    ui->lineEdit_efficiency->setText( this->database->returnValue( "efficiency" ).c_str() );
    ui->textEdit_observation->setText( this->database->returnValue( "observation" ).c_str() );

    ui->lineEdit_patternWindingNumber->setText( this->database->returnValue( "transformer_pattern_number" ).c_str() );
    ui->lineEdit_patternWindingName->setText( this->database->returnValue( "transformer_pattern_name" ).c_str() );

    ui->checkBox_compensation_power->setChecked( atoi(this->database->returnValue( "apply_transformer_loss_compensation" ).c_str())?true:false );
    ui->lineEdit_compensation_power->setText( this->database->returnValue( "transformer_loss_compensation" ).c_str() );

    ui->lineEdit_powerInput->setText( this->database->returnValue( "input_power" ).c_str() );

    ui->lineEdit_voltageInput_1->setText( this->database->returnValue( "input_voltage_1" ).c_str() );
    ui->lineEdit_voltageInput_2->setText( this->database->returnValue( "input_voltage_2" ).c_str() );
    ui->lineEdit_currentInput_1->setText( this->database->returnValue( "input_current_1" ).c_str() );
    ui->lineEdit_currentInput_2->setText( this->database->returnValue( "input_current_2" ).c_str() );
    ui->lineEdit_densityCurrentInput_1->setText( this->database->returnValue( "input_current_density_1" ).c_str() );
    ui->lineEdit_densityCurrentInput_2->setText( this->database->returnValue( "input_current_density_2" ).c_str() );
    ui->lineEdit_wireIDInput_1->setText( this->database->returnValue( "input_wire_id_1" ).c_str() );
    ui->lineEdit_wireIDInput_2->setText( this->database->returnValue( "input_wire_id_2" ).c_str() );
    ui->lineEdit_wireTypeInput_1->setText( this->database->returnValue( "input_wire_type_1" ).c_str() );
    ui->lineEdit_wireTypeInput_2->setText( this->database->returnValue( "input_wire_type_2" ).c_str() );
    ui->lineEdit_wireProviderInput_1->setText( this->database->returnValue( "input_wire_provider_1" ).c_str() );
    ui->lineEdit_wireProviderInput_2->setText( this->database->returnValue( "input_wire_provider_2" ).c_str() );
    ui->lineEdit_wireAWGInput_1->setText( this->database->returnValue( "input_wire_awg_1" ).c_str() );
    ui->lineEdit_wireAWGInput_2->setText( this->database->returnValue( "input_wire_awg_2" ).c_str() );
    ui->lineEdit_wireDiameterInput_1->setText( this->database->returnValue( "input_wire_diameter_1" ).c_str() );
    ui->lineEdit_wireDiameterInput_2->setText( this->database->returnValue( "input_wire_diameter_2" ).c_str() );
    ui->lineEdit_wireAreaInput_1->setText( this->database->returnValue( "input_wire_area_1" ).c_str() );
    ui->lineEdit_wireAreaInput_2->setText( this->database->returnValue( "input_wire_area_2" ).c_str() );
    ui->lineEdit_wireMaterialInput_1->setText( this->database->returnValue( "input_wire_material_1" ).c_str() );
    ui->lineEdit_wireMaterialInput_2->setText( this->database->returnValue( "input_wire_material_2" ).c_str() );
    ui->lineEdit_turnsIN_1->setText( this->database->returnValue( "input_wire_turns_1" ).c_str() );
    ui->lineEdit_turnsIN_2->setText( this->database->returnValue( "input_wire_turns_2" ).c_str() );

    ui->lineEdit_powerOutput->setText( this->database->returnValue( "output_power" ).c_str() );

    ui->lineEdit_voltageOutput_1->setText( this->database->returnValue( "output_voltage_1" ).c_str() );
    ui->lineEdit_voltageOutput_2->setText( this->database->returnValue( "output_voltage_2" ).c_str() );
    ui->lineEdit_currentOutput_1->setText( this->database->returnValue( "output_current_1" ).c_str() );
    ui->lineEdit_currentOutput_2->setText( this->database->returnValue( "output_current_2" ).c_str() );
    ui->lineEdit_densityCurrentOutput_1->setText( this->database->returnValue( "output_current_density_1" ).c_str() );
    ui->lineEdit_densityCurrentOutput_2->setText( this->database->returnValue( "output_current_density_2" ).c_str() );
    ui->lineEdit_wireIDOutput_1->setText( this->database->returnValue( "output_wire_id_1" ).c_str() );
    ui->lineEdit_wireIDOutput_2->setText( this->database->returnValue( "output_wire_id_2" ).c_str() );
    ui->lineEdit_wireTypeOutput_1->setText( this->database->returnValue( "output_wire_type_1" ).c_str() );
    ui->lineEdit_wireTypeOutput_2->setText( this->database->returnValue( "output_wire_type_2" ).c_str() );
    ui->lineEdit_wireProviderOutput_1->setText( this->database->returnValue( "output_wire_provider_1" ).c_str() );
    ui->lineEdit_wireProviderOutput_2->setText( this->database->returnValue( "output_wire_provider_2" ).c_str() );
    ui->lineEdit_wireAWGOutput_1->setText( this->database->returnValue( "output_wire_awg_1" ).c_str() );
    ui->lineEdit_wireAWGOutput_2->setText( this->database->returnValue( "output_wire_awg_2" ).c_str() );
    ui->lineEdit_wireDiameterOutput_1->setText( this->database->returnValue( "output_wire_diameter_1" ).c_str() );
    ui->lineEdit_wireDiameterOutput_2->setText( this->database->returnValue( "output_wire_diameter_2" ).c_str() );
    ui->lineEdit_wireAreaOutput_1->setText( this->database->returnValue( "output_wire_area_1" ).c_str() );
    ui->lineEdit_wireAreaOutput_2->setText( this->database->returnValue( "output_wire_area_2" ).c_str() );
    ui->lineEdit_wireMaterialOutput_1->setText( this->database->returnValue( "output_wire_material_1" ).c_str() );
    ui->lineEdit_wireMaterialOutput_2->setText( this->database->returnValue( "output_wire_material_2" ).c_str() );
    ui->lineEdit_turnsOUT_1->setText( this->database->returnValue( "output_wire_turns_1" ).c_str() );
    ui->lineEdit_turnsOUT_2->setText( this->database->returnValue( "output_wire_turns_2" ).c_str() );

    ui->lineEdit_bobbinID->setText( this->database->returnValue( "bobbin_id" ).c_str() );
    ui->lineEdit_bobbinType->setText( this->database->returnValue( "bobbin_type" ).c_str() );
    ui->lineEdit_bobbinCode->setText( this->database->returnValue( "bobbin_code" ).c_str() );
    ui->lineEdit_bobbinProvider->setText( this->database->returnValue( "bobbin_provider" ).c_str() );
    ui->lineEdit_bobbinWidth->setText( this->database->returnValue( "bobbin_width" ).c_str() );
    ui->lineEdit_bobbinLength->setText( this->database->returnValue( "bobbin_length" ).c_str() );
    ui->lineEdit_bobbinHeight->setText( this->database->returnValue( "bobbin_height" ).c_str() );
    ui->lineEdit_bobbinArea->setText( std::to_string( atof(this->database->returnValue( "bobbin_width" ).c_str()) * atof(this->database->returnValue( "bobbin_length" ).c_str()) ).c_str() );

    ui->lineEdit_laminaID->setText( this->database->returnValue( "lamina_id" ).c_str() );
    ui->lineEdit_laminaType->setText( this->database->returnValue( "lamina_type" ).c_str() );
    ui->lineEdit_laminaProvider->setText( this->database->returnValue( "lamina_provider" ).c_str() );
    ui->lineEdit_laminaWidth->setText( this->database->returnValue( "lamina_width" ).c_str() );
    ui->lineEdit_laminaWindowArea->setText( this->database->returnValue( "lamina_window_area" ).c_str() );
    ui->lineEdit_laminaWeight->setText( this->database->returnValue( "lamina_weight" ).c_str() );

    ui->comboBox_useMode->setCurrentIndex( atoi( this->database->returnValue( "lamina_compensation_state" ).c_str() ) );
    ui->lineEdit_laminaCompensation->setText( this->database->returnValue( "lamina_compensation_value" ).c_str() );
}

void WindowOpenProject::setTransformer(){
    this->transformer->setId( ui->lineEdit_id->text().toUInt() );
    this->transformer->setTransformerPatternNumber( ui->lineEdit_patternWindingNumber->text().toUInt() );
    this->transformer->setTransformerPatternName( ui->lineEdit_patternWindingName->text().toStdString() );
    this->transformer->setFrequency( ui->lineEdit_frequency->text().toDouble() );
    this->transformer->setCurrentDensity( ui->lineEdit_currentDensity->text().toDouble() );
    this->transformer->setApplyTransformerLossCompensation( ui->checkBox_compensation_power->isChecked() );
    this->transformer->setTransformerLossCompensation( ui->lineEdit_compensation_power->text().toDouble() );
    this->transformer->setWeightCopper( ui->lineEdit_weightTurns->text().toDouble() );
    this->transformer->setCopperLoss( ui->lineEdit_turnsLoss->text().toDouble() );
    this->transformer->setAverageTurnLength( ui->lineEdit_averageTurnLength->text().toDouble() );
    this->transformer->setCopperArea( ui->lineEdit_turnsArea->text().toDouble() );
    this->transformer->setMagneticInduction( ui->lineEdit_magneticInduction->text().toDouble() );
    this->transformer->setAverageCurrentDensity( ui->lineEdit_densityAverageCurrent->text().toDouble() );
    this->transformer->setWindowAreaPerSectionCopper( ui->lineEdit_windowAreaPerSectionTurns->text().toDouble() );
    this->transformer->setWeightIron( ui->lineEdit_ironWeight->text().toDouble() );
    this->transformer->setIronLoss( ui->lineEdit_ironLoss->text().toDouble() );
    this->transformer->setTotalLoss( ui->lineEdit_totalLoss->text().toDouble() );
    this->transformer->setEfficiency( ui->lineEdit_efficiency->text().toDouble() );
    this->transformer->setObservation( ui->textEdit_observation->toPlainText().toStdString() );

    this->transformer->setInputPower( ui->lineEdit_powerInput->text().toDouble() );
    this->transformer->setInputVoltage1( ui->lineEdit_voltageInput_1->text().toDouble() );
    this->transformer->setInputVoltage2( ui->lineEdit_voltageInput_2->text().toDouble() );
    this->transformer->setInputCurrent1( ui->lineEdit_currentInput_1->text().toDouble() );
    this->transformer->setInputCurrent2( ui->lineEdit_currentInput_2->text().toDouble() );
    this->transformer->setInputCurrentDensity1( ui->lineEdit_densityCurrentInput_1->text().toDouble() );
    this->transformer->setInputCurrentDensity2( ui->lineEdit_densityCurrentInput_2->text().toDouble() );

    Wire* wireInput1 = new Wire();
    Wire* wireInput2 = new Wire();
    wireInput1->setId( ui->lineEdit_wireIDInput_1->text().toUInt() );
    wireInput2->setId( ui->lineEdit_wireIDInput_2->text().toUInt() );
    wireInput1->setType( ui->lineEdit_wireTypeInput_1->text().toStdString() );
    wireInput2->setType( ui->lineEdit_wireTypeInput_2->text().toStdString() );
    wireInput1->setAWG( ui->lineEdit_wireAWGInput_1->text().toStdString() );
    wireInput2->setAWG( ui->lineEdit_wireAWGInput_2->text().toStdString() );
    wireInput1->setDiameter( ui->lineEdit_wireDiameterInput_1->text().toDouble() );
    wireInput2->setDiameter( ui->lineEdit_wireDiameterInput_2->text().toDouble() );
    wireInput1->setArea( ui->lineEdit_wireAreaInput_1->text().toDouble() );
    wireInput2->setArea( ui->lineEdit_wireAreaInput_2->text().toDouble() );
    wireInput1->setMaterial( ui->lineEdit_wireMaterialInput_1->text().toStdString() );
    wireInput2->setMaterial( ui->lineEdit_wireMaterialInput_2->text().toStdString() );

    this->transformer->setInputWire1( wireInput1 );
    this->transformer->setInputWire2( wireInput2 );
    this->transformer->setInputWireTurns1( ui->lineEdit_turnsIN_1->text().toUInt() );
    this->transformer->setInputWireTurns2( ui->lineEdit_turnsIN_2->text().toUInt() );

    this->transformer->setOutputPower( ui->lineEdit_powerOutput->text().toDouble() );
    this->transformer->setOutputVoltage1( ui->lineEdit_voltageOutput_1->text().toDouble() );
    this->transformer->setOutputVoltage2( ui->lineEdit_voltageOutput_2->text().toDouble() );
    this->transformer->setOutputCurrent1( ui->lineEdit_currentOutput_1->text().toDouble() );
    this->transformer->setOutputCurrent2( ui->lineEdit_currentOutput_2->text().toDouble() );
    this->transformer->setOutputCurrentDensity1( ui->lineEdit_densityCurrentOutput_1->text().toDouble() );
    this->transformer->setOutputCurrentDensity2( ui->lineEdit_densityCurrentOutput_2->text().toDouble() );

    Wire* wireOutput1 = new Wire();
    Wire* wireOutput2 = new Wire();
    wireOutput1->setId( ui->lineEdit_wireIDOutput_1->text().toUInt() );
    wireOutput2->setId( ui->lineEdit_wireIDOutput_2->text().toUInt() );
    wireOutput1->setType( ui->lineEdit_wireTypeOutput_1->text().toStdString() );
    wireOutput2->setType( ui->lineEdit_wireTypeOutput_2->text().toStdString() );
    wireOutput1->setAWG( ui->lineEdit_wireAWGOutput_1->text().toStdString() );
    wireOutput2->setAWG( ui->lineEdit_wireAWGOutput_2->text().toStdString() );
    wireOutput1->setDiameter( ui->lineEdit_wireDiameterOutput_1->text().toDouble() );
    wireOutput2->setDiameter( ui->lineEdit_wireDiameterOutput_2->text().toDouble() );
    wireOutput1->setArea( ui->lineEdit_wireAreaOutput_1->text().toDouble() );
    wireOutput2->setArea( ui->lineEdit_wireAreaOutput_2->text().toDouble() );
    wireOutput1->setMaterial( ui->lineEdit_wireMaterialOutput_1->text().toStdString() );
    wireOutput2->setMaterial( ui->lineEdit_wireMaterialOutput_2->text().toStdString() );

    this->transformer->setOutputWire1( wireOutput1 );
    this->transformer->setOutputWire2( wireOutput2 );
    this->transformer->setOutputWireTurns1( ui->lineEdit_turnsOUT_1->text().toUInt() );
    this->transformer->setOutputWireTurns2( ui->lineEdit_turnsOUT_2->text().toUInt() );

    Bobbin* bobbin = new Bobbin();
    bobbin->setId( ui->lineEdit_bobbinID->text().toUInt() );
    bobbin->setType( ui->lineEdit_bobbinType->text().toStdString() );
    bobbin->setCode( ui->lineEdit_bobbinCode->text().toStdString() );
    bobbin->setProvider( ui->lineEdit_bobbinProvider->text().toStdString() );
    bobbin->setWidth( ui->lineEdit_bobbinWidth->text().toDouble() );
    bobbin->setLength( ui->lineEdit_bobbinLength->text().toDouble() );
    bobbin->setHeight( ui->lineEdit_bobbinHeight->text().toDouble() );

    this->transformer->setBobbin( bobbin );

    Lamina* lamina = new Lamina();
    lamina->setId( ui->lineEdit_laminaID->text().toUInt() );
    lamina->setType( ui->lineEdit_laminaType->text().toStdString() );
    lamina->setWidth( ui->lineEdit_laminaWidth->text().toDouble() );
    lamina->setProvider( ui->lineEdit_laminaProvider->text().toStdString() );
    lamina->setWindowArea( ui->lineEdit_laminaWindowArea->text().toDouble() );
    lamina->setWeight( ui->lineEdit_laminaWeight->text().toDouble() );
    lamina->setCompensationPercent( ui->lineEdit_laminaCompensation->text().toDouble() );

    this->transformer->setLamina( lamina );
    switch( ui->comboBox_useMode->currentIndex() ){
        case 0:
            this->transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::NotApplied );
            break;
        case 1:
            this->transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::LaminaCompensation );
            break;
        case 2:
            this->transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::FieldCompensation );
            break;
    }
}

void WindowOpenProject::clearFields(){
    ui->lineEdit_id->setText( "" );
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
    ui->lineEdit_laminaWindowArea->setText( "" );
    ui->lineEdit_laminaWeight->setText( "" );
    ui->comboBox_useMode->setCurrentIndex( 0 );
    ui->lineEdit_laminaCompensation->setText( "" );
}

void WindowOpenProject::on_pushButton_first_clicked(){
    if( this->database->queryIsActive() ){
        if( this->database->firstRegister() ){
            this->updateFieldsWithResultQuery();
            this->setTransformer();
        }
    }
}

void WindowOpenProject::on_pushButton_last_clicked(){
    if( this->database->queryIsActive() ){
        if( this->database->lastRegister() ){
            this->updateFieldsWithResultQuery();
            this->setTransformer();
        }
    }
}

void WindowOpenProject::on_pushButton_previous_clicked(){
    if( this->database->queryIsActive() ){
        if( this->database->previousRegister() ){
            this->updateFieldsWithResultQuery();
            this->setTransformer();
        }
    }
}

void WindowOpenProject::on_pushButton_next_clicked(){
    if( this->database->queryIsActive() ){
        if( this->database->nextRegister() ){
            this->updateFieldsWithResultQuery();
            this->setTransformer();
        }
    }
}

void WindowOpenProject::on_pushButton_makeReport_clicked(){
    std::string fileName = QFileDialog::getSaveFileName( this, tr("Save Report"), "", tr("Portable Document Format Files (*.pdf)") ).toStdString();

    QMessageBox msgBox;

    if( fileName == "" ){
        msgBox.setInformativeText( "cancelamento do processo" );
        msgBox.setIcon( QMessageBox::Warning );
    }
    else{
        // https://wiki.qt.io/Exporting_a_document_to_PDF //
        QPrinter printer( QPrinter::PrinterResolution );
        printer.setOutputFormat( QPrinter::PdfFormat );
        printer.setPaperSize( QPrinter::A4 );
        printer.setOutputFileName( fileName.c_str() );

        QTextDocument doc;
        doc.setHtml( this->transformer->toHTML().c_str() );
        doc.setPageSize( printer.pageRect().size() ); // This is necessary if you want to hide the page number
        doc.print(&printer);

        msgBox.setInformativeText( "Relatório salvo com sucesso." );
        msgBox.setIcon( QMessageBox::Information );
    }
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
}

void WindowOpenProject::init(){
    this->clearFields();
    std::string sql = "SELECT * FROM ";
    sql += table;
    sql += " ORDER BY id ASC";
    if( this->database->executeSQL( sql ) > -1 ){
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

void WindowOpenProject::on_pushButton_update_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente atualizar o projeto aberto." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        if( this->transformer->getId() == ui->lineEdit_id->text().toUInt() ){
            std::string sql = "UPDATE ";
            sql += table;
            sql += " SET ";
            unsigned char size = static_cast<unsigned char>( sql.size() );

            const double precision = 1e-5;

            if( fabs( this->transformer->getFrequency() - ui->lineEdit_frequency->text().toDouble() ) >= precision ){
                sql += "frequency=" + ui->lineEdit_frequency->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getMagneticInduction() - ui->lineEdit_magneticInduction->text().toDouble() ) >= precision ){
                sql += "magneticInduction=" + ui->lineEdit_magneticInduction->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getCurrentDensity() - ui->lineEdit_currentDensity->text().toDouble() ) >= precision ){
                sql += "current_density=" + ui->lineEdit_currentDensity->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getAverageCurrentDensity() - ui->lineEdit_densityAverageCurrent->text().toDouble() ) >= precision ){
                sql += "average_current_density=" + ui->lineEdit_densityAverageCurrent->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getWeightIron() - ui->lineEdit_ironWeight->text().toDouble() ) >= precision ){
                sql += "weight_iron=" + ui->lineEdit_ironWeight->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getWeightCopper() - ui->lineEdit_weightTurns->text().toDouble() ) >= precision ){
                sql += "weight_copper=" + ui->lineEdit_weightTurns->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getAverageTurnLength() - ui->lineEdit_averageTurnLength->text().toDouble() ) >= precision ){
                sql += "average_turn_length=" + ui->lineEdit_averageTurnLength->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getCopperArea() - ui->lineEdit_turnsArea->text().toDouble() ) >= precision ){
                sql += "copper_area=" + ui->lineEdit_turnsArea->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getWindowAreaPerSectionCopper() - ui->lineEdit_windowAreaPerSectionTurns->text().toDouble() ) >= precision ){
                sql += "window_area_per_section_copper=" + ui->lineEdit_windowAreaPerSectionTurns->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getIronLoss() - ui->lineEdit_ironLoss->text().toDouble() ) >= precision ){
                sql += "iron_loss=" + ui->lineEdit_ironLoss->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getCopperLoss() - ui->lineEdit_turnsLoss->text().toDouble() ) >= precision ){
                sql += "copper_loss=" + ui->lineEdit_turnsLoss->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getTotalLoss() - ui->lineEdit_totalLoss->text().toDouble() ) >= precision ){
                sql += "total_loss=" + ui->lineEdit_totalLoss->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getEfficiency() - ui->lineEdit_efficiency->text().toDouble() ) >= precision ){
                sql += "efficiency=" + ui->lineEdit_efficiency->text().toStdString() + ", ";
            }

            if( this->transformer->getTransformerPatternNumber() != ui->lineEdit_patternWindingNumber->text().toUInt() ){
                sql += "transformer_pattern_number=" + ui->lineEdit_patternWindingNumber->text().toStdString() + ", ";
            }

            if( this->transformer->getTransformerPatternName() != ui->lineEdit_patternWindingName->text().toStdString() ){
                sql += "transformer_pattern_name='" + ui->lineEdit_patternWindingName->text().toStdString() + "', ";
            }

            // center tap //

            if( this->transformer->getApplyTransformerLossCompensation() != ui->checkBox_compensation_power->isChecked() ){
                sql += "apply_transformer_loss_compensation=";
                sql += (ui->checkBox_compensation_power->isChecked() ? "TRUE" : "FALSE");
                sql += ", ";
            }

            if( fabs( this->transformer->getTransformerLossCompensation() - ui->lineEdit_compensation_power->text().toDouble() ) >= precision ){
                sql += "transformer_loss_compensation=" + ui->lineEdit_compensation_power->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputPower() - ui->lineEdit_powerInput->text().toDouble() ) >= precision ){
                sql += "input_power=" + ui->lineEdit_powerInput->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputVoltage1() - ui->lineEdit_voltageInput_1->text().toDouble() ) >= precision ){
                sql += "input_voltage_1=" + ui->lineEdit_voltageInput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputVoltage2() - ui->lineEdit_voltageInput_2->text().toDouble() ) >= precision ){
                sql += "input_voltage_2=" + ui->lineEdit_voltageInput_2->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputCurrent1() - ui->lineEdit_currentInput_1->text().toDouble() ) >= precision ){
                sql += "input_current_1=" + ui->lineEdit_currentInput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputCurrent2() - ui->lineEdit_currentInput_2->text().toDouble() ) >= precision ){
                sql += "input_current_2=" + ui->lineEdit_currentInput_2->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputCurrentDensity1() - ui->lineEdit_densityCurrentInput_1->text().toDouble() ) >= precision ){
                sql += "input_current_density_1=" + ui->lineEdit_densityCurrentInput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputCurrentDensity2() - ui->lineEdit_densityCurrentInput_2->text().toDouble() ) >= precision ){
                sql += "input_current_density_2=" + ui->lineEdit_densityCurrentInput_2->text().toStdString() + ", ";
            }

            if( this->transformer->getInputWire1()->getId() != ui->lineEdit_wireIDInput_1->text().toUInt() ){
                sql += "input_wire_id_1=" + ui->lineEdit_wireIDInput_1->text().toStdString() + ", ";
            }

            if( this->transformer->getInputWire2()->getId() != ui->lineEdit_wireIDInput_2->text().toUInt() ){
                sql += "input_wire_id_2=" + ui->lineEdit_wireIDInput_2->text().toStdString() + ", ";
            }

            if( this->transformer->getInputWire1()->getType() != ui->lineEdit_wireTypeInput_1->text().toStdString() ){
                sql += "input_wire_type_1='" + ui->lineEdit_wireTypeInput_1->text().toStdString() + "', ";
            }

            if( this->transformer->getInputWire2()->getType() != ui->lineEdit_wireTypeInput_2->text().toStdString() ){
                sql += "input_wire_type_2='" + ui->lineEdit_wireTypeInput_2->text().toStdString() + "', ";
            }

            if( this->transformer->getInputWire1()->getAWG() != ui->lineEdit_wireAWGInput_1->text().toStdString() ){
                sql += "input_wire_awg_1='" + ui->lineEdit_wireAWGInput_1->text().toStdString() + "', ";
            }

            if( this->transformer->getInputWire2()->getAWG() != ui->lineEdit_wireAWGInput_2->text().toStdString() ){
                sql += "input_wire_awg_2='" + ui->lineEdit_wireAWGInput_2->text().toStdString() + "', ";
            }

            if( this->transformer->getInputWireTurns1() != ui->lineEdit_turnsIN_1->text().toUInt() ){
                sql += "input_wire_turns_1=" + ui->lineEdit_turnsIN_1->text().toStdString() + ", ";
            }

            if( this->transformer->getInputWireTurns2() != ui->lineEdit_turnsIN_2->text().toUInt() ){
                sql += "input_wire_turns_2=" + ui->lineEdit_turnsIN_2->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputWire1()->getDiameter() - ui->lineEdit_wireDiameterInput_1->text().toDouble() ) >= precision ){
                sql += "input_wire_diameter_1=" + ui->lineEdit_wireDiameterInput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputWire2()->getDiameter() - ui->lineEdit_wireDiameterInput_2->text().toDouble() ) >= precision ){
                sql += "input_wire_diameter_2=" + ui->lineEdit_wireDiameterInput_2->text().toStdString() + ", ";
            }

            // input wire turn per cm 1 and 2 //

            if( fabs( this->transformer->getInputWire1()->getArea() - ui->lineEdit_wireAreaInput_1->text().toDouble() ) >= precision ){
                sql += "input_wire_area_1=" + ui->lineEdit_wireAreaInput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getInputWire2()->getArea() - ui->lineEdit_wireAreaInput_2->text().toDouble() ) >= precision ){
                sql += "input_wire_area_2=" + ui->lineEdit_wireAreaInput_2->text().toStdString() + ", ";
            }

            // input wire resistance 1 and 2 //
            // input wire weight 1 and 2 //
            // input wire length 1 and 2 //
            // input wire frequency 1 and 2 //

            if( this->transformer->getInputWire1()->getMaterial() != ui->lineEdit_wireMaterialInput_1->text().toStdString() ){
                sql += "input_wire_material_1='" + ui->lineEdit_wireMaterialInput_1->text().toStdString() + "', ";
            }

            if( this->transformer->getInputWire2()->getMaterial() != ui->lineEdit_wireMaterialInput_2->text().toStdString() ){
                sql += "input_wire_material_2='" + ui->lineEdit_wireMaterialInput_2->text().toStdString() + "', ";
            }

            // input wire provider 1 and 2 //

            if( fabs( this->transformer->getOutputPower() - ui->lineEdit_powerOutput->text().toDouble() ) >= precision ){
                sql += "output_power=" + ui->lineEdit_powerOutput->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputVoltage1() - ui->lineEdit_voltageOutput_1->text().toDouble() ) >= precision ){
                sql += "output_voltage_1=" + ui->lineEdit_voltageOutput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputVoltage2() - ui->lineEdit_voltageOutput_2->text().toDouble() ) >= precision ){
                sql += "output_voltage_2=" + ui->lineEdit_voltageOutput_2->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputCurrent1() - ui->lineEdit_currentOutput_1->text().toDouble() ) >= precision ){
                sql += "output_current_1=" + ui->lineEdit_currentOutput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputCurrent2() - ui->lineEdit_currentOutput_2->text().toDouble() ) >= precision ){
                sql += "output_current_2=" + ui->lineEdit_currentOutput_2->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputCurrentDensity1() - ui->lineEdit_densityCurrentOutput_1->text().toDouble() ) >= precision ){
                sql += "output_current_density_1=" + ui->lineEdit_densityCurrentOutput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputCurrentDensity2() - ui->lineEdit_densityCurrentOutput_2->text().toDouble() ) >= precision ){
                sql += "output_current_density_2=" + ui->lineEdit_densityCurrentOutput_2->text().toStdString() + ", ";
            }

            if( this->transformer->getOutputWire1()->getId() != ui->lineEdit_wireIDOutput_1->text().toUInt() ){
                sql += "output_wire_id_1=" + ui->lineEdit_wireIDOutput_1->text().toStdString() + ", ";
            }

            if( this->transformer->getOutputWire2()->getId() != ui->lineEdit_wireIDOutput_2->text().toUInt() ){
                sql += "output_wire_id_2=" + ui->lineEdit_wireIDOutput_2->text().toStdString() + ", ";
            }

            if( this->transformer->getOutputWire1()->getType() != ui->lineEdit_wireTypeOutput_1->text().toStdString() ){
                sql += "output_wire_type_1='" + ui->lineEdit_wireTypeOutput_1->text().toStdString() + "', ";
            }

            if( this->transformer->getOutputWire2()->getType() != ui->lineEdit_wireTypeOutput_2->text().toStdString() ){
                sql += "output_wire_type_2='" + ui->lineEdit_wireTypeOutput_2->text().toStdString() + "', ";
            }

            if( this->transformer->getOutputWire1()->getAWG() != ui->lineEdit_wireAWGOutput_1->text().toStdString() ){
                sql += "output_wire_awg_1='" + ui->lineEdit_wireAWGOutput_1->text().toStdString() + "', " ;
            }

            if( this->transformer->getOutputWire2()->getAWG() != ui->lineEdit_wireAWGOutput_2->text().toStdString() ){
                sql += "output_wire_awg_2='" + ui->lineEdit_wireAWGOutput_2->text().toStdString() + "', " ;
            }

            if( this->transformer->getOutputWireTurns1() != ui->lineEdit_turnsOUT_1->text().toUInt() ){
                sql += "output_wire_turns_1=" + ui->lineEdit_turnsOUT_1->text().toStdString() + ", ";
            }

            if( this->transformer->getOutputWireTurns2() != ui->lineEdit_turnsOUT_2->text().toUInt() ){
                sql += "output_wire_turns_2=" + ui->lineEdit_turnsOUT_2->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputWire1()->getDiameter() - ui->lineEdit_wireDiameterOutput_1->text().toDouble() ) >= precision ){
                sql += "output_wire_diameter_1=" + ui->lineEdit_wireDiameterOutput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputWire2()->getDiameter() - ui->lineEdit_wireDiameterOutput_2->text().toDouble() ) >= precision ){
                sql += "output_wire_diameter_2=" + ui->lineEdit_wireDiameterOutput_2->text().toStdString() + ", ";
            }

            // output wire turn per cm 1 and 2 //

            if( fabs( this->transformer->getOutputWire1()->getArea() - ui->lineEdit_wireAreaOutput_1->text().toDouble() ) >= precision ){
                sql += "output_wire_area_1=" + ui->lineEdit_wireAreaOutput_1->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getOutputWire2()->getArea() - ui->lineEdit_wireAreaOutput_2->text().toDouble() ) >= precision ){
                sql += "output_wire_area_2=" + ui->lineEdit_wireAreaOutput_2->text().toStdString() + ", ";
            }

            // output wire resistance 1 and 2 //
            // output wire weight 1 and 2 //
            // output wire length 1 and 2 //
            // output wire frequency 1 and 2 //

            if( this->transformer->getOutputWire1()->getMaterial() != ui->lineEdit_wireMaterialOutput_1->text().toStdString() ){
                sql += "output_wire_material_1='" + ui->lineEdit_wireMaterialOutput_1->text().toStdString() + "', ";
            }

            if( this->transformer->getOutputWire2()->getMaterial() != ui->lineEdit_wireMaterialOutput_2->text().toStdString() ){
                sql += "output_wire_material_2='" + ui->lineEdit_wireMaterialOutput_2->text().toStdString() + "', ";
            }

            // output wire provider 1 and 2 //

            if( this->transformer->getLamina()->getId() != ui->lineEdit_laminaID->text().toUInt() ){
                sql += "lamina_id=" + ui->lineEdit_laminaID->text().toStdString() + ", ";
            }

            if( this->transformer->getLamina()->getType() != ui->lineEdit_laminaType->text().toStdString() ){
                sql += "lamina_type='" + ui->lineEdit_laminaType->text().toStdString() + "', ";
            }

            // lamina provider //

            if( fabs( this->transformer->getLamina()->getWidth() - ui->lineEdit_laminaWidth->text().toDouble() ) >= precision ){
                sql += "lamina_width=" + ui->lineEdit_laminaWidth->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getLamina()->getWindowArea() - ui->lineEdit_laminaWindowArea->text().toDouble() ) >= precision ){
                sql += "lamina_window_area=" + ui->lineEdit_laminaWindowArea->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getLamina()->getWeight() - ui->lineEdit_laminaWeight->text().toDouble() ) >= precision ){
                sql += "lamina_weight=" + ui->lineEdit_laminaWeight->text().toStdString() + ", ";
            }

            if( this->transformer->getMethodLaminaLossCompensation() != ui->comboBox_useMode->currentIndex() ){
                sql += "lamina_compensation_state=";
                sql += std::to_string( ui->comboBox_useMode->currentIndex() ).c_str();
                sql += ", ";
            }

            if( fabs( this->transformer->getLamina()->getCompensationPercent() - ui->lineEdit_laminaCompensation->text().toDouble() ) >= precision ){
                sql += "lamina_compensation_value=" + ui->lineEdit_laminaCompensation->text().toStdString() + ", ";
            }

            if( this->transformer->getBobbin()->getId() != ui->lineEdit_bobbinID->text().toUInt() ){
                sql += "bobbin_id=" + ui->lineEdit_bobbinID->text().toStdString() + ", ";
            }

            if( this->transformer->getBobbin()->getType() != ui->lineEdit_bobbinType->text().toStdString() ){
                sql += "bobbin_type='" + ui->lineEdit_bobbinType->text().toStdString() + "', ";
            }

            if( this->transformer->getBobbin()->getCode() != ui->lineEdit_bobbinCode->text().toStdString() ){
                sql += "bobbin_code='" + ui->lineEdit_bobbinCode->text().toStdString() + "', ";
            }

            if( this->transformer->getBobbin()->getProvider() != ui->lineEdit_bobbinProvider->text().toStdString() ){
                sql += "bobbin_provider='" + ui->lineEdit_bobbinProvider->text().toStdString() + "', ";
            }

            if( fabs( this->transformer->getBobbin()->getWidth() - ui->lineEdit_bobbinWidth->text().toDouble() ) >= precision ){
                sql += "bobbin_width=" + ui->lineEdit_bobbinWidth->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getBobbin()->getLength() - ui->lineEdit_bobbinLength->text().toDouble() ) >= precision ){
                sql += "bobbin_length=" + ui->lineEdit_bobbinLength->text().toStdString() + ", ";
            }

            if( fabs( this->transformer->getBobbin()->getHeight() - ui->lineEdit_bobbinHeight->text().toDouble() ) >= precision ){
                sql += "bobbin_height=" + ui->lineEdit_bobbinHeight->text().toStdString() + ", ";
            }

            if( this->transformer->getObservation() != ui->textEdit_observation->toPlainText().toStdString() ){
                sql += "observation='" + ui->textEdit_observation->toPlainText().toStdString() + "', ";
            }

            if( sql.size() > size ){
                sql = sql.substr( 0, sql.size()-2 );
                sql += " WHERE id=" + std::to_string( this->transformer->getId() );

                if( this->database->executeSQL( sql ) > -1 ){
                    this->on_pushButton_next_clicked();
                    msgBox.setInformativeText( "Atualização feita com sucesso." );
                    msgBox.setIcon( QMessageBox::Information );
                    this->init();
                }
                else{
                    msgBox.setInformativeText( "Erro na consulta." );
                    msgBox.setIcon( QMessageBox::Warning );
                }
            }
            else{
                msgBox.setInformativeText( "Os valores nos campos são idênticos aos armazenados na base de dados." );
                msgBox.setIcon( QMessageBox::Warning );
            }
        }
        else{
            msgBox.setInformativeText( "Erro na criação da atualização. Não é permitido a modificação de ID de projeto." );
            msgBox.setIcon( QMessageBox::Warning );
        }

        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowOpenProject::on_pushButton_saveAs_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente salvar o projeto aberto com outro ID." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        Transformer* transformer = new Transformer(this->database);
        transformer->setFrequency( ui->lineEdit_frequency->text().toDouble() );
        transformer->setMagneticInduction( ui->lineEdit_magneticInduction->text().toDouble() );
        transformer->setCurrentDensity( ui->lineEdit_currentDensity->text().toDouble() );
        transformer->setAverageCurrentDensity( ui->lineEdit_densityAverageCurrent->text().toDouble() );
        transformer->setWeightIron( ui->lineEdit_ironWeight->text().toDouble() );
        transformer->setWeightCopper( ui->lineEdit_weightTurns->text().toDouble() );
        transformer->setAverageTurnLength( ui->lineEdit_averageTurnLength->text().toDouble() );
        transformer->setCopperArea( ui->lineEdit_turnsArea->text().toDouble() );
        transformer->setWindowAreaPerSectionCopper( ui->lineEdit_windowAreaPerSectionTurns->text().toDouble() );
        transformer->setIronLoss( ui->lineEdit_ironLoss->text().toDouble() );
        transformer->setCopperLoss( ui->lineEdit_turnsLoss->text().toDouble() );
        transformer->setTotalLoss( ui->lineEdit_totalLoss->text().toDouble() );
        transformer->setEfficiency( ui->lineEdit_efficiency->text().toDouble() );

        transformer->setTransformerPatternNumber( ui->lineEdit_patternWindingNumber->text().toUInt() );
        transformer->setTransformerPatternName( ui->lineEdit_patternWindingName->text().toStdString() );
        // apply center tap //
        transformer->setApplyTransformerLossCompensation( ui->checkBox_compensation_power->isChecked() );
        transformer->setTransformerLossCompensation( ui->lineEdit_compensation_power->text().toDouble() );

        transformer->setInputPower( ui->lineEdit_powerInput->text().toDouble() );
        transformer->setInputVoltage1( ui->lineEdit_voltageInput_1->text().toDouble() );
        transformer->setInputVoltage2( ui->lineEdit_voltageInput_2->text().toDouble() );
        transformer->setInputCurrent1( ui->lineEdit_currentInput_1->text().toDouble() );
        transformer->setInputCurrent2( ui->lineEdit_currentInput_2->text().toDouble() );
        transformer->setInputCurrentDensity1( ui->lineEdit_densityCurrentInput_1->text().toDouble() );
        transformer->setInputCurrentDensity2( ui->lineEdit_densityCurrentInput_2->text().toDouble() );

        Wire* inputWire1 = new Wire();
        Wire* inputWire2 = new Wire();

        inputWire1->setId( ui->lineEdit_wireIDInput_1->text().toUInt() );
        inputWire2->setId( ui->lineEdit_wireIDInput_2->text().toUInt() );
        inputWire1->setType( ui->lineEdit_wireTypeInput_1->text().toStdString() );
        inputWire2->setType( ui->lineEdit_wireTypeInput_2->text().toStdString() );
        inputWire1->setAWG( ui->lineEdit_wireAWGInput_1->text().toStdString() );
        inputWire2->setAWG( ui->lineEdit_wireAWGInput_2->text().toStdString() );
        inputWire1->setDiameter( ui->lineEdit_wireDiameterInput_1->text().toDouble() );
        inputWire2->setDiameter( ui->lineEdit_wireDiameterInput_2->text().toDouble() );
        // input wire turn per cm 1 and 2 //
        inputWire1->setArea( ui->lineEdit_wireAreaInput_1->text().toDouble() );
        inputWire2->setArea( ui->lineEdit_wireAreaInput_2->text().toDouble() );
        // input wire resistance 1 and 2 //
        // input wire weight 1 and 2 //
        // input wire length 1 and 2 //
        // input wire frequency 1 and 2 //
        inputWire1->setMaterial( ui->lineEdit_wireMaterialInput_1->text().toStdString() );
        inputWire2->setMaterial( ui->lineEdit_wireMaterialInput_2->text().toStdString() );
        inputWire1->setProvider( ui->lineEdit_wireProviderInput_1->text().toStdString() );
        inputWire2->setProvider( ui->lineEdit_wireProviderInput_2->text().toStdString() );
        transformer->setInputWireTurns1( ui->lineEdit_turnsIN_1->text().toUInt() );
        transformer->setInputWireTurns1( ui->lineEdit_turnsIN_2->text().toUInt() );
        transformer->setInputWire1( inputWire1 );
        transformer->setInputWire2( inputWire2 );

        transformer->setOutputPower( ui->lineEdit_powerOutput->text().toDouble() );
        transformer->setOutputVoltage1( ui->lineEdit_voltageOutput_1->text().toDouble() );
        transformer->setOutputVoltage2( ui->lineEdit_voltageOutput_2->text().toDouble() );
        transformer->setOutputCurrent1( ui->lineEdit_currentOutput_1->text().toDouble() );
        transformer->setOutputCurrent2( ui->lineEdit_currentOutput_2->text().toDouble() );
        transformer->setOutputCurrentDensity1( ui->lineEdit_densityCurrentOutput_1->text().toDouble() );
        transformer->setOutputCurrentDensity2( ui->lineEdit_densityCurrentOutput_2->text().toDouble() );

        Wire* outputWire1 = new Wire();
        Wire* outputWire2 = new Wire();

        outputWire1->setId( ui->lineEdit_wireIDOutput_1->text().toUInt() );
        outputWire2->setId( ui->lineEdit_wireIDOutput_2->text().toUInt() );
        outputWire1->setType( ui->lineEdit_wireTypeOutput_1->text().toStdString() );
        outputWire2->setType( ui->lineEdit_wireTypeOutput_2->text().toStdString() );
        outputWire1->setAWG( ui->lineEdit_wireAWGOutput_1->text().toStdString() );
        outputWire2->setAWG( ui->lineEdit_wireAWGOutput_2->text().toStdString() );
        outputWire1->setDiameter( ui->lineEdit_wireDiameterOutput_1->text().toDouble() );
        outputWire2->setDiameter( ui->lineEdit_wireDiameterOutput_2->text().toDouble() );
        // output wire turn per cm 1 and 2 //
        outputWire1->setArea( ui->lineEdit_wireAreaOutput_1->text().toDouble() );
        outputWire2->setArea( ui->lineEdit_wireAreaOutput_2->text().toDouble() );
        // output wire resistance 1 and 2 //
        // output wire weight 1 and 2 //
        // output wire length 1 and 2 //
        // output wire frequency 1 and 2 //
        outputWire1->setMaterial( ui->lineEdit_wireMaterialOutput_1->text().toStdString() );
        outputWire2->setMaterial( ui->lineEdit_wireMaterialOutput_2->text().toStdString() );
        outputWire1->setProvider( ui->lineEdit_wireProviderOutput_1->text().toStdString() );
        outputWire2->setProvider( ui->lineEdit_wireProviderOutput_2->text().toStdString() );
        transformer->setOutputWireTurns1( ui->lineEdit_turnsOUT_1->text().toUInt() );
        transformer->setOutputWireTurns2( ui->lineEdit_turnsOUT_2->text().toUInt() );

        Lamina* lamina = new Lamina();

        lamina->setId( ui->lineEdit_laminaID->text().toUInt() );
        lamina->setType( ui->lineEdit_laminaType->text().toStdString() );
        lamina->setProvider(ui->lineEdit_laminaProvider->text().toStdString() );
        lamina->setWidth( ui->lineEdit_laminaWidth->text().toDouble() );
        lamina->setWindowArea( ui->lineEdit_laminaWindowArea->text().toDouble() );
        lamina->setWeight( ui->lineEdit_laminaWeight->text().toDouble() );
        lamina->setCompensationPercent( ui->lineEdit_laminaCompensation->text().toDouble() );
        switch( ui->comboBox_useMode->currentIndex() ) {
            case MethodLaminaCompensation::NotApplied:
                transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::NotApplied );
                break;

            case MethodLaminaCompensation::FieldCompensation:
                transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::FieldCompensation );
                break;

            case MethodLaminaCompensation::LaminaCompensation:
                transformer->setMethodLaminaLossCompensation( MethodLaminaCompensation::LaminaCompensation );
                break;
        }
        transformer->setLaminaLossCompensation( ui->lineEdit_laminaCompensation->text().toDouble() );
        transformer->setLamina( lamina );

        Bobbin* bobbin = new Bobbin();

        bobbin->setId( ui->lineEdit_bobbinID->text().toUInt() );
        bobbin->setType( ui->lineEdit_bobbinType->text().toStdString() );
        bobbin->setCode( ui->lineEdit_bobbinCode->text().toStdString() );
        bobbin->setProvider( ui->lineEdit_bobbinProvider->text().toStdString() );
        bobbin->setWidth( ui->lineEdit_bobbinWidth->text().toDouble() );
        bobbin->setLength( ui->lineEdit_bobbinLength->text().toDouble() );
        bobbin->setHeight( ui->lineEdit_bobbinHeight->text().toDouble() );
        transformer->setBobbin( bobbin );

        transformer->setObservation( ui->textEdit_observation->toPlainText().toStdString() );

        if( this->database->executeSQL( transformer->toSQL() ) > -1 ){
            this->on_pushButton_next_clicked();
            msgBox.setInformativeText( "Salvamento feito com sucesso." );
            msgBox.setIcon( QMessageBox::Information );
            this->init();
        }
        else{
            msgBox.setInformativeText( "Erro no salvamento." );
            msgBox.setIcon( QMessageBox::Warning );
        }

        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowOpenProject::on_pushButton_validate_clicked(){
    // To Do //
}

void WindowOpenProject::on_pushButton_delete_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente excluir o projeto aberto?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        int id = ui->lineEdit_id->text().toInt();
        if( id > 0 ){
            std::string sql = "DELETE FROM ";
            sql += table;
            sql += " WHERE id=" + std::to_string(id);
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

void WindowOpenProject::on_pushButton_close_clicked(){
    this->close();
}
