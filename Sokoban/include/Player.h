#pragma once

#include<QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include <QList>

#include <QGraphicsScene>
#include <QBrush>
#include "qsound.h"

#include "Boxes.h"
#include "Parameter.h"

class Player :public QObject, public QGraphicsRectItem {
  Q_OBJECT
public:
  Player(QGraphicsItem * parent = 0);
  void keyPressEvent(QKeyEvent * event);
  ~Player();
};