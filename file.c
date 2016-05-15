#include<stdio.h>
/*int main()
{
	char str[15];
	FILE *fp=fopen("data.txt","r"),*fp2=fopen("odata.txt","w+");
	while(fscanf(fp,"%s",str)!=EOF)
	{
		printf("%s",str);getchar();
		fprintf(fp2,"%s\n",str);
	}
	printf("\ndone\n");
	fclose(fp);
	fclose(fp2);
	getchar();
}
*/
int main()
{
    char ch;
    long long x;
    ch=getch();
    x=(long long)ch;
    printf("%lld",x);
    system("pause");
    return 0;
}
