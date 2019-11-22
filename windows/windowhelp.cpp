#include "windows/windowhelp.h"
#include "ui_windowhelp.h"

#include <QDir>
#include <stdio.h>
#include <QMessageBox>

WindowHelp::WindowHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowHelp)
{
    ui->setupUi(this);
    std::string path = QDir::currentPath().toStdString() + "/debug/doc/index.html";
    FILE* fp = fopen( path.c_str(), "r" );
    if( fp == nullptr ){
        QMessageBox msgBox;
        std::string information = "Erro na abertura do arquivo.";
        information += path.c_str();
        msgBox.setInformativeText( information.c_str() );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
        return;
    }

    fseek( fp, 0, SEEK_END );
    long int size = ftell( fp );
    fseek( fp, 0, SEEK_SET );
    char* buffer = static_cast<char*>( malloc( static_cast<unsigned long>(size) * sizeof(char) ) );
    if( buffer == nullptr ){
        QMessageBox msgBox;
        msgBox.setInformativeText( "Erro na alocacao de memoria." );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
        return;
    }

    size_t result = fread( buffer, sizeof(char), static_cast<size_t>(size), fp );
    //if( result != static_cast<size_t>(size) ){
    //    QMessageBox msgBox;
    //    msgBox.setInformativeText( "Erro na leitura das informacoes." );
    //    msgBox.setIcon( QMessageBox::Warning );
    //    msgBox.setStandardButtons( QMessageBox::Ok );
    //    msgBox.exec();
    //    return;
    //}

    ui->textBrowser->setHtml( buffer );

    fclose( fp );
    free( buffer );
}

WindowHelp::~WindowHelp()
{
    delete ui;
}
