#include <cstdio>

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
struct Node {int t[2000];} tree[2000];
int a[500][500],maxx,n,m;
inline int max(int a,int b){
    return (a>b)?a:b;
}
void init(Node &T,int at,int l,int r,int x){
    if (l==r){
        T.t[at]=a[x][l];
        return;
    }
    int mid=(l+r)/2;
    init(T,2*at,l,mid,x);
    init(T,2*at+1,mid+1,r,x);
    T.t[at]=max(T.t[2*at],T.t[2*at+1]);
}
int needcheck[2000],num=0;
void combin(Node &T1,Node &T2,Node &T3){
    for (int i=0;i<num;i++){
        int at=needcheck[i];
        T1.t[at]=max(T2.t[at],T3.t[at]);
    }
}
void INIT(int at,int l,int r){
    if (l==r){
        init(tree[at],1,0,m-1,l);
        return;
    }
    int mid=(l+r)/2;
    INIT(2*at,l,mid);
    INIT(2*at+1,mid+1,r);
    combin(tree[at],tree[2*at],tree[2*at+1]);
}
void build(int at,int l,int r){
    needcheck[num++]=at;
    if (l==r)
        return;
    int mid=(l+r)/2;
    build(2*at,l,mid);
    build(2*at+1,mid+1,r);
}
int ATL,atl,ATR,atr;
int se[2000],xd;
void search(Node &T,int at,int l,int r){
    if (atl<=l&&r<=atr){
        maxx=max(maxx,T.t[at]);
        se[xd++]=at;
        return;
    }
    int mid=(l+r)/2;
    if (mid>=atl)
        search(T,2*at,l,mid);
    if (mid+1<=atr)
        search(T,2*at+1,mid+1,r);
}
bool first;
void SEARCH(int at,int l,int r){
    if (ATL<=l&&r<=ATR){
        if (first){
            xd=0;
            search(tree[at],1,0,m-1);
            first=false;
        }
        else{
            for (int i=0;i<xd;i++)
                maxx=max(maxx,tree[at].t[se[i]]);
        }
        return;
    }
    int mid=(l+r)/2;
    if (mid>=ATL)
        SEARCH(2*at,l,mid);
    if (mid+1<=ATR)
        SEARCH(2*at+1,mid+1,r);
}
int main()
{
    int q;
    n=input(),m=input();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            a[i][j]=input();
    build(1,0,m-1);
    INIT(1,0,n-1);
    q=input();
    for (int i=0;i<q;i++){
        ATL=input()-1,atl=input()-1,ATR=input()-1,atr=input()-1;
        maxx=0;
        first=true;
        SEARCH(1,0,n-1);
        printf("%d\n",maxx);
    }
}
