#include "Users.h"

Users::Users() {
  resize(WIN_WIDHT, WIN_HEIGHT);
  list = new QFile("Data\\list.dat");
  listEdit = new QTextStream(list);
  generalUI();
}//

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

  QObject::connect(back, SIGNAL(clicked()), this, SLOT(backStart()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));

  okay->setFixedHeight(30);
  okay->setFixedWidth(135);
  back->setFixedHeight(30);
  back->setFixedWidth(135);
  exit->setFixedHeight(30);
  exit->setFixedWidth(280);

  button->addWidget(okay);
  button->addWidget(back);
  button->setAlignment(Qt::AlignCenter | Qt::AlignTop);
  button->setMargin(0);
  buttLine->setLayout(button);

  exitL->addWidget(exit);
  exitL->setMargin(0);
  exitL->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
  exitLine->setLayout(exitL);



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

  setLayout(userL);
}

void Users::backStart() {
  emit sendsignal();
  this->close();
}

void Users::signup() {

  name = userName->text();
  password = userPasswd->text();

  userfile = new Userfile(name, password);

  if (name == QString("")) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("The name cannot be empty."), QMessageBox::Ok);
    over->exec();

    return;
  }

  if (password == QString("")) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("The password cannot be empty."), QMessageBox::Ok);
    over->exec();

    return;
  }

  if (getHasExisted()) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("This user name has been taken."), QMessageBox::Ok);
    over->exec();

    return;
  }

  list->open(QIODevice::Append);

  listEdit = new QTextStream(list);
  *listEdit << name << endl;

  userfile->outputInfo();

  list->close();

  closeUI();
}

void Users::login() {
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
  QString filename(QString("Data\\") + name + QString(".dat"));

  std::string nameArr = name.toLatin1();
  std::string passArr = password.toLatin1();

  std::string inName = userfile->inputName();
  std::string inPass = userfile->inputPass();

  return((nameArr == inName) && (passArr == inPass));
}

void Users::closeUI() {

  delete userfile;
  delete userName;
  delete userPasswd;
  delete list;
  delete listEdit;

  emit closeSignal();
  this->close();
}
