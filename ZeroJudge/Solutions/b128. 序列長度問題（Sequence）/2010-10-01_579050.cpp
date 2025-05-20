#include <iostream>
#include <stdio.h>
using namespace std;
#define LEN 1000
int a[1000][LEN],ans[LEN];
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<LEN;j++)
                a[i][j]=0;
        a[0][0]=n;
        for (int i=0;i<LEN;i++)
            ans[i]=0;
        for (int i=1;i<n;i++)
            for (int j=0;j<LEN;j++)
            {
                a[i][j]+=a[i-1][j]*(n-i);
                if (a[i][j]>=100000)
                {
                    a[i][j+1]+=a[i][j]/100000;
                    a[i][j]%=100000;
                }
            }
        for (int i=0;i<n;i++)
            for (int j=0;j<LEN;j++)
                a[i][j]*=i+1;
        for (int i=0;i<n;i++)
            for (int j=0;j<LEN;j++)
                if (a[i][j]>=100000)
                {
                    a[i][j+1]+=a[i][j]/100000;
                    a[i][j]%=100000;
                }
        for (int i=0;i<n;i++)
            for (int j=0;j<LEN;j++)
                ans[j]+=a[i][j];
        for (int i=0;i<LEN;i++)
            if (ans[i]>=100000)
            {
                ans[i+1]+=ans[i]/100000;
                ans[i]%=100000;
            }
        int d;
        for (d=LEN-1;d>=0;d--)
            if (ans[d]!=0)
            {
                printf("%d",ans[d]);
                break;
            }
        d--;
        for (;d>=0;d--)
            printf("%05d",ans[d]);
        printf("\n");
    }
    return 0;
}
