#pragma 
#include<QPen>
#include<QObject>
#include<QBrush>
#include<QGraphicsRectItem>

#include"parameter.h"

class Block 
  :public QGraphicsRectItem, public QObject
{
public:
	Block();
	~Block();
};
