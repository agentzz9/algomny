#include<stdio.h>
#include<string.h>

using namespace std;

int count;
int temp[30000],c[30000];

void merge(int c[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	
	while(i<=mid && j<=high)
	{
		if(c[i]<c[j])
		{   
			temp[k]=c[i];
			i++;
			k++;
		}
		else 
		 	if(c[i]>c[j])
		{
			int t=(i-mid)<0?(mid-i):i-mid;
             
            count = count + t + 1;
            temp[k]=c[j];
			j++;
			k++;
		}
     else
	   {
			temp[k]=c[j];
			i++;
			j++;
			k++;
		}
	}
    
	while(j<=high)
		{
			temp[k]=c[j];
			j++;
			k++;
		}

	while(i<=mid)
		{
			temp[k]=c[i];
			i++;
			k++;
		}
	for(i=low;i<=high;i++)
       {
          c[i]=temp[i];
       }

}


void split(int c[], int low, int high)
{
	int mid;
	if(low<high)
	{
	    mid = (low+high)/2 ;

	    split(c,low,mid);
	    split(c,mid+1,high);

        merge(c,low,mid,high);
	}
}


int main()
{
    int i,j,n;
	int t;
	char sen[30001][21],sen2[30001][21];

	scanf("%d",&t);

	while(t--)
	{
		count=0;
		scanf("%d",&n);

          for(i=0;i<n;i++)
           {
             scanf("%s",&sen[i]);
            }
          for(i=0;i<n;i++)
            {
              scanf("%s",&sen2[i]);
             }


		for(i=0;i<n;i++)
		 {
			for(j=0;j<n;j++)
				{
					if(strcmp(sen2[i],sen[j])==0)
					    c[i]=j;
			     }
		  }

		split(c,0,n-1);
        
		printf("%d\n", count);
	}

  return 0;
}
