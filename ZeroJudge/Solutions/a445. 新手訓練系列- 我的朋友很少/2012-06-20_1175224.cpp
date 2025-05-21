#include <cstdio>

int boss[10001];
int find(int x){
    return (x==boss[x])?x:(boss[x]=find(boss[x]));
}
int main()
{
    int n,m,q,a,b;
    while (scanf("%d %d %d",&n,&m,&q)==3){
        for (int i=1;i<=n;i++)
            boss[i]=i;
        while (m--){
            scanf("%d %d",&a,&b);
            boss[find(b)]=find(a);
        }
        while (q--){
            scanf("%d %d",&a,&b);
            puts((find(a)==find(b))?":)":":(");
        }
    }
}
