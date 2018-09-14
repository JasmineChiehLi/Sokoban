#include "Player.h"

Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
  setRect(0, 0, UNIT, UNIT);
  QBrush brush_D(QImage("Resources//Player_D.png"));
  setBrush(brush_D);
}

void arrival(Boxes* box_) {                   //�ĺ������ڵ���Box�����isArrival����
  box_->isArrival();
}

void Player::keyPressEvent(QKeyEvent* event)
{
  {
    if (event->key() == Qt::Key_Left)//�����°���ʱ
    {
      QList<QGraphicsItem* >colliding_item1 = collidingItems();//�������ҵ���ײ
      for (int i = 0, n = colliding_item1.size(); i < n; i++)
      {

        if (typeid(*(colliding_item1[i])) == typeid(Boxes))//�����������ӷ�������ײ
        {
          //scene()->removeItem(this);//ͼƬ������Ƿ�������ײ��

          QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
          int j = 0, m = 0;
          for (m = colliding_item2.size(); j < m; j++)
          {
            if (typeid(*(colliding_item2[j])) == typeid(Block)
              || typeid(*(colliding_item2[j])) == typeid(Boxes))//����������ϰ������нӴ�
            {/*������ϰ���
             �赲���ӵ��ƶ������ǲ��ܼ���ǰ����,�������� �ϰ���-����-�ˣ�ʩ��������������*/
              if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + UNIT
                && colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
                && colliding_item1[i]->pos().x() + UNIT == (pos().x())
                && colliding_item1[i]->pos().y() == (pos().y())) {
                setPos(x() + UNIT, y());
                continue;
              }
            }
          }
          if (j = m)
            if (colliding_item1[i]->pos().x() + UNIT == (pos().x())
              && colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
            {
              colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - UNIT, colliding_item1[i]->pos().y());
              arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
            }

        }
        else if (typeid(*(colliding_item1[i])) == typeid(Block))
        {
          if (colliding_item1[i]->pos().x() + UNIT == (pos().x())//�˴��ϰ����Ҳ���
            && colliding_item1[i]->pos().y() == (pos().y()))
            setPos(x() + UNIT, y());
        }
      }
      QBrush brush_L(QImage("Resources\\Player_L.png"));//��ÿ���¼���ͬʱ��������ͼƬ��ͬ����setBrush����
      setBrush(brush_L);
      setPos(x() - UNIT, y());
      QSound::play("Resources\\Move.wav");                     //�����������Ʒ�
    }//������������ͬ��
    else if (event->key() == Qt::Key_Right)
    {
      QList<QGraphicsItem* >colliding_item1 = collidingItems();
      for (int i = 0, n = colliding_item1.size(); i < n; i++)
      {
        if (typeid(*(colliding_item1[i])) == typeid(Boxes))
        {
          QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
          int j = 0, m = 0;
          for (m = colliding_item2.size(); j < m; j++)
          {
            if (typeid(*(colliding_item2[j])) == typeid(Block)
              || typeid(*(colliding_item2[j])) == typeid(Boxes))
            {
              if (colliding_item1[i]->pos().x() + UNIT == colliding_item2[j]->pos().x()
                && colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
                && colliding_item1[i]->pos().x() == (pos().x() + UNIT)
                && colliding_item1[i]->pos().y() == (pos().y())) {
                setPos(x() - UNIT, y());
                continue;
              }
            }
          }
          if (j = m)
            if (colliding_item1[i]->pos().x() == (pos().x() + UNIT)//�˴����������
              && colliding_item1[i]->pos().y() == (pos().y()))
            {
              colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + UNIT, colliding_item1[i]->pos().y());
              arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
            }

        }
        else if (typeid(*(colliding_item1[i])) == typeid(Block))
        {
          if (colliding_item1[i]->pos().x() == (pos().x() + UNIT)//�˴��ϰ��������
            && colliding_item1[i]->pos().y() == (pos().y()))
            setPos(x() - UNIT, y());
        }
      }
      QBrush brush_R(QImage("Resources\\Player_R.png"));
      setBrush(brush_R);
      setPos(x() + UNIT, y());
      QSound::play("Resources\\Move.wav");
    }
    else if (event->key() == Qt::Key_Up)
    {
      QList<QGraphicsItem* >colliding_item1 = collidingItems();
      for (int i = 0, n = colliding_item1.size(); i < n; i++)
      {
        if (typeid(*(colliding_item1[i])) == typeid(Boxes))
        {
          QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
          int j = 0, m = 0;
          for (m = colliding_item2.size(); j < m; j++)
          {
            if (typeid(*(colliding_item2[j])) == typeid(Block)
              || typeid(*(colliding_item2[j])) == typeid(Boxes))
            {
              if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
                && colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + UNIT
                && colliding_item1[i]->pos().x() == (pos().x())
                && colliding_item1[i]->pos().y() + UNIT == (pos().y())) {
                setPos(x(), y() + UNIT);
                continue;
              }
            }
          }
          if (j = m)
            if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
              && colliding_item1[i]->pos().y() + UNIT == (pos().y()))
            {
              colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - UNIT);
              arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
            }
        }
        else if (typeid(*(colliding_item1[i])) == typeid(Block))
        {
          if (colliding_item1[i]->pos().y() + UNIT == (pos().y())//�˴��ϰ���������
            && colliding_item1[i]->pos().x() == (pos().x()))
            setPos(x(), y() + UNIT);
        }
      }
      QBrush brush_U(QImage("Resources\\Player_U.png"));
      setBrush(brush_U);
      setPos(x(), y() - UNIT);
      QSound::play("Resources\\Move.wav");
    }
    else if (event->key() == Qt::Key_Down)
    {
      QList<QGraphicsItem* >colliding_item1 = collidingItems();
      for (int i = 0, n = colliding_item1.size(); i < n; i++)
      {
        if (typeid(*(colliding_item1[i])) == typeid(Boxes))
        {
          QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
          int j = 0, m = 0;
          for (m = colliding_item2.size(); j < m; j++)
          {
            if (typeid(*(colliding_item2[j])) == typeid(Block)
              || typeid(*(colliding_item2[j])) == typeid(Boxes))
            {
              if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
                && colliding_item1[i]->pos().y() + UNIT == colliding_item2[j]->pos().y()
                && colliding_item1[i]->pos().x() == (pos().x())
                && colliding_item1[i]->pos().y() == (pos().y() + UNIT)) {
                setPos(x(), y() - UNIT);
                continue;
              }
            }
          }
          if (j = m)
            if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
              && colliding_item1[i]->pos().y() == (pos().y() + UNIT))
            {
              colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + UNIT);
              arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
            }
        }
        else if (typeid(*(colliding_item1[i])) == typeid(Block))
        {
          if (colliding_item1[i]->pos().y() == (pos().y() + UNIT)//�˴��ϰ���������
            && colliding_item1[i]->pos().x() == (pos().x()))
            setPos(x(), y() - UNIT);
        }
      }
      QBrush brush_D(QImage("Resources\\Player_D.png"));
      setBrush(brush_D);
      setPos(x(), y() + UNIT);
      QSound::play("Resources\\Move.wav");
    }
  }
}

Player::~Player() {

}