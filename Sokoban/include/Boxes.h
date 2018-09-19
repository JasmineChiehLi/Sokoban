#pragma once
#include<QPen>
#include<QObject>
#include<QBrush>
#include<QGraphicsRectItem>

#include"spot.h"
#include"MessageBox.h"
#include"parameter.h"

class Boxes 
  :public QGraphicsRectItem, public QObject
{
public:
	Boxes();
  ~Boxes();
  void reStart();
	bool getFlag();//返回箱子当前状态，是在普通地板上，还是在终点
	void isArrival();//用来判断玩家是否在终点
	static int count;//用来表示游戏中推到终点的箱子数
	static int boxNum;//用来表示游戏中把几个箱子推到位就算赢

private:
	int flag1 = 0;//用来存储箱子当前的状态
	int flag2 = 0;//用来存储玩家上一步的状态
};
