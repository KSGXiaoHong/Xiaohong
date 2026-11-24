#include<iostream>
#include"comtemp.h"
#include"comdate.h"
using namespace std;
Comtemp::Comtemp(const string& n, const Comdate& dat)
	:name(n),birthday(dat)
{
	cout << "Comtemp的constructor被调用\n";
	cout << "初始化成员name值为" << name << endl;
}
void Comtemp::prt()const
{
	cout << name << "的生日是";
	birthday.prt();
	cout << endl;
}
Comtemp::~Comtemp()
{
	cout << "Comtemp的destructor被调用" << endl;
}