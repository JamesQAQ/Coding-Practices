#include <cstdio>

bool use1[25],use2[25],usey[12],map[12][12];
int n,ans;
char s[13];
void dfs(int x){
    if (x==n){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                (map[i][j])?s[j]='Q':s[j]='x';
            s[n]='\0';
            puts(s);
        }
        puts("");
        ans++;
        return;
    }
    for (int i=0;i<n;i++)
        if (!(use1[x-i+n]||use2[x+i]||usey[i])){
            map[x][i]=true;
            use1[x-i+n]=use2[x+i]=usey[i]=true;
            dfs(x+1);
            use1[x-i+n]=use2[x+i]=usey[i]=false;
            map[x][i]=false;
        }
}
int main()
{
 
    bool start=true;
    while (scanf("%d",&n)){
        if (n==0)
            break;
        if (start)
            start=false;
        else
            puts("");
        for (int i=0;i<n;i++){
            use1[i]=use2[i]=usey[i]=false;
            for (int j=0;j<n;j++)
                map[i][j]=0;
        }
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
