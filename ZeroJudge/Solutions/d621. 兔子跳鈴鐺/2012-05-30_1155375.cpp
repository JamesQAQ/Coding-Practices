#include <cstdio>

int ans[400]={1},n;
bool v[400],found;
void dfs(int x,int sum,int next){
    if (sum>n)
        return;
    if (n==sum){
        printf("1");
        for (int i=1;i<x;i++)
            printf(" %c %d",(v[i])?'*':'+',ans[i]);
        puts("");
        found=true;
        return;
    }
    v[x]=false,ans[x]=next;
    dfs(x+1,sum+next,next+1);
    v[x]=true,ans[x]=2;
    dfs(x+1,sum*2,next);
}
int main()
{
    while (scanf("%d",&n),n){
        found=false;
        dfs(1,1,2);
        if (!found)
            puts("cheat!");
    }
}
