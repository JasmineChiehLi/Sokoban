#pragma once
#include"Block.h"
#include"Boxes.h"
#include"Player.h"
#include"Spot.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
class Map1
{
public:
	Map1(QGraphicsScene* scene);
	Map1();
	~Map1();
private:
	QGraphicsScene * scene_;
	Block * block[54];
	Boxes *box[3];
	Player *player;
	Spot* spot[3];
};

