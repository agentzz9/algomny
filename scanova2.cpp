#include<stdio.h>
#include<String>
String whatTime(int seconds)
{
    String H,M,S,ans;
    int hr,min,sec;
    float t,decimalpart;
    hr=seconds/3600;
    t=seconds/3600;
    decimalpart=t-hr;
    H=strcat(toString(hr),":");
    
    min=decimalpart*60;//int
    t=decimalpart*60;//float
    decimalpart=t-min;
    M=strcat(toString(min),":");
    
    sec=decimalpart*60;
    S=strcat(toString(sec),"\0");
    
    ans=strcat(H,strcat(M,S););
    return ans;
}
    
    
        
    
    
    
    
    
     
int main()
{
    int seconds=3661;
    
    String ans;
    ans=whatTime(seconds);
    printf("%s",ans);
    
    
    system("pause");
    
    return 0;
}
