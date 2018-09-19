#include "Map4.h"
#define unit 75
extern int boxesNumber;
//
Map4::Map4()
{

}
Map4::Map4(QGraphicsScene *scene)
{

	sit[0] = 150;
	sit[1] = 450;   //1
	sit[2] = 225;
	sit[3] = 225;   //2
	sit[4] = 150;
	sit[5] = 300;   //3
	sit[6] = 450;
	sit[7] = 300;   //4
	sit[8] = 150;
	sit[9] = 375;
	sit[10] = 300;
	sit[11] = 375;
	sit[12] = 450;
	sit[13] = 375;

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
  QFont mouse;
  mouse.setFamily("Impact");
  mouse.setPointSize(20);

  button[0]->setFont(mouse);
  button[1]->setFont(mouse);
  button[2]->setFont(mouse);
  button[3]->setFont(mouse);
  button[4]->setFont(mouse);

	button[0] = new QPushButton("Up");
	button[1] = new QPushButton("Down");
	button[2] = new QPushButton("Left");
	button[3] = new QPushButton("Right");
	button[4] = new QPushButton("Restart");

	button[0]->setGeometry(750, 525, 100, 75);
	button[1]->setGeometry(750, 600, 100, 75);
	button[2]->setGeometry(675, 600, 100, 75);
	button[3]->setGeometry(825, 600, 100, 75);
	button[4]->setGeometry(825, 525, 100, 75);

	button[0]->setStyleSheet("background:transparent;}");
	button[1]->setStyleSheet("background:transparent;}");
	button[2]->setStyleSheet("background:transparent;}");
	button[3]->setStyleSheet("background:transparent;}");
	button[4]->setStyleSheet("background:transparent;}");

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
	scene->addItem(step);

	Boxes::boxNum = 6;

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	QObject::connect(player, SIGNAL(countbox()), this, SLOT(receivePos()));  //一个信号槽，放进地图cpp的地图函数里面


	QPushButton* so = new QPushButton("lastStep");
	so->setGeometry(675, 525, 75, 75);
	QFont* font = new QFont();
	font->setFamily("Impact");                                               //last_step的按钮
	font->setPointSize(20);
	so->setStyleSheet("background:transparent;}");
	QObject::connect(so, SIGNAL(clicked()), this, SLOT(pen()));
	scene->addWidget(so);

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
		QBrush brush_Box(QImage("Resources/box.png"));
		box[i]->setBrush(brush_Box);
    box[i]->reStart();
	}

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	Boxes::count = 0;
	step->setStep(0);
}


void Map4::pen()    //将原来的状态输出，达到last-step的作用
{
	if (flag > 2)
	{
		player->setPos(sit[0 + (flag - 2) * 14], sit[1 + (flag - 2) * 14]);
		box[0]->setPos(sit[2 + (flag - 3) * 14], sit[3 + (flag - 3) * 14]);
		box[1]->setPos(sit[4 + (flag - 3) * 14], sit[5 + (flag - 3) * 14]);
		box[2]->setPos(sit[6 + (flag - 3) * 14], sit[7 + (flag - 3) * 14]);
		box[3]->setPos(sit[8 + (flag - 3) * 14], sit[9 + (flag - 3) * 14]);
		box[4]->setPos(sit[10 + (flag - 3) * 14], sit[11 + (flag - 3) * 14]);
		box[5]->setPos(sit[12 + (flag - 3) * 14], sit[13 + (flag - 3) * 14]);

		flag--;
	}
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}


void Map4::receivePos()   //存储信息的函数，将坐标存储进数组
{
	sit[0 + flag * 14] = player->pos().x();
	sit[1 + flag * 14] = player->pos().y();
	sit[2 + flag * 14] = box[0]->pos().x();
	sit[3 + flag * 14] = box[0]->pos().y();
	sit[4 + flag * 14] = box[1]->pos().x();
	sit[5 + flag * 14] = box[1]->pos().y();
	sit[6 + flag * 14] = box[2]->pos().x();
	sit[7 + flag * 14] = box[2]->pos().y();
	sit[8 + flag * 14] = box[3]->pos().x();
	sit[9 + flag * 14] = box[3]->pos().y();
	sit[10 + flag * 14] = box[4]->pos().x();
	sit[11 + flag * 14] = box[4]->pos().y();
	sit[12 + flag * 14] = box[5]->pos().x();
	sit[13 + flag * 14] = box[5]->pos().y();


	flag++;
}