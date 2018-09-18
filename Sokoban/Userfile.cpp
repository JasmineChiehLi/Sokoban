#include "Userfile.h"
Userfile::Userfile() {

}//

Userfile::Userfile(QString userName, QString userPass) {
	name = new QString(userName);
	password = new QString(userPass);
	filename = new QString(QString("./Data/") + name + QString(".txt"));//相对路径
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

	*output <<* name << endl;
	*output << *password << endl;
	userData->close();

}

int Userfile::getScore(int level) {
	QString temp;

	userData->open(QIODevice::ReadWrite);

	int i = 0;
	input->readLine();//读用户名
	input->readLine();//读密码
	while (!input->atEnd()) {
		input->readLine();//先把关数读了
		temp = input->readLine();
		score[i] = temp.toInt();//每关的分数存起来
		i++;
	}

	userData->close();

	return score[level - 1];
}

void Userfile::saveScore(int level, int newScore) {//我需要传进来一个newScore

	QString temp;
	//levelList[level - 1] = level;
	int preBest = getScore(level);
	//if ((preBest != 0) && (preBest > newScore)) 
	if ((preBest == 0)||(preBest != 0) && (preBest > newScore))
	{   //第一次玩的时候preBest是0
		score[level - 1] = newScore;
		userData->open(QIODevice::WriteOnly|QIODevice::Text);//Text模式自带换行

		*output << *name << endl;
		*output << *password << endl;

		int i = 0;//newScore怎么写入？
		while (score[i] > 0) {
			*output << QString(QString::number(i + 1)) << endl;//每次都会重写一遍之前的所有关，这一行存level
			*output << QString(QString::number(score[i])) << endl;
			i++;
		}
		//userData->qclear();
		userData->close();
	}
}

int Userfile::getLevel() {
	userData->open(QIODevice::ReadOnly | QIODevice::Text);
	int level = 0;
	input->readLine();//读用户名
	input->readLine();//读密码
	while (!input->atEnd()) {
		QString temp;
		temp=input->readLine();//后来每读两行，level+1最后得到的就是当前最高level
		level = temp.toInt();
		input->readLine();
		//level++;
	}
	return (level);
}
	