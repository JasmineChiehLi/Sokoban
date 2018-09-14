#include "Start.h"


Start::Start() {
  QPushButton *log = new QPushButton;
  QPushButton *sign = new QPushButton;
  QPushButton *exit = new QPushButton;

  QWidget *options = new QWidget;
  QWidget *logLine = new QWidget;
  QWidget *exitLine = new QWidget;
  QWidget *signLine = new QWidget;

  QHBoxLayout *startLay = new QHBoxLayout;
  QVBoxLayout *optLay = new QVBoxLayout;
  QHBoxLayout *logLay = new QHBoxLayout;
  QHBoxLayout *exitLay = new QHBoxLayout;
  QHBoxLayout *signLay = new QHBoxLayout;

  options->setFixedSize(QSize(buttonW1 * factorW, buttonH1 * 5.26));
  logLine->setFixedSize(QSize(buttonW1 * factorW, buttonH1*factorH));
  exitLine->setFixedSize(QSize(buttonW1 * factorW, buttonH1*factorH));
  signLine->setFixedSize(QSize(buttonW1 * factorW, buttonH1*factorH));

  options->setLayout(optLay);
  logLine->setLayout(logLay);
  exitLine->setLayout(exitLay);
  signLine->setLayout(signLay);

  logLine->setContentsMargins(0,0,startMargin,0);
  exitLine->setContentsMargins(0, 0, startMargin, 0);
  signLine->setContentsMargins(0, 0, startMargin, 0);

  logLay->addWidget(log);
  exitLay->addWidget(exit);
  signLay->addWidget(sign);

  optLay->setAlignment(Qt::AlignBottom);
  logLay->setAlignment(Qt::AlignRight | Qt::AlignBottom);
  exitLay->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
  signLay->setAlignment(Qt::AlignRight | Qt::AlignBottom);

  optLay->addWidget(logLine);
  optLay->addWidget(exitLine);
  optLay->addWidget(signLine);

  startLay->addWidget(options);

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

  setLayout(startLay);


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
