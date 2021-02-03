/*************************************
 * LeetCode 刷题时常见数据结构
*************************************/

#ifndef DATASTRUCT__H
#define DATASTRUCT__H

#include <stdio.h>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif