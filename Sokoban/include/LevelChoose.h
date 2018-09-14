#pragma once
#include <QGraphicsScene>
#include <QPushButton>
#include "Parameter.h"

class LevelChoose
  :public QGraphicsScene
{
public:
  LevelChoose();
  ~LevelChoose();

  public slots:
  void goLevel1();

signals:
  void level1();

private:
  QPushButton *L1 = nullptr;
};

