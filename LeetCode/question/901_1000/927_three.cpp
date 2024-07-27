/**
 * @date 2022/10/6
 * @author 2mu
 * @brief 三等分 hard
 *
 * 一. 暴力
 * 暴力尝试每一种i，j的可能。且题目给了条件：i + 1 < j。
 * 可以直接将 arr 3等分，分成长度差为1的3个二进制数。然后判断是否合法。
 * 
 * 时间复杂度：O(n*n*n) , 大致来说，i和j各有n种可能，然后判断3个二进制数是否相等又需要n次判断。
 * 空间复杂度：O(1)
 * 
 * 二. 题解
 * 可以确定三等分二进制数中1的数量一定相等。0不相等，可能有前导0。
 * 先判断是否元素所有的1是否可以3等分，不可以的话，就无法等分。
 * 找到3等分之后，每个1的位置。最后一份的二进制是确定的，如果前面两部分二进制值，也是这个大小，说明没有问题。
 * 
 * 时间复杂度：O(n)，其中 n 是 arr 的长度。找到三个下标的时间复杂度为 O(n)，判断三个部分是否相同的时间复杂度也是 O(n)。
 * 空间复杂度：O(1)，只用到常数个变量空间。
 */

#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> threeEqualParts(std::vector<int> &arr)
{
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0) {
        return {-1, -1};
    }
    if (sum == 0) {
        return {0, 2};
    }

    int partial = sum / 3;
    int first = 0, second = 0, third = 0, cur = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            if (cur == 0) {
                first = i;
            }
            else if (cur == partial) {
                second = i;
            }
            else if (cur == 2 * partial) {
                third = i;
            }
            cur++;
        }
    }

    // 判断3部分二进制数是否相等
    int len = (int)arr.size() - third;
    if (first + len <= second && second + len <= third) {
        int i = 0;
        while (third + i < arr.size()) {
            if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i]) {
                return {-1, -1};
            }
            i++;
        }
        return {first + len - 1, second + len};
    }
    return {-1, -1};
}

int main()
{
    return 0;
}
