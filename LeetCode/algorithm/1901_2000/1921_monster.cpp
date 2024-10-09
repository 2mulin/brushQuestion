/**
 * @date 2023/9/3
 * @author 2mu
 * @brief medium 消灭怪物的最大数量
 *
 * 1. 模拟
 * 就直接使用dist模拟, 每隔一秒就干掉数组中第一个元素, 并且所有元素按照速度向前移动
 * 这样写有两重for循环, 并且处于后面位置的怪物由于移动速度快, 可能会插入到前面的位置;
 * 位置的插入时间复杂度是O(n), 所以总的时间复杂度是 n的3次方
 * 
 * 注意: 该武器可以击杀处于任何位置的怪物... 这个条件的处理很蛋疼; 压根处理不了
 * 
 * 时间复杂度: O(n*n*n)
 * 空间复杂度: O(n)
 * 
 * 2. 贪心
 * 
 * 完全换了个思路: 按照怪物到来时间, 先消灭先到的怪物; 这样就可以保证尽可能消灭多的怪物;
 * 所以计算怪物到达时间点, 然后排序, 然后依次击杀这些怪物即可
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int eliminateMaximum(vector<int> &dist, vector<int> &speed)
{
    int n = dist.size();
    vector<int> arrivalTimes(n);
    for (int i = 0; i < n; i++)
    {
        arrivalTimes[i] = (dist[i] - 1) / speed[i] + 1;
    }
    sort(arrivalTimes.begin(), arrivalTimes.end());
    for (int i = 0; i < n; i++)
    {
        if (arrivalTimes[i] <= i)
        {
            return i;
        }
    }
    return n;
}

/*
改代码无法通过

int eliminateMaximum(vector<int> &dist, vector<int> &speed)
{
    int cnt = 0;

    // 各个位置怪物的速度, 怪物可能到达同一个位置
    std::multimap<int, int> mapPosToSpeed;
    for(int i = 0; i < dist.size(); ++i)
    {
        mapPosToSpeed.insert({dist[i], speed[i]});
    }

    while(!mapPosToSpeed.empty())
    {
        // 红黑树实现的multimap, 第一个元素位置就是最近的;
        if(mapPosToSpeed.begin()->first == 0)
        {
            break;
        }
        mapPosToSpeed.erase(mapPosToSpeed.begin());
        ++cnt;
        // 移动到新位置, map的key不能改变, 所以只能是新建一个map
        std::multimap<int, int> mapNewPos;
        for(auto iter = mapPosToSpeed.begin(); iter != mapPosToSpeed.end(); ++iter)
        {
            int newPos = iter->first - iter->second;
            if(newPos < 0)
                newPos = 0;
            mapNewPos.insert({newPos, iter->second});
        }
        mapPosToSpeed = mapNewPos;
    }
    return cnt;
}

*/

int main()
{
    std::vector<int> vct = {4,2,3};
    std::vector<int> speed = {2,1,1};
    std::cout << eliminateMaximum(vct, speed) << std::endl;
    return 0;
}
