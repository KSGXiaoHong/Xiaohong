#include<iostream>
#include"Bpce.h"
#include<string>
using namespace std;
Bpce::Bpce(const std::string& nm, const std::string& cn,
	const double& gs, const double& cm, const double& sl)
	:Comsepl(nm, cn, gs, cm)
{
	setslr(sl);
}

void Bpce::setslr(const double sl)
{
	if (sl > 0)
		baseSalary = sl;
	else
		throw invalid_argument("底薪有误");
}
double Bpce::getslr() const
{
	return baseSalary;
}

double Bpce::income() const
{
	double temp = Comsepl::income() + getslr();
	cout << "工资为：" << temp << endl;
	return temp + getslr();
}
void Bpce::prt() const
{
	Comsepl::prt();
	cout << "底薪：" << getslr()<<endl;
}