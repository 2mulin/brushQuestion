/**
 * @date 2022/1/20
 * @author 2mu
 * @brief medium 查找用户活跃数
 * 
 * 一、哈希表
 * 使用哈希表模拟，set类型 哈希表去重。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>> &logs, int k)
{
    std::unordered_map<int, std::unordered_set<int>> ma;
    for(int i = 0; i < logs.size(); ++i)
    {
        int userID = logs[i][0], min = logs[i][1];
        ma[userID].insert(min);
    }

    std::vector<int> ans(k, 0);
    for(auto iter = ma.begin(); iter != ma.end(); ++iter)
    {
        int activeMin = iter->second.size();
        ++ans[activeMin - 1];
    }
    return ans;
}

int main()
{
    return 0;
}
