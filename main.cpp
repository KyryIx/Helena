#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
        OK - bobbin.h
        OK - bobbins.h
        OK - database.h
        OK - lamina.h
        OK - laminas.h
    NAO OK - transformer.h (verificar dados na folha de calculo)
        OK - wire.h
    NAO OK - wires.h (verificar o metodo findIndexByCurrentMax)
    */
    return a.exec();

    /*
        Em calculate transformador
        -> verificar o delay ao precisar dar dois cliques no botao voltar apos excluir um projeto de transformador

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
      2 - Na tela de novo projeto, colocar alguns valores default para campos genericos;
      3 - Modificar os valores dos campos por default na tela preferencias;
      4 - Fazer uma tela de exportação do projeto para PDF
      5 - Documentar o software.
     */
}
