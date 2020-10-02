/********************************************************************************************
 * @author reddragon
 * @date 2020/10/2
 * @brief medium 单词接龙
 * 
 * 真就刷了一天。。。。碰到很多奇怪的错误，比如访问悬空指针（map::erase调用之后还想使用map::at返回的value引用），
 * 深搜一直没找到错误在哪，只有asan内存检测工具说内存泄漏，实际run，并没有问题
 * 
 * 1. 深搜
 * 从begin尝试每一种变换，知道end或者无法变化，最后比较每一种情况需要变化的次数，结果超时了
 * 时间复杂度：O(N*M*L) N为string个数，M为string长度，L为递归层数
 * 
 * 2. 广搜
 * 这题还是非常适合广搜的，可以先将所有的单词，可以相互转换的单词连起来，
 * 就会发现就是一个无向无环图（可能有环），一层一层的搜就可以了，最先到达end就是答案。
 * 把访问过的元素直接删除，因为不可能走重复的路，走重复的路一定不是最优解
 * 时间复杂度：O(M*N)M是单词个数，N是单词长度。     空间复杂度：O(N*M)存放所有的单词
 * 
 * 官方题解还有  双向广搜，从begin和end向中间进行搜索，一旦两个重逢，说明结束了
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_map<string, list<string>> m;
    int L = beginWord.size();
    // O(N*M)
    for(auto str : wordList)
    {
        // 若单词长度为L，则有L种通用格式
        for(int i = 0; i < L; i++)
        {
            string format = str;
            format[i] = '*';// 通用格式
            if(m.find(format) == m.end())
                m.insert(pair<string, list<string>>(format,list<string>()));
            m[format].push_back(str);// 将此单词插入到通用格式中
        }
    }

    // 广搜
    int minCount = 0;
    bool isFound = false;
    queue<string> qu;
    qu.push(beginWord);
    while(!qu.empty())
    {
        int length = qu.size();// 每一层的元素个数
        for(int i = 0; i < length; i++)
        {
            string frontStr = qu.front();
            qu.pop();
            if(frontStr == endWord)
                isFound = true;
            // 向队列中添加所有可以转换的元素
            for(size_t j = 0; j < frontStr.length(); j++)
            {
                string temp = frontStr;
                temp[j] = '*';
                try
                {
                    list<string>& ls = m.at(temp);
                    for(auto it = ls.begin(); it != ls.end(); it++)
                        qu.push(*it);
                    m.erase(temp);// 删除使用过的元素，避免没有答案时的死循环
                }
                catch(const std::exception& e)
                {
                    // 什么都不用干，主要是为了接收m.at(temp)调用失败时返回的out_of_range异常
                    continue;
                }
            }
        }
        minCount++;
        if(isFound)
            break;
    }
    // 判断一下是找到了最后的答案，还是没有答案退出循环了
    if(isFound)
        return minCount;
    else
        return 0;
}

int main()
{
    vector<string> wordList{"hot","dot","dog","lot","log", "cog"};
    cout << ladderLength("hit", "cog", wordList) << endl;
    return 0;
}