// problem14974.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

char** arr;

inline int pow(int n)
{
	int ans = 1;
	while (n--)
	{
		ans *= 3;
	}
	return ans;
}

void draw(int x,int y,int size)
{
	if (size == 1)
	{
		arr[x][y] = 'O';
		return;
	}
	else
	{
		draw(x, y + size / 3, size / 3);
		draw(x, y - size / 3, size / 3);
		draw(x + size / 3, y, size / 3);
		draw(x - size / 3, y, size / 3);
	}
}

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int n;
		std::cin >> n;
		if (n == 0)
		{
			std::cout << "O\n";
			continue;
		}
		int size = pow(n);
		arr = new char*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new char[size];
			//全部初始化为' '（空格）
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = ' ';
			}
		}
		draw(size/2,size/2,size);

		//找到每行的最后‘O’的位置，就好输出了
		for (int i = 0; i < size; i++) 
		{
			int p = 0;
			for (int j = size - 1; j >= 0; j--)
			{
				if (arr[i][j] == 'O')
				{
					p = j;
					break;
				}
			}
			for (int j = 0; j <= p; j++)
			{
				std::cout << arr[i][j];
			}
			std::cout << '\n';
		}

		//释放内存
		delete[] arr;
		arr = nullptr;
	}
	return 0;
}

