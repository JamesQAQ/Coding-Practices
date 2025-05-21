#include <iostream>
#include <stdio.h>
using namespace std;

long long int input()   
{   
    char cha;   
    long long int x=0,flag=1;   
    while(cha=getchar())   
        if(cha!=' '&&cha!='\n') break;
    if(cha!='-')
        x=x*10+cha-48;  
    else flag=-1;   
    while(cha=getchar())    
    {   
        if(cha==' '||cha=='\n') break;   
        x=x*10+cha-48;   
    }   
    return x*flag;   
}
int main(int argc, char *argv[])
{
    long long int x,y,xx,yy,r,temp;
    long long int flag=1;  
    char cha;
    while (scanf("%c",&cha)!=EOF)
    {
        flag=1;
        if (cha==' '||cha=='\n')
            while(cha=getchar())   
                if(cha!=' '&&cha!='\n') break;
        x=0; 
        if(cha!='-')
            x=x*10+cha-48;  
        else flag=-1;   
        while(cha=getchar())    
        {   
            if(cha==' '||cha=='\n') break;
            x=x*10+cha-48;   
        }   
        x=x*flag;
        y=input();
        xx=input();
        yy=input();
        r=input();
        if (x>xx)
        {
            temp=xx;
            xx=x;
            x=temp;
        }
        if (y>yy)
        {
            temp=yy;
            yy=y;
            y=temp;
        }
        if (xx-x+yy-y>r)
            puts("alive");
        else
            puts("die");
    }
    return EXIT_SUCCESS;
}
