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
