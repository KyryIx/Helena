#ifndef WINDOWABOUT_H
#define WINDOWABOUT_H

#include <QDialog>

namespace Ui {
class WindowAbout;
}

class WindowAbout : public QDialog
{
    Q_OBJECT

public:
    explicit WindowAbout(QWidget *parent = nullptr);
    ~WindowAbout();

private:
    Ui::WindowAbout *ui;
};

#endif // WINDOWABOUT_H
