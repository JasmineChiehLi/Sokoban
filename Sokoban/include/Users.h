#pragma once
#include <QFile>
#include <QLabel>
#include <QString>
#include <String>
#include <QWidget>
#include <QPalette>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextStream>

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Userfile.h"
#include "Parameter.h"


class Users
	:public QWidget
{
	Q_OBJECT
public:
	Users();
	~Users();
	Users(bool isNew);
  void closeUI();
	void generalUI();
	bool canPass();
  bool getHasExisted();

public slots:
	void signup();
	void login();
	void backStart();

signals:
	void sendsignal();
signals:
	void closeSignal();

private:
	bool status_;
	QString name;
	QString password;
  QFile *list = nullptr;
  QPalette *headPic = nullptr;
  QTextStream *input = nullptr;
	QLineEdit *userName = nullptr;
  QTextStream *output = nullptr;
	QLineEdit *userPasswd = nullptr;
	QTextStream *listEdit = nullptr;

};

