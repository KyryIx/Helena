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
     */
    return a.exec();
}
