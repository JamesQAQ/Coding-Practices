#include <iostream>
using namespace std;

int main()
{
    long long n,a,b,c[100000],ans;
    while (cin>>n)
    {
        if (n==0)
            break;
        ans=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a>>b;
            if (a>b)
                swap(a,b);
            c[i]=(a*4<b)?a*a*4*4:max(a*a*4,b*b);
            if (ans==0||c[i]>c[ans])
                ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
