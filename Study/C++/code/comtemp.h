#pragma once
#ifndef _COMTEMP_H
#define _COMTEMP_H
#include<string>
#include"comdate.h"
class Comtemp
{
public:
	explicit Comtemp(const std::string&,const Comdate&);
	void prt()const;
	~Comtemp();
private:
	std::string name;
	Comdate birthday;
};

#endif