#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include"book.h"
#include<array>
#include<vector>
#include<stdexcept>
#include<typeinfo>
#include<iterator>
#include<algorithm>
#include<windows.h>
#include"Time.h"
#include"ca.h"
#include"simpletime.h"
#include"comdate.h"
#include"comtemp.h"
#include"staticmember.h"
#include"date.h"
#include"PN.h"
#include"Array.h"
#include"Cmsepl.h"
#include"BPcmsepl.h"
#include"BPP.h"
#include"Epl.h"
#include"slrepl.h"
#include"Comsepl.h"
#include"Bpce.h"

#define _2_1 0//第二章_头文件接口分离
#define _2_2 0//第二章_拓展
#define _2_3 0//第二章_拓展
#define _3_1 0//第三章_计数器控制的循环
#define _3_2 0//第三章_标记控制的循环
#define ___1 0//平台数据类型最大最小值
#define _3_3 0//第三章_switch多路选择语句
#define _4_1 0//第四章_三个成绩最大值
#define _4_2 0//第四章_随机骰子
#define _4_3 0//第四章_600000骰子
#define _4_4 0//第四章_博彩
#define _4_5 0//第四章_函数模板
#define _5_1 0//第五章_声明array对象、(循环)初始化array对象的元素
#define _5_2 0//第五章_用常量变量指定array对象的大小,并用计算结果设置array对象的元素
#define _5_3 0//第五章_2-D array对象的Gradebook类
#define _5_6 0//第五章_vector对象的基本操作
#define _6_1 0//第六章_内置数组做参数/内置数组排序查找
#define _6_2 0//第六章_用const修饰指针
#define _6_3 0//第六章_实例研究：指针与内置数组
#define _6_4 0//第六章_字符串的初始化和访问
#define _7_1 0//第七章_Time类的定义
#define _7_2 0//第七章_使用Time类
#define _7_3 0//第七章_具有默认实参的构造函数
#define _7_4 0//第七章_构造函数与析构函数
#define _7_5 0//第七章_微妙的陷阱
#define _7_6 0//第七章_默认的逐个成员赋值
#define _7_7 0//第七章_组成
#define _7_8 0//第七章_显式和隐式的使用this指针
#define _7_9 0//第七章_使用this指针串联函数
#define _7_10 0//第七章_静态数据成员的访问
#define _7_11 0//第七章_使用友元函数修改private数据
#define _8_1 0//第八章_string类的重载运算符
#define _8_2 0//第八章_重载二元流插入和流提取运算符
#define _8_3 0//第八章_实例研究：Date类
#define _8_4 0//第八章_实例研究：Array类
#define _9_1 0//第九章_CmsEpl类
#define _9_2 0//第九章_不使用继承的BPcmsepl类
#define _9_3 0//第九章_创建C-BP继承层次结构
#define _10_1 0//第十章_从派生类对象调用基类函数（将基类指针指向派生类对象）
#define _10_2 0//第十章_将派生类指针指向基类对象
#define _10_3 0//第十章_C-BP层次中的virtual函数
#define _10_4 0//第十章_实例研究：应用多态性的工资发放系统
#define _10_5 0//第十章_实例研究：应用向下强制类型转换、dynamic_cast、typeid、和type_info并使用多态性和运行时类型信息的工资发放系统

using namespace std;

#if 1//总

#if _2_1//第二章_头文件接口分离
int main()
{
	Gradebook book1("你好！");//构造函数初始化数据成员
	cout << book1.get() << endl;//打印构造函数直接初始化数据成员的值
	book1.set("我不好");//set函数对数据成员进行修改
	book1.prt();//prt函数打印修改后的值
}
#endif

#if A_1//第二章_拓展
int main()
{
	std::string name;//创建一个string类的name对象
	int a = 0;
	name = "hahaha";
	a = name.size();//访问name对象中的size函数，求name字符串长度
	std::cout << a << std::endl;//6
}
#endif

#if _2_3//第二章_拓展
int main()
{
	std::string name;//创建一个string类的name对象
	int a = 0;
	name = "hahaha";
	name = name.substr(1, 4);// h   a   haha，haha   h   a
	std::cout << name << std::endl;//aha
}
#endif

#if _3_1//第三章_计数器控制的循环
int main()
{
	Gradebook book("你好");
	book.prt();
	cout << "平均成绩为:" << book.classAverage() << endl;
}
#endif

#if _3_1//第三章_计数器控制的循环
int main()
{
	Gradebook book("你好");
	book.prt();
	cout << "平均成绩为:" << book.classAverage() << endl;
}
#endif

