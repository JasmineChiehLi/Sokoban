#pragma once
#include<QGraphicsRectItem>
#include <QBrush>
#include "Parameter.h"

class Block :public QObject, public QGraphicsRectItem {
  Q_OBJECT
public:
  Block(QGraphicsItem * parent = 0);
  ~Block();
};
