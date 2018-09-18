#include "Users.h"

Users::Users() {
  //设置widget大小，初始化文件指针以及数据流
  resize(WIN_WIDHT, WIN_HEIGHT);
  list = new QFile("Data\\list.dat");
  listEdit = new QTextStream(list);
  generalUI();
}

Users::Users(bool isNew) {
  resize(WIN_WIDHT, WIN_HEIGHT);
  status_ = isNew;
  list = new QFile("Data\\list.dat");
  listEdit = new QTextStream(list);
  generalUI();
}

Users::~Users() {
}

bool Users::getHasExisted() {
  //通过遍历list中的用户名确定有无该用户

  QString temp;
  list->open(QIODevice::ReadOnly | QIODevice::Text);
  while (!listEdit->atEnd()) {
    temp = listEdit->readLine();
    std::string tempArr(temp.toStdString());
    std::string nameArr(name.toStdString());

    if (tempArr == nameArr) {
      list->close();
      return true;
    }
  }
  list->close();
  return false;
}


void Users::generalUI() {
  QLabel* user = new QLabel(QString("Username"));
  QLabel* userPass = new QLabel(QString("Password"));
  QLabel* header;
  userName = new QLineEdit;
  userPasswd = new QLineEdit;

  //按钮布局
  QWidget* userLine = new QWidget;
  QWidget* passLine = new QWidget;
  QWidget* buttLine = new QWidget;
  QWidget* exitLine = new QWidget;

  QHBoxLayout *userN = new QHBoxLayout;
  QHBoxLayout *userP = new QHBoxLayout;
  QHBoxLayout *button = new QHBoxLayout;
  QHBoxLayout *exitL = new QHBoxLayout;
  QVBoxLayout *userL = new QVBoxLayout;

  QPushButton *okay = new QPushButton("Done");
  QPushButton *back = new QPushButton("Back");
  QPushButton *exit = new QPushButton("Exit");

  okay->setFixedHeight(30);
  okay->setFixedWidth(135);
  back->setFixedHeight(30);
  back->setFixedWidth(135);
  exit->setFixedHeight(30);
  exit->setFixedWidth(280);
  //布局完毕

  //连接返回开始界面与退出
  QObject::connect(back, SIGNAL(clicked()), this, SLOT(backStart()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));

  //添加进布局
  button->addWidget(okay);
  button->addWidget(back);
  button->setAlignment(Qt::AlignCenter | Qt::AlignTop);
  button->setMargin(0);
  buttLine->setLayout(button);

  exitL->addWidget(exit);
  exitL->setMargin(0);
  exitL->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
  exitLine->setLayout(exitL);

  //设置登录界面与注册界面
  headPic = new QPalette;

  if (status_) {
    setWindowTitle("Sign Up");

    QPalette* backGround = new QPalette;
    backGround->setBrush(QPalette::Background, QBrush(QPixmap("Resources\\SignUpBG.jpg")));
    setPalette(*backGround);

    header = new QLabel("SIGN UP");
    QObject::connect(okay, SIGNAL(clicked()), this, SLOT(signup()));
  }
  else {
    setWindowTitle("Log In");

    QPalette* backGround = new QPalette;
    backGround->setBrush(QPalette::Background, QBrush(QPixmap("Resources\\LogInBG.jpg")));
    setPalette(*backGround);

    header = new QLabel("LOG  IN");
    QObject::connect(okay, SIGNAL(clicked()), this, SLOT(login()));
  }

  //设置标题字体
  QFont head;
  head.setPointSize(55);
  head.setFamily("Impact");

  header->setFixedWidth(300);
  header->setFont(head);
  header->setAlignment(Qt::AlignCenter);

  //设置文本框样式
  userName->setEchoMode(QLineEdit::Normal);
  userPasswd->setEchoMode(QLineEdit::Password);

  userName->setFixedWidth(200);
  userPasswd->setFixedWidth(200);


  //设置输入限制
  userName->setPlaceholderText("Your name here");
  userPasswd->setPlaceholderText("Your password here");
  userName->setMaxLength(15);

  //设置界面布局
  userN->addWidget(user);
  userN->addWidget(userName);
  userN->setMargin(0);
  userLine->setFixedHeight(50);
  userLine->setFixedWidth(300);
  userLine->setLayout(userN);

  userP->addWidget(userPass);
  userP->addWidget(userPasswd);
  userP->setMargin(0);
  userP->setAlignment(Qt::AlignTop);
  passLine->setFixedHeight(50);
  passLine->setFixedWidth(300);
  passLine->setLayout(userP);

  userL->addWidget(header);
  userL->addWidget(userLine);
  userL->addWidget(passLine);
  userL->addWidget(buttLine);
  userL->addWidget(exitLine);
  userL->setMargin(0);

  userL->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  
  //以上设置布局完毕，以下添加布局到控件
  setLayout(userL);
}

void Users::backStart() {
  emit sendsignal();
  this->close();
}

void Users::signup() {

  //用户单击后从输入框获取名字与密码
  name = userName->text();
  password = userPasswd->text();

  //初始化文件指针
  userfile = new Userfile(name, password);

  //判断用户名是否为空
  if (name == QString("")) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("The name cannot be empty."), QMessageBox::Ok);
    over->exec();

    return;
  }

  //判断mimashifouweikong
  if (password == QString("")) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("The password cannot be empty."), QMessageBox::Ok);
    over->exec();

    return;
  }

  //判断该用户是否存在
  if (getHasExisted()) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("This user name has been taken."), QMessageBox::Ok);
    over->exec();

    return;
  }

  //用户名合法且不存在，即准备写入list用户目录
  list->open(QIODevice::Append);

  //初始化数据流指针
  listEdit = new QTextStream(list);
  *listEdit << name << endl;
  
  userfile->outputInfo();

  list->close();

  //录入结束关闭界面
  closeUI();
}

void Users::login() {

  //逻辑同sign up
  name = userName->text();
  password = userPasswd->text();

  userfile = new Userfile(name, password);

  if (name == QString("")) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("The name cannot be empty."), QMessageBox::Ok);
    over->exec();

    return;
  }

  if (!getHasExisted()) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("This user name hasn't been signed up."), QMessageBox::Ok);
    over->exec();

    return;
  }

  //用户名与密码合法且用户名存在，判断密码是否正确即能否登入
  if (canPass()) {
    closeUI();
  }

  else {
    QMessageBox *wrong = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("Wrong password"), QMessageBox::Ok);
    wrong->exec();

    return;
  }

}

bool Users::canPass() {
  //判断密码是否正确

  //由用户名生成文件名
  QString filename(QString("Data\\") + name + QString(".dat"));

  //将QString转化为std::String以便于进行比较
  std::string nameArr = name.toLatin1();
  std::string passArr = password.toLatin1();

  std::string inName = userfile->inputName();
  std::string inPass = userfile->inputPass();

  //返回比较结果
  return((nameArr == inName) && (passArr == inPass));
}

void Users::closeUI() {

  delete userfile;
  delete userName;
  delete userPasswd;
  delete list;
  delete listEdit;

  //发出closeSignal信号，接收SLOT位于start.cpp中，接收信号后向下连接游戏
  emit closeSignal();
  this->close();
}
