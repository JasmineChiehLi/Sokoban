#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include "LevelPass.h"
#include "LevelChoose.h"

class Game
  :public QGraphicsView
{
  Q_OBJECT
public:
  Game();
  ~Game();
  void format(QGraphicsScene* newScene);

  public slots:
  void levelChange();
  void createmap1();

private:
  QGraphicsScene* scene1 = nullptr;
  /*
  QGraphicsScene* scene2 = nullptr;
  QGraphicsScene* scene3 = nullptr;
  QGraphicsScene* scene4 = nullptr;
  */

};


