#include "windownew.h"
#include "ui_windownew.h"

WindowNew::WindowNew(QWidget *parent,  DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowNew)
{
    ui->setupUi(this);
    this->setDatabase( database );
}

WindowNew::~WindowNew()
{
    delete ui;
}

void WindowNew::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowNew::on_pushButton_calculate_clicked(){
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

    Transformer* transformer = new Transformer( this->database );
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
        reportTEXT = transformer->toString();
        reportHTML = transformer->toHTML();
        reportSQL  = transformer->toSQL();
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

        reportSQL  = transformer->toSQL();
    }

    //


/*
GERAIS
				frequência
				indução magnética
				densidade corrente
				padrão das ligações
				compensação de perda no transformador
				valor de acomodação
				densidade de corrente média
				peso do ferro
				peso do enrolamento (cobre ou aluminio)
				comprimento da espira média
				área dos enrolamentos
				perda no ferro
				perda no cobre
				perda total
				eficiência
				
ENTRADA / SAÍDA
				potência de entrada/saída
				tensão de entrada/saída
				corrente de entrada/saída
				densidade de corrente de entrada/saída
				
				id do fio de entrada/saída
				tipo do fio de entrada/saída
				AWG do fio de entrada/saída
				diâmetro do fio de entrada/saída
				area do fio de entrada/saída
				material do fio de entrada/saída
				# espiras do fio de entrada/saída
				# espiras por cm do fio de entrada/saída
				# resistência  do fio de entrada/saída
				# peso do fio de entrada/saída
				# comprimento do fio de entrada/saída
				# frequência do fio de entrada/saída
				
LAMINA
				id da lamina
				tipo da lamina
				largura da lamina
				area da janela da lamina
				peso da lamina
				% da camada:

CARRETEL
				id do carretel
				tipo carretel
				código carretel
				fornecedor do carretel
				largura do carretel
				comprimento do  carretel
				altura do carretel
				area do carretel
				#volume do carretel
*/

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
    //
}

void WindowNew::on_pushButton_close_clicked(){
    this->close();
}
