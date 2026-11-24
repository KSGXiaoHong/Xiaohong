#include<iostream>
#include"PN.h"
#include<iomanip>
using namespace std;
ostream& operator<<(ostream& output, const PhoneNumber& number)
{
	output << "(+" //输出一个括号和加号
		<< number.number2 //输出值86
		<< ") " //输出右边的括号
		<< number.number3 //输出号码头
		<< " "//输出一个空格
		<< number.number4_1 //输出中间四位
		<< " " //输出一个空格
		<< number.number4_2;//输出尾号
	return output;
}
istream& operator>>(istream& input, PhoneNumber& number)
{
	input.ignore(2);//忽略输入的前两个字符，因为输入的前两个字符是(+，不需要保存
	input>>setw(2) >> number.number2;//只读取输入的两个字符，保存到number2里
	input.ignore(2);//忽略再输入的两个字符，一个右括号一个空格
	input >> setw(3) >> number.number3;//只读取再输入的三个字符
	input.ignore(1);//忽略输入的空格
	input >> setw(4)>>number.number4_1;//只读取再输入的四个字符
	input.ignore(1);//忽略输入的空格
	input >> setw(4) >> number.number4_2;//只读取再输入的四个字符
	return input;
}