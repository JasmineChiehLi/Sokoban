#pragma once
#include <QGraphicsScene>
#include <QPushButton>
#include <QFont>

#include "Parameter.h"

class LevelPass
  :public QGraphicsScene
{
  Q_OBJECT
public:
  LevelPass();
  ~LevelPass();
  void generalUI();

  public slots:
  void levelUI();
  void exitAct();
  void goNext();

signals:
  void levelPage();
  void exitSignal();
  void nextSignal();

private:
};
