// problem14835.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
			cout << "HelloWorld" << endl;
		else if (i % 2 == 0)
			cout << "Hello" << endl;
		else if (i % 3 == 0)
			cout << "World" << endl;
		else
			cout << i << endl;
	}
}

