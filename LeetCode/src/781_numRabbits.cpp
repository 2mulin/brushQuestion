/********************************************************************************************
 * @author reddragon
 * @date 2021/4/4
 * @brief medium 森林中的兔子
 * 
 * 1，辅助数组
 * 利用一个辅助数组记录下来 兔子个数i 的出现次数. 如果i出现次数大于i+1, 那么
 * 可能有多个群体, 都是 同一个颜色且数量都是i+1 .所以要注意这个群体的计算
 * 时间复杂度: O(N)        空间复杂度: O(1000)
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numRabbits(vector<int> &answers)
{
    // 哈希
    if (answers.size() == 0)
        return 0;
    vector<int> vec(1000, 0);
    int ans = 0;
    for (auto num : answers)
    {
        if (num == 0)
            ++ans; // 该兔子只有一只
        else
            ++vec[num];
    }
    for (int i = 1; i < 1000; ++i)
    {
        if (vec[i] != 0 && vec[i] <= i + 1)
            ans += (i + 1);
        else
        {
            // 几倍,说明不止一种颜色, 但它们都是i+1只兔子
            int tmp = vec[i] / (i + 1);
            if (vec[i] % (i + 1))
                ++tmp; // 向上取整
            ans += (tmp * (i + 1));
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{0,0,0,1,1};
    cout << numRabbits(arr) << endl;
    return 0;
}