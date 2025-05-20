#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    double a1,b1,a2,b2,x,y;
    while (cin>>a1>>a2>>b1>>b2)
    {
        x=(b2-b1)/(a1-a2);
        y=a1*x+b1;
        if (x==-0)
            cout<<"0"<<endl;
        else
            cout<<x<<endl;
        if (y==-0)
            cout<<"0"<<endl;
        else
            cout<<y<<endl;
    }
    return 0;
}
