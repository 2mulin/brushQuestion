// problem19814.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 利用取余就可以完成大数能不能整除的判断


#include <iostream>
using std::cin;

int main()
{
	char arr[10005];
	int size=0;
	for (int i = 0; i < 100000; i++)
	{
		cin.get(arr[i]);
		if (arr[i] == '\n')
		{
			size = i;
			break;
		}
	}
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	for (int i = 0; i < size; i++)
	{
		num1 += arr[i] - '0';
		num2 += arr[i] - '0';
		num3 += arr[i] - '0';
		num4 += arr[i] - '0';

		num1 %= 3;
		num2 %= 5;
		num3 %= 8;
		num4 %= 11;

		num1 *= 10;
		num2 *= 10;
		num3 *= 10;
		num4 *= 10;
	}
	if (num1 && num2 && num3 && num4)		//有一个0就表示至少有一个数字可以整除
		std::cout << "No"<<'\n';
	else
	{
		std::cout << "Yes" << '\n';
		if (!num1)
			std::cout << "3 ";
		if (!num2)
			std::cout << "5 ";
		if (!num3)
			std::cout << "8 ";
		if (!num4)
			std::cout << "11 ";
	}
}

