# 一、C++,一个更好的C

## 0.引言

```cpp
/*
C++文件后缀为.cpp
C中的#include<stdio.h>在C++中为#include<iostream>
OOP面向对象编程(Object-oriented programming)
输入流——流进来,输出流——流出去
*/
...over
```

## 1.C++与C的部分差异（相较于C的特性）

### 1.1 对象

> 由类的创建的具体实例

### 1.2 面向对象

> 主要是针对数据和函数进行管理(和操作)

### 1.3 类

> 自定义的一个板块,存放数据和函数,并且读写都有不同访问权限,相当于蓝图,用来创建对象

### 1.4 继承

> 在已有类的基础(属性和方法)之上,拓展其他功能

### 1.5 多态性

> 同个函数(或功能),在不同的其他函数(或功能),来实现不同的功能(同一接口实现不同功能)

### 1.6 封装

> 隐藏一个板块(类)中的数据细节(部分重要信息,不可更改的变量、数据),仅保留接口(需要改变的变量、数据)

### 1.7 重载

> 一个函数名参数不同可重复使用

### 1.8 运算符重载

> 自定义运算符功能实现对类对象的操作

### 1.9 auto占位类型

> auto类型可根据变量的值自动推导类型，复杂场景可自动识别类型，如函数指针：
>
> ```cpp
> /*****/
> int sum(int a,int b)
> {
>     return a+b;
> }
> //定义一个指针指向这个函数
> 
> //C中定义函数指针
> int (*p)(int ,int)
> p = sum;
> //C++中
> auto p = sum;
> ```

### 1.10 新增类型（类）

> bool布尔类型：
>
> ​	布尔类型只有两个值TRUE（真 非零值）、FALSE（假 零值），一般情况下`sizeof(bool)为1`
>
> ​	节省空间、易读。用于条件判断和函数返回
>
> string字符串类型（类）：
>
> ​	第二章、第八章详解

### 1.11 结构体

> C++中结构体可以定义成员函数（普通函数、构造函数、析构函数）
>
> 声明结构体后，定义结构体变量可直接省略`struct`关键字
>
> 结构体中有访问权限，默认为public，可设置为private和protected，第二章第二节详解访问修饰符（访问说明符）
>
> 支持继承、多态（virtual、虚函数等）

### 1.12 联合体

> 声明后定义变量也可忽略关键字`union`

### 1.13 枚举

> 声明后定义变量也可忽略关键字`enum`
>
> 通常情况下sizeof()为4
>
> 定义普通枚举类型是没有作用域的，程序中都可直接访问： `enum Start {ON,OFF};`
>
> 当有同名枚举值，该枚举类型的变量是有作用域的枚举变量，通过`class`来给作用域：
>
> `enum class Color1{x,y,z};` 
>
> `enum class Color2{x,y,z};`
>
> 访问时：`Color1::x;` `Color2::z` 
>
> 枚举类型可指定大小，通过在类型名后加`:目标类型`，可以将枚举类型大小改为目标类型的大小，eg： `enum Color:char{X,Y}; //sizeof为1`
>
> 不可使用流操纵符打印枚举值（流操纵符在第四节详解）

### 1.14 for

> 详见第五章1.3节——基于范围的for

## 2.main函数

与C程序相同,C++中的程序入口也是main函数,C++中可以不写返回值 `return` (仅限于main函数)

## 3.头文件

标准输入输出流头文件 `#include<iostream>` 

C++中包含头文件没有 `.h` ,若要包含C语言中相关的头文件,如下：

`#include<cxxxxx>` "xxxx"为C语言中的头文件名(stdio、stdlib、string、math等)

## 4.标准输入(输出)流

### 4.1 标准输出流

> 标准输出流对象 `std::cout` 
>
> 流插入运算符 `<<` 
>
> 等价于C中`printf`
>
> `<<`后接表达式或双引号`""`引起来的文本,但双引号和文本不能写在一块,文本与表达式之间需要用流插入运算符隔开(输出不同数据类型需要用流插入运算符隔开,成为级联流插入操作)
>
> `std::endl`  流操纵符,功能：换行+清空输出缓冲区(将endl控制的输出流语句立即输出并换行,确保endl后的代码一定执行,不会卡在缓冲区)
>
> `std::out<<std::oct; //控制后续整形流输出为八进制`
>
> `std::out<<std::dec; //控制后续整形流输出为十进制`
>
> `std::out<<std::hex; //控制后续整形流输出为十六进制`
>
> 小数控制第三章2.2详解

### 4.2 标准输入流

> 标准输入流对象 `std::cin` 
>
> 流读取运算符 `>>` 
>
> 等价于C中`scanf`
>
> `>>`后接变量,只能接一个(多个变量用流读取运算符隔开)

### 4.3 'std::'

std为命名空间,命名空间中有个名字叫cout和cin和endl(命名空间为C++高级特性,后期学习)

C++中引入 `using` (**C++中的一个关键字**)语句,可简化有关输入输出流代码的编写,如下：

```cpp
/*。。。*/
using std::cout;//后续关于流输出操作,可直接将std::cout写成cout,cin和endl同理
/*。。。*/
using namespace std;//后续关于所有流操作都可省去std::
...over
```

## 5.内联函数(inline)

在自定义的**函数体（一定要是函数体）**  ， 前面加`inline` (**C++中的一个关键字**)

内联函数可以理解为高级版的宏，所以也要像宏一样：

> 1.内联函数需要定义在使用它的函数前面，比如main函数中用到了内联函数，就需要在main函数之前定义内联函数
>
> 2.内联函数一般写在头文件中，直接将函数体写在头文件，所以内联函数的声明没有意义
>
> 3.就把内联函数当做高级版的宏来定义和处理

在代码执行时,调用内联函数时相当于直接把函数体替换到了正在执行的代码中,而不是调用。(执行效率+,程序规模-)

函数是否内联取决于编译器，有些编译器可能高级，一些简单的函数不声明为内联函数，也会被视为内联函数展开。但是gcc需要显式的声明

注意：

> 1.简洁,不能太过于复杂
>
> 2.频繁被调用
>
> 3.不能有循环
>
> 4.不能有过多的条件判断
>
> 5.函数体不能过于庞大

```cpp
#include <iostream>
using namespace std;
/*	按引用传参相当于给变量重新取了一个名字，实参和形参操作的是同一个变量
	引用传参时 实参必须是已经初始化的值 所以在这里a和b必须已经初始化
	内联函数不需要单独声明 而是要把函数体写在每个.cpp（使用内联函数）的前面
	内联函数一般直接定义在头文件中	*/
inline int my_add(int a , int b)
{
    int c = a + b;
    return c;
}

int main()
{
    z = my_add(a,y);
    /*
        内联函数，函数体直接在代码中展开，等价于：
        int c = a + b;
        z = c;
    */
    cout<<z<<endl;
    return 0;
}
```

## 6.引用形参

### 6.1 按引用传参

调用函数时,一般情况下为按值传递,形参作为实参的副本，所以形参的改变并不会影响实参的值

在函数声明和函数定义可使用 `&` 标记为按引用传参,形参即可作为实参的另一个名字(引用取别名),形参实参访问的事同一个变量

```cpp
/*。。。*/
void add(int &a,int &b);//函数声明时在变量名前加&
/*。。。*/
//声明和定义必须都写&
void add(int &a,int &b)//函数定义时,函数头在变量名前加&
{
    /*...*/
}
/*。。。*/
int main()
{
    /*。。。*/
    int x=0 , y=0;
    cin>>x>>y;
    add(x,y);//函数实参和形参访问的是同一变量，前提是实参已初始化
}
```

**按引用传参前提是原变量名已初始化**

### 6.2 函数体内引用

同理，变量按引用作为参数时，实参名和形参名控制的是同一变量。那么在函数体内,将旧变量名x 赋值 给&加新变量名y(&y=x),表示x与y两个变量名访问的是相同的变量，只是变量名不同共同的值,,前提是旧的变量名已初始化。

## 7.默认实参

在自定义的函数中,需要并且只能是在**声明时**将形参赋值,那么在调用函数时,不传参的话,将函数声明时候的值作为参数传进去。

```cpp
#include <iostream>
using namespace std;
int add(int a=1,int b=2,int c=3);//函数声明时指定默认实参
int main()
{
    cout<<add()<<endl;//6
}
int add(int a,int b,int c)
{
    return a+b+c;
}

/******或者可以直接把函数体写在前面******/
/*
int add(int a=1,int b=2,int c=3)
{
    return a+b+c;
}
int main()
{
    add();//6
}
//一般不这样写
*/
```

传参时传参数可为0~定义参数数,上述例子中传参个数可以为：0~3,若传参数小于定义参数数时,传参至按照形参顺序从左往右传。

```cpp
#include <iostream>
using namespace std;
int add(int a=1,int b=2,int c=3);//函数声明时指定默认实参
int main()
{
    cout<<add()<<endl;//6
    cout<<add(10)<<endl;//10+2+3
    cout<<add(10,10)<<endl;//10+10+3
    cout<<add(10,10,10)<<endl;//10+10+10
}
int add(int a,int b,int c)
{
    return a+b+c;
}
/*
PS E:\VScode C++\Unit1> .\a.exe        
6
15
23
30
*/
```

## 8.一元作用域运算符`::`

 在C中，全局变量和局部变量同名时，在局部变量的作用域内直接使用变量名，访问到的是局部变量。一元作用域运算符,是用于在局部变量的作用域内访问全局变量,在同名变量前加`::`即可。

```cpp
#include <iostream>
using namespace std;
int a=10;
int main()
{
    int a=10086;
     cout <<"局部a=" << a << "\n" 
      <<"全局a=" << ::a << endl;
}
//运行结果
/*
局部a=10086
全局a=10
*/
```

## 9.函数重载

可定义同名的函数,参数个数或者参数类型必须不同。但**无法仅通过返回值类型区分重载函数**。eg：

```cpp
#include <iostream>
using namespace std;
//四个同名函数 默认实参为1
void add(int a, int b);//两个整数的加法
void add(int a, int b, int c);//三个整数的加法
void add(double a, double b);//两个小数的加法
void add(double a, double b, double c);//三个小数的加法
//int add(int a, int b);//error 无法重载仅按返回类型区分的函数
int main()
{
    add(5,5);//两个整数的加法
    add(5,5,5);//三个整数的加法
    add(5.1,5.1);//两个小数的加法
    add(5.1,5.1,5.1);//三个小数的加法
}
//两个整数的加法
void add(int a,int b)
{
    cout<<"input two int:";
    cout<<a<<"+"<<b<<"="<<a+b<<endl;
}
//三个整数的加法
void add(int a, int b, int c)
{
    cout<<"input three int:";
    cout<<a<<"+"<<b<<"+"<<c<<"="<<a+b+c<<endl;
}
//两个小数的加法
void add(double a,double b)
{
    cout<<"input two folat:";
    cout<<a<<"+"<<b<<"="<<a+b<<endl;
}
//三个小数的加法
void add(double a,double b,double c)
{
    cout<<"input three folat:";
    cout<<a<<"+"<<b<<"+"<<c<<"="<<a+b+c<<endl;
}
/*
PS E:\VScode C++\Unit1> .\a.exe
input two int:5+5=10
input three int:5+5+5=15
input two folat:5.1+5.1=10.2
input three folat:5.1+5.1+5.1=15.3
*/
```

**前半部分所有内容将以名为`Gradebook`的类来进行拓展!**

# 二、类、对象和字符串

## 0.引言

类≈结构体,对象≈结构体变量

对象是类的实例,创建好类以后,给这个类取个名字,再使用这个类就是对象。

```cpp
eg：
     类				人					矩形
    对象			  某个人 	 			某个矩形
    属性			身高、体重、年龄……		长、宽、面积……
    
可以看做：
    struct Str	------>	  Str可以看做类
    {
        int x;
        char ch;
        /***/
    }
struct Str st; 	------>	  st看作是Str类的实例，也就是对象
    
```



## 1.类的定义

`class` (**C++中的一个关键字**)后空格,紧跟类名,类名第一个字母通常为大写,更好区分,花括号 `{}` 内,叫做类的体,类的定义以分号 `;` 结束,类中定义的函数叫类的成员函数,类中定义的数据叫数据成员

```cpp
//类的定义语法
class 类名
{
    访问修饰符:
    	成员1;	--->	成员由成员类型和成员名构成
    	成员2;
    /*成员分为属性成员和行为成员
    属性成员：数据成员，一般为变量，如：学号、姓名……
    行为成员：成员函数，一半为函数，对数据成员操作的方法，如：打印信息
    */ 	
};
```

### 1.1 数据成员

> 类中定义的变量,用于描述对象的属性或者状态

### 1.2 成员函数

> 类中定义的函数,用于操作数据成员或实现对象的行为

```cpp
/*。。。*/
class Gradebook
{
public:/*...*/
private;/*...*/
protected:/*...*/
};
```

## 2 .类的成员访问说明符（访问修饰符）public和private

### 2.1 public(公有的)

> 在类中`public`  (**C++中的一个关键字**)后声明的内容(函数或变量等,一般为函数)(成员函数),表示公共的
>
> 作用域：在其他函数或其他类的成员函数中可以使用和访问。程序任何地方都可以访问。
>
> 成员访问说明符后要加冒号 `:` 
>
> ```cpp
> #include<iostream>
> using namespace std;
> class Gradebook
> {
> public:
>  void welcome()
>  {
>      cout<<"欢迎你呀！！！"<<endl;
>  }
>  
> };
> int main()
> {
>  Gradebook wel;//创建了一个名为wel的对象,Gradebook类的实例
>  wel.welcome();//调用wel对象的成员函数welcome
> }
> ```
>
> 定义完类之后要创建该类的实例(对象),才能访问成员,调用成员函数。自己定义的每一个类相当于一个新的类型,该类的实例(对象)相当于变量。

### 2.2 private(私有的)

> `private` (**C++中的一个关键字**)后声明的内容(函数或变量等,一般为变量)(数据成员),表示私有的,
>
> 作用域：只可以被同一个类中的成员函数所访问(或友元,后面介绍)
>
> ```cpp
> #include<iostream>
> using namespace std;
> class Gradebook
> {
> public:
> int a = 333;//公有数据成员a
>  int hello()
>  {
>      b -= 333;//成员函数可直接访问私有成员
>      return b;//从而在其他函数中间接访问到私有成员b的值
>  }
> private:
> int b = 666;//私有数据成员b
> };
> int main()
> {
>     Gradebook wel;//创建了一个名为wel的对象,类的实例
>      cout  << wel.a + 100 << endl;//输出333+100的值,可以直接访问公有成员a
>      cout << wel.b + 100 << endl;”//error,外部函数无法直接访问私有成员b
>      cout  << wel.hello() << endl;//间接输出私有成员b的值
> }
> ```

**class中若未声明成员变量访问权限,则默认为private私有**

**struct中若未声明成员变量访问权限,则默认为public公有**

### 2.3 protected(受保护的)

> protected (**C++中的一个关键字**)后声明的内容(函数或变量等,一般为变量)(数据成员),表示受保护的
>
> 作用域：比private多了一个，派生类(子类)可以访问

**通常情况下数据成员为private/protected,而成员函数为public,通过成员函数来访问数据成员**

## 3 .定义有形参的成员函数

与C语言中类似。定义成员函数时,直接在函数头中定义好参数,然后调用成员函数时传实参进去。

```cpp
#include<iostream>
using namespace std;
class Gradebook
{
public:
    void welcome(int x)
    {
        cout << "欢迎你呀！！！\n" <<x<< endl;
    }

};
int main()
{
    Gradebook wel;
    int a=666;
    wel.welcome(a);
}
```

## 4.字符串

#### · string

> `string` 为C++中的一个处理字符串的**类**,简单用法可以用来表示字符串类型(和 `int`    `char` 等类型使用方式相同 )
>
> 它和 `cout` `cin` `endl` 类似,都属于命名空间 `std::` ,使用时需写清命名空间,如 `std::string` ,但同样 `using namespace std;` 指令可以省略所有的 `std::`。
>
> 使用时需要包含头文件 `#include<string>`。
>
> eg: `std::string ch="hello word!!!";`
>
> 若未初始化字符串变量,则默认为空字符串,输出时为空白
>
> 1）赋值方式：
>
> ​	>>等号赋值—— `string 变量=“字符串”`; —— `string str1 = "abc";`
>
> ​	>>括号赋值—— `string 变量("字符串");` —— `string str2("abc");`
>
> ​	>>相互赋值—— `str3 = str2;` `str4(str1);`
>
> ​	>>重复赋值—— `string str5(n,'x');`n为int ,x为char。表示字符串为x个n：`string str5(4,'f');//"ffff"`
>
> 2）常用接口（方法）
>
> ​	定义：`string str1;` `string* str2; `
>
> ​	>>计算字符串长度(不包含`\0`)：`size()`、`length()`
>
> 使用：`str1.size();` 或 `str1.length(); ` 
>
> ​			`str2->size();` 或 `str2->length;`
>
> ​			`string类型不可用strlen函数，strlen(const char*)`
>
> ​	>>判断字符串是否为空：`empty()`
>
> 使用：`str1.empty(); ` 
>
> ​			`str2->empty() ` 
>
> ​	>>获取指定下标字符：`at()`、 `[]`
>
> 使用：`str1.at(x);` 或 `str1[x]`
>
> ​			`str2->at(x);`
>
> ​			获取字符串中第x的字符（从0开始）
>
> ​	>>将`string`类型转换为`const char*`,C风格的字符串：`c_str()`
>
> 使用：`str1.c_str();`
>
> ​			`str2->c_str();`
>
> ​			`typeof()`为`const char*`,例如使用`open()`函数时就需要这个方法
>
> ​	>>还可以使用部分运算符，第八章详解

#### · getline()

> 函数原型`getline(char* s, streamsize count, char delim = '\n);`
>
> 含义,读取输入流 `s` ()中的一整行文本  `count` (为字符串或字符数组) ,直到遇到换行符或 `\n` 停止
>
> eg: `getline(cin,line);`//从标准输入读取文本到 `line` 里,(`line`为`string`类型)
>
> **getline避免了cin读数据时遇到空格或其他特殊字符停止的问题,getline可以读取任何特殊字符,除非遇到换行或‘\n’才停止输入**

## 5.构造函数&析构函数

**构造函数**

构造函数一般用于初始化类的数据成员,与类同名,不能返回值,每一个类都有一个或多个构造函数,**对象创建时自动调用构造函数**

```cpp
class Gradebook
{
public:
    explicit Gradebook(string name)
        :courseName(name)
        {
            
        }
private:
    string courseaname;
}
int main()
{
    Gradebook book("liuliuliu");
}

/**********CS2526F*********/
语法：
    	类名(参数列表)
        {
            //...语句
        }
注意
    1.函数名必须和类名一致
    2.可以带参数也可以不带
    3.没有返回值，void也不行
    4.创建对象时会自动调用
    5.可以有多个构造函数，表示多重的不同的初始化方法(参数不同：类型或个数)
    6.类必须有构造函数，不写的话编译器自动生成一个不带参数的构造函数
    
初始化：
    class Circle{xxx};
Circle a();
Circle b(2);
Circle{};
Circle{2};//花括号也可

JuX(int x)
    :y(x)
    
```

`explicit` 表示必须显式调用构造函数(初始化时必须用括号传参初始化)

不加也可以，可以用等号初始化，但过程就不一样了

**析构函数**

构造函数一般用于销毁对象,构造函数名前`~`,不能返回值,每一个类**仅有一个析构函数**,**对象销毁时自动调用析构函数**

```cpp
class Gradebook
{
public:
    explicit Gradebook(string name)
        :courseName(name)
        {}
    ~Gradebook();//析构函数
private:
    string courseaname;
}
int main()
{
    Gradebook book("liuliuliu");
}
```



### 5.1 构造函数初始化成员

写完构造函数后 `:` 后为初始化列表,对需要初始化的成员进行赋值 `成员名1(赋的值1),成员名2(赋的值2),……` 。 

`{}` 函数体内也可进行赋值 `成员名1=赋的值1,成员名2=赋的值2,……` ,但对特殊成员 (`const`、引用成员、无默认构造的成员) 无法赋值。**一般情况下不使用这种方法初始化数据成员，而是在初始化列表中初始化，函数体可直接实现功能**

类初始化对象时不加括号构造函数就使用的是默认实参，**加括号就必须传参给构造函数**

```cpp
class Lei
{
public:
    Lei(int a,int b,int c);
    ~Gradebook();//析构函数
private:
    int x;
    int y;
    int z;
};

Lei::Lei(int a,int b,int c)
    :x(a),y(b),z(c)
{
    //....
}
```

### 5.2 默认参数

默认参数：**声明函数时**，可以给形参赋值一个默认值,表示如果不赋值则使用这个默认值

```c
class Cls
{
    Cls(int = 10);//构造函数声明
};
//构造函数实现
Cls::Cls(int a)
    :
{}
```

默认的参数要保证靠右原则，意思就是指定参数时，**右边的参数不能空着**,只要左边的形参有初始值则右边一定得有

```cpp
class Lei
{
public:
    Lei(int a,int b,int c=3);//yes
    Lei(int a,int b=2,int c=3);//yes
    Lei(int a=1,int b,int c);//no
    Lei(int a=1,int b=2,int c);//no
    Lei(int a=1,int b,int c=3);//no
};
```

### 5.3 多构造函数

可以定义多个构造函数（函数重载），根据新参数量或者类型来区分，创建对象根据传入的形参数来决定调用哪个构造函数

```cpp
#include <iostream>
#include <cstdio>

using namespace std;

class Lei
{
public:
    Lei();//构造函数1
    Lei(int a);//构造函数2
    Lei(int a, int b);//构造函数3
    void Prt()const;//打印数据成员
    ~Lei();//析构函数
private:
    int a;
    int b;
};
Lei::Lei()
    :a(0), b(0)
{
    std::cout << "构造函数1:Lei()" << std::endl;
}
Lei::Lei(int a)
    :a(a), b(0)
{
    std::cout << "构造函数2:Lei(int a)" << std::endl;
}
Lei::Lei(int a, int b)
    :a(a), b(b)
{
    std::cout << "构造函数3:Lei(int a,int b)" << std::endl;
}
void Lei::Prt()const
{
    std::cout << "a=" << a << "\nb=" << b << std::endl;
}

Lei::~Lei()
{
    std::cout << "对象已析构" << std::endl;
}


int main()
{
    //Lei a0();//error,构造函数无参数不需要加括号，加括号就必须传参
    Lei a1;//调用构造函数1
    a1.Prt();
    Lei a2(1);//调用构造函数2
    a2.Prt();
    Lei a3(1, 2);//调用构造函数3
    a3.Prt();
}

/*************************
构造函数1:Lei()
a=0
b=0
构造函数2:Lei(int a)
a=1
b=0
构造函数3:Lei(int a,int b)
a=1
b=2
对象已析构
对象已析构
对象已析构
*/
```

多个构造函数时，定义对象时不可以有歧义

```c
class Cls
{
    //构造函数1
    /*
    	1.支持无参数
    	2.支持一个参数
    */
    explisit Cls(int = 10);
    
    //构造函数2
    /*
    	1.支持一个参数
    	2.支持两个参数
    */
    explisit Cls(int ,int = 30);
};

//主函数
int main()
{
    //定义对象
    Cls cs;//调用构造函数1
    Cls cs1(1,2);//调用构造函数2
    Cls cs2(1);//error
}
```

### 5.4 动态内存分配：new

`new`关键字用于在堆中创建一个对象，并返回其首地址；`delet`用于释放这个对象

用法：	`类名 *指针变量名 = new 类名;//开辟一段内存空间，创建一个对象。释放时：delet 指针变量名`

​				`类名 *指针变量名 = new 类名(构造函数参数列表);//开辟一段内存空间，创建一个对象并传参。释放时：delet 指针变量名`

​				`类名 *指针变量名 = new 类名[对象个数] {构造函数参数列表};//开辟一组连续的内存空间，并在这个内存空间创建对象。释放时：delet[] 指针变量名`

**new创建对象时会调用构造函数**,不主动delete是不会释放资源（不会调用析构函数）

```cpp
#include <iostream>
#include <cstdio>

using namespace std;


class Lei
{
public:
    Lei();//构造函数1
    Lei(int a);//构造函数2
    Lei(int a, int b);//构造函数3
    void Prt()const;//打印数据成员
    ~Lei();//析构函数
private:
    int a;
    int b;
};
Lei::Lei()
    :a(0), b(0)
{
    std::cout << "构造函数1:Lei()" << std::endl;
}
Lei::Lei(int a)
    :a(a), b(0)
{
    std::cout << "构造函数2:Lei(int a)" << std::endl;
}
Lei::Lei(int a, int b)
    :a(a), b(b)
{
    std::cout << "构造函数3:Lei(int a,int b)" << std::endl;
}
void Lei::Prt()const
{
    std::cout << "a=" << a << "\nb=" << b << std::endl;
}
Lei::~Lei()
{
    std::cout << "对象已析构" << std::endl;
}
int main()
{
    Lei* a1_ptr = new Lei;//调用构造函数1
    a1_ptr->Prt();//也可以用(*a1_ptr).Prt()
    Lei* a2_ptr = new Lei(1);//调用构造函数2
    (*a2_ptr).Prt();//也可以用a2_ptr->Prt();
    Lei* a3_ptr = new Lei[5]{ {1,2},{3,4},{5,6},{7,8},{9,0} };//调用构造函数3
    (a3_ptr[0]).Prt();
    (a3_ptr[1]).Prt();
    (a3_ptr[2]).Prt();
    (a3_ptr[3]).Prt();
    (a3_ptr[4]).Prt();
}
/*************************************
构造函数1:Lei()
a=0
b=0
构造函数2:Lei(int a)
a=1
b=0
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
a=1
b=2
a=3
b=4
a=5
b=6
a=7
b=8
a=9
b=0
*/
```

**delete释放对象时会调用析构函数**

```cpp
#include <iostream>
#include <cstdio>

using namespace std;


class Lei
{
public:
    Lei();//构造函数1
    Lei(int a);//构造函数2
    Lei(int a, int b);//构造函数3
    void Prt()const;//打印数据成员
    ~Lei();//析构函数
private:
    int a;
    int b;
};
Lei::Lei()
    :a(0), b(0)
{
    std::cout << "构造函数1:Lei()" << std::endl;
}
Lei::Lei(int a)
    :a(a), b(0)
{
    std::cout << "构造函数2:Lei(int a)" << std::endl;
}
Lei::Lei(int a, int b)
    :a(a), b(b)
{
    std::cout << "构造函数3:Lei(int a,int b)" << std::endl;
}
void Lei::Prt()const
{
    std::cout << "a=" << a << "\nb=" << b << std::endl;
}
Lei::~Lei()
{
    std::cout << "对象已析构" << std::endl;
}
int main()
{
    Lei* a1_ptr = new Lei;//调用构造函数1
    a1_ptr->Prt();//也可以用(*a1_ptr).Prt()
    Lei* a2_ptr = new Lei(1);//调用构造函数2
    (*a2_ptr).Prt();//也可以用a2_ptr->Prt();
    Lei* a3_ptr = new Lei[5]{ {1,2},{3,4},{5,6},{7,8},{9,0} };//调用构造函数3
    (a3_ptr[0]).Prt();
    (a3_ptr[1]).Prt();
    (a3_ptr[2]).Prt();
    (a3_ptr[3]).Prt();
    (a3_ptr[4]).Prt();
    delete a1_ptr;
    delete a2_ptr;
    delete [] a3_ptr;
}
/*************************************
构造函数1:Lei()
a=0
b=0
构造函数2:Lei(int a)
a=1
b=0
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
构造函数3:Lei(int a,int b)
a=1
b=2
a=3
b=4
a=5
b=6
a=7
b=8
a=9
b=0
对象已析构
对象已析构
对象已析构
对象已析构
对象已析构
对象已析构
对象已析构
*/
```

**malloc和new的区别**

- new在堆中创建一个对象并返回其指针，malloc在堆中分配一块指定大小的内存空间并返回其首地址
- new会调用对象的构造函数，malloc仅在堆中分配一块内存空间，不会创建对象
- new是使用delete来释放对象，malloc是使用free释放内存空间

### 5.5 this指针

C++中类的每个非静态成员函数，都隐藏了一个this指针，this指针指向调用这个成员函数的对象的地址 。用于区分是那个对象调用的函数

