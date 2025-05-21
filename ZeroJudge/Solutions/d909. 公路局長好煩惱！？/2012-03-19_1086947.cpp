#include <cstdio>
#include <algorithm>

struct Node {int a,b,w;} path[10000000];
int t[10000000],t2[10000000],boss[10000];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
void merge(int l,int mid,int r){
    for (int i=l;i<=r;i++)
        t2[i]=t[i];
    int atl=l,atr=mid+1;
    for (int i=l;i<=r;i++){
        if (atl==mid+1||(atr<=r&&path[t2[atr]].w<path[t2[atl]].w))
            t[i]=t2[atr++];
        else
            t[i]=t2[atl++];
    }
}
void merge_sort(int l,int r){
    if (l==r)
        return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}
int find(int x){
    return (x==boss[x])?x:(boss[x]=find(boss[x]));
}
int main()
{
    int n,m;
    n=input(),m=input();
    for (int i=0;i<n;i++)
        boss[i]=i;
    for (int i=0;i<m;i++)
        path[i].a=input(),path[i].b=input(),path[i].w=input(),t[i]=i;
    merge_sort(0,m-1);
    int ans=0,at=0,bossa,bossb;
    for (int j=0;j<n-1;j++){
        while (at<m&&(bossa=find(path[t[at]].a))==(bossb=find(path[t[at]].b)))
            at++;
        boss[bossb]=bossa;
        ans+=path[t[at]].w;
    }
    printf("%d\n",ans);
}
