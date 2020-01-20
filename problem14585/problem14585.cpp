// problem14585.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//   题目链接：https://ac.nowcoder.com/acm/problem/14585
//

#include <iostream>
using std::cout;
using std::cin;

int fun(int n)
{
	if (n == 1)
		return 2;
	else
	{
		return 2 + 3 * fun(n - 1);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		//判断是否读到文件末尾
		if (n == EOF)
			break;
		cout << fun(n) << std::endl;		//加上换行符，因为OJ有一些一次性测试一个文件，没有换行符会显示错误
	}
}