#if _3_2//第三章_标记控制的循环
int main()
{
	Gradebook book("您好！\n欢迎查看成绩册");
	book.prt();
	double age = book.classAverage();
	Gradebook book1("平均成绩为：");
	book1.prt();
	cout << setprecision(2) << fixed;
	cout << age << endl;
}
#endif

#if ___1//平台数据类型最大最小值
int main()
{
	cout << UINT_MAX << endl;
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	cout << LLONG_MAX << endl;
	cout << LLONG_MIN << endl;
}
#endif

#if _3_3//第三章_switch多路选择语句
int main()
{
	Gradebook book("您好、欢迎查看成绩册！");
	Gradebook book2("1");
	book.prt();
	book.inputGrades();
	cout << "book中" << endl;
	book.displayGrades();
	cout << "book2中" << endl;
	book2.displayGrades();
}
#endif

#if _4_1//三个成绩最大值
int main()
{
	Gradebook book("您好！欢迎查看成绩册！");
	book.prt();
	book.input3score();
	book.display3score();
}
#endif
	
#if _4_2//第四章_随机骰子
int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 1; i <= 20; i++)
	{
		cout << setw(5) << rand() % 6 + 1;
		if (!(i % 4))
			cout << endl;
	}
}
#endif

#if _4_3////第四章_600000骰子
int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	unsigned int a = 0, b = 0, c = 0,
		d = 0, e = 0, f = 0;
	for (int i = 0; i < 600000; i++)
	{
		switch (rand() % 6 + 1)
		{
		case 1:a++; break;
		case 2:b++; break;
		case 3:c++; break;
		case 4:d++; break;
		case 5:e++; break;
		case 6:f++; break;
		default:break;
		}
	}
	cout << setw(4) << "1" << setw(10) << a << "\n"
		<< setw(4) << "2" << setw(10) << b << "\n"
		<< setw(4) << "3" << setw(10) << c << "\n"
		<< setw(4) << "4" << setw(10) << d << "\n"
		<< setw(4) << "5" << setw(10) << e << "\n"
		<< setw(4) << "6" << setw(10) << f << "\n"
		<< setw(4) << "总数" << setw(10) << a + b + c + d + e + f << endl;
}
#endif

#if _4_4//第四章_博彩
int main()
{
	enum play { WIN, LOST, CON };
	srand(static_cast<unsigned int>(time(NULL)));
	unsigned int state = CON;
	unsigned int temp = 0;
	int a = 0, b = 0;
	int startgame = 1;
	while (startgame)
	{
		a = rand() % 6 + 1;
		b = rand() % 6 + 1;
		int i = 1;
		cout << "博彩游戏——掷双骰！\n" << endl;
		cout << "游戏开始，" << "点击回车掷出骰子" << endl;
		std::cin.get();
		cout << "第" << i << "次掷出骰子a点数为" << a << "\t"
			<< "第" << i << "次掷出骰子b点数为" << b << "\t"
			<< "第" << i << "次点数之和为" << a + b << endl;
		switch (a + b)
		{
		case 7:
		case 11:
			state = WIN; break;
		case 2:
		case 3:
		case 12:
			state = LOST; break;
		default:
			state = CON; temp = a + b; break;
		}
		while (state == CON)
		{
			cout << "点击回车继续掷骰子" << endl;
			std::cin.get();
			a = rand() % 6 + 1;
			b = rand() % 6 + 1;
			cout << "第" << i << "次掷出骰子a点数为" << a << "\t"
				<< "第" << i << "次掷出骰子b点数为" << b << "\t"
				<< "第" << i << "次点数之和为" << a + b << endl;
			if (7 == (a + b))
				state = LOST;
			else if (temp == (a + b))
				state = WIN;
			else
			{
				i++;
				continue;
			}
		}
		switch (state)
		{
		case WIN:cout << "************玩家获胜************" << endl; break;
		case LOST:cout << "************玩家失败************" << endl; break;
		}
		cout << "\n是否继续游戏？（请输入数字）\n"
			<< "0.否  1.是" << endl;
		std::cin >> startgame;
		//清空缓冲区操作
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;
	}
	cout << "游戏结束！\n" << endl;
}
#endif
	
#if _4_5//第四章_函数模板
int main()
{
	int x = add(5043, 5043);
	double y = add(50.43, 50.43);
	cout << "x=" << x << "\t" << "y=" << y << endl;
}
#endif

#if _5_1//第五章_声明array对象、(循环)初始化array对象的元素
int main()
{
	array<int, 5>  a;
	for (size_t i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << "a[" << i << "]=" << a[i] << " ";
	}
}
#endif

