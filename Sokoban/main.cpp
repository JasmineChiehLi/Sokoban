#include <QApplication>
#include <QDebug>
#include "Game.h"
#include "Start.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Start* start = new Start;
  start->show();

  /*Game* game = new Game;
  game->show();*/


  return a.exec();
}
