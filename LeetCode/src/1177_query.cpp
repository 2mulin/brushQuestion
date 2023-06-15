/**
 * @date 2023/6/15
 * @author 2mu
 * @brief medium 构建回文串检测
 *
 * 1. 模拟
 * 按照要求, 如果子串可以构建成回文串, 字串长度为双数 k的值 >= 去掉重复字符的字串的长度/2
 * 字串长度为单数, 还可以减少一个
 * 否则就不可以; 超时了...
 * 
 * 时间复杂度: O(m*n)
 * 空间复杂度: O(m*n)
 * 
 * 2. 异或前缀和数组
 * 可以发现上一个方案慢的地方就是查询整个子串 单数出现次数的字符个数;
 * 官方题解使用异或前缀和来加速...
 * 
 * 时间复杂度: O(m + n)
 * 空间复杂度: O(m)
 */

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
{
    std::vector<bool> ans;
    if(s.empty())
        return ans;

    int n = s.size();
    // 字符总共有26个, 一个int有32位, 足够
    // prefixArr[n] 表示s前n个字符组成的字串 26字母出现次数是单数还是双数, 单数对应bit为1, 双数对应bit为0
    std::vector<int> prefixArr(n + 1, 0);
    for(size_t i = 0; i < s.length(); ++i)
    {
        prefixArr[i + 1] = prefixArr[i] ^ (1 << (s[i] - 'a'));
    }
    for(std::vector<int> query : queries)
    {
        int num = prefixArr[query[1] + 1] ^ prefixArr[query[0]]; // 很关键的点: s[query[0], query[1] + 1)组成的子串中 26字符是单数还是双数
        int cnt = 0;
        while(num)
        {
            if(num & 1)
                ++cnt;
            num >>= 1;
        }
        int len =  query[1] - query[0] + 1;
        // 这里还可以优化, 实际上最多可以满足子串 单数出现次数的字符 为 query[2] * 2 + 1 个, 以这个角度去判断更加方便;
        if(len % 2 && query[2] * 2 >= cnt - 1)
            ans.push_back(true);
        else if(len % 2 == 0 && query[2] * 2 >= cnt)
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}

vector<bool> canMakePaliQueries_v1(string s, vector<vector<int>> &queries)
{
    std::vector<bool> ans;
    for(std::vector<int> query : queries)
    {
        std::vector<int> flag(26, 0);
        for(size_t i = query[0]; i <= query[1]; ++i)
        {
            int idx = s[i] - 'a';
            flag[idx] ^= 1; // 每次异或
        }
        int cnt = std::accumulate(flag.begin(), flag.end(), 0);
        // 如果长度是单数, 只要 >= cnt - 1
        int len = query[1] - query[0] + 1;
        if(len % 2 && query[2] * 2 >= cnt - 1)
            ans.push_back(true);
        else if(query[2] * 2 >= cnt)
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}

int main()
{
    std::string s = "abcda";
    std::vector<std::vector<int>> queries{
        {3,3,0},
        {1,2,0},
        {0,3,1},
        {0,3,2},
        {0,4,1}
    };
    auto ans = canMakePaliQueries(s, queries);
    for(auto elem : ans)
        std::cout << elem << '\t';
    return 0;
}