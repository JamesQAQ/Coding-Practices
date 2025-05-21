#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,amount=0,maxx=0,sum=0,a[102][102]={};
void test(int i,int j)
{
    sum+=a[i][j];
    a[i][j]=0;
    if (a[i-1][j])
        test(i-1,j);
    if (a[i][j-1])
        test(i,j-1);
    if (a[i+1][j])
        test(i+1,j);
    if (a[i][j+1])
        test(i,j+1);
    return;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]>0)
                {
                    amount++;
                    test(i,j);
                    if (sum>maxx)
                        maxx=sum;
                    sum=0;
                }
        printf("%d\n%d\n",amount,maxx);
        memset(a,0,sizeof(a));
        amount=0;
        maxx=0;
    }
    //system ("pause");
    return 0;
}
