#pragma once
#include"Block.h"
#include"Boxes.h"
#include"Player.h"
#include"Spot.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
class Map3
{
public:
	Map3();
	~Map3();
	Map3(QGraphicsScene *scene);
private:
	QGraphicsScene * scene_;
	Block * block[56];
	Boxes*box[4];
	Player *player;
	Spot* spot[4];
};

