/**
 * @date 2024/11/21
 * @author 2mu
 * @brief easy 矩阵中的蛇
 *
 * 1. 模拟
 * 向上或者向下则是-n和+n，向左和向右则是-1和+1
 * 然后模拟一下就可以了，非常简单。
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int finalPositionOfSnake(int n, vector<string> &commands)
{
    int pos = 0;
    for(auto command : commands)
    {
        if (command == "UP")
        {
            pos -= n;
        }
        else if(command == "RIGHT")
        {
            ++pos;
        }
        else if(command == "DOWN")
        {
            pos += n;
        }
        else if(command == "LEFT")
        {
            --pos;
        }
        else
        {
            // error
            return -1;
        }
    }
    return pos;
}

int main(int argc, char **argv)
{
    std::vector<std::string> commands = {"RIGHT", "DOWN"};
    std::cout << finalPositionOfSnake(2, commands) << std::endl;
    return 0;
}
