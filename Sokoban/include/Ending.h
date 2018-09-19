#pragma once
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

class Ending :
	public QGraphicsScene
{
	Q_OBJECT
public:
	Ending();
	~Ending();

private:
	QPushButton *btn_level;
	QPushButton *btn_exit;
	QLabel *label_c;
	QLabel *label_l;
	QLabel *label_e;

public slots:
	void create();
};

