/* 链表的整体翻转*/
/*
样例输入
5
1 4 3 2 5
返回结果
5 2 3 4 1
*/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}Lnode, *LinkList;

LinkList InitList_List()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	return L;
}

void Create0_Link(LinkList L, ElemType e)//头插法
{
	LinkList p = L;
	LinkList s;
	s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void Create9_Link(LinkList L, ElemType e)
{
	LinkList p = L;
	LinkList s;
	s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = NULL;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}

void Output_Link(LinkList L)
{
	LinkList p = L->next;
	if(p == NULL)
		return;
	else 
	{
		while(p != NULL)
		{
			printf("%d ",p->data);
			p = p->next;
		}
	}
}

LinkList Reverse_Link (LinkList L)
{
	LinkList curr = L->next;
	LinkList pre = NULL;

	while (curr != NULL)
	{
		LinkList next = curr -> next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	LinkList head = (LinkList)malloc(sizeof(Lnode));
	head->next = pre;
	return head;
}

int main()
{
	LinkList L = InitList_List(); 
	LinkList rev;
	int n;
	int x;
	int i;

	scanf("%d",&n);
	for(i=1; i<=n; ++i)
	{
		scanf("%d",&x);
		Create9_Link(L,x);
	}
	rev = Reverse_Link(L);
	Output_Link(rev);

	return 0;
}
