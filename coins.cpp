/*
SPOJ Problem Set (classical)
346. Bytelandian gold coins
Problem code: COINS

In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?
Input

The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.
Output

For each test case output a single line, containing the maximum amount of American dollars you can make.
Example

Input:
12
2

Output:
13
2

You can change 12 into 6, 4 and 3, and then change these into $6+$4+$3 = $13. If you try changing the coin 2 into 3 smaller coins, you will get 1, 0 and 0, and later you can get no more than $1 out of them. It is better just to change the 2 coin directly into $2.
Added by:	Tomek Czajka
Date:	2005-05-03
Time limit:	9s
Source limit:	50000B
Memory limit:	256MB
Cluster: 	Pyramid (Intel Pentium III 733 MHz)
Languages:	All except: NODEJS PERL 6
Resource:	Purdue Programming Contest Training
*/

#include<stdio.h>
unsigned int dp[1000000];
unsigned int func(unsigned int n)
{
    if(n<12)
        return n;
    else 
        if(n<=1000000)
        {
            if(dp[n]!=-1)
                return dp[n];
            else
            {
                dp[n]=func(n/2)+func(n/3)+func(n/4);
                // printf("dp %d",dp[n]);
                return dp[n];
            }
        }
        else
        {
            if(n<12)
                return n;
            else
                return func(n/2)+func(n/3)+func(n/4);
        }
              
}
int main()
{
    unsigned int n,ans,i;
    for(i=0;i<=1000000;i++)
    {
        dp[i]=-1;
    }
    /*for(i=0;i<=1000000;i++)
    {
        printf("%d ",dp[i]);
    }
    printf("\n"); */
    //printf("go");
    while(scanf("%u",&n)!=EOF)
    {
        ans=func(n);
        printf("%u\n",ans);
    }
    fflush(stdin);getchar();
    return 0;
}

        
    
        
    
