/**
 * @date 2022/2/24
 * @author 2mu
 * @brief easy 使数组中所有元素等于0
 *
 * 一、计数排序
 * 需要先排序，然后去重，因为相同数字，在同一次操作中就会被减为0，所以算一次
 * 由于条件中数字比较小，所以直接计数排序最快。
 * 
 * 然后记录非0且非负整数出现的次数。由于题目意思是，按照步骤操作，一定会有答案，
 * 所以，结果就是去重后，非负整数出现次数。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minimumOperations(vector<int> &nums)
{
    int ma[101] = {0};
    for(auto num : nums)
        ma[num] = 1;

    int sum = 0, count = 0, maxVal = 0;
    for(int i = 1; i < 101; ++i)
    {
        if(ma[i])
        {
            maxVal = i;
            sum += i;
            ++count;
        }
    }
    return count;
}

int main()
{
    std::vector<int> arr{1, 2, 3, 5};
    std::cout << minimumOperations(arr) << std::endl;
    arr = {0};
    std::cout << minimumOperations(arr) << std::endl;
    return 0;
}
