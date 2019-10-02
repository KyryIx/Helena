#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "windownew.h"

#include "windowpreference.h"

#include "windowwire.h"
#include "windowlamina.h"
#include "windowbobbin.h"

#include "windowhelp.h"
#include "windowabout.h"

#include "samples.h"

#include <QFileDialog>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->database = new DataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
    this->database->clearQuery();
    this->database->closeConnection();
    free( this->database );
}

void MainWindow::on_action_newProject_triggered(){
    WindowNew* dialog = new WindowNew(this);
    dialog->show();
    dialog->raise();
    dialog->exec();
    //dialog->activateWindow();
}

void MainWindow::on_action_openProject_triggered(){
    QFileDialog* file = new QFileDialog();
    file->open();
    QString endereco = file->getOpenFileName();
    // QtGui.QFileDialog.getSaveFileName(None,"Salvar Projeto Helena", '', "Helena Projeto (*.hp);;XML files (*.xml);;All Files (*)")
}

void MainWindow::on_action_saveProject_triggered(){
    QFileDialog* file = new QFileDialog();
    file->getSaveFileName(nullptr, "Salvar Projeto Helena", "", "Helena Projeto (*.hp);;XML files (*.xml);;All Files (*)");
}

void MainWindow::on_action_closeProject_triggered(){
    sample_wire();
    sample_wires( this->database );
    sample_bobbin();
    sample_bobbins( this->database ); // rever as funcoes de bobbins que os resultados nao batem //
    sample_lamina();
    sample_laminas( this->database ); // rever as funcoes de laminas que os resultados nao batem //
}

void MainWindow::on_action_exit_triggered(){
    this->close();
}

void MainWindow::on_action_preferences_triggered(){
    WindowPreference* dialog = new WindowPreference(this);
    dialog->show();
    dialog->raise();
    dialog->exec();
}

void MainWindow::on_action_wires_triggered(){
    WindowWire* dialog = new WindowWire(this, this->database);
    dialog->show();
    dialog->raise();
    dialog->exec();
}

void MainWindow::on_action_laminas_triggered(){
    WindowLamina* dialog = new WindowLamina(this, this->database);
    dialog->show();
    dialog->raise();
    dialog->exec();
}

void MainWindow::on_action_bobbins_triggered(){
    WindowBobbin* dialog = new WindowBobbin(this, this->database);
    dialog->show();
    dialog->raise();
    dialog->exec();
}

void MainWindow::on_action_showHelp_triggered(){
    WindowHelp* dialog = new WindowHelp(this);
    dialog->show();
    dialog->raise();
    dialog->exec();
}

void MainWindow::on_action_aboutHelena_triggered(){
    WindowAbout* dialog = new WindowAbout(this);
    dialog->show();
    dialog->raise();
    dialog->exec();
}


