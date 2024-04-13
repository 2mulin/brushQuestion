/**
 * @date 2023/4/13
 * @author 2mu
 * @brief easy 找到冠军
 *
 * 1. 遍历
 * 由于题目已经给出了规则, 仔细看就可以发现可能得到冠军的人就是 0~n 中某一个队伍;
 * 这个队伍获胜次数最多, 直接使用数组, 大小为n, 记录每个队伍取胜的次数;
 * 然后遍历一次该数组, 得到取胜次数最大的队伍;
 * 
 * 注意i==j的时候是统一队伍, 不需要比较; 比较也没关系, 每个队伍都会加一次胜场数;
 * 同样 grid[i][j] 和 grid[j][i] 也是等价的, 没必要比较, 但是比较了也不影响结果;
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 * 
 * 2. 官方题解: 每行求和
 * 由于题目给出的条件, 强弱关系具有传递性, 也就是 a > b , b > c则 a > c;
 * 这就说明冠军比其它所有队伍都强, 得分一定是n-1;
 * 
 * 所以直接对每行求和, 当i行的和为 n - 1时, 说i就是冠军; 时间复杂度相同, 但是思路更加清晰, 代码更短;
 * 
 * 时间复杂度: O(n*n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;


int findChampion(vector<vector<int>> &grid)
{
    int n = grid.size();
    std::vector<int> vct(n, 0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == j)
                continue;

            if(grid[i][j] == 1)
                vct[i]++;
            else
                vct[j]++;
        }
    }

    int champion = 0;
    for(int i = 1; i < n; ++i)
    {
        if(vct[i] > vct[champion])
            champion = i;
    }
    return champion;
}

int main(int argc, char **argv)
{
    return 0;
}