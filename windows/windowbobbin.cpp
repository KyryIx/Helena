#include "windows/windowbobbin.h"
#include "ui_windowbobbin.h"

#include <QMessageBox>

#define table "bobbins"

WindowBobbin::WindowBobbin(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowBobbin)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->bobbin = new Bobbin();
    this->init();
}

WindowBobbin::~WindowBobbin()
{
    delete ui;
}

void WindowBobbin::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowBobbin::clearFields(){
    ui->lineEdit_id->clear();
    ui->lineEdit_code->clear();
    ui->lineEdit_width->clear();
    ui->lineEdit_length->clear();
    ui->lineEdit_height->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_provider->clear();
}

void WindowBobbin::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_code->setText( this->database->returnValue( "code_bobbin" ).c_str() );
    ui->lineEdit_width->setText( this->database->returnValue( "width_bobbin" ).c_str() );
    ui->lineEdit_length->setText( this->database->returnValue( "length_bobbin" ).c_str() );
    ui->lineEdit_height->setText( this->database->returnValue( "height_bobbin" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_bobbin" ).c_str() );
    ui->lineEdit_provider->setText( this->database->returnValue( "provider_bobbin" ).c_str() );
}

void WindowBobbin::updateBobbin(){
    this->bobbin->setId( ui->lineEdit_id->text().toUInt() );
    this->bobbin->setCode( ui->lineEdit_code->text().toStdString() );
    this->bobbin->setWidth( ui->lineEdit_width->text().toDouble() );
    this->bobbin->setLength( ui->lineEdit_length->text().toDouble() );
    this->bobbin->setHeight( ui->lineEdit_height->text().toDouble() );
    this->bobbin->setType( ui->lineEdit_type->text().toStdString() );
    this->bobbin->setProvider( ui->lineEdit_provider->text().toStdString() );
}

void WindowBobbin::init(){
    this->clearFields();
    if( this->database->executeSQL( "SELECT * FROM bobbins ORDER BY id ASC" ) > -1 ){
        this->on_pushButton_after_clicked();
    }
    else{
        QMessageBox msgBox;
        msgBox.setInformativeText( "Erro na consulta." );
        msgBox.setIcon( QMessageBox::Warning );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowBobbin::on_pushButton_before_clicked(){
    if( this->database->previousRegister() ){
        this->updateFields();
        this->updateBobbin();
    }
}

void WindowBobbin::on_pushButton_after_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
        this->updateBobbin();
    }
}

void WindowBobbin::on_pushButton_update_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente atualizar o carretel aberto?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        std::string sql = "UPDATE ";
        sql += table;
        sql += " SET ";
        unsigned char size = static_cast<unsigned char>( sql.size() );
        const double precision = 1e-5;

        if( this->bobbin->getId() != ui->lineEdit_id->text().toUInt() ){
            return;
        }

        if( this->bobbin->getCode() == ui->lineEdit_code->text().toStdString() ){
            sql += "code_bobbin='" + ui->lineEdit_code->text().toStdString() + "', ";
        }

        if( fabs( this->bobbin->getWidth() - ui->lineEdit_width->text().toDouble() ) >= precision ){
            sql += "width_bobbin=" + ui->lineEdit_width->text().toStdString() + ", ";
        }

        if( fabs( this->bobbin->getLength() - ui->lineEdit_length->text().toDouble() ) >= precision ){
            sql += "length_bobbin=" + ui->lineEdit_length->text().toStdString() + ", ";
        }

        if( fabs( this->bobbin->getHeight() - ui->lineEdit_height->text().toDouble() ) >= precision ){
            sql += "height_bobbin=" + ui->lineEdit_height->text().toStdString() + ", ";
        }

        if( this->bobbin->getType() != ui->lineEdit_type->text().toStdString() ){
            sql += "type_bobbin='" + ui->lineEdit_type->text().toStdString() + "', ";
        }

        if( this->bobbin->getProvider() != ui->lineEdit_provider->text().toStdString() ){
            sql += "provider_bobbin='" + ui->lineEdit_provider->text().toStdString() + "', ";
        }

        msgBox.setInformativeText( sql.c_str() );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();

        if( sql.size() > size ){
            sql = sql.substr( 0, sql.size()-2 );
            sql += " WHERE id=" + std::to_string( this->bobbin->getId() );

            if( this->database->executeSQL( sql ) > -1 ){
                msgBox.setInformativeText( "Atualização feita com sucesso." );
                msgBox.setIcon( QMessageBox::Information );
                this->init();
            }
            else{
                msgBox.setInformativeText( "Erro na consulta." );
                msgBox.setIcon( QMessageBox::Warning );
            }
        }
        else{
            msgBox.setInformativeText( "Os valores nos campos são idênticos aos armazenados na base de dados." );
            msgBox.setIcon( QMessageBox::Warning );
        }

        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowBobbin::on_pushButton_delete_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente excluir o carretel aberto?" );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        int id = ui->lineEdit_id->text().toInt();
        if( id > 0 ){
            std::string sql = "DELETE FROM ";
            sql += table;
            sql += " WHERE id=" + std::to_string(id);
            if( this->database->executeSQL( sql ) > -1 ){
                this->on_pushButton_after_clicked();
                msgBox.setInformativeText( "Exclusão feita com sucesso." );
                msgBox.setIcon( QMessageBox::Information );
                this->init();
            }
            else{
                msgBox.setInformativeText( "Erro na consulta." );
                msgBox.setIcon( QMessageBox::Warning );
            }
        }
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }
}

void WindowBobbin::on_pushButton_exit_clicked(){
    this->close();
}
