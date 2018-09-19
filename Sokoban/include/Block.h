#pragma once
#include<QPen>
#include<QObject>
#include<QBrush>
#include<QGraphicsRectItem>

#include"Parameter.h"

class Block 
  :public QObject, public QGraphicsRectItem
{
public:
	Block();
	~Block();
};
