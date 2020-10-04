#include<stdio.h>
int ave(int arr[])
{
    int s=0, avg, i;
    int *avgptr;
    for(i=0;i<10;i++)
        s+=arr[i];
    avg=s/10;
    avgptr=&avg;
    return avgptr;
}

void main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    ave(a);
}
