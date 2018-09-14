#pragma once
#include "Player.h"
#include "Boxes.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>

#include "Parameter.h"

class Map1
{
public:
  Map1(QGraphicsScene* scene);
  Map1();
  ~Map1();
private:
  QGraphicsScene * scene_;
  Block * block[54];
  Boxes* box[3];
  Player *player;
  Spot* spot[3];
};
