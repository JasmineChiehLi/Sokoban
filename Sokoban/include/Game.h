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
  void pass();

  public slots:
  void levelChange();
  void createmap1();
  void createmap2();
  void createmap3();
  void createmap4();
  void next();

private:
  int preLevel;
  QGraphicsScene* scene1 = nullptr;
  QGraphicsScene* scene2 = nullptr;
  QGraphicsScene* scene3 = nullptr;
  QGraphicsScene* scene4 = nullptr;
};


