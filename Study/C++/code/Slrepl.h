#pragma once
#ifndef _SLREPL_H
#define _SLREPL_H
#include"Epl.h"
#include<string>
class Slrepl :public Epl
{
public:
	//姓名，卡号，固定工资
	Slrepl(const std::string& , const std::string&,
		const double&);
	virtual ~Slrepl() {};

	void setSalary(double);
	double getSalary()const;

	virtual double income()const override;
	virtual void prt()const override;
private:
	double salary;
};
#endif