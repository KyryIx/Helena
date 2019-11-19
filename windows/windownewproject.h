#ifndef WINDOWNEWPROJECT_H
#define WINDOWNEWPROJECT_H

#include <QDialog>
#include <QMessageBox>

#include "components/database.h"
#include "components/transformer.h"

namespace Ui {
class WindowNewProject;
}

class WindowNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit WindowNewProject(QWidget *parent = nullptr,  DataBase* database=nullptr);
    ~WindowNewProject();
    void setDatabase( DataBase *database );

public slots:
    void on_lineEdit_patternWindingNumber_textChanged( const QString &text );
    void on_comboBox_patternWindingName_currentIndexChanged( int index );
    void on_lineEdit_voltageInput_1_textChanged( const QString &text );
    void on_lineEdit_voltageOutput_1_textChanged( const QString &text );

    void on_pushButton_calculate_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_close_clicked();

private:
    Ui::WindowNewProject *ui;
    DataBase* database;
    Transformer* transformer;

    void clearFields();
    void setTransformer();
    void updateTransformer();
    void writeInput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns );
    void writeInput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns );
    void writeOutput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns );
    void writeOutput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, const char*provider, double diameter, double area, const char* material, unsigned int turns );
    void enableInput2( bool state );
    void enableOutput2( bool state );
};

#endif // WINDOWNEWPROJECT_H
