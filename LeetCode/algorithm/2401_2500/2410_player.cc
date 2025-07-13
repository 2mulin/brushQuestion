/**
 * @date 2025/7/13
 * @author 2mu 
 * @brief medium 运动员和训练师的最大匹配数
 * 
 * 1. 贪心+排序
 * 要想匹配数量越大，就需要队员的能力值和训练师的能力值越接近。
 * 所以可以先对两个数组进行排序，然后遍历数组，从最接近的能力值开始匹配。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
{
    std::sort(players.begin(), players.end());
    std::sort(trainers.begin(), trainers.end());

    int count = 0;
    int pos = 0;
    for(int i = 0; i < players.size(); ++i)
    {
        if (pos >= trainers.size())
            break;
        if (players[i] <= trainers[pos])
        {
            count++;
            pos++;
        }
        else
        {
            pos++;
            --i;
        }
    }
    return count;
}


int main()
{
    std::vector<int> players{4, 7, 9};
    std::vector<int> trainers{8, 2, 5, 8};
    std::cout << matchPlayersAndTrainers(players, trainers) << std::endl;
    return 0;
}
