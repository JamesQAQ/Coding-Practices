#include <cstdio>

int n;
char now[10];
bool use[10];
void dfs(int x){
    if (x==n){
        puts(now);
        return;
    }
    for (int i=n;i>=1;i--)
        if (!use[i]){
            use[i]=true;
            now[x]=i+'0';
            dfs(x+1);
            use[i]=false;
        }
}
int main()
{
    while (scanf("%d",&n)==1){
        now[n]=0;
        dfs(0);
    }
}
