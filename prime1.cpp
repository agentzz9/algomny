/*
2. Prime Generator
Problem code: PRIME1

Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5

Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed)
Added by:	Adam Dzedzej
Date:	2004-05-01
Time limit:	6s
Source limit:	50000B
Memory limit:	256MB
Cluster: 	Pyramid (Intel Pentium III 733 MHz)
Languages:	All except: NODEJS PERL 6
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int comp,numbers[31624]={0},t,t2;
    int a=0,primes[3500],m,n;
    for(int i=3;i<=31624;i=i+2)
    {
        comp=-1;
        for(int j=i*i;j<31624;j=j+i)
        {
            if(i%j==0)
            {
                comp=1;
                break;
            }
        }
        if(comp==-1)
        {        
            numbers[i]=1;
            t2=i;
            continue;
        }
        if(comp==1)
        {
            continue;
        }
    }
    numbers[2]=1;
    for(int k=2;k<=t2;k++)
    {
        if(numbers[k]==1)
        {
            primes[a++]=k;
        }
    }
    primes[a]=-1;
    /*for(int q=0;primes[q]!=-1;q++)
    {
        printf("%d ",primes[q]);
    
    }
    fflush(stdin);
    getchar();
    */
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d %d",&m,&n);
        for(int i=m;i<=n;i++)
        {
            comp=-1;
            if(i==1)
            {
                continue;
            }
            for(int j=0;primes[j]!=-1;j++)
            {
                if(i%primes[j]==0&&i!=primes[j])
                {
                    comp=1;
                    break;
                }
            }
            if(comp!=1)
            {
                printf("%d\n",i);
            }
        }
        t--;
        printf("\n");
    }
    
    fflush(stdin);
    getchar();
    return 0;
}






        
