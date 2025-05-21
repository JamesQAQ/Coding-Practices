#include <cstdio>

struct List{
    List *next;
    int to;
} path[100001];
int n,s,t,c,v[101][101],pathnum,d[101];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
void add_edge(int a,int b){
    path[pathnum].to=b;
    path[pathnum].next=path[a].next;
    path[a].next=&path[pathnum];
    pathnum++;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int dfs(int x,int flow){
    if (x==t)
        return flow;
    List *p=path[x].next;
    int mini=-1;
    while (p!=NULL){
        int to=p->to;
        if (v[x][to]){
            if (d[x]==d[to]+1){
                int value=dfs(to,min(flow,v[x][to]));
                if (value){
                    v[x][to]-=value;
                    v[to][x]+=value;
                    return value;
                }
            }
            if (mini==-1||mini>d[to]+1)
                mini=d[to]+1;
        }
        p=p->next;
    }
    if (mini==-1)
        d[x]=n;
    else
        d[x]=mini;
    return 0;
}
int Q[101];
void BFS(){
    int l=0,r=1;
    for (int i=1;i<=n;i++)
        d[i]=-1;
    Q[0]=t,d[t]=0;
    while (l<r){
        int x=Q[l];
        l++;
        List *p=path[x].next;
        while (p!=NULL){
            if (d[p->to]!=-1){
                d[p->to]=d[x]+1;
                Q[r++]=p->to;
            }
            p=p->next;
        }
    }
}
int main()
{
    int a,b,w,cases=0;
    while (n=input()){
        s=input(),t=input(),c=input();
        for (int i=1;i<=n;i++){
            path[i].next=NULL;
            for (int j=1;j<=n;j++)
                v[i][j]=0;
        }
        pathnum=n+1;
        for (int i=0;i<c;i++){
            a=input(),b=input(),w=input();
            v[a][b]+=w;
            v[b][a]+=w;
            add_edge(a,b);
            add_edge(b,a);
        }
        BFS();
        int ans=0;
        while (d[s]<n)
            ans+=dfs(s,2147483647);
        printf("Network %d\nThe bandwidth is %d.\n\n",++cases,ans);
    }
}