```cpp
#include <iostream>

class Lei
{
public:
    Lei(int _a,int _b);
    int func();
private:
    int a;
    int b;
};

Lei::Lei(int _a,int _b)
    :a(_a),b(_b)
{}
int Lei::func()
{
    return this->a + this->b;//this->a+this->b
}
int main()
{
    Lei a1(1,2);
    Lei a2(3,4);
    std::cout<<a1.func()<<std::endl;//==>&a1 = this
    std::cout << a2.func() << std::endl;
}
/**********************
3
7
*/
```



## 6.头文件与类

将类定义在头文件里,可以在主文件包含类的头文件对类直接访问并创建对象,为防止重复包含,`using name space;`只能在主文件使用,所以头文件的标准流操作必须写完整,包括std命名空间 

```cpp
//class.h
#include<iostream>
#include<string>
class Gradebook
{
public:
    explicit Gradebook(std::string name)
        :courseName(name)
        {}
    std::string put()
    {
        return courseName;
    }
private:
    std::string courseName;
};
```

```cpp
//test.c
#include<iostream>
#include<string>
#include"class.h"
using namespace std;
int main()
{
    Gradebook book("hello!");
    Gradebook books("welcome!");
    cout<<book.put()<<endl;
    cout<<books.put()<<endl;
}
```

使用头文件中的类时,需要包含自己定义的头文件,就等价于把头文件里的东西搬移到主文件中。包含时必须使用双引号, `""` 代表从当前工程(文件)开始找该头文件然后再到库找。尖括号 `<>` 代表这个文件为标准库的一个文件,只在标准库查找该文件。

## 7.接口与实现的分离

原有的类中包含了类的实现和成员的定义,为确保代码的安全性和 封装,将类成员的具体实现放在另一个文件作为保护隐藏。仅将成员和功能的定义写在头文件中。(将类的函数定义[函数体]封装在另一个文件,在头文件中仅保留接口函数原型[函数头])。

```cpp
//class.h
#include<iostream>
#include<string>
class Gradebook
{
public:
    explicit Gradebook(std::string name);
    std::string put();
private:
    std::string courseName;
};
```

```cpp
//class.cpp
//该文件对外隐藏
#include<iostream>
#include<string>
#include"class.h"
Gradebook::Gradebook(std::string name)
    :courseName(name)
    {}
std::string Gradebook::put()//c文件中具体实现,类型也要写
{
    return courseName;
}
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include"class.h"
using namespace std;
int main()
{
    Gradebook book1("hello!");
    Gradebook book2("welcome to C++");
    cout<<book1.put()<<endl;
    cout<<book2.put()<<endl;
}
```

在类的头文件中只有函数返回值类型、函数名、参数个数以及类型等基础信息,并没有该函数的具体实现,仅保留了接口。

在类的cpp文件中,首先要包含头文件,然后再具体实现的功能函数前**,标明是 `Gradebook` 的成员**。cpp文件可编译为静态库进行保护,无法查看代码的具体实现。

 `::` 为作用于分辨运算符(一元作用域运算符),C++中优先级最高的运算符,他的其中一个作用就是访问命名空间成员,具体说明为： `A::B` , `::` 前为命名空间 `A` , `::` 后为命名空间中的成员名 `B` ,说明B是A中的成员。

## 实例研究：具有数据成员、get、set函数的一个Gradebook类(及其头文件以及接口分离)

### · Gradebook类

```cpp
#include<iostream>//标准输入输出流头文件
#include<string>//引入字符串类型头文件
using namespace std;//简化标准库访问
class Gradebook
{
public:
	explicit Gradebook(string name)//构造函数,初始化数据成员courseName
		:courseName(name)
	{ }
	void set(string name)//set函数,对courseName进行写入
	{
		courseName = name;
	}
	string get() const//get函数,获取courseName中的内容
	{
		return courseName;
	}
	void prt() const//prt函数,对courseName的内容进行打印
	{
		cout << "调用prt函数打印数据成员的值为：" << get() << endl;
	}
private:
	string courseName;//私有数据成员
};
int main()
{
	Gradebook book1("你好！");//构造函数初始化数据成员
	cout << book1.get() << endl;//打印构造函数直接初始化数据成员的值
	book1.set("我不好");//set函数对数据成员进行修改
	book1.prt();//prt函数打印修改后的值
}
```

## 8.类的静态成员

### 8.1 static修饰类的数据成员

**静态数据成员**

语法：`static int a;//类中声明` `int a = 0;//类外初始化`

表示该成员是类共享的，不属于任何一个对象，但**静态数据成员任何一个对象都可以访问**，也能通过类名访问

```cpp
#include <iostream>
class Cls
{
public:
    Cls();
    void Set_a(int _a);
    void Prt()const;
private:
    static int a;
};
int Cls::a = 0;
Cls::Cls()
 //error   :a(1) 静态成员不可以在构造函数的初始化列表初始化，只能在类外全局初始化
{
    std::cout << "对象已构造" << std::endl;
}
void Cls::Set_a(int _a)
{
    a = _a;
}
void Cls::Prt()const
{
    std::cout << "a=" << a << std::endl;
}
int main()
{
    Cls c1;
    Cls c2;
    c1.Prt();
    c1.Set_a(2);
    c2.Prt();
    return 0;
}
/********************
对象已构造
对象已构造
a=0
a=2
*/
```

### 8.2 static修饰类的成员函数

**静态成员函数**

声明时加static，函数实现不用加

表示该成员是类共享的，不属于任何一个对象，任何一个对象都可以调用，也能通过类名调用

但是静态成员函数**只能访问类的静态数据成员**，不可以访问类的其他成员

**因为没有隐含的this指针，所以不能访问类的其他成员**

```cpp
#include <iostream>
class Cls
{
public:
    Cls();
    void Set_a(int _a);
    void Prt()const;
    static void Count_Obj();
private:
    static int a;
};
int Cls::a = 0;
Cls::Cls()
//error   :a(1) 静态成员不可以在构造函数的初始化列表初始化，只能在类外全局初始化
{
    std::cout << "对象已构造" << std::endl;
    a++;
}
void Cls::Count_Obj()
{
    std::cout << "对象数" << Cls::a << std::endl;
}
void Cls::Set_a(int _a)
{
    a = _a;
}
void Cls::Prt()const
{
    std::cout << "a=" << a << std::endl;
}
int main()
{
    Cls c1;
    Cls::Count_Obj();
    c1.Count_Obj();//任何对都可以访问
    Cls c2;
    Cls::Count_Obj();
    return 0;
}
/******************
对象已构造
对象数1
对象已构造
对象数2
*/
```

## 9.const修饰类的成员函数

语法：`返回值类型 函数名(参数列表)const{}`

const在成员函数后面表示该成员函数是一个常量成员函数，函数体内不修改数据成员的值（只读，不写）。

隐含的this指针指向的数据类型也为const（this指针本来就是一个const类型的常亮指针，因为他表示的是调用他的对象），表示调用它的对象的值不可被修改，是常量值。

其他const成员函数也是如此，这就导致const成员函数只能调用const成员函数，但可以被任何函数调用，因为const成员函数的权限是只读，所有关于写的操作都错误。

`mutable`关键字修饰数据成员后，允许`const`成员函数修改数据成员。const对象只能调用const成员函数。

### · 头文件及其接口分离

```cpp
//book.h
#progma once
#ifndef _BOOK_H_
#define _BOOK_H_
#include<iostream>
#include<string>
class Gradebook
{
public:
	explicit Gradebook(std::string name);//构造函数的接口
	void set(std::string name);//set函数的接口
	std::string get() const;//get函数的接口
	void prt() const;//prt函数的接口
private:
	std::string courseName;//私有数据成员
};
#endif
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include"book.h"
Gradebook::Gradebook(std::string name)
    :courseName(name)
    {}
void Gradebook::set(std::string name)
{
    courseName=name;
}
std::string Gradebook::get() const
{
    return courseName;
}
void Gradebook::prt() const
{
    std::cout<<"调用prt函数打印数据成员的值为：" << get() << std::endl;
}
std::string Gradebook::courseName;
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include"book.h"
using namespace std;
int main()
{
    Gradebook book1("你好！");//构造函数初始化数据成员
	cout << book1.get() << endl;//打印构造函数直接初始化数据成员的值
	book1.set("我不好");//set函数对数据成员进行修改
	book1.prt();//prt函数打印修改后的值
}
```

## 10.拷贝构造函数

**应用场景：**用一个已经存在的对象初始化另一个对象

已有类Cls

> Cls c1;
>
> Cls c2(c1);//或者Clsc3 = c1;

函数原型，就是**构造函数仅传入一个参数为本类对象的引用**

`类名(const 类名&){}`

没有显式声明**拷贝构造函数**的话，编译器会自动生成一个**默认拷贝构造函数**。构造函数也是同理，没有显式声明**构造函数**的话，编译器会自动生成一个**默认构造函数**。（不带任何参数）

**默认拷贝构造函数：**默认拷贝构造函数会将所以数据成员进行拷贝（浅拷贝，后续详细介绍）

**默认拷贝构造函数**

```cpp
#include <iostream>

class A
{
public:
    A();//构造函数
    void set(int _a);//设置a值
    void Prt() const;//打印值
private:
    int a;
};

A::A()
    :a(1)
{
    std::cout << "已构造A()" << std::endl;
}
void A::Prt() const
{
    std::cout << "a=" << a << std::endl;
}
void A::set(int _a)
{
    a = _a;
}
int main()
{
    A a1;//调用构造函数
    a1.Prt();//打印1
    a1.set(2);//将值设置为2
    A a2(a1);//调用拷贝构造函数
    a2.Prt();//打印值为2
}

/****************
已构造A()
a=1
a=2
*/

```

**手动拷贝构造函数**

```cpp
#include <iostream>

class A
{
public:
    A();//构造函数
    A(const A&);//拷贝构造函数
    void set(int _a);//设置a值
    void Prt() const;//打印值
private:
    int a;
};

A::A()
    :a(1)
{
    std::cout << "已构造A()" << std::endl;
}
A::A(const A& a_a)
{
    std::cout << "已拷贝A(const A& a)" << std::endl;
    this->a = a_a.a;
}
void A::Prt() const
{
    std::cout << "a=" << a << std::endl;
}
void A::set(int _a)
{
    a = _a;
}
int main()
{
    A a1;//调用构造函数
    a1.Prt();//打印1
    a1.set(2);//将值设置为2
    A a2(a1);//调用拷贝构造函数
    a2.Prt();//打印值为2
}

/****************
已构造A()
a=1
已拷贝A(const A& a)
a=2
*/

```

### 10.1 浅拷贝

拷贝构造（浅拷贝）图示

![image-20251104214847524](C:\Users\XiaoHong\AppData\Roaming\Typora\typora-user-images\image-20251104214847524.png)

如果成员中有指针，代码：

```cpp
#include <iostream>

class A
{
public:
    A();//构造函数
    void set_a(int _a);//设置a值
    void Prt_a() const;//打印值
    void Prt_p() const;//打印p值（a的地址）
private:
    int a;
    int* a_ptr;//定义一个指针，指向a
};

A::A()
    :a(1),a_ptr(&a)
{
    std::cout << "已构造A()" << std::endl;
}
void A::Prt_a() const
{
    std::cout << "a=" << a << std::endl;
}
void A::set_a(int _a)
{
    a = _a;
}
void A::Prt_p() const
{
    std::cout << "a_ptr=" << a_ptr << std::endl;
}
int main()
{
    A a1;//调用构造函数
    std::cout <<"对象a1地址" << &a1 << std::endl;
    a1.Prt_a();//打印a值
    a1.Prt_p();//打印地址
    A a2(a1);//拷贝构造a2
    std::cout << "对象a2地址" << &a2 << std::endl;
    a1.Prt_a();//打印a值
    a1.Prt_p();//打印地址

}
/****************
已构造A()
a=1
已拷贝A(const A& a)
a=2
*/


/***************
已构造A()
对象a1地址00000018272FFA88
a=1
a_ptr=00000018272FFA88
a地址:&a=00000018272FFA88
指针地址:&p=00000018272FFA90

拷贝构造

对象a2地址00000018272FFAB8
a=1
a_ptr=00000018272FFA88
a地址:&a=00000018272FFAB8
指针地址:&p=00000018272FFAC0
*/
```

对象实现了拷贝，对象中的内容也实现了拷贝，并且**重新分配**了独立的内存空间（包括对象，各数据成员：指针,变量），但是，原成员函数中的**指针指向（指针的值）没有被新分配**，依旧**指向原来的地址**。这个就叫**浅拷贝**

![image-20251105094159450](C:\Users\XiaoHong\AppData\Roaming\Typora\typora-user-images\image-20251105094159450.png)

### 10.2 深拷贝

深拷贝就是将指针的指向也进行拷贝，将拷贝过后的指针指向自己内存地址的变量：

![image-20251105094607961](C:\Users\XiaoHong\AppData\Roaming\Typora\typora-user-images\image-20251105094607961.png)

实现**深拷贝**就需要手动写构造函数，将旧对象所有成员重新分配地址空间并拷贝

```cpp
#include <iostream>

class A
{
public:
    A();//构造函数
    A(const A&);//拷贝构造函数
    void set_a(int _a);//设置a值
    void Prt_a() const;//打印值
    void Prt_p() const;//打印p值（a的地址）
    void Prt_a_add() const;
    void Prt_p_add() const;
private:
    int a;
    int* a_ptr;//定义一个指针，指向a
};

A::A()
    :a(1), a_ptr(&a)
{
    std::cout << "已构造A()" << std::endl;
}

A::A(const A& old_obj)//拷贝构造函数
{
    //拷贝构造函数实现什么功能？\
        1.将旧对象中所有数据成员的值进行拷贝\
        2.将旧对象中，指向旧数据成员的指针指向新对象（自身）的数据成员

    std::cout << "\n已拷贝A(const A& old_obj)" << std::endl;
    this->a = old_obj.a;
    this->a_ptr = &(this->a);

}

void A::Prt_a_add() const
{
    std::cout << "&a=" << &a << std::endl;
}

void A::Prt_a() const
{
    std::cout << "a=" << a << std::endl;
}

void A::set_a(int _a)
{
    a = _a;
}

void A::Prt_p_add() const
{
    std::cout << "&p=" << &a_ptr << std::endl;
}

void A::Prt_p() const
{
    std::cout << "a_ptr=" << a_ptr << std::endl;
}

int main()
{
    A a1;//调用构造函数
    std::cout << "对象a1地址" << &a1 << std::endl;
    a1.Prt_a();//打印a值
    a1.Prt_p();//打印地址
    std::cout << "a地址:" ;
    a1.Prt_a_add();
    std::cout << "指针地址:";
    a1.Prt_p_add();

    A a2(a1);//拷贝构造a2
    std::cout << "\n拷贝构造\n\n对象a2地址" << &a2 << std::endl;
    a2.Prt_a();//打印a值
    a2.Prt_p();//打印地址
    std::cout << "a地址:";
    a2.Prt_a_add();
    std::cout << "指针地址:";
    a2.Prt_p_add();

}
/****************
已构造A()
对象a1地址0000008DB70FF8B8
a=1
a_ptr=0000008DB70FF8B8
a地址:&a=0000008DB70FF8B8
指针地址:&p=0000008DB70FF8C0

已拷贝A(const A& old_obj)

拷贝构造

对象a2地址0000008DB70FF8E8
a=1
a_ptr=0000008DB70FF8E8
a地址:&a=0000008DB70FF8E8
指针地址:&p=0000008DB70FF8F0
*/
```

上述例程实现了**深拷贝**



## 拓展

### size()(length())

`size()`为 `string`类中的一个成员函数,用于求`string`创建的对象字符串长度(字符个数),返回值为字符串长度(int),eg:

```cpp
/*...*/
std::string name;//创建一个string类的name对象
int a=0;
name = "hahaha";
a=name.size();//访问name对象中的size函数,求name字符串长度
std::cout<<a<<std::endl;//6
/***********length()和size()完全相同*************/
```

### substr()

`substr(n,m);`

`substr()`为 `string`类中的一个成员函数,用于把`string`创建的对象字符串长度从第n位取到第m位,返回值为新字符串,eg:

```cpp
/*...*/
std::string name;//创建一个string类的name对象
int a = 0;
name = "hahaha";
name = name.substr(1, 4);//012345,hahaha
std::cout << name << std::endl;//aha
```

### setw

`cout<<setw(所占域宽)`,流操作符(需要包含头文件<iomanip>),表示下一个用cout输出的值最小占用宽度为指定字符,若输出字符长度小于指定域宽,右对齐,若输出字符长度大于指定域宽,按实际数值长度输出。setw也属于命名空间std

```cpp
cout<<setw(3)<<"a"<<endl;//"  a"
cout<<setw(3)<<"abcd"<<endl;//"abcd"
```

# 三、控制语句、赋值、自增减运算符

## 0.引言

通过控制语句对 `Gradebook` 类进一步拓展功能,进行计算。任何计算问题的算法都完成两个事情：动作、顺序。

## 1.控制结构

### 1.1 顺序结构

按照语句书写顺序来执行

### 1.2 选择结构

#### 1.2.1 if选择语句

```cpp
if(条件)
{
    语句
    ……
}
```

条件为真,执行语句,条件为假跳过语句

#### 1.2.2 if……else双路选择语句

```cpp
if(条件)
{
    语句
    ……
}
else
{
    语句
}
```

条件为真,执行`if`中的语句,条件为假执行`else`中的语句。一个`else`对应一个`if`,二者相匹配,`else`总会与其最近的并且未匹配的`if`匹配

**·** 条件运算符`?:` 条件为真执行语句1,条件为假,执行语句2,条件运算符仅可用于单条语句

> `(条件)?(语句1):(语句2)`

#### 1.2.3 if……else if……多分支选择语句

```cpp
if(条件)
{
    语句
}
else if(条件)
{
    语句
}
else if(条件)
{
    语句
}
……
```

谁的条件为真,执行谁的语句,条件为假跳过语句

#### 1.2.4 switch

后续内容详细解释

### 1.3 循环结构

#### 1.3.1 while

```cpp
while(条件)
{
    语句
    ……
}
```

先判断条件,为真执行语句,执行完后在判断条件,为真继续执行语句,直至为假。所以语句中必须包含限制条件的语句,否则将无限循环

#### 1.3.2 do……while

```cpp
do
{
    语句
    ……
}while(条件);
```

先执行语句,执行完后在判断条件,为真继续执行语句,直至为假。所以语句中必须包含限制条件的语句,否则将无限循环。与`while`的区别：`do……while`至少执行一次(一定会执行一次)

#### 1.3.3 for

后续内容详细解释

## 2.实例研究：算法详述

### 2.1 计数器控制的循环

【统计班级平均成绩,使用循环语句实现,利用一个变量作为计数器,并且作为while的控制条件,来进行成绩统计】

```cpp
//book.h
#progma once
#ifndef _BOOK_H_
#define _BOOK_H_
#include<iostream>
#include<string>
class Gradebook
{
public:
	explicit Gradebook(std::string name);//构造函数的接口
	void set(std::string name);//set函数的接口
	std::string get() const;//get函数的接口
	void prt() const;//prt函数的接口
	int classAverage();//classAverage函数的接口
private:
	std::string courseName;//私有数据成员
};
#endif
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include"book.h"
Gradebook::Gradebook(std::string name)
    :courseName(name)
{
}
void Gradebook::set(std::string name)
{
    courseName = name;
}
std::string Gradebook::get() const
{
    return courseName;
}
void Gradebook::prt() const
{
    std::cout << "欢迎查看成绩册\n" <<get()<< std::endl;
}
int Gradebook::classAverage()
{
    unsigned int sum = 0;
    unsigned int count = 1;
    while (count <= 10)//执行十次,获取十个成绩
    {
        unsigned int temp = 0;
        std::cout << "请输入成绩：" ;
        std::cin >> temp ;
        sum += temp;//成绩总和
        count=count+1;//计数器
    }
    return (sum / 10);
}
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include"book.h"
using namespace std;
int main()
{
    Gradebook book("你好");
	book.prt();
	cout << "平均成绩为:" << book.classAverage() << endl;
}
```

### 2.2 标记控制的循环

【统计班级平均成绩,使用循环语句实现,利用一个标记作为、作为while的控制条件,来进行成绩统计,可统计任意个数的成绩】

```cpp
//book.h
#progma once
#ifndef _BOOK_H_
#define _BOOK_H_
#include<iostream>
#include<string>
class Gradebook
{
public:
	explicit Gradebook(std::string name);//构造函数的接口
	void set(std::string name);//set函数的接口
	std::string get() const;//get函数的接口
	void prt() const;//prt函数的接口
	double classAverage();//classAverage函数的接口
private:
	std::string courseName;//私有数据成员
};
#endif
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include"book.h"
Gradebook::Gradebook(std::string name)
    :courseName(name)
{
}
void Gradebook::set(std::string name)
{
    courseName = name;
}
std::string Gradebook::get() const
{
    return courseName;
}
void Gradebook::prt() const
{
    std::cout << get() <<  std::endl;
}
double Gradebook::classAverage()
{
    int sum = 0,count = 0, temp = 0;//总分,人数,单个成绩
    std::cout << "请输入成绩(-1输入结束)：";
    std::cin >> temp;//输入第一个成绩
    while (temp != -1)//判断输入是成绩还是退出
    {
        sum += temp;//加
        std::cout << "请输入成绩(-1输入结束)：";
        std::cin >> temp;//再次输入
        count++;//计数
    }
    return ((static_cast<double>(sum)) / count);
}
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
using namespace std;
int main()
{
	Gradebook book("您好！\n欢迎查看成绩册");
	book.prt();
	double age = book.classAverage();
	Gradebook book1("平均成绩为：");
	book1.prt();
	cout << setprecision(2) <<fixed;
	cout << age << endl;
}
```

#### 2.2.1 强制类型转换符

> 如果最后计算总分除法,得到平均分的结果是一个小数,那么返回的值依然是一个整型,将丢失精度。C++中提供了强制类型转换符`static_cast`来进行临时的强制类型转换。格式：
>
> `siatic_cast<强制转换类型>(强制转换的变量)`
>
> 例程中``static_cast<double>(sum)` ,把sum的int类型在此时强制转换为double。像这样使用强制类型转换符的转换称为**显式转换**。
>
> 但在返回值中,为保证表达式所有的操作数类型是相同的,C++会进行一种操作叫**升级**。在`static_cast<double>(sum) / count`中`count`是一个`int`整型,C++会将`count`升级为精度更高的,与`sum`相等的`double`类型后再进行计算,通过升级进行的类型转换称为**隐式转换**。

#### 2.2.2 浮点数流操作符

##### setprecision

> 格式：`cout<<setprecision(输出位数n);`
>
> 所有使用`cout`输出的浮点数,将只输出指定的n位数(从左往右数,小数点不算),整数不受影响
>
> 指定的位数若在小数部分,将在该位四舍五入；指定的位数若在整数部分,将在该位转换成科学计数
>
> ```cpp
> cout<<setprecision(4);
> cout<<23.4587<<endl;//23.46
> cout<<234587.3<<endl;//2.346e+05
> cout<<2345873<<endl;//2345873
> ```

##### fixed

> 格式：`cout<<fixed;`
>
> 所有使用`cout`输出的浮点数,定点为小数点后六位,整数不受影响
>
> 小数不足六位补零,超出六位四舍五入
>
> ```cpp
> cout<<fixed;
> cout << 1.2345 << endl;//1.234500
> cout << 1.23456789 << endl;//1.234568
> cout << 123456789 << endl;//123456789
> ```

##### showpoint

> 格式：`cout<<showpoint;`
>
> 所有使用`cout`输出的浮点数,输出6位数(从左往右数,小数点不算位数),包括小数点也输出,如果小数点后为0,不省略0,整数不受影响,
>
> 若第六位在小数部分,小数不足六位补零,小数超出六位四舍五入
>
> 若第六位在整数部分,在该位转换成科学计数
>
> ```cpp
> cout<<showpoint;
> cout << 1.0 << endl;//1.00000
> cout << 123456.0 << endl;//123456.
> cout <<123456789.0<<endl;//1.23457e+08
> cout << 12.34 << endl;//12.3400
> cout << 1.23456789 << endl;//1.23457
> cout << 1243334 << endl;//1243334
> ```

##### setprecision+fixed(三者都可配合使用,将遵循每个的特性)

>格式：`cout<<fixed<<setprecision(输出位数n);`或`cout<<setprecision(输出位数n)<<fixed;`
>
>所有使用`cout`输出的浮点数,保留n位小数,整数不受影响
>
>不足补零,超出四舍五入
>
>```cpp
>cout << fixed << setprecision(2);
>cout << 1.2345 << endl;//1.23
>cout << 1234.56789 << endl;//1234.57
>cout << 123456789 << endl;//123456789
>```

**setprecision带有参数,在使用setprecision前需要包含头文件`#include<iomanip>`,fixed和showpoint在标准输入输出流头文件`#include<iostream>`中**

## 3.赋值运算符、自增自减运算符

与C中相同

## 4.for循环语句

与C中相同

`for(初始值;判断条件;控制条件)`,先判断,为真执行循环体,循环体执行完执行控制条件,再判断……

## 5.实例研究：switch多路选择语句

【将统计的成绩划分为ABCD四个等级,输入等级,统计各等级的人数】

```cpp
//book.h
#progma once
#ifndef _BOOK_H_
#define _BOOK_H_
#include<iostream>
#include<string>
class Gradebook
{
public:
	explicit Gradebook(std::string name);//构造函数的接口
    void set(std::string name);//set函数的接口
    std::string get() const;//get函数的接口
    void prt() const;//prt函数的接口
    double classAverage();//classAverage函数的接口
    void inputGrades();//inputGrade函数的接口
    void displayGrades();
private:
	std::string courseName;//私有数据成员名称
    int Acount;//统计各个等级人数
    int Bcount;
    int Ccount;
    int Dcount;
};
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include"book.h"
Gradebook::Gradebook(std::string name)
    :courseName(name),
    Acount(0), Bcount(0), Ccount(0), Dcount(0)
    //通过构造函数将私有数据成员,四个等级的人数初始化为0
{
}
void Gradebook::set(std::string name)
{
    courseName = name;
}
std::string Gradebook::get() const
{
    return courseName;
}
void Gradebook::prt() const
{
    std::cout << get() <<  std::endl;
}
void Gradebook::inputGrades()
{
    char grade=0;
    std::cout << "请输入成绩等级(A、B、C、D):\n";
    while ((grade = std::cin.get())!=EOF)
    {
        switch (grade)
        {
        case 'A':
            Acount++; 
            break;
        case 'B':
            Bcount++; 
            break;
        case 'C':
            Ccount++; 
            break;
        case 'D':
            Dcount++; 
            break;
        case '\n':
        case '\t':
        case ' ':
            break;
        default:
            std::cout << "输入有误,请重新输入\n";
            break;
        }
    }
}
void Gradebook::displayGrades()
{
    std::cout << "等级A共有" << Acount << "人" << std::endl;
    std::cout << "等级B共有" << Bcount << "人" << std::endl;
    std::cout << "等级C共有" << Ccount << "人" << std::endl;
    std::cout << "等级D共有" << Dcount << "人" << std::endl;
}
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
using namespace std;
int main()
{
	Gradebook book("您好、欢迎查看成绩册！");
    Gradebook book2("1");
    book.prt();
    book.inputGrades();
    cout << "book中"<<endl;
    book.displayGrades();
    cout << "book2中" << endl;
    book2.displayGrades();
}
```

```cpp
/**********************终端****************************/
您好、欢迎查看成绩册！
请输入成绩等级(A、B、C、D):
A
C
C
B
^Z
book中
等级A共有1人
等级B共有1人
等级C共有2人
等级D共有0人
book2中
等级A共有0人
等级B共有0人
等级C共有0人
等级D共有0人
```

该例程中新增了两个成员函数,`inputGrades()`和`displayGrades()`；四个数据成员`(A、B、C、D)count`

`inputGrades()`用来输入成绩等级,`displayGrades()`用来打印各等级人数；`(A、B、C、D)count`用来统计各等级人数

### 例程分析：inputGrades()

首先定义了一个字符变量来存放等级的值,while循环的条件为,从键盘标准输入获取一个字符,为文件结束符(EOF)时停止循环。主函数中实例化了两个对象book和book2,并同时打印结果

