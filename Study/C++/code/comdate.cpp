#include<iostream>
#include<stdexcept>
#include<array>
#include"comdate.h"
using namespace std;
Comdate::Comdate(int nian,int yue,int ri )
{
	cout << "comdate的constructor被调用" << endl;
	if (nian > 0 && nian < 2026)
		y = nian;
	else
		throw invalid_argument("年设置错误\n");
	if (yue > 0 && yue <= 12)
		m = yue;
	else
		throw invalid_argument("月设置错误\n");
	d = setday(ri);
	cout << "当前日期为：";
	prt();
}
int Comdate::setday(int ri)const
{
	const static array<int, 13>day{0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (ri<=day[m])
	{
		return ri;
	}
	if (2 == m && 29 == ri && ((0 == y % 400) || (0 != y % 100 && 0 == y % 4)))
		return ri;
	else
		throw invalid_argument("日设置错误\n");
}
void Comdate::prt()const
{
	cout<<y <<"年"<<m <<"月" <<d <<"日" << endl;
}
Comdate::~Comdate()
{
	cout << "comdate的desstructor被调用,当前日期为：" ;
	prt();
}
