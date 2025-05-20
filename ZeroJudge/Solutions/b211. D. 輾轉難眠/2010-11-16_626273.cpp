#include <iostream>
using namespace std;

int a[201][2],p;
int gcd(int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
void abpow(int d)
{
    int l=d/2;
    int r=d-l;
    if (a[l][0]==0)
        abpow(l);
    if (a[r][0]==0)
        abpow(r);
    a[d][0]=a[l][0]*a[r][0]%p;
    a[d][1]=a[l][1]*a[r][1]%p;
}
int main()
{
    a[0][0]=1;
    a[0][1]=1;
    int m,n,d;
    while (scanf("%d",&a[1][0])!=EOF)
    {
        scanf("%d %d %d %d",&a[1][1],&m,&n,&p);
        d=gcd(max(m,n),min(m,n));
        for (int i=2;i<=d;i++)
        {
            a[i][0]=0;
            a[i][1]=0;
        }
        abpow(d);
        if (a[d][0]>=a[d][1])
            printf("%d\n",(a[d][0]-a[d][1])%p);
        else
            printf("%d\n",(a[d][0]-a[d][1])%p+p);
    }
    return 0;
}
