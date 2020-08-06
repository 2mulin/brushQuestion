/*************************************************************************
真二叉树是指每个节点的孩子要么为0要么为2
该题是已知真二叉树的前序遍历和后序遍历求中序遍历。

注意：只有真二叉树才可以通过前序和中序求中序遍历
*************************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int *getTree(int *p, int *s, int size)
{
    if (size == 1)
    {
        int *ans = new int[size];
        ans[0] = p[0];
        return ans;
    }

    int *newP = nullptr; // 按照中序遍历排好序的左子树
    int lenP = 0;        // 左子树的大小
    for (int i = 0; i < size; i++)
    {
        // 前序遍历的第二个数是左子树的根
        if (p[1] == s[i])
        {
            lenP = i + 1;
            newP = getTree(&p[1], s, lenP);
            break;
        }
    }

    int *newS = nullptr;
    int lenS = 0; // 右子树的大小
    for (int i = size - 1; i >= 0; i--)
    {
        // 后序遍历的倒数第二个是右子树的根
        if (s[size - 2] == p[i])
        {
            lenS = size - i;
            newS = getTree(&p[lenP + 1], &s[lenP], lenS);
            break;
        }
    }

    int index = 0;
    int *ans = new int[size];
    for (int i = 0; i < lenP; i++)
    {
        ans[index++] = newP[i]; // 左子树赋值
    }
    ans[index++] = p[0];
    for (int i = 0; i < lenS; i++)
    {
        ans[index++] = newS[i]; // 右子树赋值
    }
    delete[] newP;
    delete[] newS;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    int *s = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int *ans = getTree(p, s, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << ans[n - 1] << std::endl;
    delete[] p;
    delete[] s;
    delete[] ans;
    return 0;
}