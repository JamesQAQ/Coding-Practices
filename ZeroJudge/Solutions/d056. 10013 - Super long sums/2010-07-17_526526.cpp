#include <iostream>
#include <stdio.h>
using namespace std;

int sum[1000000];
int main()
{
    int n,m,a,b;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&m);
            for (int j=m-1;j>=0;j--)
            {
                scanf("%d%d",&a,&b);
                sum[j]=a+b;
            }
            for (int j=0;j<m;j++)
                if (sum[j]>=10)
                {
                    sum[j+1]+=::sum[j]/10;
                    sum[j]%=10;
                }
            for (int j=m-1;j>=0;j--)
                printf("%d",sum[j]);
            printf("\n\n");
        }
    }
    //system("pause");
    return 0;
}
