//#include "Player_1.h"/
#include <QtWidgets/QApplication>
#include"LevelChoose.h"
#include"QGraphicsView"
#include"Top.h"
#include"Start.h"
Top * top;//top����ȫ���࣬�������һ��֮�ϵ�һ����
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//top = new Top();
	Start *start = new Start();
	start->show();
	return a.exec();
}