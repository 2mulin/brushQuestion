/**
 * @date 2024/5/1
 * @author 2mu
 * @brief medium 雇佣k位工人的总代价
 *
 * 1. 堆
 * 使用一个堆维护前condidates和后condidates个员工的雇佣代价, 然后依次从中选择最小的代价;
 * 每次雇佣之后, 该员工被删除, 然后需要重新整理前condidates和后condidates个员工, 让其入队
 * 我们可以知道删除员工是位于前段还是后段, 对应在前段或者后段添加新员工即可...
 * 
 * 但是堆排序不是稳定的, 怎么让下标小的元素排在前面呢?
 * 自定义比较方法即可, 比较的不是cost, 而是(cost, idx)二元组, 这样就可以保证;
 * 
 * 这里比较麻烦的就是堆的维护, 如果堆中有错误的元素入队, 就会导致答案错误...
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;


struct tuple_compare
{
public:
    // 小根堆
    bool operator() (const std::tuple<int, int>& left, const std::tuple<int, int>& right) const
    {
        int lvalue = std::get<0>(left), rvalue = std::get<0>(right);
        if(lvalue != rvalue)
            return lvalue > rvalue;
        else
            return std::get<1>(left) > std::get<1>(right);
    }
};


long long totalCost(vector<int> &costs, int k, int candidates)
{
    std::priority_queue<std::tuple<int, int>, 
        std::vector<tuple<int, int> >, tuple_compare> heap;
    long long cost = 0;

    int left = 0;
    for(; left < candidates; ++left)
    {
        std::tuple<int, int> elem = std::make_tuple(costs[left], left);
        heap.push(elem);
    }
    int right = costs.size() - 1;
    // 注意这里的停止条件...
    for(; right >= costs.size() - candidates && left <= right; --right)
    {
        std::tuple<int, int> elem = std::make_tuple(costs[right], right);
        heap.push(elem);
    }
    while(k--)
    {
        std::tuple<int, int> elem = heap.top();
        heap.pop();
        cost += std::get<0>(elem);
        if(left > right)
            continue;
        if(std::get<1>(elem) < left)
        {
            std::tuple<int, int> elem = std::make_tuple(costs[left], left);
            heap.push(elem);
            ++left;
        }
        else
        {
            std::tuple<int, int> elem = std::make_tuple(costs[right], right);
            heap.push(elem);
            --right;
        }
    }
    return cost;
}

int main(int argc, char **argv)
{
    std::vector<int> costs{31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    int cost = totalCost(costs, 11, 2);
    // 423是正常答案
    std::cout << cost << std::endl;

    costs = {1,2,4,1};
    cost = totalCost(costs, 3, 3);
    std::cout << cost << std::endl;

    costs = {28,35,21,13,21,72,35,52,74,92,25,65,77,1,73,32,43,68,8,100,84,80,14,88,42,53,98,69,64,40,60,23,99,83,5,21,76,34};
    cost = totalCost(costs, 32, 12);
    std::cout << cost << std::endl;
    return 0;
}