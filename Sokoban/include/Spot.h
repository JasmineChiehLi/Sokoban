#pragma once
#include <QBrush>
#include <QGraphicsRectItem>
#include "Parameter.h"

class Spot
  :public QObject, public QGraphicsRectItem
{
  Q_OBJECT
public:
  Spot();
  ~Spot();
};

