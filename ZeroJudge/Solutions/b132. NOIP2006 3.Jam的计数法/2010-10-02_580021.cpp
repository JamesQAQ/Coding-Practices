#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int s,t,w,a[25],l[25];
    char c[26];
    while (scanf("%d",&s)==1)
    {
        scanf("%d",&t);
        scanf("%d",&w);
        scanf("%s",&c);
        for (int i=0;i<w;i++)
        {
            a[i]=c[i]-'a';
            l[i]=t-w+i;
        }
        for (int i=0;i<5;i++)
        {
            if (a[w-1]==l[w-1])
            {
                int d=w-2;
                while (a[d]==l[d])
                {
                    d--;
                    if (d<0)
                        break;
                }
                if (d<0)
                    break;
                a[d]++;
                for (int j=d+1;j<w;j++)
                    a[j]=a[j-1]+1;
            }
            else
                a[w-1]++;
            for (int j=0;j<w;j++)
                printf("%c",a[j]+'a');
            printf("\n");
        }
    }
    return 0;
}
