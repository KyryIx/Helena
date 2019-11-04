#include "windows/mainwindow.h"
#include "ui_mainwindow.h"

#include "windows/windownew.h"
#include "windows/windowopen.h"

#include "windows/windowpreference.h"

#include "windows/windowwire.h"
#include "windows/windowlamina.h"
#include "windows/windowbobbin.h"

#include "windows/windowhelp.h"
#include "windows/windowabout.h"

//#include "samples.h"

#include <QFileDialog>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->database = new DataBase();
    //samples( this->database );
}

MainWindow::~MainWindow()
{
    delete ui;
    this->database->clearQuery();
    this->database->closeConnection();
    free( this->database );
}

void MainWindow::on_action_newProject_triggered(){
    WindowNew* dialog = new WindowNew(this, this->database);
    dialog->show();
    dialog->raise();
    dialog->exec();
    //dialog->activateWindow();
}

void MainWindow::on_action_openProject_triggered(){
    WindowOpen* dialog = new WindowOpen(this, this->database);
    dialog->show();
    dialog->raise();
    dialog->exec();
    //dialog->activateWindow();
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
