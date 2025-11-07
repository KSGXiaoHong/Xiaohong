//book.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
#include<array>

Gradebook::Gradebook(std::string& title, std::string&name,
    std::array<std::array<int,subject>, students>& student)
    :bookTitle(title), courseName(name), stu(student)
{
}
void Gradebook::set(std::string name)
{
    courseName = name;
}
std::string Gradebook::getTitle() const
{
    return bookTitle;
}
void Gradebook::prtName() const
{
    std::cout << courseName << std::endl;
}
void Gradebook::prtTitle() const
{
    std::cout << getTitle() <<  std::endl;
}
double Gradebook::stuAverage
(std::array<int,subject>&stuAv)const
{
   unsigned int age = 0;
    for (auto const& Average : stuAv)
        age += Average;
    return static_cast<double>(age) / subject;
}

int Gradebook::getMax()const
{
    static int max_s = 0;
    for (auto const &row : stu)
    {
        for (auto const& max : row)
        {
            (max >= max_s) ? (max_s = max) : (max_s = max_s);
        }
    }
    return max_s;    
}
int Gradebook::getMin()const
{
    static int min_s = 100;
    for (auto const& row : stu)
    {
        for (auto const& min : row)
        {
            (min <= min_s) ? (min_s = min) : (min_s = min_s);
        }
    }
    return min_s;
}

void Gradebook::displaysubstu()
{
    std::cout << std::setw(17) << "语文 "
        << "数学 " << "英语 " <<"平均分 " << std::endl;
    for (auto const &i:stu)
    {
        static size_t a = 1;
        std::cout <<std::setw(2)<<a<< "号学生：";
        for (auto const& j : i)
        {
            
            std::cout << std::setw(5) << j;
        }
        double age = stuAverage(stu[a - 1]);
        std::cout<<std::setprecision(2)<<std::fixed;
        std::cout <<"  " << age << std::endl;
        a++;
    }
}
void Gradebook::displaystatistics()
{
    std::array<int, 11> classify = { 0 };
    for (auto const& row : stu)
    {
        for (auto const& col : row)
            classify[col / 10]++;
    }
    std::cout << "\n各分段人数统计图如下：\n";
    std::cout<<std::setw(3) << "0" << "~" << "9" << "：";
    for (size_t i = 0; i < classify[0]; i++)
        std::cout << "*";
    std::cout << std::endl;
    for (size_t i = 1; i < stu.size(); i++)
    {
        std::cout << 10 * i << "~" << i * 10 + 9 << "：";
        for (size_t j = 0; j < classify[i]; j++)
            std::cout << "*";
        std::cout << std::endl;
    }
    std::cout << std::setw(7) << "100：";
    for (size_t i = 0; i < classify[10]; i++)
        std::cout << "*";
    std::cout << std::endl;  
}