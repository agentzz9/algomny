#include<stdio.h>
#include<string.h>
#include<conio.h>

int main()
{
	int arr1[26],arr2[26],a,b,c,i,j,k,l,f=1;
	char str1[50],str2[50];


//arr1 and arr2 initializations
	for(a=0;a<26;a++)
	{
		*(arr1+a)=0;
	}
	for(b=0;b<26;b++)
	{
		*(arr2+b)=0;
	}
//_______________________________________
	printf("\nenter 1st string ");
	gets(str1);
	printf("\nenter jumbled version ");
	gets(str2);



//make the frequency arrays for both....
	a=strlen(str1);
 	for(i=0;i<a;i++)
	{
		switch(*(str1+i))
		{
			case 'a':arr1[0]++;break;
			case 'b':arr1[1]++;break;
			case 'c':arr1[2]++;break;
			case 'd':arr1[3]++;break;
			case 'e':arr1[4]++;break;
			case 'f':arr1[5]++;break;
			case 'g':arr1[6]++;break;
			case 'h':arr1[7]++;break;
			case 'i':arr1[8]++;break;
			case 'j':arr1[9]++;break;
			case 'k':arr1[10]++;break;
			case 'l':arr1[11]++;break;
			case 'm':arr1[12]++;break;
			case 'n':arr1[13]++;break;
			case 'o':arr1[14]++;break;
			case 'p':arr1[15]++;break;
			case 'q':arr1[16]++;break;
			case 'r':arr1[17]++;break;
			case 's':arr1[18]++;break;
			case 't':arr1[19]++;break;
			case 'u':arr1[20]++;break;
			case 'v':arr1[21]++;break;
			case 'w':arr1[22]++;break;
			case 'x':arr1[23]++;break;
			case 'y':arr1[24]++;break;
			case 'z':arr1[25]++;break;


			default: printf("\nerror");break;
		}
	}
	
	a=strlen(str2);
	for(i=0;i<a;i++)
	{
		switch(*(str2+i))
		{
			case 'a':arr2[0]++;break;
			case 'b':arr2[1]++;break;
			case 'c':arr2[2]++;break;
			case 'd':arr2[3]++;break;
			case 'e':arr2[4]++;break;
			case 'f':arr2[5]++;break;
			case 'g':arr2[6]++;break;
			case 'h':arr2[7]++;break;
			case 'i':arr2[8]++;break;
			case 'j':arr2[9]++;break;
			case 'k':arr2[10]++;break;
			case 'l':arr2[11]++;break;
			case 'm':arr2[12]++;break;
			case 'n':arr2[13]++;break;
			case 'o':arr2[14]++;break;
			case 'p':arr2[15]++;break;
			case 'q':arr2[16]++;break;
			case 'r':arr2[17]++;break;
			case 's':arr2[18]++;break;
			case 't':arr2[19]++;break;
			case 'u':arr2[20]++;break;
			case 'v':arr2[21]++;break;
			case 'w':arr2[22]++;break;
			case 'x':arr2[23]++;break;
			case 'y':arr2[24]++;break;
			case 'z':arr2[25]++;break;
			default: printf("\nerror");break;
		}
	}
	
//_____________________________________________________________________

//compare the freq distribution arrays...

	for(c=0;c<26;c++)
	{

		if(*(arr1+c)!=*(arr2+c))
		{
			f=0;break;//even one unequal... then f=0.. so negative on the result below...
		}
	}
	
//_________________________________
	if(f==1)
	    printf("\nyes");
	else
	    printf("\nno");
	
	getchar();
	return 0;
}
			
	
	
