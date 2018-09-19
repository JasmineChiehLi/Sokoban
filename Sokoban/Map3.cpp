#include "Map3.h"
#define unit 75
//
Map3::Map3() {

}

Map3::Map3(QGraphicsScene *scene) {

	sit[0] = 225;
	sit[1] = 450;   //1
	sit[2] = 150;
	sit[3] = 225;   //2
	sit[4] = 225;
	sit[5] = 225;   //3
	sit[6] = 300;
	sit[7] = 225;   //4
	sit[8] = 450;
	sit[9] = 375;


	scene_ = scene;
	scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
	scene->setBackgroundBrush(QBrush(QImage("Resources/Floor.png")));
	//create the map

	//block*54,player*1,,box*3
	for (int i = 0; i < 56; i++) {
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0; i < 4; i++) {
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	int boxesNumber = 4;

	//row0
	for (int i = 0; i < 9; i++) {
		block[i]->setPos(unit*i, 0);
	}

	//row1
	for (int i = 9; i < 18; i++) {
		block[i]->setPos(unit*(i - 9), unit);
	}

	//row2
	int row2 = unit * 2;
	block[18]->setPos(0, row2);
	for (int i = 19; i < 22; i++) {
		block[i]->setPos(unit*(i - 13), row2);
	}

	//row3
	int row3 = unit * 3;
	block[22]->setPos(0, row3);
	for (int i = 23; i < 27; i++) {
		block[i]->setPos(unit*(i - 18), row3);
	}
	for (int i = 0; i < 3; i++) {
		box[i]->setPos(unit*(i + 2), row3);
	}

	//row4
	int row4 = unit * 4;
	block[27]->setPos(0, row4);
	block[28]->setPos(unit * 3, row4);
	for (int i = 29; i < 32; i++) {
		block[i]->setPos(unit*(i - 23), row4);
	}
	spot[0]->setPos(unit * 4, row4);
	spot[1]->setPos(unit * 5, row4);

	//row5
	int row5 = unit * 5;
	block[32]->setPos(0, row5);
	block[33]->setPos(unit, row5);
	block[34]->setPos(unit * 8, row5);
	spot[2]->setPos(unit * 4, row5);
	spot[3]->setPos(unit * 5, row5);
	box[3]->setPos(unit * 6, row5);

	//row6
	int row6 = unit * 6;
	block[35]->setPos(0, row6);
	block[36]->setPos(unit, row6);
	block[37]->setPos(unit * 8, row6);
	player->setPos(unit * 3, row6);

	//row7
	int row7 = unit * 7;
	for (int i = 38; i < 47; i++) {
		block[i]->setPos(unit*(i - 38), row7);
	}

	//row8
	int row8 = unit * 8;
	for (int i = 47; i < 56; i++) {
		block[i]->setPos(unit*(i - 47), row8);
	}

	//add items to the scene
	scene->addItem(player);
	for (int i = 0; i < 57; i++) {
		scene->addItem(block[i]);
	}
	for (int i = 0; i < 4; i++) {
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

	Boxes::boxNum = 4;

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


Map3::~Map3() {
}
//鼠标控制槽函数
void Map3::Player_Up() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->up();
}

void Map3::Player_Down() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->down();
}

void Map3::Player_Right() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->right();
}

void Map3::Player_Left() {
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->left();
}

void Map3::Player_Restart() {
	int boxesNumber = 4;
	int row3 = unit * 3;
	for (int i = 0; i < 3; i++) {
		box[i]->setPos(unit*(i + 2), row3);
	}

	//row5
	int row5 = unit * 5;
	box[3]->setPos(unit * 6, row5);

	//row6
	int row6 = unit * 6;
	player->setPos(unit * 3, row6);

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

void Map3::pen() {  //将原来的状态输出，达到last-step的作用 
	if (flag > 2) {
		player->setPos(sit[0 + (flag - 2) * 10], sit[1 + (flag - 2) * 10]);
		box[0]->setPos(sit[2 + (flag - 3) * 10], sit[3 + (flag - 3) * 10]);
		box[1]->setPos(sit[4 + (flag - 3) * 10], sit[5 + (flag - 3) * 10]);
		box[2]->setPos(sit[6 + (flag - 3) * 10], sit[7 + (flag - 3) * 10]);
		box[3]->setPos(sit[8 + (flag - 3) * 10], sit[9 + (flag - 3) * 10]);
		flag--;
	}
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}


void Map3::receivePos() {   //存储信息的函数，将坐标存储进数组
	sit[0 + flag * 10] = player->pos().x();
	sit[1 + flag * 10] = player->pos().y();
	sit[2 + flag * 10] = box[0]->pos().x();
	sit[3 + flag * 10] = box[0]->pos().y();
	sit[4 + flag * 10] = box[1]->pos().x();
	sit[5 + flag * 10] = box[1]->pos().y();
	sit[6 + flag * 10] = box[2]->pos().x();
	sit[7 + flag * 10] = box[2]->pos().y();
	sit[8 + flag * 10] = box[3]->pos().x();
	sit[9 + flag * 10] = box[3]->pos().y();

	flag++;
}