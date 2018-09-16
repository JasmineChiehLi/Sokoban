#pragma once
#include "Player.h"
#include "Boxes.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>

#include "Parameter.h"
class Map3
{
public:
  Map3();
  ~Map3();
  Map3(QGraphicsScene *scene);
private:
  QGraphicsScene * scene_;
  Block * block[56];
  Boxes*box[4];
  Player *player;
  Spot* spot[4];
};