#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,len1,len2;
    char str1[10005],str2[10005],ch;
    scanf("%d",&t);
    
    while(t)
    {
        int trav[10005]={0};
        int count1[150]={0},count2[150]={0};
        int tot=0,smaller=0;
        //char a='0';
        //printf("%d",(int)a);
        
        scanf("%s",&str1);
        scanf("%s",&str2);
        len1=strlen(str1);
        len2=strlen(str2);
        
        for(i=0;i<len1;i++)
        {
            count1[(int)str1[i]]++;
        }
        for(i=0;i<len2;i++)
        {
            count2[(int)str2[i]]++;
        }
        for(i=0;i<150;i++)
        {
            if(count1[i]!=0&&count2[i]!=0)
            {
                smaller=(count1[i]<count2[i])?count1[i]:count2[i];
                tot+=smaller;
            }
        }
        /*for(i=0;i<150;i++)
        {
            printf("%d \t",count1[i]);
        }
        getchar();
        getchar();
        */
        printf("%d\n",tot); 
        
        t--;
    }
    system("pause");
    return 0;
}
