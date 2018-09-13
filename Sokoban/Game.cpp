#include "Game.h"

Game::Game() {
  LevelPass* passScene = new LevelPass;
  format(passScene);
  setScene(passScene);
  QObject::connect(passScene, SIGNAL(levelPage()), this, SLOT(levelChange()));
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
