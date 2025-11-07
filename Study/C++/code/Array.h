#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H
#include<iostream>
class Array
{
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);
public:
	explicit Array(int = 4);
	Array(const Array&);
	~Array();
	size_t getSize() const;
	Array& operator=(const Array&);
	bool operator!=(const Array&) const;
	bool operator==(const Array&) const;
	int& operator[](int);
	int operator[](int) const;

private:
	size_t size;
	int* p;
};

#endif