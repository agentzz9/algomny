#include<iostream.h>
#include<conio.h>
void shellsort(int vector[],int n)
{
    int d,i,temp;
    d=n/2;
    while(d>=1)
    {    
        for(i=0;i<(n-d);i++)
        {
            if(vector[i]>=vector[i+d])
            {
                temp=vector[i];
                vector[i]=vector[i+d];
                vector[i+d]=temp;
            }
            
        }
        if(d==1)
            return;
        d=d/2.0+0.5;
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
    shellsort(vector,size);
    for(i=0;i<size;i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}


