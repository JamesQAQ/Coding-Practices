#include <iostream>
#include <stdio.h>
using namespace std;

int input()   
{   
  char cha;   
  int x=0,flag=1;   
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
int a[10000];
int two(int x,int l,int r)
{
    if (r>=l)
    {
        int mid=(l+r)/2;
        if (x>a[mid]) return two(x,mid+1,r);
        if (x<a[mid]) return two(x,l,mid-1);
        if (x==a[mid]) return 1;
    }
    return 0;
}
int main()
{
    int n,m,x;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        for (int i=0;i<n;i++)
        {
            int sum=0;
            for (int j=0;j<m;j++)
                a[j]=input();
            for (int j=0;j<m;j++)
            {
                x=input();;
                if (two(x,0,m))
                    sum++;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
