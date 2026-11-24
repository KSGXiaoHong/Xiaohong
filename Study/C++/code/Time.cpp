#include"Time.h"
#include<iostream>
#include<stdexcept>
#include<iomanip>
using namespace std;

Time::Time(int shi,int fen,int miao)
{
	setTime(shi,fen,miao);
}
Time& Time::setTime(int shi, int fen, int miao)
{
	setH(shi);
	setM(fen);
	setS(miao);
	return *this;
}
Time& Time::setH(int shi)
{
	if (shi < 24 && shi >= 0)
		h = shi;
	else
		throw invalid_argument("时设置错误,范围0~23");
	return *this;
}
Time& Time::setM(int fen)
{
	if (fen < 60 && fen >= 0)
		m = fen;
	else
		throw invalid_argument("分设置错误,范围0~59");
	return *this;
}
Time& Time::setS(int miao)
{
	if (miao < 60 && miao >= 0)
		s = miao;
	else
		throw invalid_argument("秒设置错误,范围0~59");
	return *this;
}
void Time::prtTime24h()const
{
	cout << "当前时间为："
		<< setfill('0') << setw(2) << getH() << ":" << setw(2) << getM() << ":" << setw(2) << getS() << endl;
}

void Time::prtTime12h()const
{
	if (h > 12)
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << getH() - 12 << ":" << setw(2) << getM() << ":" << setw(2) << getS() << "-PM" << endl;
	}
	else if(h==12)
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << 12 << ":" << setw(2) << getM() << ":" << setw(2) << getS() << "-PM" << endl;
	}
	else
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << getH() << ":" << setw(2) << getM() << ":" << setw(2) << getS() <<"-AM" << endl;
	}
}
unsigned int Time::getH()const
{
	return h;
}
unsigned int Time::getM()const
{
	return m;
}
unsigned int Time::getS()const
{
	return s;
}