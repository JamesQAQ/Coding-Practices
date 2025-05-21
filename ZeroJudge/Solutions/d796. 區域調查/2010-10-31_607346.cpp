#include <iostream>
using namespace std;

short int input()   
{   
  char cha;   
  short int x=0;   
  while(cha=getchar())   
     if(cha!=' '&&cha!='\n') break;   
  x=cha-48;   
  while(cha=getchar())    
    {   
     if(cha==' '||cha=='\n') break;   
      x=x*10+cha-48;   
    }   
    return x;   
}
int main()
{
    int q,sum;
    short a[500][500],first,x1,y1,x2,y2,n;
    while (scanf("%hd %d",&n,&q)!=EOF)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                a[i][j]=input();
        for (int i=0;i<q;i++)
        {
            first=input();
            if (first==1)
            {
                sum=0;
                x1=input();
                y1=input();
                x2=input();
                y2=input();
                if (x1>x2)
                {
                    int temp=x1;
                    x1=x2;
                    x2=temp;
                }
                if (y1>y2)
                {
                    int temp=y1;
                    y1=y2;
                    y2=temp;
                }
                for (int i=x1-1;i<=x2-1;i++)
                    for (int j=y1-1;j<=y2-1;j++)
                        sum+=a[i][j];
                printf("%d\n",sum);
            }
            else
            {
                x1=input();
                y1=input();
                a[x1-1][y1-1]=input();
            }
        }
    }
    return 0;
}
