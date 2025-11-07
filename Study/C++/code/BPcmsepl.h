//BPcmsepl.h
#pragma once
#ifndef _BPCMSEPL_H
#define _BPCMSEPL_H
#include<string>
class BPcmsepl
{
public:
	explicit BPcmsepl(const std::string&, const std::string&, 
		double = 0.0,double = 0.0, double = 0.0);
	void setName(const std::string&);
	std::string getName()const;

	void setcardNum(const std::string&);
	std::string getcardNum()const;

	void setgrossSell(double);
	double getgrossSell()const;

	void setCom(double);
	double getCom()const;

	void setBasesalary(double);
	double getBasesalary()const;

	double income()const;
	void prt()const;
private:
	std::string name;
	std::string cardNum;
	double grossSell;
	double commission;
	double baseSalary;
};

#endif