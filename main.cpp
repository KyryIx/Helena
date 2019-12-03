#include "windows/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
     wires.h (verificar o metodo findIndexByCurrentMax)
     transformer.h (No método calculate, verificar o delay ao precisar dar dois cliques no botao voltar apos excluir um projeto de transformador)
     windownewproject.h (ver a opção de criar uma opção de center tap)
     http://www.novacon.com.br/audiotabawg.htm
	 
	 Use C:\Qt\5.11.2\mingw53_32\bin\windeployqt.exe para criar o projeto para ser distribuido

     ver o metodo init da classe windowhelp
     // http://www.cplusplus.com/doc/tutorial/files/ //
     */
    return a.exec();
}
