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
    transformer1->setFlux( 11300.0 );
    transformer1->setCurrentDensity( 3.0 );
    transformer1->setStyle( 0 );
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
    transformer2->setFlux( 11300.0 );
    transformer2->setCurrentDensity( 2.5 );
    transformer2->setStyle( 0 );
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
}
