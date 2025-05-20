#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,e,h1,m1,h2,m2,h3,m3;
    char s[50];
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d %d:%d %d:%d",&e,&h1,&m1,&h2,&m2);
            for (int j=0;j<e;j++)
            {
                scanf("%s %d:%d",&s,&h3,&m3);
                printf("%02d:%02d %02d:%02d\n",((h1*60+m1)-(h3*60+m3))/60,((h1*60+m1)-(h3*60+m3))%60,((h2*60+m2)-(h3*60+m3))/60,((h2*60+m2)-(h3*60+m3))%60);
            }
        }
    }
    return 0;
}
