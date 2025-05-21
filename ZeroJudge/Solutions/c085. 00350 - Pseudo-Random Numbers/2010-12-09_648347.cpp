#include <iostream>
using namespace std;

int main()
{
    int z,i,m,l,t=0;
    bool a[10000];
    while (cin>>z>>i>>m>>l)
    {
        t++;
        if (z==0&&i==0&&m==0&&l==0)
            break;
        int ans=0;
        for (int j=0;j<m;j++)
            a[j]=0;
        while (1)
        {
            l=(z*l+i)%m;
            if (a[l])
                break;
            a[l]=1;
            ans++;
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
