// problem16407.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


/*					总结一下：数组范围在外面加一圈，可以在搜索的时候省去判断上下左右的时候还要判断是不是墙
								传参数时是（数组第pos个元素）一个参数而不是（x行,y列）两个参数，省去了递归时判断
								数组x，y值是否越界。
*/	

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool** arr;
int M, N, K, ans;

//对标记数组的初始化
void init()
{
	ans = 0;
	for (int i = 0; i < M + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			arr[i][j] = false;
		}
	}
}

void fun(int pos,int seats)
{
	if (seats == K)
	{
		ans++;
		return;
	}
	if (pos > M * N)
		return;
	int x = (pos - 1) / N + 1, y = (pos - 1) % N + 1;							//通过pos(即数组中第几个pos元素)得到数组坐标，好处如下
	if (!arr[x + 1][y] && !arr[x - 1][y] && !arr[x][y - 1] && !arr[x][y + 1])	//省去了递归时去判断是否会越界
	{
		arr[x][y] = true;
		fun(pos + 1, seats + 1);
		arr[x][y] = false;
		fun(pos + 1, seats);
	}
	else
		fun(pos + 1, seats);
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		//初始化,数组多加一圈防止越界
		cin >> M >> N >> K;
		arr = new bool*[M+2];
		for (int j = 0; j < M + 2; j++)
		{
			arr[j] = new bool[N + 2];
		}

		init();
		fun(1,0);
		cout << ans % 420047 << endl;
		delete[] arr;
		arr = nullptr;
	}
}