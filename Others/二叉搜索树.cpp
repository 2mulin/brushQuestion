/********************************************************************************************
 * @author reddragon
 * @date 2020/11/21
 * @brief 二叉搜索树
 * 
 * 浙江大学数据结构的课上使用C语言实现的二叉搜索树的代码。
 * 写的真的好，特别是 插入和删除。
 * 全部是递归实现，写的简洁明了
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

// 这个比较重要，函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
Position Find( BinTree BST, ElementType X )
{
    while(BST)
    {
        if(BST->Data == X)
            break;
        else if(BST->Data > X)
            BST = BST->Left;
        else
            BST = BST->Right;
    }
    return BST;
}
// 函数FindMin返回二叉搜索树BST中最小元结点的指针
Position FindMin( BinTree BST )
{
    if(BST == NULL)
        return NULL;
    while(BST->Left)
    {
        BST =BST->Left;
    }
    return BST;
}

// 函数FindMax返回二叉搜索树BST中最大元结点的指针。
Position FindMax( BinTree BST )
{
    if(BST == NULL)
        return NULL;
    while(BST->Right)
    {
        BST = BST->Right;
    }
    return BST;
}

// 这下面两个递归真的写的好，简洁明了

// 函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针
BinTree Insert( BinTree BST, ElementType X )
{
    if(BST == NULL)
    {
        struct TNode *node = (struct TNode*)malloc(sizeof(struct TNode));
        node->Data = X;
        node->Left = NULL;
        node->Right= NULL;
        return node;
    }
    if(BST->Data > X)
        BST->Left = Insert(BST->Left, X);
    else if(BST->Data < X)
        BST->Right = Insert(BST->Right, X);
    return BST;
}

// 函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针
BinTree Delete( BinTree BST, ElementType X ) 
{ 
    Position Tmp; 
    if( !BST ) 
        printf("Not Found\n"); 
    else {
        if( X < BST->Data ) 
            BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
        else if( X > BST->Data ) 
            BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
        else { /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */ 
            if( BST->Left && BST->Right ) {
                /* 从右子树中找最小的元素填充删除结点 */
                Tmp = FindMin( BST->Right );
                BST->Data = Tmp->Data;
                /* 从右子树中删除最小元素 */
                BST->Right = Delete( BST->Right, BST->Data );
            }
            else { /* 被删除结点有一个或无子结点 */
                Tmp = BST; 
                if( !BST->Left )       /* 只有右孩子或无子结点 */
                    BST = BST->Right; 
                else                   /* 只有左孩子 */
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
}



