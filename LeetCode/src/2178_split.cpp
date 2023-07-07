/**
 * @date 2023/7/7
 * @author 2mu
 * @brief medium 拆分成最多数目的正偶数
 *
 * 1. 贪心
 * 需要数目最多, 理所当然的就是每次拆分出来的偶数越小; 拆分出来的偶数又不允许重复, 所以说从2开始累增即可;
 * 直到finalSum已经不能再拆分非重复的偶数出来了; 此时直接将未拆分完的finalSum加到最后一个拆分过的偶数上(保证不重复)
 * 就完成了;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<long long> maximumEvenSplit(long long finalSum)
{
    std::vector<long long> ans;
    if(finalSum % 2)
        return ans;
    for(int i = 2; i <= finalSum; i += 2)
    {
        ans.push_back(i);
        finalSum -= i;
    }
    if(!ans.empty())
        ans.back() += finalSum;
    else
        ans.push_back(finalSum);
    return ans;
}

void Print(std::vector<long long> vctNums)
{
    for(auto num : vctNums)
        std::cout << num << '\t';
    std::cout << std::endl;
}

int main()
{
    std::vector<long long> ans = maximumEvenSplit(12);
    Print(ans);

    ans = maximumEvenSplit(2);
    Print(ans);

    ans = maximumEvenSplit(28);
    Print(ans);
    return 0;
}