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
    void on_pushButton_save_clicked();
    void on_pushButton_close_clicked();

private:
    Ui::WindowNew *ui;
    DataBase* database;
    /*
    double frequency;                // Hz
    double magneticInduction;        // G
    double currentDensity;           // A/mm2
    double meanCurrentDensity;       // A/mm2
    double weigthIron;               // g
    double weightCopper;             // g
    unsigned int turnsAverageLength; // cm
    double coilArea;                 // mm^2
    double ironLoss;                 // W
    double copperLoss;               // W
    double totalLoss;                // W
    double efficiency;               // %

    unsigned int patternTransformer;
    double compensationLossTransformer;
    double compensationLamina;

    double voltageIN;           // V
    double powerIN;             // W
    double currentIN;           // A
    double currentDensityIN;    // A/mm2

    unsigned int wireIDIN;
    std::string wireAWGIN;
    unsigned int wireTurnsIN;   // esp
    double wireDiameterIN;      // mm
    double wireTurnPerCmIN;     // esp/cm
    double wireAreaIN;          // mm2
    double wireResistanceIN;    // ohm/km
    double wireWeightIN;        // kg/km
    double wireLengthIN;        // m/kg
    double wireFrequencyIN;     // kHz

    double voltageOUT;          // V
    double powerOUT;            // W
    double currentOUT;          // A
    double currentDensityOUT;   // A/mm2

    unsigned int wireIDOUT;
    std::string wireAWGOUT;
    unsigned int wireTurnsOUT;  // esp
    double wireDiameterOUT;     // mm
    double wireTurnPerCmOUT;    // esp/cm
    double wireAreaOUT;         // mm2
    double wireResistanceOUT;   // ohm/km
    double wireWeightOUT;       // kg/km
    double wireLengthOUT;       // m/kg
    double wireFrequencyOUT;    // kHz

    unsigned int laminaID;
    std::string laminaType;
    double laminaWidth;         // mm
    double laminaWindowArea;    // mm^2
    double laminaWeight;        // kg/cm

    unsigned int bobbinID;
    std::string bobbinType;
    std::string bobbinCode;
    std::string bobbinProvider;
    double bobbinWidth;         // mm
    double bobbinLength;        // mm
    double bobbinHeight;        // mm
    double bobbinArea;          // mm^2
    double bobbinVolume;        // mm^3
    */
};

#endif // WINDOWNEW_H
