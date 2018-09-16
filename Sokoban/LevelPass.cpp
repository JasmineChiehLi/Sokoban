#include "LevelPass.h"

LevelPass::LevelPass() {
  setSceneRect(0, 0, WIDTH, HEIGHT);
  generalUI();
}

LevelPass::~LevelPass() {

}

void LevelPass::generalUI() {
  QFont* font = new QFont;
  font->setFamily("Impact");
  font->setPointSize(20);

  QPushButton* choose = new QPushButton("Levels");
  QPushButton* exit = new QPushButton("Exit");
  QPushButton* next = new QPushButton("Next");

  next->setFixedHeight(buttonH);
  next->setFixedWidth(buttonW);
  choose->setFixedHeight(buttonH);
  choose->setFixedWidth(buttonW);
  exit->setFixedHeight(buttonH);
  exit->setFixedWidth(buttonW);

  addWidget(next);
  addWidget(choose);
  addWidget(exit);

  QObject::connect(choose, SIGNAL(clicked()), this, SLOT(levelUI()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(exitAct()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(goNext()));

  choose->setFont(*font);
  exit->setFont(*font);
  next->setFont(*font);

  next->setGeometry(720, 440, buttonW, buttonH);
  choose->setGeometry(720, 500, buttonW, buttonH);
  exit->setGeometry(720, 560, buttonW, buttonH);

}

void LevelPass::levelUI() {
  emit levelPage();
}

void LevelPass::exitAct() {
  emit exitSignal();
}

void LevelPass::goNext() {
  emit nextSignal();
}