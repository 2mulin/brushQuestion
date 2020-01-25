// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <deque>
using std::deque;
using std::string;
using std::cin;
using std::cout;

struct s
{
	string address;
	int data;
	string next;
};

int main()
{
	//初始化
	string start;
	int n, k;
	cin >> start >> n >> k;
	if (n <= 0)
		exit(-1);
	s* arr = new s[n];						//存放排好顺序的链表
	deque<s> q;								//存放刚输入的数据，便于查找
	for (int i = 0; i < n; i++)
	{
		s temp;
		cin >> temp.address >> temp.data >> temp.next;
		q.push_back(temp);
	}

	//把排好序的链表放到数组里去
	int index = 0;
	while (!q.empty())
	{
		if (q.front().address == start)
		{
			arr[index++] = q.front();
			q.pop_front();
			start = arr[index - 1].next;
			if (start == "-1")
			{
				n = index;					//n为有效数据
				break;
			}
		}
		else
		{
			q.push_back(q.front());
			q.pop_front();
		}
	}

	//链表反转
	int sizeK = k;							//原来K的大小
	index = 0;
	while (k<n)
	{
		int count = sizeK / 2;				//swap需要调用的次数
		while (count--)
		{
			if (sizeK % 2 == 0)				//输入的k为偶数
				std::swap(arr[index], arr[index + count * 2 + 1]);
			else							//输入的k为奇数
				std::swap(arr[index], arr[index + count * 2 + 2]);
			index++;
		}
		index = k;
		k += sizeK;
	}
	//重新写next
	for (int i = 0; i < n - 1; i++)
	{
		arr[i].next = arr[i+1].address;
	}

	//输出结果
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].address << ' ' << arr[i].data << ' ' << arr[i].next << std::endl;
	}
	delete[] arr;
	return 0;
}