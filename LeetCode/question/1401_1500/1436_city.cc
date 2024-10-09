/**
 * @date 2024/10/9
 * @author 2mu
 * @brief easy 旅行终点站
 *
 * 1. 哈希表
 * 
 * 利用哈希表将所有path都存储起来，查找终点时，查询哈希表可以加快查找速度。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string destCity(vector<vector<string>> &paths)
{
    std::unordered_map<std::string, std::string> hashmap;
    for(const vector<string>& path : paths)
    {
        hashmap.insert({path[0], path[1]});
    }
    // 找到终点, 由于并不知道哪个值是起点，所以只能遍历paths进行寻找。
    // 终点一定不会出现在hashmap的key
    for(const vector<string>& path : paths)
    {
        if(hashmap.find(path[1]) == hashmap.end())
        {
            return path[1];
        }
    }
    return "";
}

int main(int argc, char **argv)
{
    std::vector<std::vector<std::string>> paths{ {"B", "C"}, {"D", "B"}, {"C", "A"}};
    std::cout << destCity(paths) << std::endl;
    return 0;
}
