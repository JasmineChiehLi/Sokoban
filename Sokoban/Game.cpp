#include "Game.h"

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
  format(levelPage);
  setWindowTitle("Levels");
  setScene(levelPage);
}
