/*
题目描述
输入一个已经排好序的顺序表，利用折半查找算法实现对表中元素的查找，并输出元素在顺序表中的序号。

输入
第一行数据表示顺序表的长度n，第二行表示由n个数据构成的顺序表，第三行表示待查询的元素
例如输入样例1：
11
2 3 10 15 20 25 28 29 30 35 40
20
输出
输出待查找元素在顺序表中的序号（从序号从1开始），若不存在则输出-1
例如针对样例1的输出为:
5
样例输入 Copy
11
2 3 10 15 20 25 28 29 30 35 40
20
样例输出 Copy
5

*/
#include "stdio.h"
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
 
typedef struct{
    KeyType Key;
    InfoType data;
}RecType;//查找元素类型
 
void CreateList(RecType R[],KeyType Keys[],int n){//创建顺序表
    for(int i=0;i<n;i++){
    R[i].Key=Keys[i];
    }
}
void DispList(RecType R[],int n){//输出顺序表
    for(int i=0;i<n;i++)
        printf("%d",R[i].Key);
    printf("\n");
}
int BinSearch(RecType R[],int n,KeyType k){//折半查找算法
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

