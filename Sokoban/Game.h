#pragma once
#include <QGraphicsView>
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

private:

};


/*#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>*/

/*class Game
  :public QGraphicsView
{
  Q_OBJECT
public:
  Game();
  ~Game();


  public slots:


private:

};*/

