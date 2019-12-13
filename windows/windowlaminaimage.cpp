#include "windowlaminaimage.h"
#include "ui_windowlaminaimage.h"

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
