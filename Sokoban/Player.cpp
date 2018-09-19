#include "Player.h"
#include"Step.h"
#include"Top.h"
#include "Block.h"
#include"qsound.h"

extern Top * top;
Player::Player()
{
	setRect(0, 0, playerSize, playerSize);//创建人物
	QBrush brush_player(QImage("Resources/Player_D.png"));
	setBrush(brush_player);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
}

void Player::arrival(Boxes * box)
{
	box->isArrival();//每走一步都触发判断箱子目前状态的函数
}

void Player::keyPressEvent(QKeyEvent * event)
{
	{
		if (event->key() == Qt::Key_Left)//当按下按键时
		{
			left();//执行相应函数
			QSound::play("Resources/move.wav");//同时播放移动音效
		}//其它几个按键同理
		else if (event->key() == Qt::Key_Right)
		{
			right();
			QSound::play("Resources/move.wav");

		}
		else if (event->key() == Qt::Key_Up)
		{
			up();
			QSound::play("Resources/move.wav");

		}
		else if (event->key() == Qt::Key_Down)
		{
			down();
			QSound::play("Resources/move.wav");

		}
	}
}

void Player::left()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();//检测与玩家的碰撞
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{

		if (typeid(*(colliding_item1[i])) == typeid(Boxes))//如果玩家与箱子发生了碰撞
		{
			//scene()->removeItem(this);//图片情况下是发生了碰撞的

			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//在检测在这种情况下与箱子的碰撞
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{//还差一个箱子撞箱子
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))//如果箱子与障碍物又有接触
				{/*如果有障碍物
					阻挡箱子的推动则人是不能继续前进的,下述就是 障碍物-箱子-人，施力方向向左的情况*/
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + playerSize
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() + playerSize == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() + stepLength, y());//走不动时，会加上相反的坐标，以抵消数值
						if (top->view1 != nullptr)//走不动时会减去相应的步数，以抵消数值
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() + playerSize == (pos().x())
				&& colliding_item1[i]->pos().y() == (pos().y()))//人从箱子右侧推
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - stepLength, colliding_item1[i]->pos().y());
				emit countbox();
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() + playerSize == (pos().x())//人从障碍物右侧推
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() + stepLength, y());
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_L(QImage("Resources/Player_L.png"));//在每按下键的同时更换朝向图片，同样用setBrush函数
	setBrush(brush_L);
	setPos(x() - stepLength, y());
	emit countbox();
	if (top->view1 != nullptr)//人物移动完会加上相应的步数
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)//当推到位的箱子数与每一关的标准一样时，弹出对话框
		top->messagebox = new MessageBox();
}
//人物向右移动
void Player::right()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() + playerSize == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() == (pos().x() + playerSize)
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() - stepLength, y());
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//人从箱子左侧推
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + stepLength, colliding_item1[i]->pos().y());
				emit countbox();
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//人从障碍物左侧推
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() - stepLength, y());
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_R(QImage("Resources/Player_R.png"));
	setBrush(brush_R);
	setPos(x() + stepLength, y());
	emit countbox();
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}
//人物向上移动
void Player::up()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + playerSize
						&& colliding_item1[i]->pos().x() == (pos().x())
						&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
					{
						setPos(x(), y() + stepLength);
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子下面推
				&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - stepLength);
				emit countbox();
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() + playerSize == (pos().y())//人从障碍物下面推
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() + stepLength);
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_U(QImage("Resources/Player_U.png"));
	setBrush(brush_U);
	setPos(x(), y() - stepLength);
	emit countbox();
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}
//人物向下移动
void Player::down()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() + playerSize == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
					{
						setPos(x(), y() - stepLength);
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子上面推
				&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + stepLength);
				emit countbox();
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() == (pos().y() + playerSize)//人从障碍物上面推
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() - stepLength);
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_D(QImage("Resources/Player_D.png"));
	setBrush(brush_D);
	setPos(x(), y() + stepLength);
	emit countbox();
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}
Player::~Player()
{
}
