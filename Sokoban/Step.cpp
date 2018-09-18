#include "Step.h"
#include<QFont>
//

Step::Step(QGraphicsTextItem * parent): QGraphicsTextItem(parent)
{
	step = 0;
	setPlainText(QString("Step: ") + QString::number(step));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times", 30));//设置显示样式
}

void Step::increase()
{
	step++;
	setPlainText(QString("Step: ") + QString::number(step));//增加步数并实时显示
}

int Step::getStep()
{
	return step;
}

void Step::decrease()
{
	step--;//用来实现走不动时不加步的功能
}

Step::~Step()
{
}

void Step::setStep(int newStep)
{
	step = newStep;
	setPlainText(QString("Step: ") + QString::number(step));//更改步数
}
