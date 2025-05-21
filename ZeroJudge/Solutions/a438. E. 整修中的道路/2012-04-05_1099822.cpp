#include <cstdio>
#include <vector>

struct Node{int x,y;} edge[514001]; 
std::vector <int> path[32001];
bool use[32001],key[514001];
int low[32001],dfn[32001],st[32001],ed[32001],tag;
int min(int a,int b){
    return (a<b)?a:b;
}
void dfs(int x,int f,int d){
    use[x]=true;
    dfn[x]=low[x]=d;
    st[x]=ed[x]=tag++;
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (to!=f){
            if (use[to])
                low[x]=min(low[x],dfn[to]);
            else{
                dfs(to,x,d+1);
                ed[x]=tag++;
                low[x]=min(low[x],low[to]);
            }
        }
    }
}
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int cases,n,m,d,no,x,y;
    cases=input();
    while (cases--){
        n=input(),m=input();
        for (int i=1;i<=n;i++)
            path[i].clear(),use[i]=false;
        for (int i=1;i<=m;i++){
            key[i]=false;
            edge[i].x=input(),edge[i].y=input();
            path[edge[i].x].push_back(edge[i].y);
            path[edge[i].y].push_back(edge[i].x);
        }
        tag=0;
        for (int i=1;i<=n;i++)
            if (!use[i])
                dfs(i,0,0);
        for (int i=1;i<=m;i++)
            if (dfn[edge[i].x]<low[edge[i].y]||dfn[edge[i].y]<low[edge[i].x])
                key[i]=true;
        scanf("%d",&d);
        for (int i=0;i<d;i++){
            scanf("%d %d %d",&no,&x,&y);
            if (!key[no])
                putchar('N');
            else{
                int p=(dfn[edge[no].x]>dfn[edge[no].y])?edge[no].x:edge[no].y;
                putchar(((st[p]<=st[x]&&st[x]<=ed[p])^(st[p]<=st[y]&&st[y]<=ed[p]))?'Y':'N');
            }
        }
        puts("");
    }
}
