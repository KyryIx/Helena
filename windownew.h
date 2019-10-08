#ifndef WINDOWNEW_H
#define WINDOWNEW_H

#include <QDialog>
#include "database.h"
#include "transformer.h"

namespace Ui {
class WindowNew;
}

class WindowNew : public QDialog
{
    Q_OBJECT

public:
    explicit WindowNew(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowNew();
    void setDatabase( DataBase *database );

public slots:
    void on_pushButton_calculate_clicked();

private:
    Ui::WindowNew *ui;
    DataBase* database;
};

#endif // WINDOWNEW_H
