#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
float RandomFloat(float a, float b) 
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
string makepop(int n)
{
	char c;
	string pop;
	for(int i=0;i<n;i++)
	{
		c='0';
		double rd=RandomFloat(0,1);
		if(rd>.5)
		c='1';
		
		pop+=c;
	}
	return pop;
}
int rselect(int fitness[],int p)
{
	int sum1=0;
	for(int i=0;i<p;i++)
	sum1=sum1+fitness[i];
	int rd=RandomFloat(0,1)*sum1;
	int i=0,sum=0;
	do
	{
		sum=sum+fitness[i];
		i++;
		
	}while(sum <rd);
	return --i;
}
int evalfit(string pop,int weight[],int max,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		//printf("%c ",pop[i]);
		if(pop[i]=='1')
		{
			sum=sum+weight[i];
		}
	}
	if(sum>max)
	return 0;
	else
 	return sum;
}
string cross(string a,string b,int n)
{
	int c=rand()%n;
	return a.substr(0,c)+b.substr(c);
}
int main()
{
	int benefit[100],weight[100];
	int n,i,j,max,k=0,p=20;
	cout<<"enter the no of items"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>benefit[i];
		cin>>weight[i];
	}
	cout<<"enter the capacity of the bag"<<endl;
	cin>>max;

	string population[100];
	for(i=0;i<p;i++)
	{
		population[i]=makepop(n);
	}
	for(i=0;i<p;i++)
	{
		cout<<population[i]<<endl;
	}
	int gen=1;
	int fitness[100];
	printf("fitness : \n");
	for(i=0;i<p;i++)
	{
		//cout<<"string is : "<<population[i]<<endl;
		fitness[i]=evalfit(population[i],weight,max,n);
		printf("%d\n",fitness[i]);
	}
	cout<<"new breed population : "<<endl;
	string breedpop[100];
	for(i=0;i<p;i++)
	{
		int j = rselect(fitness,p);
  		breedpop[i] = population[j];
  		cout<<breedpop[i]<<" "<<fitness[j]<<endl;
	}
	for(i=0;i<p-1;i++)
	{
		population[i]=cross(breedpop[i],breedpop[i+1],n);
	}
	population[p - 1] = cross(breedpop[0],breedpop[p - 1],n);
	cout<<"new population after crossover"<<endl;
	for(i=0;i<p;i++)
	{
		
		fitness[i]=evalfit(population[i],weight,max,n);
		cout<<population[i]<<" "<<fitness[i]<<endl;
	}
	
}
