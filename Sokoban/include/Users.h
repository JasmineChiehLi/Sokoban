#pragma once
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <String>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QFile>


#include <QDebug>

#define height 675
#define width 975

class Users
  :public QWidget
{
  Q_OBJECT
public:
  Users();
  //Users(bool isNew = true);
  bool getHasExisted();
  void signup();
  void login();

  public slots:
  void initUser();

private:
  bool isNew_;
  QString name;
  QString password;
  QFile *userfile;
  QFile *list;
  QLineEdit *userName;
  QLineEdit *userPasswd;
  QTextStream *listEdit;
  QTextStream *output;
  QTextStream *input;
};