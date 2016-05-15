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
        int count=0;
       
        scanf("%s",&str1);
        scanf("%s",&str2);
        len1=strlen(str1);
        len2=strlen(str2);
        if(len1>len2)
        {
            for(i=0;i<len2;i++)
            {
                ch=str2[i];
               // printf("ch is %c \n",ch);
                for(j=0;j<len1;j++)
                {
                    if(str1[j]==ch&&trav[j]!=1)
                    {
                        count++;
                       // printf("%c, count=%d |",big[j],count);
                        trav[j]=1;
                        break;
                    }
                    
                }
                //printf("\n");
            }   
            //strcpy(big,str1);lenb=len1;
            //strcpy(small,str2);lens=len2;
            
        }
        else
        {
                for(i=0;i<len1;i++)
                {
                    ch=str1[i];
                   // printf("ch is %c \n",ch);
                    for(j=0;j<len2;j++)
                    {
                        if(str2[j]==ch&&trav[j]!=1)
                        {
                            count++;
                           // printf("%c, count=%d |",big[j],count);
                            trav[j]=1;
                            break;
                        }
                        
                    }
                    //printf("\n");
                }   
            //strcpy(small,str1);lens=len1;
            //strcpy(big,str2);lenb=len2;
        }
        
    
        printf("%d\n",count); 
        t--;
    }
    system("pause");
    return 0;
}
