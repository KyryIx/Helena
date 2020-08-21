#include "windowreport.h"
#include "ui_windowreport.h"

#include<QMessageBox>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>

WindowReport::WindowReport(QWidget *parent, Transformer* transformer) :
    QDialog(parent),
    ui(new Ui::WindowReport)
{
    ui->setupUi(this);
    this->transformer = transformer;
    QString constantes[8] = {"tensao_entrada", "tensao_saida", "frequencia", "corrente_entrada", "corrente_saida", "espiras_primario", "espiras_secundario"};
    float valores[8] = {1240, 12, 60, 10, 50, 6845, 68};
    QString str = this->ui->plainTextEdit_reportCode->toPlainText();
    for( int i=0; i<8; i++ ){
        str = str.replace( QString("$$")+constantes[i]+QString("$$"), QString::number(valores[i]), Qt::CaseSensitive );
    }
    this->ui->textBrowser_reportResult->setHtml( str );
}

WindowReport::~WindowReport()
{
    delete ui;
}

void WindowReport::on_pushButton_makeReportFinal_clicked(){
    std::string fileName = QFileDialog::getSaveFileName( this, tr("Save Report"), "", tr("Portable Document Format Files (*.pdf)") ).toStdString();

    QMessageBox msgBox;

    if( fileName == "" ){
        msgBox.setInformativeText( "cancelamento do processo" );
        msgBox.setIcon( QMessageBox::Warning );
    }
    else{
        // https://wiki.qt.io/Exporting_a_document_to_PDF //
        QPrinter printer( QPrinter::PrinterResolution );
        printer.setOutputFormat( QPrinter::PdfFormat );
        printer.setPaperSize( QPrinter::A4 );
        printer.setOutputFileName( fileName.c_str() );

        QTextDocument doc;
        doc.setHtml( this->transformer->toHTML().c_str() );
        doc.setPageSize( printer.pageRect().size() ); // This is necessary if you want to hide the page number
        doc.print(&printer);

        msgBox.setInformativeText( "Relatório salvo com sucesso." );
        msgBox.setIcon( QMessageBox::Information );
    }
    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.exec();
}

void WindowReport::on_pushButton_exit_clicked(){
    this->close();
}

void WindowReport::on_plainTextEdit_reportCode_textChanged(){
    QString constantes[8] = {"tensao_entrada", "tensao_saida", "frequencia", "corrente_entrada", "corrente_saida", "espiras_primario", "espiras_secundario"};
    float valores[8] = {1240, 12, 60, 10, 50, 6845, 68};
    QString str = this->ui->plainTextEdit_reportCode->toPlainText();
    for( int i=0; i<8; i++ ){
        str = str.replace( QString("$$")+constantes[i]+QString("$$"), QString::number(valores[i]), Qt::CaseSensitive );
    }
    this->ui->textBrowser_reportResult->setHtml( str );
}
