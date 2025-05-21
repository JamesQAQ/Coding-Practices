#include <iostream>
using namespace std;

int main()
{
    int a[4],ans;
    while (cin>>a[0]>>a[1]>>a[2]>>a[3])
    {
        ans=0;
        ans+=a[3]+a[2];
        if (a[2]*37>a[0])
            a[0]=0;
        else
            a[0]-=a[2]*37;
        ans+=a[1]/8;
        a[1]%=8;
        if (a[1]>0)
        {
            ans++;
            if (64-a[1]*8>a[0])
                a[0]=0;
            else
                a[0]-=64-a[1]*8;
        }
        if (a[0]>0)
            ans+=(a[0]-1)/64+1;
        cout<<ans<<endl;
    }
    return 0;
}
