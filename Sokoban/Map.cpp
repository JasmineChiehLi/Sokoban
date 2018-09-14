#include "Map.h"
//#include<qdebug.h>
#include<qtimer.h>
Map::Map()
{

	setBackgroundBrush(QBrush(QImage("Resources/floor.jpg")));
	//初始选关界面
	//view->setScene(level);
	
	//去掉滚动栏
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(975, 675);

	
	createmap1();

	QTimer::singleShot(3*1000, this, SLOT(createmap2()));
}


Map::~Map()
{
}

void Map::createmap1()
{
	scene1 = new QGraphicsScene();
	map1 = new Map1(scene1);
	setScene(scene1);

	
}
void Map::createmap2()
{
	scene2 = new QGraphicsScene();
	map2 = new Map2(scene2);
	setScene(scene2);
	QTimer::singleShot(2 * 1000, this, SLOT(createmap3()));
}

void Map::createmap3()
{
	scene3 = new QGraphicsScene();
	map3 = new Map3(scene3);
	setScene(scene3);
	QTimer::singleShot(2 * 1000, this, SLOT(createmap4()));
}

void Map::createmap4()
{
	scene4 = new QGraphicsScene();
	map4 = new Map4(scene4);
	setScene(scene4);
	
}