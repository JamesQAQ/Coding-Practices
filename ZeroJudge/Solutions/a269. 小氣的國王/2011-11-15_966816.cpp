#include <cstdio>
#include <queue>
#include <vector>

struct Node {int to,w,c;} temp;
std::vector <Node> path[10001];
int n,m,d[10001],oo=2147483647;
bool inq[10001];
int spfa_cost(){
    for (int i=2;i<=n;i++)
        d[i]=oo,inq[i]=false;
    d[1]=0,inq[1]=true;
    std::queue <int> Q;
    Q.push(1);
    while (!Q.empty()){
        int x=Q.front(),p=path[x].size();
        Q.pop();
        inq[x]=false;
        for (int i=0;i<p;i++){
            int to=path[x][i].to,w=path[x][i].w;
            if (d[x]+w<d[to]){
                d[to]=d[x]+w;
                if (!inq[to]){
                    Q.push(to);
                    inq[to]=true;
                }
            }
        }
    }
    int Cost=0;
    for (int i=2;i<=n;i++){
        int cost=oo,p=path[i].size();
        for (int j=0;j<p;j++){
            int to=path[i][j].to,w=path[i][j].w;
            if (d[to]+w==d[i])
                cost=(cost<path[i][j].c)?cost:path[i][j].c;
        }
        Cost+=cost;
    }
    return Cost;
}
int main()
{
    int a;
    while (scanf("%d %d",&n,&m)){
        if (n==0&&m==0)
            break;
        for (int i=1;i<=n;i++)
            path[i].clear();
        for (int i=0;i<m;i++){
            scanf("%d %d %d %d",&a,&temp.to,&temp.w,&temp.c);
            path[a].push_back(temp);
            a^=temp.to^=a^=temp.to;
            path[a].push_back(temp);
        }
        printf("%d\n",spfa_cost());
    }
    return 0;
}
