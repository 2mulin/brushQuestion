/**
 * @date 2023/7/12
 * @author 2mu
 * @brief easy 交替数字和
 *
 * 1. 模拟
 * 按照条件模拟即可, 由于需要计算正负号, 所以使用了一个queue记录数字每一位的数字;
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <stack>

using namespace std;

// 我的写法浪费空间, 还是官方题解好
// int alternateDigitSum(int n)
// {
//     std::stack<int> st;
//     while(n)
//     {
//         st.push(n % 10);
//         n /= 10;
//     }

//     int sum = 0;
//     bool isNeg = false;
//     while(!st.empty())
//     {
//         int num = st.top();
//         st.pop();
//         if(isNeg)
//             sum = sum - num;
//         else
//             sum = sum + num;
//         isNeg = !isNeg;
//     }
//     return sum;
// }

int alternateDigitSum(int n)
{
    int sum = 0;
    int neg = 1;
    while(n)
    {
        sum = sum + neg * (n % 10);
        neg = -neg;
        n /= 10;
    }
    return sum * (-neg);
}

int main()
{
    std::cout << alternateDigitSum(521) << std::endl;
    std::cout << alternateDigitSum(111) << std::endl;
    std::cout << alternateDigitSum(886996) << std::endl;
    return 0;
}