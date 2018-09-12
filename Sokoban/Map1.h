#pragma once
#include"Block.h"
#include"Boxes.h"
#include"Player.h"
#include"Spot.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
class Map1:public QGraphicsView
{
public:
	Map1();
	~Map1();
private:
	QGraphicsScene * scene;
	Block * block[54];
	Boxes*box[3];
	Player *player;
	Spot* spot[3];
};

