/********************************************************************************************
 * @author reddragon
 * @date 2020/10/3
 * @brief easy 数组中只出现过一次的数字
 * 
 * 1.异或
 * 利用异或的性质，0和任何一个数异或这个数本身，两个相同的数异或为0
 * 就是说数组中相同的数全部异或到一起的话，最后都会成为0，只有出现一次的那个数留下来了
********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(size_t i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}

int main()
{
    vector<int> arr{1,2,4,4,2};
    cout << singleNumber(arr) << endl;
    return 0;
}