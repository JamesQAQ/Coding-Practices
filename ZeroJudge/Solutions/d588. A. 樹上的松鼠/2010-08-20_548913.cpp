#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,a,b,c,max;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            max=0;
            scanf("%d",&m);
            for (int j=0;j<m;j++)
            {
                scanf("%d %d %d",&a,&b,&c);
                scanf("%d %d %d",&a,&b,&c);
                if (c>max)
                    max=c;
            }
            printf("%d\n",max);                
        }
    }
    //system ("pause");
    return 0;
}
