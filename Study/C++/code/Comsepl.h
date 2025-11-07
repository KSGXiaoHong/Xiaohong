#pragma once
#ifndef _COMSEPL_H
#define _COMSEPL_H
#include"Epl.h"
class Comsepl :public Epl
{
public:
	//姓名，卡号，销售金额，提成比例
	Comsepl(const std::string&, const std::string&,
		const double&, const double&);
	virtual ~Comsepl() {};
	void setgrossSeles(const double);
	double getgrossSeles() const;

	void setCom(const double);
	double getCom() const;

	virtual double income() const override;
	virtual void prt() const override;

private:
	double grossSales;
	double com;

};
#endif