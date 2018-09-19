#include "LevelChoose.h"
//#include "qsound.h"
#include"Top.h"
extern Top * top;
LevelChoose::LevelChoose(QGraphicsScene* scene,int level) {
	//initialize the scene
	scene_ = scene;
	level_ = level;
	setScene(scene_);
	scene_->setSceneRect(0, 0, 975, 675);
	scene_->setBackgroundBrush(QBrush(QImage("Resources/wall.jpg")));

	//去掉滚动栏
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(975, 675);
	levelChoose();
}

void LevelChoose::levelChoose() {
	//显示可以选择关卡按钮
	if (level_ >= 3)//通过第三关时，这样
	{
		button1 = new QPushButton("level1", this);
		button2 = new QPushButton("level2", this);
		button3 = new QPushButton("level3", this);
		button4 = new QPushButton("level4", this);

		button1->setGeometry(QRect(75, 500, 200, 75));
		button2->setGeometry(QRect(275, 370, 200, 75));
		button3->setGeometry(QRect(475, 240, 200, 75));
		button4->setGeometry(QRect(675, 100, 200, 75));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));
		QObject::connect(button4, SIGNAL(clicked()), this, SLOT(createmap4()));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button4, SIGNAL(clicked()), this, SLOT(deleteButton()));

		//设置按钮字体和图片
		QFont* font = new QFont;
		font->setFamily("Impact");
		font->setPointSize(20);
		button1->setFont(*font);
		button2->setFont(*font);
		button3->setFont(*font);
		button4->setFont(*font);
		button1->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
					"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
					"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");    //可选关卡的图
		button2->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
		button3->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
		button4->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
		
	}

	else if (level_ == 2)//通过第2关时，这样
	{
		button1 = new QPushButton("level1", this);
		button2 = new QPushButton("level2", this);
		button3 = new QPushButton("level3", this);

		button1->setGeometry(QRect(75, 500, 200, 75));
		button2->setGeometry(QRect(275, 370, 200, 75));
		button3->setGeometry(QRect(475, 240, 200, 75));
		

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteButton()));

		QFont* font = new QFont;
		font->setFamily("Impact");
		font->setPointSize(20);
		button1->setFont(*font);
		button2->setFont(*font);
		button3->setFont(*font);
		button1->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");    //可选关卡的图
    button2->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
		button3->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
	}

	else if (level_ == 1)//通过第1关时，这样
	{
		button1 = new QPushButton("level1", this);
		button2 = new QPushButton("level2", this);

		button1->setGeometry(QRect(75, 500, 200, 75));
		button2->setGeometry(QRect(275, 370, 200, 75));


		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton())); QFont* font = new QFont;
		font->setFamily("Impact");
		font->setPointSize(20);
		button1->setFont(*font);
		button2->setFont(*font);
		button1->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");    //可选关卡的图
		button2->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
	}

	else//初玩时，这样
	{
		button1 = new QPushButton("level1", this);
		button1->setGeometry(QRect(75, 500, 200, 75));

		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
		QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
		QFont* font = new QFont;
		font->setFamily("Impact");
		font->setPointSize(20);
		button1->setFont(*font);
		button1->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}"
			"QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}"
			"QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");    //可选关卡的图
	}
}

void LevelChoose::deleteButton() {
	delete button1;
	delete button2;
	delete button3;
	delete button4;
}


LevelChoose::~LevelChoose() {
	delete scene_;

}
//创建游戏
void LevelChoose::createmap1() {
	top->scene1 = new QGraphicsScene();
	top->map1 = new Map1(top->scene1);//进入map1
	top->view1 = new QGraphicsView(top->scene1);
	top->view1->show();//地图的显示
	delete this;//关掉选关界面
}

void LevelChoose::createmap2() {
	top->scene2 = new QGraphicsScene();
	top->map2 = new Map2(top->scene2);//进入map2
	top->view2 = new QGraphicsView(top->scene2);
	top->view2->show();
	delete this;
}

void LevelChoose::createmap3() {
	top->scene3 = new QGraphicsScene();
	top->map3 = new Map3(top->scene3);//进入map3
	top->view3 = new QGraphicsView(top->scene3);
	top->view3->show();//地图的显示
	delete this;
}

void LevelChoose::createmap4() {
	top->scene4 = new QGraphicsScene();
	top->map4 = new Map4(top->scene4);//进入map4
	top->view4 = new QGraphicsView(top->scene4);
	top->view4->show();//地图的显示
	delete this;
}