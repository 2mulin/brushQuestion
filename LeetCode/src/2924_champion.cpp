/**
 * @date 2023/4/14
 * @author 2mu
 * @brief medium 找到冠军II
 *
 * 1. 遍历
 * 题目题意: a. 冠军就是没有人比他强(没输过), b. 只有一个冠军
 * 综合以上两个条件, 唯一冠军就是比其它所有人都要强, 否则没有;
 * 反映到有向图中, 即只有一个入度为0的元素;
 * 
 * 只需要遍历整个数组, 找到所有入度不为0的元素, 并判断是不是只有一个即可;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int findChampion(int n, vector<vector<int>> &edges)
{
    std::unordered_set<int> degree;
    for(int i = 0; i < n; ++i)
    {
        degree.insert(i);
    }

    for(const std::vector<int>& edge : edges)
    {
        if(degree.find(edge[1]) != degree.end())
            degree.erase(edge[1]);
    }
    if(degree.size() == 1)
        return *degree.begin();
    return -1;
}


int main(int argc, char **argv)
{
    return 0;
}