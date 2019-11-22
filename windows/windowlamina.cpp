#include "windows/windowlamina.h"
#include "ui_windowlamina.h"

#include <QMessageBox>

#define table "laminas"

WindowLamina::WindowLamina(QWidget *parent, DataBase* database) :
    QDialog(parent),
    ui(new Ui::WindowLamina)
{
    ui->setupUi(this);
    this->setDatabase( database );
    this->lamina = new Lamina();
    this->init();
}

WindowLamina::~WindowLamina()
{
    delete ui;
}

void WindowLamina::setDatabase( DataBase *database ){
    this->database = database;
}

void WindowLamina::clearFields(){
    ui->lineEdit_id->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_provider->clear();
    ui->lineEdit_width->clear();
    ui->lineEdit_weight->clear();
    ui->lineEdit_windowArea->clear();
    ui->lineEdit_thicknessPercent->clear();
}

void WindowLamina::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_lamina" ).c_str() );
    ui->lineEdit_provider->setText( this->database->returnValue( "provider_lamina" ).c_str() );
    ui->lineEdit_width->setText( this->database->returnValue( "width_lamina" ).c_str() );
    ui->lineEdit_weight->setText( this->database->returnValue( "weight_lamina" ).c_str() );
    ui->lineEdit_windowArea->setText( this->database->returnValue( "window_area_lamina" ).c_str() );
    ui->lineEdit_thicknessPercent->setText( this->database->returnValue( "thickness_percent_lamina" ).c_str() );
}

void WindowLamina::updateLamina(){
    this->lamina->setId( ui->lineEdit_id->text().toUInt() );
    this->lamina->setWidth( ui->lineEdit_width->text().toDouble() );
    this->lamina->setWindowArea( ui->lineEdit_windowArea->text().toDouble() );
    this->lamina->setWeight( ui->lineEdit_weight->text().toDouble() );
    this->lamina->setThicknessPercent( ui->lineEdit_thicknessPercent->text().toDouble() );
    this->lamina->setType( ui->lineEdit_type->text().toStdString() );
    this->lamina->setProvider( ui->lineEdit_provider->text().toStdString() );
}

void WindowLamina::init(){
    this->clearFields();
    if( this->database->executeSQL( "SELECT * FROM laminas ORDER BY id ASC" ) > -1 ){
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

void WindowLamina::on_pushButton_before_clicked(){
    if( this->database->previousRegister() ){
        this->updateFields();
        this->updateLamina();
    }
}

void WindowLamina::on_pushButton_after_clicked(){
    if( this->database->nextRegister() ){
        this->updateFields();
        this->updateLamina();
    }
}

void WindowLamina::on_pushButton_update_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente atualizar a lâmina aberta." );
    msgBox.setIcon( QMessageBox::Warning );
    msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
    if( msgBox.exec() == QMessageBox::Ok ){
        std::string sql = "UPDATE ";
        sql += table;
        sql += " SET ";
        unsigned char size = static_cast<unsigned char>( sql.size() );
        const double precision = 1e-5;

        if( this->lamina->getId() != ui->lineEdit_id->text().toUInt() ){
            return;
        }

        if( fabs( this->lamina->getWidth() - ui->lineEdit_width->text().toDouble() ) >= precision ){
            sql += "width_lamina=" + ui->lineEdit_width->text().toStdString() + ", ";
        }

        if( fabs( this->lamina->getWindowArea() - ui->lineEdit_windowArea->text().toDouble() ) >= precision ){
            sql += "window_area_lamina=" + ui->lineEdit_windowArea->text().toStdString() + ", ";
        }

        if( fabs( this->lamina->getWeight() - ui->lineEdit_weight->text().toDouble() ) >= precision ){
            sql += "weight_lamina=" + ui->lineEdit_weight->text().toStdString() + ", ";
        }

        if( fabs( this->lamina->getThicknessPercent() - ui->lineEdit_thicknessPercent->text().toDouble() ) >= precision ){
            sql += "thickness_percent_lamina=" + ui->lineEdit_thicknessPercent->text().toStdString() + ", ";
        }

        if( this->lamina->getType() != ui->lineEdit_type->text().toStdString() ){
            sql += "type_lamina='" + ui->lineEdit_type->text().toStdString() + "', ";
        }

        if( this->lamina->getProvider() != ui->lineEdit_provider->text().toStdString() ){
            sql += "provider_lamina='" + ui->lineEdit_provider->text().toStdString() + "', ";
        }

        if( sql.size() > size ){
            sql = sql.substr( 0, sql.size()-2 );
            sql += " WHERE id=" + std::to_string( this->lamina->getId() );

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

void WindowLamina::on_pushButton_delete_clicked(){
    QMessageBox msgBox;
    msgBox.setInformativeText( "Deseja realmente excluir a lâmina aberta?" );
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

void WindowLamina::on_pushButton_exit_clicked(){
    this->close();
}
