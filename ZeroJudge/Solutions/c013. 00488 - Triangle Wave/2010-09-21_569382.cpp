#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a,f;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            scanf("%d",&f);
            for (int j=0;j<f;j++)
            {
                for (int k=1;k<=a;k++)
                {
                    for (int l=0;l<k;l++)
                        printf("%d",k);
                    printf("\n");
                }
                for (int k=a-1;k>0;k--)
                {
                    for (int l=0;l<k;l++)
                        printf("%d",k);
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
