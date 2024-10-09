/**
 * @date 2022/8/6
 * @author 2mu
 * @brief easy 数组中的字符串匹配
 *
 * 1. KMP算法
 * 看到字符串匹配，都不用问，直接KMP算法。
 * 
 * 不过，KMP算法不好写，那么问题来了：干嘛不直接使用标准库的find函数，NICE，std牛逼。
 * 
 * KMP算法的时间复杂度是O(M + N)，如果使用KMP，时间复杂度会下降到O(N*N*N)
 * 
 * 时间复杂度：O(N*N*N*N)
 * 空间复杂度：O(N)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> stringMatching(vector<string> &words)
{
    std::sort(words.begin(), words.end(), [](const std::string& left, const std::string& right)
        {return left.length() < right.length();}
    );

    std::vector<std::string> ans;
    for(size_t i = 0; i < words.size() - 1; ++i)
    {
        for(size_t j = i + 1; j < words.size(); ++j)
        {
            if(words[j].find(words[i]) != std::string::npos)
            {
                ans.push_back(words[i]);
                break;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}
