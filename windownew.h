#ifndef WINDOWNEW_H
#define WINDOWNEW_H

#include <QDialog>

namespace Ui {
class WindowNew;
}

class WindowNew : public QDialog
{
    Q_OBJECT

public:
    explicit WindowNew(QWidget *parent = nullptr);
    ~WindowNew();

private:
    Ui::WindowNew *ui;
};

#endif // WINDOWNEW_H
