#ifndef WINDOWPREFERENCE_H
#define WINDOWPREFERENCE_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class WindowPreference;
}

class WindowPreference : public QDialog
{
    Q_OBJECT

public:
    explicit WindowPreference(QWidget *parent = nullptr);
    ~WindowPreference();

public slots:
    void on_pushButton_ok_clicked();

private:
    Ui::WindowPreference *ui;
};

#endif // WINDOWPREFERENCE_H
