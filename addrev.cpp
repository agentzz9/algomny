/*
Problem code: ADDREV

The Antique Comedians of Malidinesia prefer comedies to tragedies. Unfortunately, most of the ancient plays are tragedies. Therefore the dramatic advisor of ACM has decided to transfigure some tragedies into comedies. Obviously, this work is very hard because the basic sense of the play must be kept intact, although all the things change to their opposites. For example the numbers: if any number appears in the tragedy, it must be converted to its reversed form before being accepted into the comedy play.

Reversed number is a number written in arabic numerals but the order of digits is reversed. The first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed number never has any trailing zeros.

ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and output their reversed sum. Of course, the result is not unique because any particular number is a reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must assume that no zeros were lost by reversing (e.g. assume that the original number was 12).
Input

The input consists of N cases (equal to about 10000). The first line of the input contains only positive integer N. Then follow the cases. Each case consists of exactly one line with two positive integers separated by space. These are the reversed numbers you are to add.
Output

For each case, print exactly one line containing only one integer - the reversed sum of two reversed numbers. Omit any leading zeros in the output.
Example

Sample input: 

3
24 1
4358 754
305 794

Sample output:

34
1998
1
*/
#include<iostream>
#include<cmath>
using namespace std;
long long rev(long long n)
{
    int mod,j,arr[255];
    long long rev=0;
    double t,i=0,t2;
    while(n>0)
    {
        mod=n%10;
        arr[(int)i]=mod;
        i++;
        n=n/10;
    }
    arr[(int)i]=999;
    i--;
    for(j=0;arr[j]!=999;j++)
    {
        t=pow(10,i);
        t2=arr[j]*t;
        rev=rev+t2;
        
        i--;
    }
    return rev;
}
int main()
{
    long long n,x1,x2,rev1,rev2,rev3,ans;

    scanf("%lld",&n);
    while(n>0)
    {
        scanf("%lld %lld",&x1,&x2);
        rev1=rev(x1);
       // cout<<"rev1 "<<rev1<<endl;system("pause");
        rev2=rev(x2);
       // cout<<"rev2 "<<rev2<<endl;system("pause");
        rev3=rev1+rev2;
       // cout<<"rev3"<<rev3<<endl;system("pause");
        ans=rev(rev3);
      //  printf("%lld %lld",rev1,rev2);
        printf("%lld\n",ans);
        n--;
    }
    system("pause");
    return 0;
}

    
        
        
        
            
        
        
        
