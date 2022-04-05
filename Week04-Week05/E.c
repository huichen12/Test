/*
∂—≈≈–Ú
*/
#include <stdio.h>
#define MAXL 100
typedef int KeyType;      
typedef char InfoType;  
typedef struct 
{       KeyType key;            
         InfoType data;                
} RecType;                                
void CreateList(RecType R[],KeyType keys[],int n) 
{
    for (int i=1;i<=n;i++) 
        R[i].key=keys[i-1];
}
void DispList(RecType R[],int n) 
{
    for (int i=1;i<=n;i++)
        printf("%d ",R[i].key);
    printf("\n");
}
void sift(RecType R[],int low, int high){
	int i=low,j=2*i;
	RecType temp=R[i];
	while(j<=high){
		if(j<high && R[j].key<R[j+1].key)
		    j++;
		if(temp.key <R[j].key){
			R[i]=R[j];
			i=j;
			j=2*i;
		}
		else break;
	}
	R[i]=temp;
}
 void HeapSort(RecType R[],int n){
 	int i;
 	RecType tmp;
 	for(i=n/2;i>=1;i--){
 		sift(R,i,n);
	 }
	for(i=n;i>=2;i--){
		tmp=R[1];
		R[1]=R[i];
		R[i]=tmp;
		sift(R,1,i-1);
	}
} 
int main(){
	RecType R[MAXL];
	KeyType a[MAXL];
	int n;
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    CreateList(R,a,n);
    HeapSort(R,n);
    DispList(R,n);
    return 1;
}
