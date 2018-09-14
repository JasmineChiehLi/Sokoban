#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPalette>
#include <QtGui>
#include <QDebug>

#include "Users.h"
#include "Game.h"

#define buttonH1 70
#define buttonW1 200

class Start
  :public QWidget
{
  Q_OBJECT
public:
  Start();
  ~Start();
  //void setButtonStyle(QPushButton* button);

  public slots:
  void logIn();
  void signUp();
  void play();

private:
  Users * logUser = nullptr;
  Users *signUser = nullptr;
};