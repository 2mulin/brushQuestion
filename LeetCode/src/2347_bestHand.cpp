/**
 * @date 2022/2/20
 * @author 2mu
 * @brief easy 最好手牌
 *
 * 一、模拟
 * 就5张牌，直接判断就完事了。不可能超时。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string bestHand(vector<int> &ranks, vector<char> &suits)
{
    bool Flush = true;
    for(int i = 0; i < suits.size() - 1; ++i)
    {
        if(suits[i] != suits[i + 1])
        {
            Flush = false;
            break;
        }
    }
    if(Flush)
        return "Flush";
    std::unordered_map<int, int> mapRanks;
    for(auto rank : ranks)
    {
        mapRanks[rank]++;
    }
    bool threePage = false, twoPair=false;
    for(auto iter = mapRanks.begin(); iter != mapRanks.end(); ++iter)
    {
        if(iter->second >= 3)
            threePage = true;
        else if(iter->second == 2)
            twoPair = true;
    }

    if(threePage)
        return "Three of a Kind";
    if(twoPair)
        return "Pair";
    return "High Card";
}

int main()
{
    return 0;
}
