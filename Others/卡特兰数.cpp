/*******************************************************************************
 * 牛客网的 https://ac.nowcoder.com/acm/problem/15409
 * 题目：神奇的数据结构栈   
 * 实际是一个Catalan数，数据范围0<n<50000,估计数字非常长，所以要实现高精度计算
 * Catalan数公式：Catalan(n)=Catalan(n-1)*(4*n-2)/(n+1)	主要实现高精度乘法和除法
 * 实现高精度也过不了，一般的都是输出到100，但是这题的数据太大了，
*******************************************************************************/

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;

char *dp[100000] = {nullptr};
const int length = 1000;

char *Catalan(int n)
{
    if (dp[n] != nullptr)
        return dp[n];
    else
    {
        char *ans = new char[length]; //存放中间计算结果
        memset(ans, '0', length * sizeof(ans[0]));
        char *temp = Catalan(n - 1); //存放因数1
        //因数1和因数2的乘法运算
        for (int i = length - 1; temp[i] != '\0'; i--)
        {
            int tempNum = 4 * n - 2, index = i;
            tempNum *= (temp[i] - '0');
            while (tempNum)
            {
                int num2 = tempNum % 10 + ans[index] - '0';
                //超过10需要进位,两个一位数相加最大不过18
                if (num2 >= 10)
                {
                    ans[index--] = num2 % 10 + '0';
                    if (ans[index] != '9')
                        ans[index] += 1;
                    else
                    {
                        int j = index;
                        //前面都是9的话，进的位可能很多
                        while (ans[j] != '9')
                        {
                            ans[j--] = '0';
                        }
                        ans[j] += 1;
                    }
                }
                else
                {
                    ans[index--] = num2 + '0';
                }
                tempNum /= 10;
            }
        }
        //除法运算
        int num = n + 1;        //除数
        temp = ans;             //被除数
        ans = new char[length]; //使用temp来保留中间结果，ans保存最后结果 ans=temp/num
        memset(ans, '\0', length * sizeof(char));
        //找到temp数组中第一个不为0的下标
        int i;
        for (i = 0; i < 500; i++)
        {
            if (temp[i] != '0')
                break;
        }
        //按位相除
        int y = 0;
        bool flag = false;
        for (int j = i; j < length; j++)
        {
            int x = (temp[j] - '0' + y * 10) / num; //商
            if (x != 0)
                flag = true;
            if (flag)
                ans[j] = x + '0';
            y = (temp[j] - '0' + y * 10) % num; //余
        }
        delete[] temp;
        dp[n] = ans;
        return dp[n];
    }
}

int main()
{
    dp[0] = new char[length];
    memset(dp[0], '\0', length * sizeof(char));
    dp[0][length - 1] = '1';
    dp[1] = new char[length];
    memset(dp[1], '\0', length * sizeof(char));
    dp[1][length - 1] = '1';
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        char *ans = Catalan(n);
        for (int i = 0; i < length; i++)
        {
            if (ans[i] != '\0')
                cout << ans[i];
        }
        cout << std::endl;
    }
    /*//打表
	for (int i = 1; i <= 1000; i++)
	{
		cout << i << '\t';
		char* ans = Catalan(i);
		for (int j = 0; j < length; j++)
		{
			if (ans[j] != '\0')
				cout << ans[j];
		}
		cout << std::endl;
	}*/
    return 0;
}