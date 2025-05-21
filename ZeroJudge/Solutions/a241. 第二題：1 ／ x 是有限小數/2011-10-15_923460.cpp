#include <cstdio>

int ans=0,n,a[2]={2,5};
void dfs(int x,int d){
    if (x>n)
        return;
    if (x!=1)
        ans++;
    for (int i=d;i<2;i++)
        dfs(x*a[i],i);
}
int main()
{
    int m;
    scanf("%d",&m);
    while (m--){
        scanf("%d",&n);
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
