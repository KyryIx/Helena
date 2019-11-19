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
    void on_pushButton_update_clicked();
    void on_pushButton_saveAs_clicked();
    void on_pushButton_validate_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_close_clicked();

private:
    Ui::WindowOpenProject *ui;
    DataBase* database;
    Transformer* transformer;

    /*
    unsigned int id;
    unsigned int patternWindingNumber;
    std::string patternWindingName;
    double frequency;
    double currentDensity;
    bool compensation_power_state;
    double compensation_power_value;
    double weightTurns;
    double turnsLoss;
    double averageTurnLength;
    double turnsArea;
    double magneticInduction;
    double densityAverageCurrent;
    double windowAreaPerSectionTurns;
    double ironWeight;
    double ironLoss;
    double totalLoss;
    double efficiency;
    std::string observation;

    double powerInput;
    double voltageInput_1;
    double voltageInput_2;
    double currentInput_1;
    double currentInput_2;
    double densityCurrentInput_1;
    double densityCurrentInput_2;
    unsigned int wireIDInput_1;
    unsigned int wireIDInput_2;
    std::string wireTypeInput_1;
    std::string wireTypeInput_2;
    std::string wireAWGInput_1;
    std::string wireAWGInput_2;
    double wireDiameterInput_1;
    double wireDiameterInput_2;
    double wireAreaInput_1;
    double wireAreaInput_2;
    std::string wireMaterialInput_1;
    std::string wireMaterialInput_2;
    unsigned int turnsIN_1;
    unsigned int turnsIN_2;

    double powerOutput;
    double voltageOutput_1;
    double voltageOutput_2;
    double currentOutput_1;
    double currentOutput_2;
    double densityCurrentOutput_1;
    double densityCurrentOutput_2;
    unsigned int wireIDOutput_1;
    unsigned int wireIDOutput_2;
    std::string wireTypeOutput_1;
    std::string wireTypeOutput_2;
    std::string wireAWGOutput_1;
    std::string wireAWGOutput_2;
    double wireDiameterOutput_1;
    double wireDiameterOutput_2;
    double wireAreaOutput_1;
    double wireAreaOutput_2;
    std::string wireMaterialOutput_1;
    std::string wireMaterialOutput_2;
    unsigned int turnsOUT_1;
    unsigned int turnsOUT_2;

    unsigned int bobbinID;
    std::string bobbinType;
    std::string bobbinCode;
    std::string bobbinProvider;
    double bobbinWidth;
    double bobbinLength;
    double bobbinHeight;
    double bobbinArea;

    unsigned int laminaID;
    std::string laminaType;
    double laminaWidth;
    double laminaArea;
    double laminaWeight;
    bool laminaCompensation_state;
    double laminaCompensation_value;
    */
};

#endif // WINDOWOPENPROJECT_H
