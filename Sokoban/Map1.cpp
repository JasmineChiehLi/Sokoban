#include "Map1.h"

Map1::Map1()
{

}

Map1::Map1(QGraphicsScene *scene)
{
  //initialize the scene

  scene_ = scene;
  scene->setSceneRect(0, 0, 975, 675);
  scene->setBackgroundBrush(QImage("Resources/Floor.jpg"));

  //create the map

  //block*54,player*1,,box*3
  for (int i = 0; i <54; i++)
  {
    block[i] = new Block();
  }
  player = new Player();
  for (int i = 0; i < 3; i++)
  {
    box[i] = new Boxes();
    spot[i] = new Spot();
  }

  //row0
  for (int i = 0; i < 9; i++)
  {
    block[i]->setPos(UNIT*i, 0);
  }
  //row1
  int row1 = UNIT;
  block[9]->setPos(0, row1);
  block[10]->setPos(UNIT * 4, row1);
  block[11]->setPos(UNIT * 5, row1);
  block[12]->setPos(UNIT * 6, row1);
  block[13]->setPos(UNIT * 7, row1);
  block[14]->setPos(UNIT * 8, row1);
  player->setPos(UNIT, row1);

  //row2
  int row2 = UNIT * 2;
  block[15]->setPos(0, row2);
  block[16]->setPos(UNIT * 4, row2);
  block[17]->setPos(UNIT * 5, row2);
  block[18]->setPos(UNIT * 6, row2);
  block[19]->setPos(UNIT * 7, row2);
  block[20]->setPos(UNIT * 8, row2);
  box[0]->setPos(UNIT * 2, row2);
  box[1]->setPos(UNIT * 3, row2);

  //row3
  int row3 = UNIT * 3;
  block[21]->setPos(0, row3);
  block[22]->setPos(UNIT * 4, row3);
  block[23]->setPos(UNIT*5., row3);
  block[24]->setPos(UNIT * 6, row3);
  block[25]->setPos(UNIT * 8, row3);
  box[2]->setPos(UNIT * 2, row3);
  spot[0]->setPos(UNIT * 7, row3);

  //row4
  int row4 = UNIT * 4;
  block[26]->setPos(0, row4);
  block[27]->setPos(UNIT * 1, row4);
  block[28]->setPos(UNIT * 2, row4);
  block[29]->setPos(UNIT * 4, row4);
  block[30]->setPos(UNIT * 5, row4);
  block[31]->setPos(UNIT * 6, row4);
  block[32]->setPos(UNIT * 8, row4);
  spot[1]->setPos(UNIT * 7, row4);

  //row5
  int row5 = UNIT * 5;
  block[33]->setPos(0, row5);
  block[34]->setPos(UNIT * 1, row5);
  block[35]->setPos(UNIT * 2, row5);
  block[36]->setPos(UNIT * 8, row5);
  spot[2]->setPos(UNIT * 7, row5);

  //row6
  int row6 = UNIT * 6;
  block[37]->setPos(0, row6);
  block[38]->setPos(UNIT, row6);
  block[39]->setPos(UNIT * 5, row6);
  block[40]->setPos(UNIT * 8, row6);

  //row7
  int row7 = UNIT * 7;
  block[41]->setPos(0, row7);
  block[42]->setPos(UNIT, row7);
  block[43]->setPos(UNIT * 5, row7);
  block[44]->setPos(UNIT * 8, row7);

  //row8
  for (int i = 45; i < 54; i++)
  {
    block[i]->setPos(UNIT*(i - 45), UNIT * 8);
  }


  //add items to the scene
  scene->addItem(player);
  for (int i = 0; i < 54; i++)
  {
    scene->addItem(block[i]);
  }
  for (int i = 0; i < 3; i++)
  {
    scene->addItem(box[i]);
    scene->addItem(spot[i]);

  }

  //人物可移动设置
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

}


Map1::~Map1()
{
}
