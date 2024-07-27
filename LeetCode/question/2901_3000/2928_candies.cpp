/**
 * @date 2024/6/1
 * @author 2mu
 * @brief easy 给小朋友分糖果
 *
 * 1. 枚举
 * 题目给出的范围比较小, 糖果数量小于等于50, 小朋友数量只有3;
 * 这里题目没说清楚, 糖果一定要全部分出去, 所以{0,0,0}这种方案是不允许的;
 * 所以可以直接使用枚举;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>


using namespace std;


int distributeCandies(int n, int limit)
{
    int count = 0;
    for(int a = 0; a <= limit; ++a)
    {
        for(int b = 0; b <= limit; ++b)
        {
            // 只要a,b确认, c就已经固定
            int c = n - a - b;
            if(0 <= c && c <= limit)
                ++count;
        }
    }
    return count;
}


int main(int argc, char **argv)
{
    std::cout << distributeCandies(5, 2) << std::endl;
    std::cout << distributeCandies(3, 3) << std::endl;
    return 0;
}
