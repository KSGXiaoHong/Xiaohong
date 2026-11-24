#pragma once
#ifndef _COMDATE_H
#define _COMDATE_H

class Comdate
{
public:
	explicit Comdate(int =2000,int=1,int =1);
	int setday(int)const;
	void prt()const;
	~Comdate();
private:
	int y;
	int m;
	int d;
};
#endif