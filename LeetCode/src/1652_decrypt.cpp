/**
 * @date 2024/5/5
 * @author 2mu
 * @brief easy 拆炸弹
 *
 * 1. 拆炸弹
 * 前缀和数组，根据k的值维护连续3个元素数组的和。注意看题目要求，n是1~100的整数，而且k还可能是个负数....
 * 但是k的绝对值 <= n - 1
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> decrypt(vector<int> &code, int k)
{
    int n = code.size();
    std::vector<int> result(n, 0);
    if(k > 0)
    {
        int sum = std::accumulate(code.begin(), code.begin() + k, 0);
        for(int i = n - 1; i >= 0; --i)
        {
            result[i] = sum;
            sum -= code[(i + k) % n];
            sum += code[i];
        }
    }
    else if(k < 0)
    {
        // 因为k是负数，注意这里取绝对值
        int sum = std::accumulate(code.rbegin(), code.rbegin() + std::abs(k), 0);
        for(int i = 0; i < n; ++i)
        {
            result[i] = sum;
            // 因为k是负数，所以这里也是+
            sum -= code[(n + k + i) % n];
            sum += code[i];
        }
    }
    else
    { 
        result = std::vector<int>(code.size(), 0);
    }
    return result;
}


int main(int argc, char **argv)
{
    // std::vector<int> arr{5,7,1,4};
    // std::vector<int> ans = decrypt(arr, 3);

    std::vector<int> arr{2, 4, 9, 3};
    std::vector<int> ans = decrypt(arr, -2);
    for(auto value : ans)
        std::cout << value << '\t';
    return 0;
}
