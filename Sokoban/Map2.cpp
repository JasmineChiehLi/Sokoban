#include "Map2.h"
#define unit 75

Map2::Map2()
{

}

Map2::Map2(QGraphicsScene *scene)
{
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, 975, 675);

	//create the map

	//block*55,player*1,,box*3
	for (int i = 0;i <57;i++)
	{
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0;i < 3;i++)
	{
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	//row0
	for (int i = 0;i < 9;i++)
	{
		block[i]->setPos(unit*i, 0);
	}
	
	//row1
	int row1 = unit;
	for (int i = 9;i < 15;i++)
	{
		block[i]->setPos(unit*(i - 9), row1);
	}
	block[15]->setPos(unit * 8, row1);
	block[55]->setPos(unit * 6, row1);
	block[56]->setPos(unit * 7, row1);

	//row2
	int row2 = unit * 2;
	for (int i = 16;i < 19;i++)
	{
		block[i]->setPos(unit*(i - 16), row2);
	}
	for (int i = 19;i < 23;i++)
	{
		block[i]->setPos(unit*(i - 14), row2);
	}
	player->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	for (int i = 23;i < 26;i++)
	{
		block[i]->setPos(unit*(i - 23), row3);
	}
	box[0]->setPos(unit * 4, row3);
	block[26]->setPos(unit * 7, row3);
	block[27]->setPos(unit * 8, row3);

	//row4
	int row4 = unit * 4;
	for (int i = 28;i < 32;i++)
	{
		block[i]->setPos(unit*(i - 28), row4);
	}
	block[32]->setPos(unit * 5, row4);
	block[33]->setPos(unit * 7, row4);
	block[34]->setPos(unit * 8, row4);

	//row5
	int row5 = unit * 5;
	block[35]->setPos(0, row5);
	block[36]->setPos(unit, row5);
	block[37]->setPos(unit * 5, row5);
	block[38]->setPos(unit * 8, row5);
	spot[0]->setPos(unit * 2, row5);

	//row6
	int row6 = unit * 6;
	block[39]->setPos(0, row6);
	block[40]->setPos(unit, row6);
	block[41]->setPos(unit * 6, row6);
	block[42]->setPos(unit * 8, row6);
	spot[1]->setPos(unit * 2, row6);
	box[1]->setPos(unit * 3, row6);

	//row7
	int row7 = unit * 7;
	block[43]->setPos(0, row7);
	block[44]->setPos(unit, row7);
	block[45]->setPos(unit * 8, row7);
	spot[2]->setPos(unit * 2, row7);
	box[2]->setPos(unit * 6, row7);

	//row8
	int row8 = unit * 8;
	for (int i = 46;i < 55;i++)
	{
		block[i]->setPos(unit*(i - 46), row8);
	}

	//add items to the scene
	scene->addItem(player);
	for (int i = 0;i < 57;i++)
	{
		scene->addItem(block[i]);
	}
	for (int i = 0;i < 3;i++)
	{
		scene->addItem(box[i]);
		scene->addItem(spot[i]);

	}

}


Map2::~Map2()
{
}
