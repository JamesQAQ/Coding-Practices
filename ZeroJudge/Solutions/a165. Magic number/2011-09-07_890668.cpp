#include <cstdio>

bool use[10]={};
int ans=0;
void dfs(int x,int sum){
    if (x==10){
        ans=sum;
        return;
    }
    if (ans)
        return;
    for (int i=1;i<=9;i++)
        if (!use[i]){
            int p=sum*10+i;
            if (p%x==0){
                use[i]=true;
                dfs(x+1,p);
                use[i]=false;
            }
            if (ans)
                return;
        }
}
int main()
{
    dfs(1,0);
    printf("%d\n",ans);
    //while (getchar());
    return 0;
}
