#ifndef SAMPLES_H
#define SAMPLES_H

//#include "wire.h"
#include "wires.h"

//#include "bobbin.h"
#include "bobbins.h"

//#include "lamina.h"
#include "laminas.h"

#include <QMessageBox>

void samples( DataBase* database ){
    ///////////////////////////////////////////////////
    // Exemplo baseado na                            //
    // Tabela de fios de cobre esmaltados padrão AWG //
    // da Altana Tubes                               //
    //                                               //
    //              Numero AWG: 00                   //
    //           Diâmetro (mm): 9.2659               //
    //          Espiras por cm: 1.079                //
    //             Área (mm^2): 67.432               //
    //      Resistência (Ω/km): 0.255                //
    //            Peso (kg/km): 604.2                //
    //      Comprimento (m/kg): 1.6551               //
    //     Corrente máxima (A):                      //
    //                          2.5A/mm^2 => 168.579 //
    //                          3.0A/mm^2 => 202.295 //
    //                          6.0A/mm^2 => 404.590 //
    // Frequência máxima (kHz): 0.203                //
    ///////////////////////////////////////////////////
    Wire* wire = new Wire();
    wire->setId( 10 );
    wire->setType( "redondo" );
    wire->setAWG( "00" );
    wire->setDiameter( 9.2659 );
    wire->setTurnsPerCm( 1.079 );
    wire->setArea( 67.432 );
    wire->setResistance( 0.255 );
    wire->setWeight( 604.2 );
    wire->setLength( 1.6551 );
    wire->setCurrentMax( {{2.5, 168.579}, {3.0, 202.295}, {6.0, 404.590}} );
    wire->setFrequency( 0.203 );

    unsigned int id                               = wire->getId();
    std::string type                              = wire->getType();
    std::string awg                               = wire->getAWG();
    double diameter                               = wire->getDiameter();
    double turnsPerCm                             = wire->getTurnsPerCm();
    double area                                   = wire->getArea();
    double resistance                             = wire->getResistance();
    double weight                                  = wire->getWeight();
    double length                                 = wire->getLength();
    std::vector< std::vector<double> > currentMax = wire->getCurrentMax();
    double frequency                              = wire->getFrequency();

    std::string report                            = wire->toString();
    QMessageBox msgBox;
    msgBox.setText( report.c_str() );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();

    ///////////////////////////////////////////
    // Exemplo baseado na                    //
    // Página de Prodtos da Dragão Plasticos //
    //                                       //
    //           Código: DR 46               //
    //     Largura (mm): 28.6                //
    // Comprimento (mm): 29.5                //
    //      Altura (mm): 42.9                //
    //             Tipo: STSR                //
    // Temperatura (°C): 140.0               //
    //       Fornecedor: Dragão Plasticos    //
    ///////////////////////////////////////////
    Bobbin* bobbin = new Bobbin();
    bobbin->setId( 1 );
    bobbin->setType( "STSR" );
    bobbin->setWidth( 28.6 );
    bobbin->setLength( 29.5 );
    bobbin->setHeight( 42.9 );

    id            = bobbin->getId();
    type          = bobbin->getType();
    double width  = bobbin->getWidth();
    length        = bobbin->getLength();
    double height = bobbin->getHeight();
    area          = bobbin->getArea();
    double volume = bobbin->getVolume();
    report        = bobbin->toString();

    msgBox.setText( report.c_str() );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();

    /////////////////////////////////////////
    // Exemplo baseado no                  //
    // Livro Transformadores de Martignoni //
    //                                     //
    //         lagura (mm): 25             //
    // area janela (mm*mm): 468            //
    //        peso (kg/cm): 0.273          //
    //                tipo: simples        //
    /////////////////////////////////////////
    Lamina* lamina = new Lamina();
    lamina->setId( 1 );
    lamina->setType( "simples" );
    lamina->setWidth( 25.0 );
    lamina->setWindowArea( 468 );
    lamina->setWeight( 0.273 );

    id                = lamina->getId();
    type              = lamina->getType();
    width             = lamina->getWidth();
    double windowArea = lamina->getWindowArea();
    weight            = lamina->getWeight();
    report            = lamina->toString();

    msgBox.setText( report.c_str() );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();

    //////////////////////////////////////////
    //             search wires             //
    //////////////////////////////////////////
    Wires* wires = new Wires();
    wires->setDatabase( database );

    type       = wires->getType( 2 );
    awg        = wires->getAWG( 2 );
    diameter   = wires->getDiameter( 2 );
    turnsPerCm = wires->getTurnsPerCm( 2 );
    area       = wires->getArea( 2 );
    resistance = wires->getResistance( 2 );
    weight     = wires->getWeight( 2 );
    length     = wires->getLength( 2 );
    frequency  = wires->getFrequency( 2 );
    currentMax = wires->getCurrentMax( 2 );

    id = wires->findIndexByDiameter( 3.5 );
    id = wires->findIndexByTurnsPerCm( 10.0 );
    id = wires->findIndexByArea( 12.5 );
    id = wires->findIndexByResistance( 25.0 );
    id = wires->findIndexByWeight( 45.0 );
    id = wires->findIndexByLength( 50.0 );
    id = wires->findIndexByFrequency( 2.0 );
    id = wires->findIndexByCurrentMax( 20.0 );
    wire = wires->getWire( 2 );

    msgBox.setText( wire->toString().c_str() );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();

    //////////////////////////////////////////
    //            search bobbins            //
    //////////////////////////////////////////
    Bobbins* bobbins = new Bobbins();
    bobbins->setDatabase( database );

    type   = bobbins->getType( 10 );
    width  = bobbins->getWidth( 10 );
    length = bobbins->getLength( 10 );
    height = bobbins->getHeight( 10 );

    id = bobbins->findIndexByWidth( 29.7 );
    id = bobbins->findIndexByWidthAndArea( 29.7, 100.0 );
    id = bobbins->findIndexByLength( 71.0 );
    id = bobbins->findIndexByHeight( 50.4 );
    bobbin = bobbins->getBobbin( 10 );

    msgBox.setText( bobbin->toString().c_str() );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();

    //////////////////////////////////////////
    //            search laminas            //
    //////////////////////////////////////////
    Laminas* laminas = new Laminas();
    laminas->setDatabase( database );

    type       = laminas->getType(2 );
    width      = laminas->getWidth( 2 );
    windowArea = laminas->getWindowArea( 2 );
    weight     = laminas->getWeight( 2 );

    id = laminas->findIndexByWidth( 22.7 );
    id = laminas->findIndexByWindowArea( 714 );
    id = laminas->findIndexByWeight( 1.5 );
    lamina = laminas->getLamina( 2 );

    msgBox.setText( lamina->toString().c_str() );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();

    printf( "id: %d\ndiameter: %f\nturns per cm: %f\narea: %f\nresistance: %f\nweight: %f\nlength: %f\nfrequency: %f\nwidth: %f\nheight: %f\nvolume: %f\nwindow area: %f\n", id, diameter, turnsPerCm, area, resistance, weight, length, frequency, width, height, volume, windowArea );
}

#endif // SAMPLES_H
