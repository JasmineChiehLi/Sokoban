#pragma once
#include <QFile>
#include <QTextStream>

#include <QString>
#include <String>

#define ALL 4

class Userfile
	:public QObject
{
	Q_OBJECT
public:
	Userfile();
  Userfile(QString userName, QString userPass);
	~Userfile();

  int getLevel();
  int getScore(int level);
  void outputInfo();
  void saveScore(int level, int score);

	std::string inputName();
	std::string inputPass();

private:
	int score[ALL];
	int levelList[ALL];
	QTextStream *input;
	QTextStream *output;
  QFile *userData = nullptr; //ÎÄ¼þÖ¸Õë
  QString *name = nullptr;
  QString *password = nullptr;
  QString *filename = nullptr;
};

