#include "windowlaminaimage.h"
#include "ui_windowlaminaimage.h"

// https://en.wikipedia.org/wiki/Pi
#define pi 3.1415926535

WindowLaminaImage::WindowLaminaImage(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowLaminaImage)
{
    ui->setupUi(this);
    this->setDatabase( database );
}

WindowLaminaImage::~WindowLaminaImage()
{
    delete ui;
}

void WindowLaminaImage::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowLaminaImage::on_pushButton_calculate_clicked(){
    double A = ui->lineEdit_A->text().toDouble();
    double B = ui->lineEdit_B->text().toDouble();
    double C = ui->lineEdit_C->text().toDouble();
    double D = ui->lineEdit_D->text().toDouble();
    double E = ui->lineEdit_E->text().toDouble();
    double F = ui->lineEdit_F->text().toDouble();
    //double G = ui->lineEdit_G->text().toDouble();
    //double H = ui->lineEdit_H->text().toDouble();
    double I = ui->lineEdit_I->text().toDouble();
    double J = ui->lineEdit_J->text().toDouble();
    double K = ui->lineEdit_K->text().toDouble();

    // width central leg - lamina //
    ui->lineEdit_width->setText( ui->lineEdit_A->text() );

    // window area - lamina //
    double windowArea = D * F;
    ui->lineEdit_windowArea->setText( std::to_string(windowArea).c_str() );

    double area = 0.0;
    if( (B != 0.0) && (C != 0.0) ){
        area  = B * C;
        area -= 2 * windowArea;
    }
    else{
        area  = 2 * C * E;
        area += A * C;
        area += 2 * (C - D) * F;
        area += E * (2 * (E + F) + A);
    }

    area -= 2 * pi * pow( I, 2.0 ) / 4.0;
    area -= 2 * pi * pow( J, 2.0 ) / 4.0;
    area -= 2 * pi * pow( K, 2.0 ) / 4.0;

    // density material - lamina //
    double materialDensity = ui->lineEdit_materialDensity->text().toDouble();
    // tickness lamina - lamina //
    double tickenessLamina = ui->lineEdit_thicknessLamina->text().toDouble();
    // thickness layer - layer //
    double ticknessLayer = ui->lineEdit_thicknessLayer->text().toDouble();

    double tickenessLaminaReal = tickenessLamina * 1000.0 - 2 * ticknessLayer;
    double areaCm2 = area / 100.0;


    // falta o processo de transformar a massa por centimetro


}

void WindowLaminaImage::on_pushButton_exit_clicked(){
    this->close();
}
