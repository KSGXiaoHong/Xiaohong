#pragma once
#ifndef _STATICMEMBER_H
#define _STATICMEMBER_H
#include<string>
class stMem
{
public:
	stMem(const std::string );
	std::string getName() const;
	~stMem();
	static size_t getct();
private:
	std::string name;
	static size_t count;
};

#endif
