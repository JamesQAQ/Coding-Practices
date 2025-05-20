#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int m,int n)
{
    if (m==0)
        return n;
        else
            return gcd(n%m,m);
}
int main()
{
    int n,F,W,f[40],w[40];
    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&f[i]);
            scanf("%d",&w[i]);
        }
        F=f[0];
        W=w[0];
        int l;
        for (l=1;l<n;l++)
        {
            int mini=(W<w[l])?W:w[l],maxx=(W>w[l])?W:w[l];
            int d=gcd(mini,maxx);
            if ((F-f[l])%d==0)
            {
                while (F!=f[l])
                {
                    while (F>f[l])
                        f[l]+=w[l];
                    while (F<f[l])
                        F+=W;
                }
                W=W*w[l]/d;
            }
            else
                break;
        }
        if (l==n)
        {
            int h,m;
            h=F/60;
            m=F%60;
            h=(h%12==0)?12:h%12;
            printf("%d:%02d\n",h,m);
        }
        else
            puts("Starvation");
    }
    return 0;
}
