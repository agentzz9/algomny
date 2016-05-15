#include<iostream.h>
#include<stdio.h>

void output(char arr[50][50],int tr,int tc)
{
	int tarr[250];
	int n,k=0,i,j,t;
	n=tr*tc;
	for(i=0;i<tr;i++)
	{
		for(j=0;j<tc;j++)
		{
			tarr[k++]=arr[i][j];
		}
	}
	tarr[k]='\0';
	for(i=1;i<=(n-1);i++)
	{
		t=tarr[i];
		j=i-1;
		while(tarr[j]>t&&j>=0)
		{
			tarr[j+1]=tarr[j];
			tarr[j]=t;
			j--;
		}
	}

	for(i=0;tarr[i]!='\0';i++)
	{

		printf("%c",tarr[i]);
		if((i+1)%tc==0)
		{
			printf("\n");
		}
	}

}
int main()
{
	char arr[50][50];
	int t,r,c,i,j,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d",&r,&c);
		for(j=0;j<r;j++)
		{
   			//gets(arr[j]);
			scanf("%s\0",arr[j]);
		}
		output(arr,r,c);
	}
	system("pause");
	return 0;
}


