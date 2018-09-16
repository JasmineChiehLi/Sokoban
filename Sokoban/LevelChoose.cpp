#include "LevelChoose.h"
#include "qsound.h"


LevelChoose::LevelChoose() {
  //initialize the scene
  setSceneRect(0, 0, 975, 675);
  levelChoose();
}

void LevelChoose::levelChoose()
{
  //显示选关界面
  setBackgroundBrush(QBrush(QImage(":/photos/Floor")));



  //显示可以选择关卡按钮
  button1 = new QPushButton("level1");
  button2 = new QPushButton("level2");
  button3 = new QPushButton("level3");
  button4 = new QPushButton("level4");

  button1->setGeometry(QRect(75, 75, 75, 75));
  button2->setGeometry(QRect(150, 75, 75, 75));
  button3->setGeometry(QRect(225, 75, 75, 75));
  button4->setGeometry(QRect(300, 75, 75, 75));

  //button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");  用于加图片
  //button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");
  //button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");
  //button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");

  QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
  QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
  QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));
  QObject::connect(button4, SIGNAL(clicked()), this, SLOT(createmap4()));

  addWidget(button1);
  addWidget(button2);
  addWidget(button3);
  addWidget(button4);

  /*
  QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
  QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
  QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteButton()));
  QObject::connect(button4, SIGNAL(clicked()), this, SLOT(deleteButton()));*/

}

/*void LevelChoose::deleteButton() {
  delete button1;
  delete button2;
  delete button3;
  delete button4;
} */


LevelChoose::~LevelChoose()
{

}

void LevelChoose::createmap1() {
  emit level1();
}

void LevelChoose::createmap2() {
  emit level2();
}

void LevelChoose::createmap3() {
  emit level3();
}

void LevelChoose::createmap4() {
  emit level4();
}