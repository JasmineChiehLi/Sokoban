#pragma once
#include <QGraphicsScene>
#include <QPushButton>

class LevelChoose :public QGraphicsScene
{
  Q_OBJECT
public:
  LevelChoose();
  ~LevelChoose();

  public slots:

  void levelChoose();
  //void deleteButton();
  void createmap1();
  void createmap2();
  void createmap3();
  void createmap4();

signals:
  void level1();
  void level2();
  void level3();
  void level4();

private:
  QPushButton* button1;
  QPushButton* button2;
  QPushButton* button3;
  QPushButton* button4;
};

