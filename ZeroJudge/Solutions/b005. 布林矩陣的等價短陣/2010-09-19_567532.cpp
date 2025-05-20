#include <iostream>
#include <stdio.h>
using namespace std;

bool a[100][100];
int r[100],c[100],rn,cn,n,ra,ca;
bool sea()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            c[i]+=a[i][j];
        if (c[i]%2==1)
        {
            cn++;
            ca=i;
        }
        if (cn>1)
            return 0;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            r[i]+=a[j][i];
        if (r[i]%2==1)
        {
            rn++;
            ra=i;
        }
        if (rn>1)
            return 0;
    }
    if (((rn==1)&&(cn==1))||((rn==0)&&(cn==0)))
        return 1;
    return 0;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            r[i]=0;
            c[i]=0;
        }
        cn=0;
        rn=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        if (sea())
        {
            if (rn==0)
                puts("OK");
            else
                printf("Change bit (%d,%d)\n",ca+1,ra+1);
        }
        else
            puts("Corrupt");
    }
    return 0;
}
