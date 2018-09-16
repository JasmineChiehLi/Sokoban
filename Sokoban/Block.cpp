#include "Block.h"


Block::Block(QGraphicsItem *parent)
  :QObject(), QGraphicsRectItem(parent)
{
  setRect(0, 0, UNIT, UNIT);
  QBrush brush_Block(QImage("Resources/Block.png"));
  setBrush(brush_Block);
}


Block::~Block()
{
}
