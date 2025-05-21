#include <iostream>
#include <stdio.h>
using namespace std;

int a[1001][1000];
int main()
{
    memset(a,0,sizeof(a));
    a[1][0]=1;
    a[2][0]=1;
    a[3][0]=1;
    for (int i=4;i<1001;i++)
        for (int j=0;j<1000;j++)
        {
            a[i][j]+=a[i-2][j]+a[i-3][j];
            if (a[i][j]>=10)
            {
                a[i][j+1]+=a[i][j]/10;
                a[i][j]%=10;
            }
        }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i=999;
        for (;i>=0;i--)
            if (a[n][i]!=0)
                break;
        for (;i>=0;i--)
            printf("%d",a[n][i]);
        printf("\n");
    }
    //system ("pause");
    return 0;
}
