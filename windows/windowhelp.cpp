#include "windows/windowhelp.h"
#include "ui_windowhelp.h"

#include <QDir>
#include <stdio.h>
#include <QMessageBox>
#include <stdlib.h>
#include <stdio.h>

WindowHelp::WindowHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowHelp)
{
    ui->setupUi(this);
    std::string path = QDir::currentPath().toStdString() + "/debug/doc/index.html";
    //FILE* fp = fopen( path.c_str(), "r,ccs=UTF-8" ); // c++11
    FILE* fp = fopen( path.c_str(), "r" ); // have ansi
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
    long size = ftell( fp );
    fseek( fp, 0, SEEK_SET );

    char* buffer = static_cast<char*>( malloc( static_cast<size_t>(size) * sizeof(char) ) );
    if( buffer == nullptr ){
        QMessageBox msgBox;
        msgBox.setInformativeText( "Erro na alocacao de memoria." );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
        fclose( fp );
        free( buffer );
        return;
    }

    size_t result = fread( buffer, sizeof(char), static_cast<size_t>(size), fp );
    //if( static_cast<long>(result) != size ){
    if( result == 0 ){
        QMessageBox msgBox;
        std::string str = "Erro na leitura das informacoes.";
        msgBox.setInformativeText( str.c_str() );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
        fclose( fp );
        free( buffer );
        return;
    }

    std::string html( buffer );
    std::string str( "src=\"./" );

    std::size_t found = html.find( str );
    std::string replace = "";
    while( found != std::string::npos ){
        replace = "src=\"";
        replace += QDir::currentPath().toStdString();
        replace += "/debug/doc/";
        html.replace( found, 7, replace );
        found = html.find( str, found );
    }

    std::string path2 = path + ".html";
    FILE* fp2 = fopen( path2.c_str(), "w" );
    fwrite( html.c_str(), 1, static_cast<size_t>(html.size()), fp2 );
    fclose(fp2);

    //ui->textBrowser->setHtml( buffer );
    ui->textBrowser->setHtml( html.c_str() );

    fclose( fp );
    free( buffer );
}

WindowHelp::~WindowHelp()
{
    delete ui;
}