#### std::cin.get

函数`std::cin.get()`从键盘上输入数据,用于一个一个字符的获取,并按(队列)顺序返回每个字符的值(包括空格换行等特殊字符也会读取并返回)

本例程中获取到的值为：A|\n|C|\n|C|\n|B|\n|EOF|

#### switch

`switch`中将对应等级的字符计数,换行跳出,继续循环读取字符,输入其他打印错误报告

#### EOF

EOF(End Of File)文件结束符,值为-1,一般用于while循环的终止条件,输入方式为Ctrl+Z(Windows)或Ctrl+D(Linux、Unix)

#### 对象

不同的对象,进行操作时,数据成员和成员函数是独立的,不相互影响

#### break(continue)

与C中用法相同

## 6.逻辑运算符

与C同理

## 拓展：平台数据类型最大最小值

`#include<climits>`中的符号常量`(数据类型)_MAX`、`(数据类型)_MIN`可以来确认自己平台数据类型的最大值和最小值,例如：

```cpp
cout << UINT_MAX<<endl;//4294967295
cout << INT_MIN << endl;//-2147483648
cout << INT_MAX << endl;//2147483647
cout << LLONG_MIN << endl;//9223372036854775807
cout << LLONG_MAX << endl;//-9223372036854775808
```

# 四、函数和递归

## 0.引言

C++程序通常由程序员编写的新函数和类,以及在C++标准库中预先打包好的函数和类组合而成,程序员可以把任务分解成多个独立的单元来实现程序的模块化。函数是通过调用来执行的,调用者将控制权给函数来执行任务,函数执行完任务之后,要么返回一个值,要么不返回值,把控制权还给调用者。

## 1.库文件

### 1.1 数学库函数

`main`函数不属于任何类的成员,这种函数成为全局函数,数学库中的函数也是全局函数,使用数学库函数前需要包含头文件`<cmath>`

1.ceil(x)：x为小数,超过x的最小整数。ceil(9.8)为10

2.floor(x)：x为小数,不超过x的最大整数.floor(9.8)为9

3.fabs(x)：x的绝对值

4.sqart(x)：x的平方根

5.pow(x,y)：x的y次方

6.fmod(x,y)：x/y的浮点数余数。fmod(2.6,1.2)为0.2

7.sin、cos、tan(x)：x(弧度)的三角函数值

8.log、log10(x)：log以e为底x的对数;log以10为底x的对数

9.exp(x)：指数函数e的x次方

### 1.2 标准库头文件

1.<iostream>：包含C++标准输入输出的函数原型

2.<iomanip>：包含C++中格式化数据流的流操作符的函数原型

3.<cmath>：包含数学库中函数的函数原型

4.<cstdlib>：包含各种文本、数字、内存等各种工具函数的函数原型,在C中为<stdlib.h>

5.<ctime>：包含处理时间日期等函数的函数原型

6.<cstring>：包含C风格字符串处理函数的函数原型

7.<string>：包含C++标准库的string类的定义

8.<cstdio>：C风格标准输入输出头文件

## 2.多形参的函数定义

### 2.1 实例研究：比较大小

在`Gradebook`类中继续添加一个多形参的成员函数`max3score`用来计算成绩的最大值。通过`iput3score`函数输入三个成绩,然后返回三者之间的最大值。再添加一个数据成员`max3`用来存放最大成绩。最后通过`displayGrades`查看最成绩

```cpp
//book.h
#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_
#include<iostream>
#include<string>
class Gradebook
{
public:
	explicit Gradebook(std::string name);//构造函数的接口
	std::string get() const;//get函数的接口
	void prt() const;//prt函数的接口
	void input3score();
	int max3score(int,int,int) const;
	void display3score() const;
private:
	std::string courseName;//私有数据成员名称
	int max3=0;//3个成绩的最大值
};
#endif
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include"book.h"
Gradebook::Gradebook(std::string name)
{}
std::string Gradebook::get() const
{
    return courseName;
}
void Gradebook::prt() const
{
    std::cout << get() <<  std::endl;
}
void Gradebook::input3score()//输入3个成绩函数
{
    int a=0, b=0, c=0;
    std::cout << "请输入三个成绩,空格隔开：";
    std::cin >> a >> b >> c;
    max3=Gradebook::max3score(a, b, c);
}
int Gradebook::max3score(int x,int y,int z)const//判断三个成绩的最大值
{
    int max3_1=0;
    (x >= y) ? (max3_1 = x) : (max3_1 = y);
    (z >= max3_1) ? (max3_1 = z) : max3_1 = max3_1;
    return max3_1;
}
void Gradebook::display3score() const
{
    std::cout << "最高成绩为：" << max3<<std::endl;
}
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
using namespace std;
int main()
{
	Gradebook book("您好！欢迎查看成绩册！");
	book.prt();
	book.input3score();
	book.display3score();
}
```

```cpp
/**********************终端****************************/
您好！欢迎查看成绩册！
请输入三个成绩,空格隔开：34 95 58
最高成绩为：95
```

Gradebook类中新增了一个多形参函数`max3score`,在类的头文件接口中类似于C中的函数声明一样,不需要写变量,只需说明类型即可。在cpp文件中的函数具体实现需要写明类型和具体变量。cpp文件的成员函数互相调用是可以不指定明明空间。如book.cpp的第20行可写成`max3=max3score(a, b, c);`,其余规则与C相同。

### 2.2 函数原型(声明)、定义

#### 2.2.1 函数原型(声明)

构成：`[返回值类型] [函数名](形参类型 形参,形参类型 形参……)`,函数声明括号内不包括形参,只有形参类型

原型：`void max3score(int a,int b,int c);`

声明：`void max3score(int,int,int);`

函数原型的一个重要特性是“实参类型强制转换”,意思是无论传给函数的实参是什么类型,在调用函数时都会被转换成函数原型所指定的形参类型,eg：

```cpp
/*函数原型*/
void max3score(int a,int b,int c);
/*调用函数*/
max3score(32.65,85.76,43.8);
/*当这三个数传入函数中时的值为,32,85,43,double类型被强制转换为int*/
/*影响：导致精度丢失*/
```

#### 2.2.2 函数定义

构成： `[返回值类型] [函数名](形参类型 形参……){函数体 具体实现}`

## 3.随机数

### 3.1 C++的随机数

与C相同,通过`stdlib`库中的`rand`函数来生成一个伪随机数,与`time`库中的`time`函数获取每次都不同的时间戳和`stdlib`库中的`srand`来初始化种子,生成一个从0~RAND_MAX的随机数。**通过取模运算可以指定随机数生成的范围**。

```cpp
#include<cstdlib>
#include<ctime>
srand(time(NULL));
```

但C++中建议将第3行代码写为`srand(static_cast<unsigned int>(time(NULL)))`,因为srand要传入的是一个无符号整型数。

`srand`函数声明为`_ACRTIMP void __cdecl srand(_In_ unsigned int _Seed);`

### 3.2 实例研究：随机数

#### 3.2.1 骰子

【掷一个六面体骰子20次,重复两次代码查看结果】

```cpp
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    for(int i=1;i<=20;i++)
    {
        cout<<setw(4)<<rand()%6+1;
            if(!(i%4))
        cout<<endl;
    }
}
```

```cpp
/**********************终端****************************/
   6   1   6   4
   2   1   2   1
   5   6   2   1
   1   2   6   3
   6   1   1   1
```

```cpp
/**********************终端****************************/
   6   6   6   5
   1   5   5   1
   5   3   6   2
   2   5   3   6
   6   3   3   5

```

`srand`进行种子初始化,用来生成随机数

`for`循环执行二十次,生成20次随机数

`setw(4)`域宽4,右对齐,包含头文件<iomanip>

`if`每输出四个数换行

【掷一个六面体骰子600000次,统计每个面出现的次数】

```cpp
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    unsigned int a = 0, b = 0, c = 0, 
	d = 0, e = 0, f = 0;
    for (int i = 0; i < 600000; i++)
    {
        switch (rand()%6+1)
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
	 << setw(4) << "总数"<<setw(10) << a + b + c + d + e + f << endl;
}
```

```cpp
/**********************终端****************************/
   1    100293
   2     99926
   3    100110
   4     99870
   5     99837
   6     99964
总数     600000
```

结果都接近100000次

#### 3.2.2 博彩

【掷两个六面骰,和为7获胜,和为2、3、12输,和为其他,进入目标点数状态。目标点数状态时要一直掷骰子,直到再次为目标点数,则获胜,目标点数期间掷出和为7,输】

```cpp
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
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
		cout << "游戏开始," << "点击回车掷出骰子" << endl;
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
		cout << "\n是否继续游戏？(请输入数字)\n"
			<< "0.否  1.是" << endl;
		std::cin >> startgame;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "游戏结束！\n" << endl;
}
```

当想继续进行游戏时,缓冲区可能还有不需要的值,导致程序重复执行出现错误,或者在其他情况缓冲区有不需要的值,需要清理干净。

`std::cin.ignore()`函数,有两个形参,第一个表示清楚的字符上限,第二个表示到哪个字符停止(并将该位也清除),从左往右

若不传参直接调用该函数,表示清除最后一个输入到缓冲区的字符。

`std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');`表示清空缓冲区,包括换行符。

#### 3.2.3 枚举简介

与C中相同。

上述例程中使用了枚举类型`enum play { WIN, LOST, CON };`,`enum关键字+枚举类型名+{枚举常量列表};`列表中的枚举值被视为常量(右值),第一个值为0,依次增1,可对第一个值进行赋值来改变值。eg：

`enum play{a,b,c,d};` a为0,b为1,c为2,d为3

`enum play{a=2,b,c,d};` a为2,b为3,c为4,d为5

### 3.3 C++11的枚举和随机数

#### 3.3.1 作用域限定的枚举

通过关键字`enum class`来限定作用域访问枚举值,eg：

`enum class play{a,b,c,d};`

> 访问枚举值时,必须加上命名空间play,通过枚举类型名`play`加作用域分辨运算符`::`来进行访问,play::a,play::b,play::c,play::d

#### 3.3.2 随机数

C++11中提供了更加安全可靠的的随机数功能库,在头文件<random>中。

随机数生成引擎`default_random_engine`(种子),创建对象,构造函数实参用当前时间戳作为种子

指定范围`uniform_int_distribution`,创建对象,实参为生成数的范围

```cpp
/*创建一个对象engine实参为时间*/
default_random_engine engine(static_cast<unsigned int>(time(NULL)));
/*创建一个对象randomint生成1~6的unsigned int类型的值*/
uniform_int_distribution<unsigned int> randomint(1,6);
/*表达式randomint(engine)返回一个1~6整形的值*/
randomint(engine);
```

<unsigned int>表明uniform_int_distribution是一个类模板,类模板后续章节详细介绍

## 4.存储类别、存储期、作用域

### 4.1 存储类别和存储期

C++提供了5个存储类别说明符：auto、register、extern、mutable、static,存储类别决定了变量的存储期。自动存储期、静态存储期、动态存储期、线程存储期。

#### 4.1.1 自动存储期

声明在函数中的局部变量,函数的形参,用register声明的局部变量或函数形参

这种变量仅在定义他们的语句块活动时存在(花括号内`{}`),函数的形参则存在于整个函数体中。当出了他们的活动范围后被自动销毁。具有自动存储期的变量成为自动变量。

`register` (**C++中的一个关键字**)只可以放在局部变量或者函数形参的定义前面,表示将值直接存在计算机的告诉硬件寄存器中,若频繁访问该变量,可以直接从寄存器中读取值,而不是频繁的访问内存,提高效率。

#### 4.1.2 静态存储期

static和extern为函数和具有静态存储期变量的声明标识符。具有静态存储期的变量从程序执行到程序结束一直存放在内存中,并且静态变量初始化语句只执行一次后销毁。与C中相同。

### 4.2 作用域

标识符的作用域指的是标识符在程序中可以被访问的范围。与C中相同。

### 4.3 一元作用域分辨运算符

局部变量可以和全局变量使用相同的名字,但访问时会出现问题。C++提供了一元作用域分辨运算符`::`,全局变量在同名局部变量的作用域内,可以用来访问全局变量

```cpp
/*。。。*/
string a="全局变量";
int main()
{
    string a = "局部变量";
	cout << a <<"\t" << ::a << endl;
}
/*。。。*/
/**********************终端****************************/
局部变量        全局变量
```

## 5.函数

### 5.1 函数调用堆栈和活动记录

#### 5.1.1 堆栈

单开口,先进后出,后进先出,如图：

```cpp
|	| <——栈顶
|	|
|	|
|	|
|———| <——栈底
```

函数被调用时,需要保存此刻的位置,就是调用被调函数的函数是在什么时候什么位置把他调用的,把这个位置(数据项)记住压入堆栈,这个数据项叫做一条活动记录。每个函数被调用时,都会向堆栈压入一条活动记录,被调函数可能还会调用其他函数,此时堆栈中栈底是第一条活动记录,再压入第二条活动记录,调用结束后,先将后面调用的函数活动记录弹出,返回调用它的位置,等第一条被调函数执行完后,再把栈底的活动记录弹出,返回到第一次调用被调函数的位置。

### 5.2 无形参函数

无形参函数可以在形参列表中写`void`或者什么都不写。与C相同

### 5.3 内联函数

函数调用时会有开销,C++提供内联函数减少函数调用时的开销,在函数定义时将限定符`inline`写在函数头返回值类型之前,建议编译器在调用该函数时在调用的位置生成一个完整的函数体副本,减少调用时的开销,但副作用是会使程序规模变得很大。eg:

```cpp
/*...*/
inline int LF(const int a)
{
    rerturn a*a*a;
}

/*...*/
int main()				
{
    int a=0;
    cin>>a;
    cout<<LF(a)<<endl;
}
//约等于
int main()
{
    int a=0;
    cin>>a;//输入5
    cout<<5*5*5<<endl;
}
```

`const`表示函数不可修改a的值,a相当于一个常量(右值),若要修改a的值会报错

### 5.4 引用

按值传参时，相当于(在函数调用堆栈上)产生了一份实参的(副本)复制体，然后把副本传给被调函数，在函数体内对副本进行操作。对于副本的操作不会改变原始变量的值。

#### 5.4.1 引用形参

按引用传参，被调函数可以直接访问调用者的数据，进行读写。按引用传参，需要在被调函数原型的形参变量前加`&`（函数声明也要加），然后实际调用函数时，操作被引用的变量就相当于对实参直接操作了。

```cpp
void a(int&,int&);
int main()
{
    int x=1,y=2;
    a(x,y);
    cout<<x<<endl;
    cout<<y<<endl;
}
void a(int &a,int &b)
{
    a=a+100;
    b=b+200;
}
/**********************终端****************************/
101
202
```

#### 5.4.2 函数体内引用

在函数体内,将旧变量名 赋值 给&加新变量名(&y=x),表示x与y是共同的值,y为x的另一个名字,相互绑定了,前提是旧的变量名必须先定义。

### 5.5 默认实参

在自定义的函数中,声明时将形参赋值,那么在调用函数时,不传参的话,将函数声明时候的值作为参数传进去。

```cpp
/*...*/
int add(int,int,int);//error
int add(int a=1,int b=2,int c=3)//pass
int main()
{
    add();
}
int add(int a=1,int b=2,int c=3)//error
{/*。。。*/}
int add(int a,int b,int c)//pass
{/*。。。*/}
```

传参时传参数可为0~定义参数数,上述例子：0~3,若传参数小于定义参数数时,传参至按照形参顺序从左往右传。

```cpp
/*...*/
int add(int a=1,int b=2,int c=3)//pass
int main()
{
    add(10);//结果为 10*2*3
    add(10,20);//结果为 10*20*3
}
int add(int a,int b,int c)//pass
{/*。。。*/}
```

### 5.6 函数重载

可定义同名的函数,但参数个数或者参数类型必须不同,eg：

```cpp
#include<iostream>
using namespace std;
int add(int a,int b);
int add(int a,int b,int c);
float add(float a, float b);
float add(float a, float b, float c);
int main()
{
    cout<<"两个整数3+6="<<add(8,6)<<endl;
    cout<<"三个整数1+5+8="<<add(1,5,8)<<endl;
    cout<<"两个小数2.3+6.3="<<add(2.3,6.3)<<endl;
    cout<<"三个小数1.3+7.8+5.6="<<add(1.3,7.8,5.6)<<endl;
}
int add(int a,int b)
{
    return a+b;
}
int add(int a,int b,int c)
{
    return a+b+c;
}
float add(float a,float b)
{
    return a+b;
}
float add(float a,float b,float c)
{
    return a+b+c;
}
//运行结果
/*
两个整数3+6=14
三个整数1+5+8=14
两个小数2.3+6.3=8.6
三个小数1.3+7.8+5.6=14.7
*/
```

## 6.递归和迭代

与C相同,递归使用选择结构,迭代使用循环结构。

# 五、类模板array和vector、异常捕获

## 0.引言

本章主要介绍数据结构这一主题。数据结构是相关元素的集合。`array`类模板是由相同类型数据项组成的固定大小的数据集合，`vector`也是，但大小可以在程序执行期间动态调整。使用前要包含头文件<array>和<vector>。继续对Gradebook进行改进，使用一维和二维`array`对成绩进行保存和分析。类模板与函数模板类似，类模板的成员用自定义类型表示。

## 1.泛型编程

泛型编程是指**不具体化数据类型**的编程范式，通过将**类型参数化**，提高代码可重用性，泛型编程的核心是**模板**

### 1.1 函数模板

当多个函数的功能的差异仅仅只有数据类型，那么就可以使用函数模板。

语法：

```cpp
template<typename 自定义类型名,……>
返回值类型 函数名(参数列表)
{
    函数体
}
```

自定义类型名可以随便去名字，返回值可以使用这个自定义的类型,函数体中也是与自定义类型相关的逻辑

typename可以换成class

使用方式：

```cpp
#include<iostream>
#include"book.h"
using namespace std;
template<typename A>//定义了一个函数模板,类型为a
A add(A x,A y)//函数模板的返回值类型为a,形参为a类型的两个值
{
	return x+y;
}
int main()
{
    int x=add(5043,5043);
    double y=add(50.43,50.43);
    cout<<"x="<<x<<"\t"<<"y="<<y<<endl;
}
/**********************终端****************************/
x=10086 y=100.86
```

C++11中有关函数模板的新特性是尾随函数的返回值类型,构建复杂函数类型模板时只能采用尾随返回值类型,格式：

```cpp
template<class (自定义类型),class (自定义类型)……>
auto [函数名]([自定义类型] 变量,[自定义类型] 变量……)->[自定义返回值类型]
//实例
template<typename A>
auto add(A x,A y)->A
{
    return x+y;
}
```

## 

## 2.array

### 2.1 array对象

`array`对象是一组有相同类型并且连续的内存区域。访问时需要指定`array`对象名和下标（类似C中数组）。下标从0开始，带下标的`array`对象是一个左值。array

声明：`array<[类型],[个数(大小)]>[array对象名];`,由尖括号<>括起来的类型和大小，表明array是一个类模板。

`array<int,11> a;`表示定义了一个大小为11的`array`对象a，访问时`a[0]``a[1]``a[2]`……

**array也属于命名空间std，使用时需要加上std::**

### 2.2 实例研究：array对象

#### 2.2.1 声明array对象、(循环)初始化array对象的元素

```cpp
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,5>a;
    for(size_t i=0;i<a.size();++i)
    {
        cin>>a[i];
    }
    for(size_t i=0;i<a.size();++i)
    {
        cout<<"a["<<i<<"]="<<a[i]<<" ";
    }
}
/**********************终端****************************/
1 2 3 4 5
a[0]=1 a[1]=2 a[2]=3 a[3]=4 a[4]=5
```

`array<int,5>a;`使用`array`类模板声明了一个大小为5，`int`类型的`array`对象a

`size_t`表示无符号整数类型，多用于计数、表示内存大小、数组索引、元素数量等类型。

`size()`不仅是`string`(字符串对象)的成员函数,他还是标准库容器的成员函数。用于返回容器或字符串的元素个数。

os：标准库容器，如array、vector、list(双向链表)

#### 2.2.2 在声明中初始化array对象的元素

声明时在array对象名后加赋值运算符`=`和花括号`{}`，花括号内为初始化元素，元素之间用逗号隔开

eg`:array<int,5> a={1,2,3,4,5};`

#### 2.2.3 用常量变量指定array对象的大小,并用计算结果设置array对象的元素

【初始化为5个奇数】

```cpp
#include<iostream>
#include<array>
#include<iomanip>
using namespace atd;
int main()
{
    const size_t arrSize=5;
    array<int,arrSize>a;
    for(size_t i=0;i<a.size();i++)
    {
        a[i]=1+2*i;
    }
    cout<<setw(8)<<"数组索引"<<setw(10)<<"数组元素"<<endl;
    for(size_t i=0;i<a.size();i++)
    {
        cout<<setw(4)<<i<<setw(10)<<a[i]<<endl;
    }
}
/**********************终端****************************/
数组索引  数组元素
   0         1
   1         3
   2         5
   3         7
   4         9
```

常量变量：由于数组元素大小只能为常量，所以直接给一个变量赋值，再用这个变量作为数组大小是不可行的。所以使用const关键字把这个变量声明为一个常量(或只读变量)，此时这个变量是一个右值，是一个常量，这样就可以作为常量使用了。常量变量是一个常量但它实际上是一个变量转换为了常量，可以将这个变量作为常量使用

上述代码中若在第7行之后加一段`arrSize=7;`会报错，并不可以将数组大小修改为7，因为arrSize是一个常量，不能被赋值

#### 2.2.4 求array对象元素之和

【计算五个学生成绩总和：66，77，88，99，100】

```cpp
#include<iostream>
#include<array>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);  // 设置控制台输出为 UTF-8  
    unsigned int Gradesum=0;
    const size_t arrSize=5;
    array<int,arrSize>a={66,77,88,99,100};
    for(size_t i=0;i<a.size();i++)
        Gradesum+=a[i];
    cout<<"成绩总和为"<<Gradesum<<endl;
}
/**********************终端****************************/
成绩总和为430
```

**VS code终端中文显示乱码：使用`SetConsoleOutputCP(65001);`语句解决，需要包含头文件`<windows.h>`**

#### 2.2.5 用条形图图形化显示array对象的数据

【一批成绩，每十分一个段，各段人数以条形图分批显示：1个100，2个90多，4个80多，2个70多，3个40多，剩下为0】

```cpp
#include<iostream>
#include<array>
#include<windows.h>
#include<iomanip>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    array<int,11>a={0,0,0,0,3,0,0,2,4,2,1};
    cout<<"条形图"<<endl;
    for(size_t i=0;i<a.size();i++)
    {
        if(10==i)
        cout<<"  100: ";
        else
        cout<<10*i<<"~"<<10*i+9<<": ";
        while(a[i])
        {
            cout<<"*";
            a[i]--;
        }
        cout<<endl;
    }
}
/**********************终端****************************/
条形图
0~9
10~19
20~29
30~39
40~49***
50~59
60~69
70~79**
80~89****
90~99**
100:*
```

因为分数变化是区间是十分递增，所以可以用循环来打印分数区间，并判断对应区间的人数，利用`while`控制打印*的数量

#### 2.2.6 把array对象元素当作计数器

【掷一个六面体骰子600000次,统计每个面出现的次数】

```cpp
#include<iostream>
#include<array>
#include<windows.h>
#include<iomanip>
#include<ctime>
#include<random>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    default_random_engine engine(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<unsigned int> randomint(1,6);
    array<int,7>a={0};
    for(size_t i=0;i<600000;i++)
    {
        a[randomint(engine)]++;
    }
    for(size_t i=1;i<a.size();i++)
    {
        cout<<i<<"点数出现次数："<<a[i]<<endl;
    }
    cout<<"总共"<<a[6]+a[1]+a[2]+a[3]+a[4]+a[5]<<endl;
}
/**********************终端****************************/
1点数出现次数：100206
2点数出现次数：99568
3点数出现次数：100086
4点数出现次数：100159
5点数出现次数：99773
6点数出现次数：100208
总共600000
```

本例程用到了C++11的随机数生成方法，首先需要包含头文件<random>，其次用到了时间戳，要包含头文件<ctime>，使用随机数生成引擎`default_random_engine engine()`，形参是时间戳，要求无符号整型`static_cast<unsigned int>`,使用类模板`uniform_int_distribution<>`定义一个无符号整型的数`randomint`，范围是1~6。 `uniform_int_distribution<unsigned int> randomint(1,6);`，`randomint(engine)`为生成的随机数。

然后直接用随机数作为a的下标，生成对应的数，对应的下标元素+1。生成的随机数只有1~6，所以用到的下标有1，2，3，4，5，6。a大小要为7，因为0不用。

#### 2.2.7 用array对象汇总调查结果

【统计等级评分，20人进行评价，打分1~5分，统计各分值人数】

```cpp
#include<iostream>
#include<array>
#include<windows.h>
#include<iomanip>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    const array<unsigned int,20> 
    evl={1,1,1,2,2,2,1,3,3,3,4,4,4,5,5,5,4,3,2,1};
    array<unsigned int,6> Grade={0};
    for(size_t i=0;i<20;i++)
    {
        Grade[evl[i]]++;
    }
    cout<<"等级"<<setw(8)<<"人数"<<endl;
    for(size_t i=1;i<=5;i++)
    {
        cout<<setw(2)<<i<<setw(8)<<Grade[i];
        cout<<endl;
    }
}
```

定义一个常量`array`对象`evl`来保存评价，再定义一个`array`对象`Grade`来统计各等级的人次，并用`evl`的值来作为`Grade`的下标进行统计。

访问`array`对象锁定义的大小之外的元素不会产生警告，C++中没有提供对array对象边界的自动检查机制，这是一个常见的漏洞。后续会介绍类模板`array`和`vector`中的`at`函数，他能够实现边界检查功能。

#### 2.2.8 静态和自动局部array对象

静态的array对象元素初始化代码只会执行一次，然后将初始化元素的值一直存在内存中，直到程序结束。以后每次读取的静态元素的值都是上一次进行改变之后的值。但自动array对象元素只存在于他的作用域内，出了作用域便会销毁，再次进入作用域又重新创建。

自己编写复杂代码进入终端运行陷入死循环卡死按`Ctrl+C`结束程序（仅限Windows系统）

```cpp
/**********************终端****************************/
欢迎使用该系统！

**********静态数组***********
当前静态数组元素为：
staticarr[0]=0   staticarr[1]=0   staticarr[2]=0
输入1,将静态数组元素全部加1
输入其他退出：(输入)1

当前静态数组元素为：
staticarr[0]=1   staticarr[1]=1   staticarr[2]=1
输入1，将静态数组元素全部加1
输入其他退出：(输入)2

**********自动数组***********
当前自动数组元素为：
autocarr[0]=0   autocarr[1]=0   autocarr[2]=0
输入1，将自动元素全部加1
输入其他退出：(输入)1

当前自动数组元素为：
autoarr[0]=1   autoarr[1]=1   autoarr[2]=1
输入1，将自动数组元素全部加1
输入其他退出：(输入)2

请输入要再次调用的array对象(1.静态  2.自动)：(输入)1

**********静态数组***********
当前静态数组元素为：
staticarr[0]=1   staticarr[1]=1   staticarr[2]=1
输入1,将静态数组元素全部加1
输入其他退出：(输入)2

是否继续使用该系统？(1.继续  2.退出)：(输入)1
请输入要再次调用的array对象(1.静态  2.自动)：(输入)2

**********自动数组***********
当前自动数组元素为：
autocarr[0]=0   autocarr[1]=0   autocarr[2]=0
输入1，将自动元素全部加1
输入其他退出：(输入)2

是否继续使用该系统？(1.继续  2.退出)：(输入)2
```

代码：

