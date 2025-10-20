/**
 * @date 2025/10/20
 * @author 2mu
 * @brief easy 执行操作后的变量值
 *
 * 1. 模拟
 * 非常简单。直接字符串比较判断操作是什么即可
 * 编程时还可以考虑下边界条件，比如说数字是否允许减为负数。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;


int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for(auto operation : operations)
    {
        if (operation.find("++") != std::string::npos)
        {
            ++x;
        }
        else if (operation.find("--") != std::string::npos)
        {
            --x;
        }
    }
    return x;
}


int main()
{
    std::vector<std::string> operations = {"--X", "X++", "X++"};
    std::cout << finalValueAfterOperations(operations) << std::endl;
    return 0;
}
