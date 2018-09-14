#include "Start.h"

Start::Start() {
  QPushButton *log = new QPushButton;
  QPushButton *sign = new QPushButton;
  QPushButton *exit = new QPushButton;

  QVBoxLayout *options = new QVBoxLayout;
  options->addWidget(log);
  options->addWidget(exit);
  options->addWidget(sign);

  QObject::connect(log, SIGNAL(clicked()), this, SLOT(logIn()));
  QObject::connect(sign, SIGNAL(clicked()), this, SLOT(signUp()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));

  setFixedHeight(height);
  setFixedWidth(width);

  log->setFixedHeight(buttonH1);
  log->setFixedWidth(buttonW1);
  sign->setFixedHeight(buttonH1);
  sign->setFixedWidth(buttonW1);
  exit->setFixedHeight(buttonH1);
  exit->setFixedWidth(buttonW1);

  log->setStyleSheet("QPushButton{border-image:url(Resources/LogNormal.png);background:transparent;}"
    "QPushButton:hover{border-image:url(Resources/LogHover.png);background:transparent;}"
    "QPushButton:pressed{border-image:url(Resources/LogPressed.png);background:transparent;");

  sign->setStyleSheet("QPushButton{border-image:url(Resources/SignNormal.png);background:transparent;}"
    "QPushButton:hover{border-image:url(Resources/SignHover.png);background:transparent;}"
    "QPushButton:pressed{border-image:url(Resources/SignPressed.png);background:transparent;");

  exit->setStyleSheet("QPushButton{border-image:url(Resources/ExitNormal.png);background:transparent;}"
    "QPushButton:hover{border-image:url(Resources/ExitHover.png);background:transparent;}"
    "QPushButton:pressed{border-image:url(Resources/ExitPressed.png);background:transparent;");

  options->setAlignment(Qt::AlignHCenter);
  setLayout(options);

  setAutoFillBackground(true);
  QPalette* backGround = new QPalette;
  backGround->setBrush(QPalette::Background, QBrush(QPixmap("Resources\\StartWall.jpg")));
  setPalette(*backGround);
}

Start::~Start() {

}

void Start::logIn() {
  logUser = new Users(LogIn);
  logUser->show();
  QObject::connect(logUser, SIGNAL(closeSignal()), this, SLOT(play()));
  QObject::connect(logUser, SIGNAL(sendsignal()), this, SLOT(show()));
  this->hide();
}

void Start::signUp() {
  signUser = new Users(SignUp);
  QObject::connect(signUser, SIGNAL(closeSignal()), this, SLOT(play()));
  QObject::connect(signUser, SIGNAL(sendsignal()), this, SLOT(show()));
  signUser->show();
  this->hide();
}

void Start::play() {
  Game* game = new Game;
  game->show();
}