```cpp
#include<iostream>
#include<array>
#include<windows.h>
#include<iomanip>
#define A SetConsoleOutputCP(65001)
using namespace std;
void staticarray(void)
{
    A;
    int an=0;
    static array<int ,3> staticarr;
    cout<<"\n\n**********静态数组***********\n";
    cout<<"当前静态数组元素为：\n";
    for(size_t i=0;i<staticarr.size();i++)
        cout<<"staticarr["<<i<<"]="
            <<staticarr[i]<<"   ";
    cout<<endl;
    cout<<"输入1,将静态数组元素全部加1\n输入其他退出：";
    cin>>an;
    while(1==an)
    {
        size_t i=0;
        cout<<"\n当前静态数组元素为：\n";
        for(;i<staticarr.size();i++)
        {
            staticarr[i]=(staticarr[i]+1);
            cout<<"staticarr["<<i<<"]="
                <<staticarr[i]<<"   ";
        }
        cout<<endl;
        cout<<"输入1，将静态数组元素全部加1\n输入其他退出：";
        cin>>an;
    }
}
void autoarray(void)
{
    A;
    int an=0;
    array<int,3>autoarr={0,0,0};
    cout<<"\n\n**********自动数组***********\n";
    cout<<"当前自动数组元素为：\n";
    for(size_t i=0;i<autoarr.size();i++)
        cout<<"autocarr["<<i<<"]="
            <<autoarr[i]<<"   ";
    cout<<endl;
    cout<<"输入1，将自动元素全部加1\n输入其他退出：";
    cin>>an;
    while(1==an)
    {
        size_t i=0;
        cout<<"\n当前自动数组元素为：\n";
        for(;i<autoarr.size();i++)
        {
            autoarr[i]=autoarr[i]+1;
            cout<<"autoarr["<<i<<"]="
                <<autoarr[i]<<"   ";
        }
        cout<<endl;
        cout<<"输入1，将自动数组元素全部加1\n输入其他退出：";
        cin>>an;
    }   
}
int main()
{
    A;
    int man=1;
    cout<<"\n欢迎使用该系统！\n";
    staticarray();
    autoarray();
    while(1==man)
    {
        int saa=0;
        cout<<"\n\n请输入要再次调用的array对象(1.静态  2.自动)：";
        cin>>saa;
        while(1==saa)
        {
            staticarray();break;
        }
        while(2==saa)
        {
            autoarray();break;
        }
        cout<<"\n是否继续使用该系统？(1.继续  2.退出)：";
        cin>>man;
    }
}
```

### 2.3 基于范围的for语句

用于从array对象的第一个元素到最后一个元素的遍历，语法：

`for(元素类型 自定义变量:[容器]) { 语句 }`

**元素类型可直接设置为auto自动识别类型**

容器可以是任何标准容器：array、vector、list等创建的对象。for的一次执行就相当于，从容器第一个元素开始，把元素的值赋给自定义变量，然后执行语句，然后再进行for，直到最后一个元素。

上面为按值传递，仅用于访问元素（对元素只读）。还可以按引用遍历，可以改变元素的值（对元素写入），变量作为了地址，在语句中通过操作自定义变量可以间接改变元素的值，语法：

`for(元素类型 &自定义变量:[容器]) { 语句 }`

```cpp
array<int ,3> arr={1,2,3};
for(int x:arr)//把元素的每个值给x
{
    x=x+1;//x的值自增1
}//x的作用域结束，x销毁，元素值不变
cout<<endl;
for(int x:arr)//把元素的每个值给x
{
    cout<<x<<"  ";//打印每个x的值，x的值存放着元素的值
    //相当于打印元素的值 1  2  3
}
cout<<endl;
for(int &y:arr)//把元素的地址给告诉y
{
    y=y+1;//y的值就是元素的值，每个元素的值自增1
}//y的作用域结束，y销毁，元素值增1
cout<<endl;
for(int y:arr)
{
    cout<<y<<"  ";//打印2  3  4
}
cout<<endl;
/**********************终端****************************/
1  2  3
2  3  4
```

不要求访问下标时建议使用基于范围的for循环，防止访问出容器边界

### 2.4 实例研究：利用array对象存放成绩的Gradebook类

【升级Gradebook类，十名学生的成绩分别为：87,68,94,100,83,78,85,91,76,87。统计平均分，最高分，最低分，用条形图显示分数分布】

```cpp
//book.h
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
	explicit Gradebook(std::string &, std::string &, std::array<int, students>&);//构造函数的接口
	void set(std::string name);//set函数的接口,获取课程名
	std::string getTitle() const;//getTitle函数的接口，返回成绩册标题
	void prtTitle() const;//prt函数的接口,打印标题
	void prtName() const;//prt函数的接口,打印课程名
	double stuAverage() const;//stuAverage函数的接口，计算所有stu平均分
	int getMax()const;//获取成绩最大值
	int getMin()const;//获取成绩最小值
	void displaystu();//打印每个同学的成绩
	void displaystatistics();//统计条形图
private://私有数据成员
	std::string bookTitle;//成绩册标题
	std::string courseName;//课程名称
	std::array<int, students> stu;//创建一个array对象stu，存放每个学生的成绩
};
#endif
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
#include<array>
/*构造函数的三个参数，标题，课程名，array各元素*/
Gradebook::Gradebook(std::string& title, std::string&name, std::array<int, students>& student)
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
double Gradebook::stuAverage()const
{
    unsigned int s = 0;
    size_t count = 0;
    for (int sum : stu)
    {
        s += sum;
        count++;
    }
    return static_cast<double>(s) / count;
}
int Gradebook::getMax()const
{
    static int max_s = 0;
    for (int max : stu)
    {
        (max>=max_s)?(max_s=max):(max_s=max_s);
    }
    return max_s;
}
int Gradebook::getMin()const
{
    static int min_s = 100;
    for (int min : stu)
    {
        (min<=min_s) ? (min_s=min) : (min_s = min_s);
    }
    return min_s;
}
void Gradebook::displaystu()
{
    std::cout << "各学生成绩如下:\n";
    for (int stud : stu)
    {
        static size_t i = 1;
        std::cout <<std::setw(8)<< i++ << "号学生成绩：" << stud << std::endl; 
    }
}
void Gradebook::displaystatistics()
{
    std::array<int, students+1>classify = { 0 };
    for (size_t i = 0; i < classify.size()-1; i++)
    {
        for (size_t j = 0; j < stu.size(); j++)
        {
            if ((stu[j] >= 10 * i) && (stu[j] <= 10 * i + 9))
                classify[i]++;
        }
    } 
    for (size_t j = 0; j < stu.size(); j++)
    {
        if (stu[j] == 100)
            classify[students]++;
    }
    std::cout << "各分段人数统计图如下：\n";
    for (size_t i = 0; i < stu.size(); i++)
    {
        std::cout <<std::setw(10)<< 10 * i << "~" << i * 10 + 9 << "：";
        for (size_t j = 0; j < classify[i]; j++)
            std::cout << "*";
        std::cout << std::endl;
    }
    std::cout << std::setw(15) << "100：";
    for (size_t i = 0; i < classify[10]; i++)
        std::cout << "*";
    std::cout << std::endl;  
}
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
#include<array>
using namespace std;
int main()
{
	string s = "您好！\n欢迎查看成绩册\n";
	string k = "数学\n";
	array<int, Gradebook::students>stu = { 87,68,94,100,83,78,85,91,76,87 };
	Gradebook book(s,k,stu);
	book.prtTitle();
	book.prtName();
	book.displaystu();
	cout << setprecision(2) << fixed;
	cout <<setw(20)<<"\n平均成绩为：" << book.stuAverage() << endl;
	cout << setw(20) << "最高成绩为：" << book.getMax() << endl;
	cout << setw(20) << "最低成绩为：" << book.getMin() <<"\n" << endl;
	book.displaystatistics();
}
```

**类的头文件**

类中成员函数

> 将之前的`prt`修改为`prtTitle`和`prtName`，一个迎来打印成绩册标题，一个迎来打印课程名称。
>
> 将之前的`get`修改为`getTitle`，用来获取成绩册标题。
>
> 新增了一个`stuAverage`,用来计算平均成绩。
>
> 新增了`getMax`和`getMin`，返回成绩最大值和最小值。
>
> 新增了`displaystu`来打印许所有学生成绩。
>
> 新增了`displaystatistics`来打印统计的条形图。

类中数据成员

> 新增了一个公有的`students`用来保存学生总人数，。
>
> 新增了一个bookTitle保存成绩册标题
>
> 新增了一个array对象stu来存放每个学生的成绩

构造函数：

接收三个参数分别为`string`、`string`、`array`，全部为按引用传参，比之前按值传参效率更高。

**头文件的cpp文件：**

构造函数构造函数的三个形参的值`title`、`name`、`student`，创建对象初始化时通过引用，直接改变了私有数据成员的值。

`stuAverage()`函数：函数返回成绩的平均值，防止值被修改，将返回值用`const`修饰。函数体内定义了一个无符号整型变量s来存放总成绩，`size_t`类型的`count`来作为计数器，保存总人数。然后使用基于范围的for语句来计算值。最后返回值(总成绩s/总人数`count`)，计算出来的返回值可能为小数，由于s和`count`都为整型，会丢失精度。所以使用`static_cast<>()`来将s强制转换为`double`型，通过升级，`count`也将被隐式转换为`double`型。

`getMax()`和`getMin()`函数：通过`? :`运算符来获取最大值。

`displaystatistics()`函数：首先创建了一个`array`对象`classify`，用来统计各分段成绩人数，`classify`大小为成绩的分段，共有11个。用循环来将分段打印出来，十分一个分段，满分为另外一个分段单独计算，所以循环次数要减一。打印时`classify`作为循环次数打印`*`，来显示条形图。

**main文件**

定义两个string变量作为成绩册标题和科目名称，作为构造函数前两个形参。创建了一个array对象stu作为学生成绩，并初始化，stu为构造函数第三个形参。然后打印标题和成绩。再通过`setprecision()`和`fixed()`函数保留两位小数,输出平均分。输出最高成绩和最低成绩，最后打印条形图。

### 2.5 实例研究：array对象的排序与查找

通过C++内置的标准库函数，`sort`来对`array`对象的元素进行排序，`binary_search`来对`array`对象的元素进行查找，查找前元素必须是升序的。

```cpp
#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
int main()
{
    const size_t i=5;
    array<int,i> m=
    {3,2,5,4,1};
    array<char,i> ch=
    {'b','d','a','g','l'};
    cout<<"数字原序:";
    for(int ma:m)
        cout<<ma<<' ';
    cout<<endl;
    cout<<"字母原序:";
    for(char c:ch)
        cout<<c<<' ';
    cout<<endl;
     cout<<"数字升序:";
    sort(m.begin(),m.end());
    for(int ma:m)
        cout<<ma<<' ';
    cout<<endl;
    cout<<"字母升序:";
    sort(ch.begin(),ch.end());
    for(char c:ch)
        cout<<c<<' ';
    cout<<endl;
    cout<<"查找字母:  ";
    char c='0';
    cin>>c;
    bool j=binary_search(ch.begin(),ch.end(),c);
    string t="找到了";
    string f="没找到";
    string n="0";
    j?n=t:n=f;
    cout<<n<<endl;
    cout<<"查找数字:  ";
    int d=0;
    cin>>d;
    j=binary_search(m.begin(),m.end(),d);
    j?n=t:n=f;
    cout<<n<<endl;
}
```

上述例程sort()函数中有两个形参begin在前，end在后，表示升序。

binary_search()函数比sort多一个参数，查找的元素。

使用这两个函数前要包含头文件<algorithm>，后续章节详细解释。

### 2.6 多维array对象

#### 2.6.1 2-D array对象

二维array对象，类似于C中二维数组。

```cpp
#include<iostream>
#include<array>
using namespace std;
int main()
{
    size_t rows=2;
    size_t cols=3;
    array<array<int ,cols>,rows>arr1=
    {1,2,3,4,5,6};
    array<array<int ,cols>,rows>arr2=
    {1,2,3,4};
    cout<<“数组1元素\n”;
    for(auto const &row:arr1)
    {
        for(auto const &col:row)
            cout<<col<<" ";
    	cout<<endl;
    }
    cout<<“数组2元素\n”;
    for(auto const &row:arr2)
    {
        for(auto const &col:row)
            cout<<col<<" ";
    	cout<<endl;
    }
}
```

创建二维array对象，先创建一个一维array对象作为二维array对象的类型，一维对象的大小为列数n，二维对象的大小为行号m。二维array对象类型的位置实际上是已经创建了一个大小为n的一维array对象，然后把这个一维array对象拓展m份。

打印时需要嵌套基于范围的for语句，或者嵌套普通的for语句

for类型auto自动匹配，外层for为自定义变量+和array对象名。内层for为自定义变量+外层的自定义变量。

arr是一个二维数组，外层for中的arr，传给row的是一个一维数组，从arr的第一行开始，一行行把一维数组传给row，row最后是一维数组

内层的for中的row作为一个一维数组，把一个个值传给col，col最后是具体的值。

#### 2.6.2 实例研究：2-D array对象的Gradebook类

【升级Gradebook类，统计十名学生的语数英三门课的成绩(87,68,94,100,83,78,85,91,76,87,67,100,87,36,76,15,65,46,98,67,98,45,87,76,56,100,76,34,100,87)，所有成绩的最大值和最小值，和所有科目成绩分段条形图】

```cpp
//book.h
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

	explicit Gradebook(std::string &, 
		std::array<std::array<int ,subject>, students>&);//构造函数的接口
	std::string getTitle() const;//getTitle函数的接口，返回成绩册标题
	void prtTitle() const;//prt函数的接口,打印标题
	double stuAverage(std::array<int, subject>&) const;//stuAverage函数的接口，计算所有stu平均分
	int getMax()const;//获取成绩最大值
	int getMin()const;//获取成绩最小值
	void displaysubstu();//打印每个同学各科成绩的成绩
	void displaystatistics();//统计条形图
private://私有数据成员
	std::string bookTitle;//成绩册标题
	std::array<std::array<int ,subject>, students> stu;//创建一个array对象stu，存放每个学生的成绩
};
```

```cpp
//book.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
#include<array>
Gradebook::Gradebook(std::string& title,
    std::array<std::array<int,subject>, students>& student)
    :bookTitle(title), stu(student)
{
}
std::string Gradebook::getTitle() const
{
    return bookTitle;
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
```

```cpp
//main.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include"book.h"
#include<array>
int main()
{
	string s = "您好！欢迎查看成绩册\n";
	array<array<int,Gradebook::subject>, Gradebook::students>stu = 
	{	87,68,94,
		100,83,78,
		85,91,76,
		87,67,100,
		87,36,76,
		15,65,46,
		98,67,98,
		45,87,76,
		56,100,76,
		34,100,87 };
	Gradebook book(s,stu);
	book.prtTitle();
	book.displaysubstu();
	book.displaystatistics();
	cout << setprecision(2) << fixed;
	cout << setw(20) << "\n最高成绩为：" << book.getMax() << endl;
	cout << setw(20) << "最低成绩为：" << book.getMin() << endl;
}
```

相对于上一个`Gradebook`来说，将其中的一维`array`对象全部替换为了二维`array`对象，使用嵌套的基于范围的`for`语句。

主函数中声明并初始化了一个二维`array`对象`stu`，用来存放各学生个各科成绩。之前`Gradebook`类中的一维`array`数据成员现在换成了二维`array`，作为存放成绩的容器，构造函数的参数为成绩册标题和一个二维`array`对象。主函数中创建`Gradebook`对象时，将两个参数传进去，一个是标题一个是array对象名。

`stuAverage`函数中，需要一个一维`array`对象作为形参，但传实参是要的是对象名。

`displaysubstu`函数中调用了`stuAverage`函数并传入了参数`stu[a-1]`，但是`stuAverage`要传的参数实际上应该是一个`array`对象名，此时`stu`是一个二维`array`对象，当他的索引只有一个数值i时，那么就代表他的值是将他的第i行当作了一个一维`array`对象，这个一维对象的名字就是stu[i],要访问他的第j个元素则为`stu[i][j]`。

## 3.vector

C++标准库类模板`verctor`与类模板`array`类似，但他支持动态调整大小。`verctor`在头文件<vector>中定义，它也属于命名空间std。后续章节将讨论有关`vector`的全部内容。

### 3.1 创建vector对象

 创建`verctor`对象与`array`不同的是，`vector`对象的<>中只有类型，而它的大小跟在`vector`对象名后的括号内。格式：

`vector<int>vct1(10);`表示创建了一个大小为10的整型`vector`对象

### 3.2 实例研究：vector对象的基本操作

```cpp
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>//异常捕获
using namespace std;
static void inputvct(vector<int>&vct)//输入vector对象
{
	for (int &temp : vct)
		cin >> temp;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
static void outputvct(const vector<int>&vct)//输出vector对象
{
	for (int temp : vct)
		cout << temp<<" ";
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
	cout <<setw(25)<< "vector2对象的元素为：";
	outputvct(vct2);
	(vct2 == vct1) ? (cout << "vct2等于vct1"<<endl) : (cout << "vct2不等于vct1" << endl);
	vector<int>vct3;
	vct3 = vct1;
	cout << "将vector1赋值给vector3，";
	cout << "vector3对象的元素为：";
	outputvct(vct3);
	(vct3 == vct1) ? (cout << "vct3等于vct1" << endl) : (cout << "vct3不等于vct1" << endl);
	vct3[3] = 10086;
	cout << "将10086赋值给vector3[3],";
	cout <<  "vector3对象的元素为：";
	outputvct(vct3);
    cout<<"当前vector3的大小为："<<vct3.size()<<endl;
    cout<<"给vector3新增两个元素：66，99"<<endl;
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
    /*异常捕获*/
}
/**********************终端****************************/
请输入vector1对象的元素：1 2 3 4 5 6 7
    vector1对象的元素为：1 2 3 4 5
请输入vector2对象的元素：9 8 7 6 5 4 3 2 1 0
    vector2对象的元素为：9 8 7 6 5 4 3 2 1 0
vct2不等于vct1
将vector1赋值给vector3，vector3对象的元素为：1 2 3 4 5
vct3等于vct1
将10086赋值给vector3[3],vector3对象的元素为：1 2 3 10086 5
当前vector3的大小为：5
给vector3新增两个元素：66，99
当前vector3对象的元素为：1 2 3 10086 5 66 99
当前vector3的大小为：7
给vector3弹出一个元素
vector3对象的元素为：1 2 3 10086 5 66
当前vector3的大小为：6
```

`vecter`对象可以互相比较是否相同，也可以互相赋值，也可以对单个元素进行操作。

最大的不同在于vector对象可以通过调用他的成员函数`push_back`和`pop_back`来对`vector`对象的大小进行动态增减，从这里可以看出`vector`也是一个堆栈结构。

`push_back()`函数有一个形参，即为要添加的元素。

`pop_back()`函数没有形参

`resize()`函数可以动态调整vector对象的大小

```cpp
std::vector<int> vec(5);  // 初始大小为5
vec.resize(10);  // 扩展到10个元素，新元素默认初始化为0
vec.resize(3);  // 缩小到3个元素，超出部分被丢弃
```



## 4.基于vector对象的异常捕获

延续上述例程，在原有基础上，进行异常处理。在上个例程`/*异常捕获*/`行添加如下代码：

```cpp
try
{
	cout << "尝试打印vector1[15]的值" << endl;
	cout << vct1.at(15) << endl;
}
catch(out_of_range &ex)
{
	cerr << "已引发异常：" << ex.what() << endl;
}
cout << "异常已处理" << endl;
```

处理一个异常，需要把可能引发异常的任何代码放进try语句块中，如果引发异常，则执行相应的catch语句块，未引发异常，则忽略catch语句块。

vector的成员函数at提供了边界检查和异常抛出的功能，也就是说at函数的实参是一个无效的下标，该语句就会抛出一个异常：`out_of_range`，然后立即终止try语句块，开始执行catch语句块。如果at函数的实参是一个有效的下标，那么at函数将返回该下标的元素值。

catch语句块声明了一个类型(out_of_range)和一个接收引用的异常形参(ex)。当catch语句块捕捉到异常后，程序调用这个异常对象的成员函数what来显示一则错误消息，一旦这个消息被显示，这个异常就视为已被处理，然后继续执行catch语句块下面的语句。

# 八、STL容器

## 1.vector

- 头文件`#include <vector>`
- 动态可变数组
- 可随机存取元素，通过`at()`方法或者下标运算符访问

### 1.1 构造方式

vector采用类模板实现,默认构造方式：

`vector<类型> 名字;`

带参数的构造方式：

- `vector<类型> 名字(begin,end);`——将begin到end区间的元素存储到vector中，begin和end是指针

  ```cpp
  #include <iostream>
  #include<vector>
  
  using namespace std;
  
  int main()
  {
  	int arr[] = { 1,2,3,4,5 };
  	vector<int> Arr(arr, arr + 5);
  	for (auto x : Arr)
  	{
  		cout << x << " ";
  	}
  }
  
  /*
  1 2 3 4 5
  */
  ```

  

# 七、指针

## 0.引言

C++中的指针与C中指针大致相同。并继承了C中的数组，C++中称为内置数组，但C++中的`array`和`vector`类模板创建的对象更加先进成熟，实际上`array`和`vector`将他们的元素存在内置数组中。C++中提供了两种类型的字符串，一种是`string`类对象，另一种是C语言中基于指针的字符串。新的软件开发项目中，`string`字符串更方便使用，也更好理解。

## 1.指针

### 1.1 指针变量

与C中相同，指针变量把内存的地址作为值，而在这个内存的地址有一个实际的值，所以这个指针间接引用了这个值，称为指针指向了这个值。指针变量也是变量，使用前要声明和赋值。

`int *p1,*p2,a;`//声明了两个指向整型值的指针变量和一个整型变量，*表示是一个类型，不是运算符，实际的指针是p1和p2，而不是 *p1 和 *p2。

没有赋值的指针会指向一个未知的内存空间，没有具体的赋值地址的话要把指针赋值为`nullptr`(C++11新特性)或`NULL`(C中通用)，这样的指针称为空指针，他没有指向任何内存地址。

### 1.2 指针运算符

#### 1.2.1 地址运算符(取地址，引用)

`&`是取地址运算符，对变量使用，放在变量之前，用来获得变量的地址，格式：`&k` 这个表达式的值就是k的地址，然后将这个地址赋值给指针变量，格式：`p1=&k;`这条语句的意思就是指针p1指向了k。

#### 1.2.2 间接运算符(解地址/解引用)

`*`是间接运算符，对指针变量使用，放在指针变量前，用来获取指针指向的变量,格式：`*p`，这个表达式的值是p指向的变量，例如：

```cpp
int *p=nullptr,k=0;
p=&k;
*p;//*p就代表变量k
cout<<*p<<endl;//就相当于cout<<k<<endl;
```

对解引用的指针操作，就是对该指针指向的变量进行操作。

```cpp
int a=7;
int *p=nullptr;
p=&a;
cout<<&a;//0x51C8A1(地址)
cout<<p;//0x51C8A1(地址)
cout<<a;//7
cout<<*p;//7
```

### 1.3 使用指针的按引用传递方式

指针作为形参时候，实参应该为地址，而被调函数的形参应该为指针类型。eg：

```cpp
int main()
{
    int x=0;
    a(&x);//<-实参，地址
}
void a(int *p)//<-形参，指针
{
    
}
```

## 2. 内置数组

C中的数组，简要说明，仅强调一下重点，基础知识不再过多赘述

### 2.1 声明内置数组

格式：`元素类型 数组名 [数组大小];`  声明一个大小为10，元素为整型，名为arr的数组：`int arr[10];`

### 2.2 访问和初始化

下标从0，开始。通过数组名+[]来访问某个数组元素。

声明初始化列表：`int a[]={1,2,3,4,5};`,可以不指定数组大小，大小自动被设置为元素个数。

若指定大小，但未初始化，数组元素将是一个未知的值：

若指定大小，但初始化元素少于元素个数，未被初始化的元素为基本数据类型时，将被自动初始化为0，指针类型被初始化为nullptr，bool类型被初始化为false：

```cpp
int a[5] = {1,2};
int* b[5]={a,a};
bool c[5] = {false,true};
/***************************监视****************************/
a[0]=1	b[0]=0x000000eeefeff548	c[0]=false
a[1]=2	b[1]=0x000000eeefeff548	c[1]=true
a[2]=0	b[2]=0x0000000000000000	c[2]=false
a[3]=0	b[3]=0x0000000000000000	c[3]=false
a[4]=0	b[4]=0x0000000000000000	c[4]=false
```

### 2.3 内置数组作参数

当要将数组作为参数传入函数，传的是数组名，实参就是数组名`a`，和C一样，数组名可作为数组的首地址使用，数组`a`隐式的转换为了`&a[0]`。也就是说传的实参实际上是数组的首地址，那么就是一个指针的类型，所以形参的类型就要设置为指针类型`*`。但为了更直观的表示传进去的是一个数组，形参一般用数组名+下标运算符来表示。函数声明的类型要跟函数头一致，如果是`*`就都是`*`，如果是`[]`就都是`[]`，eg：

```cpp
void arr(int*);
//或void arr(int[]);
int main()
{
	int a[5] = { 1 };
	arr(a);
}
void arr(int* x){}
//或
//void arr(int x[]){}
```

### 2.4 内置数组排序查找

内置数组也可以像`array`和`vector`一样使用<algorithm>中的sort和binary_search函数来进行排序和查找，`array`和`vector`通过他俩的成员函数`begin`和`end`来进行排序。

C++11也提供了可以对数组进行排序的`begin`和`end`，在头文件<iterator>中，将数组名作为实参传给`begin`和`end`，然后用sort排序 ：`sort(begin(a),end(a));`

查找binary_search使用方法相同，返回的也是一个`bool`类型的值，找到了返回`tuer`，未找到返回`false`。

### 2.5 内置数组的局限性

数组之间无法像`vector`对象那样，用关系运算符进行比较，也不能赋值。

并且数组不知道自己的大小，一个函数要对数组进行处理，必须将他的数组名和大小都作为参数传给函数。没有提供边界检查功能。

## 3.用const修饰指针

使用一个函数之前，要先检查他的函数体，查看哪些值（包括返回值）会被改变，哪些值没有被改变。如果一个值作为参数传进函数中，它的值不应该被改变或者没有改变，那这个值参数应该声明为`const`。指针传给函数如下有四种方式：

### 3.1 指向非const数据的非const指针

```cpp
///begin:非c数，非c指
int i1 = 1,j1=2;
int* p1 = &j1;//p1指针指向j1，指向的j1是一个int类型的数据
p1 = &i1;//改变指针指向i1
cout << "指向非const数据的非const指针" << endl;
cout <<"i1=" << *p1 << endl;//输出i1为1
(*p1)++;//通过指针使i1数据自增1
cout <<"i1=" << *p1 << endl;//修改成功，输出i1为2
//end:非c数，非c指
```

可以改变指针的指向，可以通过指针改变指向数据的值

### 3.2 指向const数据的非const指针

```cpp
///begin:c数，非c指
int i2 = 1, j2 = 2;
const int* p2 = &j2;//指针p2指向j2，指向的是const int类型的数据
p2 = &i2;//改变指针指向i2
cout << "\n指向const数据的非const指针" << endl;
cout<<"i2=" << *p2 << endl;//输出i2为1
 ///(*p2)++;//通过指针修改i2数据,errer，这条语句将p2指向的数据进行自增，但是p2指向的是一个const类型的值，值不可被修改
//i2的值不可被修改
cout <<"i2=" << *p2 << endl;//无法修改，输出i2还是为1
//end:c数，非c指针
```

可以改变指针的指向，不可以通过指针改变指向数据的值

### 3.3 指向非const数据的const指针

```cpp
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
```

不可以改变指针的指向，可以通过指针改变指向数据的值

### 3.4 指向const数据的const指针

```cpp
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
```

不可以改变指针的指向，不可以通过指针改变指向数据的值

## 4.sizeof运算符

`sizeof`是一个一元运算符，用来求一个目标的字节大小，这个目标可以是数组、常量、变量、数据类型等。格式：`sizeof(目标);`，返回一个`size_t`类型的数，单位是字节。

当目标为数组名，求出来的是整个数组的字节大小，当目标为这个数组元素的类型，求出来的是这个类型的字节大小。所以可以通过该方法来计算出数组大小：`sizeof(数组名)/sizeof(数组元素类型);`

## 5.指针算数运算

指针算数运算只适用于指向内置数组元素的指针。

假设如下情况来进行探讨：

```cpp
int a[5]={1,2,3,4,5};//声明一个整型数组a
int *p=a;//声明一个指针p指向数组a(的第一个元素a[0])
假设a[0]的内存地址为0x3000,则
&a[0]=0x3000,&a[1]=0x3004,&a[2]=0x3008
    &a[3]=0x300C,&a[4]=0x3010
p=a=&a[0]=0x3000
⬇
|  1  |  2  |  3  |  4  |  5  |
  a[0]  a[1]  a[2]  a[3]  a[4] 
    ⬆
   *p=a[0]=1
```

