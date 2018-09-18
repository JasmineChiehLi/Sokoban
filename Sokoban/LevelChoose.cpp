#include "LevelChoose.h"
//#include "qsound.h"/
#include"Top.h"
extern Top * top;
LevelChoose::LevelChoose(QGraphicsScene* scene,int level) {
	//initialize the scene
	scene_ = scene;
	level_ = level;
	scene->setSceneRect(0, 0, 1000, 1000);
	setBackgroundBrush(QBrush(QImage("Resources/Floor.png")));

	//去掉滚动栏
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(1000, 1000);
	levelChoose();
}

void LevelChoose::levelChoose()
{
	//显示可以选择关卡按钮
	if (level_ >= 3)//通过第三关时，这样
	{
		button1 = new QPushButton("level1", this);
		button2 = new QPushButton("level2", this);
		button3 = new QPushButton("level3", this);
		button4 = new QPushButton("level4", this);

		button1->setGeometry(QRect(100, 100, 100, 100));
		button2->setGeometry(QRect(300, 100, 100, 100));
		button3->setGeometry(QRect(500, 100, 100, 100));
		button4->setGeometry(QRect(700, 100, 100, 100));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));
		QObject::connect(button4, SIGNAL(clicked()), this, SLOT(createmap4()));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button4, SIGNAL(clicked()), this, SLOT(deleteButton()));
	}

	else if (level_ == 2)//通过第2关时，这样
	{
		button1 = new QPushButton("level1", this);
		button2 = new QPushButton("level2", this);
		button3 = new QPushButton("level3", this);

		button1->setGeometry(QRect(100, 100, 100, 100));
		button2->setGeometry(QRect(300, 100, 100, 100));
		button3->setGeometry(QRect(500, 100, 100, 100));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteButton()));
	}

	else if (level_ == 1)//通过第1关时，这样
	{
		button1 = new QPushButton("level1", this);
		button2 = new QPushButton("level2", this);

		button1->setGeometry(QRect(100, 100, 100, 100));
		button2->setGeometry(QRect(300, 100, 100, 100));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
	}

	else//初玩时，这样
	{
		button1 = new QPushButton("level1", this);
		button1->setGeometry(QRect(100, 100, 100, 100));
		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
	}
}

void LevelChoose::deleteButton() {
	delete button1;
	delete button2;
	delete button3;
	delete button4;
}


LevelChoose::~LevelChoose()
{
	delete scene_;

}
//创建游戏
void LevelChoose::createmap1()
{
	top->scene1 = new QGraphicsScene();
	top->map1 = new Map1(top->scene1);//进入map1
	top->view1 = new QGraphicsView(top->scene1);
	top->view1->show();//地图的显示
	delete this;
}

void LevelChoose::createmap2()
{
	top->scene2 = new QGraphicsScene();
	top->map2 = new Map2(top->scene2);
	top->view2 = new QGraphicsView(top->scene2);
	top->view2->show();
	delete this;
}

void LevelChoose::createmap3()
{
	top->scene3 = new QGraphicsScene();
	top->map3 = new Map3(top->scene3);//进入map1
	top->view3 = new QGraphicsView(top->scene3);
	top->view3->show();//地图的显示
	delete this;
}

void LevelChoose::createmap4()
{
	top->scene4 = new QGraphicsScene();
	top->map4 = new Map4(top->scene4);//进入map1
	top->view4 = new QGraphicsView(top->scene4);
	top->view4->show();//地图的显示
	delete this;
}