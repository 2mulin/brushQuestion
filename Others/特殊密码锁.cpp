/********************************************************************************************
 * @author reddragon
 * @date 2020/10/6
 * @brief hard 特殊密码锁
 * http://cxsjsxmooc.openjudge.cn/2020t2fallall2/001/
 * 
 * 1. 枚举
 * 首先：一个按钮不可能按下两次以上，2次相当于没按，3次相当于按1次
 * 第二，确定第一个按钮之后就确定了第二个按钮,随着后面所有的按钮全部确定了。
 * 
 * 位运算可以减低空间复杂度：
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
    string src,dst;
    while(cin >> src >> dst)
    {
        int ans = INT_MAX;
        int len = dst.size();
        for(int i = 0; i <= 1; i++)
        {// 枚举第一个开关按还是不按
            int pushCount = 0;
            string temp = src;
            bool switchs = i;// 表示按还是不按
            for(int j = 0; j < len; j++)
            {
                if(switchs)
                {
                    pushCount++;
                    temp[j] = temp[j] == '1' ? '0' : '1';
                    if(j > 0)
                        temp[j - 1] = temp[j - 1] == '1' ? '0' : '1';
                    if(j < len - 1)
                        temp[j + 1] = temp[j + 1] == '1' ? '0' : '1';
                }
                // 若是两者不相等，只能按下后面开关一个使其相等
                if(temp[j] == dst[j])
                    switchs = false;
                else
                    switchs = true;
            }
            if(!switchs)
                ans = min(pushCount,ans);
        }
        if(ans == INT_MAX)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}