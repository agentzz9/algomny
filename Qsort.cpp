#include<iostream.h>
#include<conio.h>
void swap(int &tx,int &ty)
{
    int temp;
    temp=tx;
    tx=ty;
    ty=temp;
}    
void qsort(int vector[],int m,int n)
{
    int pivot,left,right,i,done=0;
    pivot=m;
    left=m;
    right=n;   
    while(done!=1)
    {
        while(right>=pivot)
        {
            if(vector[right]<=vector[pivot])
            {
                swap(vector[right],vector[pivot]);
                pivot=right;
                break;
            }
            right--;
         }
        while(left<=pivot)
        {
            if(vector[left]>=vector[pivot])
            {
                swap(vector[left],vector[pivot]);
                pivot=left;
                break;
            }
            left++;
        }
        if(left==right && pivot==right)
        {
            done=1;
        }
        /*for(i=right;i>pivot;i--)
        {
            if(vector[i]<=vector[pivot])
            {
                swap(vector[i],vector[pivot]);
                pivot=i;
                right=i;
                break;
            }
         }
        for(i=left;i<pivot;i++)
        {
            if(vector[i]>=vector[right])
            {
                swap(vector[i],vector[right]);
                pivot=i;
                left=i;
                break;
            }
        }
        if(left==right && pivot==right)
        {
            done=1;
        }*/
    
    }
    qsort(vector,m,pivot-1);
    qsort(vector,pivot+1,n);
}
int main()
{
    int vector[100],size,i=0;
     
    printf("\nEnter no of elements:");
    cin>>size;
    for(i=0;i<size;i++)
    {
        cin>>vector[i];
    }
    for(i=0;i<size;i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
    i=0;
    system("pause");
    qsort(vector,i,size-1);
    system("pause");
    for(i=0;i<size;i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
