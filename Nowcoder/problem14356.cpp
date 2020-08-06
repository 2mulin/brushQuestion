// problem14356.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using std::queue;
using std::cin;
using std::cout;

int main()
{
	int count;			//要转换的次数
	cin >> count;
	queue<char> s;
	s.push('0');		//初始化

	for (int i = 0; i < count; i++)
	{
		queue<char> temp;
		while (!s.empty())
		{
			char ch = s.front();
			s.pop();
			if (ch == '0')
				temp.push('1');
			else
			{
				temp.push('0');
				temp.push('1');
			}
		}
		s = temp;
	}
	while (!s.empty())
	{
		cout << s.front();
		s.pop();
	}
	cout << std::endl;
}