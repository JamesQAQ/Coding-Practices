#include <iostream>
using namespace std;

int main()
{
    int n,temp,a[41],m,ans;
    while (cin>>n)
    {
        if (n==0)
            break;
        ans=1000;
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            cin>>m;
            for (int j=0;j<m;j++)
            {
                cin>>temp;
                a[temp-1]++;
            }
        }
        for (int i=0;i<41;i++)
            if (a[i]<ans)
                ans=a[i];
        cout<<ans<<endl;
    }
    return 0;
}
