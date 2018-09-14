#include "LevelChoose.h"
#include "Spot.h"
#include "Block.h"
#include "Boxes.h"
#include "Player.h" //Boxes included
//#include "Map1.h" //Player, Boxes included
//#include "Map.h" //Map1 included


LevelChoose::LevelChoose()
{
  L1 = new QPushButton("Level 1");
  L1->setGeometry(50, 50, buttonW, buttonH);
  addWidget(L1);
}


LevelChoose::~LevelChoose()
{
}
