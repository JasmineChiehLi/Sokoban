#pragma once
#include "Player.h"
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
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
#include"MessageBox.h"
#include"Userfile.h"
#include"parameter.h"
#include"LevelChoose.h"
#include"Ending.h"
class Top
{
public:
	Top();
	~Top();
	QGraphicsScene * ch;
	LevelChoose * c;

	QGraphicsScene * newScene;
	LevelChoose * newChoose;

	MessageBox * messagebox;

	QGraphicsScene * scene1;//地图1
	QGraphicsView * view1=nullptr;
	Map1 * map1;

	QGraphicsScene * scene2;//地图2
	QGraphicsView * view2=nullptr;
	Map2 * map2;

	QGraphicsScene * scene3;//地图3
	QGraphicsView * view3 = nullptr;
	Map3 * map3;

	QGraphicsScene * scene4;//地图4
	QGraphicsView * view4 = nullptr;
	Map4 * map4;

	Ending * ending = new Ending();//结束界面
};

