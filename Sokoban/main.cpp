#include <QApplication>
#include "Start.h"


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Start* start = new Start;
  start->show();

  return a.exec();
}
