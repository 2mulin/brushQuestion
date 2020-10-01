/********************************************************************************************
 * @author reddragon
 * @date 2020/9/25
 * @brief medium 单词接龙
 * 
 * 1.深搜：堆栈爆了
 ********************************************************************************************/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// 题目保证字符串一定相等
bool cmp(string s1, string s2)
{
    int num = 0;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] != s2[i])
            num++;
    }
    if(num == 1)
        return true;
    return false;
}

int dfs(string begin,string end, unordered_set<string> wordList)
{
    int minCount = INT_MAX;

    if(begin == end)
        return 1;

    // 转换
    for(auto i : wordList)
    {
        if(cmp(i, begin))
        {
            wordList.erase(i);// 避免dfs死循环
            int ret = dfs(i, end, wordList);
            // 不能转换，返回INT_MAX
            if(ret == INT_MAX)
                return INT_MAX;
            else
                minCount = min(ret + 1, minCount);
            wordList.insert(i);
        }
    }
    
    return minCount;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    // 哈希表加快查找
    unordered_set<string> hashtable;
    for(int i = 0; i < wordList.size(); i++)
        hashtable.insert(wordList[i]);
    // 深搜
    int ret = dfs(beginWord, endWord, hashtable);
    if(ret == INT_MAX)
        return 0;
    return ret;
}

int main()
{
    vector<string> wordList{"hot","dot","dog","lot","log", "cog"};
    cout << ladderLength("hit", "cog", wordList) << endl;
    return 0;
}