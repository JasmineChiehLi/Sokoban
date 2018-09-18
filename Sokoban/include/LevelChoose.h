#pragma once
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
#include<qpushbutton.h>
//#include"Map.h"/
#include<QObject>
#include"Map1.h"
#include"Map2.h"
#include"Map3.h"
#include"Map4.h"

class LevelChoose :public QGraphicsView 
{
	Q_OBJECT
public:
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
	QGraphicsScene * scene_;
	int level_;
	QPushButton * button1;
	QPushButton * button2;
	QPushButton * button3;
	QPushButton * button4;
	QGraphicsScene * level;
};

