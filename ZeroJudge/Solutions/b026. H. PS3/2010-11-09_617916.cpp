#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,a[3000][2],ansa,ansb,maxx,d;
    while (cin>>n)
    {
        if (n==0)
            break;
        maxx=0;
        for (int i=0;i<n;i++)
            cin>>a[i][0]>>a[i][1];
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
            {
                d=abs(a[i][0]-a[j][0])*abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1])*abs(a[i][1]-a[j][1]);
                if (d>maxx)
                {
                    maxx=d;
                    ansa=i;
                    ansb=j;
                }
                if (d==maxx)
                {
                    if (i<ansa)
                    {
                        ansa=i;
                        ansb=j;
                    }
                    else if (i==ansa)
                        if (j<ansb)
                            ansb=j;
                }
            }
        cout<<ansa<<" "<<ansb<<endl;
    }    
    return 0;
}
