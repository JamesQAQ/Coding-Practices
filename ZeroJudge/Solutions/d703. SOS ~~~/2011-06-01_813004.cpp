#include <cstdio>

int n,tn,m,tm,num;
char s[21],ans[4000000];
void dfs(int x){
    if (x==n+m){
        for (int i=0;i<n+m;i++)
            ans[num++]=s[i];
        ans[num++]='\n';
        return;
    }
    if (tn>0){
        tn--;
        s[x]='S';
        dfs(x+1);
        tn++;
    }
    if (tm>0){
        tm--;
        s[x]='L';
        dfs(x+1);
        tm++;
    }
}
int main()
{
    num=0;
    while (scanf("%d %d",&n,&m)==2)
        tn=n,tm=m,dfs(0);
    ans[num]='\0';
    printf("%s",ans);
    return 0;
}
