/**
 * @date 2022/6/17
 * @author 2mu
 * @brief easy 复写零
 *
 * 1. 备份一个数组
 * 要求将数组中出现的0复制一个，然后其它数右移，末尾的数就没了。
 * 
 * 备份一个数组，然后按照要求完成，最后删除多余的元素。
 * 
 * 时间复杂度：O(N)
 * 空间复杂度：O(N)
 * 
 * 2. 原地
 * 题目要求就是原地。想到了双指针，却想不到双指针还能模拟stack。
 * 
 * 时间复杂度: O(N)
 * 空间复杂度：O(1)
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

/* // 最容易想到的方式
void duplicateZeros(vector<int> &arr)
{
    std::vector<int> res;
    for(auto num : arr)
    {
        res.push_back(num);
        if(num == 0)
            res.push_back(0);
    }
    res.resize(arr.size());
    arr = res;
}
*/

void duplicateZeros(vector<int> &arr)
{
    // 双指针模拟栈
}

int main()
{
    std::vector<int> arr{1,0,2,3,0,4,5,0};
    duplicateZeros(arr);
    for(auto num : arr)
        std::cout << num << '\t';
    std::cout << std::endl;
    return 0;
}
