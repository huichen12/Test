/*二叉树的后序遍历（非递归）*/
/*
建立一棵普通二叉树，用非递归实现该二叉树的后序遍历，并输出遍历节点序列。
输入
【输入说明】
给定一棵二叉树的层次序列（叶子节点默认为NULL），①用非递归方法实现该二叉树的后序遍历，②并输出序列。
（本题重点考察非递归，请勿直接使用递归算法）
输入以广义表表示：A(B(C,D(E(,G),F)))
输出
【输出说明】
非递归方法遍历给定二叉树得到的后序序列
输出后序序列：C G E F D B A
样例输入 Copy
A(B(C,D(E(,G),F)))
样例输出 Copy
CGEFDBA
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
 
typedef struct BTREE {
    char data;
    struct BTREE *lchild, *rchild;
}BT, *LBTREE;
 
LBTREE Creat()
{
    LBTREE STACK[M], p = NULL, T = NULL;
    int flag, top = -1,len,i;
    char ch[100];
    gets(ch);
    len=strlen(ch);
    for(i=0;i<len;i++){
        switch (ch[i])
        {
        case '(':   
            STACK[++top] = p;
            flag = 1;
            break;
        case ')':                                   
            top--;
            break;
        case ',':
            flag = 2;
            break;
        default:    
            p = (LBTREE)malloc(sizeof(BT));
            p->data = ch[i];
            p->lchild = NULL;
            p->rchild = NULL;
            if (T == NULL)
                T = p;
            else if (flag == 1)
                STACK[top]->lchild = p;
            else if (flag == 2)
                STACK[top]->rchild = p;
        }
    }
    return T;
}
 
void POSTORED(LBTREE T)     
{
    LBTREE STACK1[M];
    int STACK2[M], flag, top = -1;      
    LBTREE p = T;
    if (T != NULL)
    {
        do {
            while (p != NULL)
            {
                STACK1[++top] = p;
                STACK2[top] = 0;
                p = p->lchild;
            }
            p = STACK1[top];
            flag = STACK2[top--];
            if (flag == 0)
            {
                STACK1[++top] = p;
                STACK2[top] = 1;
                p = p->rchild;
            }
            else
            {
                printf("%c", p->data);
                p = NULL;
            }
        } while (!(p == NULL && top == -1));
    }
}
 
void Distroyb(LBTREE T)     
{
    if (T != NULL)
    {
        Distroyb(T->lchild);
        Distroyb(T->rchild);
        free(T);
    }
}
 
int main()
{
    LBTREE T = NULL;                
    T=Creat();
    POSTORED(T);
    Distroyb(T);
    return 0;
}
