#ifndef WINDOWWIRE_H
#define WINDOWWIRE_H

#include <QDialog>
#include "components/database.h"

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
    void init();

public slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_before_clicked();
    void on_pushButton_after_clicked();

private:
    Ui::WindowWire *ui;
    DataBase* database;
    std::vector< std::vector<double> > string2Vector( std::string text, char separator );
};

#endif // WINDOWWIRE_H
