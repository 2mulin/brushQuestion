/*************************************
 * @author reddragon
 * @date 2020/6/9
 * @description: 并查集
*************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int arr[100001];
/********************************************
 * @param i 数组下标
 * @return root
 * @description: 自己就是root，直接返回。
 * 否则，继续找root.返回root所在位置
********************************************/
int find(int i)
{
    if (i == arr[i])
        return i;
    return arr[i] = find(arr[i]); //细节，路径压缩。
}

/*******************************************
 * @param x 集合1
 * @param y 集合2
 * @description: 合并集合1和集合2
*******************************************/
void Union(int x, int y)
{
    int xRoot = find(x), yRoot = find(y);
    if (xRoot != yRoot)
        arr[xRoot] = yRoot; // 注意是改变arr[xRoot]。这样xRoot这边整个树的根都会变
    return;
}

int main()
{
    ios::sync_with_stdio(false); //关闭scanf和printf。
    int n, m;
    while (cin >> n >> m)
    {
        // 所有点自成一个集合
        for (int i = 1; i <= n; i++)
            arr[i] = i;
        int a, b;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            Union(a, b);
        }
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(find(arr[i])); //一定find(arr[i])得到root,然后插入。
        cout << s.size() - 1 << endl;
    }
    return 0;
}