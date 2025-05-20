#include <iostream>
#include <cmath>
using namespace std;

int gcd(int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
    int t,x1,y1,x2,y2;
    while (cin>>t)
    {
        for (int i=0;i<t;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            int x=abs(x1-x2),y=abs(y1-y2);
            if (x==0&&y==0)
                cout<<"1"<<endl;
            else if (x==0)
                cout<<y+1<<endl;
            else if (y==0)
                cout<<x+1<<endl;
            else
                cout<<gcd(max(x,y),min(x,y))+1<<endl;
        }
    }
    return 0;
}
