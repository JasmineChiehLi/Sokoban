#pragma once
#include<QObject>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QPen>
#include"parameter.h"
class Spot :public QObject,public QGraphicsRectItem
{
public:
	Spot();
	~Spot();
};
