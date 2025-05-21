#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int ans[100001];
    int n,x,y,c,d;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&c);
            scanf("%d",&x);
            for (int j=0;j<x;j++)
            {
                scanf("%d",&d);
                ans[d]=c;
            }
        }
        scanf("%d",&y);
        printf("%d\n",ans[y]);
    }
    //system ("pause");
    return 0;
}
