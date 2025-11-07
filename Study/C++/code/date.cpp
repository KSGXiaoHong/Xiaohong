#include"date.h"
using namespace std;
const array<unsigned int ,13> Date::arr={0,31,28,31,30,31,30,31,31,30,31,30,31};
ostream& operator<<(ostream& x, const Date& yy)
{
	static const array<string,13> const yue=
	{"零月","一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
	x << yy.y << "年" << yue[yy.m]  << yy.d << "日";
	return x;
}
Date::Date(int a,int b,int c)
{
	setDate(a, b, c);
}
void Date::setDate(int a, int b, int c)
{
	if (a > 0 && a <= 2025)
		y = a;
	else
		throw invalid_argument("年输入错误\n");
	if (b >= 0 && b <= 12)
		m = b;
	else
		throw invalid_argument("月输入有误\n");
	if (c <= arr[b] && c >= 1 || 2 == m && runNian(a) && c <= 29 && c >= 1)
		d = c;
	else
		throw invalid_argument("日输入有误\n");
}
Date& Date::operator++()
{
	day();
	return *this;
}
Date Date::operator++(int)
{
	Date temp = (*this);
	day();
	return temp;
}
Date& Date::operator+=(unsigned int a)
{
	for (size_t i = 0; i < a; i++)
	{
		day();
	}
	return *this;
}
bool Date::runNian(unsigned int a)
{
	if (0 == (a % 400) || 0 != (a % 100) && (0 == a % 4))
		return true;
	else
		return false;
}
bool Date::lastday(int a)const
{
	if (2 == m && runNian(y))
		return (29 == a);
	else
		return (arr[m] == a);
}
void Date::day()
{
	if (!lastday(d))
		d++;
	else
	{
		if ( m<12)
		{
			++m;
			d = 1;
		}
		else
		{
			++y;
			m = 1;
			d = 1;
		}
	}
}