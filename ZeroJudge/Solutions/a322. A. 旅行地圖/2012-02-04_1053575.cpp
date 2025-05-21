#include <cstdio>

int n,m;
bool use[8],main_map[8][8],match_map[8][8];
int main_at[26],match_at[26],main_degree[8],match_degree[8],now[8];
int find(char c,int at[],int &cnt){
    if (at[c]==-1)
        at[c]=cnt++;
    return at[c];
}
void build(bool map[8][8],int degree[],int at[],char c){
    for (int i=0;i<26;i++)
        at[i]=-1;
    for (int i=0;i<n;i++){
        degree[i]=0;
        for (int j=0;j<n;j++)
            map[i][j]=false;
    }
    int cnt=0,a,b;
    char A,B;
    for (int i=0;i<m;i++){
        scanf(" %c %c",&A,&B);
        A-=c,B-=c;
        a=find(A,at,cnt),b=find(B,at,cnt);
        map[a][b]=map[b][a]=true;
        degree[a]++,degree[b]++;
    }
}
bool judge(){
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (main_map[i][j]^match_map[now[i]][now[j]])
                return false;
    return true;
}
bool dfs(int x){
    if (x==n)
        return judge();
    for (int i=0;i<n;i++){
        if (!use[i]&&main_degree[x]==match_degree[i]){
            use[i]=true;
            now[x]=i;
            if (dfs(x+1))
                return true;
            use[i]=false;
        }
    }
    return false;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        build(main_map,main_degree,main_at,'A');
        build(match_map,match_degree,match_at,'a');
        for (int i=0;i<n;i++)
            use[i]=false;
        puts((dfs(0))?"yes":"no");
    }
}
