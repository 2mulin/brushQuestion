/**
 * @date 2022/9/9
 * @author 2mu 文件夹日志操作收集器
 * @brief 
 *
 * 一. 判断下
 * 
 * 记录当前在第几级目录就可以了。直接返回。反正每次操作也只可以往上走一级目录。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int minOperations(vector<string> &logs)
{
    int ans = 0;
    for (auto log : logs)
    {
        if(log == "../")
        {
            if(ans != 0)
                --ans;
        }
        else if(log == "./")
            continue;
        else
            ++ans;
    }
    return ans;
}

int main()
{
    return 0;
}
