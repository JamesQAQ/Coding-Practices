#include <iostream>
#include <cmath>
using namespace std;

struct Node{int x,d;} a[20];
int n,ans,ansd;
int gcd(int m,int n)
{
    int temp;
    while (n!=0)
    {
        temp=n;
        n=m%n;
        m=temp;
    }
    return m;
}
bool test()
{
    ans=a[0].x;
    ansd=a[0].d;
    for (int i=1;i<n;i++)
    {
        int d=gcd(max(ansd,a[i].d),min(ansd,a[i].d));
        if (abs(ans-a[i].x)%d!=0)
            return 0;
        while (ans!=a[i].x)
        {
            while (ans>a[i].x)
            {
                a[i].x+=a[i].d;
                if (a[i].x>=10000)
                    return 0;
            }
            while (ans<a[i].x)
            {
                ans+=ansd;
                if (ans>=10000)
                    return 0;
            }
        }
        ansd*=a[i].d/d;
    }
    return 1;
}
int main()
{
    int t=0,y,b,c;
    while (cin>>n)
    {
        if (n==0)
            break;
        cout<<"Case #"<<++t<<":"<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>y>>b>>c;
            a[i].x=y;
            a[i].d=c-b;
        }
        if (test())
            cout<<"The actual year is "<<ans<<"."<<endl<<endl;
        else
            cout<<"Unknown bugs detected."<<endl<<endl;
    }
    return 0;
}
