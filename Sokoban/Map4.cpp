#include "Map4.h"


Map4::Map4()
{

}
Map4::Map4(QGraphicsScene *scene)
{
  //initialize the scene
  scene_ = scene;
  scene->setBackgroundBrush(QImage("Resources/Floor.jpg"));
  scene->setSceneRect(0, 0, 975, 675);

  //create the map

  //block*52,player*1,,box*3
  for (int i = 0; i <52; i++)
  {
    block[i] = new Block();
  }
  player = new Player();
  for (int i = 0; i < 6; i++)
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
  for (int i = 9; i < 18; i++)
  {
    block[i]->setPos(UNIT*(i - 9), UNIT);
  }

  //row2
  int row2 = UNIT * 2;
  block[18]->setPos(0, row2);
  block[19]->setPos(UNIT * 7, row2);
  block[20]->setPos(UNIT * 8, row2);
  for (int i = 0; i < 6; i++)
  {
    spot[i]->setPos(UNIT*(i + 1), row2);
  }

  //row3
  int row3 = UNIT * 3;
  block[21]->setPos(0, row3);
  block[22]->setPos(UNIT * 5, row3);
  block[23]->setPos(UNIT * 7, row3);
  block[24]->setPos(UNIT * 8, row3);
  box[0]->setPos(UNIT * 3, row3);

  //row4
  int row4 = UNIT * 4;
  block[25]->setPos(0, row4);
  block[26]->setPos(UNIT * 4, row4);
  block[27]->setPos(UNIT * 8, row4);
  box[1]->setPos(UNIT * 2, row4);
  box[2]->setPos(UNIT * 6, row4);

  //row5
  int row5 = UNIT * 5;
  block[28]->setPos(0, row5);
  block[29]->setPos(UNIT, row5);
  block[30]->setPos(UNIT * 8, row5);
  box[3]->setPos(UNIT * 2, row5);
  box[4]->setPos(UNIT * 4, row5);
  box[5]->setPos(UNIT * 6, row5);

  //row6
  int row6 = UNIT * 6;
  block[31]->setPos(0, row6);
  block[32]->setPos(UNIT, row6);
  block[33]->setPos(UNIT * 8, row6);
  player->setPos(UNIT * 2, row6);

  //row7
  for (int i = 34; i < 43; i++)
  {
    block[i]->setPos(UNIT*(i - 34), UNIT * 7);
  }

  //row8
  for (int i = 43; i < 52; i++)
  {
    block[i]->setPos(UNIT*(i - 43), UNIT * 8);
  }

  //add items to the scene
  scene->addItem(player);
  for (int i = 0; i < 52; i++)
  {
    scene->addItem(block[i]);
  }

  for (int i = 0; i < 6; i++)
  {
    scene->addItem(box[i]);
    scene->addItem(spot[i]);

  }

  //人物可移动设置
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

}


Map4::~Map4()
{
}
