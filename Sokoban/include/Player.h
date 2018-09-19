#pragma once
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QBrush>
#include<QPen>
#include<QList>
#include<QMainWindow>

#include"block.h"
#include"boxes.h"
#include"spot.h"
#include"parameter.h"
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
