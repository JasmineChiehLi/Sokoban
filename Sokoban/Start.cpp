#include "Start.h"

Start::Start() {
  QPushButton *log = new QPushButton("Log in");
  QPushButton *sign = new QPushButton("Sign up");

  QHBoxLayout *options = new QHBoxLayout;
  options->addWidget(log);
  options->addWidget(sign);

  setWindowTitle("Account");

  QObject::connect(log, SIGNAL(clicked()), this, SLOT(logIn()));
  QObject::connect(sign, SIGNAL(clicked()), this, SLOT(signUp()));

  setFixedHeight(height);
  setFixedWidth(width);

  options->setAlignment(Qt::AlignHCenter);
  setLayout(options);
  
}

Start::~Start() {

}

void Start::logIn() {
  logUser = new Users(LogIn);
  logUser->show();
  //QObject::connect(logUser,SIGNAL(close()),this,SLOT(play()));
  QObject::connect(logUser, SIGNAL(sendsignal()), this, SLOT(show()));
  this->hide();
}

void Start::signUp() {
  signUser = new Users(SignUp);
  //QObject::connect(signUser, SIGNAL(close()), this, SLOT(play()));
  QObject::connect(signUser, SIGNAL(sendsignal()), this, SLOT(show()));
  signUser->show();
  this->hide();
}

void Start::play() {
  game = new Game;
  game->show();
}