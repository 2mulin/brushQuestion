/**
 * @date 2024/10/4
 * @author 2mu 
 * @brief medium 飞机座位分配概率
 * 
 * 1. 数学
 * 很明显是数学题，第n个乘员的固定位置都有两种情况，一种是被占用，一种是没被占用。
 * 实际推理过程很复杂：
 * 用f(n)表示第n个乘员坐到准确位置的概率：
 * 
 * 当n=1时，只有 1 位乘客和 1 个座位，因此第1位乘客只能坐在第1个座位上(位置坐对了)，f(1)=1
 * 当n=2时，当 n=2 时，有 2 个座位，每个座位有 0.5 的概率被第 1 位乘客选中，当第 1 位乘客选中座位之后，
 * 第 2 位乘客只能选择剩下的座位，因此第 2 位乘客有 0.5 的概率坐在自己的座位上，f(2)=0.5。
 * 
 * 当n>2时，情况就比较复杂了，有三种情况：
 * 1. 第1位乘客有1/n 的概率选择第1个座位，则所有乘客都可以坐在自己的座位上，此时第n位乘客坐在自己的座位上的概率是 1.0。
 * 2. 第1位乘客有1/n 的概率选择第n个座位，则第[2, n−1]位乘客都可以坐在自己的座位上，第n位乘客只能坐在第1个座位上，此时第n位乘客坐在自己的座位上的概率是0
 * 3. 除以上两种情况外，第1位乘客有n−2/n的概率选择其余的座位，每个座位被选中的概率是1/n。
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

double nthPersonGetsNthSeat(int n)
{
    double result = 1;
    if (n == 1)
        return result;
    return result / 2;
}

int main()
{
    std::cout << nthPersonGetsNthSeat(1) << std::endl;
    std::cout << nthPersonGetsNthSeat(2) << std::endl;
    return 0;
}
