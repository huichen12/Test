/*
��Ŀ����
����һ���Ѿ��ź����˳��������۰�����㷨ʵ�ֶԱ���Ԫ�صĲ��ң������Ԫ����˳����е���š�

����
��һ�����ݱ�ʾ˳���ĳ���n���ڶ��б�ʾ��n�����ݹ��ɵ�˳��������б�ʾ����ѯ��Ԫ��
������������1��
11
2 3 10 15 20 25 28 29 30 35 40
20
���
���������Ԫ����˳����е���ţ�����Ŵ�1��ʼ�����������������-1
�����������1�����Ϊ:
5
�������� Copy
11
2 3 10 15 20 25 28 29 30 35 40
20
������� Copy
5

*/
#include "stdio.h"
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
 
typedef struct{
    KeyType Key;
    InfoType data;
}RecType;//����Ԫ������
 
void CreateList(RecType R[],KeyType Keys[],int n){//����˳���
    for(int i=0;i<n;i++){
    R[i].Key=Keys[i];
    }
}
void DispList(RecType R[],int n){//���˳���
    for(int i=0;i<n;i++)
        printf("%d",R[i].Key);
    printf("\n");
}
int BinSearch(RecType R[],int n,KeyType k){//�۰�����㷨
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(k==R[mid].Key)
            return mid+1;
        if(k<R[mid].Key)
            high=mid-1;
        else
            low=mid+1;
 
    }
    return -1;
}
int main(){
    int n,k;
    RecType R[MAXL];
    KeyType a[MAXL];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    CreateList(R,a,n);
    printf("%d\n",BinSearch(R,n,k));
    return 1;
 
}

