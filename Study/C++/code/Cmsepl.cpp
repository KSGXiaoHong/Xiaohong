#include<iostream>
#include<string>
#include"Cmsepl.h"
using namespace std;
Cmsepl::Cmsepl(const std::string& nm, const std::string& cn,
	double gs, double cs)
{
	setName(nm);
	setcardNum(cn);
	setgrossSell(gs);
	setCom(cs);
}
void Cmsepl::setName(const string& nm)
{
	if (nm.size() >= 0 && nm.size() <= 6)
		name = nm;
	else
		throw invalid_argument("姓名长度有误");
}
string Cmsepl::getName() const
{
	return name;
}
void Cmsepl::setcardNum(const string& cn)
{
	if (cn.size() >= 0 && cn.size() <= 15)
		cardNum = cn;
	else
		throw invalid_argument("卡号长度有误");
}
string Cmsepl::getcardNum() const
{
	return cardNum;
}
void Cmsepl::setgrossSell(double gs)
{
	if (gs>=0.0)
		grossSell = gs;
	else
		throw invalid_argument("销售总额有误");
}
double Cmsepl::getgrossSell() const
{
	return grossSell;
}
void Cmsepl::setCom(double cs)
{
	if (cs >= 0.0&&cs<=1.0)
		commission = cs;
	else
		throw invalid_argument("提成比例有误");
}
double Cmsepl::getCom() const
{
	return commission;
}
double Cmsepl::income() const
{

	cout <<"提成工资:"<< getCom() * getgrossSell()<<endl;
	return getCom() * getgrossSell();
}
void Cmsepl::prt()const
{
	cout << "姓名："<<getName()
		<<"\n卡号："<<getcardNum()
		<<"\n销售总额："<<getgrossSell()
		<<"\n提成比例："<<getCom()
		<<endl;
}