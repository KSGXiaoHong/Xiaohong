#pragma once
#ifndef _TIME_H
#define _TIME_H

class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0);
	Time &setTime(int, int, int);
	Time &setH(int);
	Time &setM(int);
	Time &setS(int);
	void prtTime24h()const;
	void prtTime12h()const;
	unsigned int getH()const;
	unsigned int getM()const;
	unsigned int getS()const;
private:
	unsigned int h;
	unsigned int m;
	unsigned int s;
};

#endif