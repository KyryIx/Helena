#ifndef WINDOWBOBBIN_H
#define WINDOWBOBBIN_H

#include <QDialog>
#include <math.h>
#include "components/database.h"
#include "components/bobbin.h"

namespace Ui {
class WindowBobbin;
}

class WindowBobbin : public QDialog
{
    Q_OBJECT

public:
    explicit WindowBobbin(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowBobbin();
    void setDatabase( DataBase *database );
    void clearFields();
    void updateFields();
    void updateBobbin();
    void init();

public slots:
    void on_pushButton_first_clicked();
    void on_pushButton_last_clicked();
    void on_pushButton_before_clicked();
    void on_pushButton_after_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_insert_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::WindowBobbin *ui;
    DataBase* database;
    Bobbin* bobbin;
    void setStateInsert( unsigned char state );
    unsigned char stateInsert;
};

#endif // WINDOWBOBBIN_H
