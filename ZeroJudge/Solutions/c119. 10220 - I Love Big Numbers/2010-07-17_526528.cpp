#include <iostream>
#include <stdio.h>
using namespace std;

int a[1000][3000]={},sum[1000]={};
int main()
{
    int n;
    sum[0]=1;
    a[0][0]=1;
    for (int i=2;i<=1000;i++)
    {
        for (int j=0;j<3000;j++)
        {
            a[i-1][j]+=a[i-2][j]*i;
            if (a[i-1][j]>=100)
            {
                a[i-1][j+2]+=a[i-1][j]/100;
                a[i-1][j]%=100;
            }
            if (a[i-1][j]>=10)
            {
                a[i-1][j+1]+=a[i-1][j]/10;
                a[i-1][j]%=10;
            }
        }
        for (int j=0;j<3000;j++)
            sum[i-1]+=a[i-1][j];
    }
    while (scanf("%d",&n)!=EOF)
        printf("%d\n",sum[n-1]);
    //system("pause");
    return 0;
}
