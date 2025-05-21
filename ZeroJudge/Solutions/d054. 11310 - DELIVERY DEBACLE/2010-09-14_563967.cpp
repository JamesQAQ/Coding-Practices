#include <iostream>
#include <stdio.h>
using namespace std;

int a[40][19],n,m;
void dsum(int i)
{
    for (int j=0;j<19;j++)
    {
        if (a[i][j]>=10)
        {
            a[i][j+1]++;
            a[i][j]-=10;
        }
    }
}
int main()
{
    memset(a,0,sizeof(a));
	a[0][0]=1;
	a[1][0]=5;  
	for (int i=2;i<40;i++)
	{
        for (int j=0;j<19;j++)
            a[i][j]+=a[i-1][j]+a[i-2][j];
        dsum(i);
        for (int j=0;j<19;j++)
            a[i][j]*=2;
        dsum(i);
        if (i%2==0)
        {
            a[i][0]--;
            for (int j=0;j<19;j++)
            {
                if (a[i][j]<0)
                {
                    a[i][j+1]--;
                    a[i][j]+=10;
                }
            }
        }
        else
        {
            a[i][0]++;
            dsum(i);
        } 
    }
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&m);
            int d;
            for (d=18;d>=0;d--)
                if (a[m-1][d]!=0)
                    break;
            for (;d>=0;d--)
                printf("%d",a[m-1][d]);
            printf("\n");
        }       
    }
   //system("pause");
   return 0;
}
