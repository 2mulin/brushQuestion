/**
 * @date 2025/7/19
 * @author 2mu
 * @brief medium 删除子文件夹
 *
 * 1. 暴力
 * 先将数组排序。
 *
 * 然后直接双层循环，判断每两个字符串是否是子文件夹，如果是就过滤掉该子文件夹。
 * 否则加入到结果数组中。
 *
 * 时间复杂度：O(n的3次方)
 * 空间复杂度：O(1)
 *
 * 2. 排序
 * 仔细想想，排序之后直接就让子文件夹待在父文件夹后，都比较好遍历了。
 *
 * 时间复杂度：O(n*nlogn)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> removeSubfolders(vector<string> &folder)
{
    std::sort(folder.begin(), folder.end());

    std::vector<std::string> result;
    std::string prevStr = folder.front();
    result.push_back(prevStr);
    for(int i = 1; i < folder.size(); ++i)
    {
        if(folder[i].find(prevStr) == 0 && folder[i][prevStr.length()] == '/')
            continue;
        else
        {
            prevStr = folder[i];
            result.push_back(prevStr);
        }
    }
    return result;
}

int main()
{
    std::vector<std::string> folder{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    std::vector<std::string> result = removeSubfolders(folder);
    for(auto str : result)
        std::cout << str << std::endl;
    return 0;
}
