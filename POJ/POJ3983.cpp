/********************************************************************************************
 * @author reddragon
 * @date 2020/10/30
 * @brief POJ3983 算24
 * 
 * 1. 递归
 * poj的测试很水，直接输出就OK了，但是那样没意义了
 * 题目意思是给四个数加减乘除后，答案等于4，就输出Yes，否则输出NO
 * 思路是每次递归解决最后两个数，将最后两个数，加减乘除都尝试一遍。看是否满足条件
 * 由于数字排列顺序影响最终结果，所以还要尝试所有的数字排列顺序。
 * 时间复杂度：O(48*24*8) 每层递归次数         空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::next_permutation;

bool foo(vector<double> arr)
{
    int len = arr.size();
    if(len == 1)
    {
        // 浮点数比较方法
        if(fabs(arr[0] - 24) < 1e-6)
            return true;
        else
            return false;        
    }
    std::sort(arr.begin(), arr.end()));
    // 每两个数字的组合都要试一遍
    do
    {
        // 加减乘除都要试一遍5
        vector<double> b(len - 1);
        for(int i = 0; i < len - 1; i++)
            b[i] = arr[i];

        // 加法
        b[len - 2] = arr[len - 1] + arr[len - 2];
        if(foo(b))
            return true;

        // 减法：两个位置不一样会得到不一样的答案
        b[len - 2] = arr[len - 1] - arr[len - 2];
        if(foo(b))
            return true;
        b[len - 2] = arr[len - 2] - arr[len - 1];
        if(foo(b))
            return true;

        // 乘法
        b[len - 2] = arr[len - 1] * arr[len - 2];
        if(foo(b))
            return true;
            
        // 除法：两个位置不一样会得到不一样的答案
        if(fabs(arr[len - 2]) > 1e-6)
        {
            b[len - 2] = arr[len - 1] / arr[len - 2];
            if(foo(b))
                return true;
        }
        if(fabs(arr[len - 1]) > 1e-6)
        {
            b[len - 2] = arr[len - 2] / arr[len - 1];
            if(foo(b))
                return true;
        }
    }while(next_permutation(arr.begin(), arr.end()));
    return false;
}

int main()
{
    vector<double> arr(4);
    while(1)
    {
        for(int i = 0; i < 4; i++)
            cin >> arr[i];
        if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == 0)
            break;
        if(foo(arr))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}