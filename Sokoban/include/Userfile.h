#pragma once
#include <QFile>
#include <QTextStream>
#include <QFileDevice>

#include <QString>
#include <String>

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
//  void saveScore(int score);
//  void getLevel();

private:
  QFile *userData = nullptr;
  QString *name = nullptr;
  QString *password = nullptr;
  QString *filename = nullptr;
  QTextStream *input;
  QTextStream *output;
};