#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char ans[2][11],a[2][11];
    int n,e,mini,m,la0,la1;
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&e);
            mini=0;
            for (int j=0;j<e;j++)
            {
                scanf("%s %s %d",&a[0],&a[1],&m);
                if (m<mini)
                {
                    la0=strlen(a[0]),la1=strlen(a[1]);
                    for (int k=0;k<la0;k++)
                        ans[0][k]=a[0][k];
                    for (int k=0;k<la1;k++)
                        ans[1][k]=a[1][k];
                    mini=m;
                }
            }
            if (mini<0)
            {
                for (int k=0;k<la0;k++)
                    printf("%c",ans[0][k]);
                printf(" ");
                for (int k=0;k<la1;k++)
                    printf("%c",ans[1][k]);
                printf("\n");
            }
            else
                puts("Are you kidding me?");
        }
    }
    return 0;
}
