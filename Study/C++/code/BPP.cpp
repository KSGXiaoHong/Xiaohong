#include<iostream>
#include"BPP.h"
#include<string>
using namespace std;
BPP::BPP(const string& nm,const string& cn,
	double gs,double cs,double bs)
	:Cmsepl(nm,cn,gs,cs)
{
	setBasesalary(bs);
}
void BPP::setBasesalary(double bs)
{
	if (bs >= 0)
		baseSalary = bs;
	else
		throw invalid_argument ("底薪有误");
}

double BPP::getBasesalary()const
{
	return baseSalary;
}
double BPP::income() const
{
	cout << "总工资:" << Cmsepl::getCom() * Cmsepl::getgrossSell() + getBasesalary() << endl;
	return Cmsepl::getCom() * Cmsepl::getgrossSell() + getBasesalary();
	//return commission * grossSell + baseSalary;//error
}
void BPP::prt()const
{
	cout << "姓名：" << Cmsepl::getName()
		<< "\n卡号：" << Cmsepl::getcardNum()
		<< "\n销售总额：" << Cmsepl::getgrossSell()
		<< "\n提成比例：" << Cmsepl::getCom()
		<< "\n底薪：" << getBasesalary()
		<< endl;
	/*error
	cout << "姓名：" << name
		<< "\n卡号：" << cardNum
		<< "\n销售总额：" << grossSell
		<< "\n提成比例：" << commission
		<< "\n底薪：" << baseSalary
		<< endl;
	*/
}