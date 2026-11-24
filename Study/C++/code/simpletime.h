#pragma once
#ifndef _SIMPLETIME_H
#define _SIMPLETIME_H

class simpleTime
{
public:
	explicit simpleTime(int =0,int =0,int =0);
	void setTime(int, int, int);
	unsigned int getH()const;
	unsigned int& setH(unsigned int);
private:
	unsigned int h;
	unsigned int m;
	unsigned int s;
};

#endif