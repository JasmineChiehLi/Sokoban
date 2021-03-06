#include "Ending.h"
#include"Top.h"
#include"qwidget.h"
extern Top*top;
Ending::Ending()
{

}
Ending::~Ending()
{
  delete btn_exit;
  delete btn_level;
  delete label_c;
  delete label_e;
  delete label_l;
}

void Ending::create()
{
  //initialize backgroud and scene
  setBackgroundBrush(QBrush(QImage("Resources/wall.jpg")));
  setSceneRect(0, 0, 975, 675);

  //brn_level and pictures
  btn_level = new QPushButton();
  btn_level->setGeometry(450, 370, 186, 74);
  btn_level->setText("level");
  btn_level->setFont(QFont("impact", 14));
  btn_level->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalE.png);background:transparent;}""QPushButton:hover{border-image:url(Resources/ButtonHoverE.png);background:transparent;}""QPushButton:pressed{border-image:url(Resources/ButtonPressedE.png);background:transparent;}");
  addWidget(btn_level);

  label_l = new QLabel();
  label_l->setGeometry(540, 295, 75, 75);
  label_l->setStyleSheet("QLabel{border-image:url(Resources/Player_R.png);background:transparent;}");
  addWidget(label_l);

  //btn_exit and pictures
  btn_exit = new QPushButton();
  btn_exit->setGeometry(320, 470, 186, 74);
  btn_exit->setText("exit");
  btn_exit->setFont(QFont("impact", 14));
  btn_exit->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormalLE.png);background:transparent;}""QPushButton:hover{border-image:url(Resources/ButtonHoverLE.png);background:transparent;}""QPushButton:pressed{border-image:url(Resources/ButtonPressedLE.png);background:transparent;}");
  addWidget(btn_exit);
  label_e = new QLabel();
  label_e->setGeometry(340, 395, 75, 75);
  label_e->setStyleSheet("QLabel{border-image:url(Resources/Player_L.png);background:transparent;}");
  addWidget(label_e);

  //label_congrats
  label_c = new QLabel();
  label_c->setGeometry(237.5, 30, 500, 250);
  label_c->setAlignment(Qt::AlignCenter);
  label_c->setStyleSheet("QLabel{border-image:url(Resources/congrats.png);background:transparent;}");
  addWidget(label_c);

  finalView = new QGraphicsView(this);
  finalView->show();
  QObject::connect(btn_exit, SIGNAL(clicked()), finalView, SLOT(close()));
  QObject::connect(btn_level, SIGNAL(clicked()), this, SLOT(levelchoose()));
}


void Ending::levelchoose()
{
  QGraphicsScene* scene = new QGraphicsScene();
  top->c = new LevelChoose(scene, 3);
  top->c->show();

  finalView->close();
}