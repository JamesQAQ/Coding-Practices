#include <iostream>
using namespace std;

int a[16]={1},n,p[32]={};
bool use[17]={};
void dfs(int x)
{
    if (x==n)
    {
        if (p[a[n-1]+1])
        {
            cout<<"1";
            for (int i=1;i<n;i++)
                cout<<" "<<a[i];
            cout<<endl;
        }
        return;
    }
    for (int i=1;i<=n;i++)
        if (!use[i]&&p[a[x-1]+i])
        {
            use[i]=1;
            a[x]=i;
            dfs(x+1);
            use[i]=0;
        }
}
int main()
{
    p[2]=1;
    p[3]=1;
    p[5]=1;
    p[7]=1;
    p[11]=1;
    p[13]=1;
    p[17]=1;
    p[19]=1;
    p[23]=1;
    p[29]=1;
    p[31]=1;
    int t=0;
    use[1]=1;
    bool start=0;
    while (cin>>n)
    {
        t++;
        cout<<"Case "<<t<<":"<<endl;
        dfs(1);
        cout<<endl;
    }
    return 0;
}
