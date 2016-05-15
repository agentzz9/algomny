#include<stdio.h>
#include<string.h>
char* check(char tstr2[20],FILE *tfp1)
{

	int arr1[39],arr2[39],a,b,f=1,i;

    char tstr1[20];

//	tfp1=fopen("data.txt","r");
    
//arr1 and arr2 initializations
	for(a=0;a<39;a++)
	{
		*(arr1+a)=0;
	}
	for(b=0;b<39;b++)
	{
		*(arr2+b)=0;
	}

//keeping tstr1 ready from bulk data file...
	fscanf(tfp1,"%s",tstr1);
	

//make the frequency arrays for both....
	a=strlen(tstr1);
 	for(i=0;i<a;i++)
	{
		switch(*(tstr1+i))
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
			case '0':arr1[26]++;break;
            case '1':arr1[27]++;break;
            case '2':arr1[28]++;break;
            case '3':arr1[29]++;break;
            case '4':arr1[30]++;break;
            case '5':arr1[31]++;break;
            case '6':arr1[32]++;break;
            case '7':arr1[33]++;break;
            case '8':arr1[34]++;break;
            case '9':arr1[35]++;break;
            case ':':arr1[36]++;break;
            case ';':arr1[37]++;break;
            case ')':arr1[38]++;break;
            default: printf("\nerror");break;
		}
	}

	a=strlen(tstr2);
	for(i=0;i<a;i++)
	{
		switch(*(tstr2+i))
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
			case '0':arr2[26]++;break;
			case '1':arr2[27]++;break;
            case '2':arr2[28]++;break;
            case '3':arr2[29]++;break;
            case '4':arr2[30]++;break;
            case '5':arr2[31]++;break;
            case '6':arr2[32]++;break;
            case '7':arr2[33]++;break;
            case '8':arr2[34]++;break;
            case '9':arr2[35]++;break;
            case ':':arr2[36]++;break;
            case ';':arr2[37]++;break;
            case ')':arr2[38]++;break;
			default: printf("\nerror2");break;
		}
	}


//compare the freq distribution arrays...

	for(b=0;b<39;b++)
	{

		if(*(arr1+b)!=*(arr2+b))
		{
			f=0;break;//even one unequal... then f=0.. so negative on the result below...
		}
	}

//return result...
	if(f==1)
	{
		//fclose(tfp1);
        return tstr1;
	}
		//return tstr1;
	else
	{
        //fclose(tfp1);
		return NULL;
	}
	
}

int main()
{

// fp1 :    bulk database       str1
// fp2 :    input data          str2
// fp3 :    output data         str3


	char str1[20],str2[20],*str3;
 	FILE *fp1,*fp2=fopen("idata.txt","r+"),*fp3;

	while(fscanf(fp2,"%s",str2)!=EOF)
	{
        fp3=fopen("odata.txt","w+");
        fp1=fopen("data.txt","r");
        str3=check(str2,fp1);
		if(str3!=NULL)
		{

			fprintf(fp3,"%s\n",str3);//fprintf(fp3,"%s\n",str3);
			fflush(fp3);
		}
		
	}
	printf("done\n");
	printf("press any key to close flush the streams");
	getchar();
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	printf("success\n");
	getchar();
	return 0;
	
}