#include<iostream>
#include<string>
#include"ca.h"
using namespace std;
ca::ca(size_t c,string o)
	:count(c),os(o)
{
	cout << "对象" << count << "的 构造 函数被调用————" << os<<endl;
}
ca::~ca()
{
	cout << "对象" << count << "的 析构 函数被调用————" << os << endl;
}