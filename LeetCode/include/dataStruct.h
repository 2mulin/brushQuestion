/*************************************
 * LeetCode 刷题时常见数据结构
*************************************/

#ifndef DATASTRUCT__H
#define DATASTRUCT__H

#include <stdio.h>
#include <sys/time.h>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/***************************
 * @return long long 毫秒
****************************/
long long getTime()
{
	struct timeval tm;
	if(gettimeofday(&tm, nullptr))
	{
		perror("gettimeofday");
		exit(-1);
	}
	return static_cast<long long>(tm.tv_sec * 1000) + static_cast<long long>(tm.tv_usec / 1000);
}

#endif