#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_
#include<iostream>
#include<string>
#include<array>

class Gradebook
{
public:
	static size_t const students = 10;//学生人数
	static size_t const subject = 3;//科目

	explicit Gradebook(std::string &, std::string &, 
		std::array<std::array<int ,subject>, students>&);//构造函数的接口
	void set(std::string name);//set函数的接口,获取课程名
	std::string getTitle() const;//getTitle函数的接口，返回成绩册标题
	void prtTitle() const;//prt函数的接口,打印标题
	void prtName() const;//prt函数的接口,打印课程名
	double stuAverage(std::array<int, subject>&) const;//stuAverage函数的接口，计算所有stu平均分
	int getMax()const;//获取成绩最大值
	int getMin()const;//获取成绩最小值
	void displaystu();//打印每个同学的成绩
	void displaysubstu();//打印每个同学各科成绩的成绩
	void displaystatistics();//统计条形图
private://私有数据成员
	std::string bookTitle;//成绩册标题
	std::string courseName;//课程名称
	std::array<std::array<int ,subject>, students> stu;//创建一个array对象stu，存放每个学生的成绩
};

template<class a>//两个数加法函数模板
a add(a x, a y)
{
	return x+y;
}

#endif