### 5.1 指针二则运算（加减）

如果`p=p+2`，他的实际意义是将指针往后移动两个位置，也就是指向元素a[2]，`p=&a[2]=0x3008`，并不是数学意义上的将地址的值直接加二`0x3000+2=0x3002`，在数学意义上指的是指的是`0x3000+2*sizeof(int)`，加的是元素类型所占内存地址的大小，`sizeof(int)`为4，`0x3000+2*4=0x3008`。

再p=p-1，则指向了p[1]。

如果两个指针相减，求的是这两个指针之间有几个元素，假设p1指向a[0]，p2指向a[3]，p2-p1结果是一个整数3，相当于下标相减的结果，表示的是从a[0]的地址到a[3]的地址有三个元素：a[0]、a[1]、a[2]。

### 5.2 指针赋值

两个同一类型的指针可以互相赋值，否则需使用强制类型转换符，将右侧的转换为和左侧相同类型的(使用`reinterpret_cast`，后续详细介绍)。`void*`类型除外，`void*`类型的指针可以被任意类型的指针赋值，但`void*`类型的指针不可以给其他类型的指针赋值。`void*`类型的指针不能被间接引用。

```cpp
int a=1;
int *p1=&a;
void* p3=nullptr;
double *p2=reinterpret_cast<double*>(p1);
p3=p1;
```

### 5.3 指针比较

指针之间可以使用相等运算符和关系运算符进行比较，指针的比较实际上是比较指针中存放的地址。例如两个指针指想相同的元素，那么它两的值就是相等的；两个指针指向数组元素，指向下标较大的指针的值，就比指向下标较小指针的值大。

```cpp
	int a[10] = { 0 };
	int* p1, * p2, * p3;
	p1 = &a[0];
	p2 = a;
	p3 = &a[1];
	(p1 == p2) ? (cout << "p1等于p2" << endl) : (cout << "p1不等于p2" << endl);
	(p1 < p3) ? (cout << "p1小于p3" << endl) : (cout << "p1大于p3" << endl);
/**********************终端****************************/
p1等于p2
p1小于p3
```

## 6.指针与内置数组

指针与数组密切相关，二者几乎可以交换使用。

### 6.1 表示法

#### 6.1.1 指针/偏移量表示法

声明一个数组`int a[10]={0};`，声明一个指针并指向这个数组`int *p=a;`。

此时表示数组元素

第一个元素：`a[0]`或`*(p+0)`

第二个元素：`a[1]`或`*(p+1)`

第n个元素：`a[n-1]`或`*(p+(n-1))`

指针表示法中的数字表示偏移量。

数组元素的地址：`&a[0]`等于`p+0`，`&a[n]`等于`p+n`

#### 6.1.2 以内置数组名表示

因为数组名就是第一个元素的地址，所以有a=&a[0]。

所以数组名本身就是一个指向自身数组的指针。

表示数组元素

第一个元素：`a[0]`或`*(a+0)`

第二个元素：`a[1]`或`*(a+1)`

第n个元素：`a[n-1]`或`*(a+(n-1))`

但是内置数组名是一个左值，它的值不可以被修改。

#### 6.1.3 指针/下标表示法

指针指向数组元素，如果把指针指向的元素看做是一个新数组首地址，那这个指针就可以作为这个新数组名来对数组进行下标放访问。如果指针指向的是一个数组的首地址，那这个指针自身就可以当作这个数组名来用。

声明一个数组`int a[10]={0};`，声明一个指针并指向这个数组`int *p=a;`。

访问数组元素：p[0]，p[1]，p[2]……

总结：如果有声明`int a[n]={m};` `int *p=a;` 那么**p<=>&a[0]<=>a**完全等价

```cpp
int a[5] = { 1,2,3,4,5 };
int* p0 = a;
int* p1 = &a[1];
int* p2 = &a[3];
/*
遍历a[0]~a[5]：1 2 3 4 5
遍历p0[0]~p0[5]：1 2 3 4 5
遍历p1[0]~p1[5]：2 3 4 5 -858993460//越界访问，p1[4]为未知元素
遍历p2[0]~p2[5]：4 5 -858993460 -858993460 -858993460//越界访问，p2[2]~p2[4]为未知元素
*/
```

### 6.2 实例研究：指针与内置数组

```cpp
#include<iostream>
#include<iomanip>
using namespace std;
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
/**********************终端****************************/
声明一个数组a[5] = { 1,2,3,4,5 }        声明一个指针p指向a

数组名表示元素：        指针表示元素：
        a[0]=1                p[0]=1
        a[1]=2                p[1]=2
        a[2]=3                p[2]=3
        a[3]=4                p[3]=4
        a[4]=5                p[4]=5

数组偏移量表示：        指针偏移量表示：
      *(a+0)=1              *(p+0)=1
      *(a+1)=2              *(p+1)=2
      *(a+2)=3              *(p+2)=3
      *(a+3)=4              *(p+3)=4
      *(a+4)=5              *(p+4)=5
```

## 7.基于指针的字符串

C++中使用`string`类对象来直接表示字符串，还可以使用基于指针的C字符串。

### 7.1 字符串

每一个字符（数字、字母、符号、特殊符号、换行、空格等）都表示一个整数值，叫做字符的ASCII码，字符由单引号`‘’`引起来。`'a','A',' ','\n','1','*'`。

字符串就是将一个字符序列看成一个整体，用双引号`“”`引起来。`"aA1 2&*\n"`。

### 7.2 基于指针的字符串

由一个空字符`‘\0’`来结尾的字符数组，利用`sizeof`求出来的C字符串长度包括这个空字符。

### 7.3 字符串的初始化和访问

C字符串是一个`char`指针（数组）类型的值，初始化时要将值用双引号引起来。访问时与访问数组相同，每个字符作为一个数组元素

```cpp
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	char c[] = "hello world!";
	const char* pc = "你好，世界！";
	char s[] = "123";
	const char* ps = "123";
	for (int i=0;i<(sizeof(c))/sizeof(c[0]);i++)
	{
		cout <<"c["<<i<<"]=" << c[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < (sizeof(s)) / sizeof(s[0]); i++)
	{
		cout << "s[" << i << "]=" << s[i] << endl;
	}
	cout << endl;
	((s[3] != '\0')&&(c[12]!='\0')) 
		?(cout << "s[3]和c[12]不是空字符" << endl)
		: (cout << "s[3]和c[12]是空字符" << endl);
	cout << c << "  " << pc << endl;
	cout << s << "  " << ps << endl;
	cout << "c的第四个元素：" << c[3] << endl;
}
/**********************终端****************************/
c[0]=h
c[1]=e
c[2]=l
c[3]=l
c[4]=o
c[5]=
c[6]=w
c[7]=o
c[8]=r
c[9]=l
c[10]=d
c[11]=!
c[12]=

s[0]=1
s[1]=2
s[2]=3
s[3]=

s[3]和c[12]是空字符
hello world!  你好，世界！
123  123
c的第四个元素：l
```

当字符串使用指针初始化时，必须声明为const，因为指针指向的时单个字符，是常量。

# 八、类的深入剖析：抛出异常

## 0.引言

本章通过一个新的完整的类Time来进行详细研究。

## 1.Time类的实例研究

### 1.1 Time类的定义

定义一个`Time`类。类中包含四个`public`成员函数，其中包括一个构造函数。还包含三个数据成员。该类的功能 是获取时间，打印时间。所以该类的成员：

用来获取时间的函数、用来打印时间的函数（12小时显示）、用来打印时间的函数（24小时显示）、用来存放时的变量、用来存放分的变量、用来存放秒的变量。

```cpp
//time.h
#ifndef _TIME_H
#define _TIME_H
class Time
{
public:    
    Time();
    void setTime(int,int,int);
    void prtTime24h()const;
    void prtTime12h()const;
private:
    unsigned int h;
    unsigned int m;
    unsigned int s;
};
#endif
```

### 1.2 Time类的成员函数

```cpp
#include"time.h"
#include<iostream>
#include<stdexcept>
#include<iomanip>
using namespace std;
Time::Time():h(0),m(0),s(0)
{ }
void Time::setTime(int shi, int fen, int miao)
{
	if ((shi >= 0 && shi < 24) && (fen >= 0 && fen < 60) && (miao >= 0 && miao < 60))
	{
		h = shi;
		m = fen;
		s = miao;
	}
	else
		throw invalid_argument("输入有误\n");
}
void Time::prtTime24h()const
{
		cout << "当前时间为："
		<< setfill('0') << setw(2) << h << ":" << setw(2) << 		m << ":" << setw(2) << s << endl;
}
void Time::prtTime12h()const
{
	if (h >= 12)
	{
			cout << "当前时间为："
		<< setfill('0') << setw(2) << h - 12 << ":" << 			setw(2) << m << ":" << setw(2) << s << "-PM" << endl;
	}
	else
	{
			cout << "当前时间为："
		<< setfill('0') << setw(2) << h << ":" << setw(2) << 		m << ":" << setw(2) << s <<"-AM" << endl;
	}
}
```

`Time()`构造函数,构造函数将私有数据变量的值初始化为0

`setTime()`函数接受三个整型变量，如果满足条件就将三个参数的值赋给对应的三个私有数据成员。如果不满足,则通过`throw`(**C++中的一个关键字**)主动，显式的抛出一个 `invalid_argument`类型的异常（称为throw创建了一个invalid_argment对象，但该对象是个临时对象，不可见）， `invalid_argument`是一个类，可以通过类名加括号直接调用构造函数，无需实例化对象。该构造函数允许用户自定义错误信息的字符串**"输入有误"**。异常对象被创建之后，throw语句立即终止setTime函数，异常返回到尝试设置时间的代码处。后续将通过try……catch语句来尝试修复异常。`invalid_argument`和`out_of_range`异常都属于头文件<stdexcept>。

两个`prtTime`函数里使用了`setfill`函数，该函数可以输出域宽大于输出的数字个数时，填充他实参的值。使用一次setfill函数后，后续的输出规则都将按照这样来进行输出，这种称为setfill是一个”粘性“设置。而setw函数调用之后，他只对紧接着输出的值起作用，setw是一个”非粘性设置“。

类中声明的成员函数，在其他文件中通过作用域分辨运算符绑定到该类，这个函数的作用域仍然在该类中。如果成员函数定义在类的体内，则该函数被隐式的升名为`inline`内联函数。

### 1.3 使用Time类

一旦定义了类，类就可以作为类型来进行如下声明（以Time类为例）：

`Time time`//声明了一个Time类的对象time，构造函数没有参数创建对象不需要加括号

`Time &d=p;`//引用了d，将d与time绑定（引用做别名）

`Time *p=&d;`//声明了一个指向Time类型的指针，该指针指向d（time）对象

`array<Time,5>a;`//声明了一个大小为5，存放Time类型数据的array对象a

```cpp
//main.cpp
#include<iostream>
#include"time.h"
using namespace std;
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
```

该段代码使用`try……catch`语句来处理一个错误。try语句尝试将无效的参数值传给setTime函数，执行`setTime`中`else`分支语句通过`throw`主动抛出一个`invalid_argument`类型的错误。然后主函数中的`catch`语句捕捉异常，参数创建了一个`invalid_argument`的对象e，并按引用传参，catch体内通过调用`invalit_argument`的成员函数`what()`来打印错误信息，此时`invalit_argument`的错误信息被我们自定义为**”输入有误“**，so:

```cpp
/**********************终端****************************/
当前时间为：
当前时间为：00:00:00-AM
当前时间为：00:00:00
修改时间：
当前时间为：12:25:52-PM
当前时间为：12:25:52
错误:输入有误

当前时间为：
当前时间为：12:25:52-PM
当前时间为：12:25:52
```

### 1.4 引入组成与继承

类一般不需要从头开始创建。类可以把其他类的对象作为自己的成员，或者可以由其他能为自己提供可以使用的属性和行为的**类派生**，通过这几种方式来创建类可以大大提高效率。把其他类作为自己类的成员称为**组成**或**聚合**，从已有的类派生出新的类称为**继承**。

## 2.类的作用域和类成员的访问

### 2.1 类作用域

类的成员函数和数据成员的作用域都属于该类的作用域。类作用域之内类的成员可以互相访问，在类作用域之外，类的public成员可以通过对象的句柄访问，句柄包括对象名、对象名的引用、对象的指针。

### 2.2 类作用域和块作用域

在任何函数（包括类的成员函数）内声明的变量具有块作用域，只有该函数知道他们，如果类中或者全局有同名的变量，他们将被忽略。

如要访问类中的同名变量，通过类名加二元作用域分辨运算符加变量名来访问该变量（`类名::同名变量名`）。

如果要访问全局变量，通过一元作用域分辨运算符加变量名来访问该变量（`::同名变量名`）

### 2.3 成员运算符

圆点运算符访问对象的成员：`对象名.成员`或&`对象名.成员`

箭头运算符访问对象的成员：`对象的指针->成员`或&`对象的指针->成员`

```cpp
/*...*/
class Time
{
/*...*/
public:
    setTime(int,int,int)
        /*...*/
}
int main()
{ /*...*/
    Time t;
    Time &b=t;
    Time *pt=&b;
    t.setTime();
    b.setTime();
    pt->setTime(); 
 /*...*/
}
```

## 3.访问函数和工具函数

访问函数可以读取或者显示数据，另一个作用是测试条件是真还是假（定义为bool类型，并且要声明为const），也被称为判定函数。例如任何容器类都有一个成员函数`isEmpty`就是一个判定函数，用来测试一个容器类对象是否都还有空间。

工具函数也称为助手函数，工具函数是private成员函数，但支持类的其他成员函数操作，工具函数需要被声明为private，因为他们不希望被类的客户使用。工具函数一个非常普遍的使用情况是，把一些公共代码放在一个函数中（这个函数就叫做工具函数），否则这些代码将重复出现在多个成员函数中，节省了代码量。

## 4.Time类实例研究

### 4.1 具有默认实参的构造函数

强化Time类，并将实参传递给构造函数，构造函数可以指定默认的实参值。

```cpp
//Time.h
#pragma once
#ifndef _TIME_H
#define _TIME_H
class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0);
	void setTime(int, int, int);
	void setH(int);
	void setM(int);
	void setS(int);
	void prtTime24h()const;
	void prtTime12h()const;
	unsigned int getH()const;
	unsigned int getM()const;
	unsigned int getS()const;
private:
	unsigned int h;
	unsigned int m;
	unsigned int s;
};
#endif
```

类中`explicit`声明了构造函数，它可以在调用时有一个实参，并三个实参值默认值设置为0。将在下章详细讨论`explicit`构造函数。

头文件中新增六个public成员函数：

`setH(int);`用于设置时，数据成员中的h，有一个int类型的实参

`setM(int);`用于设置分，数据成员中的m，有一个int类型的实参

`setS(int);`用于设置秒，数据成员中的s，有一个int类型的实参

`getH();`用于获取并返回设置好的时

`getM();`用于获取并返回设置好的分

`getS();`用于获取并返回设置好的秒

```cpp
//Time.cpp
#include"Time.h"
#include<iostream>
#include<stdexcept>
#include<iomanip>
using namespace std;
Time::Time(int shi,int fen,int miao)
{
	setTime(shi,fen,miao);
}
void Time::setTime(int shi, int fen, int miao)
{
	setH(shi);
	setM(fen);
	setS(miao);
}
void Time::setH(int shi)
{
	if (shi < 24 && shi >= 0)
		h = shi;
	else
		throw invalid_argument("时设置错误,范围0~23");
}
void Time::setM(int fen)
{
	if (fen < 60 && fen >= 0)
		m = fen;
	else
		throw invalid_argument("分设置错误,范围0~59");
}
void Time::setS(int miao)
{
	if (miao < 60 && miao >= 0)
		s = miao;
	else
		throw invalid_argument("秒设置错误,范围0~59");
}
void Time::prtTime24h()const
{
	cout << "当前时间为："
		<< setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
}

void Time::prtTime12h()const
{
	if (h > 12)
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << h - 12 << ":" << setw(2) << m << ":" << setw(2) << s << "-PM" << endl;
	}
	else if(h==12)
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << 12 << ":" << setw(2) << m << ":" << setw(2) << s << "-PM" << endl;
	}
	else
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s <<"-AM" << endl;
	}
}
unsigned int Time::getH()const
{
	return h;
}
unsigned int Time::getM()const
{
	return m;
}
unsigned int Time::getS()const
{
	return s;
}
```

在构造函数`Time()`中将默认的0值作为形参传给`setTime()`函数。

`setTime()`函数中，分别调用了三个`setX()`函数,并将形参值作为实参传给三个`setX()`函数，用于并单独判断设置时、分、秒。

在`setX()`函数中，首先对传进来的形参做了判断，如果范围设置合理，就将值赋值给对应的数据成员，否则`throw`主动抛出一个类型为`invalid_argument`的异常，并自定义错误信息文本。

`getX()`函数返回对应数据成员的值。

`prtTimeX()`函数打印时，打印的时函数`getX()`的值。

```cpp
//main.cpp
#include<iostream>
#include<stdexcept>
unsigned namespace std;
int main()
{
	Time t0;
	Time t1(13);
	Time t2(13,34);
	Time t3(13, 34, 55);
	cout << "打印t0的时间"<<endl;
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
	catch(invalid_argument &e)
	{
		cerr << "创建对象时已引发错误：" << e.what() << endl;
	}
}
```

主函数中初始化了5个对象：第一个未指定实参，隐式的构造函数调用时，使用默认的实参0；第二个指定了一个实参；第三个指定了两个实参；第四个指定了三个实参；第五个指定了三个无效实参。然后分别打印他们。

创建第五个对象时，把他放到`try`语句里，尝试将他的实参设置一个不合理的范围，当第一个参数传进去时，`Time.cpp`文件中的setH()函数就通过`throw`抛出一个类型为`invalid_argument`的异常，并将错误文本作为`invalid_argument`构造函数的参数传入。已引发异常，`try`语句立即终止，转入到`catch`语句处理这个异常。`catch`语句首先创建了一个`invalid_argument`类型的对象e，语句块内`cerr`显示错误信息，然后调用`invalid_argument`类的成员函数`what()`，来显示在我们使用`throw`主动抛出异常时，作为`invalid_argument`类构造函数参数传进去的自定义错误文本。

**C++11列表初始化器**

C++11提供了一种统一的初始化语法，称为列表初始化器，可以用来初始化任何变量，就是在需要初始化的变量后加花括号`{}`，花括号里放初始化的值。

例如：int x{1},double x{1.1},Time t{1,2,3}

**C++11重载构造函数和委托构造函数**

构造函数也可以重载，他们的参数类型或数量需要不同。如果要重载构造函数，那么需要为每一个构造函数写明它的函数原型。上述例程中的构造函数可以定义为如下四个重载的构造函数：

`Time();` `Time(int);` `Time(int,int);` `Time(int,int,int);`

C++11还允许一个重载的构造函数调用类中其他的构造函数，这样的构造函数称为委托构造函数，eg：

`Time::Time(int h) : Time(h,0,0){}`，第二个构造函数调用了第三个构造函数，并将参数作为第三个构造函数的第一个实参传进去，剩余两个为第三个构造函数的默认实参。

### 4.2 微妙的陷阱——返回private数据成员的引用或指针

写一个简单的time程序

```cpp
//simpleTime.h
#pragma once
#ifndef _SIMPLETIME_H
#define _SIMPLETIME_H
class simpleTime
{
public:
	explicit simpleTime(int =0,int =0,int =0);
	void setTime(int, int, int);
	unsigned int getH()const;
	unsigned int& setH(unsigned int);
private:
	unsigned int h;
	unsigned int m;
	unsigned int s;
};
#endif
```

getH函数用于返回私有成员h的值来查看，并用const将它设置为一个常量。

setH函数用来设置私有成员h，并返回私有成员h的值，返回是一个引用。

```cpp
//simpleTime.cpp
#include<stdexcept>
#include"simpletime.h"
using namespace std;
simpleTime::simpleTime(int shi, int fen, int miao)
{
	setTime(shi, fen, miao);
}
void simpleTime::setTime(int shi, int fen, int miao)
{
	if( (shi >= 0 && shi < 24) && (fen >= 0 && fen < 60) && (miao >= 0 && miao < 60))
	{
		h = shi;
		m = fen;
		s = miao;
	}
	else
		throw invalid_argument("输入错误\n");
}
unsigned int simpleTime::getH()const
{
	return h;
}
unsigned int& simpleTime::setH(unsigned int shi)
{
	if (shi >= 0 && shi < 24)
	{
		h = shi;
	}
	else
		throw invalid_argument("时设置有误\n");
	return h;
}
```

```cpp
//main.cpp
#include<iostream>
#include"simpleTime"
using namespace std;
int main()
{
	simpleTime t;
	unsigned int& d = t.setH(10);
	cout << "置时函数返回值的别名d=" << d << endl;
	cout << "通过成员函数获取私有数据成员的值：" << t.getH()<<endl;
	cout << "修改d的值为100" << endl;
	d = 100;
	cout << "通过成员函数获取私有数据成员的值：" << t.getH() << endl;
}
```

创建一个对象t,然后调用t的成员函数setH，并将返回值引用了一个b做别名。

通过修改引用b的值，可以间接改变私有成员h的值，破坏了类的封装。

## 5.析构函数

### 5.1 析构函数

析构函数是在类名前添加求补运算符`~`，在某种意义上来讲，构造函数和析构函数是互补的。析构函数不接受任何参数也不返回任何值,也没有初始化列表。构造函数初始化对象，析构函数清理对象占用的资源。与构造函数一样，析构函数如果没有被显式的调用，编译器会生成一个空的析构函数

### 5.2 构造函数与析构函数

这些函数的调用顺序由进入和离开对象实例化的作用域的顺序决定，一般来说析构函数和他的构造函数调用顺序相反。

#### 5.2.1 全局（auto）

全局作用域定义的对象的构造函数，在任何函数执行之前被调用，当主程序结束后，相应的析构函数被调用。`exit`和`abort`这类终止程序结束的函数执行时，析构函数不会被调用，他们的作用是迫使程序立即终止，而`abort`函数指的是程序非正常终止。

#### 5.2.2 局部（auto）

当程序在局部(花括号内`{}`)对象的定义处时，该对象的构造函数被调用，当离开该对象的作用域(花括号外`{}`)，析构函数被调用。

#### 5.2.3 静态（static）

静态局部对象的构造函数只在对象创建时被调用一次，析构函数在主函数结束时或使用exit()函数时被调用。使用`abort`函数不调用析构函数。

**总结：所有构造函数在他的对象创建时就被调用，自动构造函数在出他们的块作用域被调用，全局和静态析构函数在main结束调用，静态析构函数还可以通过exit函数终止程序来调用，abort函数执行不会调用任何状态的析构函数**

#### 5.2.4 实例研究

```cpp
//ca.h
#pragma once
#ifndef _CA_H
#define _CA_H
#include<string>
class ca
{
public:
	ca(size_t,std::string);
	~ca();
private:
	size_t count;
	std::string os;
};
#endif
```

```cpp
//ca.cpp
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
```

```cpp
//main.cpp
#include<iostream>
#include"ca.h"
using namespace std;
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
	cout << "test内创建一个auto对象5"<<endl;
	ca c5(5, "test块内，auto");
	cout << "test内创建一个static对象6" << endl;
	static ca c6(6, "test块内，static");
	cout << "test内创建一个auto对象7" << endl;
	ca c7(7, "test块内，auto");
	cout << "\t第" << i << "次test块内\tend\n" << endl;
}
```

```cpp
/************************终端**************************/
对象1的 构造 函数被调用————全局，自动

                main    begin

        第1次test块内   begin
test内创建一个auto对象5
对象5的 构造 函数被调用————test块内，auto
test内创建一个static对象6
对象6的 构造 函数被调用————test块内，static
test内创建一个auto对象7
对象7的 构造 函数被调用————test块内，auto
        第1次test块内   end

对象7的 析构 函数被调用————test块内，auto
对象5的 析构 函数被调用————test块内，auto
main内创建一个auto对象2
对象2的 构造 函数被调用————main块内，auto
main内创建一个static对象3
对象3的 构造 函数被调用————main块内，static

        第2次test块内   begin
test内创建一个auto对象5
对象5的 构造 函数被调用————test块内，auto
test内创建一个static对象6
test内创建一个auto对象7
对象7的 构造 函数被调用————test块内，auto
        第2次test块内   end

对象7的 析构 函数被调用————test块内，auto
对象5的 析构 函数被调用————test块内，auto
main内创建一个auto对象4
对象4的 构造 函数被调用————main块内，auto

        第3次test块内   begin
test内创建一个auto对象5
对象5的 构造 函数被调用————test块内，auto
test内创建一个static对象6
test内创建一个auto对象7
对象7的 构造 函数被调用————test块内，auto
        第3次test块内   end

对象7的 析构 函数被调用————test块内，auto
对象5的 析构 函数被调用————test块内，auto
                main    end

对象4的 析构 函数被调用————main块内，auto
对象2的 析构 函数被调用————main块内，auto
对象3的 析构 函数被调用————main块内，static
对象6的 析构 函数被调用————test块内，static
对象1的 析构 函数被调用————全局，自动
```

只有在对象的析构函数被调用了之后，才能再次调用构造函数。块作用域内的静态对象构造函数只会被调用一次，因为块作用域的析构函数在main函数结束才会被调用。构造函数和析构函数是对称的，最先被调用的构造函数，他的析构函数最后才会被调用。

## 6.默认的逐个成员赋值

同个类的对象可以互相赋值，  通过的是逐个成员赋值的方式进行的赋值。即赋值运算符右边对象的每个数据成员的值，赋值给左边对象相同的数据成员。eg:

```cpp
//testdate.h
#pragma once
#ifndef _TESTDATE_H
#define _TESTDATA_H
class Date
{
public:
	explicit Date(int = 2025, int =5 ,int = 7);
	void prt()const;
private:
	int y;
	int m;
	int d;
};
#endif
```

```cpp
//testdate.cpp
#include<iostream>
#include"testdate.h"
using namespace std;
Date::Date(int nian, int yue,int ri)
	:y(nian),m(yue),d(ri)
{}
void Date::prt()const
{
	cout << y << "年" << m << "月" << d << "日" << endl;
}
```

```cpp
//main.cpp
#include<iostream>
#include"testdate.h"
using namespace std;
int main()
{
	cout << "创建一个对象date1并给构造函数赋值2001，1，1"<<endl;
	Date date1(2001, 1, 1);
	cout << "打印date1：" ;
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
```

```cpp
/************************终端**************************/
创建一个对象date1并给构造函数赋值2001，1，1
打印date1：2001年1月1日
创建一个对象date2构造函数默认实参2025，5，7
打印date2：2025年5月7日
把date1赋值给data2
打印date1：2001年1月1日
打印date2：2001年1月1日
```

警告：当所用类的数据成员包含指向动态分配内存的指针时，逐个成员赋值的方法会引发严重的问题

## 7.const对象和const成员函数

类实例化对象时，用const修饰之后表示对象不可修改`const Time time(12,13,14)`，这样试图修改对象的任何操作都会导致编译错误。 const对象除了const成员函数以外，其他的成员函数不可被调用访问

```cpp
/*头文件*/
class Time
{
public:
    /*。。。*/
    void setH(int);
    void prtTime24h()const;
    /*。。。*/
}
/*cpp文件*/
int main()
{
    const Time t(12,2,9);//对象被const修饰
	//t.setH(12);//error,setH函数返回值不是const
    t.prtTime24h();//可以，prtTime24h()返回值类型是const
}
```

构造函数和析构函数不可被const修饰，并且一个const对象的常量性，是构造函数完成对象的初始化和析构函数的调用之间

## 8.组成：对象作为类的成员

将一个已有类的对象纳入一个新类这种功能称为组成。新类中被纳入的对象称为成员对象。eg:

```cpp
//comdate.h
#pragma once
#ifndef _COMDATE_H
#define _COMDATE_H

class Comdate
{
public:
	explicit Comdate(int =2000,int=1,int =1);
	int setday(int)const;
	void prt()const;
	~Comdate();
private:
	int y;
	int m;
	int d;
};
#endif
```

