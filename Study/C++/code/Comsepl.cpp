#include"Comsepl.h"
#include<iostream>
#include<string>
using namespace std;
Comsepl::Comsepl(const std::string& nm, const std::string& cn,
	const double& gs, const double& cm)
	:Epl(nm,cn)
{
	setgrossSeles(gs);
	setCom(cm);
}
void Comsepl::setgrossSeles(const double gs)
{
	if (gs > 0)
		grossSales = gs;
	else
		throw invalid_argument("销售金额有误");
}
double Comsepl::getgrossSeles() const
{
	return grossSales;
}

void Comsepl::setCom(const double cm)
{
	if (cm > 0&&cm<=1)
		com = cm;
	else
		throw invalid_argument("提成比例有误");
}
double Comsepl::getCom() const
{
	return com;
}
double Comsepl::income() const
{
	cout << "提成工资：" << getCom() * getgrossSeles() << endl;
	return getCom() * getgrossSeles();
}
void Comsepl::prt() const
{
	Epl::prt();
	cout << "销售金额：" << getgrossSeles()<<endl;
	cout << "提成比例：" << getCom() << endl;
}