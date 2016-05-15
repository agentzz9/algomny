/*
Input

There is a single positive integer T on the first line of input (equal to about 100000). It stands for the number of numbers to follow. Then there are T lines, each containing exactly one positive integer number N, 1 <= N <= 1000000000.

Output

For every number N, output a single line containing the single non-negative integer Z(N).
Example

Sample Input:

6
3
60
100
1024
23456
8735373

Sample Output:

0
14
24
253
5861
2183837
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long t,n,z,x,p,count,y;
    
    scanf("%lld",&t);
    while(t>0)
    {
        count=0;
        scanf("%lld",&n);
        x=99;
        p=1;
        while(x>0)
        {
            y=pow(5,p);
            x=n/y;
            
            count=count+x;
            p++;
        }
        printf("\n%lld",count);
        t--;
    }
    
    system("pause");
    return 0;
}

