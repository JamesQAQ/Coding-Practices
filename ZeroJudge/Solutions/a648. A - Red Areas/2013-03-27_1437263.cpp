#include <iostream>  
#include <cmath>  
using namespace std;  
#define intdivide 3000  
struct Node {double x,y,r;} c[100];  
double divide=3000.0,pi=3.14159265,pi2=2.0*pi/divide;  
int n;  
bool test(double x,double y,int at)  
{  
    for (int i=0;i<n;i++)  
        if (i!=at)  
        {  
            double xx=x-c[i].x,yy=y-c[i].y,r=c[i].r;  
            if (xx*xx+yy*yy<r*r)  
                return 0;  
        }  
    return 1;  
}  
int main()  
{  
    int cases;  
    cin>>cases;  
    cout.setf(ios::fixed);  
    cout.precision(2);  
    while (cases-->0)  
    {  
        cin>>n;  
        for (int i=0;i<n;i++)  
            cin>>c[i].x>>c[i].y>>c[i].r;  
        double ans=0.0;  
        int b=0;  
        for (int i=0;i<n;i++)  
        {  
            int sum=0;  
            for (int j=0;j<intdivide;j++)  
                if (test(c[i].x+sin(pi2*j)*c[i].r,c[i].y+cos(pi2*j)*c[i].r,i))  
                    sum++;  
            double d=(double)sum;  
            ans+=c[i].r*pi*2.0*d/divide;  
        }  
        while (ans>=10.0)  
        {  
            ans/=10.0;  
            b++;  
        }  
        cout<<ans<<" "<<b<<endl;  
    }  
    return 0;  
}
