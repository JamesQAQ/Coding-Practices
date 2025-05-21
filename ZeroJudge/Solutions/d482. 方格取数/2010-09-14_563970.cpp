#include <iostream>
#include <stdio.h>
using namespace std;

int n,a[100][100],b[100][100];
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        b[0][0]=a[0][0];
        for (int i=1;i<n;i++)
        {
            b[0][i]=b[0][i-1]+a[0][i];
            b[i][0]=b[i-1][0]+a[i][0];
        }
        for (int i=1;i<n;i++)
            for (int j=1;j<n;j++)
                b[i][j]=(b[i-1][j]>b[i][j-1])?b[i-1][j]+a[i][j]:b[i][j-1]+a[i][j];
        printf("%d\n",b[n-1][n-1]);
    }
    return 0;
}
