/********************************************************************************************
 * @author reddragon
 * @date 2020/10/8
 * @brief hard 
 * 
 * 汉诺塔值得再刷一次，典型的递归，先将上面n-1个盘子啊放到中转站mid，再第n个盘子，也就是最下面的那个盘子
 * 放到目标dst去，然后再把在mid的n-1个盘子放到目标，把刚被搬空的src当作中转站
 ********************************************************************************************/
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

void hanoi(int n, char src, char mid, char dst)
{
    if(n == 1)
    {
        cout << src << "-->" << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, mid);// 先将除了最后一个盘子之外的，上面n-1个盘子从src移动到mid

    cout << src << "-->" << dst << endl;// 只剩下最下面一个放到dst去

    // 进入下一步递归
    hanoi(n - 1, mid, src, dst);// 最下面一个放过去了，现在只要将n-1盘子从mid移动到dst就OK了
    return;
}

int main()
{
    hanoi(3, 'A', 'B', 'C');
    return 0;
}