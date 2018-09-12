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
}

Userfile::~Userfile() {

}

//�ӵ�½�û��ļ���ȡ�û���������
std::string Userfile::inputName() {
  userData->open(QIODevice::ReadOnly | QIODevice::Text);
  
  QString tempName;
  tempName = input->readLine();
  std::string inName(tempName.toLatin1());
  
  userData->close();

  return inName;
}

std::string Userfile::inputPass() {
  QString tempPass;

  tempPass = input->readLine();
  std::string inPass(tempPass.toLatin1());

  userData->close();

  return inPass;
}

//��ע���û��ļ�����û���������
void Userfile::outputInfo() {
  userData->open(QIODevice::WriteOnly);

  *output << name << endl;
  *output << password << endl;
  userData->close();

}

/*void Userfile::saveScore(int score) {

}*/