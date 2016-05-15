#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<dos.h>
using namespace std;
void delay()
{
    for ( int c = 1 ; c <= 32767 ; c++ )
       for ( int d = 1 ; d <= 3299 ; d++ )
       {}
 
   
    
}
void showheart(char grid[25][80],int masks[25][4])
{
    for(int r=0;r<25;r++)
    {
        for(int c=0;c<80;c++)
        {
            int one,two,three,four;
            one=masks[r][0];
            two=masks[r][1];
            three=masks[r][2];
            four=masks[r][3];
            if(c>=one&&c<=two || c>=three&&c<=four)
            {
                printf("%c",grid[r][c]); 
            }
            else
                printf(" ");
        }    
        
    }
    
}
void showgrid(char grid[25][80])
{
 
    for(int r=0;r<25;r++)
    {
        for(int c=0;c<80;c++)
        {
                printf("%c",grid[r][c]); 
           
        }    
        
    }   
}

int main()
{
    char grid[25][80];
    int masks[25][4]=
    {
        {20,20,60,60},       //0
        {19,29,51,61},
        {16,32,48,64},
        {14,34,46,66},
        {13,36,44,67},
        {12,38,42,68},
        {11,39,41,69},
        {11,40,40,69},
        {11,40,40,69},
        {11,40,40,69},            //9
        {11,40,40,69},  //          //10   
        {12,40,40,68},
        {13,40,40,67},
        {14,40,40,66},
        {15,40,40,65},            //14
        {16,40,40,64},//15
        {18,40,40,63},
        {20,40,40,61},
        {22,40,40,58},
        {23,40,40,57},
        {25,40,40,55},
        {28,40,40,52},
        {32,40,40,48},
        {36,40,40,44},
        {40,40,40,40}//24
        
    };
    
    for(int r=0;r<25;r++)
    {
        for(int c=0;c<80;c++)
        {
            grid[r][c]='.'; 
        }    
    }
    
    cout<<"PRESS ANY KEY TO SEE WHAT HAPPENDS TO SPARSH WHEN DEEPANSHI LOVES HIM SO MUCH..."<<endl;
    getchar();
    for(int i=1;i>=1;i++)
    {
        showgrid(grid);
        delay();
        showheart(grid,masks);
        delay();
        delay();
        delay();
    }
    return 0;    
}
