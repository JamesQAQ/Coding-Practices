#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1,x2,y1,y2,s,cases,n,ans;
    double mini;
    while (cin>>cases)
        while (cases-->0)
        {
            mini=10000000;
            cin>>n;
            for (int i=1;i<=n;i++)
            {
                cin>>x1>>y1>>x2>>y2>>s;
                int x=abs(x1-x2),y=y1-y2;
                double p=sqrt(x*x+y*y)*s/x;
                if (p<mini)
                {
                    mini=p;
                    ans=i;
                }
            }
            cout<<ans<<endl;
        }
    return 0;
}
