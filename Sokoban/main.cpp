#include "Player.h"
#include <QtWidgets/QApplication>
#include"LevelChoose.h"
#include"QGraphicsView"
#include"Top.h"
#include"Start.h"
#include"userfile.h"
Top * top;//top类是全局类，是凌驾于一切之上的一个类
Userfile * userfile;//为方便，userfile类也设为全局类
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Start* start = new Start;//生成一个Start类
	start->show();
	return a.exec();
}