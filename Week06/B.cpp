/*
��Ŀ����
����һ�����У����������е�Ԫ��˳�򣬹�����������������Ҹ���Ԫ�ص�˫�׽�㡣
����
��һ�����ݱ�ʾ���еĳ���n���ڶ��б�ʾ��n�����ݹ��ɵ����У������б�ʾ����ѯ��Ԫ��
������������1��
12
25 18 46 2 53 39 32 4 74 67 60 11
18
���
�����ѯ����Լ�������Ԫ���ڹ���Ķ����������е�˫�׽�㣬�����ҳɹ���˫�׽����ڣ������Success����˫�׽�㣻�����ҳɹ���˫�׽�㲻���ڣ������Success��None�������Ҳ��ɹ���ֻ���Failure
�����������1�����Ϊ:
Success 25
�������� Copy
12
25 18 46 2 53 39 32 4 74 67 60 11
18
������� Copy
Success 25
*/
#include<stdio.h>
#include<malloc.h>
#define maxl 100
int n;

typedef struct Tree {
	int val;
	struct Tree* left, * right;
}T, * TN;

TN newnode(int val) {
	TN node = (TN)malloc(sizeof(T));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

void Insert(TN root, int x) {
	TN p = root, pr;
	while (p) {
		pr = p;
		//printf("%d\n",p->val);
		if (p->val == x)
			return;
		else if (p->val > x)
			p = p->left;
		else
			p = p->right;
	}
	if (x < pr->val)
		pr->left = newnode(x);
	else
		pr->right = newnode(x);
}

void create(TN root) {
	int x;
	TN p;
	scanf("%d", &x);
	root->val = x;
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		Insert(root, x);
	}
}

void find(TN root, int val) {
	TN p = root, pr = NULL;
	while (p) {
		// printf("%d\n",p->val);
		if (p->val == val) {
			if (!pr)
				printf("Success None\n");
			else
				printf("Success %d\n", pr->val);
			return;
		}
		else if (val > p->val) {
			pr = p;
			p = p->right;
		}
		else {
			pr = p;
			p = p->left;
		}
	}
	printf("Failure\n");
}

int main() {
	TN root = newnode(0);
	int val;
	scanf("%d", &n);
	create(root);
	scanf("%d", &val);
	find(root, val);
	return 0;
}
