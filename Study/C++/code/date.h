#pragma once
#ifndef _DATE_H
#define _DATE_H
#include<array>
#include<iostream>
class Date
{
	friend std::ostream& operator<<(std::ostream&, const Date&);
public:
	explicit Date(int a = 2000, int b = 1, int c = 1);
	void setDate(int, int, int);
	Date& operator++();
	Date operator++(int);
	Date& operator+=(unsigned int);
	static bool runNian(unsigned int );
	bool lastday(int) const;
private:
	unsigned int y;
	unsigned int m;
	unsigned int d;
	static const std::array<unsigned int, 13> arr;
	void day();
};
#endif