#include<iostream.h>
#include<conio.h>

void merge(int vector[],int m,int h,int n)
{
    int p1,p2,p3,i;
    int temp[100];
    p1=m;
    p2=h+1;
    p3=m;
    while((p1<=h)&&(p2<=n))
    {
        if(vector[p1]==vector[p2])
        {
            temp[p3++]=vector[p1++];
            temp[p3++]=vector[p2++];
        }
        else
        if(vector[p1]<vector[p2])
        {
            temp[p3++]=vector[p1++];
        }
        else
        {
            temp[p3++]=vector[p2++];
        }
    }
    while(p1<=h)
    {
        temp[p3++]=vector[p1++];
    }
    while(p2<=n)
    {
        temp[p3++]=vector[p2++];
    }

    for(i=m;i<=n;i++)
    {
        vector[i]=temp[i];
    }
}

void merge_pass(int vector[],int m,int n)
{
    int h;
    if(m!=n)
    {
        h=(m+n)/2;
        merge_pass(vector,m,h);
        merge_pass(vector,h+1,n);
        merge(vector,m,h,n);
    }
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
    merge_pass(vector,i,size-1);
    system("pause");
    for(i=0;i<size;i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}

        
