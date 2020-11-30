/********************************************************************************************
 * @author reddragon
 * @date 2020/11/30
 * @brief 并查集
 * 
 * 1. 并查集
 * 这个并查集优点简单，可能是我用了set的原因把
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int find(vector<int>& arr, int i)
{
    if(arr[i] == i)
        return i;
    else
        return arr[i] = find(arr, arr[i]);
}

int main()
{
    int N;
    while(cin >> N)
    {
        vector<int> arr(N + 1, 0);
        bool loop = true;
        while(loop)
        {
            char op;
            cin >> op;
            switch (op)
            {
                int a,b;
                case 'C':
                {
                    cin >> a >> b;
                    if(arr[a] != 0 && find(arr, a) == find(arr, b))
                        cout << "yes" << endl;
                    else
                        cout << "no" << endl;
                    break;
                }
                case 'I':
                {// 合并操作
                    cin >> a >> b;
                    if(arr[a] == 0 && arr[b] == 0)
                        arr[b] = arr[a] = a;
                    else if(arr[a] == 0 && arr[b])
                        arr[a] = find(arr,b);
                    else if(arr[a] && arr[b] == 0)
                        arr[b] = find(arr,a);
                    else
                    {// 将B集合添加到A集合
                        int parent = find(arr, a);
                        int child = find(arr, b);
                        arr[parent] = arr[child];
                    }
                    break;
                }
                case 'S':
                    loop = false;
                default:
                    break;
            }
        }
        set<int> s;
        for(int i = 1; i <= N; ++i)
            s.insert(arr[i] = find(arr, i));
        int ans = s.size();
        if(ans == 1)
        {
            if(s.find(0) != s.end())
                cout << "There are " << N << " components." << endl;
            else
                cout << "The network is connected." << endl;
        }
        else
            cout << "There are " << ans << " components." << endl;
    }
    return 0;
}