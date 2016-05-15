#include<stdio.h>
int main()
{
    FILE *fp=fopen("Z://DropBox/009log.txt","a+");
    char s[100];
    scanf("%s",s);
    printf("%s",s);
    system("pause");
    return 0;
}
