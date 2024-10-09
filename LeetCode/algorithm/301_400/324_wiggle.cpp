/**
 * @date 2022/6/28
 * @author 2mu
 * @brief medium 摆动排序II
 *
 * 1. 排序
 * 先将数组排序，接下来每次取最大值，最小值，按要求排序应该就可以了。(行不通，因为数字可能相等)
 * 
 * 分为两半，题解的数学推理挺长的。
 * 
 * 时间复杂度：O(N*logN)
 * 空间复杂度：O(N)
 * 
 * 2. 三向切分
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int> &nums)
{
    std::vector<int> tmp = nums;
    std::sort(tmp.begin(), tmp.end());

    int mid = (tmp.size()+1) / 2 - 1, high = tmp.size() - 1;
    for(size_t i = 0; i < tmp.size(); i += 2)
    {
        nums[i] = tmp[mid--];
        if(i+1 < tmp.size())
            nums[i+1] = tmp[high--];
    }
}

int main()
{
    std::vector<int> arr{1,3,2,2,3,1};
    wiggleSort(arr);
    for(auto num : arr)
        std::cout << num << '\t';
    std::cout << std::endl;

    arr = {1,5,1,1,6};
    wiggleSort(arr);
    for(auto num : arr)
        std::cout << num << '\t';
    std::cout << std::endl;

    return 0;
}
