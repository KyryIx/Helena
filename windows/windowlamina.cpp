#include "windows/windowlamina.h"
#include "ui_windowlamina.h"

#include "windows/windowlaminaimage.h"

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
    this->stateInsert = 0;
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
    ui->lineEdit_compensationPercent->clear();
}

void WindowLamina::updateFields(){
    this->clearFields();
    ui->lineEdit_id->setText( this->database->returnValue( "id" ).c_str() );
    ui->lineEdit_type->setText( this->database->returnValue( "type_lamina" ).c_str() );
    ui->lineEdit_provider->setText( this->database->returnValue( "provider_lamina" ).c_str() );
    ui->lineEdit_width->setText( this->database->returnValue( "width_lamina" ).c_str() );
    ui->lineEdit_weight->setText( this->database->returnValue( "weight_lamina" ).c_str() );
    ui->lineEdit_windowArea->setText( this->database->returnValue( "window_area_lamina" ).c_str() );
    ui->lineEdit_compensationPercent->setText( this->database->returnValue( "compensation_percent_lamina" ).c_str() );
}

void WindowLamina::updateLamina(){
    this->lamina->setId( ui->lineEdit_id->text().toUInt() );
    this->lamina->setWidth( ui->lineEdit_width->text().toDouble() );
    this->lamina->setWindowArea( ui->lineEdit_windowArea->text().toDouble() );
    this->lamina->setWeight( ui->lineEdit_weight->text().toDouble() );
    this->lamina->setCompensationPercent( ui->lineEdit_compensationPercent->text().toDouble() );
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

void WindowLamina::on_pushButton_visualMode_clicked(){
    WindowLaminaImage* dialog = new WindowLaminaImage(this, this->database);
    dialog->show();
    dialog->raise();
    dialog->exec();
    //dialog->activateWindow();
     this->init();
}

void WindowLamina::on_pushButton_first_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->firstRegister() ){
            this->updateFields();
            this->updateLamina();
        }
    }
}

void WindowLamina::on_pushButton_last_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->lastRegister() ){
            this->updateFields();
            this->updateLamina();
        }
    }
}

void WindowLamina::on_pushButton_before_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->previousRegister() ){
            this->updateFields();
            this->updateLamina();
        }
    }
}

void WindowLamina::on_pushButton_after_clicked(){
    this->setStateInsert( 0 );
    if( this->database->queryIsActive() ){
        if( this->database->nextRegister() ){
            this->updateFields();
            this->updateLamina();
        }
    }
}

void WindowLamina::on_pushButton_update_clicked(){
    this->setStateInsert( 0 );
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
            msgBox.setInformativeText( "Dados em branco. Use a opção de \"Inserir Novo\"" );
            msgBox.setStandardButtons( QMessageBox::Ok );
            msgBox.exec();
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

        if( fabs( this->lamina->getCompensationPercent() - ui->lineEdit_compensationPercent->text().toDouble() ) >= precision ){
            sql += "compensation_percent_lamina=" + ui->lineEdit_compensationPercent->text().toStdString() + ", ";
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

void WindowLamina::setStateInsert( unsigned char state ){
    switch( state ){
        case 0:
            ui->pushButton_insert->setText( "Inserir Novo" );
            this->stateInsert = 0;
            break;

        case 1:
            ui->pushButton_insert->setText( "Salvar" );
            this->stateInsert = 1;
            break;
    }
}

void WindowLamina::on_pushButton_insert_clicked(){
    switch( this->stateInsert ){
        case 0:
        {
            QMessageBox msgBox;
            msgBox.setInformativeText( "Deseja campos em branco?" );
            msgBox.setIcon( QMessageBox::Warning );
            msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
            if( msgBox.exec() == QMessageBox::Ok ){
                this->clearFields();
            }
            this->setStateInsert( 1 );
            break;
        }

        case 1:
        {
            QMessageBox msgBox;
            msgBox.setInformativeText( "Deseja salvar mesmo?" );
            msgBox.setIcon( QMessageBox::Warning );
            msgBox.setStandardButtons( QMessageBox::Ok|QMessageBox::No );
            if( msgBox.exec() == QMessageBox::Ok ){
                Lamina* lamina = new Lamina();
                lamina->setId( ui->lineEdit_id->text().toUInt() );
                lamina->setType( ui->lineEdit_type->text().toStdString() );
                lamina->setProvider( ui->lineEdit_provider->text().toStdString() );
                lamina->setWidth( ui->lineEdit_width->text().toDouble() );
                lamina->setWindowArea( ui->lineEdit_windowArea->text().toDouble() );
                lamina->setWeight( ui->lineEdit_weight->text().toDouble() );
                lamina->setCompensationPercent( ui->lineEdit_compensationPercent->text().toDouble() );

                if( this->database->executeSQL( lamina->toSQL() ) > -1 ){
                    this->on_pushButton_after_clicked();
                    msgBox.setInformativeText( "Salvamento feito com sucesso." );
                    msgBox.setIcon( QMessageBox::Information );
                    this->init();
                }
                else{
                    msgBox.setInformativeText( "Erro na consulta." );
                    msgBox.setIcon( QMessageBox::Warning );
                }
                msgBox.setStandardButtons( QMessageBox::Ok );
                msgBox.exec();
            }
            this->setStateInsert( 0 );
            break;
        }
    }
}

void WindowLamina::on_pushButton_delete_clicked(){
    this->setStateInsert( 0 );
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
    this->setStateInsert( 0 );
    this->close();
}
