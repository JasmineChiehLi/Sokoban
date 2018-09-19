#pragma once
#include<QMessageBox>
#include"Boxes.h"

class MessageBox:public QMessageBox
{
public:
	MessageBox(QMessageBox * parent=0);
	~MessageBox();
};

