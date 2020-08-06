#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

int visit[200] = {0};
int *arr1, *arr2;

//是否已经移动完成
bool isMoved(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        arr1 = new int[n];
        arr2 = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i] >> arr2[i];
        }

        //如果移动的两个位置之间有公共的走廊，肯定不能在同一时间内移动，所以
        //此题的关键在于找到那些公共的走廊有多少个，定义一个200的数组表示走廊
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++)
        {
            int start = ((arr1[i] > arr2[i] ? arr2[i] : arr1[i]) - 1) / 2;
            int end = ((arr1[i] > arr2[i] ? arr1[i] : arr2[i]) - 1) / 2;
            for (int j = start; j <= end; j++)
            {
                visit[j] += 10;
            }
        }
        int ans = 0;
        for (int i = 0; i < 200; i++)
        {
            if (ans < visit[i])
                ans = visit[i];
        }
        cout << ans << endl;
        delete[] arr1;
        delete[] arr2;
    }
    return 0;
}