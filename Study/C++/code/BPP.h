#pragma once
#ifndef _BPP_H
#define _BPP_H
#include"Cmsepl.h"
#include<string>
class BPP :public Cmsepl
{
public:
	BPP(const std::string&, const std::string&, 
		double=0.0, double = 0.0, double = 0.0);
	void setBasesalary(double);
	double getBasesalary()const;
	virtual double income() const override;
	virtual void prt() const override;
private:
	double baseSalary;
};
#endif