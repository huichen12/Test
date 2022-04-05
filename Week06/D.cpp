#include "stdio.h"
#define MaxSize 100
#define NULLKEY -1
#define DELKEY -2
typedef int KeyType;
typedef struct{
		KeyType key;
		int count;//̽�����
}HashTable;
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k){//���ؼ��ֲ����ϣ��
	int i,adr;
	adr=k%p;
	if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY){
	ha[adr].key=k;
	ha[adr].count=1;
	}
	else//������ͻ
	{
		i=1;//��ͻ����
		do{
			adr=(adr+1)%m;//����̽��
			i++;
		}while(ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);
	ha[adr].key=k;
	ha[adr].count=i;//̽�����
	}
	n++;
}
void CreateHT(HashTable ha[],int &n,int m,int p,KeyType keys[],int n1){//������ϣ��
	for(int i=0;i<m;i++){
		ha[i].key=NULLKEY;
		ha[i].count=0;
	}
	n=0;
	for(int i=0;i<n1;i++){
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
	int keys[100];
	int n,n1,m,p,k;
	HashTable ha[MaxSize];
	scanf("%d%d%d",&n1,&m,&p);
	for(int i=0;i<n1;i++){
	scanf("%d",&keys[i]);
	}
	scanf("%d",&k);
	CreateHT(ha,n,m,p,keys,n1);
	SearchHT(ha,m,p,k);
	return 1;
}

