#pragma once
#include<QGraphicsRectItem>
#include<QObject>
#include<QBrush>
#include<QPen>

#include"parameter.h"

class Block :public QGraphicsRectItem, public QObject
{
public:
	Block();
	~Block();
};
//