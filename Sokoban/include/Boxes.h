#pragma once
#include<QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include "Block.h"
#include "Spot.h"
#include "qsound.h"


class Boxes :public QObject, public QGraphicsRectItem {
  Q_OBJECT
public:
  Boxes(QGraphicsItem * parent = 0);
  void isArrival();
  ~Boxes();
  const bool getFlag();
private:
  bool flag = 0;          //flag�����ж�box�Ƿ񵽴�spot
};
