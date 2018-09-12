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
  std::string inputName();
  std::string inputPass();
  void outputInfo();
  int getScore(int level);
  void saveScore(int level, int score);
  int getLevel();

private:
  QFile *userData = nullptr;
  QString *name = nullptr;
  QString *password = nullptr;
  QString *filename = nullptr;
  int score[ALL];
  QTextStream *input;
  QTextStream *output;
};