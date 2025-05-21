#include <cstdio>

long long tree[2000000],a[2000000],ans,mark[2000000]={},k;
int x,y;
int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c!=' '&&c!='\n'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
void create(int at,int l,int r){
    if (l==r){
        tree[at]=a[l];
        return;
    }
    int mid=(l+r)/2;
    create(2*at,l,mid);
    create(2*at+1,mid+1,r);
    tree[at]=tree[2*at]+tree[2*at+1];
}
void spread(int at,int l,int r){
    if (l!=r){
        mark[2*at]+=mark[at];
        mark[2*at+1]+=mark[at];
    }
    tree[at]+=(r-l+1)*mark[at];
    mark[at]=0;
}
void plus(int at,int l,int r){
    if (l>=x&&r<=y){
        mark[at]+=k;
        return;
    }
    int mid=(l+r)/2;
    if (mid>=x)
        plus(2*at,l,mid);
    if (mid+1<=y)
        plus(2*at+1,mid+1,r);
    if (mark[2*at]>0)
        spread(2*at,l,mid);
    if (mark[2*at+1]>0)
        spread(2*at+1,mid+1,r);
    tree[at]=tree[2*at]+tree[2*at+1];
}
void search(int at,int l,int r){
    if (mark[at])
        spread(at,l,r);
    if (l>=x&&r<=y){
        ans+=tree[at];
        return;
    }
    int mid=(l+r)/2;
    if (mid>=x)
        search(2*at,l,mid);
    if (mid+1<=y)
        search(2*at+1,mid+1,r);
}
int main()
{
    int n,q,v;
    n=input();
    //scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i]=input();
        //scanf("%d",&a[i]);
    create(1,1,n);
    q=input();
    //scanf("%d",&q);
    for (int i=0;i<q;i++){
        v=input();
        //scanf("%d",&v);
        if (v==1){
            x=input();
            y=input();
            k=input();
            //scanf("%d %d %d",&x,&y,&k);
            plus(1,1,n);
        }
        else{
            x=input();
            y=input();
            //scanf("%d %d",&x,&y);
            ans=0;
            search(1,1,n);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
