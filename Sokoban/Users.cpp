#include "Users.h"

Users::Users() {
  resize(width, height);
  list = new QFile("Data\\list.dat");
  listEdit = new QTextStream(list);
  generalUI();
}

Users::Users(bool isNew) {
  resize(width, height);
  isNew_ = isNew;
  list = new QFile("Data\\list.dat");
  listEdit = new QTextStream(list);
  generalUI();
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
  userName = new QLineEdit;
  userPasswd = new QLineEdit;

  QWidget* userLine = new QWidget;
  QWidget* passLine = new QWidget;

  QHBoxLayout *userN = new QHBoxLayout;
  QHBoxLayout *userP = new QHBoxLayout;
  QVBoxLayout *userL = new QVBoxLayout;

  QPushButton *okay = new QPushButton("Done");
  okay->setGeometry(0, 0, 100, 50);

  if (isNew_) {
    QObject::connect(okay, SIGNAL(clicked()), this, SLOT(signup()));
  }
  else {
    QObject::connect(okay, SIGNAL(clicked()), this, SLOT(login()));
  }

  //设置文本框样式
  userName->setEchoMode(QLineEdit::Normal);
  userPasswd->setEchoMode(QLineEdit::Password);

  //设置输入限制
  userName->setPlaceholderText("Your name here");
  userPasswd->setPlaceholderText("Your password here");
  userName->setMaxLength(15);

  //设置界面布局
  userN->addWidget(user);
  userN->addWidget(userName);
  userLine->setLayout(userN);

  userP->addWidget(userPass);
  userP->addWidget(userPasswd);
  passLine->setLayout(userP);

  userL->addWidget(userLine);
  userL->addWidget(passLine);
  userL->addWidget(okay);

  setLayout(userL);
}


void Users::signup() {

  name = userName->text();
  password = userPasswd->text();

  if (getHasExisted()) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("This user name has been taken."), QMessageBox::Ok);
    over->exec();

    return;
  }

  QString filename(QString("Data\\") + name + QString(".dat"));

  list->open(QIODevice::Append);

  userfile = new QFile;
  userfile->setFileName(filename);
  userfile->open(QIODevice::WriteOnly);

  listEdit = new QTextStream(list);
  output = new QTextStream(userfile);
  input = new QTextStream(userfile);


  *listEdit << name << endl;
  *output << name << endl;
  *output << password << endl;

  userfile->close();
  list->close();

  closeUI();

}

void Users::login() {
  name = userName->text();
  password = userPasswd->text();

  if (!getHasExisted()) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("This user name hasn't been signed up."), QMessageBox::Ok);
    over->exec();

    return;
  }

  /* listEdit = new QTextStream(list);
  output = new QTextStream(userfile); */

  if (canPass()) {
    closeUI();
  }

  else {
    QMessageBox *wrong = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("Wrong password"), QMessageBox::Ok);
    wrong->exec();

    return;
  }
  // userfile->close();
}

bool Users::canPass() {
  QString filename(QString("Data\\") + name + QString(".dat"));

  userfile = new QFile;
  userfile->setFileName(filename);
  userfile->open(QIODevice::ReadOnly | QIODevice::Text);

  input = new QTextStream(userfile);

  QString tempName, tempPass;

  tempName = input->readLine();
  tempPass = input->readLine();

  std::string nameArr(tempName.toLatin1());
  std::string passArr(tempPass.toLatin1());
  std::string inName(name.toLatin1());
  std::string inPass(password.toLatin1());

  userfile->close();

  return((nameArr == inName) && (passArr == inPass));

}

void Users::closeUI() {

  delete userfile;
  delete userName;
  delete userPasswd;
  delete list;
  delete listEdit;
  delete output;
  delete input;

  this->close();
}