#pragma once
#include"Block.h"
#include"Boxes.h"
#include"Player.h"
#include"Spot.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
class Map4:public QGraphicsView
{
public:
	Map4();
	~Map4();
private:
	QGraphicsScene * scene;
	Block * block[52];
	Boxes*box[6];
	Player *player;
	Spot* spot[6];
};

