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

#include"Player.h"
#include"Boxes.h"
#include"Block.h"
#include"Spot.h"
#include"Step.h"
#include"Userfile.h"
#include"parameter.h"
class Map2 
  :public QObject
{
	Q_OBJECT
public:
	Map2(QGraphicsScene* scene);
	Map2();
	~Map2();
	Step * step;

private:
	Boxes* box[3];
	Spot* spot[3];
  int flag = 1;        //用来改变数组坐标的flag
  Player *player;
  qreal sit[10000];   //last_step，存储坐标的数组
  Block * block[57];
  QGraphicsScene * scene_;
	QPushButton * button[buttonNum];


public slots:
	void Player_Up();
	void Player_Down();
	void Player_Right();
	void Player_Left();
	void Player_Restart();

	void pen();   //last_step
	void receivePos();


};
