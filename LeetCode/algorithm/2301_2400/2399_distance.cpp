/**
 * @date 2023/4/9
 * @author 2mu
 * @brief easy
 *
 * 1. 哈希表
 * 记录每个字符出现过的第一个位置和第二个位置; 然后两个位置计算diff, 最后和distance数组进行比较, 全部相等表示合法;
 * 时间复杂度是O(n), 只需要遍历一遍字符串就行, 由于s长度小于52, 实际开销可以认为是O(1)
 *  
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct st_position
{
    short first;   // 第一次出现的位置
    short second;  // 第二次出现的位置

public:
    st_position()
    {
        first = -1;
        second = -1;
    }
    ~st_position() = default;
};

bool checkDistances(string s, vector<int> &distance)
{
    std::unordered_map<char, st_position> mapCharPosititon;
    for(size_t i = 0; i < s.length(); ++i)
    {
        char ch = s[i];
        if(mapCharPosititon[ch].first == -1)
        {
            mapCharPosititon[ch].first = i;
        }
        else
        {
            mapCharPosititon[ch].second = i;
            int diff = mapCharPosititon[ch].second - mapCharPosititon[ch].first - 1;
            if(diff != distance[ch - 'a'])
                return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::cout << checkDistances("abaccb", distance) << std::endl;
    return 0;
}