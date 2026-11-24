#pragma once
#ifndef _BPCE_H
#define _BPCE_H
#include"Comsepl.h"
class Bpce :public Comsepl
{
public:
	//姓名，卡号，销售金额，提成比例，底薪
	Bpce(const std::string&, const std::string&,
		const double&, const double&, const double&);
	virtual ~Bpce() {};

	void setslr(const double);
	double getslr() const;

	virtual double income() const override;
	virtual void prt() const override;
private:
	double baseSalary;
};
#endif