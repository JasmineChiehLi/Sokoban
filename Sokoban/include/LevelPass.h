#pragma once
#include <QGraphicsScene>
//#include <QGraphicsWidget>
#include <QPushButton>
/*#include <QGraphicsLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsGridLayout>*/
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

signals:
  void levelPage();

signals:
  void exitSignal();

private:
};
