#include <iostream>
using namespace std;

int dp[3000],c[3000],v[3000];
int main()
{
    //freopen("in_4.txt","r",stdin);
    int n,m;
    while (cin>>n>>m)
    {
        v[0]=2;
        c[0]=1;
        for (int i=1;i<n;i++)
        {
            int sum=0;
            for (int j=(i-m<0)?0:i-m;j<i;j++)
            {
                sum+=c[j];
                if (sum>10000)
                    sum%=10000;
            }
            c[i]=v[i-1]-sum;
            if (c[i]<0)
                c[i]+=10000;
            v[i]=v[i-1]+c[i];
            if (v[i]>10000)
                v[i]%=10000;
        }
        cout<<v[n-1]<<endl;
    }
    return 0;
}
