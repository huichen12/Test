/*
按层次给定一棵二叉树的元素，建立该二叉树。为了方便验证，请利用递归方法输出所建二叉树的先序序列。
给定二叉树序列如下(其中#表示叶子节点）：ab#cd##ef#g####
输入
按照二叉树的层次序列，输入字符串，叶子节点用“#”表示。
例如输入样例1：
ab#cd##ef#g####
输出
二叉树的先序遍历序列。
例如针对样例1的输出为:
abc##de#g##f###
样例输入 Copy
ab#cd##ef#g####
样例输出 Copy
abc##de#g##f###?
*/

#include<stdio.h>
#include<malloc.h>
typedef struct BiTnode 
{
    char data;
    struct BiTnode* lchild, * rchild;
}BiTnode, * BiTree;
 
BiTree creat() 
{
    char ch;
    int front = 0, rear = 0;
    BiTree BT, T;
    BiTree queue[100];
    scanf("%c", &ch);
    if (ch != '#') 
    {
        BT = (BiTree)malloc(sizeof(BiTnode));
        BT->data = ch;
        BT->lchild = BT->rchild = NULL;
        queue[rear++] = BT;
    }
    else
    {
        return NULL;
    }
    while (front != rear)
    {
        T = queue[front++];//从队列中取出一个结点
        scanf("%c", &ch);//输入左孩子的数据 
        if (ch == '#') 
        {
            T->lchild = NULL;
        }
        else
        {
            T->lchild = (BiTree)malloc(sizeof(BiTnode));
            T->lchild->data = ch;
            T->lchild->lchild = NULL;
            T->lchild->rchild = NULL;
            queue[rear++] = T->lchild;
        }
        scanf("%c", &ch);//输入右孩子的数据 
        if (ch == '#') 
        {
            T->rchild = NULL;
        }
        else
        {
            T->rchild = (BiTree)malloc(sizeof(BiTnode));
            T->rchild->data = ch;
            T->rchild->lchild = NULL;
            T->rchild->rchild = NULL;
            queue[rear++] = T->rchild;
        }
    }
    return BT;
}
void pre(BiTree T) 
{
    if (T) 
    {
        printf("%c", T->data);
        pre(T->lchild);
        pre(T->rchild);
    }
    else
    {
        printf("#");
    }
}
 
int main() 
{
    BiTree T;
    T = creat();
    pre(T);
    return 0;
}
