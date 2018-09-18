#include "Start.h"
#include"Top.h"
extern Top*top;
Start::Start() {

  //初始化三个按鈕
  QPushButton *log = new QPushButton;
  QPushButton *sign = new QPushButton;
  QPushButton *exit = new QPushButton;

  //初始化四个用以布局的QWidget
  QWidget *options = new QWidget;
  QWidget *logLine = new QWidget;
  QWidget *exitLine = new QWidget;
  QWidget *signLine = new QWidget;
  
  //初始化五个Layout用以布局，对应以上的Widget以及最底层的父Widget
  QHBoxLayout *startLay = new QHBoxLayout;
  QVBoxLayout *optLay = new QVBoxLayout;
  QHBoxLayout *logLay = new QHBoxLayout;
  QHBoxLayout *exitLay = new QHBoxLayout;
  QHBoxLayout *signLay = new QHBoxLayout;

  //以下通过设置layout和widget大小及对齐方式布局按钮以和背景图上的人物图完成预设效果
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

  optLay->setAlignment(Qt::AlignBottom);
  logLay->setAlignment(Qt::AlignRight | Qt::AlignBottom);
  exitLay->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
  signLay->setAlignment(Qt::AlignRight | Qt::AlignBottom);
  //设置布局完成

  //将按钮部件加到layout中
  logLay->addWidget(log);
  exitLay->addWidget(exit);
  signLay->addWidget(sign);

  //将三个Widget放入父layout
  optLay->addWidget(logLine);
  optLay->addWidget(exitLine);
  optLay->addWidget(signLine);

  //设置父layout为父widget布局
  startLay->addWidget(options);

  //为三个按钮添加slot事件
  QObject::connect(log, SIGNAL(clicked()), this, SLOT(logIn()));
  QObject::connect(sign, SIGNAL(clicked()), this, SLOT(signUp()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));

  //设置各种部件大小尺寸
  setFixedHeight(WIN_HEIGHT);
  setFixedWidth(WIN_WIDHT);

  
  log->setFixedHeight(buttonH1);
  log->setFixedWidth(buttonW1);
  sign->setFixedHeight(buttonH1);
  sign->setFixedWidth(buttonW1);
  exit->setFixedHeight(buttonH1);
  exit->setFixedWidth(buttonW1);

  //设置按钮图，达到预期效果
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

  //设置背景图
  setAutoFillBackground(true);
  QPalette* backGround = new QPalette;
  backGround->setBrush(QPalette::Background, QBrush(QPixmap("Resources\\StartWall.jpg")));
  setPalette(*backGround);
}

Start::~Start() {

}

//登陆界面
void Start::logIn() {
  logUser = new Users(LogIn);
  logUser->show();
  QObject::connect(logUser, SIGNAL(closeSignal()), this, SLOT(play()));
  QObject::connect(logUser, SIGNAL(sendsignal()), this, SLOT(show()));
  this->hide();
}

//注册界面
void Start::signUp() {
  signUser = new Users(SignUp);
  QObject::connect(signUser, SIGNAL(closeSignal()), this, SLOT(play()));
  QObject::connect(signUser, SIGNAL(sendsignal()), this, SLOT(show()));
  signUser->show();
  this->hide();
}

//开始游戏，转到游戏
void Start::play() {
	top = new Top();
}
