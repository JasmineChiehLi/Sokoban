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
#include <QPixmap>
#include <QPalette>
#include <QBrush>

#include <QFile>
#include <QTextStream>

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Userfile.h"

#define height 400
#define width 600
#define SignUp true
#define LogIn false

class Users
  :public QWidget
{
  Q_OBJECT
public:
  Users();
  ~Users();
  Users(bool isNew);
  bool getHasExisted();
  void generalUI();
  bool canPass();
  void closeUI();

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
  Userfile *userfile = nullptr;
  QLineEdit *userName = nullptr;
  QLineEdit *userPasswd = nullptr;
  QTextStream *listEdit = nullptr;
  QTextStream *output = nullptr;
  QTextStream *input = nullptr;
  QPalette *headPic = nullptr;
};