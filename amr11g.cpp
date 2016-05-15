/*
Problem code: AMR11G

The Triwizard Tournament's third task is to negotiate a corridor of many segments, and reach the other end. The corridor is N segments long. The ith segment is either empty or has a dragon. Harry cannot pass the dragon and will have no option but to retreat if he encounters one. Is it possible for him to reach the exit starting from the entrance?
Input (STDIN):
The first line contains the number of test cases T.
Each of the next T lines contains a string describing the corridor. The ith character is either a '.' if the segment is empty, or a 'D' if the segment contains a dragon.
Output (STDOUT):
Output T lines, each containing either the string "Possible" if you can reach the exit, and "You shall not pass!" if it is not possible to reach the exit.
Constraints:
1 <= T <= 50
1 <= N <= 50
Time Limit: 1 s
Memory Limit: 32 MB
Sample Input:
3
..
..D.
D..D
Sample Output:
Possible
You shall not pass!
You shall not pass!

 

The Triwizard Tournament's third task is to negotiate a corridor of many segments, and reach the other end. The corridor is N segments long. The ith segment is either empty or has a dragon. Harry cannot pass the dragon and will have no option but to retreat if he encounters one. Is it possible for him to reach the exit starting from the entrance?

 

Input (STDIN):

The first line contains the number of test cases T.

Each of the next T lines contains a string describing the corridor. The ith character is either a '.' if the segment is empty, or a 'D' if the segment contains a dragon.

 

Output (STDOUT):

Output T lines, each containing either the string "Possible" if you can reach the exit, and "You shall not pass!" if it is not possible to reach the exit.

 

Constraints:

1 <= T <= 50

1 <= N <= 50

 

Sample Input:

3

..

..D.

D..D

 

Sample Output:

Possible

You shall not pass!

You shall not pass!

 

 
Added by:	Varun Jalan
Date:	2011-12-15
Time limit:	1s
Source limit:	50000B
Memory limit:	256MB
Cluster: 	Pyramid (Intel Pentium III 733 MHz)
Languages:	All
Resource:	Varun Jalan - ICPC Asia regionals, Amritapuri 2011
*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int t,n,i,len;
    char str[100];

    scanf("%d",&t);
    fflush(stdin);
    while(t>0)
    {
        n=0;
        scanf("%s",&str);
        len=strlen(str);
        
        for(i=0;i<len;i++)
        {
            if(str[i]=='D')
            {
                n=1; break;
            }
        }
        if(n==1)
        {
            printf("You shall not pass!\n");
        }
        else
        {
            printf("Possible\n");
        }
        t--;
    }
    
    system("pause");
    return 0;
}
