#pragma once
#ifndef _CMSEPL_H
#define _CMSEPL_H
#include<string>
class Cmsepl
{
public:
	Cmsepl(const std::string&, const std::string&, double=0.0,double=0.0);
	void setName(const std::string&);
	std::string getName()const;

	void setcardNum(const std::string&);
	std::string getcardNum()const;

	void setgrossSell(double);
	double getgrossSell()const;

	void setCom(double);
	double getCom()const;

	virtual double income()const ;
	virtual void prt()const ;
private:
	std::string name;
	std::string cardNum;
	double grossSell;
	double commission;
};

#endif