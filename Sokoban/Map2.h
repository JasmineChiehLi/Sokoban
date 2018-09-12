#pragma once
#include"Block.h"
#include"Boxes.h"
#include"Player.h"
#include"Spot.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
class Map2 :public QGraphicsView
{
public:
	Map2();
	~Map2();
private:
	QGraphicsScene * scene;
	Block * block[57];
	Boxes*box[3];
	Player *player;
	Spot* spot[3];
};

