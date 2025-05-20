#include <iostream>
#include <algorithm>
using namespace std;

double f[399],temp[399],sum;
int n,tree[399][2],t[399];
char c;
bool cmp(int i,int j)
{
    if (temp[i]<temp[j])
        return 1;
    return 0;
}
void dfs(int x,int d)
{
    if (tree[x][0]==-1)
    {
        sum+=d*f[x];
        return;
    }
    dfs(tree[x][0],d+1);
    dfs(tree[x][1],d+1);
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    while (cin>>n)
    {
        sum=0;
        for (int i=0;i<n;i++)
        {
            cin>>c>>f[i];
            temp[i]=f[i];
            tree[i][0]=-1;
            tree[i][1]=-1;
        }
        for (int i=0;i<2*n-1;i++)  
            t[i]=i;    
        for (int i=0;i<n-1;i++)
        {
            stable_sort(t,t+n+i,cmp);
            f[n+i]=f[t[0]]+f[t[1]];
            temp[n+i]=f[n+i];
            temp[t[0]]=1.1;
            temp[t[1]]=1.1;
            tree[n+i][0]=t[0];
            tree[n+i][1]=t[1];
        }
        dfs(2*n-2,0);
        cout<<sum<<endl;
    }
    return 0;
}
