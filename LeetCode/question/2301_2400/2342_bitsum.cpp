/**
 * @date 2023/11/18
 * @author 2mu
 * @brief medium 数位和相等数对的最大和
 *
 * 1. 遍历
 * 实际上是道简单题, 使用std容器的哈希表, 以及堆就可以解决;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int maximumSum(vector<int> &nums)
{
    // key数位和, value 数位和相等的值
    std::unordered_map<int, std::priority_queue<int>> hash_table;
    for(auto num : nums)
    {
        int sum = 0;// 数位和
        int num_copy = num;
        while(num_copy)
        {
            sum = sum + (num_copy % 10);
            num_copy /= 10;
        }
        hash_table[sum].push(num);
    }
    int ans = -1;
    for(auto iter = hash_table.begin(); iter != hash_table.end(); ++iter)
    {
        std::priority_queue<int>& que = iter->second;
        if(que.size() < 2)
            continue;
        int sum = que.top();
        que.pop();
        sum += que.top();
        ans = std::max(sum, ans);
    }

    return ans;
}

int main()
{
    std::vector<int> vct{18,43,36,13,7};
    std::cout << maximumSum(vct) << std::endl;
}