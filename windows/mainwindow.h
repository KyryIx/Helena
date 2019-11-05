#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "components/database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_action_newProject_triggered();
    void on_action_openProject_triggered();
    void on_action_exit_triggered();

    void on_action_preferences_triggered();

    void on_action_wires_triggered();
    void on_action_laminas_triggered();
    void on_action_bobbins_triggered();

    void on_action_showHelp_triggered();
    void on_action_aboutHelena_triggered();

private:
    Ui::MainWindow *ui;
    DataBase* database;
};

#endif // MAINWINDOW_H
