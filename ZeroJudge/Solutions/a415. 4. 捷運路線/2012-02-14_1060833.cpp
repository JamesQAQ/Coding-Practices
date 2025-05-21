#include <cstdio>
#include <vector>
#include <queue>

struct Node {int to,w;} temp;
std::vector <Node> path[400];
int no[101],at[10][20],num[10],cnt=0,len[10][20],d[400];
bool inq[400];
int spfa(int st,int ed){
    for (int i=0;i<cnt;i++)
        d[i]=-1,inq[i]=false;
    d[st]=0,inq[st]=true;
    std::queue <int> Q;
    Q.push(st);
    while (!Q.empty()){
        int x=Q.front(),p=path[x].size();
        Q.pop();
        inq[x]=false;
        for (int i=0;i<p;i++){
            int to=path[x][i].to,w=path[x][i].w;
            if (d[to]==-1||d[to]-w-1>d[x]){
                d[to]=d[x]+w+1;
                if (!inq[to]){
                    inq[to]=true;
                    Q.push(to);
                }
            }
        }
    }
    return d[ed];
}
int main()
{
    int n,k,tmp,a,b,c,d,h,m;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d %d",&tmp,&num[i]);
        no[tmp]=i;
        for (int j=0;j<num[i];j++)
            scanf("%d",&len[i][j]),at[i][j]=cnt++;
    }
    for (int i=0;i<k;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        at[no[a]][b-1]=at[no[c]][d-1]=cnt++;
    }
    for (int i=0;i<cnt;i++)
        path[i].clear();
    for (int i=0;i<n;i++){
        temp.to=at[i][1],temp.w=len[i][1];
        path[at[i][0]].push_back(temp);
        for (int j=1;j<num[i]-1;j++){
            temp.to=at[i][j-1],temp.w=len[i][j];
            path[at[i][j]].push_back(temp);
            temp.to=at[i][j+1],temp.w=len[i][j+1];
            path[at[i][j]].push_back(temp);
        }
        temp.to=at[i][num[i]-2],temp.w=len[i][num[i]-1];
        path[at[i][num[i]-1]].push_back(temp);
    }
    for (int i=0;i<5;i++){
        scanf("%d %d %d %d %d %d",&h,&m,&a,&b,&c,&d);
        int st=at[no[a]][b-1],ed=at[no[c]][d-1];
        printf("%d\n",spfa(st,ed));
    }
}
