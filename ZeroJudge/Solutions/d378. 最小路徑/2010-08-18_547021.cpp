#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,a[101][101],ii=1;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<m;i++)
            a[0][i]+=a[0][i-1];
        for (int i=1;i<n;i++)
        {
            a[i][0]+=a[i-1][0];
            for (int j=1;j<m;j++)
                a[i][j]=(a[i-1][j]<a[i][j-1])?a[i][j]+a[i-1][j]:a[i][j]+a[i][j-1];
        }
        printf("Case #%d :\n%d\n",ii++,a[n-1][m-1]);
    }
    //system ("pause");
    return 0;
}
