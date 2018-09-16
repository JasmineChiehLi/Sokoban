#include "Map3.h"

Map3::Map3()
{

}

Map3::Map3(QGraphicsScene *scene)
{
  //initialize the scene
  scene_ = scene;
  scene->setBackgroundBrush(QImage("Resources/Floor.jpg"));
  scene->setSceneRect(0, 0, 975, 675);

  //create the map

  //block*54,player*1,,box*3
  for (int i = 0; i < 56; i++)
  {
    block[i] = new Block();
  }
  player = new Player();
  for (int i = 0; i < 4; i++)
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
  for (int i = 19; i < 22; i++)
  {
    block[i]->setPos(UNIT*(i - 13), row2);
  }

  //row3
  int row3 = UNIT * 3;
  block[22]->setPos(0, row3);
  for (int i = 23; i < 27; i++)
  {
    block[i]->setPos(UNIT*(i - 18), row3);
  }
  for (int i = 0; i < 3; i++)
  {
    box[i]->setPos(UNIT*(i + 2), row3);
  }

  //row4
  int row4 = UNIT * 4;
  block[27]->setPos(0, row4);
  block[28]->setPos(UNIT * 3, row4);
  for (int i = 29; i < 32; i++)
  {
    block[i]->setPos(UNIT*(i - 23), row4);
  }
  spot[0]->setPos(UNIT * 4, row4);
  spot[1]->setPos(UNIT * 5, row4);

  //row5
  int row5 = UNIT * 5;
  block[32]->setPos(0, row5);
  block[33]->setPos(UNIT, row5);
  block[34]->setPos(UNIT * 8, row5);
  spot[2]->setPos(UNIT * 4, row5);
  spot[3]->setPos(UNIT * 5, row5);
  box[3]->setPos(UNIT * 6, row5);

  //row6
  int row6 = UNIT * 6;
  block[35]->setPos(0, row6);
  block[36]->setPos(UNIT, row6);
  block[37]->setPos(UNIT * 8, row6);
  player->setPos(UNIT * 3, row6);

  //row7
  int row7 = UNIT * 7;
  for (int i = 38; i < 47; i++)
  {
    block[i]->setPos(UNIT*(i - 38), row7);
  }

  //row8
  int row8 = UNIT * 8;
  for (int i = 47; i < 56; i++)
  {
    block[i]->setPos(UNIT*(i - 47), row8);
  }

  //add items to the scene
  scene->addItem(player);
  for (int i = 0; i < 57; i++)
  {
    scene->addItem(block[i]);
  }
  for (int i = 0; i < 4; i++)
  {
    scene->addItem(box[i]);
    scene->addItem(spot[i]);

  }
  //人物可移动设置
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
}


Map3::~Map3()
{
}
