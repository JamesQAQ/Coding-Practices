#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,sac,ac;
    string name[10000],cd[10000];
    int t[10000],num;
    bool r[10000];
    char c='%';
    while (scanf("%d",&n)==1)
    {
        sac=0;
        ac=0;
        num=0;
        for (int i=0;i<n;i++)
            cin>>name[i]>>cd[i];
        for (int i=n-1;i>=0;i--)
        {
            int j;
            for (j=0;j<num;j++)
                if (name[t[j]]==name[i])
                    break;
            if (j==num)
            {
                t[j]=i;
                r[j]=1;
                num++;
            }
            if (cd[i][0]=='A')
                if (r[j])
                {
                    if (t[j]==i)
                        sac++;
                    ac++;
                    r[j]=0;
                }
        }
        printf("%d%c\n",100*sac/ac,c);
    }
    return 0;
}
