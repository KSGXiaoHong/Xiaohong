#include<iostream>
#include"Epl.h"
#include<string>
using namespace std;
Epl::Epl(std::string nm, std::string cn)
{
	setName(nm);
	setcardNum(cn);
}
void Epl::setName(const std::string& nm)
{
	if (nm.size() > 0&&nm.size()<10)
		Name = nm;
	else
		throw invalid_argument("ÐÕÃûÓÐÎó");
}
string Epl::getName()const
{
	return Name;
}

void Epl::setcardNum(const std::string& cn)
{
	if (cn.size() > 0 && cn.size() < 20)
		cardNum = cn;
	else
		throw invalid_argument("¿¨ºÅÓÐÎó");
}
string Epl::getcardNum()const
{
	return cardNum;
}
void Epl::prt()const
{
	cout << "ÐÕÃû£º" << getName() << endl;
	cout << "¿¨ºÅ£º" << getcardNum() << endl;
}