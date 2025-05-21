#include <iostream>
using namespace std;

int boss[50001],n;
bool use[50001];
int search(int x)
{
    return (x==boss[x])?x:boss[x]=search(boss[x]);
}
int main()
{
    int m,t=0,a,b;
    while (cin>>n>>m)
    {
        cout<<"Case "<<++t<<": ";
        if (n==0&&m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            boss[i]=i;
            use[i]=0;
        }
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            boss[search(b)]=search(a);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            if (!use[search(i)])
            {
                use[search(i)]=1;
                ans++;
            }
        cout<<ans<<endl;
    }
    return 0;
}
