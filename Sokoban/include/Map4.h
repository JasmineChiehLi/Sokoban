#pragma once
#include "Player.h"
#include "Boxes.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>

#include "Parameter.h"
class Map4
{
public:
  Map4();
  Map4(QGraphicsScene*scene);
  ~Map4();
private:
  QGraphicsScene * scene_;
  Block * block[52];
  Boxes*box[6];
  Player *player;
  Spot* spot[6];
};
