#include <iostream>
#include <algorithm>
using namespace std;

int a[100000],b[100000],no[100000],tree[200000][2],t[100000],ans;
bool cmp(int i,int j)
{
    return b[i]<b[j];
}
void dfs(int x,int d)
{
    if (tree[x][0]==-1)
    {
        ans+=a[x]*d;
        return;
    }
    dfs(tree[x][0],d+1);
    dfs(tree[x][1],d+1);
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        ans=0;
        for (int i=0;i<n;i++)
        {
            t[i]=i;
            no[i]=i;
            scanf("%d",&a[i]);
            b[i]=a[i];
            tree[i][0]=-1;
        }
        stable_sort(t,t+n,cmp);
        for (int i=1;i<n;i++)
        {
            b[t[i]]+=b[t[i-1]];
            tree[n+i-1][0]=no[t[i]];
            tree[n+i-1][1]=no[t[i-1]];
            no[t[i]]=n+i-1;
            for (int j=i;j<n-1;j++)
            {
            	if (b[t[j]]<b[t[j+1]])
            		break;
            	else
            		swap(t[j],t[j+1]);
				}
        }
        dfs(2*n-2,0);
        cout<<ans<<endl;
    }
    return 0;
}
