// problem18992.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

unsigned long long pow(int x)
{
	unsigned long long ans = 2;
	if (x == 0)
		return 1;
	while (--x)
	{
		ans <<= 1;
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	unsigned long long nn = pow(n) / 7 + (pow(n) % 7 == 1 ? -1 : 0);
	unsigned long long mm = pow(m) / 7 + (pow(m) % 7 == 1 ? -1 : 0);
	cout << mm - nn << '\n';
	return 0;
}