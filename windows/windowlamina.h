#ifndef WINDOWLAMINA_H
#define WINDOWLAMINA_H

#include <QDialog>
#include "components/database.h"
#include "components/lamina.h"

namespace Ui {
class WindowLamina;
}

class WindowLamina : public QDialog
{
    Q_OBJECT

public:
    explicit WindowLamina(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowLamina();
    void setDatabase( DataBase *database );
    void clearFields();
    void updateFields();
    void updateLamina();
    void init();

public slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_before_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_after_clicked();

private:
    Ui::WindowLamina *ui;
    DataBase* database;
    Lamina* lamina;
};

#endif // WINDOWLAMINA_H