#if _5_2//第五章_用常量变量指定array对象的大小,并用计算结果设置array对象的元素
int main()
{
	const size_t arrSize = 5;
	array<int, arrSize> a;
	for (size_t i = 0; i < a.size(); ++i)
	{
		a[i] = 1 + i * 2;
	}
	cout << setw(8) << "数组索引" << setw(10) << "数组元素" << endl;
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << setw(4) << i << setw(10) << a[i] << endl;
	}
}
#endif

#if _5_3//第五章_2-D array对象的Gradebook类
int main()
{
	string s = "您好！欢迎查看成绩册\n";
	string k = "           语文  数学 英语";
	array<array<int, Gradebook::subject>, Gradebook::students>stu =
	{ 87,68,94,
		100,83,78,
		85,91,76,
		87,67,100,
		87,36,76,
		15,65,46,
		98,67,98,
		45,87,76,
		56,100,76,
		34,100,87 };
	Gradebook book(s, k, stu);
	book.prtTitle();
	book.displaysubstu();
	book.displaystatistics();
	cout << setprecision(2) << fixed;
	cout << setw(20) << "\n最高成绩为：" << book.getMax() << endl;
	cout << setw(20) << "最低成绩为：" << book.getMin() << endl;

}
#endif  


#if _5_6//第五章_vector对象的基本操作
static void inputvct(vector<int>& vct)//输入vector对象
{
	for (int& temp : vct)
		cin >> temp;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
static void outputvct(const vector<int>& vct)//输出vector对象
{
	for (int temp : vct)
		cout << temp << " ";
	cout << endl;
}
int main()
{
	vector<int>vct1(5);
	vector<int>vct2(10);
	cout << "请输入vector1对象的元素：";
	inputvct(vct1);
	cout << setw(25) << "vector1对象的元素为：";
	outputvct(vct1);
	cout << "请输入vector2对象的元素：";
	inputvct(vct2);
	cout << setw(25) << "vector2对象的元素为：";
	outputvct(vct2);
	(vct2 == vct1) ? (cout << "vct2等于vct1" << endl) : (cout << "vct2不等于vct1" << endl);
	vector<int>vct3;
	vct3 = vct1;
	cout << "将vector1赋值给vector3，";
	cout << "vector3对象的元素为：";
	outputvct(vct3);
	(vct3 == vct1) ? (cout << "vct3等于vct1" << endl) : (cout << "vct3不等于vct1" << endl);
	vct3[3] = 10086;
	cout << "将10086赋值给vector3[3],";
	cout << "vector3对象的元素为：";
	outputvct(vct3);
	cout << "当前vector3的大小为：" << vct3.size() << endl;
	cout << "给vector3新增两个元素：66，99" << endl;
	vct3.push_back(66);
	vct3.push_back(99);
	cout << "当前vector3对象的元素为：";
	outputvct(vct3);
	cout << "当前vector3的大小为：" << vct3.size() << endl;
	cout << "给vector3弹出一个元素" << endl;
	vct3.pop_back();
	cout << "vector3对象的元素为：";
	outputvct(vct3);
	cout << "当前vector3的大小为：" << vct3.size() << endl;
	try
	{
		cout << "尝试打印vector1[15]的值" << endl;
		cout << vct1.at(15) << endl;
	}
	catch (out_of_range& ex)
	{
		cerr << "已引发异常：" << ex.what() << endl;
	}
	cout << "异常已处理" << endl;
}
#endif

#if _6_1//第六章_内置数组做参数/内置数组排序查找
void arr(int[], int);
int main()
{
	int a[5] = { 3,5,2,9,1 };
	int* b[5] = { a,a };
	bool c[5] = { false,true };
	sort(begin(a), end(a));
	bool f = binary_search(begin(a), end(a), 8);
	for (int x : a)
	{
		cout << x << " ";
	}
	cout << endl << f << endl;
	arr(a, 5);
}
static void arr(int x[], int y)
{
	for (int i = 0; i < y; i++)
		cout << x[i] << " ";
}
#endif

#if _6_2//第六章_用const修饰指针
int main()
{
	///begin:非c数，非c指
	int i1 = 1, j1 = 2;
	int* p1 = &j1;//p1指针指向j1，指向的j1是一个int类型的数据
	p1 = &i1;//改变指针指向i1
	cout << "指向非const数据的非const指针" << endl;
	cout << "i1=" << *p1 << endl;//输出i1为1
	(*p1)++;//通过指针使i1数据自增1
	cout << "i1=" << *p1 << endl;//修改成功，输出i1为2
	//end:非c数，非c指

	///begin:c数，非c指
	int i2 = 1, j2 = 2;
	const int* p2 = &j2;//指针p2指向j2，指向的是const int类型的数据
	p2 = &i2;//改变指针指向i2
	cout << "\n指向const数据的非const指针" << endl;
	cout << "i2=" << *p2 << endl;//输出i2为1
	///(*p2)++;//通过指针修改i2数据,errer，这条语句将p2指向的数据进行自增，但是p2指向的是一个const类型的值，值不可被修改
   //i2的值不可被修改
	cout << "i2=" << *p2 << endl;//无法修改，输出i2还是为1
	//end:c数，非c指针

	///begin:非c数，c指
	int i3 = 1, j3 = 1;
	int* const p3 = &j3;//指针指向j3，指向的是int类型的数据，指针是一个const类型
	///p3 = &i3;//无法修改指针指向i3，因为指针p3是一个const类型的指针，无法改变指向
	//p3只能指向j3
	cout << "\n指向非const数据的const指针" << endl;
	cout << "j3=" << *p3 << endl;//输出j3为1
	(*p3)++;//通过指针使j3数据自增
	cout << "j3=" << *p3 << endl;//修改成功，输出j3为2
	//end:非c数，c指针

   ///begin:c数，c指
	int i4 = 1, j4 = 1;
	const int* const p4 = &j4;//指针指向j4，指向的是一个const int类型的数据，指针也是一个const类型
	///p4 = &i4;//无法修改指针指向i4，因为指针p4是一个const类型的指针，无法改变指向
	//p4只能指向j4
	cout << "\n指向const数据的const指针" << endl;
	cout << "j4=" << *p4 << endl;//输出j3为1
	///(*p4)++;//通过指针修改j4数据,errer，这条语句将p4指向的数据进行自增，但是p4指向的是一个const类型的值，值不可被修改
	//j4的值不可被修改
	cout << "j4=" << *p4 << endl;
	//end:c数，c指针
}
#endif

#if _6_3//第六章_实例研究：指针与内置数组
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int* p = a;
	cout << "声明一个数组a[5] = { 1,2,3,4,5 }\t"
		<< "声明一个指针p指向a\n";

	cout << "\n数组名表示元素：" << "\t" << "指针表示元素：\n";
	for (int x = 0; x < 5; x++)
	{
		cout << setw(10) << "a[" << x << "]=" << a[x] << setw(18)
			<< "p[" << x << "]=" << a[x] << "\n";
	}

	cout << "\n数组偏移量表示：" << "\t" << "指针偏移量表示：\n";
	for (int x = 0; x < 5; x++)
	{
		cout << setw(10) << "*(a+" << x << ")=" << *(a + x) << setw(18)
			<< "*(p+" << x << ")=" << *(p + x) << "\n";
	}
}
#endif

