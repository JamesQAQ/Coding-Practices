#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m;
    string a,s;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        if (m==0&&n==0)
            break;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            s+=a;
        }
        int p;
        for (int i=0;i<m;i++)
        {
            scanf("%d",&p);
            printf("%c",s[p-1]);
        }
        printf("\n");
        s.clear();
    }
    return 0;
}
