#pragma once
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QBrush>
#include<QPen>
#include<QList>
#include<QMainWindow>

#include"Block.h"
#include"Boxes.h"
#include"Spot.h"
#include"Parameter.h"
class Player 
  :public QObject, public QGraphicsRectItem
{
  Q_OBJECT
public:
  Player();
  ~Player();
  void up();
  void down();
  void left();
  void right();
  void arrival(Boxes * box);
  void keyPressEvent(QKeyEvent * event);

signals:
  void countbox();

};
