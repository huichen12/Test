/*
题目描述
输入一个序列，按照序列中的元素顺序，构造二叉排序树，查找给定元素的双亲结点。
输入
第一行数据表示序列的长度n，第二行表示由n个数据构成的序列，第三行表示待查询的元素
例如输入样例1：
12
25 18 46 2 53 39 32 4 74 67 60 11
18
输出
输出查询结果以及待查找元素在构造的二叉排序树中的双亲结点，若查找成功且双亲结点存在，则输出Success和其双亲结点；若查找成功但双亲结点不存在，则输出Success和None；若查找不成功则只输出Failure
例如针对样例1的输出为:
Success 25
样例输入 Copy
12
25 18 46 2 53 39 32 4 74 67 60 11
18
样例输出 Copy
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
