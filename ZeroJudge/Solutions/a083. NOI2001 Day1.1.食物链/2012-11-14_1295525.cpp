#include <cstdio>

int boss[100000],dis[100000];
int find(int x){
    if (x==boss[x])
        return x;
    int tmp=find(boss[x]);
    dis[x]+=dis[boss[x]];
    dis[x]%=3;
    boss[x]=tmp;
    return boss[x];
}
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int n,m,c,a,b;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        boss[i]=i,dis[i]=0;
    int ans=0;
    for (int i=0;i<m;i++){
        c=input();
        a=input();
        b=input();
        if (a>n||b>n){
            ans++;
            continue;
        }
        int bossa=find(a),bossb=find(b);
        c--;
        if (bossa==bossb){
            int D=dis[b]-dis[a];
            if (D<0)
                D+=3;
            if (D!=c)
                ans++;
        }
        else{
            boss[bossb]=bossa;
            dis[bossb]=(dis[a]-dis[b]+c)%3;
            if (dis[bossb]<0)
                dis[bossb]+=3;
        }
    }
    printf("%d\n",ans);
}
/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/
