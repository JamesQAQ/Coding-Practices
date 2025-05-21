#include <cstdio>
#include <vector>

struct Node {int to,w;} tmp;
std::vector <Node> path[1001];
void swap(int &a,int &b){
    a^=b^=a^=b;
}
int d[1001],f[1001],*fpath[1001],Q[1000000],ans;
bool inq[1001];
void spfa(int n,bool o){
    for (int i=2;i<=n;i++)
        d[i]=-1;
    d[1]=0;
    int l=0,r=1;
    Q[0]=1;
    while (l<r){
        int x=Q[l++],p=path[x].size();
        inq[x]=false;
        for (int i=0;i<p;i++){
            int to=path[x][i].to,*w=&path[x][i].w;
            if (d[to]==-1||d[x]+(*w)<d[to]){
                d[to]=d[x]+(*w);
                if (o){
                    f[to]=x;
                    fpath[to]=w;
                }
                if (!inq[to]){
                    inq[to]=true;
                    Q[r++]=to;
                }
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
    int n,m,a;
    while (scanf("%d %d",&n,&m)==2){
        ans=0;
        for (int i=1;i<=n;i++)
            path[i].clear();
        while (m--){
            a=input(),tmp.to=input(),tmp.w=input();
            path[a].push_back(tmp);
            swap(a,tmp.to);
            path[a].push_back(tmp);
        }
        spfa(n,true);
        int sp=d[n],at=n;
        while (at!=1){
            if ((*fpath[at])>ans){
                (*fpath[at])*=2;
                spfa(n,false);
                if (d[n]-sp>ans)
                    ans=d[n]-sp;
                (*fpath[at])/=2;
            }
            at=f[at];
        }
        printf("%d\n",ans);
    }
}
