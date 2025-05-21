#include <cstdio>
#include <algorithm>

struct Node {int a,b,w;} edge[200000];
int boss[100000],n,m;
long long ans;
bool cmp(Node i,Node j){
    return i.w<j.w;
}
int search (int x){
    return (x==boss[x])?x:boss[x]=search(boss[x]);
}
bool ok(){
    int at=0,bossa,bossb;
    for (int i=0;i<n-1;i++){
        while (at<m&&(bossa=search(edge[at].a))==(bossb=search(edge[at].b)))
            at++;
        if (at==m)
            return false;
        ans+=(long long)edge[at].w;
        boss[bossb]=bossa;
        at++;
    }
    return true;
}
int main()
{
    while (scanf("%d %d",&n,&m)==2){
        for (int i=0;i<n;i++)
            boss[i]=i;
        for (int i=0;i<m;i++)
            scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].w);
        std::stable_sort(edge,edge+m,cmp);
        ans=0;
        (ok())?printf("%lld\n",ans):puts("-1");
    }
    return 0;
}
