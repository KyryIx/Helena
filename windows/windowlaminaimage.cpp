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

    // density material (g/cm^3) - lamina //
    double materialDensity = ui->lineEdit_materialDensity->text().toDouble();
    // density lamina (kg/cm) //
    double densityLamina = (area * materialDensity) / 100000.0;
    ui->lineEdit_weight->setText( std::to_string(densityLamina).c_str() );

    // tickness lamina (mm) - lamina //
    double tickenessLamina = ui->lineEdit_thicknessLamina->text().toDouble();
    // thickness layer (mm) - layer //
    double ticknessLayer = ui->lineEdit_thicknessLayer->text().toDouble();
    // % //
    double compensation = (2.0 * ticknessLayer) / (tickenessLamina * 1000.0);
    ui->lineEdit_compensationPercent->setText( std::to_string(compensation).c_str() );
}

void WindowLaminaImage::clearFields(){
    ui->lineEdit_A->clear();
    ui->lineEdit_B->clear();
    ui->lineEdit_C->clear();
    ui->lineEdit_D->clear();
    ui->lineEdit_E->clear();
    ui->lineEdit_F->clear();
    ui->lineEdit_G->clear();
    ui->lineEdit_H->clear();
    ui->lineEdit_I->clear();
    ui->lineEdit_J->clear();
    ui->lineEdit_K->clear();

    ui->lineEdit_code->clear();
    ui->lineEdit_loss->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_width->clear();
    ui->lineEdit_weight->clear();
    ui->lineEdit_provider->clear();
    ui->lineEdit_windowArea->clear();
    ui->lineEdit_stackingFactor->clear();
    ui->lineEdit_thicknessLayer->clear();
    ui->lineEdit_materialDensity->clear();
    ui->lineEdit_thicknessLamina->clear();
    ui->lineEdit_compensationPercent->clear();
}

void WindowLaminaImage::on_pushButton_clear_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente limpar os campos?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        this->clearFields();
    }
}

void WindowLaminaImage::on_pushButton_insert_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja salvar mesmo?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        Lamina* lamina = new Lamina();
        //lamina->setId( ui->lineEdit_id->text().toUInt() );
        lamina->setType( ui->lineEdit_type->text().toStdString() );
        lamina->setProvider( ui->lineEdit_provider->text().toStdString() );
        lamina->setWidth( ui->lineEdit_width->text().toDouble() );
        lamina->setWindowArea( ui->lineEdit_windowArea->text().toDouble() );
        lamina->setWeight( ui->lineEdit_weight->text().toDouble() );
        lamina->setCompensationPercent( ui->lineEdit_compensationPercent->text().toDouble() );

        if( this->database->executeSQL( lamina->toSQL() ) > -1 ){
            msgBox.setInformativeText( "Salvamento feito com sucesso." );
            msgBox.setIcon( QMessageBox::Information );
        }
        else{
            msgBox.setInformativeText( "Erro na consulta." );
            msgBox.setIcon( QMessageBox::Warning );
        }
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowLaminaImage::on_pushButton_exit_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente sair do formulário?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
       this->close();
    }
}
