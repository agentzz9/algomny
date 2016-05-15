#include<stdio.h>
#include<string.h>
int main()
{
    int t,m,l;
    long long a,res;
    char b[255];
    
    scanf("%d",&t);
    while(t)
    {
        res=1;
        scanf("%lld %s %d",&a,b,&m);
        l=strlen(b);
        l--;
        while(l>=0)
        {
            if(b[l]=='0')
            {
                a=((a%m)*(a%m)*(a%m))%m;
            }
            else if(b[l]=='1')
                {
                    res=(res%m*a%m)%m;
                    a=(a%m*a%m*a%m)%m;
                }
                else if(b[l]=='2')
                    {
                        res=(res%m*a%m*a%m)%m;
                        a=(a%m*a%m*a%m)%m;
                    }
            l--;
        }
        printf("%lld\n",res);
            
        t--;
    }
    system("pause");
    return 0;
}


/*
#include <iostream>
#include <cstdlib>
using namespace std;

long long ab(long long a,long long b)
{
	long long ans=1;
	
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a);
		}
		
		a=(a*a);
	
		b=b>>1;
	}
	
	return ans;
	
}

long long abmodm(long long a,long long b,long long m)
{
	long long ans=1;
	
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		
		a=(a*a)%m;
	
		b=b>>1;
	}
	
	return ans;
	
}

long long base10(char* str)
{
	long long n,s=0,p=0;
	int len=0;
	
	for(n=0;str[n]!='\0';n++);
	
	len=n;
	   
	for(n=len-1;n>=0;n--)
	{
	//	s=s+((int)(str[n]-'0'))*pow(3,p);
		
        s=s+((int)(str[n]-'0'))*ab(3,p);
		
        p++;
	}	
	return s;
	
}

int main() {
	
	
	long long t,a,b,m;
	char *bs=(char*)malloc(400*sizeof(char));                  
	

	
	scanf("%lld",&t);
	while(t)
	{
	
		scanf("%lld %s %lld",&a,bs,&m);
		b=base10(bs);  // looks fine...
	//	cout<<b<<endl;
  		
        printf("%lld\n",abmodm(a,b,m));
		
		t--;
	}
	
//	system("pause");
	return 0;
}


*/
