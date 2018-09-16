#include "Game.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Map4.h"

#include <QTimer>

Game::Game() {
  LevelPass* passScene = new LevelPass;
  format(passScene);
  setScene(passScene);
  QObject::connect(passScene, SIGNAL(levelPage()), this, SLOT(levelChange()));
  QObject::connect(passScene, SIGNAL(exitSignal()), this, SLOT(close()));
  QObject::connect(passScene, SIGNAL(nextSignal()), this, SLOT(next()));
}


Game::~Game() {

}


void Game::format(QGraphicsScene* newScene) {
  newScene->setSceneRect(0, 0, WIDTH, HEIGHT);
}

void Game::levelChange() {
  LevelChoose* levelPage = new LevelChoose;

  QObject::connect(levelPage, SIGNAL(level1()), this, SLOT(createmap1()));
  QObject::connect(levelPage, SIGNAL(level2()), this, SLOT(createmap2()));
  QObject::connect(levelPage, SIGNAL(level3()), this, SLOT(createmap3()));
  QObject::connect(levelPage, SIGNAL(level4()), this, SLOT(createmap4()));


  format(levelPage);
  setWindowTitle("Levels");
  setScene(levelPage);
}

void Game::createmap1()
{
  preLevel = 1;
  scene1 = new QGraphicsScene();
  Map1 *map1 = new Map1(scene1);
  setScene(scene1);

  show();
}

void Game::createmap2()
{
  preLevel = 2;
  scene2 = new QGraphicsScene();
  Map2 *map2 = new Map2(scene2);
  setScene(scene2);

  QTimer* timer = new QTimer();
  QObject::connect(timer, SIGNAL(timeout()), this, SLOT(pass()));
  timer->start(2000);

  show();
}

void Game::createmap3() {
  preLevel = 3;
  scene3 = new QGraphicsScene();
  Map3 *map3 = new Map3(scene3);
  setScene(scene3);

  show();
}

void Game::createmap4() {
  preLevel = 4;
  scene4 = new QGraphicsScene();
  Map4 *map4 = new Map4(scene4);
  setScene(scene4);

  show();
}

void Game::next() {
  switch (preLevel) {
  case 1:
    createmap2();
    break;
  case 2:
    createmap3();
    break;
  case 3:
    createmap4();
    break;
  }
}

void Game::pass() {
  LevelPass* passScene = new LevelPass;
  format(passScene);
  setScene(passScene);
  QObject::connect(passScene, SIGNAL(levelPage()), this, SLOT(levelChange()));
  QObject::connect(passScene, SIGNAL(exitSignal()), this, SLOT(close()));
  QObject::connect(passScene, SIGNAL(nextSignal()), this, SLOT(next()));
}