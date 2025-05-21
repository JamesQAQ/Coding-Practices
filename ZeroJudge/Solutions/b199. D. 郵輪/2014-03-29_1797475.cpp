#include <stdio.h>

#define MAX 1000

int w[MAX][MAX];
int degree[MAX];
struct EDGE{
    int a,b;
} edge[MAX*MAX];

int limit,n,m;
bool found;

int choice[9];
bool coverd[MAX]={};

void dfs(int x,int d,int sum){
    if (x>limit)
        return;
    if (sum==m){
        found=true;
        return;
    }
    for (int i=d;i<m;i++)
        if (!coverd[edge[i].a]&&!coverd[edge[i].b]){
            int tmp_sum=sum+degree[edge[i].a];
            for (int j=0;j<x;j++)
                tmp_sum-=w[edge[i].a][choice[j]];
            choice[x]=edge[i].a;
            coverd[edge[i].a]=true;
            dfs(x+1,i+1,tmp_sum);
            coverd[edge[i].a]=false;
            if (found)
                return;
            
            tmp_sum=sum+degree[edge[i].b];
            for (int j=0;j<x;j++)
                tmp_sum-=w[edge[i].b][choice[j]];
            choice[x]=edge[i].b;
            coverd[edge[i].b]=true;
            dfs(x+1,i+1,tmp_sum);            
            coverd[edge[i].b]=false;
            return;
        }
}

int main()
{
    while (scanf("%d %d",&n,&m)){
        if (n+m==0)
            break;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                w[i][j]=0;
            degree[i]=0;
            coverd[i]=false;
        }
        int a,b;
        for (int i=0;i<m;i++){
            scanf("%d %d",&edge[i].a,&edge[i].b);
            w[edge[i].a][edge[i].b]++;
            w[edge[i].b][edge[i].a]++;
            degree[edge[i].a]++;
            degree[edge[i].b]++;
        }
        int single=0;
        for (int i=0;i<n;i++)
            if (degree[i]==0)
                single++;
        if (single>8){
            puts("Makoto should die!");
        }
        else{
            limit=8-single;
            found=false;
            dfs(0,0,0);
            if (found)
                puts("Nice boat.");
            else
                puts("Makoto should die!");                
        }
    }
}
