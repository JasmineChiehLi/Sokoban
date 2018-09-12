#include "Userfile.h"

Userfile::Userfile() {

}

Userfile::Userfile(QString userName, QString userPass) {
  name = new QString(userName);
  password = new QString(userPass);
  filename = new QString(QString("Data\\") + name + QString(".dat"));
  userData = new QFile(*filename);

  input = new QTextStream(userData);
  output = new QTextStream(userData);

  for (int i = 0; i < ALL; i++) {
    score[i] = 0;
  }
}

Userfile::~Userfile() {

}

//从登录用户文件获取用户名
std::string Userfile::inputName() {
  userData->open(QIODevice::ReadOnly | QIODevice::Text);

  QString tempName;
  tempName = input->readLine();
  std::string inName(tempName.toLatin1());

  userData->close();

  return inName;
}

//从登录用户文件获取用户密码
std::string Userfile::inputPass() {
  QString tempPass;

  tempPass = input->readLine();
  std::string inPass(tempPass.toLatin1());

  userData->close();

  return inPass;
}

//向注册用户文件输出用户名与密码
void Userfile::outputInfo() {
  userData->open(QIODevice::WriteOnly);

  *output << name << endl;
  *output << password << endl;
  userData->close();

}

int Userfile::getScore(int level) {
  QString temp;

  userData->open(QIODevice::ReadWrite);
  
  int i = 0;
  input->readLine();
  input->readLine();
  while (!input->atEnd()) {
    temp = input->readLine();
    score[i] = temp.toInt();
  }

  userData->close();

  return score[level - 1];
}

void Userfile::saveScore(int level, int newScore) {

  QString temp;

  int preBest = getScore(level);
  if ((preBest != 0) && (preBest > newScore)) {
    userData->open(QIODevice::WriteOnly);

    *output << *name << endl;
    *output << *password << endl;
    
    int i = 0;
    while (score[i] > 0) {
      *output << QString(score[i]) << endl;
      i++;
    }
    userData->close();
  }

}

int Userfile::getLevel() {
  int level = 0;
  while (!input->atEnd()) {
    QString temp = input->readLine();
    level++;
  }
  return (level - 2);
}