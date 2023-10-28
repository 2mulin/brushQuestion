/**
 * @date 2023/10/28
 * @author 2mu
 * @brief easy 从数量最多的堆中取走礼物
 * 
 * 1. 利用堆
 * 
 * 首先建立大根堆, 然后按照规则每次取出最大值, 求平方根, 再存回到堆中;
 * 
 * 弗洛伊德建堆过程最低 O(n), 复杂度证明过程可以搜索下, 然后堆的删除和插入都是O(logn), 执行k次, 总时间复杂度是: O(k logn)
 *  
 * 时间复杂度: O(n + klogn)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    std::priority_queue<int> heap(gifts.begin(), gifts.end());
    while(k--)
    {
        int num = heap.top();
        heap.pop();
        num = std::sqrt(num);
        heap.push(num);
    }
    long long sum = 0;
    while(!heap.empty())
    {
        sum += heap.top();
        heap.pop();
    }
    return sum;
}

int main()
{
    std::vector<int> gifts{25, 64, 9, 4, 100};
    std::cout << pickGifts(gifts, 4) << std::endl;
    return 0;
}
