/**
 * @date 2023/5/15
 * @author 2mu
 * @brief medium 计算矩阵中有多少本质相同的行
 *
 * 1. 哈希
 * 
 * 题目描述感觉是故意偏离 解决方案; 完全不需要管反转哪些列;
 * 实际上是反转行更加容易解决, 反转行之后相等, 相当于反转列之后相等;
 * 
 * 然后每行开头要么是1, 要么是0; 所以只要统一为一种, 然后计算matrix中有多少相等的行;
 * 这就是最终答案;
 * 
 * 时间复杂度: O(m*n)
 * 空间复杂度: O(m*n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
{
    // 矩阵行 -> 出现次数
    std::unordered_map<std::string, int> ma;
    for(auto tmpVct : matrix)
    {
        std::string strLine(tmpVct.size(), '0');
        for(int i = 0; i < tmpVct.size(); ++i)
        {
            // 如果开头为0, 直接反转这一行
            if(tmpVct.front() == 0)
                strLine[i] += !tmpVct[i];
            else
                strLine[i] += tmpVct[i];
        }
        ++ma[strLine];
    }
    int ans = 1;
    for(auto iter = ma.begin(); iter != ma.end(); ++iter)
    {
        ans = max(iter->second, ans);
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix{
        {0,0,0},
        {0,0,1},
        {1,1,0}
    };

    std::cout << maxEqualRowsAfterFlips(matrix) << std::endl;
    return 0;
}