#include <cstdio>
#include <algorithm>

int mod=1000000007;
struct Node {int x,y;} site[1000000];
int r,c,v[1001][1001],tree[1001][1001],p[1001];
bool cmp(Node i,Node j){
    if (v[i.x][i.y]!=v[j.x][j.y])
        return v[i.x][i.y]<v[j.x][j.y];
    if (i.x!=j.x)
        return i.x>j.x;
    return i.y>j.y;
}
void update(int x,int y,int v){
    for (;x<=r;x+=p[x])
        for (int j=y;j<=c;j+=p[j]){
            tree[x][j]+=v;
            if (tree[x][j]>=mod)
                tree[x][j]-=mod;
        }
}
int query(int x,int y){
    long long sum=0;
    for (;x>0;x-=p[x])
        for (int j=y;j>0;j-=p[j])
            sum+=(long long)tree[x][j];
    return sum%mod;
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
    for (int i=0;i<=1000;i++)
        p[i]=i&(-i);
    int cases,num;
    cases=input();
    while (cases--){
        num=0;
        r=input(),c=input();
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
                v[i][j]=input(),site[num].x=i,site[num].y=j,num++,tree[i][j]=0;
        std::stable_sort(site,site+num,cmp);
        long long ans=0;
        for (int i=0;i<num;i++){
            int v=query(site[i].x,site[i].y)+1;
            ans+=(long long)v;
            update(site[i].x,site[i].y,v);
        }
        printf("%d\n",ans%mod);
    }
}
