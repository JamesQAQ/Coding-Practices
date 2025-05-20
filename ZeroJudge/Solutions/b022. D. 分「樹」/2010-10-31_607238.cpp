#include <iostream>
using namespace std;

int main()
{
    int n,m;
    bool use[29];
    while (cin>>n>>m)
    {
        if (n==0&&m==0)
            break;
        if (n==1)
        {
            if (m==1)
                printf("0/1\n");
            else
                printf("1/0\n");
            continue;
        }
        if (n==2)
        {
            printf("1/1\n");
            continue;
        }
        m--;
        for (int i=0;i<n-2;i++)
        {
            use[i]=m%2;
            m/=2;
        }
        int p=1,q=1,lp=0,lq=1,rp=1,rq=0;
        for (int i=n-3;i>=0;i--)
        {
            if (use[i])
            {
                lp=p;
                lq=q;
            }
            else
            {
                rp=p;
                rq=q;
            }
            p=lp+rp;
            q=lq+rq;
        }
        printf("%d/%d\n",p,q);
    }
    return 0;
}
