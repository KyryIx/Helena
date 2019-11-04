#ifndef WINDOWOPEN_H
#define WINDOWOPEN_H

#include <QDialog>
#include <QMessageBox>

#include "components/database.h"

namespace Ui {
class WindowOpen;
}

class WindowOpen : public QDialog
{
    Q_OBJECT

public:
    explicit WindowOpen(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowOpen();
    void setDatabase( DataBase *database );
    void clearFields();
    void updateFields();
    void init();

public slots:
    void on_pushButton_previous_clicked();
    void on_pushButton_next_clicked();
    void on_pushButton_edit_clicked();
    void on_pushButton_saveAs_clicked();
    void on_pushButton_validate_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_close_clicked();

private:
    Ui::WindowOpen *ui;
    DataBase* database;
};

#endif // WINDOWOPEN_H
