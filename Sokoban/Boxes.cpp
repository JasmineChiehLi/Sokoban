#include "Boxes.h"
#include"Top.h"
#include"Userfile.h"
#include"qsound.h"

extern Userfile * userfile;
extern Top * top;
int Boxes::count = 0;//count是静态变量
int Boxes::boxNum = 0;

Boxes::Boxes()
{
  //设置箱子大小及图片
  setRect(0, 0, boxSize, boxSize);
  QBrush brush_box(QImage("Resources/box.png"));
  setBrush(brush_box);
}

void Boxes::isArrival()
{
  //flag2用于存放之前一步的flag,flag1用来表示现在这一步的flag
  flag2 = flag1;
  flag1 = 0;

  //以是否重合判定是否到达
  QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);

  for (int i = 0, n = colliding_items.size(); i < n; ++i)
  {
    if (typeid(*(colliding_items[i])) == typeid(Spot))//当箱子与终点重合时
    {
      //弹出对话框，询问是否进入下一关
      QBrush brush_Box(QImage("Resources/boxF.png"));
      this->setBrush(brush_Box);
      colliding_items[i]->stackBefore(this);
      flag1 = 1;//到终点，falg设为1
    }
  }
  if (flag2 == 1 && flag1 == 0) {//箱子由1变为0时，count--  
    QBrush brush_Box(QImage("Resources/box.png"));
    this->setBrush(brush_Box);
    count--;
  }
  else if (flag2 == 0 && flag1 == 1) //箱子由0变为1时，count++
    count++;
  if (count == boxNum) //将boxNum设为箱子的属性，静态的，让后在地图初始化时重新设置
  {
    QSound::play("Resources/victory.wav"); //播放胜利音效
    if (top->view1 != nullptr) //用非空指针来判断当前关
      userfile->saveScore(1, top->map1->step->getStep()); //将游戏数据存起来,村游戏这一步骤要放在上面
    if (top->view2 != nullptr)
      userfile->saveScore(2, top->map2->step->getStep()); //前面的是level属性，可以传进来
    if (top->view3 != nullptr)
      userfile->saveScore(3, top->map3->step->getStep());
    if (top->view4 != nullptr)
      userfile->saveScore(4, top->map4->step->getStep());
  }
}

bool Boxes::getFlag()
{
  return flag1;
}

Boxes::~Boxes()
{
}

void Boxes::reStart() {
  flag1 = 0;
  flag2 = 0;
  count = 0;
}