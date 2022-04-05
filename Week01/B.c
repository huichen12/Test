/*链表的局部翻转*/
/*
样例输入 Copy
8
1 2 3 4 5 6 7 8
2 7
样例输出 Copy
1 7 6 5 4 3 2 8
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode   
{
	int data;
	struct LNode* next;    
}Lnode, * linkList;

void Create9_link(linkList L, int n) {
	Lnode* q, * s;
	q = L;
	int x;
	for (int i = 0; i < n; i++) {
		s = (linkList)malloc(sizeof(Lnode));
		scanf("%d", &x);
		s->next = q->next;
		q->next = s;
		s->data = x;
		q = s;
	}
	q->next = NULL;
}

void Output_link(linkList L) {
	Lnode* q;
	q = L->next;
	while (q != NULL) {
		printf("%d ", q->data);
		q = q->next;
	}

}

linkList reverseBtw(linkList l, int left, int right) {
	{
		linkList pre = l;
		for (int i = 1; i < left; i++)
		{
			pre = pre->next;
		}
		int count = 0; linkList cur = pre->next;
		linkList curr = cur;
		linkList temp = NULL; linkList pree = NULL;
		while (count < right - left + 1)
		{
			temp = cur->next;
			cur->next = pree;
			pree = cur;
			cur = temp;
			count++;
		}
		pre->next = pree;
		curr->next = temp;
		return l;
	}
}

int main() {
	int n, left, right;
	linkList L;
	L = (linkList)malloc(sizeof(Lnode));
	L->next = NULL;
	scanf("%d", &n);
	Create9_link(L, n);
	scanf("%d %d", &left, &right);
	L = reverseBtw(L, left, right);
	Output_link(L);
	return 0;
}

