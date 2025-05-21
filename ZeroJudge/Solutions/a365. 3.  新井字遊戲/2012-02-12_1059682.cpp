#include <cstdio>

int ans[4096],line[12][2]={{11,8},{10,7},{9,8},{8,7},{7,6},{8,4},{7,3},{5,4},{4,3},{3,2},{4,1},{3,0}};
bool run[4096]={};
int dfs(int x){
    if (!run[x]){
        ans[x]=0;
        for (int i=1<<11;i>0;i>>=1)
            if (x&i)
                if (dfs(x-i)==0)
                    ans[x]=1;
        for (int i=0;i<12;i++){
            int v=(1<<line[i][0])+(1<<line[i][1]);
            if ((x&v)==v)
                if (dfs(x-v)==0)
                    ans[x]=1;
        }
        run[x]=true;
    }
    return ans[x];
}
int main()
{
    ans[0]=1,run[0]=true;
    dfs((1<<12)-1);
    int n,m;
    char s[20];
    scanf("%d",&n);
    while (n--){
        scanf("%s",&s);
        m=0;
        for (int i=0;s[i];i++)
            m=m*2+s[i]-48;
        printf("%d",ans[m]);
    }
    puts("");
}
