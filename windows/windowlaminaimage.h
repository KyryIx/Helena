#ifndef WINDOWLAMINAIMAGE_H
#define WINDOWLAMINAIMAGE_H

#include <QDialog>
#include "components/database.h"
#include "components/lamina.h"

namespace Ui {
class WindowLaminaImage;
}

class WindowLaminaImage : public QDialog
{
    Q_OBJECT

public:
    explicit WindowLaminaImage(QWidget *parent = nullptr, DataBase* database=nullptr);
    ~WindowLaminaImage();
    void setDatabase( DataBase *database );

private:
    Ui::WindowLaminaImage *ui;
    DataBase* database;
    Lamina* lamina;
};

#endif // WINDOWLAMINAIMAGE_H
