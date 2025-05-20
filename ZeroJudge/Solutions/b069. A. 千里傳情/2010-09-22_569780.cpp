#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,len;
    char a[90];
    int temp[5],b[21][21],cc[450];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            int r,c;
            len=0;
            scanf("%d",&r);
            scanf("%d",&c);
            for (int j=0;j<r;j++)
                for (int k=0;k<c;k++)
                    b[j][k]=0;
            getchar();
            while (a[len-1]!='\n')
                a[len++]=getchar();
            len--;
            for (int j=0;j<5*len;j++)
                cc[j]=0;
            for (int j=0;j<len;j++)
            {
                if (a[j]==32)
                    continue;
                else
                {
                    memset(temp,0,sizeof(temp));
                    int x=0,y=a[j]-'A'+1;
                    while (y>0)
                    {
                        temp[x]=y%2;
                        y=(y%2==0)?y/2:(y-1)/2;
                        x++;
                    }
                    for (int k=0;k<5;k++)
                        cc[j*5+k]=temp[4-k];
                }
            }
            int le=0,ri=c-1,u=0,d=r-1,p=0;
            while (p<5*len)
            {
                for (int j=le;j<=ri;j++)
                {
                    if (p>=5*len)
                        break;
                    b[u][j]=cc[p++];
                }
                u++;
                for (int j=u;j<=d;j++)
                {
                    if (p>=5*len)
                        break;
                    b[j][ri]=cc[p++];
                }
                ri--;
                for (int j=ri;j>=le;j--)
                {
                    if (p>=5*len)
                        break;
                    b[d][j]=cc[p++];
                }
                d--;
                for (int j=d;j>=u;j--)
                {
                    if (p>=5*len)
                        break;
                    b[j][le]=cc[p++];
                }
                le++;
            }
            printf("%d ",i+1);
            for (int j=0;j<r;j++)
                for (int k=0;k<c;k++)
                    printf("%d",b[j][k]);
            printf("\n");
        }        
    }
    return 0;
}
