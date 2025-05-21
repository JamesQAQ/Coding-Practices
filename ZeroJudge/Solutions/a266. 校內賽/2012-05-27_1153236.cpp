#include <cstdio>
#include <vector>

std::vector <int> path[101],rpath[101];
int cnt[101],win[101];
bool use[101],se[101]={},sw[101]={},ans[101]={};
int dfs(int x){
    use[x]=true;
    int sum=1,p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (!use[to])
            sum+=dfs(to);
    }
    return sum;
}
int rdfs(int x){
    use[x]=true;
    int sum=1,p=rpath[x].size();
    for (int i=0;i<p;i++){
        int to=rpath[x][i];
        if (!use[to])
            sum+=rdfs(to);
    }
    return sum;
}
int main()
{
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
        scanf("%d %d",&a,&b),path[b].push_back(a),rpath[a].push_back(b);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            use[j]=false;
        cnt[i]=dfs(i)-1;
        for (int j=1;j<=n;j++)
            use[j]=false;
        win[i]=rdfs(i)-1;
        se[cnt[i]]=true;
        sw[win[i]]=true;
    }
    int cut=0;
    for (int i=n-1;i>=0;i--)
        if (!se[i]){
            cut=i+1;
            break;
        }
    int ccut=0;
    for (int i=n-1;i>=0;i--)
        if (!sw[i]){
            ccut=i+1;
            break;
        }
    bool one=false;
    for (int i=1;i<=n;i++)
        if (cnt[i]>=cut||win[i]>=ccut){
            if (!one)
                one=true;
            else
                putchar(' ');
            printf("%d",i);
        }
    if (!one)
        puts("non");
    puts("");
    //while (1);
}
