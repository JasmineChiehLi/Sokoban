#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QImage>
#include<QBrush>
#include<qpushbutton.h>
#include<QKeyEvent>

#include"Player.h"
#include"Boxes.h"
#include"Block.h"
#include"Spot.h"
#include"Step.h"
#include"Userfile.h"
#include"parameter.h"
class Map4
  :public QObject
{
  Q_OBJECT
public:
  Map4();
  Map4(QGraphicsScene* scene);
  ~Map4();

  Step * step;
  Userfile * userfile;

private:
  Boxes*box[6];
  Spot* spot[6];
  int flag = 1;        //用来改变数组坐标的flag
  Player *player;
  Block * block[52];
  QGraphicsScene * scene_;
  qreal sit[10000];   //last_step，存储坐标的数组
  QPushButton * button[buttonNum];

  public slots:
  void pen();   //last_step
  void Player_Up();
  void Player_Down();
  void Player_Right();
  void Player_Left();
  void Player_Restart();
  void receivePos();
};

