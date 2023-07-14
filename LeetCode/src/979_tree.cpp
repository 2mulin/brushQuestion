/**
 * @date 2023/7/14
 * @author 2mu
 * @brief medium 在二叉树中分配硬币
 *
 * 1. 层次遍历
 * 对Tree进行层次遍历, 最后从leaf节点往上;
 * leaf节点如果是1, 那么它就不需要移动, 如果它是0, 那么它只能从父节点移动1过来;
 * 此时不管父节点有没有, 都要移动1过来, 父节点没有就去其它地方移动1过来;
 * 如果leaf>1, 那么它将自己多余的都给父节点即可;
 *
 * 不符合这里题意, 因为题目给的Tree结构没有父节点; 题解给出了更详细的解释, 意思和我这个差不多
 * 给出了完整的推理证明;
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int &moveCnt)
{
    if (root == NULL)
        return 0;
    int leftMoveCnt = dfs(root->left, moveCnt);
    int rightMoveCnt = dfs(root->right, moveCnt);
    moveCnt = moveCnt + abs(leftMoveCnt) + abs(rightMoveCnt);
    return leftMoveCnt + rightMoveCnt + root->val - 1;
}

int distributeCoins(TreeNode *root)
{
    int move = 0;
    dfs(root, move);
    return move;
}

int main()
{
    return 0;
}