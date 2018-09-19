#include "Map1.h"
#include<qbrush.h>
#include"Top.h"
#include"parameter.h"
#define unit 75
extern Top * top;

Map1::Map1() {

}

Map1::Map1(QGraphicsScene *scene) { //这里是一个指针，传进来的是scene1 

	sit[0] = 75;
	sit[1] = 75;   //1
	sit[2] = 150;
	sit[3] = 150;   //2
	sit[4] = 225;
	sit[5] = 150;   //3
	sit[6] = 150;
	sit[7] = 225;   //4

	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
	scene->setBackgroundBrush(QBrush(QImage("Resources/Floor.png")));

	//create the map

	//block*54,player*1,,box*3
	for (int i = 0; i < 54; i++)
	{
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0; i < 3; i++)
	{
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	int boxesNumber = 3;

	//row0
	for (int i = 0; i < 9; i++)
	{
		block[i]->setPos(unit*i, 0);
	}
	//row1
	int row1 = unit;
	block[9]->setPos(0, row1);
	block[10]->setPos(unit * 4, row1);
	block[11]->setPos(unit * 5, row1);
	block[12]->setPos(unit * 6, row1);
	block[13]->setPos(unit * 7, row1);
	block[14]->setPos(unit * 8, row1);
	player->setPos(unit, row1);

	//row2
	int row2 = unit * 2;
	block[15]->setPos(0, row2);
	block[16]->setPos(unit * 4, row2);
	block[17]->setPos(unit * 5, row2);
	block[18]->setPos(unit * 6, row2);
	block[19]->setPos(unit * 7, row2);
	block[20]->setPos(unit * 8, row2);
	box[0]->setPos(unit * 2, row2);
	box[1]->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	block[21]->setPos(0, row3);
	block[22]->setPos(unit * 4, row3);
	block[23]->setPos(unit*5., row3);
	block[24]->setPos(unit * 6, row3);
	block[25]->setPos(unit * 8, row3);
	box[2]->setPos(unit * 2, row3);
	spot[0]->setPos(unit * 7, row3);

	//row4
	int row4 = unit * 4;
	block[26]->setPos(0, row4);
	block[27]->setPos(unit * 1, row4);
	block[28]->setPos(unit * 2, row4);
	block[29]->setPos(unit * 4, row4);
	block[30]->setPos(unit * 5, row4);
	block[31]->setPos(unit * 6, row4);
	block[32]->setPos(unit * 8, row4);
	spot[1]->setPos(unit * 7, row4);

	//row5
	int row5 = unit * 5;
	block[33]->setPos(0, row5);
	block[34]->setPos(unit * 1, row5);
	block[35]->setPos(unit * 2, row5);
	block[36]->setPos(unit * 8, row5);
	spot[2]->setPos(unit * 7, row5);

	//row6
	int row6 = unit * 6;
	block[37]->setPos(0, row6);
	block[38]->setPos(unit, row6);
	block[39]->setPos(unit * 5, row6);
	block[40]->setPos(unit * 8, row6);

	//row7
	int row7 = unit * 7;
	block[41]->setPos(0, row7);
	block[42]->setPos(unit, row7);
	block[43]->setPos(unit * 5, row7);
	block[44]->setPos(unit * 8, row7);

	//row8
	for (int i = 45; i < 54; i++) {
		block[i]->setPos(unit*(i - 45), unit * 8);
	}


	//add items to the scene
	scene->addItem(player);
	for (int i = 0; i < 54; i++) {
		scene->addItem(block[i]);
	}
	for (int i = 0; i < 3; i++) {
		scene->addItem(box[i]);
		scene->addItem(spot[i]);

	}
	//鼠标控制按钮设置
	button[0] = new QPushButton("Up");
	button[1] = new QPushButton("Down");
	button[2] = new QPushButton("Left");
	button[3] = new QPushButton("Right");
	button[4] = new QPushButton("Restart");

	button[0]->setGeometry(750, 525, 75, 75);
	button[1]->setGeometry(750, 600, 75, 75);
	button[2]->setGeometry(675, 600, 75, 75);
	button[3]->setGeometry(825, 600, 75, 75);
	button[4]->setGeometry(825, 525, 75, 75);

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
	scene->addItem(step);//步数要放在最后创建

	Boxes::boxNum = 3;//决定推几个箱子到位就算赢

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
	scene_->addWidget(so);

}


Map1::~Map1() {
}


//以下是鼠标控制槽函数
void Map1::Player_Up() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->up();
}

void Map1::Player_Down() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->down();
}

void Map1::Player_Right() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->right();
}

void Map1::Player_Left() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->left();
}

//重新开始功能，地图重画，数据归零
void Map1::Player_Restart() {
	int boxesNumber = 3;

	int row1 = unit;
	player->setPos(unit, row1);

	//row2
	int row2 = unit * 2;
	box[0]->setPos(unit * 2, row2);
	box[1]->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	box[2]->setPos(unit * 2, row3);

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


void Map1::pen() { //将原来的状态输出，达到last-step的作用
	if (flag > 2)
	{
		player->setPos(sit[0 + (flag - 2) * 8], sit[1 + (flag - 2) * 8]);
		box[0]->setPos(sit[2 + (flag - 3) * 8], sit[3 + (flag - 3) * 8]);
		box[1]->setPos(sit[4 + (flag - 3) * 8], sit[5 + (flag - 3) * 8]);
		box[2]->setPos(sit[6 + (flag - 3) * 8], sit[7 + (flag - 3) * 8]);
		flag--;
	}
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}


void Map1::receivePos() { //存储信息的函数，将坐标存储进数组
	sit[0 + flag * 8] = player->pos().x();
	sit[1 + flag * 8] = player->pos().y();
	sit[2 + flag * 8] = box[0]->pos().x();
	sit[3 + flag * 8] = box[0]->pos().y();
	sit[4 + flag * 8] = box[1]->pos().x();
	sit[5 + flag * 8] = box[1]->pos().y();
	sit[6 + flag * 8] = box[2]->pos().x();
	sit[7 + flag * 8] = box[2]->pos().y();

	flag++;
}