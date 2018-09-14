#include "Game.h"
#include "Map1.h"

Game::Game() {
  LevelPass* passScene = new LevelPass;
  format(passScene);
  setScene(passScene);
  QObject::connect(passScene, SIGNAL(levelPage()), this, SLOT(levelChange()));
  QObject::connect(passScene, SIGNAL(exitSignal()), this, SLOT(close()));
}


Game::~Game() {

}


void Game::format(QGraphicsScene* newScene) {
  newScene->setSceneRect(0, 0, WIDTH, HEIGHT);
}

void Game::levelChange() {
  LevelChoose* levelPage = new LevelChoose;

  QObject::connect(levelPage, SIGNAL(level1()), this, SLOT(createmap1()));

  format(levelPage);
  setWindowTitle("Levels");
  setScene(levelPage);
}

void Game::createmap1()
{
  scene1 = new QGraphicsScene();
  Map1 *map1 = new Map1(scene1);
  setScene(scene1);

  show();
}