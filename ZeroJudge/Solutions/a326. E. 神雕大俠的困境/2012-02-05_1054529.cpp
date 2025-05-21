#include <cstdio>
#include <vector>

char map[20][21];
struct Node {int x,y;} need[400];
std::vector <int> bomb_x[20],bomb_y[20];
bool cover_x[20][10],cover_y[20][10],use_x[20],use_y[20];
int n,m,k,cnt[10],need_num;
bool dfs(int at,int cut){
    if (cut>k)
        return false;
    if (at==need_num)
        return true;
    int x=need[at].x,y=need[at].y;
    if (use_x[x]||use_y[y])
        return dfs(at+1,cut);
    use_x[x]=true;
    for (int i=0;i<bomb_x[x].size();i++){
        int v=bomb_x[x][i];
        if (cnt[v]==0)
            cut++;
        cnt[v]++;
    }
    if (dfs(at+1,cut))
        return true;
    for (int i=0;i<bomb_x[x].size();i++){
        int v=bomb_x[x][i];
        if (cnt[v]==1)
            cut--;
        cnt[v]--;
    }
    use_x[x]=false;
    use_y[y]=true;
    for (int i=0;i<bomb_y[y].size();i++){
        int v=bomb_y[y][i];
        if (cnt[v]==0)
            cut++;
        cnt[v]++;
    }
    if (dfs(at+1,cut))
        return true;
    for (int i=0;i<bomb_y[y].size();i++){
        int v=bomb_y[y][i];
        if (cnt[v]==1)
            cut--;
        cnt[v]--;
    }
    use_y[y]=false;
    return false;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d %d",&n,&m,&k);
        need_num=0;
        for (int i=0;i<m;i++)
            cnt[i]=0;
        for (int i=0;i<n;i++){
            use_x[i]=use_y[i]=false;
            bomb_x[i].clear(),bomb_y[i].clear();
            for (int j=0;j<m;j++)
                cover_x[i][j]=cover_y[i][j]=false;
        }
        for (int i=0;i<n;i++){
            scanf("%s",map[i]);
            for (int j=0;j<n;j++){
                if (map[i][j]=='*'){
                    need[need_num].x=i;
                    need[need_num].y=j;
                    need_num++;
                }
                else if (map[i][j]!='.'){
                    int v=map[i][j]-'A';
                    if (!cover_x[i][v]){
                        cover_x[i][v]=true;
                        bomb_x[i].push_back(v);
                    }
                    if (!cover_y[j][v]){
                        cover_y[j][v]=true;
                        bomb_y[j].push_back(v);
                    }
                }
            }
        }
        puts((dfs(0,0))?"yes":"no");
    }
}
