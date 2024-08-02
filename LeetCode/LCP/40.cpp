/**
 * @date 2024/8/2
 * @author 2mu
 * @brief easy 心算挑战
 *
 * 1. 排序
 * 创建两个小顶堆, 都限制大小为cnt; 然后遍历整个cards数组;
 * 分别用小顶堆找到前cnt大的奇数元素, 和前cnt大的偶数元素;
 * 
 * 最后结果肯定就是两个堆中合起来的 cnt 个元素;
 * 
 * 该方法不太行, 用堆还不如用官方题解的直接排序...利用一些贪心的思想;
 * 排序之后先使用最大的cnt加起来为sum; 然后判断sum是否是偶数, 如果不是,
 * 那就有两种情况:
 * 1. 去掉sum中的一个最小奇数, 然后加上一个不在sum中的最大偶然; 重新sum
 * 2. 去掉sum中的一个最小偶数, 然后加上一个不在sum中的最大奇数; 重新sum
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxmiumScore(vector<int> &cards, int cnt)
{
    std::sort(cards.begin(), cards.end(), std::greater<int>());
    int sum = 0;
    int min_odd_number = INT_MAX, min_even_number = INT_MAX;
    int max_odd_number = INT_MIN, max_even_number = INT_MIN;
    int i = 0;
    for(i = 0; i < cnt; ++i)
    {
        sum += cards[i];
        if( cards[i] % 2)
        {
            min_odd_number = std::min(min_odd_number, cards[i]);
        }
        else
        {
            min_even_number = std::min(min_even_number, cards[i]);
        }
    }
    if (sum % 2 == 0)
        return sum;// 已经是最大的偶数, 直接返回
    else
    {
        for(; i < cards.size(); ++i)
        {
            if(cards[i] % 2)
            {
                if(max_odd_number == INT_MIN)
                    max_odd_number = cards[i];
            }
            else
            {
                if(max_even_number == INT_MIN)
                    max_even_number = cards[i];
            }
            if(max_odd_number != INT_MIN && max_even_number != INT_MIN)
                break;
        }
    }

    int ans1 = 0, ans2 = 0;
    // 可能没有答案; 比如数组中5个奇数, cnt等于3; 这就没有答案;
    if(min_odd_number != INT_MAX && max_even_number != INT_MIN)
    {
        ans1 = sum - min_odd_number + max_even_number;
    }
    if(min_even_number != INT_MAX && max_odd_number != INT_MIN)
    {
        ans2 = sum - min_even_number + max_odd_number;
    }
    sum = std::max(ans1, ans2);
    return sum;
}

int main(int argc, char **argv)
{
    std::vector<int> cards{7, 6, 4, 6};
    std::cout << maxmiumScore(cards, 1) << std::endl;
    return 0;
}

