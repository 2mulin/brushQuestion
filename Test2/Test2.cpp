// Test2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class A 
{
public:
	static int a;
private:
	static int b;
};

int A::a = 10;
int A::b = 20;

//返回X转化为二进制后的1的个数
int func(int x)
{
	int countx = 0;
	while (x)
	{
		countx++;
		x = x & (x - 1);
	}
	return countx;
}

int main()
{
	A instance;
	std::cout << A::a << std::endl << instance.a << std::endl;
	std::cout << func(22);
}
