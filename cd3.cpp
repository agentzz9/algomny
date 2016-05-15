#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int dfa[25][2];

    int i,n,f,fn,final[10],str[100],state,k;

    printf("No. of states: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        cout<<"( "<<i<<" ,0) -> ";
            cin>>dfa[i][0];

        cout<<"\n( "<<i<<" ,1) -> ";
            cin>>dfa[i][1];
    }
    printf("Enter no. of final states: ");
        cin>>n;

    i=1; fn=n;
    while(n--)
    {
        cin>>f;
        final[i++]=f;
    }

    printf("Enter no. of input symbols: ");
        scanf("%d",&n);

    printf("Enter input symbols: ");

    i=1;
    while(n--)
    {
        scanf("%d",&f);
        str[i++]=f;
    }

    state = dfa[1][str[1]];
    k=2;

    while(k<i)
    {
        state = dfa[state][str[k++]];
    }

    int flag=0;

    for(i=1;i<=fn;i++)
    {
        if(state==final[i])
            {
                printf("\n String is accepted.!!!!");
                flag=1;
                break;
            }
    }

    if(i>fn && flag==0)
        printf("\nNot Accepting.");

    system("pause");
    return 0;
}

