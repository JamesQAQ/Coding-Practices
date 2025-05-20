#include <iostream>
#include <stdio.h>
using namespace std;

bool cmp(char a[],char b[],int l)
{
    for (int i=0;i<l;i++)
    {
        if (a[i]>b[i]) return 1;
        if (a[i]<b[i]) return 0;
    }
    return 0;
}
int main()
{
    char a[20],b[20];
    while (scanf("%s %s",a,b))
    {
        int la=strlen(a),lb=strlen(b);
        if (la==1&&lb==1&&a[0]=='0'&&b[0]=='0')
            break;
        if (la>lb)
            puts("Unfair");
        else if (la<lb)
            puts("Fair");
        else if (cmp(a,b,la))
            puts("Unfair");
        else
            puts("Fair");
    }
    return 0;
}
