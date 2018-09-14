#pragma once

#include"Map1.h"
#include"Map2.h"
#include"Map3.h"
#include"Map4.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
#include<qobject.h>
class Map:public QGraphicsView,public Map1,public Map2,public Map3,public Map4
{
	Q_OBJECT
public:
	Map();
	~Map();
private:
	QGraphicsView * view;
	QGraphicsScene * level;
	QGraphicsScene * scene1;
	QGraphicsScene *scene2;
	QGraphicsScene *scene3;
	QGraphicsScene *scene4;
	Map1 *map1;
	Map2 *map2;
	Map3 *map3;
	Map4 *map4;
	public slots:
	void createmap1();
	void createmap2();
	void createmap3();
	void createmap4();


};

