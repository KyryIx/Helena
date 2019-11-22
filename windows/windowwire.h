#ifndef WINDOWWIRE_H
#define WINDOWWIRE_H

#include <QDialog>
#include "components/database.h"
#include "components/wire.h"

namespace Ui {
class WindowWire;
}

class WindowWire : public QDialog
{
    Q_OBJECT

public:
    explicit WindowWire(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowWire();
    void setDatabase( DataBase *database );
    void clearFields();
    void updateFields();
    void updateWire();
    void init();

public slots:
    void on_pushButton_before_clicked();
    void on_pushButton_after_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_insert_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::WindowWire *ui;
    DataBase* database;
    Wire* wire;
    std::vector< std::vector<double> > string2Vector( std::string text, char separator );
    void setStateInsert( unsigned char state );
    unsigned char stateInsert;
};

#endif // WINDOWWIRE_H
