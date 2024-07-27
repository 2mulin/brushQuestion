/**
 * @author ling
 * @date 2021/3/24
 * @brief easy 图片平滑器
 *
 * 1. 枚举
 * 按照规则，扫描9个格子的所有值，最终求平均值。有个小技巧就是外面补一卷0，
 * 然后定义一个方向数组，这样就可以少些很多的if，else条件判断代码。
 * 时间复杂度：O(9MN)          空间复杂度: O(MN)
 */

#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    int row = img.size(), col = img[0].size();
    // 补一圈0
    vector<vector<int>> arr(row + 2, vector<int>(col + 2, 0));

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            arr[i + 1][j + 1] = img[i][j];
        }
    }

    std::vector<std::vector<int>> dir{
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    std::vector<std::vector<int>> ans(row, std::vector<int>(col, 0));

    for (int i = 1; i < row + 1; ++i)
    {
        for (int j = 1; j < col + 1; ++j)
        {
            int sum = arr[i][j], count = 1;
            for (auto d : dir)
            {
                int x = i + d[0], y = j + d[1];
                if(x == 0 || y == 0 || x == row + 1 || y == col + 1)
                    continue;
                sum += arr[x][y];
                ++count;
            }
            ans[i - 1][j - 1] = sum / count;
        }
    }

    return ans;
}

int main()
{
    std::vector<std::vector<int>> arr{
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100}
    };

    auto ans = imageSmoother(arr);

    for(auto vct : ans)
    {
        for(auto num : vct)
            std::cout << num << '\t';
        std::cout << std::endl;
    }
    return 0;
}