#ifndef WINDOWOPENPROJECT_H
#define WINDOWOPENPROJECT_H

#include <QDialog>
#include <QMessageBox>

#include "components/database.h"
#include "components/transformer.h"

namespace Ui {
class WindowOpenProject;
}

class WindowOpenProject : public QDialog
{
    Q_OBJECT

public:
    explicit WindowOpenProject(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowOpenProject();
    void setDatabase( DataBase *database );
    void setTransformer();
    void updateFieldsWithResultQuery();

    void clearFields();


    void init();

public slots:
    void on_pushButton_previous_clicked();
    void on_pushButton_next_clicked();
    void on_pushButton_makeReport_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_saveAs_clicked();
    void on_pushButton_validate_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_close_clicked();

private:
    Ui::WindowOpenProject *ui;
    DataBase* database;
    Transformer* transformer;
};

#endif // WINDOWOPENPROJECT_H
