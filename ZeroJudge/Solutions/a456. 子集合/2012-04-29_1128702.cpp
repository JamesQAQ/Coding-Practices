#include <cstdio>

int n,limit,now[16];
void dfs(int x,int d){
    if (x==limit){
        putchar('{');
        for (int i=0;i<limit;i++)
            printf((i)?",%d":"%d",now[i]);
        putchar('}');
        puts("");
        return;
    }
    for (int i=d;i<=n-(limit-x)+1;i++)
        now[x]=i,dfs(x+1,i+1);
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        puts("{0}");
        for (limit=1;limit<=n;limit++)
            dfs(0,1);
        if (cases)
            puts("");
    }
}
