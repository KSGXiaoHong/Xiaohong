#include"staticmember.h"
using namespace std;
size_t stMem::count = 0;
stMem::stMem(const string n)
	:name(n)
{
	count++;
}
string stMem::getName()const
{
	return name;
}
size_t stMem::getct()
{
	return count;
}
stMem::~stMem()
{
	count--;
}