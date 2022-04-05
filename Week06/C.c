
/*
题目描述
输入一个序列，按照序列中的元素顺序，利用拉链法构造哈希表，输出哈希表的查询结果。哈希表的插入（插入同一线性链表时采用头插法）
输入
第一行数据分别表示序列的长度n，哈希表的长度m，以及用计算哈希函数（采用除留余数法）值的p，第二行表示由n个数据构成的序列，第三行表示待查询的元素
例如输入样例1：
11 13 13
16 74 60 43 54 90 46 31 29 88 77
29
输出
输出查询结果（若成功则输出Success，失败则输出Failure）以及比较次数
例如针对样例1的输出为:
Success 1
样例输入 Copy
11 13 13
16 74 60 43 54 90 46 31 29 88 77
29
样例输出 Copy
Success 1
*/
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int KeyType;
typedef struct node
{
	KeyType key;
	struct node *next; 
} NodeType;
typedef struct
{
	NodeType *firstp;
} HashTable;
void InsertHT(HashTable ha[],int n,int p,KeyType k)
{
	int adr;
	adr = k % p;
	NodeType *q;
	q = (NodeType *)malloc(sizeof(NodeType));
	q->key = k;
	q->next = NULL;
	if (ha[adr].firstp == NULL)
		ha[adr].firstp = q;
	else
	{
		q->next = ha[adr].firstp;
		ha[adr].firstp =q;
		
	}
	n++;
}

void CreateHT(HashTable ha[], int n, int m, int p, KeyType keys[],int n1)
{
	int i; 
	for(i=0;i<m;i++)
		ha[i].firstp = NULL;
	n=0;
	for(i=0;i<n1;i++)
		InsertHT(ha,n,p,keys[i]);
}

void SearchHT(HashTable ha[], int p, KeyType k)
{
	int i=0,adr;
	adr = k%p;
	NodeType *q;
	q = ha[adr].firstp;
	while(q!=NULL)
	{
		i++;
		if(q->key == k)
			break;
		q = q->next;
		
	}
	if(q!=NULL)
		printf("Success %d\n",i);
	else
		printf("Failure %d\n",i);
	
}
void DestroyHT(HashTable ha[],int m)
{
	int i;
	NodeType *q, *preq;
	for(i=0; i<m; i++)
	{
		q = ha[i].firstp;
		while(q!=NULL)
		{
			preq = q;
			q=q->next;
			free(preq);
		}
	}	
}

int main()
{
	int i;
	int keys[100];
	int n,n1,m,p,k;
	HashTable ha[MaxSize];
	scanf("%d%d%d",&n1,&m,&p);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&keys[i]);
	}
	scanf("%d",&k);
	CreateHT(ha,n,m,p,keys,n1);
	SearchHT(ha,p,k);
	DestroyHT(ha,m);
	return 1;
}
