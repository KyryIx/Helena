#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    /*
        Em calculate transformador
        campos a serem alimentados pelos usuario //
        -> potencia de saida
        -> tensao de saida
        -> tensao de entrada
        ->                                                                      x compensacao de perdas
        -> densidade utilizada no projeto
        -> tipo de fio
        ->                                                                      x compensacao da espessura do isolante da lamina em relacao ao lamina no todo
        -> tipo de lamina usada
        ->                                                                      x valor de acomodacao dos fios em relacao a janela
     */

    /*
      Itens a modificar ou acrescentar:
      -1 - Falta arrumar o metodo toHTML do wire.h
      0 - Olhar o que precisa fazer no metodo findIndexByCurrentMax em wires.h
      1 - Campo de compensação na tela de novo projeto;
      2 - Na tela de novo projeto, colocar alguns valores default para campos genericos;
      3 - Modificar os valores dos campos por default na tela preferencias;
      4 - Documentar o software.

      IMPORTANTE - Na tela de novo projeto, colocar todos os campos no qual sao calculados ou gerados
                 - Fazer uma tela de exportação do projeto para PDF



     */
}
