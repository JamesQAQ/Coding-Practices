#include <iostream>
#include <cmath>
using namespace std;

bool p[10000000]={};
int prime[10000]={2},pnum=1,n,k,a[20],ans,sum=0,temp;
bool testp(int x)
{
    if (x>10000000)
    {
        for (int i=0;i<pnum;i++)
            if (x%prime[i]==0)
                return 0;
        return 1;
    }
    return p[x];
}
void dfs(int x,int d,int sum)
{
    if (x==k)
    {
        if (testp(sum))
            ans++;
        return;
    }
    for (int i=d;i<=n+x-k;i++)
        dfs(x+1,i+1,sum+a[i]);
}
int main()
{
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum>10000000)
    {
        sum=10000000;
        temp=10001;
    }
    else
        temp=sqrt(sum);
    for (int i=3;i<sum;i+=2)
        p[i]=1;
    for (int i=3;i<temp;i+=2)
        if (p[i])
        {
            prime[pnum++]=i;
            for (int j=3*i;j<sum;j+=2*i)
                p[j]=0;
        }
    ans=0;
    dfs(0,0,0);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
