/**
 * @date 2022/10/15
 * @author 2mu
 * @brief medium 用栈操作数组
 * 
 * 一. stack
 * 利用stack，直接完成。每次都确定一下target首元素，不满足target首元素，那就只能push，在pop了。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    int idx = 0;
    std::vector<std::string> ans;
    for(int i = 1; i <= n; ++i)
    {
        if(idx >= target.size())
        {
            break;
        }
        if(i == target[idx])
        {
            idx++;
            ans.emplace_back("Push");
        }
        else
        {
            ans.emplace_back("Push");
            ans.emplace_back("Pop");
        }
    }
    return ans;
}

int main()
{
    std::vector<int> target{1, 3};
    auto ans = buildArray(target, 3);
    for(auto str : ans)
        std::cout << str << std::endl;
    return 0;
}
