#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    double delta,x[3],y[3],a[2],b[2],c[2],d,e,f;
    while (cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2])
    {
        a[0]=x[0]-x[1];
        a[1]=x[1]-x[2];
        b[0]=y[0]-y[1];
        b[1]=y[1]-y[2];
        c[0]=-x[0]*x[0]-y[0]*y[0]+x[1]*x[1]+y[1]*y[1];
        c[1]=-x[1]*x[1]-y[1]*y[1]+x[2]*x[2]+y[2]*y[2];
        delta=a[0]*b[1]-a[1]*b[0];
        d=(c[0]*b[1]-c[1]*b[0])/delta;
        e=(a[0]*c[1]-a[1]*c[0])/delta;
        f=-x[0]*x[0]-y[0]*y[0]-d*x[0]-e*y[0];
        cout<<sqrt(d*d+e*e-4*f)*3.141592653589793<<endl;
    }
    return 0;
}
