#ifndef WINDOWREPORT_H
#define WINDOWREPORT_H

#include <QDialog>

namespace Ui {
class WindowReport;
}

class WindowReport : public QDialog
{
    Q_OBJECT

public:
    explicit WindowReport(QWidget *parent = nullptr);
    ~WindowReport();

private:
    Ui::WindowReport *ui;
};

#endif // WINDOWREPORT_H
