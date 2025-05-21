#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {int to,w;} temp;
queue <int> Q;
int n,m,a,d[10001];
long long ans;
bool v[10001]={};
bool ok(){
    for (int i=2;i<=n;i++){
        if (d[i]==2147483647)
            return false;
        ans+=(long long)d[i];
    }
    return true;
}
void spfa(int s,vector <Node> path[]){
    for (int i=1;i<=n;i++)
        d[i]=2147483647;
    Q.push(s);
    d[s]=0;
    v[s]=true;
    while (!Q.empty()){
        int x=Q.front(),p=path[x].size();
        Q.pop();
        for (int i=0;i<p;i++){
            int to=path[x][i].to,w=path[x][i].w;
            if (d[to]-w>d[x]){
                d[to]=d[x]+w;
                if (!v[to]){
                    Q.push(to);
                    v[to]=false;
                }
            }
        }
    }
}
int main()
{
    vector <Node> path[10001],rpath[10001]; 
    while (scanf("%d %d",&n,&m)==2){
        for (int i=1;i<=n;i++)
            path[i].clear(),rpath[i].clear();
        for (int i=0;i<m;i++){
            scanf("%d %d %d",&a,&temp.to,&temp.w);
            path[a].push_back(temp);
            a^=temp.to^=a^=temp.to;
            rpath[a].push_back(temp);
        }
        spfa(1,path);
        ans=0;
        (ok())?(spfa(1,rpath),(ok())?printf("%lld\n",ans):puts("0")):puts("0");
    }
    return 0;
}