comdate类是用来初始化一个日期的

**warning：构造函数声明时要加explicit，初始化默认实参有值时，不需要引用，没有实参值时要加引用，并且要加const修饰！！！**

setday函数是用来单独判断月份的天数正确与否

prt函数打印当前设置的日期

```cpp
//comdate.cpp
#include<iostream>
#include<array>
#include"comdate.h"
using namespace std;
Comdate::Comdate(int nian,int yue,int ri )
{
	cout << "comdate的constructor被调用"<<endl;
	if (nian > 0 && nian < 2026)
		y = nian;
	else
		throw invalid_argument("年设置错误\n");
	if (yue > 0 && yue <= 12)
		m = yue;
	else
		throw invalid_argument("月设置错误\n");
	d = setday(ri);
	cout << "当前日期为：";
    prt();
}
int Comdate::setday(int ri)const
{
	const static array<int, 13>day{0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (ri<=day[m])
	{
		return ri;
	}
	if (2 == m && 29 == ri && ((0 == y % 400) || (0 != y % 100 && 0 == y % 4)))
		return ri;
	else
		throw invalid_argument("日设置错误\n");
}
void Comdate::prt()const
{
	cout<<y <<"年"<<m <<"月" <<d <<"日" << endl;
}
Comdate::~Comdate()
{
	cout << "comdate的desstructor被调用,当前日期为：" ;
	prt();
}
```

构造函数接收三个参数，分别是年月日，首先打印信息”构造函数被调用“，然后调用prt函数打印默认实参的日期。然后直接在构造函数中判断传入的年、月参数是否正确，若不正确则通过throw语句主动抛出invalid_argument异常并自定义错误文本,若正确将值分别赋给数据成员y和m。因为每个月的日不同，所以将传入构造函数的日参数，作为实参传给一个setday函数单独对天判断，并将函数返回值作为天数赋值给数据成员d

setday函数返回值为天数（int类型），并将返回值设为常量，传入函数是由为int类型的值。函数体内首先初始化了一个一个array对象，为每个月的最大天数，因为下标从0开始，月份没有0，为方便起见将array对象大小设为13，索引值为0~12，我们不使用0。然后开始进行判断，将月份作为下标，那么值就是该月的最大值，将传入的天数值与他作比较，如果传入的天数没超过该月的最大值那就说明传入正确，将传入的值返回，赋值给数据成员d。二月是个例外，如果传入的值是29，则要额外判断是否为闰年，因为闰年可以有29天，判断的条件就是传入的月份是2月，天数是29天，判断闰年，如果正确，就将传入的29返回赋值给数据成员d。否则（传入天数大于最大天数），抛出invalir_argument错误信息

prt函数将初始化完成的数据成员进行打印

析构函数调用时，打印信息”构造函数被调用“，然后再次打印一遍完成初始化的日期

```cpp
//comtemp.h
#pragma once
#ifndef _COMTEMP_H
#define _COMTEMP_H
#include<string>
#include"comdate.h"
class Comtemp
{
public:
	explicit Comtemp(const std::string&,const Comdate&);
	void prt()const;
	~Comtemp();
private:
	std::string name;
	Comdate birthday;
};

#endif
```

comtemp用来测试组成功能，该类将comdate类对象作为成员对象，首先要包含成员对象类的头文件

构造函数接收一个字符串类型作为姓名和一个comdate类型，来对数据成员初始化。没有默认实参值，按引用传递

prt函数打印姓名和comdate初始化的日期

数据成员一个是用来保存姓名，另一个是comdate类型的对象用来保存构造函数传入的值，但是他没有调用构造函数，所以给它赋值的时候，仅逐各成员赋值，使用默认复值的构造函数，仅将成员的值赋值过去

```cpp
//comtemp.cpp
#include<iostream>
#include"comtemp.h"
#include"comdate.h"
using namespace std;
Comtemp::Comtemp(const string& n, const Comdate& dat)
	:name(n),birthday(dat)
{
	cout << "Comtemp的constructor被调用\n";
	cout << "初始化成员name值为" << name << endl;
}
void Comtemp::prt()const
{
	cout << name << "的生日是";
	birthday.prt();
	cout << endl;
}
Comtemp::~Comtemp()
{
	cout << "Comtemp的destructor被调用" << endl;
}
```

构造函数俩个值分别传入，初始化数据成员，并打印消息和name的值

prt函数首先打印name的值，然后调用成员对象的prt函数，打印传进来的设置对象的日期值

析构函数打印结束信息

```cpp
#include<iostream>
#include<stdexcept>
#include"comdate.h"
#include"comtemp.h"
using namespace std;
int main()
{
	try
	{
		Comdate d(2025, 2,22);
		Comtemp t("小红", d);
		d.prt();
		t.prt();
	}
	catch (invalid_argument& e)
	{
		cerr << "输入有误" << e.what() << endl;
	}
}
```

主函数中将整个函数体放到try里，如果有异常，就执行catch语句，显示异常信息，没有异常则忽略

首先声明comdate类对象d并传入实参初始化日期值。然后声明comtemp类对象t，传入string实参和刚刚声明的comdate对象d，调用对象d的打印函数打印初始化的日期值，在调用t对象的打印函数打印生日

```cpp
/********************终端**********************/
comdate的constructor被调用
当前日期为：2025年2月2日
Comtemp的constructor被调用
初始化成员name值为小红
2025年2月2日
小红的生日是2025年2月2日

Comtemp的destructor被调用
comdate的desstructor被调用,当前日期为：2025年2月2日
comdate的desstructor被调用,当前日期为：2025年2月2日
```

主函数执行Comdate d(2025, 2,2);声明对象时打印终端2、3行

主函数执行Comtemp t("小红", d);声明对象时打印终端4、5行

主函数执行d.prt();打印终端第6行

主函数执行t.prt();打印终端第7行

主函数结束，返回，第一个被调用的析构是对象t的，打印终端第9行。第二个是在创建对象t时，在comtemp.h头文件的private成员里定义的一个comdate成员，没有传参，默认复制过去的构造函数，所以没有打印，结束时打印终端第10行。最后一个是主函数中创建对象d时的析构

**os：因为构造函数可以传参，析构函数不可以传参。所以在comtemp.h头文件中数据成员定义了一个对象，但没有括号，说明给它赋值时是默认构造函数（一个新的构造函数，空白），无参数，所以按照逐个成员赋值，默认构造函数的内容不会赋值，仅将数据成员的值拷贝过去**

## 9.友元

类的友元定义在类的作用域之外，但是可以访问private和protected成员的权力。类、函数、类的成员函数，都可以作为另一个类的友元。

### 9.1 友元的声明

如果一个东西要作为一个类的友元，那么在这个类里加如下声明

一个单独的函数作为友元：`friend 返回值类型 函数名(参数);`

整个类作为友元：`friend class 类名;`

友元是授予的，不是索取的，没有互相性。我把你声明为我的友元，只说明你可以访问我的东西，但是我不可以访问你的东西。

### 9.2 使用友元函数修改private数据

```cpp
#include<iostream>
using namespace std;
class Temp
{
	friend void set(Temp&, int);
public:
	Temp()
		:x(0)
	{	}
	void prt()const;
private:
	int x;
};
void Temp::prt()const
{
	cout <<"数据成员的值为：" << x << endl;
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
void set(Temp& y,int a)
{
	y.x = a;
}
/***************************终端**************************/
声明一个对象t
数据成员的值为：0
使用友元函数修改值为666
数据成员的值为：666
```

友元函数不需要额外声明，只需要在类中声明即可，并且不能再类的成员说明符里声明。

友元函数是C风格的单独的一个函数，接收一个Temp对象，和一个整型的值，接收的是主函数里声明的对象，和要改的值。函数体中访问对象数据成员的值并赋值。

最后通过prt函数打印数据成员的值

## 10.this指针

每个实例化的对象都有一个this指针，来访问对象自己的地址。this是一个地址，对象的this指针指向被实例化对象，this指针不是对象的一部分

使用this指针来避免命名冲突，用法与C语言中结构体指针类似，使用this加指向运算符(->)或者解引用(*)和圆点运算符(.)来进行对象成员的访问

### 10.1 使用this指针避免名字冲突

一个this指针的常用用法是，避免类的数据成员和成员函数中的变量同名，当成员函数中有和数据成员同名的变量，函数中默认使用函数的变量，而通过`this->数据成员`可以访问类的数据成员。用Time文件中的setH来举例

```cpp
void Time::setH(int h)
{
    if(h=>0&&h<24)
        this->h=h;//(*this).h;也可以
    else
        throw invalid_argument("时设置有误");
}
```

setH函数中有和数据成员同名的变量，在函数作用域内，数据成员将被隐藏，通过this指针可以访问数据成员

this指针的类型取决于对象的类型以及使用this的成员函数是否被声明为const。如果使用它的成员函数是一个const那么指针就是const类型的指针，否则非const

### 10.2 显式和隐式的使用this指针

```cpp
#include<iostream>
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
/********************终端**********************/
隐式使用x:              666
显式使用this->x:        666
显式使用(*this).x:      666

```

(*this)必须加括号。

### 10.3 使用this指针串联函数

使用this指针可以在同一条语句中调用多个函数，但这些函数的返回值必须是一个对象（this指针解引用，因为this指针指向对象）。修改Time文件

```cpp
//Time.h
#pragma once
#ifndef _TIME_H
#define _TIME_H
class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0);
	Time &setTime(int, int, int);
	Time &setH(int);
	Time &setM(int);
	Time &setS(int);
	void prtTime24h()const;
	void prtTime12h()const;
	unsigned int getH()const;
	unsigned int getM()const;
	unsigned int getS()const;
private:
	unsigned int h;
	unsigned int m;
	unsigned int s;
};
#endif
```

头文件中将设置时间的四个函数返回值类型设置成了Time类(型)的引用，返回值为this指针的解引用（this指针指向的就是对象本身，解引用后就是对象本身，所以返回值类型为Time）

```cpp
//Time.cpp
#include"Time.h"
#include<iostream>
#include<stdexcept>
#include<iomanip>
using namespace std;
Time::Time(int shi,int fen,int miao)
{
	setTime(shi,fen,miao);
}
Time& Time::setTime(int shi, int fen, int miao)
{
	setH(shi);
	setM(fen);
	setS(miao);
	return *this;
}
Time& Time::setH(int shi)
{
	if (shi < 24 && shi >= 0)
		h = shi;
	else
		throw invalid_argument("时设置错误,范围0~23");
	return *this;
}
Time& Time::setM(int fen)
{
	if (fen < 60 && fen >= 0)
		m = fen;
	else
		throw invalid_argument("分设置错误,范围0~59");
	return *this;
}
Time& Time::setS(int miao)
{
	if (miao < 60 && miao >= 0)
		s = miao;
	else
		throw invalid_argument("秒设置错误,范围0~59");
	return *this;
}
void Time::prtTime24h()const
{
	cout << "当前时间为："
		<< setfill('0') << setw(2) << getH() << ":" << setw(2) << getM() << ":" << setw(2) << getS() << endl;
}

void Time::prtTime12h()const
{
	if (h > 12)
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << getH() - 12 << ":" << setw(2) << getM() << ":" << setw(2) << getS() << "-PM" << endl;
	}
	else if(h==12)
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << 12 << ":" << setw(2) << getM() << ":" << setw(2) << getS() << "-PM" << endl;
	}
	else
	{
		cout << "当前时间为："
			<< setfill('0') << setw(2) << getH() << ":" << setw(2) << getM() << ":" << setw(2) << getS() <<"-AM" << endl;
	}
}
unsigned int Time::getH()const
{
	return h;
}
unsigned int Time::getM()const
{
	return m;
}
unsigned int Time::getS()const
{
	return s;
}
```

TIme.cpp文件中将对应的四个函数加上了返回值（*this）

```cpp
//main.cpp
#include<iostream>
#include"Time.h"
using namespace std;
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
```

第7行首先声明了一个对象t，没传参，构造函数默认实参0，0，0，所以打印值为0.

第9行的代码是从左往右执行的,首先调用了t的置时函数setH，传入参数13，函数体内将13传给时，然后！返回一个this解引用（this解引用为对象本身），实际上就是返回了一个对象。然后返回到这个对象又调用了置分函数setM……后面同理，到了最后setS返回的值没有使用，也没有关系，不会报错。然后打印值

第16行也是同理，返回的对象调用时间打印函数

```cpp
/********************终端**********************/
初始化声明对象打印：当前时间为：00:00:00-AM
当前时间为：00:00:00
串联三个函数，分别置时分秒，打印：当前时间为：01:14:15-PM
当前时间为：13:14:15
串联两个函数，一次性置时间并串联打印函数：当前时间为：02:54:34-PM
当前时间为：14:54:34
```

## 11.static类成员

对于每个类的对象那个来说，都有一份各自的成员副本，而static的作用就是将类成员设置为类创建的对象**共享的成员**，所有类成员只使用一份数据。就像全局变量一样，但他只在类的作用域起作用

**类的静态成员**

### 11.1 静态数据成员的初始化

静态数据成员必须被精确的初始化一次。C++11之前static const的int和enum类型可以在声明时初始化，而其他数据成员必须在全局作用域，也就是类定义之外初始化，初始化时必须包含类名和二元作用域分辨运算符。C++11中可以在类内初始化

类类型的static数据成员（例如Time类：static Time t;），也就是static成员对象，如果这个类又默认构造函数，则不需要初始化，因为他们的默认构造函数会被调用

静态成员函数在头文件中声明为静态，在cpp文件中不需要再声明static

### 11.2 静态数据成员的访问

类的private和protected的静态成员通常通过类的成员函数或者友元访问。如果类没有实例化任何对象，没有任何对象存在，但static的public数据成员仍然存在，可以访问，通过类名加二元作用域分辨运算符加数据成员名来访问（例如Time类有一个static数据成员temp,该类没有实例化任何对象，访问时：`Time::temp;`），private和protected不可以访问，若未实例化对象只能通过成员函数访问。

```cpp
//staticmember.h
#pragma once
#ifndef _STATICMEMBER_H
#define _STATICMEMBER_H
#include<string>
class stMem
{
public:
	stMem(const std::string );
	std::string getName() const;
	~stMem();
	static size_t getct();
private:
	std::string name;
	static size_t count;
};

#endif
```

两个数据成员一个输入姓名，另一个静态数据成员统计创建对象的个数

构造函数接受一个string的值，这个值要初始化数据成员name

getName函数返回name的值

getct函数返回count的值

```cpp
//staticmember.cpp
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
```

首先在全局作用域内把静态数据成员初始化为0

构造函数中将接收到的值赋值给name，如果构造函数被调用说明创建了一个对象，那么就让count自增

析构函数如果被调用说明对象被销毁，count就自减

```cpp
//main.h
#include<iostream>
#include"staticmember.h"
using namespace std;
int main()
{
	cout << "未创建对象时，静态成员值：" << stMem::getct() << endl;
	stMem s("小红");
	cout << "主函数中创建一个对象"
		<<s.getName()<<"  " << "\t静态成员值：" << stMem::getct() << endl;
	{
		stMem s1("小绿");
		stMem s2("小蓝");
		cout << "主函数中构建一个块作用域中，创建两个对象:"<<s1.getName()
			<<"  "<<s2.getName() << "\t静态成员值：" << stMem::getct() << endl;
	}
	cout << "出块作用域时，静态成员值：" << stMem::getct() << endl;
}
```

```cpp
/********************终端**********************/
未创建对象时，静态成员值：0
主函数中创建一个对象小红        静态成员值：1
主函数中构建一个块作用域中，创建两个对象:小绿  小蓝   静态成员值：3
出块作用域时，静态成员值：1
```

首先直接查看count的值，因为没有创建对象，为0

然后创建了一个s对象，再查看查看count的值，为1

然后在一个花括号中创建了两个对象，这两个对象的声明周期就在这个块作用域内，所以此时查看count的值为3，等出块作用域在查看count的值为1

可以将声明直接写在构造和析构函数中，可以更直观的查看

# 九、运算符重载：string类

## 0.引言

将C++中的运算符和类对象结合在一起称为运算符重载。”<<“和">>"就是运算符重载的一个例子他们即是流操作运算符，又是位移运算符。C++允许程序员重载大部分由雷使用的运算符。

## 1. string类的重载运算符

下面例程展示了很多string的重载运算符和一些成员函数。empty、substr、at。

empty判断一个string是否为空，substr返回现有string的一部分，st返回指定的string下标处的字符。

```cpp
#include<iostream>
#include<string>
using namespace std;
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
	cout << "接下来给s1加个字符串\"!!!\",s1+\"!!!\",s1=" << s1<<endl;
	cout << "接下来从s1的第5个字符，取5个,substr(5,5)=\"" << s1.substr(5, 5) << "\""<<endl;
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
		s3.at(30)='G';
	}
	catch(out_of_range &ex)
	{
		cerr << "错误，无法访问s3.at(30):" << ex.what()<<endl;
	}
	getchar();
}
/*****************************************************
声明三个string对象；
s1="hello"      s2="world"      s3=""
开始判断↓：
s1==s2真的假的？        假的
s1!=s2真的假的？        真的
s1>=s2真的假的？        假的
s1<=s2真的假的？        真的
s1>s2真的假的？         假的
s1<s2真的假的？         真的
s3为空真的假的？        真的
好s3为空，真的。那我们把s1的值赋给s3
现在s1="hello"  s3="hello"
接下来s1+=s2，结果为：
s1="helloworld" s2="world"
接下来给s1加个字符串"!!!",s1+"!!!",s1=helloworld!!!
接下来从s1的第5个字符，取5个,substr(5,5)="world"
接下来把substr参数换成一个数，substr(10)="!!!"
新声明一个string对象s4，将s1作为初始化值传进去：
s4="helloworld!!!"
接下来把s4看成内置数组来处理，把大写H赋值给s4[0]
s4="Helloworld!!!"
接下来使用at函数，s2.at(0)='w'
再使用at函数，把大写W赋值给s2.at(0)，查看s2="World"
使用try访问s3下标为30的字符
尝试执行语句s3.at(30)='G';
错误，无法访问s3.at(30):invalid string position
```

string类的成员函数empty判断一个string对象是否为空，返回一个bool类型的值

at函数访问对象指定下标的字符，返回值为该字符。可以使用at函数对这个字符读写

substr函数返回的是从指定下标元素开始往后的所有字符，可以指定第二个参数，第二个参数为往后的字符个数

string中的重载运算符，比较运算符是进行字符长度的比较，算数运算符是将两个string对象拼接

## 2.重载运算符

### 2.1 基础知识

重载运算符可以通过简洁的符号来操作对象，同样可以自定义重载运算符。需要定义重载运算符函数来描述需要实现的功能。

通过关键字**operator加需要重载的运算符**，如果以**成员函数**的方式重载运算符，那么这个成员函数必须是非static的，因为他们由类的对象调用，并作用在对象上。要在类的对象上使用重载运算符，必须定义该类的运算符重载函数。

绝大多数的类可以用赋值运算符对其数据成员进行逐各成员赋值的操作。对于具有指针成员的类，逐个成员赋值是非常危险的，后续即将介绍，因此显式的为这种类重载赋值运算符

如果重载的运算符是成员函数运算时，运算符左边必须是类的对象。非成员函数无所谓，并且可以通过交换形参来决定运算符左右两边的值，但如果要操作私有成员，需要声明为友元

不可重载的运算符：

` ::		.		*		? :			sizeof`

格式如下：
`返回值类型 类名::operator运算符(参数列表){函数体}`

### 2.2 重载二元运算符

#### 2.2.1 作为成员函数的二元重载运算符

使用<来比较自己定义的String类的两个对象y和z。重载为带有一个参数的非static成员函数，y<z被处理为y.operator<(z)，意思就是调用对象y的成员函数`operator<`,传入的参数为z。如果是成员函数，调用它的对象一定在左侧。

```cpp
class String
{
public:
    bool operator<(const String& )const;
}
```

调用完后返回一个bool类型的值，因为实际的大于小于号进行比较后只有两个值，要么为真，要么为假。传入的和返回的值必须声明为cosnt类型，不可以被改变，声明为一个常量

#### 2.2.2 作为非成员函数的二元重载运算符

函数必须有两个参数，其中一个必须为与重载运算符有关系的类对象或者类对象的引用。y<z就被理解为operator<(y,z)，函数声明：`bool operator<(const String& ,const String& )const;`。非成员函数可以自定义重载运算符两边谁在左谁在右

### 2.3 重载二元流插入和流提取运算符

把PhoneNumber对象以(+86)151 5555 8888的形式输入输出

```cpp
//PN.h
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
```

将流插入和流提取运算符重载函数声明为友元，因为使用时格式为`cout+运算符+对象`，如果只传一个参数，那么就得是对象调用成员函数，格式为`对象+运算符+cout`。返回值是ostream和istream，这是cout和cin的类型。传入的第一个参数就是cout和cin，第二个是对象。

```cpp
//PN.cpp
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
```

```cpp
//main.cpp
int main()
{
	PhoneNumber nb;
	cout << "请输入电话号码格式为(+86) 123 4567 8910：";
	cin >> nb;
	cout<<"电话号码为：" << nb;
}
```

`cin>>nb`————》`operator>>(cout,nb){……}`，因为他的返回值还是一个cin,所以如果串联的话，`cin>>nb>>nb2;`,`cin>>nb`执行完之后返回cin，继续执行`cin>>nb2`

```cpp
/***************************************
请输入电话号码格式为(+86) 123 4567 8910：(+86) 195 2824 5674
电话号码为：(+86) 195 2824 5674
```

输入时，输入`(+`被忽略，`86`被存放到number2，`) ` 被忽略，`195`被存放到number3,` ` 被忽略，`2824`被存放到number4_1,` ` 被忽略，`5674`被存放到number4_2。

输出时，先打印了`(+`，然后number2的值，然后……

### 2.4 重载一元运算符

一元运算符可以重载为不带参数的成员函数或带一个参数的非成员函数，参数必须是类的对象或者对象引用

#### 2.4.1 作为成员函数的一元重载运算符

```cpp
class String
{
public:
    bool operator!()const;
};
```

当使用`!s`时，被理解为`s.operator()`

#### 2.4.2 作为非成员函数的一元重载运算符

`bool operator!(Const String& );`

当使用`!s`时，被理解为`operator(s)`。

### 2.5 重载一元前置后置运算符：++和--

假设把Date类对象d1的天数加一

成员函数++d1被理解成d1.operator++()，函数原型Date &operator++()；非成员函数被理解为operator++(d1),函数原型为Date &operator(Date &)。

成员函数d1++被理解为d1.operator++(0),函数原型Date& operator++(int)；非成员函数被理解为operator++(d1,0),函数原型为Date& operator++(Date& ,int)

0是编译器用来区分前置和后置运算的

### 2.6 实例研究：Date类

【改进之前的Date类，重载++、+=运算符，实现对日期天数的增加并打印，需要考虑闰年】

```cpp
//date.h
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
```

新的Date类，首先声明了一个友元函数为重载流输出函数，因为输出格式要为cout<<xxx，所以必须传两个值，作为成员函数只能传一个，所以作为非成员函数。

构造函数默认实参为2000，1，1

设置日期的函数setDate()

重载前置++运算符，没有参数，返回的值是在重载前置++函数中执行完毕后的对象本身，所以是Date类的引用

重载后置++运算符，有一个参数（该参数没有实际意义，仅仅是编译器用来区分前置后置），返回的值是对象刚进去是的值，不参与运算，对象自身的值改变但不返回，所以返回的值不能作为引用

重载+=运算符，有一个参数，实现的是将日期加并赋值指定的天数（参数），返回的值是在重载+=函数中执行完毕加了天数的对象，需要将这个值作为对象自身，所以是Date类的引用

**因为引用就相当于，还是对象自身进去，发生了什么改变了什么，出来就是对象自己经过改变的值。如果按值传递返回值，那么对象本身的值不会被改变，仅在函数体内的哪个变量改变。**

判断闰年的函数runNian，每个对象都要进行判断，声明为静态，返回一个bool类型的值，判断闰年的真假值

判断是否为月内最后一天的函数lastday，返回也是bool类型的值

day函数用来增加天数

```cpp
//date.cpp
#include"date.h"
using namespace std;
const array<unsigned int ,13> Date::arr={0,31,28,31,30,31,30,31,31,30,31,30,31};
ostream& operator<<(ostream& x, const Date& yy)
{
	static const array<string,13> const yue=
	{"零月","一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
	x << yy.y << "年" << yue[yy.m]  << yy.d << "日";
	return x;
}
Date::Date(int a,int b,int c)
{
	setDate(a, b, c);
}
void Date::setDate(int a, int b, int c)
{
	if (a > 0 && a <= 2025)
		y = a;
	else
		throw invalid_argument("年输入错误\n");
	if (b >= 0 && b <= 12)
		m = b;
	else
		throw invalid_argument("月输入有误\n");
	if (c <= arr[b] && c >= 1 || 2 == m && runNian(a) && c <= 29 && c >= 1)
		d = c;
	else
		throw invalid_argument("日输入有误\n");
}
Date& Date::operator++()
{
	day();
	return *this;
}
Date Date::operator++(int)
{
	Date temp = (*this);
	day();
	return temp;
}
Date& Date::operator+=(unsigned int a)
{
	for (size_t i = 0; i < a; i++)
	{
		day();
	}
	return *this;
}
bool Date::runNian(unsigned int a)
{
	if (0 == (a % 400) || 0 != (a % 100) && (0 == a % 4))
		return true;
	else
		return false;
}
bool Date::lastday(int a)const
{
	if (2 == m && runNian(y))
		return (29 == a);
	else
		return (arr[m] == a);
}
void Date::day()
{
	if (!lastday(d))
		d++;
	else
	{
		if ( m<12)
		{
			++m;
			d = 1;
		}
		else
		{
			++y;
			m = 1;
			d = 1;
		}
	}
}
```

首先初始化定义的arr对象，将值赋为12个月份。

然后是operator<<函数，传入的第一个参数为ostream类型的cout，第二个为打印的对象，当代码中执行cout<<对象时，调用此函数`operator<<(cout,date1)`,通过cout的别名形参x的打印对象的数据成员

构造函数体中调用setDate函数来对数据成员赋值

setDate函数返回值为空，对传入的形参判断，对年月直接判断。判断日是先跟对应月的天数最大值进行判断（这里将2月28日之前也判断进去了），或者如果是二月，对二月单独判断，如果是二月并且是闰年，那么传入的这个值不超过29就是合理的。将合理的值赋给数据成员。不合理抛出异常

先来看runNian函数，判断闰年，函数接受一个参数，参数为年份，对年份判断，如果是闰年返回true，如果不是闰年返回false。

再看lastday，判断是否为月的最后一天。函数接受一个实参，如果是二月并且为闰年，那么29是他的最后一天，传入的值如果为29，那么29==a的表达式值为真，说名是二月的最后一天。不是二月的话，判断传入的值和每个月最大值进行比较，如果是最大值，说明判断的表达式为真，那么就返回true。反之如果上述表达式的值不满足，那么就返回假。

day函数作用是将天数加1，首先进来通过if语句，调用lastday函数判断是否为最后一天，当返回值为假，说明不是最后一天，给这个值取反，那么if语句条件就为真，执行if语句，将天数加一。否则就是最后一天，再进行判断，如果月份不是最后一个月，也就是月份为1~11月，那么就将月份更新为下一个月，原来的月份自增，然后重置天数为1。如果是最后一个月，那么就将年自增1，然后将月和日都重置为1

operator++()前置自增函数，将日期先加一再使用，返回值（表达式的值）为加后的日期本身。函数进来后就调用day()先将日期加1，然后返回this指针的解引用，表示返回调用operator++()函数的对象的值。

operator++(int)后置自增函数，先使用当前值，然后再自增。所以这个函数的返回值就是调用函数的对象原来的值。所以进来之后先把对象的值赋值给一个变量，返回这个变量的值，中间再进行自增

operator+=函数，对调用他的对象加上实参的天数再赋值给他自身，接收一个实参为要增加的天数。函数体内将这个天数作为循环次数，循环体为day函数，每次执行day增加一天，最后返回调用它的对象的值，实现赋值

