#include <cstdio>
#include <algorithm>

int n,a[10],now[10];
bool use[10],found;
void dfs(int x){
    if (x==n){
        found=true;
        for (int i=0;i<n;i++){
            if (i)
                putchar(' ');
            printf("%d",now[i]);
        }
        puts("");
        return;
    }
    for (int i=0;i<n;i++)
        if (!use[i]){
            if (x>1&&((long long)now[x-1]+now[x-2])%a[i]!=0&&((long long)now[x-1]*now[x-2])%a[i]!=0)
                continue;
            now[x]=a[i];
            use[i]=true;
            dfs(x+1);
            if (found)
                return;
            use[i]=false;
        }
}
int main()
{
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]),use[i]=false;
        std::sort(a,a+n);
        found=false;
        dfs(0);
        if (!found)
            puts("No");
    }  
    return 0;
}
