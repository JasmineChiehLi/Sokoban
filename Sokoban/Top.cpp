#include "Top.h"



Top::Top()
{
	ch = new QGraphicsScene();
	userfile = new Userfile(QString("Cys"), QString("1010"));
	c = new LevelChoose(ch,userfile->getLevel());
	c->show();
}


Top::~Top()
{
}
//