#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
using namespace std;

struct Node {int to,re;};
struct FLOW {int x,flow;} e;
int main()
{
    int n,m,d[102],a,b,w,ok[102][102];
    Node temp,from[102];
    vector <Node> path[102];
    deque <FLOW> Q;
    while (scanf("%d",&n)==1){
        for (int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        d[n+1]=INT_MAX;
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=n+1;j++)
                ok[i][j]=0;
        for (int i=0;i<=n;i++)
            path[i].clear();
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&w);
            temp.to=b; temp.re=0;
            path[a].push_back(temp);
            temp.to=a; temp.re=1;
            path[b].push_back(temp);
            ok[a][b]+=w;
        }
        scanf("%d %d",&a,&b);
        for (int i=0;i<a;i++){
            scanf("%d",&w);
            temp.to=w; temp.re=0;
            path[0].push_back(temp);
            temp.to=0; temp.re=1;
            path[w].push_back(temp);
            ok[0][w]=INT_MAX;
        }
        for (int i=0;i<b;i++){
            scanf("%d",&w);
            temp.to=n+1; temp.re=0;
            path[w].push_back(temp);
            ok[w][n+1]=INT_MAX;
        }
        int ans=0;
        while (1){
            bool findpath=0;
            int minflow;
            Q.clear();
            from[0].to=-1;
            for (int i=1;i<=n+1;i++)
                from[i].to=-2;
            for (int i=0;i<path[0].size();i++){
                e.x=path[0][i].to;
                if (d[e.x]>0){
                    from[e.x].to=0;
                    from[e.x].re=0;
                    e.flow=d[e.x];
                    Q.push_back(e);
                }
            }
            while (!Q.empty()){
                e=Q.front();
                Q.pop_front();
                int x=e.x,flow=e.flow,p=path[x].size();
                //cout<<x<<endl;
                if (x==n+1){
                    minflow=flow;
                    findpath=1;
                    break;
                }
                for (int i=0;i<p;i++){
                    int to=path[x][i].to;
                    //cout<<x<<" "<<to<<" "<<from[to].to<<" "<<d[to]<<" "<<ok[x][to]<<endl;
                    if (from[to].to==-2&&d[to]>0&&ok[x][to]>0){
                        from[to].to=x;
                        from[to].re=path[x][i].re;
                        e.x=to;
                        e.flow=min(flow,min(d[to],ok[x][to]));
                        Q.push_back(e);
                    }
                }
            }
            if (!findpath)
                break;
            int at=from[n+1].to;
            while (from[at].to!=-1){
                //cout<<at<<" ";
                int f=from[at].to;
                ok[f][at]-=minflow;
                ok[at][f]+=minflow;
                if (from[at].re)
                    d[at]+=minflow;
                else
                    d[at]-=minflow;
                at=f;
            }
            /*cout<<endl;
            cout<<"minflow:"<<minflow<<endl;
            getchar();*/
            ans+=minflow;
        }
        printf("%d\n",ans);
    }
    return 0;
}
