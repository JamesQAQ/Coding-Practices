#include <iostream>
#include <stdio.h>
using namespace std;

char s[1001];
int k;
bool con(int l,int x)
{
    for (int i=l;i<x;i++)
        if (s[i]!=s[x+k+i-l])
            return 0;
    return 1;
}
int main()
{
    while (scanf("%d",&k)!=EOF)
    {
        int sum=0;
        scanf("%s",&s);
        int len=strlen(s);
        for (int i=1;i+k-1<len;i++)
        {
            for (int j=i-1;j>=0;j--)
                if (con(j,i))
                    sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
