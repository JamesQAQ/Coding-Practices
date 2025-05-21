#include <cstdio>
#include <vector>

std::vector <int> path[26];
char now[27];
bool use[26],found;
void dfs(int x,int d,int ed){
    use[x]=true;
    if (x==ed){
        now[d]=0;
        puts(now);
        found=true;
        return;
    }
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (!use[to]){
            now[d]=to+'A';
            dfs(to,d+1,ed);
            if (found)
                return;
        }
    }
}
int main()
{
    char sa[1000],sb[1000];
    int cases,m,q;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&m,&q);
        for (int i=0;i<26;i++)
            path[i].clear();
        while (m--){
            scanf("%s %s",sa,sb);
            int a=sa[0]-'A',b=sb[0]-'A';
            path[a].push_back(b);
            path[b].push_back(a);
        }
        while (q--){
            scanf("%s %s",sa,sb);
            int a=sa[0]-'A',b=sb[0]-'A';
            for (int i=0;i<26;i++)
                use[i]=false;
            found=false;
            now[0]=a+'A';
            dfs(a,1,b);
        }
    }
}

/*
7 3
Rome Turin
Turin Venice
Turin Genoa
Rome Pisa
Pisa Florence
Venice Athens
Turin Milan
Turin Pisa
Milan Florence
Athens Genoa
*/
