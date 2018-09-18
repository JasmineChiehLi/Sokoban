#pragma once
#include <QPushButton>
#include <QHBoxLayout>
#include <QPalette>
#include <QFont>

#include "Users.h"
#include "Game.h"
//

class Start
  :public QWidget
{
  Q_OBJECT
public:
  Start();
  ~Start();

  public slots:
  void logIn();
  void signUp();
  void play();

private:
  Users * logUser = nullptr;
  Users *signUser = nullptr;
};