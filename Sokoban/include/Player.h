#pragma once
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QBrush>
#include<QPen>
#include<QList>
//#include<Boxes.h>
#include<QMainWindow>
//
#include"block.h"
#include"boxes.h"
#include"spot.h"
#include"parameter.h"
class Player:public QObject,public QGraphicsRectItem
{
public:
	Player();
	void keyPressEvent(QKeyEvent * event);
	void arrival(Boxes * box);
	void up();
	void down();
	void left();
	void right();
	/*void left_pull();
	void right_pull();
	void up_pull();
	void down_pull();*/
	~Player();
};

