/**
 * @date 2022/7/11
 * @author 2mu
 * @brief medium 魔法字典
 *
 * 1. 暴力
 * 暴力也可以过，但是不建议。
 * 
 * 时间复杂度：O(N*N*N)
 * 空间复杂度：O(N)
 * 
 * 2. 字典树
 * 题解说能优化，我没看出哪里有效率上的优化。
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class MagicDictionary
{
public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        for(auto str : dictionary)
        {
            m_dict.insert(str);
        }
    }

    bool search(string searchWord)
    {
        for(int i = 0; i < searchWord.length(); ++i)
        {
            char oldChar = searchWord[i];
            std::string tmp  = searchWord;
            for(char ch = 'a'; ch <= 'z'; ++ch)
            {
                if(ch == oldChar)
                    continue;
                tmp[i] = ch;
                if(m_dict.find(tmp) != m_dict.end())
                    return true;
            }
        }
        return false;
    }

private:
    std::unordered_set<string> m_dict;
};

int main()
{
    return 0;
}
