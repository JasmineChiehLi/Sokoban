#include "Users.h"

Users::Users() {
  resize(width, height);
  list = new QFile("Data\\list.dat");
  signup();
}

/*Users::Users(bool isNew = true) {
  isNew_ = isNew;

  if (isNew_) {
    signup();
  }
  else
  {
    login();
  }
}
*/
bool Users::getHasExisted() {
  QString temp;

  list->open(QIODevice::ReadOnly | QIODevice::Text);
  while (!list->atEnd()) {
    temp = list->readLine();
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

void Users::signup() {
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

  QObject::connect(okay, SIGNAL(clicked()), this, SLOT(initUser()));

  //�����ı�����ʽ
  userName->setEchoMode(QLineEdit::Normal);
  userPasswd->setEchoMode(QLineEdit::Password);

  //������������
  userName->setPlaceholderText("Your name here");
  userPasswd->setPlaceholderText("Your password here");
  userName->setMaxLength(10);

  //���ý��沼��
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

  //ͨ��slot������Ĳ�����ϵ
}


void Users::initUser() {

  name = userName->text();
  password = userPasswd->text();

  if (getHasExisted()) {
    QMessageBox *over = new QMessageBox(QMessageBox::Warning, QString("Oops.."),
      QString("This user name has been taken."), QMessageBox::Ok);
    over->exec();

    return;
  }

  QString filename(QString("Data\\") + name + QString(".dat"));

  list = new QFile("Data\\list.dat");
  list->open(QIODevice::Append);

  userfile = new QFile;
  userfile->setFileName(filename);
  userfile->open(QIODevice::WriteOnly);

  listEdit = new QTextStream(list);
  output = new QTextStream(userfile);
  input = new QTextStream(userfile);

  *listEdit << endl << name;
  *output << name << endl;
  *output << password << endl;

  userfile->close();
}