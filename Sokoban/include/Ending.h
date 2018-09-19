#pragma once
#include<qpushbutton.h>
#include<qobject.h>
#include<qlabel.h>
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
class Ending :
  public QGraphicsScene
{
  Q_OBJECT
public:
  Ending();
  ~Ending();
private:
  QPushButton * btn_level;
  QPushButton *btn_exit;
  QLabel *label_c;
  QLabel *label_l;
  QLabel *label_e;
  QGraphicsView *finalView;
  public slots:
  void create();
  //void close();
  void levelchoose();
};



