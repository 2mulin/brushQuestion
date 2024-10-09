/*******************************************************************************
 * @author reddragon
 * @date 2020/8/24
 * @brief medium 字符串相乘
 * 首先最简单的思路就是模拟乘法运算。
 * 时间O(mn + nn)   空间O(m + n)
 * 
 * 我看完题解只有牛逼可说，这就是数学问题，看评论说是什么卷积。反正我是不懂
 * 
 * 大致思路就是num1和num2的每一个数字两两组合相乘，加到ansArr[i + j + 1]中
 * 最后统一进位，使得ansArr的每一个元素值都是>=0且<10, 再复制到string中。
 * 时间O(mn)        空间O(2mn)
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    int m = num1.size(), n = num2.size();
    vector<int> ansArr(m + n);
    for (int i = m - 1; i >= 0; i--) {
        int x = num1[i] - '0';
        for (int j = n - 1; j >= 0; j--) {
            int y = num2[j] - '0';
            ansArr[i + j + 1] += x * y;// 加等于
        }
    }
    // 统一进位，全部变成0 <= ans[i] < 10
    for (int i = m + n - 1; i > 0; i--) {
        ansArr[i - 1] += ansArr[i] / 10;
        ansArr[i] %= 10;
    }
    // num1 和 num2的乘积的长度是 m+n-1 或者 m+n。显然我证明不出来
    int index = ansArr[0] == 0 ? 1 : 0;
    // 变成string
    string ans;
    while (index < m + n) {
        ans.push_back(ansArr[index] + '0');
        index++;
    }
    return ans;
}


int main()
{
    string num1 = "1111";
    string num2 = "1000";
    cout << multiply(num1,num2) << endl;
    return 0;
}