#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
/*int partitionn(int arr[],int low,int high)
{
    int pivot=arr[low];
    int left=low;
    int right=high;
    while(left<right)
    {

        while(arr[left]<=pivot)
        {
            left++;
        }
        while(arr[right]>pivot)
        {

            right--;
        }
        if(left<right)
        {

            int temp;
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
        }
    }
    arr[low]=arr[right];
    arr[right]=pivot;
    return right;


}
void Qsort(int arr[],int low,int high)
{
    //cout<<endl<<"here"<<endl;

    if(low<high)
    {
        int pivot;
        pivot=partitionn(arr,low,high);
        Qsort(arr,low,pivot-1);
       
        Qsort(arr,pivot+1,high);
    }

}
*/
void merge(int arr[],int left,int mid,int right)
{
    int tarr[100];
    int p1,p2,p3;
    p1=left;
    p2=mid+1;
    p3=left;
    while(p1<=mid&&p2<=right)
    {
        if(arr[p1]<=arr[p2])
        {
            tarr[p3++]=arr[p1++];
        }
        else
        {
            tarr[p3++]=arr[p2++];
        }
        
    }    
    while(p1<=mid)
    {
        tarr[p3++]=arr[p1++];   
    }
    while(p2<=right)
    {
        tarr[p3++]=arr[p2++];
    }
    for(int i=left;i<=right;i++)
    {
        arr[i]=tarr[i];
    }
    
}
void mergesort(int arr[],int left, int right)
{
    if(left<right)
    {
        int mid;
        mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int  main()
{
    int arr[100],N;


    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {

        scanf("%d",&arr[i]);
    }
    /*
    for(int i=0;i<N;i++)
    {

        printf("%d ",arr[i]);
    }
    */
    mergesort(arr,0,N-1);
    printf("\n");
    for(int i=0;i<N;i++)
    {

        printf("%d ",arr[i]);
    }


    system("pause");
    return 0;


}
