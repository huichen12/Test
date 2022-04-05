/*
¿ìËÙÅÅĞò
*/
#include <stdio.h>
#include <stdlib.h>
int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;

    return low;
}

void quick_sort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }

    return;
}

int main(){
    int i;
    int n;
    int arr[100]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf ("\n");
    //system("pause");
    return 0;
}