#if _6_4//第六章_字符串的初始化和访问
int main()
{
	char c[] = "hello world!";
	const char* pc = "你好，世界！";
	char s[] = "123";
	const char* ps = "123";
	for (int i = 0; i < (sizeof(c)) / sizeof(c[0]); i++)
	{
		cout << "c[" << i << "]=" << c[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < (sizeof(s)) / sizeof(s[0]); i++)
	{
		cout << "s[" << i << "]=" << s[i] << endl;
	}
	cout << endl;
	((s[3] != '\0') && (c[12] != '\0'))
		? (cout << "s[3]和c[12]不是空字符" << endl)
		: (cout << "s[3]和c[12]是空字符" << endl);
	cout << c << "  " << pc << endl;
	cout << s << "  " << ps << endl;
	cout << "c的第四个元素：" << c[3] << endl;
}
#endif

#if _7_1//第七章_Time类的定义
int main()
{
	Time t;
	t.setTime(12, 12, 12);
	t.prtTime24h();
	t.prtTime12h();
}
#endif

#if _7_2//第七章_使用Time类
int main()
{
	Time t;
	cout << "当前时间为：\n";
	t.prtTime12h();
	t.prtTime24h();
	cout << "修改时间：\n";
	t.setTime(12, 25, 52);
	t.prtTime12h();
	t.prtTime24h();
	try
	{
		t.setTime(99, 88, 66);
	}
	catch (invalid_argument& e)
	{
		cout << "错误:" << e.what() << endl;
	}
	cout << "当前时间为：\n";
	t.prtTime12h();
	t.prtTime24h();
}
#endif

#if _7_3//第七章_具有默认实参的构造函数
int main()
{
	Time t0;
	Time t1(13);
	Time t2(13, 34);
	Time t3(13, 34, 55);
	cout << "打印t0的时间" << endl;
	t0.prtTime12h();
	t0.prtTime24h();
	cout << "\n打印t1的时间" << endl;
	t1.prtTime12h();
	t1.prtTime24h();
	cout << "\n打印t2的时间" << endl;
	t2.prtTime12h();
	t2.prtTime24h();
	cout << "\n打印t3的时间" << endl;
	t3.prtTime12h();
	t3.prtTime24h();
	try
	{
		cout << "\n尝试创建一个超出时间范围的对象" << endl;
		Time t5(99, 99, 99);
	}
	catch (invalid_argument& e)
	{
		cerr << "创建对象时已引发错误：" << e.what() << endl;
	}
}

#endif

#if _7_4//第七章_构造函数与析构函数
ca c1(1, "全局，自动\n");
void test();
int main()
{
	cout << "\n\n\t\tmain\tbegin" << endl;
	test();
	cout << "main内创建一个auto对象2" << endl;
	ca c2(2, "main块内，auto");
	cout << "main内创建一个static对象3" << endl;
	static ca c3(3, "main块内，static");
	test();
	cout << "main内创建一个auto对象4" << endl;
	ca c4(4, "main块内，auto");
	test();
	cout << "\t\tmain\tend\n" << endl;
}
void test()
{
	static size_t i = 0;
	cout << "\n\n\t第" << ++i << "次test块内\tbegin" << endl;
	cout << "test内创建一个auto对象5" << endl;
	ca c5(5, "test块内，auto");
	cout << "test内创建一个static对象6" << endl;
	static ca c6(6, "test块内，static");
	cout << "test内创建一个auto对象7" << endl;
	ca c7(7, "test块内，auto");

	cout << "\t第" << i << "次test块内\tend\n" << endl;
}
#endif

#if _7_5//第七章_微妙的陷阱
int main()
{
	simpleTime t;
	unsigned int& d = t.setH(10);
	cout << "置时函数返回值的别名d=" << d << endl;
	cout << "通过成员函数获取私有数据成员的值：" << t.getH() << endl;
	cout << "修改d的值为100" << endl;
	d = 100;
	cout << "通过成员函数获取私有数据成员的值：" << t.getH() << endl;
}
#endif


#if _7_6//第七章_默认的逐个成员赋值
int main()
{
	cout << "创建一个对象date1并给构造函数赋值2001，1，1" << endl;
	Date date1(2001, 1, 1);
	cout << "打印date1：";
	date1.prt();
	cout << "创建一个对象date2构造函数默认实参2025，5，7" << endl;
	Date date2;
	cout << "打印date2：";
	date2.prt();
	cout << "把date1赋值给data2" << endl;
	date2 = date1;
	cout << "打印date1：";
	date1.prt();
	cout << "打印date2：";
	date2.prt();
}
#endif

#if _7_7//第七章_组成
int main()
{
	try
	{
		Comdate d(2025, 2, 2);
		Comtemp t("小红", d);
		d.prt();
		t.prt();
	}
	catch (invalid_argument& e)
	{
		cerr << "输入有误" << e.what() << endl;
	}
}
#endif

#if _7_8//第七章_显式和隐式的使用this指针
using namespace std;
class Test
{
public:
	explicit Test(int = 0);
	void prt();
private:
	int x;
};
Test::Test(int y)
	:x(y)
{
}
void Test::prt()
{
	cout << "隐式使用x:\t\t" << x << endl;
	cout << "显式使用this->x:\t" << this->x << endl;
	cout << "显式使用(*this).x:\t" << (*this).x << endl;
}
int main()
{
	Test t(666);
	t.prt();
}
#endif
#if _7_9//使用this指针串联函数
int main()
{
	Time t;
	cout << "初始化声明对象打印：";
	t.prtTime12h();
	t.prtTime24h();
	cout << "串联三个函数，分别置时分秒，打印：";
	t.setH(13).setM(14).setS(15);
	t.prtTime12h();
	t.prtTime24h();
	cout << "串联两个函数，一次性置时间并串联打印函数：";
	t.setTime(14, 54, 34).prtTime12h();
	t.prtTime24h();
}
#endif

#if _7_10//第七章_静态数据成员的访问
int main()
{
	cout << "未创建对象时，静态成员值：" << stMem::getct() << endl;
	stMem s("小红");
	cout << "主函数中创建一个对象"
		<< s.getName() << "  " << "\t静态成员值：" << stMem::getct() << endl;
	{
		stMem s1("小绿");
		stMem s2("小蓝色");
		cout << "主函数中构建一个块作用域中，创建两个对象:" << s1.getName()
			<< "  " << s2.getName() << "\t静态成员值：" << stMem::getct() << endl;
	}
	cout << "出块作用域时，静态成员值：" << stMem::getct() << endl;
}
#endif


#if _7_11//第七章_使用友元函数修改private数据
class Temp
{
	friend void set(Temp&, int);
public:
	Temp()
		:x(0)
	{
	}
	void prt()const;
private:
	int x;
};
void Temp::prt()const
{
	cout << "数据成员的值为：" << x << endl;
}
int main()
{
	Temp t;
	cout << "声明一个对象t" << endl;
	t.prt();
	cout << "使用友元函数修改值为666" << endl;
	set(t, 666);
	t.prt();
}
void set(Temp& y, int a)
{
	y.x = a;
}
#endif

#if _8_1 //第八章_string类的重载运算符
int main()
{
	string s1("hello");
	string s2("world");
	string s3;
	cout << "声明三个string对象；\n"
		<< "s1=\"" << s1 << "\"\t"
		<< "s2=\"" << s2 << "\"\t"
		<< "s3=\"" << s3 << "\"\t"
		<< endl;
	cout << "开始判断↓：\n"
		<< "s1==s2真的假的？\t" << ((s1 == s2) ? ("真的\n") : ("假的\n"))
		<< "s1!=s2真的假的？\t" << ((s1 != s2) ? ("真的\n") : ("假的\n"))
		<< "s1>=s2真的假的？\t" << ((s1 >= s2) ? ("真的\n") : ("假的\n"))
		<< "s1<=s2真的假的？\t" << ((s1 <= s2) ? ("真的\n") : ("假的\n"))
		<< "s1>s2真的假的？\t\t" << ((s1 > s2) ? ("真的\n") : ("假的\n"))
		<< "s1<s2真的假的？\t\t" << ((s1 < s2) ? ("真的\n") : ("假的\n"))
		<< "s3为空真的假的？\t" << ((s3.empty()) ? ("真的") : ("假的")) << endl;
	if (s3.empty())
	{
		cout << "好s3为空，真的。那我们把s1的值赋给s3\n";
		s3 = s1;
		cout << "现在s1=\"" << s1 << "\"\t"
			<< "s3=\"" << s3 << "\"\t" << endl;
	}
	cout << "接下来s1+=s2，结果为：\n";
	s1 += s2;
	cout << "s1=\"" << s1 << "\"\t"
		<< "s2=\"" << s2 << "\"\t" << endl;
	s1 += "!!!";
	cout << "接下来给s1加个字符串\"!!!\",s1+\"!!!\",s1=" << s1 << endl;
	cout << "接下来从s1的第5个字符，取5个,substr(5,5)=\"" << s1.substr(5, 5) << "\"" << endl;
	cout << "接下来把substr参数换成一个数，substr(10)=\"" << s1.substr(10) << "\"" << endl;
	cout << "新声明一个string对象s4，将s1作为初始化值传进去：\n";
	string s4(s1);
	cout << "s4=\"" << s4 << "\"" << endl;
	s4[0] = 'H';
	cout << "接下来把s4看成内置数组来处理，把大写H赋值给s4[0]\n"
		<< "s4=\"" << s4 << "\"" << endl;
	cout << "接下来使用at函数，s2.at(0)='" << s2.at(0) << "'" << endl;
	s2.at(0) = 'W';
	cout << "再使用at函数，把大写W赋值给s2.at(0)，查看s2=\"" << s2 << "\"" << endl;

	cout << "使用try访问s3下标为30的字符\n";
	try
	{
		cout << "尝试执行语句s3.at(30)='G';\n";
		s3.at(30) = 'G';
	}
	catch (out_of_range& ex)
	{
		cerr << "错误，无法访问s3.at(30):" << ex.what() << endl;
	}
	getchar();
}
#endif
#if _8_2//第八章_重载二元流插入和流提取运算符
int main()
{
	PhoneNumber nb;
	cout << "请输入电话号码格式为(+86) 123 4567 8910：";
	cin >> nb;
	cout << "电话号码为：" << nb;
}
#endif

#if _8_3//第八章_实例研究：Date类
int main()
{
	try
	{
		Date date1;
		cout << "打印date1++的值为：" << date1++ << endl;
		cout << "date1 += 3,date1的值为：";
		date1 += 3;
		cout << date1 << endl;
		cout << "date2赋值为2025年2月28日,打印++date2：";
		Date date2(2025, 2, 28);
		cout << ++date2 << endl;
		cout << "date3赋值为2008年2月28日" << endl;
		Date date3(2008, 2, 28);
		cout << "date3加并赋值1,打印date3的值为：";
		date3 += 1;
		cout << date3 << endl;
	}
	catch (invalid_argument& e)
	{
		cerr << "警告：" << e.what() << endl;
	}
}
#endif

#if _8_4
int main()
{
	Array a1(2);
	cout << "声明一个Array对象a1并传参2，输出为：\n";
	cout << a1;
	cout << "查看a1数组元素的大小：" << a1.getSize() << endl;
	Array a2;
	cout << "声明一个Array对象a2不传参，输出为：\n";
	cout << a2;
	cout << "一次性输入a1和a2的元素，请输入：";
	cin >> a1 >> a2;
	cout << "输出a1的元素:" << endl << a1;
	cout << "输出a2的元素:\n" << a2;
	cout << "判断a1和a2元素是否相等\n";
	if (a1 != a2)
		cout << "不相等\n";
	else
		cout << "相等\n";
	Array a3(a1);
	cout << "再声明一个数组a3，把a1作为参数传入\n"
		<< "a3大小为:" << a3.getSize() << "\n打印a3为:\n"
		<< a3;
	a1 = a2;
	cout << "把a2赋值给a1，输出a1为：\n" << a1
		<< "a2为：\n" << a2;
	cout << "再次判断a1和a2元素是否相等\n";
	if (a1 == a2)
		cout << "相等\n";
	else
		cout << "不相等\n";
	cout << "输出a1的第3个元素：" << a1[2] << endl;
	cout << "把这个元素改为10086，点击回车继续";
	a1[2] = 10086;
	getchar();
	cout << "输出a1的元素:" << endl << a1;
	cout << "点击回车程序继续" << endl;
	getchar();
	try
	{
		cout << "尝试访问a3的第1000个元素：";
		a3[1000] = 2;
	}
	catch (out_of_range& ex)
	{
		cerr << "警告！！！" << ex.what() << endl;
	}
	cout << "点击回车程序继续" << endl;
	getchar();
	try
	{
		cout << "尝试新创建一个数组a4,设置大小为-1：";
		Array a4(-1);
	}
	catch (invalid_argument& e)
	{
		cerr << "警告！！！" << e.what() << endl;
	}
}
#endif

#if _9_1
int main()
{
	try
	{
		Cmsepl ep("李慧", "6859 2569 145", 3000, -0.6);
		ep.prt();
		cout << "收入" << ep.income() << endl;
		getchar();
		return 0;
	}
	catch (invalid_argument& e)
	{
		cerr << "警告：" << e.what() << endl;
	}
}
#endif


#if _9_2
int main()
{
	try
	{
		BPcmsepl bp("李慧", "6585 5245 6956", 1500, 0.3, 3000);
		bp.prt();
		cout << "收入为：" << bp.income() << endl;
		return 0;
	}
	catch (invalid_argument& e)
	{
		cerr << "警告：" << e.what() << endl;
	}
}
#endif


#if _9_3
int  main()
{
	try
	{
		BPP bp("李慧", "4558 5225 7848", 3000, 0.5, 4000);
		bp.prt();
		cout << "收入：" << bp.income() << endl;
		getchar();
	}
	catch (invalid_argument& e)
	{
		cerr << "警告：" << e.what() << endl;
	}

}
#endif
#if _10_1//第十章_从派生类对象调用基类函数（将基类指针指向派生类对象）
int main()
{
	//声明一个Cmsepl对象ce1和BPP对象bp1，并赋初值
	Cmsepl ce1("张瑞雪", "6599 849648494", 4000, 0.5);
	BPP bp1("李慧", "1616 486454165", 3000, 0.3, 2500);
	//在定义两个Cmsepl类型和BPP类型的指针
	Cmsepl* ceptr = nullptr;
	BPP* bpptr = nullptr;
	//打印这两个对象
	cout << "张瑞雪的部分工资：\n";
	ce1.prt();
	cout << "\n李慧的全部工资：\n";
	bp1.prt();
	//将刚刚定义的指针分别指向这两个对象
	ceptr = &ce1;
	bpptr = &bp1;

	cout << "\n通过指针调用各自的ptr函数进行打印" << endl;
	cout << "张瑞雪的部分工资：\n";
	ceptr->prt();
	cout << "\n李慧的全部工资：\n";
	bpptr->prt();

	cout << "\n将原本指向张瑞雪类型的指针指向李慧\n";
	ceptr = &bp1;
	cout << "调用张瑞雪类型的指针打印工资，究竟是谁的呢？\n\n";
	cout << "↓↓↓↓↓↓↓↓\n";
	ceptr->prt();
}
#endif
#if _10_2//第十章_将派生类指针指向基类对象
int main()
{
	Cmsepl ce1("张瑞雪", "6599 849648494", 4000, 0.5);
	BPP bp1("李慧", "1616 486454165", 3000, 0.3, 2500);
	BPP* bpptr = nullptr;
	//bpptr=&ce1;//error
}
#endif
#if _10_3//第十章_C-BP层次中的virtual函数
int main()
{
	Cmsepl* ceptr = nullptr;
	Cmsepl ce1("张瑞雪", "165165 165161", 500, 0.6);
	BPP bp1("李慧", "44984 84984984", 5000, 0.5, 2500);
	ceptr = &bp1;
	//动态绑定
	ceptr->prt();
	ceptr->income();
	puts(""); puts("");

	ceptr = &ce1;
	//动态绑定
	ceptr->prt();
	ceptr->income();


}
#endif
#if _10_4//第十章_实例研究：应用多态性的工资发放系统
int main()
{
	cout << fixed << setprecision(2);
	Slrepl a1("李慧", "9438984", 3000);
	Comsepl a2("张瑞雪", "8357345983", 5738, 0.5);
	Bpce a3("高云龙", "3857293", 9999, 0.9, 20000);
	cout << "分别声明了三个具体类的对象：固定薪资雇员，提成雇员，提成+底薪雇员\n" << endl;
	cout << "静态绑定，通过各自调用各自的prt和income函数打印信息如下：\n";
	a1.prt();
	a1.income();
	puts("");
	a2.prt();
	a2.income();
	puts("");
	a3.prt();
	a3.income();
	puts("");
	int oiiioi = getchar();
	//声明一个大小为3的vector对象eplPtr，里面放的是Epl*类型的元素
	//指针数组
	vector<Epl*>eplPtr(3);
	eplPtr[0] = &a1;//第一个指针指向对象a1
	eplPtr[1] = &a2;//第2个指针指向对象a2
	eplPtr[2] = &a3;//第3个指针指向对象a3
	puts("");
	cout << "动态绑定，通过遍历数组中存放的每个对象的地址，箭头运算符访问prt成员打印信息如下：\n";
	for (const Epl* ep : eplPtr)
	{
		ep->prt();//打印a1的信息
		ep->income();//打印a1的信息
	}
	oiiioi = getchar();
	puts("");
	cout << "动态绑定，通过遍历数组中存放的每个对象的地址，成员运算符访问prt成员打印信息如下：\n";
	for (const Epl* ep : eplPtr)
	{
		(*ep).prt();//打印a1的信息
		(*ep).income();//打印a1的信息
	}
}
#endif
#if _10_5//第十章_实例研究：应用向下强制类型转换、dynamic_cast、typeid、和type_info并使用多态性和运行时类型信息的工资发放系统
int main()
{
	cout << fixed << setprecision(2);
	vector<Epl*>eplPtr(3);//定义三个基类类型的指针
	eplPtr[0] = new Slrepl("李慧", "9438984", 3000);//给每个派生类动态分配内存，地址为基类类型
	eplPtr[1] = new Comsepl("张瑞雪", "64648984", 5800, 0.5);//派生类的对象可以用基类指针指
	eplPtr[2] = new Bpce("高云龙", "3857293", 9999, 0.9, 20000);//但不能通过指针访问派生类独有的成员
	for (Epl* epl : eplPtr)//遍历这个基类指针数组
	{
		//打印每个指针的prt函数
		epl->prt();
		cout << endl;
		//定义一个Bpce类型的指针，将此时的指针强转为Bpce类型
		Bpce* bpcePtr = dynamic_cast<Bpce*>(epl);
		if (bpcePtr != nullptr)//说明指向了Bpce类型的对象
		{
			static bool tempbool = true;
			if (tempbool)
			{
				cout << "打印一次bpcePtr对象的信息\n" << endl;
				bpcePtr->prt();
				tempbool = false;
			}
			double oldslr = bpcePtr->getslr();
			cout << "\n以前的底薪为：" << oldslr << endl;
			bpcePtr->setslr(oldslr * 1.1);
			cout << "\n加薪后的员工信息为：" << endl;
			bpcePtr->prt();
		}
	}
	size_t i = 0;
	for (Epl* epl : eplPtr)
	{
		cout << "第" << ++i << "个对象的类型为："
			<< typeid(*epl).name() << endl;
	}
	puts("");
	eplPtr[2]->income();
	while (i)
	{
		delete eplPtr[3 - i--];
	}
	//eplPtr[2]->income();//内存已经被释放，这样做会炸刚
	bool oiiioi = getchar();
}
#endif
//默认实参
#include <iostream>


//在函数声明时 将形参赋值
int add_3(int a = 10, int b = 10, int c = 10, int d = 10)
{
	return a + b + c + d;
}

int main()
{
	std::cout << "add_3=" << add_3() << std::endl;
}



#endif//总

