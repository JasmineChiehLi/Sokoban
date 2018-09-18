#include "Map4.h"
#define unit 75
extern int boxesNumber;
//
Map4::Map4()
{

}
Map4::Map4(QGraphicsScene *scene)
{
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
	scene->setBackgroundBrush(QBrush(QImage("Resources/Floor.png")));
	//create the map

	//block*52,player*1,,box*3
	for (int i = 0; i < 52; i++)
	{
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0; i < 6; i++)
	{
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	int boxesNumber = 6;

	//row0
	for (int i = 0; i < 9; i++)
	{
		block[i]->setPos(unit*i, 0);
	}

	//row1
	for (int i = 9; i < 18; i++)
	{
		block[i]->setPos(unit*(i - 9), unit);
	}

	//row2
	int row2 = unit * 2;
	block[18]->setPos(0, row2);
	block[19]->setPos(unit * 7, row2);
	block[20]->setPos(unit * 8, row2);
	for (int i = 0; i < 6; i++)
	{
		spot[i]->setPos(unit*(i + 1), row2);
	}

	//row3
	int row3 = unit * 3;
	block[21]->setPos(0, row3);
	block[22]->setPos(unit * 5, row3);
	block[23]->setPos(unit * 7, row3);
	block[24]->setPos(unit * 8, row3);
	box[0]->setPos(unit * 3, row3);

	//row4
	int row4 = unit * 4;
	block[25]->setPos(0, row4);
	block[26]->setPos(unit * 4, row4);
	block[27]->setPos(unit * 8, row4);
	box[1]->setPos(unit * 2, row4);
	box[2]->setPos(unit * 6, row4);

	//row5
	int row5 = unit * 5;
	block[28]->setPos(0, row5);
	block[29]->setPos(unit, row5);
	block[30]->setPos(unit * 8, row5);
	box[3]->setPos(unit * 2, row5);
	box[4]->setPos(unit * 4, row5);
	box[5]->setPos(unit * 6, row5);

	//row6
	int row6 = unit * 6;
	block[31]->setPos(0, row6);
	block[32]->setPos(unit, row6);
	block[33]->setPos(unit * 8, row6);
	player->setPos(unit * 2, row6);

	//row7
	for (int i = 34; i < 43; i++)
	{
		block[i]->setPos(unit*(i - 34), unit * 7);
	}

	//row8
	for (int i = 43; i < 52; i++)
	{
		block[i]->setPos(unit*(i - 43), unit * 8);
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

	button[0] = new QPushButton("Up");
	button[1] = new QPushButton("Down");
	button[2] = new QPushButton("Left");
	button[3] = new QPushButton("Right");
	button[4] = new QPushButton("Restart");

	button[0]->setGeometry(800, 700, 100, 100);
	button[1]->setGeometry(800, 900, 100, 100);
	button[2]->setGeometry(700, 800, 100, 100);
	button[3]->setGeometry(900, 800, 100, 100);
	button[4]->setGeometry(800, 800, 100, 100);

	QGraphicsProxyWidget* proxy1 = scene_->addWidget(button[0]);
	QGraphicsProxyWidget* proxy2 = scene_->addWidget(button[1]);
	QGraphicsProxyWidget* proxy3 = scene_->addWidget(button[2]);
	QGraphicsProxyWidget* proxy4 = scene_->addWidget(button[3]);
	QGraphicsProxyWidget* proxy5 = scene_->addWidget(button[4]);

	QObject::connect(button[0], SIGNAL(clicked()), this, SLOT(Player_Up()));
	QObject::connect(button[1], SIGNAL(clicked()), this, SLOT(Player_Down()));
	QObject::connect(button[2], SIGNAL(clicked()), this, SLOT(Player_Left()));
	QObject::connect(button[3], SIGNAL(clicked()), this, SLOT(Player_Right()));
	QObject::connect(button[4], SIGNAL(clicked()), this, SLOT(Player_Restart()));

	step = new Step();
	scene->addItem(step);//步数要放在最后创建

	Boxes::boxNum = 1;

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}


Map4::~Map4()
{
}

void Map4::Player_Up()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->up();
}
void Map4::Player_Down()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->down();
}

void Map4::Player_Right()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->right();
}

void Map4::Player_Left()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->left();
}

void Map4::Player_Restart()
{
	int boxesNumber = 6;
	//row3
	int row3 = unit * 3;
	box[0]->setPos(unit * 3, row3);

	//row4
	int row4 = unit * 4;
	box[1]->setPos(unit * 2, row4);
	box[2]->setPos(unit * 6, row4);

	//row5
	int row5 = unit * 5;
	box[3]->setPos(unit * 2, row5);
	box[4]->setPos(unit * 4, row5);
	box[5]->setPos(unit * 6, row5);

	//row6
	int row6 = unit * 6;
	player->setPos(unit * 2, row6);

	for (int i = 0; i < boxesNumber; i++) {
		QBrush brush_Box(QImage(":/Player_1/Resources/box.png"));
		box[i]->setBrush(brush_Box);
	}

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	Boxes::count = 0;
	step->setStep(0);
}