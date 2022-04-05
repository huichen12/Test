/*给定一棵二叉树的广义表表示法，请实现二叉树的建立，并用递归方法输出该二叉树的中序遍历序列。
例如样例1（其中，“#”不输出）：A(B(C,D(E(,G),F)))*/
/*
输入
【输入说明】
二叉树的广义表表示，例如：  A(B(C,D(E(,G),F)))

输出
【输出说明】
递归遍历该二叉树得到的中序序列，例如上述二叉树的中序序列为：
C B E G D F A
样例输入 Copy
A(B(C,D(E(,G),F)))
样例输出 Copy
C B E G D F A?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#define N 100000
 
typedef char Element;
typedef struct Node BTNode;
typedef struct Node * BTree;
 
struct Node{
    Element data;
    struct Node *lchild;
    struct Node *rchild;
};
 
BTree NewNode(Element x) 
{
    BTree p=(BTree)malloc(sizeof(BTNode));
    p->data=x;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}
 
BTree Create_BTree(char s[])   
{
    int i,k,top;
    BTree path[N],p;
    k=0;
    top=-1;
    for(i=0;s[i]!='\0';i++)
    {
        switch(s[i]) 
        {
          
            case '(':
                path[++top]=p;
                k=1;
                break;
            case ',':
                k=2;
                break;
            case ')':
                top--;
                break;
        } 
        if(isalpha(s[i])) 
        {
            p=NewNode(s[i]);
            if(k==1)
                path[top]->lchild=p;
            else if(k==2)
                path[top]->rchild=p;
        }
    } 
    return path[0];
}
 
void In_Order(BTree root) 
{    
    if (root!=NULL)
    {
        In_Order(root->lchild);
        printf("%c ",root->data);
        In_Order(root->rchild);
    }
}
 
int main()
{
    char s[N];
    BTree root=NULL;
    gets(s);
    root=Create_BTree(s);
    In_Order(root);
    return 0;
}
