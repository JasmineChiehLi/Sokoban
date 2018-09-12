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
#define SignUp true
#define LogIn false

class Users
  :public QWidget
{
  Q_OBJECT
public:
  Users();
  Users(bool isNew);
  bool getHasExisted();
  void generalUI();
  bool canPass();
  void closeUI();

  public slots:
  void signup();
  void login();

private:
  bool isNew_;
  QString name;
  QString password;
  QFile *userfile = nullptr;
  QFile *list = nullptr;
  QLineEdit *userName = nullptr;
  QLineEdit *userPasswd = nullptr;
  QTextStream *listEdit = nullptr;
  QTextStream *output = nullptr;
  QTextStream *input = nullptr;
};