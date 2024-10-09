/**
 * @date 2023/5/14
 * @author 2mu
 * @brief 距离相等的条形码
 *
 * 1. 最大堆
 * 由于题目保证一定有答案, 所以只有出现次数最多的code尽量先使用, 最后就一定能成功; (至于为什么? 暂时没得到证明)
 * 就当作是heap的练习吧
 * 
 * 时间复杂度: O(nlogN)
 * 空间复杂度: O(nlogN)
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> rearrangeBarcodes(vector<int> &barcodes)
{
    std::unordered_map<int, int> maCodes; // code -> code出现次数
    for(auto code : barcodes)
    {
        ++maCodes[code];
    }

    // {code, count} 按照count进行堆排
    auto compare = [](const std::pair<int, int>& left, const std::pair<int, int>& right)->bool
    {
        return left.second < right.second;
    };
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int,int>>,
        decltype(compare)> heap(compare);
    for(auto iter : maCodes)
    {
        heap.push(iter);
    }

    std::vector<int> ans;
    while(!heap.empty())
    {
        std::pair<int, int> maxValue = heap.top();
        heap.pop();
        if(!ans.empty() && maxValue.first == ans.back())
        {
            std::pair<int, int> secondValue = heap.top();
            heap.pop();
            ans.push_back(secondValue.first);
            secondValue.second -= 1;
            if(secondValue.second > 0)
                heap.push(secondValue);
        }
        else
        {
            ans.push_back(maxValue.first);
            maxValue.second -= 1;
        }
        if(maxValue.second > 0)
            heap.push(maxValue);
    }
    return ans;
}

int main()
{
    std::vector<int> barcodes{1,1,1,1,2,2,3,3};
    std::vector<int> ans = rearrangeBarcodes(barcodes);
    for(auto val : ans)
    {
        std::cout << val << '\t';
    }
    std::cout << std::endl;
    return 0;
}