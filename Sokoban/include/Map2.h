#pragma once
#include "Player.h"
#include "Boxes.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>

#include "Parameter.h"
class Map2
{
public:
  Map2();
  Map2(QGraphicsScene *scene);
  ~Map2();
private:
  QGraphicsScene * scene_;
  Block * block[57];
  Boxes* box[3];
  Player *player;
  Spot* spot[3];
};

