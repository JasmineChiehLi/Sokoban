#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QImage>
#include<QBrush>
#include<qpushbutton.h>
#include<QKeyEvent>
//
#include"Player.h"
#include"Boxes.h"
#include"Block.h"
#include"Spot.h"
#include"Step.h"
#include"Userfile.h"
#include"parameter.h"
class Map3:public QObject
{Q_OBJECT
public:
	Map3(QGraphicsScene* scene);
	Map3();
	~Map3();
	Step * step;
private:
	QGraphicsScene * scene_;
	Block * block[56];
	Boxes*box[4];
	Player *player;
	Spot* spot[4];
	QPushButton * button[buttonNum];
public slots:
	void Player_Up();
	void Player_Down();
	void Player_Right();
	void Player_Left();
	void Player_Restart();
};
