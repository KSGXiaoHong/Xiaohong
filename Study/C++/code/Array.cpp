#include<iostream>
#include"Array.h"
using namespace std;
ostream& operator<<(ostream& out,const Array& a)
{
	for (size_t i = 0; i < a.getSize(); i++)
	{
		out << a.p[i] << "  ";
		if (0 == (i+1) % 4)
			out << endl;
	}
	if(0!=a.getSize()%4)
		out << endl;
	return out;
}
istream& operator>>(istream& in, Array& a)
{
	for (size_t i = 0; i < a.getSize(); i++)
	{
		in >> a.p[i] ;
	}
	return in;
}
Array::Array(int arrsize)
	:size(arrsize > 0 ? arrsize :
		throw invalid_argument("数组大小设置有误")),p(new int[size] ())
{
	for (size_t i = 0; i < size; i++)
	{
		p[i] = 0;
	}
}
Array::Array(const Array& a)
	:size(a.getSize()),p(new int[size] ())
{
	for (size_t i = 0; i < size; i++)
	{
		p[i] = a.p[i];
	}
}
Array& Array::operator=(const Array& a)
{
	if (a != (*this))
	{
		if (this->size != a.getSize())
		{
			delete[] this->p;
			this->size = a.getSize();
			this->p = new int[this->size]();
		}
		for (size_t i = 0; i < this->size; i++)
		{
			this->p[i] = a.p[i];
		}
	}
	
	return (*this);
}
bool Array::operator!=(const Array& a)const
{
	if ((this->size) != (a.getSize()))
		return true;
	else
	{
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->p[i] != a.p[i])
				return true;
		}
	}
	return false;
}
bool Array::operator==(const Array& a)const
{
	if ((this->size) != (a.getSize()))
		return false;
	else
	{
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->p[i] != a.p[i])
				return false;
		}
	}
	return true;
}

int& Array::operator[](int x)
{
	if (x<0 || x>(this->getSize()))
		throw out_of_range("访问越界");
	return (this->p[x]);
}
int Array::operator[](int x) const
{
	if (x<0 || x>(this->getSize()))
		throw out_of_range("访问越界");
	return (this->p[x]);
}
size_t Array::getSize() const
{
	return size;
}
Array::~Array()
{
	delete[] p;
}