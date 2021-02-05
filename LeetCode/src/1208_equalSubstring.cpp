/********************************************************************************************
 * @author reddragon
 * @date 2021/2/5
 * @brief medium 尽可能使字符串相等
 * 
 * 假定字符串s和t的长度均为n, 对于任意0 <= i < n, 将s[i] 变成 t[i] 的开销是abs(s[i] - t[i]) 
 * 因此可以创建一个diff数组, 记录s[i]->t[i]的开销
 * 创建数组 diff 之后，问题转化成计算数组 diff 的元素和不超过 maxCost 的最长子数组的长度
 * (这里强调一下,题目说的是s的子字符串转化它在t中对应的子字符串, 说明这里是连续的子数组)。
 * 
 * 1.双指针
 * 先计算出diff数组, 然后通过双指针,找到满足条件(数组之和<=maxCost)的最长子数组
 * 时间复杂度：O(N)		空间复杂度：O(N)
 ********************************************************************************************/
#include <sys/time.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 双指针实现
int equalSubstring(string s, string t, int maxCost)
{
	int len = s.length();
	vector<int> cost(len + 1, 0);// 记录s[i]->t[i]的花费
	for(int i = 0; i < len; ++i)
		cost[i] = abs(s[i] - t[i]);

	int ptr1 = len;
	int ptr2 = len;
	int sumCost = 0;
	int ans = 0;
	while(ptr1 != 0)
	{
		if(maxCost >= sumCost + cost[ptr1 - 1])
		{// 长度扩张
			--ptr1;
			sumCost += cost[ptr1];
		}
		else
		{// 长度减少
			--ptr2;
			sumCost -= cost[ptr2];
		}
		ans = max(ans, ptr2 - ptr1);
	}
	return ans;
}

int main()
{
    struct timeval tm1, tm2;
    if(gettimeofday(&tm1, nullptr) == -1)
    {
        perror("gettimeofday");
    }

	cout << equalSubstring("abcd", "cdef", 3) << endl;

    if(gettimeofday(&tm2, nullptr) == -1)
    {
        perror("gettimeofday");
    }
	cout << "消耗时间: " << tm2.tv_usec - tm1.tv_usec << "微秒." <<  endl;
	return 0;
}