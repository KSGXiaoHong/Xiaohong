#pragma once
#ifndef _PN_H
#define _PN_H
#include<iostream>
class PhoneNumber
{
	friend std::ostream& operator<<(std::ostream& output, const PhoneNumber& number);//流提取。运算符前面的为cout，后面的是对象
	friend std::istream& operator>>(std::istream& input, PhoneNumber& number);//流插入。所以传参的顺序为istream和对象
private:
	std::string number2;//存放前两位，加号那里
	std::string number3;//存放号码头
	std::string number4_1;//存放中间
	std::string number4_2;//存放尾号
};
#endif