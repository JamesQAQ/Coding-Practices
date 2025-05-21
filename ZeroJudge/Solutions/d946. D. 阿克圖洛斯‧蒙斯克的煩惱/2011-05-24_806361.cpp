#include <cstdio>
#include <algorithm>

struct Node {int a,b; double w;} path[100000];
int boss[100000];
double ans;
int search(int x){
    return (x==boss[x])?x:boss[x]=search(boss[x]);
}
bool cmp(Node i,Node j){
    return i.w>j.w;
}
bool ok(int n,int m){
    for (int i=0;i<n;i++)
        boss[i]=i;
    for (int i=0;i<m;i++)
        scanf("%d %d %lf",&path[i].a,&path[i].b,&path[i].w);
    std::stable_sort(path,path+m,cmp);
    int at=0,bossa,bossb;
    ans=1e10;
    for (int i=0;i<n-1;i++){
        while (at<m&&(bossa=search(path[at].a))==(bossb=search(path[at].b)))
            at++;
        if (at==m)
            return false;
        if (path[at].w<ans)
            ans=path[at].w;
        boss[bossb]=bossa;
        at++;
    }
    return true;
}
int main()
{
    int cases,n,m;
    while (scanf("%d",&cases)==1)
        while (cases--){
            scanf("%d %d",&n,&m);
            if (n==1){
                puts("No way.");
                continue;
            }
            (ok(n,m))?printf("%.4lf\n",ans):puts("The empire of Arcturus is ending.");
        }
    return 0;
}
