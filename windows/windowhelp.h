#ifndef WINDOWHELP_H
#define WINDOWHELP_H

#include <QDialog>

namespace Ui {
class WindowHelp;
}

class WindowHelp : public QDialog
{
    Q_OBJECT

public:
    explicit WindowHelp(QWidget *parent = nullptr);
    ~WindowHelp();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::WindowHelp *ui;
    void init();
};

#endif // WINDOWHELP_H
