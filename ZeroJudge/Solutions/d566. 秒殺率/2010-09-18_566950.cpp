#include <iostream>
#include <stdio.h>
using namespace std;

char name[10000][31],cd[10000][4],t[10000];
bool compar(int i,int j)
{
    int li=strlen(name[i]);
    int lj=strlen(name[j]);
    if (li>lj) return 1;
    if (li<lj) return 0;
    for (int d=0;d<li;d++)
    {
        if (name[i][d]>name[j][d]) return 1;
        if (name[i][d]<name[j][d]) return 0;
    }
    if (i<j) return 0;
    if (i>j) return 1;
    return 1;
}
bool cmp(int i,int j)
{
    int li=strlen(name[i]);
    int lj=strlen(name[j]);
    if (li!=lj) return 1;
    for (int d=0;d<li;d++)
        if (name[i][d]!=name[j][d]) return 1;
    return 0;
}
int main()
{
    int n,sac,ac;
    char c='%';
    while (scanf("%d",&n)!=EOF)
    {
        sac=0;
        ac=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",&name[i]);
            scanf("%s",&cd[i]);
            t[i]=i;
        }
        stable_sort(t,t+n,compar);
        int a=t[0];
        bool r=0;
        for (int i=0;i<n;i++)
        {
            if (cmp(a,t[i]))
            {
                a=t[i];
                r=0;
            }
            if (cd[t[i]][0]=='A')
            {
                if (!r)
                {
                    if (a==t[i])
                        sac++;
                    r=1;
                    ac++;
                }
            }
        }
        if (sac==1)
            sac+=2;
        printf("%d%c\n",100*sac/ac,c);
    }
    return 0;
}
