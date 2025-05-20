#include <iostream>
#include <stdio.h>
using namespace std;

int m,n,b[200],maxx=0,sum;
bool a[200][200];
int main()
{
    while (scanf("%d",&m)!=EOF)
    {
        scanf("%d",&n);
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<m;i++)
        {
            memset(b,0,sizeof(b));
            for (int j=i;j<m;j++)
            {
                for (int k=0;k<n;k++)
                {
                    if (!a[j][k])
                        b[k]=-1;
                    else if (b[k]==-1)
                        continue;
                    else
                        b[k]++;
                }
                sum=0;
                for (int l=0;l<n;l++)
                {
                        if (b[l]==-1)
                            sum=0;
                        else
                            sum+=b[l];
                        if (sum>maxx)
                            maxx=sum;
                }
            }
        }
        printf("%d\n",maxx);
        maxx=0;
    }
    //system ("pause");
    return 0;
}
