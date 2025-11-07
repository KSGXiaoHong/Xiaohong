#include"Slrepl.h"
#include<string>
#include<iostream>
using namespace std;
Slrepl::Slrepl(const std::string& nm, const std::string& cn,
	const double& sl)
	:Epl(nm,cn)
{
	setSalary(sl);
}
void Slrepl::setSalary(double sl)
{
	if (sl > 0)
		salary = sl;
	else
		throw invalid_argument("固定工资有误");
}
double Slrepl::getSalary()const
{
	return salary;
}
double Slrepl::income()const
{
	cout <<"工资：" << getSalary() << endl;
	return getSalary();
}
void Slrepl::prt()const
{
	Epl::prt();
	cout << "固定工资：" << Slrepl::getSalary() << endl;

}