```cpp
//main.cpp
#include<iostream>
#include"date.h"
using namespace std;
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
		cerr << "警告：" << e.what() << endl ;
	}
}
/*******************************************************
打印date1++的值为：2000年一月1日
date1 += 3,date1的值为：2000年一月5日
date2赋值为2025年2月28日,打印++date2：2025年三月1日
date3赋值为2008年2月28日
date3加并赋值1,打印date3的值为：2008年二月29日
```

执行代码cout<< date1++，首先调用后置++函数，date1.operator++(0),然后返回data1的值再对date1的值加1。返回的是date1，代码变为cout<<date1,然后调用重载流输出函数，operator<<(cout,date1),第一个参数为重载运算符左边，第二个为右边。剩下代码同理

## 3.动态内存

### 3.1 动态内存管理

通过内存分配和释放可以控制对象，或者自定义类型的数组。通过new和delete运算符来实现。

#### 3.1.1 new运算符

new运算符为对象分配恰好容纳他所需要的内存空间，对象被创建再堆上（这是一个专门存储动态分配对象内存区域，也叫自由存储区）。

new运算符返回一个指针，指针指向被分配在堆上的这个对象，所以使用完new运算符将他的返回值存储在一个对象的类型的指针中。

给对象（不带参数，默认构造）分配空间：`指针 = new 类型名;`

给对象（带参数）分配空间：`指针 = new 类型名(参数列表);`

给数组（不带参数，默认构造）分配空间：`指针 = new 类型名[元素个数];`

给数组（带参数）分配空间：`指针 = new 类型名[元素个数]{{},{}……};`

 `Time *p = new Time`，含义：首先调用对象的默认构造函数，在堆上给Time对象分配一块存储空间，指针p指向对象TIme，通过解引用p来访问对象成员。

`Time *p = new Time{参数}`

`Time *p= new Time(参数)`

#### 3.1.2 delete运算符

delete运算符后面接指针变量，表示释放所创建的内存空间 `delete p`，含义首先调用p所指向的对象的析构函数，收回对象的内存空间，然后将内存返还给堆。返还之后就可以再次使用这块内存空间分配给其他对象

#### 3.1.3 new[]

new还可以给内置数组分配空间， `int* p = new int[10]()`,表示在堆上分配了一块内存存放十个int类型的数组元素，p指向第一个元素，后面括号用于初始化元素，基本数值类型被置为0，bool被指为false,指针被置为nullptr

C++11中可以使用初始化列表器来初始化元素 `int* p = new int[10]{元素列表}`

#### 3.1.4 delete[]

`delede [] p`释放内存

### 3.2 实例研究：Array类

```cpp
//Array.h
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
```

数据成员size为数组大小，p为对象管理的动态分配基于指针数组的首地址指针

首先声明了两个友元重载运算符函数（流输出，流输入），前一个参数为cout(cin)，后一个为要输出的Array对象

声明默认构造函数，参数为4

一个拷贝构造函数，参数为一个Array对象的引用

getSize函数获取数组大小，函数内未对数据成员改变，将函数声明为常量成员函数

重载赋值运算符。赋值表达式返回的值为等号左边的值，所以重载运算符返回值为Array类引用，传入的参数就是等号右边的值，所以也是Array类型的引用，并且这个值不能修改

重载不等和相等运算符，返回值为bool，传入的参数为运算符右边要进行比较的Array对象，并且不能改变，声明为const，函数体内未对数据成员修改，声明为const常量成员函数

重载[]运算符，如果为左值，则要对数据成员进行读写，返回值为数组元素的值，并且要为引用，因为要返回的是直接读的数组元素自身，做别名返回，传入的参数为改后的值整型

如果[]为右值那么就只对元素值进行读取，不写入，所以将函数声明为常量成员函数，返回值为函数体内计算完后普通的一个int值

```cpp
//Array.cpp
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
```

重载的operator<<通过循环来输出元素的值，四个一换行，循环条件为数组大小

operator>>也是同理，逐个输入元素的值，返回流输入指令

默认构造函数将形参作为数组大小进行判断后传给size，函数体内将所有数组元素默认赋值为0

拷贝构造函数，将接收到的形参数组的大小，赋值给调用拷贝构造函数的对象数组大小，并为新的数组申请一块大小为数组大小的地址空间，然后将形参数组的值赋给新数组

operator=函数体内首先判断赋值运算符右边的对象是不是自己（防止给自己赋值，危险！），然后再判断大小是否相等，相等的话跳过该if语句，不相等的话，首先把赋值运算符左边的对象（当前要被赋值的，或者说是调用这个重载运算符的对象）内存释放掉，然后把新数组的大小赋值给给当前要被赋值的数组大小，再用这个大小，申请一块新的内存空间。然后通过for循环逐个元素赋值

operator!=函数，bool类型本来就是常量，所以返回值不需要声明const，因为仅进行判断和比较所以将函数声明为常量成员函数const，传入的对象进行比较，也不进行改变，所以也声明为常量，因为要访问变量自身，所以声明为引用。函数体内首先判断调用该函数的对象和传进来被比较的对象，数组大小是否不同，若不同直接返回ture，否则相同的话就一一进行比较是否不同。当全部都比较完了那就说明都相同，返回false。operator==函数同理。

operator[]函数有两个，但他们一个要作为左值被赋值，一个要作为右值赋值给其他。无论左值还是右值，方括号代表元素下标，所以返回值就是指定下标的元素，为int类型。右值作为常量，不能被赋值，只能作为一个int类型，返回值不能包含引用。仅通过返回类型无法重载，所以将右值的方括号重载运算符声明为常量成员函数

getSize函数返回数组大小，没有改变私有数据成员，声明为常量成员函数

析构函数体内释放数组空间

```cpp
//main.cpp
#include<iostream>
#include"Array.h"
#include<stdexcept>
using namespace std;
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
	cout << "输出a1的元素:"<<endl<<a1;
	cout << "输出a2的元素:\n" << a2;
	cout << "判断a1和a2元素是否相等\n";
	if(a1 != a2) 
		cout << "不相等\n";
	else
		cout<<"相等\n";
	Array a3(a1);
	cout << "再声明一个数组a3，把a1作为参数传入\n"
		<<"a3大小为:"<< a3.getSize()<<"\n打印a3为:\n"
		<< a3;
	a1 = a2;
	cout << "把a2赋值给a1，输出a1为：\n" << a1
		<<"a2为：\n"<<a2;
	cout << "再次判断a1和a2元素是否相等\n";
	if (a1 == a2)
		cout << "相等\n";
	else
		cout<<"不相等\n";
	cout << "输出a1的第3个元素：" << a1[2] << endl;
	cout << "把这个元素改为10086，点击回车继续";
	a1[2] = 10086;
	getchar();
	cout << "输出a1的元素:" << endl << a1;
	cout << "点击回车程序继续"<<endl;
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
```

主函数中声明了一个Array对象a1，并传参2，调用构造函数，判断2大于0，将值赋给数据成员size，然后再申请一块大小为2的内存空间让数据成员p指向这块内存。在构造函数体内通过指针p对每一个元素赋值

cout<<a1，a1对象调用重载的流输出运算符，cout作为第一个参数传入，a1作为第二个参数传入，在循环遍历输出数组每个元素，最后将cout返回

然后创建了一个Array对象a2，调用默认构造函数，初始化为4个元素，然后a1调用cin函数，输入a1各个元素值后返回cin，c2再调用cin，输出c2各个元素的值

后续是比较函数和赋值函数的验证，省略

当自己的类或者自己的重载运算符不想被重载，可以声明为私有成员private。C++11中，可以通过delete直接显式的删除，防止类被构造。直接在构造函数声明的语句前加赋值运算符和delete，eg：

```cpp
Array(const Array&) = delete;
Array& operator=(const Array&) = delete;
```

## 4.类型转化

通过cast强制类型转换运算符在基本类型之间进行强制转换

用于将某个类的对象转换成另一个类的对象，或者其他类型

`Myclass::operator char* () const;`该函数原型（重载）表示将Myclass的对象转换成一个`char*`对象，声明为常量成员函数，因为他不修改原始对象（只读）,重载的强制类型转换符不指定返回类型。当编译器遇到`static_cast<char*>(s)`,他表示类的对象s调用了重载的强制类型转换函数`s.operator char*()`把s转换为`char*`类型

`Myclass::operator int() const;` 重载了强制类型转换符，将Myclass类型的对象转换为int型

`Myclass::operator Otherclass() const;` 将Myclass类型的对象转换为Otherclass的对象

## 5.explicit

所有的单参数构造函数都可看做转换构造函数（将值赋给对象时，将隐式的调用构造函数，将赋值给对象的值作为参数传给构造函数）

防止被隐式转换导致逻辑和预期出现错误，将单参数的构造函数声明为explicit

```cpp
//当声明构造函数如下形式
class Myclass
{
public:    
    Myclass(int i);
    /*....*/
}
Myclass mc(100);//可以
Myclass mc=100;//可以
/*********************************/
//当声明构造函数如下形式
class Myclass
{
public:    
    explicit Myclass(int i);
    /*....*/
}
Myclass mc(100);//可以
Myclass mc=100;//不可以，必须显式调用构造函数
```

## 6.重载函数调用运算符()

函数可以接收任意数量的逗号分隔参数，再String类中可以通过重载该运算符来选择一个String的子类（从已有的String对象中取出来一个包含在已有对象中的String对象），用两个参数来作为要取的位置和长度

`String String::opeartor()(size_t a,size_t b) const`

因为未对原有的对象进行修改，所以声明为cosnt

```cpp
#include<iostream>
#include"String"//自定义的类
using namespace std;
int main()
{
    String s1;
    //假设s1是包含字符串“hello”的对象
    s1(2,3);//调用函数为s1.operator()(2,3),返回字符串“ell”
}
```

# 十、面向对象编程：继承

## 0.引言

通过继承可以吸收现有类的各种性能的基础上，再加以定制/增强来创建新的类，软件复用节省开发时间。新类继承现有类的成员，此时现有类称为**基类**，新类称为**派生类**（Java和C#中称为超类和子类）

有三种继承：public、private、protecteed。public继承中，**每个派生类的对象同时也是基类的对象**，反之不是。

派生类与基类的关系是：is a --------------------派生类  是  基类

好处：**提高代码可重用性**

## 1.基类和派生类

### 1.1 实例理解

​										基类					派生类

-------

​										学生					本科生|研究生 							

​										形状					圆形|三角形

​										贷款					房贷|车贷

基类更加通用，派生类更加具体。当类投入到继承关系中就不只是普通的类，而作为基类、或者是派生类、或者二者兼具

语法：单继承	 `class 派生类名: 继承方式 基类名 {}`

​			多继承	`class 派生类名: 继承方式 基类名,继承方式 基类名…… {}`

**继承方式**

​	每种继承方式**基类中的所有成员都被继承到派生类中**

- public继承：基类中**public成员可在类中或通过对象直接访问**，**protected成员仅能在类中直接访问**，**private成员不可直接访问**，但是可以**通过继承来的方法访问**，如果没有方法访问基类的private成员，那么派生类中继承基类的private成员就在派生类中就几乎没有意义了，因为永远访问不到。

  public继承后，派生类中的成员

  > public-----基类的全部public成员(派生类中**可直接访问**，派生类对象**可直接访问**)
  >
  > protected----基类的全部protected成员(派生类中**可直接访问**，派生类对象**不可直接访问**)
  >
  > private----基类的全部private成员(派生类中**不可直接访问**，可通过继承来的方法**间接访问**，派生类对象**不可直接访问**)

- protected继承：基类中的**public和protected成员在派生类中可以直接访问**(在派生类中的权限为protected)，类的对象都不可以直接访问。

  protected继承后，派生类中的成员

  > public-----基类的全部public成员(派生类中**可直接访问**，派生类对象**不可直接访问**)
  >
  > protected----基类的全部protected成员(派生类中**可直接访问**，派生类对象**不可直接访问**)
  >
  > private----基类的全部private成员(派生类中**不可直接访问**，派生类对象**不可直接访问**，可通过继承来的方法**间接访问**)

- private继承：基类中的**public和protected成员在派生类中可以直接访问**(在派生类中的权限为private)，类的对象都不可以直接访问。

  private继承，派生类中的成员

  > public-----基类的全部public成员(派生类中**可直接访问**，派生类对象**不可直接访问**)
  >
  > protected----基类的全部protected成员(派生类中**可直接访问**，派生类对象**不可直接访问**)
  >
  > private----基类的全部private成员(派生类中**不可直接访问**，派生类对象**不可直接访问**，可通过继承来的方法**间接访问**)

public继承例子

```cpp
//基类
class 形状
{
public:
    计算面积的方法();
protected:
    计算重量;
private:
    长;
    宽;
}
//派生类
class 圆形:public 形状
{
    可直接调用 计算面积的方法();//权限public  外部可访问
    可直接访问 计算重量;//权限protected  外部不可访问
    不可访问长宽//无权限访问
}
int main()
{
    圆形 圆形1;
    圆形1.计算面积的方法;//可以
    //圆形1.计算重量;//不可以
    //圆形1.长;//更不可以了
}
```

protected继承例子

```cpp
//基类
class 形状
{
public:
    计算面积的方法();
protected:
    计算重量;
private:
    长;
    宽;
}
//派生类
class 圆形:protected 形状
{
    可直接调用 计算面积的方法();//权限protected  外部不可访问
    可直接访问 计算重量;//权限protected  外部不可访问
    不可访问长宽//无权限访问
}
int main()
{
    圆形 圆形1;
    //圆形1.计算面积的方法;//不可以
    //圆形1.计算重量;//不可以
    //圆形1.长;//更不可以了
}
```

private继承例子

```cpp
//基类
class 形状
{
public:
    计算面积的方法();
protected:
    计算重量;
private:
    长;
    宽;
}
//派生类
class 圆形:private 形状
{
    可直接调用 计算面积的方法();//权限private  外部不可访问
    可直接访问 计算重量;//权限private  外部不可访问
    不可访问长宽//无权限访问
}
int main()
{
    圆形 圆形1;
    //圆形1.计算面积的方法;//不可以
    //圆形1.计算重量;//不可以
    //圆形1.长;//更不可以了
}
```

所以什么叫继承？

```cpp
//基类
class 形状
{
public:
    计算面积的方法();
protected:
    计算重量;
private:
    长;
    宽;
}
```

形状有圆形，长方形，三角形……
在这个基类中，成员仅有长宽，但是如果还有一个正方形，不仅需要长宽，还需要对角线这个参数

那么可以通过继承形状类，然后多加一个对角线就好了，不用重新写一个正方形类

不使用继承：

```cpp
//形状类
class XinZ
{
public:
    XinZ(int = 0,int = 0);//构造函数
    void prt_Chang()const;//打印形状的长
    void prt_Kuan()const;//打印形状的宽
private:
    int Chang;
    int Kuan;
};

/*
* 构造函数初始化长宽
    @_c:传入长度
    @_k:传入宽度
*/
XinZ::XinZ(int _c,int _k)
    :Chang(_c),
    Kuan(_k)
{
    cout << "形状对象已构造" << endl;
}

void XinZ::prt_Chang()const
{
    cout << Chang << endl;
}

void XinZ::prt_Kuan()const
{
    cout << Kuan << endl;
}


//正方形类
class Zfx
{
public:
    Zfx(int = 0, int = 0,int = 0);//构造函数
    int get_Chang()const;//打印正方形的长
    int get_Kuan()const;//打印正方形的宽
    int get_Duijiao()const;//打印正方形的对角线
private:
    int Chang;
    int Kuan;
    int Duijiao;
};

/*
* 构造函数初始化长宽
    @_c:传入长度
    @_k:传入宽度
    @_d
*/
Zfx::Zfx(int _c, int _k,int _d)
    :Chang(_c),
    Kuan(_k),
    Duijiao(_d)
{
    cout << "形状对象已构造" << endl;
}

int XinZ::get_Chang()const
{
    return Chang ;
}

int XinZ::get_Kuan()const
{
    return Kuan ;
}

int Zfx::get_Duijiao()const
{
    return Duijiao;
}
```

需要写两个类，但是大部分成员是相同的，浪费代码量，所以使用继承

使用继承：

```cpp

//正方形类
class Zfx:public XinZ
{
public:
    Zfx(int = 0);//构造函数重写
    int get_Duijiao()const;//获取正方形的对角线
private:
    int Duijiao;
};

Zfx::Zfx(int _d)
    : Duijiao(_d)
{
    cout << "形状对象已构造" << endl;
}

int Zfx::get_Duijiao()const
{
    return Duijiao;
}
```

只需要将新加的成员加进去就好了，原有的成员函数可以直接访问

### 1.2 佣金雇员Cmsepl类

佣金雇员类，数据成员为姓名(name)、银行卡号（cardNum）、销售总额（grossSell）、提成（commission）

```cpp
//Cmsepl.h
#pragma once
#ifndef _CMSEPL_H
#define _CMSEPL_H
#include<string>
class Cmsepl
{
public:
    //构造函数传入参数
	Cmsepl(const std::string&, const std::string&, double=0.0,double=0.0);
	void setName(const std::string&);
	std::string getName()const;

	void setcardNum(const std::string&);
	std::string getcardNum()const;

	void setgrossSell(double);
	double getgrossSell()const;

	void setCom(double);
	double getCom()const;

	double income()const;
	void prt()const;
private:
	std::string name;
	std::string cardNum;
	double grossSell;
	double commission;
};

#endif
```

```cpp
//Cmsepl.cpp
#include<iostream>
#include<string>
#include"Cmsepl.h"
using namespace std;
Cmsepl::Cmsepl(const std::string& nm, const std::string& cn,
	double gs, double cs)
{
	setName(nm);
	setcardNum(cn);
	setgrossSell(gs);
	setCom(cs);
}
void Cmsepl::setName(const string& nm)
{
	if (nm.size() > 0 && nm.size() <= 6)
		name = nm;
	else
		throw invalid_argument("姓名长度有误");
}
string Cmsepl::getName() const
{
	return name;
}
void Cmsepl::setcardNum(const string& cn)
{
	if (cn.size() > 0 && cn.size() <= 15)
		cardNum = cn;
	else
		throw invalid_argument("卡号长度有误");
}
string Cmsepl::getcardNum() const
{
	return cardNum;
}
void Cmsepl::setgrossSell(const double& gs)
{
	if (gs>0.0)
		grossSell = gs;
	else
		throw invalid_argument("销售总额有误");
}
double Cmsepl::getgrossSell() const
{
	return grossSell;
}
void Cmsepl::setCom(const double& cs)
{
		commission = cs;
}
double Cmsepl::getCom() const
{
	return commission;
}
double Cmsepl::income() const
{
	return commission * grossSell;
}
void Cmsepl::prt()const
{
	cout << "姓名："<<name
		<<"\n卡号："<<cardNum
		<<"\n销售总额："<<grossSell
		<<"\n提成比例："<<commission
		<<endl;
}
```

```cpp
//main.cpp
#include<iostream>
#include"Cmsepl.h"
using namespace std;
int main()
{
	Cmsepl ep("李慧","6859 2569 145",3000,9.9);
	ep.prt();
	cout << "提成收入" << ep.income() << endl;
	cout << "\n本月总收入" << ep.income()+ep.getgrossSell() << endl;
	cout << "替你接了" << endl;
	getchar();
	return 0;
}
```

### 1.3 不使用继承的BPcmsepl类

比前一个类多了底薪

```cpp
//BPcmsepl.h
#pragma once
#ifndef _BPCMSEPL_H
#define _BPCMSEPL_H
#include<string>
class BPcmsepl
{
public:
	explicit BPcmsepl(const std::string&, const std::string&, 
		double = 0.0,double = 0.0, double = 0.0);
	void setName(const std::string&);
	std::string getName()const;

	void setcardNum(const std::string&);
	std::string getcardNum()const;

	void setgrossSell(double);
	double getgrossSell()const;

	void setCom(double);
	double getCom()const;

	void setBasesalary(double);
	double getBasesalary()const;

	double income()const;
	void prt()const;
private:
	std::string name;
	std::string cardNum;
	double grossSell;
	double commission;
	double baseSalary;
};

#endif
```

```cpp
//BPcmsepl.cpp
#include<iostream>
#include<string>
#include"BPcmsepl.h"
using namespace std;
BPcmsepl::BPcmsepl(const std::string& nm, const std::string& cn,
	double gs, double cs,double bs)
{
	setName(nm);
	setcardNum(cn);
	setgrossSell(gs);
	setCom(cs);
	setBasesalary(bs);
}
void BPcmsepl::setName(const string& nm)
{
	if (nm.size() > 0 && nm.size() <= 6)
		name = nm;
	else
		throw invalid_argument("姓名长度有误");
}
string BPcmsepl::getName() const
{
	return name;
}
void BPcmsepl::setcardNum(const string& cn)
{
	if (cn.size() > 0 && cn.size() <= 15)
		cardNum = cn;
	else
		throw invalid_argument("卡号长度有误");
}
string BPcmsepl::getcardNum() const
{
	return cardNum;
}
void BPcmsepl::setgrossSell(double gs)
{
	if (gs > 0.0)
		grossSell = gs;
	else
		throw invalid_argument("销售总额有误");
}
double BPcmsepl::getgrossSell() const
{
	return grossSell;
}
void BPcmsepl::setCom(double cs)
{
	if (cs > 0.0 && cs <= 1.0)
		commission = cs;
	else
		throw invalid_argument("提成比例有误");
}
double BPcmsepl::getCom() const
{
	return commission;
}
void BPcmsepl::setBasesalary(double bs)
{
	if (bs > 0)
		baseSalary = bs;
	else
		throw ("底薪有误");
}

double BPcmsepl::getBasesalary()const
{
	return baseSalary;
}


double BPcmsepl::income() const
{
	return commission * grossSell+baseSalary;
}
void BPcmsepl::prt()const
{
	cout << "姓名：" << name
		<< "\n卡号：" << cardNum
		<< "\n销售总额：" << grossSell
		<< "\n提成比例：" << commission
		<<"\n底薪："<<baseSalary
		<< endl;
}
```

```cpp
//main.cpp
#include<iostream>
#include"Cmsepl.h"
using namespace std;
int main()
{
	try
	{
		BPcmsepl bp("李慧", "6585 5245 6956", 1500, 0.3, 3000);
		bp.prt();
		cout <<"收入为：" << bp.income() << endl;
		return 0;
	}
	catch (invalid_argument& e)
	{
		cerr << "警告：" << e.what() << endl;
	}
}
```

### 1.4 创建C-BP继承层次结构

#### 1.4.1 C-BP的public继承

这两个类中大量代码都完全相同，采用复制粘贴的方法耗费时间而且维护时也比较麻烦。现在创建一个新的BPP类，他由Cmsepl继承而来

```cpp
//BPP.h
#pragma once
#ifndef _BPP_H
#define _BPP_H
#include"Cmsepl.h"
#include<string>
class BPP :public Cmsepl
{
public:
	BPP(const std::string&, const std::string&, 
		double=0.0, double = 0.0, double = 0.0);
	void setBasesalary(double);
	double getBasesalary()const;
	double income() const;
	void prt() const;
private:
	double baseSalary;
};
#endif
```

类BPP的对象同时也是Cmsepl的对象，在类定义是，声明为继承，在关键字class后，格式：

`class 派生类名 : 访问权限 基类名`

在该头文件中表示,BPP类继承于类Cmsepl,public表明了继承的类型。由public继承形成的派生类继承了基类中除构造函数的所有成员。构造函数和析构函数不能被继承，每个类都提供于自己特定的构造函数和析构函数。该派生类提供的public服务还包括成员函数`setBasesalary()`，`getBasesalary()`，`income()`，`prt()`，还有一个私有成员baseSalary存储底薪

```cpp
#include<iostream>
#include"BPP.h"
#include<string>
using namespace std;
BPP::BPP(const string& nm,const string& cn,
	double gs,double cs,double bs)
	:Cmsepl(nm,cn,gs,cs)
{
	setBasesalary(bs);
}
void BPP::setBasesalary(double bs)
{
	if (bs >= 0)
		baseSalary = bs;
	else
		throw invalid_argument ("底薪有误");
}

double BPP::getBasesalary()const
{
	return baseSalary;
}
double BPP::income() const
{
	return Cmsepl::getCom() * Cmsepl::getgrossSell() + getBasesalary();
	//return commission * grossSell + baseSalary;//error
}
void BPP::prt()const
{
	cout << "姓名：" << Cmsepl::getName()
		<< "\n卡号：" << Cmsepl::getcardNum()
		<< "\n销售总额：" << Cmsepl::getgrossSell()
		<< "\n提成比例：" << Cmsepl::getCom()
		<< "\n底薪：" << getBasesalary()
		<< endl;
	/*error
	cout << "姓名：" << name
		<< "\n卡号：" << cardNum
		<< "\n销售总额：" << grossSell
		<< "\n提成比例：" << commission
		<< "\n底薪：" << baseSalary
		<< endl;
	*/
}
```

派生类实现中构造函数要将值赋值给基类的成员时，引入了**基类初始化器**语法：在派生类的成员初始化器中，将要作为基类成员的数据，使用基类的构造函数传递给基类。派生类自己的成员函数可以在成员初始化器的花括号中初始化

编译器对任何没有显式包含构造函数的类，提供一个无参数的默认构造函数，但是该基类显式的有一个构造函数，所以编译器不会提供默认的构造函数。如果派生类的构造函数没有显式的调用基类的构造函数，那么C++将尝试隐式的调用基类的默认构造函数，但是该类的构造函数已经定义，所以会报错。

因为由public继承，所以派生类实现中不能直接访问基类的私有成员，但是可以通过getx函数来间接读取值

**派生类的头文件中需要包含基类的头文件**

```cpp
#include<iostream>
#include<string>
#include"BPP.h"
using namespace std;
int  main()
{
	try
	{
		BPP bp("李慧", "4558 5225 7848",3000,0.5,4000);
		bp.prt();
		cout << "收入：" << bp.income() << endl;
		getchar();
	}
	catch (invalid_argument& e)
	{
		cerr << "警告：" << e.what() << endl;
	}
}
```

#### 1.4.2 使用protested数据的C-BP的public继承

##### 优点

将基类中的数据成员访问权限改为protected后，派生类可以直接访问数据。基类中的protected成员不仅可以被基类的成员和友元访问，还可以被基类派生的任何类的成员和友元访问

##### 缺点

使用protected时，派生类可以直接对基类的数据进行读写，基类中的设置和获取（setx/getx）成员将不再起作用，因为派生类直接修改了数据的值。或者当基类中的数据成员改名字的时候，所有派生类访问该成员的位置都要修改

#### 1.4.3 使用protested数据的C-BP的public继承

继续将Cmsepl类拿过来，修改Cmsepl类，做如下修改，其他不变

```cpp
/*
//原
double Cmsepl::income() const
{
	return commission * grossSell;
}
void Cmsepl::prt()const
{
	cout << "姓名："<<name
		<<"\n卡号："<<cardNum
		<<"\n销售总额："<<grossSell
		<<"\n提成比例："<<commission
		<<endl;
}
*/

//现
double Cmsepl::income() const
{
	return getCom() * getgrossSell();
}
void Cmsepl::prt()const
{
	cout << "姓名："<<getName()
		<<"\n卡号："<<getcardNum()
		<<"\n销售总额："<<getgrossSell()
		<<"\n提成比例："<<getCom()
		<<endl;
}
```

将原来直接访问数据成员，改为getx函数来访问

继续将public派生的BPP类拿过来,进行分析

```cpp
//BPP.cpp
double BPP::income() const
{
	return Cmsepl::getCom() * Cmsepl::getgrossSell() + baseSalary;
	//return commission * grossSell + baseSalary;//error
}
void BPP::prt()const
{
	cout << "姓名：" << Cmsepl::getName()
		<< "\n卡号：" << Cmsepl::getcardNum()
		<< "\n销售总额：" << Cmsepl::getgrossSell()
		<< "\n提成比例：" << Cmsepl::getCom()
		<< "\n底薪：" << baseSalary
		<< endl;
	/*error
	cout << "姓名：" << name
		<< "\n卡号：" << cardNum
		<< "\n销售总额：" << grossSell
		<< "\n提成比例：" << commission
		<< "\n底薪：" << baseSalary
		<< endl;
	*/
}
```

无论是基类 还是派生，除了setx和getx函数，其他访问私有数据成员时，都是通过基类中的setx和getx。这样在需要修改数据成员名时，只需要修改setx和getx函数。这些修改只发生在基类中的setx和getx函数，其余函数和派生类无需任何改变

