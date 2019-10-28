#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    NAO OK - transformer.h (verificar dados na folha de calculo)
    NAO OK - wires.h (verificar o metodo findIndexByCurrentMax)
    */
    return a.exec();

    /*
        Em calculate transformador
        -> verificar o delay ao precisar dar dois cliques no botao voltar apos excluir um projeto de transformador

        campos a serem alimentados pelos usuario //
     */

    /*
      Itens a modificar ou acrescentar:
      4 - Fazer uma tela de exportação do projeto para PDF
      5 - Documentar o software.
     */
}
