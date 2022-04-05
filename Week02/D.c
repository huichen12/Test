/*
给定一个特定格式字符串，先建立一棵二叉树（叶子节点为‘#’），然后依次输出二叉树的4个基本信息：
① 二叉树的高度
② 二叉树的节点个数
③ 二叉树的叶子节点个数
④ 二叉树的叶子节点的各个值
输入
给定一个字符串，表示二叉树按层次遍历得到的序列：
例如样例1："ab#cd##ef#g####"
输出
输出4行数据，分别如下：
6
15
8
# # # # # # # #
样例输入 Copy
ab#cd##ef#g####
样例输出 Copy
6
15
8
# # # # # # # #
*/
#include<stdio.h>
#include<stdio.h>
#include<malloc.h>
typedef char DataType;
  
typedef struct BiTNode 
{
    DataType data;
    struct BiTNode* lchild, *rchild ;
}BiTNode, * BiTree;
  
BiTree CreateBiTree() 
{
    BiTree T;
    char ch;int MaxSize=50;
    BiTree Q[MaxSize];
    int front=0,rear=0;
    BiTNode *p,*pre=T;
    scanf("%c",&ch);
    if (ch=='#')
    {
        T=NULL;
        return 0;
    }
    else
    {
        T=(BiTNode*) malloc(sizeof(BiTNode));
        T->data=ch;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    Q[rear]=T;
    rear=(rear+1)%MaxSize;
    while (front!=rear)
    {
        pre=Q[front];//从队列中取出一个结点
        front=(front+1)%MaxSize;
        scanf("%c",&ch);//输入左孩子的数据 
        if(ch!='#')
        {
            p=(BiTNode*) malloc(sizeof(BiTNode));
            p->data=ch;
            pre->lchild=p;
            Q[rear]=p;
            rear=(rear+1)%MaxSize;
        } 
        else
        {
            p=(BiTNode*) malloc(sizeof(BiTNode));
            p->data='#';
            pre->lchild=p;
            p->lchild=NULL;
            p->rchild=NULL;
        }
        scanf("%c",&ch);//输入右孩子的数据 
        if (ch!='#')
        {
            p=(BiTNode*) malloc(sizeof(BiTNode));
            p->data=ch;
            pre->rchild=p;
            Q[rear]=p;
            rear=(rear+1)%MaxSize;
        }
        else
        {
            p=(BiTNode*) malloc(sizeof(BiTNode));
            p->data='#';
            pre->rchild=p;
            p->lchild=NULL;
            p->rchild=NULL;
        }
    }
    return T;
}
 
void PreOrderTraverse(BiTree T) //先序遍历二叉树
{
    if (!T)
    {
     //printf("#");
     return;
    } 
    printf("%c", T->data);
    PreOrderTraverse(T->lchild); //递归遍历左子树
    PreOrderTraverse(T->rchild); //递归遍历右子树
}
 
//二叉树中的结点数 
int Num(BiTree T)
{
    if(T==NULL) return 0;
    if(T->lchild==NULL&&T->rchild==NULL) return 1;
    return Num(T->lchild)+Num(T->rchild)+1;
} 
 
//高度 
int Treehigh(BiTree T){
    int m,n,max;
    if(T){
        m=Treehigh(T->lchild);
        n=Treehigh(T->rchild);
        max=m>n?m:n;
        return max+1;
    }
    else return 0;
}
 
//二叉树中的叶子结点数  
int leafNum(BiTree T){
    if(T==NULL) return 0;
    else if(T->lchild==NULL&&T->rchild==NULL) return 1;
    else return leafNum(T->lchild)+leafNum(T->rchild);
}
  
void display(BiTree T){//二叉树中的叶子结点值 
    if(T){
        if(T->lchild==NULL&&T->rchild==NULL)
            printf("%c ",T->data);
        display(T->lchild);
        display(T->rchild);
    }
}
 
int main()
{
    BiTree T;
    T = CreateBiTree();
    int treenum=Treehigh(T);
    printf("%d\n",treenum);
    int num=Num(T);
    printf("%d\n",num);
    int leafnum=leafNum(T);
    printf("%d\n",leafnum);
    display(T);
    printf("\n");
    return 0;
     
}
