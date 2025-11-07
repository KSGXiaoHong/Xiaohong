#pragma once
#ifndef _EPL_H
#define _EPL_H
#include<string>
class Epl
{
public:
	//ÐÕÃû£¬¿¨ºÅ
	Epl(const std::string, const std::string);
	virtual ~Epl() {};
	void setName(const std::string& );
	std::string getName()const;

	void setcardNum(const std::string&);
	std::string getcardNum()const;

	virtual double income()const = 0;
	virtual void prt()const;
private:
	std::string Name;
	std::string cardNum;
};
#endif