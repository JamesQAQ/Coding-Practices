#include <iostream>
using namespace std;

struct Node{int l,r;} a[101];

int main()
{
    int n,k,at,l,r;
    while (cin>>n>>k)
    {
        if (n==0&&k==0)
            break;
        at=n;
        for (int i=1;i<=n;i++)
        {
            a[i].l=i-1;
            a[i].r=i+1;
        }
        a[1].l=n;
        a[n].r=1;
        for (int i=n;i>2;i--)
        {
            for (int j=0;j<k;j++)
                at=a[at].r;
            l=a[at].l;
            r=a[at].r;
            a[at].l=-1;
            a[at].r=-1;
            a[l].r=r;
            a[r].l=l;
            at=l;
            for (int j=0;j<k;j++)
                at=a[at].r;
            if (!(at==l||at==r))
            {
                a[l].r=at;
                a[r].l=at;
                a[a[at].l].r=a[at].r;
                a[a[at].r].l=a[at].l;
                a[at].l=l;
                a[at].r=r;
            }
        }
        int ans=(k%2==0)?a[at].r:at;
        cout<<((ans==1)?ans:n+2-ans)<<endl;
    }
    return 0;
}
