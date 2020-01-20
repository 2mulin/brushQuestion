// problem14291.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
/*
//冒泡排序和选择排序超时					 头文件自带的不超时，快速排序没试过
void sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}*/

inline long long Sum(int *arr,int size)
{
	long long sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	//初始化
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	std::sort(arr, arr+n);						//#include <algorithm>的算法有sort方法
	long long ans = 0, sum = Sum(arr, n);
	for (int i = 0; i < n-1; i++)
	{
		ans += sum;
		sum -= arr[i];
	}
	cout <<ans;

	//释放内存
	delete[] arr;
	arr = nullptr;
}
