#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QImage>
#include<qpushbutton.h>
#include<QKeyEvent>

#include"Player.h"
#include"Boxes.h"
#include"Block.h"
#include"Spot.h"
#include"Step.h"
#include"Userfile.h"
#include"Parameter.h"

class Map3 
  :public QObject
{
	Q_OBJECT
public:
	Map3(QGraphicsScene* scene);
	Map3();
	~Map3();
	Step * step;

private:
	Boxes*box[4];
	Block * block[56];
	Spot* spot[4];
	Player *player;
  QGraphicsScene * scene_;
	QPushButton * button[buttonNum];

	qreal sit[10000];   //last_step，存储坐标的数组
	int flag = 1;        //用来改变数组坐标的flag

public slots:
	void Player_Up();
	void Player_Down();
	void Player_Right();
	void Player_Left();
	void Player_Restart();

	void pen();   //last_step
	void receivePos();
};
