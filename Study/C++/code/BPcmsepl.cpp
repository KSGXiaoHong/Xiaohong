#include<iostream>
#include<string>
#include"BPcmsepl.h"
using namespace std;
BPcmsepl::BPcmsepl(const std::string& nm, const std::string& cn,
	double gs, double cs,double bs)
{
	setName(nm);
	setcardNum(cn);
	setgrossSell(gs);
	setCom(cs);
	setBasesalary(bs);
}
void BPcmsepl::setName(const string& nm)
{
	if (nm.size() >= 0 && nm.size() <= 6)
		name = nm;
	else
		throw invalid_argument("姓名长度有误");
}
string BPcmsepl::getName() const
{
	return name;
}
void BPcmsepl::setcardNum(const string& cn)
{
	if (cn.size() >= 0 && cn.size() <= 15)
		cardNum = cn;
	else
		throw invalid_argument("卡号长度有误");
}
string BPcmsepl::getcardNum() const
{
	return cardNum;
}
void BPcmsepl::setgrossSell(double gs)
{
	if (gs >= 0.0)
		grossSell = gs;
	else
		throw invalid_argument("销售总额有误");
}
double BPcmsepl::getgrossSell() const
{
	return grossSell;
}
void BPcmsepl::setCom(double cs)
{
	if (cs >= 0.0 && cs <= 1.0)
		commission = cs;
	else
		throw invalid_argument("提成比例有误");
}
double BPcmsepl::getCom() const
{
	return commission;
}
void BPcmsepl::setBasesalary(double bs)
{
	if (bs >= 0)
		baseSalary = bs;
	else
		throw invalid_argument("底薪有误");
}

double BPcmsepl::getBasesalary()const
{
	return baseSalary;
}


double BPcmsepl::income() const
{
	return commission * grossSell+baseSalary;
}
void BPcmsepl::prt()const
{
	cout << "姓名：" << name
		<< "\n卡号：" << cardNum
		<< "\n销售总额：" << grossSell
		<< "\n提成比例：" << commission
		<<"\n底薪："<<baseSalary
		<< endl;
}