也可以在BPP中添加get和set函数来管理baseSalary成员，将操作的值与baseSalary隔离开，修改时也只需要修改get和set函数，不需要修改具体实现里面的内容

## 2.派生类

### 2.1 派生类中的构造函数

派生类构造函数在执行自己的任务前，要先显式（或者隐式）的调用基类的构造函数。如果该基类也是其他类的派生，那么该基类也要先调用他的基类的构造函数。在这个构造函数调用链中，调用的最后一个构造函数，是继承层次结构中最顶层的类，她的函数体是最先执行完毕的。最早调用派生类的构造函数最晚执行完毕

每个基类，构造函数初始化派生类对象继承该类的数据成员

### 2.2 派生类中的析构函数

销毁派生类对象时，其析构函数与构造函数调用顺序相反。派生类的析构函数先被调用，执行他的任务，然后是基类，顶层的析构函数最后被调用，之后，该对象就从内存中删除了。

**派生类不会继承基类的构造函数、析构函数、重载运算符，但是可以调用**

### 2.3 C++11：继承基类的构造函数

有时候派生类的构造函数只是简单模拟一些基类的构造函数，C++11中 在派生类定义中任何地方加`using Myclass::Myclass`，对于基类的每个构造函数，编译器都生成一个派生类的构造函数。

> 继承来的构造函数与基类中的访问权限相同
>
> 缺省构造函数、拷贝构造函数、移动构造函数不被继承
>
> 基类的构造函数原型放置=delete，在基类中删除这个构造函数，派生类中的构造函数响应也被删除

## 3.不同权限继承

采用public继承时

> 基类中的public成员是派生类中的public成员
>
> 基类中的protected成员是派生类中的protected成员
>
> 基类中的private成员永远不能被派生类直接访问

采用protected继承时

> 基类中的public成员是派生类中的protected成员
>
> 基类中的protected成员是派生类中的protected成员
>
> 基类中的private成员永远永远不能被派生类直接访问

采用private继承时

> 基类中的public成员是派生类中的private成员
>
> 基类中的protected成员是派生类中的private成员
>
> 基类中的private成员永远永远永远不能被派生类直接访问

**基类中的private成员永远永远永远永远不能被派生类直接访问**

## 4.多继承

一个派生类可以继承多个基类

语法：`class 派生类名:继承方式 基类A,继承方式 基类B……{……};`

如果两个基类有一样的成员函数，那么派生类调用哪个呢？

```cpp
#include <iostream>
//基类A
class A
{
public:
	void Prt();
};
//基类B
class B
{
public:
    void Prt();
};
//派生类C
class C:public A,public B
{
public:
    void func()
    {
        Prt();
	}
};
int main()
{
    C c1;
    c1.func();
    return 0;
}

/*
xiaohong@xhs-ubt:/mnt/hgfs/VS/code/YQ/c++/3_继承$ g++ test.cpp 
test.cpp: In member function ‘void C::func()’:
test.cpp:20:9: error: reference to ‘Prt’ is ambiguous
   20 |         Prt();
      |         ^~~
test.cpp:12:10: note: candidates are: ‘void B::Prt()’
   12 |     void Prt();
      |          ^~~
test.cpp:6:14: note:                 ‘void A::Prt()’
    6 |         void Prt();
      |              ^~~
xiaohong@xhs-ubt:/mnt/hgfs/VS/code/YQ/c++/3_继承$ 
*/
//不明确，编译不通过
```

所以多继承中，多个基类有同名函数要使用作用域运算符明确调用的是哪个类的函数

### 4.1 重写（覆盖）

如果多个基类中的成员函数不能实现我派生类中同样需要实现的功能，那么就需要重写基类的函数。也就是说，**基类中已有的成员函数在派生类中再次声明和实现**，这样就实现了**重写（覆盖）**。

```cpp
#include <iostream>
using namespace std;
//基类A
class A
{
public:
	void Prt() const
    {
        cout<<"A::Prt()"<<endl;
    }
};
//基类B
class B
{
public:
    void Prt() const
    {
        cout<<"B::Prt()"<<endl;
    }
};
//派生类C
class C:public A,public B
{
public:
    void Prt()const
    {
        cout<<"C::Prt()"<<endl;
    }
};
int main()
{
    C c1;
    c1.Prt();
    return 0;
}

/*********************
C::Prt()
*/
```

这部分内容见将在下一章节详细说明

# 十一、面向对象编程：多态性

## 0.引言

多态性使编写的程序在处理同一个类层次结构下的所有对象都好像是基类的对象一样

假设有多个派生类的对象，他们由一个共同的基类继承而来，基类中有一个成员函数，这些派生类有各自不同的方式来实现这个成员函数。程序向这些派生类发送同样的成员函数消息，这些成员函数都有各自的相应方式

这样更便于向一个系统中添加新类，只需改变少量代码

多态在C++中有两种表现形式：

- 编译时多态

  > 函数重载——**编译过程中**编译器会整合参数类型或数量，形成新的函数名然后自动匹配调用，这种机制称为**换名机制**。可以将编译好的.out文件通过nm指令查看可执行文件的符号表来查看函数名和地址，但是在C语言中没有这个机制，这就导致了C和C++混合编程时，C++中重载的函数名在C文件中没法调用，找不到编译过后的函数名，所以C++提供了extern "C"来解决
  >
  > 运算符重载

- 运行时多态

  > 虚函数

## 1.类层次中对象之间的关系

public继承的派生类的对象可以当成他们基类的对象进行处理。程序中可以创建一个基类指针的数组，数组元素指向多个派生类的对象，尽管基类对象和派生类对象不是同类型，但编译器允许这样赋值，因为每个派生类对象都是一个基类对象，但是不能把基类对象当成派生类对象进行处理

### 1.1 从派生类对象调用基类函数（将基类指针指向派生类对象）

继续沿用1.4.1的BPP类和Cmsepl类，主函数如下

```cpp
//。。。
int main()
{
	//声明一个Cmsepl对象ce1和BPP对象bp1，并赋初值
	Cmsepl ce1("张瑞雪", "6599 849648494", 4000, 0.5);
	BPP bp1("李慧","1616 486454165",3000,0.3,2500);
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
/*****************终端*****************
张瑞雪的部分工资：
姓名：张瑞雪
卡号：6599 849648494
销售总额：4000
提成比例：0.5

李慧的全部工资：
姓名：李慧
卡号：1616 486454165
销售总额：3000
提成比例：0.3
底薪：2500

通过指针调用各自的ptr函数进行打印
张瑞雪的部分工资：
姓名：张瑞雪
卡号：6599 849648494
销售总额：4000
提成比例：0.5

李慧的全部工资：
姓名：李慧
卡号：1616 486454165
销售总额：3000
提成比例：0.3
底薪：2500

将原本指向张瑞雪类型的指针指向李慧
调用张瑞雪类型的指针打印工资，究竟是谁的呢？

↓↓↓↓↓↓↓↓
姓名：李慧
卡号：1616 486454165
销售总额：3000
提成比例：0.3
```

**基类指针指向派生类对象**

定义的ceptr指针指向的类型为Cmsepl，而bp1的类型为BPP，但是编译器允许这样赋值，因为**每个派生类对象都是基类对象**

ceptr指向bp1，然后用这个指针调用prt函数ceptr->prt()，调用的仍然是Cmsepl类中的prt函数。

被调用的功能取决于调用函数的句柄的类型，而不是取决于句柄指向对象的类型

### 1.2 将派生类指针指向基类对象

沿用1.1例程，修改main函数

```cpp
int main()
{
    Cmsepl ce1("张瑞雪", "6599 849648494", 4000, 0.5);
BPP bp1("李慧", "1616 486454165", 3000, 0.3, 2500);
	BPP* bpptr = nullptr;
    //bpptr=&ce1;//error
}
```

第六行代码尝试将BPP（派生类）类型的指针bpptr，指向Cmsepl（基类）类型的对象ce1。这样会报错，因为Cmsepl类对象并不是BPP类对象，但BPP类对象是Cmsepl类对象

如果允许这样赋值，调用类BPP的每个函数，包括setBasesalary，但是Cmsepl没有提供这样的函数。强行这样会导致内存中其他重要数据被覆盖

### 1.3 通过基类指针调用派生类成员函数

沿用1.1例程继续说明，当基类指针指向派生类对象时，基类指针只能调用基类的成员函数和继承下去的函数，不能直接调用派生类独有的成员函数

**向下转换**

> C++允许指向派生类对象的基类指针访问只在派生类对象中独有的成员函数，只要显式的将基类指针强转为派生类指针，这就是**向下转换技术**，但向下转换具有潜在的威胁性

本节简要概述向下转换技术，本章最后会介绍如何安全的向下转换

## 2.virtual函数和virtual析构函数

假设有一组形状类：三角、圆、方……他们都是由Shape类派生而来，每个类都有一个draw函数来绘制自己的图形。在程序中，要绘制任意一种形状，通过Shape类指针调用函数draw，让程序动态的决定调用哪个派生类的draw函数来进行绘制，这就是多态行为

### 2.1 声明virtual函数（虚函数）

要允许这种行为，必须在基类中将这种函数声明为virtual，在派生类中重写darw（其实差不多就是重新定义），使之能够完成对应的行为

在派生类中重写的基类函数必须与基类函数有相同的签名和返回值类型。如果基类没有把这个函数声明为virtual，那么在派生类中就可以重新定义这个函数。如果基类中把该函数声明为virtual，那么该基类的整个继承层次的派生类中，都可以重写该函数来实现多态性行为

`virtual void darw() cosnt`该声明是在基类中的声明，这个函数声明为const是表示在这个函数体内没有对对象进行改变，virtual函数不一定分要声明为const

一旦基类中的一个函数声明为virtual，那么整个继承层次从该基类向下的所有派生，这个函数都是virtual的，即使派生类中没有将这个函数显式的声明为virtual，但是为了程序更加清晰可读，要将派生中重写的函数前加上virtual

当派生类不重写函数，那么使用该派生对象的这个函数是，会默认调用基类的virtual函数实现

### 2.2 动态绑定

声明一个基类指针`Shape* shapeptr=nullptr;`声明一个Shape基类的继承类SanJ三角类型对象`SanJ sj1`指向三角继承类`shapeptr=&sj1`,调用virtual函数`shapeptr->draw()` 

或者声明一个派生类对象`SanJ sj1`,通过指向派生类对象的基类引用`Shape& sp=sj1`,调用`virtual`函数`sp.darw()`

通过基类指针或者引用调用虚函数这样的做法，是在执行时（不是编译时）选择合适的调用函数，称为**动态绑定**或迟绑定

C++11中，在派生类重写的函数声明后加override会破是编译器检查基类是否有对应的virtual函数，如果没有会报错

### 2.3 静态绑定

声明一个派生类对象`SanJ sj1`，通过对象访问darw函数`sj1.darw()`

通过对象名称调用虚函数这样的做法，是在编译时就已经决定了调用哪个函数的，称为**静态绑定**

非虚函数的调用始终采用的是静态绑定

### 2.4 C-BP层次中的virtual函数

将Cmsepl和BPP中的income函数和prt函数声明为virtual,仅在头文件函数原型声明即可，不需要再函数实现声明

```cpp
//Cmsepl.h
#pragma once
#ifndef _CMSEPL_H
#define _CMSEPL_H
#include<string>
class Cmsepl
{
public:
	Cmsepl(const std::string&, const std::string&, double=0.0,double=0.0);
	void setName(const std::string&);
	std::string getName()const;

	void setcardNum(const std::string&);
	std::string getcardNum()const;

	void setgrossSell(double);
	double getgrossSell()const;

	void setCom(double);
	double getCom()const;

	virtual double income()const;
	virtual void prt()const;
private:
	std::string name;
	std::string cardNum;
	double grossSell;
	double commission;
};

#endif
```

```cpp
//BPP.cpp
#pragma once
#ifndef _BPP_H
#define _BPP_H
#include"Cmsepl.h"
#include<string>
class BPP :public Cmsepl
{
public:
	BPP(const std::string&, const std::string&, 
		double=0.0, double = 0.0, double = 0.0);
	void setBasesalary(double);
	double getBasesalary()const;
	virtual double income() const;
	virtual void prt() const;
private:
	double baseSalary;
};
#endif
```

主函数中通过动态绑定实现多态

```cpp
int main()
{
	Cmsepl* ceptr = nullptr;
	Cmsepl ce1("张瑞雪","165165 165161",500,0.6);
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
/****************终端************
姓名：李慧					<-1
卡号：44984 84984984		 <-2
销售总额：5000				<-3
提成比例：0.5				<-4
底薪：2500				   	 <-5
总工资:5000				 <-6


姓名：张瑞雪				   <-1
卡号：165165 165161		 <-2
销售总额：500			    <-3
提成比例：0.6				<-4
提成工资:300				 <-5
```

当相同的消息（prt和income）通过基类指针发送给不同的派生类对象时，会呈现出不同样式，这就是**多态性行为**

### 2.5 virtual析构函数

 如果一个类含有虚函数，那么该类就要提供一个virtual析构函数，及时这个析构函数是该类不需要的。这样可以保证一个派生类对象通过基类指针删除 时，这个派生类的virtual析构函数会被调用

### 2.6 C++11：Final成员函数和类

C++11之前任何派生类虚函数都可以重写基类的虚函数，C++11中，可以将基类中的虚函数声明为Final，那么该函数就不可被派生类重写。保证了所有派生类的该函数调用时都是基类中的虚函数实现

`virtual void func() final;`

C++11前，任何现有类在层次上都能被作为基类，C++11中，将类声明为final可以防止被用作基类

`class Myclass final{...};`

## 3.类型域和switch语句

判断加入到大型程序的对象类型的一种方式是使用switch语句，switch语句可以区分对象的不同类型。但是需要在switch语句中判断所有的可能情况，容易发生潜在的问题

但多态性程序设计可以消除不必要的switch逻辑，使用多态性机制同样可以完成同样逻辑。使用多态性可以使代码看上去更加简单

## 4.抽象类和纯virtual函数

### 4.1 抽象类

当把类当作类型时，都假设程序将创建这种类型的对象。有些情况下，有的类并不需要实现具体的功能，也不对这种类实例化任何对象，这种类叫**抽象类**。可以实例化对象的类叫做**具体类**。抽象类必须作为基类，抽象类只提供一个功能的方向,但没有具体功能的实现，功能的实现由抽象类派生出来的具体类实现。例如创建一个类叫二维形状，他派生出具体类方形、三角形……

### 4.2 纯虚函数

通过声明类的一个或者多个纯虚函数，可以使类称为抽象类。一个纯虚函数是在声明时将函数赋值为0：

`virtual void draw()const =0;`

`=0`称为纯指示符，纯虚函数只有声明，没有具体实现。每个派生的具体类必须重写抽象基类的纯虚函数，来提供函数的具体实现。

virtual函数有具体的实现，并且提供在派生类中是否重写这些函数的选择权

纯virtual函数不提供函数的实现，派生类重写这些函数可以使派生类成为具体类，否则派生类也是一个抽象类

当基类实现一个函数是没有意义的，而且又希望在派生类中实现这个函数，就会用到纯virtual函数，例如一个动物类，有一个成员函数就是动物叫声，这个成员函数并不具体，他是一个抽象的概念，并没有意义，但是派生的各种具体的动物（如猫、狗……）类中，要确确实实实现这种叫声（如喵喵喵、汪汪汪……），所以就要用到纯虚函数，将动物叫声这个函数设为纯虚函数。这个类就叫抽象类，它并不能实例化对象，因为他有一个纯虚函数

没有在派生类中重写基类中的纯虚函数，在实例化派生类对象时会报错

抽象类中可以有纯虚函数和普通函数，纯虚函数由派生类重写实现具体功能，普通函数再代码实现中可以由派生类对象之间调用

## 5.实例研究：应用多态性的工资发放系统

【某公司给员工发工资，雇员有三类：定薪雇员（Slrepl,SalariedEmployee）固定薪资、佣金雇员（Comsepl，CommissionEmployee）只赚提成、带薪佣金雇员（Bpce，BasePlusCommissionEmployee）基本工资加提成，统计他们的工资和个人基本信息】

### 5.1 创建抽象基类：Epl类

每种员工都应该有姓名、卡号这是具体的，变量也是具体的。还应该有计算总工资的函数income，再Epl类中，没有具体的工资，所以将他定义为纯虚函数；还有打印信息的函数prt，再Epl类中，它可以实现名字和卡号的打印，其他的信息需要由具体的派生类来实现各自的信息打印

|         |               income（总工资）                |           prt（打印）            |
| ------: | :-------------------------------------------: | :------------------------------: |
|     Epl |           没有具体总工资，纯虚函数            |          打印姓名和卡号          |
|  Slrepl |                固定工资salary                 |     打印姓名、卡号、固定工资     |
| Comsepl |      佣金工资=销售额gtossSalary*比例Coms      |     打印姓名、卡号、佣金工资     |
|    Bpce | 销售额gtossSalary*比例Coms+基本工资baseSalary | 打印姓名、卡号、佣金工资、总工资 |

**Epl的头文件**

```cpp
//Epl.h
#pragma once
#ifndef _EPL_H
#define _EPL_H
#include<string>
class Epl
{
public:
	Epl(std::string, std::string);
	virtual ~Epl() {};
	void setName(const std::string& );
	std::string getName()const;
	void setcardNum(const std::string&);
	std::string getcardNum()const;
	virtual double income()const = 0;
	virtual void prt()const;
private:
	std::string Name;
	std::string cardNum;
};
#endif
```

该文件有两个数据成员：姓名和卡号。

包括一个构造函数，传参为姓名和卡号；一个虚析构函数；设置姓名和卡号的set和get函数；计算和打印工资的纯虚函数income，因为该类中没有可打印的工资，该类作为基类继承下去的派生类通过重写income来打印对应派生具体的工资；一个prt虚函数，可以打印姓名、卡号，但在派生类中需要重写打印具体的信息

**头文件类成员的具体定义文件**

```cpp
//Epl.cpp
#include<iostream>
#include"Epl.h"
#include<string>
using namespace std;
Epl::Epl(std::string nm, std::string cn)
{
	setName(nm);
	setcardNum(cn);
}
void Epl::setName(const std::string& nm)
{
	if (nm.size() > 0&&nm.size()<10)
		Name = nm;
	else
		throw invalid_argument("姓名有误");
}
string Epl::getName()const
{
	return Name;
}

void Epl::setcardNum(const std::string& cn)
{
	if (cn.size() > 0 && cn.size() < 20)
		cardNum = cn;
	else
		throw invalid_argument("卡号有误");
}
string Epl::getcardNum()const
{
	return cardNum;
}
void Epl::prt()const
{
	cout << "姓名：" << getName() << endl;
	cout << "卡号：" << getcardNum() << endl;
}
```

### 5.2 创建具体的派生类：Slrepl类

**注意：类实现前要记得写访问权限，继承类时也要记得写明访问权限（经常忘写QAQ，然后莫名其妙报错找不到哪里有问题）**

**Slrepl的头文件。Slrepl类继承于Epl类**

```cpp
//Slrepl.h
#pragma once
#ifndef _SLREPL_H
#define _SLREPL_H
#include"Epl.h"
#include<string>
class Slrepl :public Epl
{
public:
	Slrepl(const std::string& , const std::string&,
		const double&);
	virtual ~Slrepl() {};

	void setSalary(double);
	double getSalary()const;

	virtual double income()const override;
	virtual void prt()const override;
private:
	double salary;
};
#endif
```

该文件有一个数据成员：固定工资salary。

包括一个构造函数，传参为姓名、卡号、固定工资；一个虚析构函数；设置固定工资的set和get函数；重写基类中计算和打印工资的虚函数income；重写基类中的prt虚函数，打印姓名、卡号、固定工资

**要注意派生类重写虚函数，要在声明后加override**

**头文件类成员的具体定义文件**

```cpp
//Slrepl.cpp
#include"Slrepl.h"
#include<string>
#include<iostream>
using namespace std;
Slrepl::Slrepl(const std::string& nm, const std::string& cn,
	const double& sl)
	:Epl(nm,cn)
{
	setSalary(sl);
}
void Slrepl::setSalary(double sl)
{
	if (sl > 0)
		salary = sl;
	else
		throw invalid_argument("固定工资有误");
}
double Slrepl::getSalary()const
{
	return salary;
}
double Slrepl::income()const
{
	cout << getSalary() << endl;
	return getSalary();
}
void Slrepl::prt()const
{
	/*
    cout << "姓名：" << Epl::getName() << endl;
	cout << "卡号：" << Epl::getcardNum() << endl;
	*/
    Epl::prt();
	cout << "固定工资：" << Slrepl::getSalary() << endl;

}
```

构造函数中，将姓名和卡号作为参数传给基类的构造函数，用来初始化姓名，然后花括号成员初始化器中调用set函数对固定工资初始化

还有一个要注意的点就是，重写的虚函数中可以直接调用基类的该虚函数，然后添加要增加的功能。比如该文件中，prt虚函数函数体中，同样需要打印姓名和卡号，不必写成注释中的那样，直接调用基类的prt函数即可。注意要加作用域分辨运算符，不然会死循环

如果不重写income函数，那么这个类也将变成抽象类

如果不重写prt函数，那么打印时执行的是基类中提供的prt函数，仅打印姓名和卡号

为了使程序清晰可读，重写的虚函数最好在类层次结构中的每一级都显式的声明为virtual

### 5.2 创建具体的派生类：Comsepl类

**Comsepl类的头文件。Comsepl类继承于Epl类**

```cpp
//Comsepl.h
#pragma once
#ifndef _COMSEPL_H
#define _COMSEPL_H
#include"Epl.h"
class Comsepl :public Epl
{
public:
	Comsepl(const std::string&, const std::string&,
		const double&, const double&);
	virtual ~Comsepl() {};
	void setgrossSeles(const double);
	double getgrossSeles() const;
	void setCom(const double);
	double getCom() const;
	virtual double income() const override;
	virtual void prt() const override;
private:
	double grossSales;
	double com;
};
#endif
```

同理，但是这次数据成员为两个，有销售金额和提成比例，所以构造函数中参数也多了一个

```cpp
//Comsepl.cpp
#include"Comsepl.h"
#include<iostream>
#include<string>
using namespace std;
Comsepl::Comsepl(const std::string& nm, const std::string& cn,
	const double& gs, const double& cm)
	:Epl(nm,cn)
{
	setgrossSeles(gs);
	setCom(cm);
}
void Comsepl::setgrossSeles(const double gs)
{
	if (gs > 0)
		grossSales = gs;
	else
		throw invalid_argument("销售金额有误");
}
double Comsepl::getgrossSeles() const
{
	return grossSales;
}

void Comsepl::setCom(const double cm)
{
	if (cm > 0&&cm<=1)
		com = cm;
	else
		throw invalid_argument("提成比例有误");
}
double Comsepl::getCom() const
{
	return com;
}
double Comsepl::income() const
{
	cout << "提成工资：" << getCom() * getgrossSeles() << endl;
	return getCom() * getgrossSeles();
}
void Comsepl::prt() const
{
	Epl::prt();
	cout << "销售金额：" << getgrossSeles()<<endl;
	cout << "提成比例：" << getCom() << endl;
}
```

### 5.3 创建间接派生的具体类：Bpce类

**Bpce类的头文件。Bpce类继承于继承于Epl类的Comsepl类**

**说人话，也就是Bpce类直接继承于Comsepl类，而Comsepl类直接继承于Epl类，所以Bpce类间接继承于Epl类**

```cpp
//Bpce.h
#pragma once
#ifndef _BPCE_H
#define _BPCE_H
#include"Comsepl.h"
class Bpce :public Comsepl
{
public:
	Bpce(const std::string&, const std::string&,
		const double&, const double&, const double&);
	virtual ~Bpce() {};

	void setslr(const double);
	double getslr() const;

	virtual double income() const override;
	virtual void prt() const override;
private:
	double baseSalary;
};
#endif
```

```cpp
//Bpce.cpp
#include<iostream>
#include"Bpce.h"
#include<string>
using namespace std;
Bpce::Bpce(const std::string& nm, const std::string& cn,
	const double& gs, const double& cm, const double& sl)
	:Comsepl(nm, cn, gs, cm)
{
	setslr(sl);
}

void Bpce::setslr(const double sl)
{
	if (sl > 0)
		baseSalary = sl;
	else
		throw invalid_argument("底薪有误");
}
double Bpce::getslr() const
{
	return baseSalary;
}

double Bpce::income() const
{
	cout << "工资为：" << Comsepl::income() + getslr() << endl;
	return Comsepl::income() + getslr();
}
void Bpce::prt() const
{
	Comsepl::prt();
	cout << "底薪：" << getslr()<<endl;
}
```

### 5.4 多态执行过程演示

将上述所有代码编译，在下述主函数执行

将三个具体类都创建对象

```cpp
//main.cpp
#include"Epl.h"
#include"slrepl.h"
#include"Comepl.h"
#include"Bpce.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    cout << fixed << setprecision(2);
	Slrepl a1("李慧","9438984",3000 );
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
    getchar();
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
    getchar();
    puts("");
    cout << "动态绑定，通过遍历数组中存放的每个对象的地址，成员运算符访问prt成员打印信息如下：\n";
    for (const Epl* ep : eplPtr)
    {
        (*ep).prt();//打印a1的信息
        (*ep).income();//打印a1的信息
    }
}
/********打印的值完全相同，均为*************
姓名：李慧
卡号：9438984
固定工资：3000.00
工资：3000.00

姓名：张瑞雪
卡号：8357345983
销售金额：5738.00
提成比例：0.50
提成工资：2869.00

姓名：高云龙
卡号：3857293
销售金额：9999.00
提成比例：0.90
底薪：20000.00
提成工资：8999.10
工资为：28999.10
```

## 6.实例研究：应用向下强制类型转换、dynamic_cast、typeid、和type_info并使用多态性和运行时类型信息的工资发放系统

要动态改变值，必须知道他的地址，通过指针来修改值

```cpp
#include<iostream>
#include<iomanip>
#include<vector>
#include<typeinfo>
#include"Epl.h"
#include"slrepl.h"
#include"Comepl.h"
#include"Bpce.h"
using namespace std;
int main()
{
	cout << fixed << setprecision(2);
	vector<Epl*>eplPtr(3);//定义三个基类类型的指针
	eplPtr[0] = new Slrepl("李慧", "9438984", 3000);//给每个派生类动态分配内存，地址为基类类型
	eplPtr[1] = new Comsepl("张瑞雪", "64648984", 5800,0.5);//派生类的对象可以用基类指针指
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
			double oldslr=bpcePtr->getslr();
			cout << "\n以前的底薪为：" << oldslr << endl;
			bpcePtr->setslr(oldslr * 1.1);
			cout << "\n加薪后的员工信息为：" << endl;
			bpcePtr->prt();
		}
	}
	size_t i = 0;
	for (Epl* epl : eplPtr)
	{
		cout << "第"<<++i<<"个对象的类型为："
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
/*****************终端*************
姓名：李慧
卡号：9438984
固定工资：3000.00

姓名：张瑞雪
卡号：64648984
销售金额：5800.00
提成比例：0.50

姓名：高云龙
卡号：3857293
销售金额：9999.00
提成比例：0.90
底薪：20000.00

打印一次bpcePtr对象的信息

姓名：高云龙
卡号：3857293
销售金额：9999.00
提成比例：0.90
底薪：20000.00

以前的底薪为：20000.00

加薪后的员工信息为：
姓名：高云龙
卡号：3857293
销售金额：9999.00
提成比例：0.90
底薪：22000.00
第1个对象的类型为：class Slrepl
第2个对象的类型为：class Comsepl
第3个对象的类型为：class Bpce

提成工资：8999.10
工资为：30999.10
```

`dynamic_cast<tipe-id>(expression)`用于处理继承体系安全类型转化的运算符

expression为对应类型的指针或引用，type-id为目标类指针、类引用或void*。dynamic_cast与static不同的是，dunamic_cast会在运行时检查类型，在这里只讨论例程中的情况

`Bpce* bpcePtr = dynamic_cast<Bpce*>(epl);`

当epl实际指向的对象为Bpce类型时，将转换后的值赋值给bpcePtr，当epl实际指向的对象不是Bpce类型，返回nullptr

typeid用于运行时类型识别，`typeid(目标).name()`表示，打印目标的类型

