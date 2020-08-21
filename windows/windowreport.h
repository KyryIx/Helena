#ifndef WINDOWREPORT_H
#define WINDOWREPORT_H

#include "components/transformer.h"

#include <QDialog>

namespace Ui {
class WindowReport;
}

class WindowReport : public QDialog
{
    Q_OBJECT

public:
    explicit WindowReport(QWidget *parent = nullptr, Transformer* transformer = nullptr );
    ~WindowReport();

public slots:
    void on_plainTextEdit_reportCode_textChanged();
    void on_pushButton_exit_clicked();
    void on_pushButton_makeReportFinal_clicked();

private:
    Ui::WindowReport *ui;
    Transformer* transformer;
};

#endif // WINDOWREPORT_H
