/**
 * @date 2025/7/5
 * @author 2mu 
 * @brief easy 找出数组中的幸运数
 *
 * 1. 模拟
 * 还是比较简单，数字范围在500之内，所以可以直接使用500大小的数组统计一下各个数字出现次数。
 * 最后逆序遍历一遍就知道哪个数字出现次数和数字值相等。
 * 
 * 还可以使用map，这样空间复杂度会小一点，而且可以不那么考虑数字范围。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findLucky(vector<int> &arr)
{
    std::vector<int> count(501, 0);
    for(int i = 0; i < arr.size(); ++i)
    {
        ++count[arr[i]];
    }

    for(int i = 500; i > 0; --i)
    {
        if (count[i] == i)
            return i;
    }
    return -1;
}

int main()
{
    std::vector<int> arr{2,2,3,4};
    std::cout << findLucky(arr) << std::endl;
    return 0;
}
