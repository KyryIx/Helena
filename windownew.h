#ifndef WINDOWNEW_H
#define WINDOWNEW_H

#include <QDialog>
#include <QMessageBox>

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
    void on_pushButton_save_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_close_clicked();
    void on_comboBox_patternWinding_currentIndexChanged(int index);
    void on_lineEdit_voltageInput_1_textChanged( const QString &text );
    void on_lineEdit_voltageOutput_1_textChanged( const QString &text );

private:
    Ui::WindowNew *ui;
    DataBase* database;
    Transformer* transformer;

    void clearFields();
    void setTransformer();
    void updateTransformer();
    void writeInput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns );
    void writeInput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns );
    void writeOutput1( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns );
    void writeOutput2( double voltage, double current, double densityCurrent, unsigned int id, unsigned type, const char* awg, double diameter, double area, const char* material, unsigned int turns );
    void enableInput2( bool state );
    void enableOutput2( bool state );
};

#endif // WINDOWNEW_H
