#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(6);
    double x,ans,temp;
    while (cin>>x)
    {
        x=x/180*3.1415926;
        ans=0;
        int n=0;
        temp=x;
        while (fabs(temp)>0.01)
        {
            ans+=(n++%2)?-temp:temp;
            temp=temp*x*x/(2*n*(2*n+1));
        }
        ans+=(n%2)?-temp:temp;
        cout<<"N = "<<n*2+1<<endl<<ans<<endl;
    }
    return 0;
}
