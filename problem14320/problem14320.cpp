// problem14320.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//总结一下，了解了memset能初始化连续的内存地址的，而使用多次new出来的二维数组地址并不连续所以不能使用memset
//

#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int n;
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n] {0};		//就地初始化
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			arr[i][0] = 1;
		else
		{
			for (int j = 0; j <= i; j++)
			{
				//第一个数等于上一行的第一个数
				if (j == 0)
					arr[i][j] = arr[i - 1][j];
				//最后一个数等于上一行最后的一个数
				else if (j == i)
					arr[i][j] = arr[i - 1][j - 1];
				//其他的等于头顶两个数之和
				else
				{
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == i)
				cout << arr[i][j];
			else
				cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}