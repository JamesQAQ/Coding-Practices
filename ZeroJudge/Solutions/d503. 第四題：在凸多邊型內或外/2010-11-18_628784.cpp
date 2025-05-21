#include <iostream>
using namespace std;

struct xy{int x,y;};
xy a[50],t;
int n;
bool wrong(int i1)
{
    int i2=(i1+1)%n,i3=(i2+1)%n;
    int x0=a[i1].x,y0=a[i1].y,x3=a[i3].x,y3=a[i3].y;
    int x=x0-a[i2].x,y=y0-a[i2].y;
    if (y==0)
    {
        if (x3>x0)
            return (t.x<x0)?1:0;
        else
            return (t.x>x0)?1:0;
    }
    double m=x/y;
    double z=m*(y3-y0)-x3+x0,tz=m*(t.y-y0)-t.x+x0;
    if (z>0)
        return (tz<0)?1:0;
    else
        return (tz>0)?1:0;
}
bool test()
{
    for (int i=0;i<n;i++)
        if (wrong(i))
            return 0;
    return 1;
}
int main()
{
    char c;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
            cin>>a[i].x>>c>>a[i].y;
        cin>>t.x>>c>>t.y;
        if (test())
            cout<<"IN"<<endl;
        else
            cout<<"OUT"<<endl;
    }
    return 0;
}
