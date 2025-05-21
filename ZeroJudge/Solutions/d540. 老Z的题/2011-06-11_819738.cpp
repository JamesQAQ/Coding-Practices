#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

int n,m,w,a,b,d[501],inq[501];
struct Node {int to,w;} temp;
bool in[501];
std::vector <Node> path[501];
bool spfa(int s){
    for (int i=1;i<=n;i++)
        d[i]=2147483647,in[i]=false,inq[i]=0;
    d[s]=0;
    std::queue <int> Q;
    Q.push(s);
    in[s]=true;
    inq[s]++;
    while (!Q.empty()){
        int x=Q.front();
        /*printf("%d\n",x);
        for (int i=1;i<=n;i++)
            printf("%d %d %d\n",i,d[i],inq[i]);*/
        Q.pop();
        in[x]=false;
        if (inq[x]>=n)
            return true;
        for (int i=0;i<path[x].size();i++){
            int to=path[x][i].to,tw=path[x][i].w;
            if (d[to]-tw>d[x]){
                d[to]=d[x]+tw;
                if (!in[to]){
                    Q.push(to);
                    inq[to]++;
                    in[to]=true;
                }
            }
        }
    }
    return false;
}
bool ok(){
    for (int i=1;i<=n;i++)
        if (spfa(i))
            return true;
    return false;
}
int main()
{
    int cases;
    while (scanf("%d",&cases)==1){
        while (cases--){
            scanf("%d %d %d",&n,&m,&w);
            for (int i=1;i<=n;i++)
                path[i].clear();
            for (int i=0;i<m;i++){
                scanf("%d %d %d",&a,&b,&temp.w);
                temp.to=b,path[a].push_back(temp);
                temp.to=a,path[b].push_back(temp);
            }
            for (int i=0;i<w;i++)
                scanf("%d %d %d",&a,&temp.to,&temp.w),temp.w=-temp.w,path[a].push_back(temp);
            (ok())?puts("YES"):puts("NO");
        }
    }
    return 0;
}
