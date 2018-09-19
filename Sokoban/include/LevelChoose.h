#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>
#include <QObject>

#include"Map1.h"
#include"Map2.h"
#include"Map3.h"
#include"Map4.h"

class LevelChoose 
  :public QGraphicsView 
{
	Q_OBJECT
public:
  LevelChoose();
	LevelChoose(QGraphicsScene * scene,int level=0);
	~LevelChoose();

public slots:

	void levelChoose();
	void deleteButton();
	void createmap1();
	void createmap2();
	void createmap3();
	void createmap4();

private:
  int level_;
	QPushButton * button1;
	QPushButton * button2;
	QPushButton * button3;
	QPushButton * button4;
	QGraphicsScene * level;
  QGraphicsScene * scene_;
};

