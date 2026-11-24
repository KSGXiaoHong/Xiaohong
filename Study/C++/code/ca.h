#pragma once
#ifndef _CA_H
#define _CA_H
#include<string>
class ca
{
public:
	ca(size_t,std::string);
	~ca();
private:
	size_t count;
	std::string os;
};

#endif