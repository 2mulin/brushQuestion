/********************************************************************************************
 * @author reddragon
 * @date 2020/11/26
 * @brief stack弹出序列是否合法
 * 
 * 1.模拟
 * 很简单，用一个栈模拟一下。
 * 主要是要注意maxDeep参数，题目给了栈的最大容量，一旦栈超过了最大容量
 * 立即返回false。入栈序列当前元素若是栈顶元素相等，立即出栈，否则入栈
 * 时间复杂度：O(N)     空间复杂度：O(maxDeep)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// 判断序列是否合法
bool isFail(int maxDeep, int n, vector<int> arr)
{
    stack<int> st;
    int i = 1;// 输入序列
    int pos = 0;// 输出序列的pos
    while(1)
    {
        if(!st.empty() && st.top() == arr[pos])
        {
            st.pop();
            ++pos;
        }
        else
        {
            st.push(i);
            ++i;
        }
        // 深度限制
        if(st.size() > maxDeep)
            return false;
        if(i > n)
            break;
    }
    while(!st.empty() && st.top() == arr[pos])
    {
        st.pop();
        ++pos;
    }
    if(i > n && st.empty())
        return true;
    return false;
}

int main()
{
    int M,N,K;// M是堆栈的最大容量，N是推送序列长度，K是测试样例数
    cin >> M >> N >> K;
    while(K--)
    {
        vector<int> arr(N);
        for(int i = 0; i < N; ++i)
            cin >> arr[i];
        if(isFail(M, N,arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}