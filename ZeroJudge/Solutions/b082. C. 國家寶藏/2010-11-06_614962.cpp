#include <iostream>
using namespace std;

int main()
{
    int t,n,a,f[300],b[300];
    char s[300];
    string ans;
    while (cin>>t)
    {
        for (int i=0;i<t;i++)
        {
            cin>>n;
            ans.clear();
            for (int j=0;j<n;j++)
                cin>>f[j]>>s[j]>>b[j];
            int first;
            for (int j=0;j<n;j++)
            {
                int k;
                for (k=0;k<n;k++)
                    if (f[j]==b[k])
                        break;
                if (k==n)
                {
                    first=j;
                    break;
                }
            }
            ans+=s[first];
            for (int j=1;j<n;j++)
            {
                for (int k=0;k<n;k++)
                    if (b[first]==f[k])
                    {
                        first=k;
                        break;
                    }
                ans+=s[first];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
