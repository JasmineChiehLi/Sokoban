#include "Game.h"


//
Game::Game()
{
	userfile = new Userfile(QString("Cys"),QString("1111"));

	scene[0] = new QGraphicsScene();
	scene[0]->setSceneRect(0, 0, sceneWidth,sceneHeight);
	scene[0]->setBackgroundBrush(QBrush(QImage("Resources/Floor.png")));

	scene[1] = new QGraphicsScene();
	scene[1]->setSceneRect(0, 0, sceneWidth, sceneHeight);

	scene[0]->addItem(player);

	box[0] = new Boxes();
	scene[0]->addItem(box[0]);

	box[1] = new Boxes();
	scene[0]->addItem(box[1]);

	block = new Block();
	scene[0]->addItem(block);

	spot = new Spot();
	scene[0]->addItem(spot);

	Spot * spot1 = new Spot();
	scene[0]->addItem(spot1);

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	step = new Step();
	scene[0]->addItem(step);

	view[0] = new QGraphicsView(scene[0]);
	view[0]->setFixedSize(sceneWidth, sceneHeight);
	view[0]->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view[0]->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	button[0] = new QPushButton("Up", view[0]);
	button[1] = new QPushButton("Down", view[0]);
	button[2] = new QPushButton("Left", view[0]);
	button[3] = new QPushButton("Right", view[0]);

	button[0]->setGeometry(800, 700, 100, 100);
	button[1]->setGeometry(800, 900, 100, 100);
	button[2]->setGeometry(700, 800, 100, 100);
	button[3]->setGeometry(900, 800, 100, 100);

	QGraphicsProxyWidget* proxy1 = scene[0]->addWidget(button[0]);
	QGraphicsProxyWidget* proxy2 = scene[0]->addWidget(button[1]);
	QGraphicsProxyWidget* proxy3 = scene[0]->addWidget(button[2]);
	QGraphicsProxyWidget* proxy4 = scene[0]->addWidget(button[3]);

	QObject::connect(button[0], SIGNAL(clicked()), this, SLOT(Player_Up()));
	QObject::connect(button[1], SIGNAL(clicked()), this, SLOT(Player_Down()));
	QObject::connect(button[2], SIGNAL(clicked()), this, SLOT(Player_Left()));
	QObject::connect(button[3], SIGNAL(clicked()), this, SLOT(Player_Right()));

	view[0]->show();

	view[1] = new QGraphicsView(scene[1]);
	view[1]->setFixedSize(sceneWidth, sceneHeight);

	player->setPos(900, 100);
	box[0]->setPos(500, 500);
	block->setPos(200, 200);
	spot->setPos(600, 600);
	box[1]->setPos(700, 700);
	spot1->setPos(500, 700);

}


Game::~Game()
{
}

void Game::Player_Up()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->up();
}
void Game::Player_Down()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->down();
}

void Game::Player_Right()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->right();
}

void Game::Player_Left()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->left();
}

/*void Game::keyPressEvent(QKeyEvent * event)
{
	{
		if (event->key() == Qt::Key_Left)//当按下按键时
		{
			player->left();
		}//其它几个按键同理
		else if (event->key() == Qt::Key_Right)
		{
			player->right();
		}
		else if (event->key() == Qt::Key_Up)
		{
			player->up();
		}
		else if (event->key() == Qt::Key_Down)
		{
			player->down();
		}
	}
}*/