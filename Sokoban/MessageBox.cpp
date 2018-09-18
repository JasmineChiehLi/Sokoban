#include "MessageBox.h"
#include<cstdlib>
#include"Map1.h"
#include"LevelChoose.h"//
#include"Top.h"
extern Top * top;
MessageBox::MessageBox(QMessageBox * parent) :QMessageBox(parent)
{
	setWindowTitle(QString("Message"));
	setText(QString("Congratulations!"));
	setStandardButtons(QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
	setButtonText(QMessageBox::StandardButton::Ok, QString("continue"));
	setButtonText(QMessageBox::StandardButton::Cancel, QString("quit"));
	exec(); QMessageBox::StandardButton ret = standardButton(clickedButton());
	switch (ret)
	{
	case QMessageBox::Ok:
	{//当一关通过时，创建一个新的选关界面
	 //if (top->userfile->getLevel() != 4)
		QGraphicsScene* ch = new QGraphicsScene();
		LevelChoose * c = new LevelChoose(ch, top->userfile->getLevel());
		//c->show();
		//根据当前哪个显示指针不为空来删除原来的旧地图
		if (top->view1 != nullptr)
		{
			c->show();
			delete top->view1;
			top->view1 = nullptr;
		}//我们在删除一个指针之后，编译器只会释放该指针所指向的内存空间，而不会删除这个指针本身。

		if (top->view2 != nullptr)
		{
			c->show();
			delete top->view2;
			top->view2 = nullptr;
		}

		if (top->view3 != nullptr)
		{
			c->show();
			delete top->view3;
			top->view3 = nullptr;
		}

		if (top->view4 != nullptr)
		{
			delete top->view4;
			top->view4 = nullptr;
			delete c;
			top->ending->create();
		}
		Boxes::count = 0;
		break;
	}
	case QMessageBox::Cancel:
		exit(0);
		break;
	default:
		break;
	}
}
MessageBox::~MessageBox()
{

}
