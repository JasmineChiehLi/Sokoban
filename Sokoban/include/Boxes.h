#pragma once//
#include<QGraphicsRectItem>
#include<QObject>
#include<QBrush>
#include<QPen>
#include"spot.h"
#include"MessageBox.h"
#include"parameter.h"
class Boxes :public QGraphicsRectItem, public QObject
{
public:
	Boxes();
	bool getFlag();
	void isArrival();//用来判断玩家是否在终点
	static int count;
	static int boxNum;;
	~Boxes();
private:
	int flag1 = 0;
	int flag2 = 0;
};
