// problem50966.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目：team queue

#include <iostream>
#include <queue>
#include <string>
using std::queue;
using std::string;
using std::cin;
using std::cout;

int t;													//数组行数
int* index;												//存放队列顺序，也就是哪个队伍排前面，哪个排后面
int team[1000000];										//元素是0到999999范围内的整数，存放元素属于哪个队伍，省去查找的时间O(n)。不然会爆

//查看i是否存在index中
bool visit(int val)
{
	for (int i = 0; i < t; i++)
	{
		if (index[i] == val)
			return true;
	}
	return false;
}

int main()
{
	for (int k = 1;; k++)
	{
		cin >> t;
		if (t == 0)
			break;
		int** arr = new int* [t];						//二维数组
		queue<int>* qArr = new queue<int>[t];			//队列数组，存放不同队列的人
		int count = 0;									//队列中已经有的队伍数
		index = new int[t];

		//读取t个数组
		for (int i = 0; i < t; i++)
		{
			int size;									//数组列数
			cin >> size;
			arr[i] = new int[size + 1];					//多加一列，数组元素a[0]存放该数组长度
			arr[i][0] = size;
			for (int j = 1; j <= size; j++)
			{
				int temp;
				cin >> temp;
				arr[i][j] = temp;
				team[temp] = i;							//给每个元素找到队伍
			}
			index[i] = -1;								//表示该队伍没有人在排队
		}

		cout << "Scenario #" << k << '\n';

		//判断输入决定执行
		while (true)
		{
			string input, s = "STOP", e = "ENQUEUE";
			cin >> input;
			if (input == s)								//STOP结束
			{
				cout << std::endl;
				delete[] index;
				index = NULL;
				break;
			}
			else if (input == e)
			{
				int val;								//要入队的数
				cin >> val;
				//team[val]表示val属于哪一队
				qArr[team[val]].push(val);				//进入队列
				if (count < t && !visit(team[val]))
					index[count++] = team[val];			//记录该团队在队列的排行
			}
			else
			{
				//排名前面的一个团队出队一个人
				cout << qArr[index[0]].front() << std::endl;
				qArr[index[0]].pop();
				if (qArr[index[0]].empty())				//如果该团队没有人在队列了
				{
					for (int i = 0; i < t - 1; i++)
					{
						index[i] = index[i + 1];
					}
					index[t - 1] = -1;
					count--;							//进队列的团队数减少1个
				}
			}
		}
		delete[] arr;
		arr = NULL;
		delete[] qArr;
		qArr = NULL;
	}
}
