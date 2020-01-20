// problem19814.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*						借鉴了高手的写法，简洁明了，下面注释的代码自己写的，运用了一些规律，但是过不了			*/		

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

/*
int main()
{
	char arr[100000];
	int size = -1;													//记录数字长度
	bool num1 = false, num2 = false, num3 = false, num4 = false;	//记录能不能整除3，5，8，11
	for (int i = 0; i < 100000; i++)
	{
		cin.get(arr[i]);
		if (arr[i] == '\n')
		{
			size = i;
			break;
		}
	}
	//判断能不能被3整除
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i]-'0';
	}
	if (sum % 3 == 0)
		num1 = true;
	//判断能不能被5整除
	if (arr[size - 1]-'0' == 0 || arr[size - 1]-'0' == 5)
		num2 = true;
	//判断能不能被8整除
	if (size < 3)
	{
		if (size == 2)
		{
			int num = (arr[0] - '0') * 10 + arr[1] - '0';
			if (num % 8 == 0)
				num3 = true;
		}
		if (size == 1 && (arr[0] - '0') % 8 == 0)
			num3 = true;
	}
	else
	{
		int num = 0;
		num += arr[size - 1] - '0';
		num += (arr[size - 2] - '0') * 10;
		num += (arr[size - 3] - '0') * 100;
		if (num % 8 == 0)
			num3 = true;
	}
	//判断能不能被11整除
	int oddNum = 0, evenNum = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			oddNum += arr[i]-'0';
		else
			evenNum += arr[i]-'0';
	}
	if (oddNum == evenNum)
		num4 = true;

	//输出
	if (!(num1 || num2 || num3 || num4))
	{
		std::cout << "No";
	}
	else
	{
		std::cout << "Yes" << std::endl;
		if (num1)
			std::cout << "3";
		if (num2)
			std::cout << "5";
		if (num3)
			std::cout << "8";
		if (num4)
			std::cout << "11";
	}
}
*/
