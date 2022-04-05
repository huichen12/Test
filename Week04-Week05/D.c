/*
оё╤ШеепР
*/
#include <stdio.h>
int shsort(int s[], int n)//оё╤ШеепР
//уш╟КеепР 
{
    int i,j,d;
    d=n/2;
    while(d>=1)
    {
        for(i=d+1;i<=n;i++)
        {
            s[0]=s[i];
            j=i-d;
            while((j>0)&&(s[0]<s[j]))
            {
                s[j+d]=s[j];
                j=j-d;
            }
            s[j+d]=s[0];
        }
        d = d/2;
    }
    return 0;
}

int main()
{
    int a[100]={0},i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    shsort(a,n);
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    printf("\n");
    return 0;
}

