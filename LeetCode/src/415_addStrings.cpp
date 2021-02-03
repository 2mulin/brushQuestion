/*******************************************************************************
 * @author reddragon
 * @date 2020/8/23
 * @brief easy 字符串相加
 * 首先要知道ans长度最长都达不到num1和num2长度之和。差好远。
 * 然后，只要保留一个进位标志就OK了，一趟for就做完了，最后去除前面多余的0
 * 有进位标志，两数相加就多加1
 * 时间复杂度：O(N)   空间复杂度：O(N)
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    size_t len1 = num1.length();
    size_t len2 = num2.length();
    string ans(len1 + len2, '0');

    int pos1 = len1 -1 , pos2 = len2 - 1;
    int pos = len1 + len2 - 1;
    int add = 0;//进位标志
    while(pos >= 0)
    {
        int n = 0;

        if(pos1 >= 0 && pos2 >= 0)
            n = num1[pos1--] - '0' + num2[pos2--] - '0' + add;
        else if(pos1 >= 0)
            n = num1[pos1--] - '0' + add;
        else if(pos2 >= 0)
            n = num2[pos2--] - '0' + add;
        else
            break;
        if(n > 10)
            add = 1;
        ans[pos--] += n % 10;
    }
    pos = 0;
    while(ans[pos] == '0')
    {
        pos++;
        if(pos >= ans.size())
            return "0";
    }
    return ans.substr(pos);
}

/*******************************************************
 * 字符串相加。这里是利用arr数组直接每两个对应数字相加。
 * 最后统一进位。当然看完题解之后觉得自己是个sb
 * 时间复杂度：O(N)     空间复杂度：O(N)
*******************************************************/
// string addStrings(string num1, string num2) {
//     size_t len1 = num1.length();
//     size_t len2 = num2.length();
//     vector<int> arr(len1 + len2, 0);

//     int pos1 = len1 -1 , pos2 = len2 - 1;
//     int pos = len1 + len2 - 1;
//     while(pos >= 0)
//     {
//         if(pos1 >= 0 && pos2 >= 0)
//             arr[pos--] = num1[pos1--] - '0' + num2[pos2--] - '0';
//         else if(pos1 >= 0)
//             arr[pos--] = num1[pos1--] - '0';
//         else if(pos2 >= 0)
//             arr[pos--] = num2[pos2--] - '0';
//         else
//             break;
//     }
//     // 统一处理进位
//     for(int i = len1 + len2 - 1; i >= 0; i--)
//     {
//         if(arr[i] >=10)
//         {
//             arr[i - 1] += arr[i] / 10;
//             arr[i] %= 10;
//         }
//     }
//     pos = 0;
//     while(arr[pos] == 0)
//     {
//         pos++;
//         // 全0
//         if(pos >= arr.size())
//             return "0";
//     }
//     string ans(len1 + len2 - pos,'0');
//     for(size_t i = 0; i < ans.size(); i++)
//         ans[i] += arr[pos++];
//     return ans;
// }


int main()
{
    string num1 = "4654561321";
    string num2 = "6546512";
    cout << addStrings(num1,num2) << endl;
    return 0;
}