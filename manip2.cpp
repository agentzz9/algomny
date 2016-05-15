/*
Numbers, Numbers, Numbers

Problem code: MANIP2
	

    Submit
    My Submissions
    All Submissions

All submissions for this problem are available.

Okay. Before we begin, a hint : This one's taken from somewhere. Word to word. Google comes to mind, doesn't it? Here goes: For the heck of it, we define a new sequence as the infinite sequence of all integers, in ascending order, that can represented as any positive integer power of 5 (i.e 5k where k is a positive integer) or as a sum of distinct positive integer powers of 5 (i.e 5a1 + 5a2 + 5a3 + ... , where a1, a2, a3, ... are distinct positive integers). All the numbers in the lucky sequence are called lucky numbers. The first few numbers are 5, 25, 30, 125, 130, 150, ... Given n your task is to find the nth number in the sequence.
Input

First line of input contains an integer t, t ? 200, representing the number of test- cases. Then t lines follow each containing one integer n, 1 ? n ? 8000.
Output

For each test case output the "Case#x" followed by nth number on a separate line. Answers will fit in a 32-bit signed integer.
Sample

Input
4 
1 
2 
3 
9 

Output
5 
25 
30 
630

Author: 	admin
Date Added: 	31-08-2009
Time Limit: 	1 sec
Source Limit: 	50000 Bytes
Languages: 	ADA, ASM, BASH, BF, C, C99 strict, CAML, CLOJ, CLPS, CPP 4.0.0-8, CPP 4.3.2, CS2, D, FORT, FS, GO, HASK, ICK, ICON, JAR, JAVA, JS, LISP clisp, LISP sbcl, LUA, NEM, NICE, NODEJS, PAS fpc, PAS gpc, PERL, PERL6, PHP, PIKE, PRLG, PYTH, PYTH 3.1.2, RUBY, SCALA, SCM guile, SCM qobi, ST, TEXT, WSPC


*/
#include<stdio.h>
#include<math.h>
/*int main()
{
    int n,a,b,c,d;
    for(int i=0;i<=8000;i++)
    {
        n=i;
        cout<<endl<<n<<endl;
        while(n)
        {
        
            a=n&1;
            n=n>>1;
            cout<<a<<" ";
        }
        cout<<"\n__________________________";
    }
    system("pause");
    
    return 0;
}
*/
int main()
{
    int t,a,s,n,i,k;
    int t2;
    scanf("%d",&t);
    while(t>0)
    {
        s=0;
        i=1;
      
        scanf("%d",&n);
        while(n)
        {
            if((n&1)==0)
            {                
                n=n>>1;
                i++;
                continue;
            }
            else
            {
            
               // s=s+5^i;
                t2=1;
                for(k=1;k<=i;k++)//math.h sux
                {
                    t2=5*t2;
                }
                    
                s=s+t2;
                i++;
                n=n>>1;
            }
            
        }
        printf("%d\n",s);
        t--;
    }
    
   fflush(stdin);getchar();
    
    return 0;
}

