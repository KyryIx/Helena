#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    /*
      Itens a modificar ou acrescentar:
      1 - Campo de compensação na tela de novo projeto;
      2 - Na tela de novo projeto, colocar alguns valores default para campos genericos;
      3 - Modificar os valores dos campos por default na tela preferencias;
      4 - Documentar o software.

      IMPORTANTE - Na tela de novo projeto, colocar todos os campos no qual sao calculados ou gerados
                 - Fazer uma tela de exportação do projeto para PDF



     */
}
