// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

int main()
{
	double a = 11.1111;
	cout << a << std::endl;
	cout<<std::setprecision(3);
	cout << a << std::endl;
	cout << std::setiosflags(std::ios::fixed);
	cout << a;
	return 0;
}