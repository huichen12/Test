/*
题目描述
输入一个序列，按照序列中的元素顺序，利用开放定址法（增量取法采用线性探测再散列）构造哈希表，输出哈希表的查询结果。
输入
第一行数据分别表示序列的长度n，哈希表的长度m，以及用计算哈希函数值（采用除留余数法）的p，第二行表示由n个数据构成的序列，第三行表示待查询的元素
例如输入样例1：
11 13 13
16 74 60 43 54 90 46 31 29 88 77
29
输出
输出查询结果（若成功则输出Success，失败则输出Failure）以及比较次数
例如针对样例1的输出为:
Success 4
样例输入 Copy
11 13 13
16 74 60 43 54 90 46 31 29 88 77 
29
样例输出 Copy
Success 4
*/
#include "stdio.h"
#define MaxSize 100
#define NULLKEY -1
#define DELKEY -2
typedef int KeyType;
typedef struct{
		KeyType key;
		int count;//探测次数
}HashTable;
void InsertHT(HashTable ha[],int n,int m,int p,KeyType k){//将关键字插入哈希表
	int i,adr;
	adr=k%p;
	if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY){
	ha[adr].key=k;
	ha[adr].count=1;
	}
	else//发生冲突
	{
		i=1;//冲突次数
		do{
			adr=(adr+1)%m;//线性探测
			i++;
		}while(ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);
	ha[adr].key=k;
	ha[adr].count=i;//探测次数
	}
	n++;
}
void CreateHT(HashTable ha[],int n,int m,int p,KeyType keys[],int n1){//创建哈希表
	int i;
	for(i=0;i<m;i++){
		ha[i].key=NULLKEY;
		ha[i].count=0;
	}
	n=0;
	for(i=0;i<n1;i++){
		InsertHT(ha,n,m,p,keys[i]);
	}
}
void SearchHT(HashTable ha[],int m,int p,KeyType k){
		int i=1,adr;
		adr=k%p;
		while(ha[adr].key!=NULLKEY&&ha[adr].key!=k){
		i++;
		adr=(adr+1)%m;
		}
		if(ha[adr].key==k)
			printf("Success %d\n",i);
		else
			printf("Failure %d\n",i);
}
int main(){
	int i;
	int keys[100];
	int n,n1,m,p,k;
	HashTable ha[MaxSize];
	scanf("%d%d%d",&n1,&m,&p);
	for(i=0;i<n1;i++){
	scanf("%d",&keys[i]);
	}
	scanf("%d",&k);
	CreateHT(ha,n,m,p,keys,n1);
	SearchHT(ha,m,p,k);
	return 1;
}

