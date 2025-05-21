#include <cstdio>
struct Node {
    int led,rst,mst,med;
    long long sum,lmax,rmax,mmax;
} tree[800000];
long long f0,f1,ans;
int a[200000];
int f1st,f1ed,ast,aed;
void update(long long v,int s,int e,long long &value,int &st,int &ed){
    if (v>value||(v==value&&(s<st||(s==st&&e<ed))))
        value=v,st=s,ed=e;
}
void build(int at,int l,int r){
    if (l==r){
        tree[at].led=tree[at].rst=tree[at].mst=tree[at].med=l;
        tree[at].sum=tree[at].lmax=tree[at].rmax=tree[at].mmax=(long long)a[l];
        return;
    }
    int mid=(l+r)/2,lat=2*at,rat=2*at+1;
    build(lat,l,mid);
    build(rat,mid+1,r);
    tree[at].sum=tree[lat].sum+tree[rat].sum;
    //sum
    if (tree[lat].lmax>=tree[lat].sum+tree[rat].lmax){
        tree[at].lmax=tree[lat].lmax;
        tree[at].led=tree[lat].led;
    }
    else{
        tree[at].lmax=tree[lat].sum+tree[rat].lmax;
        tree[at].led=tree[rat].led;
    }
    //lmax
    if (tree[rat].rmax>tree[lat].rmax+tree[rat].sum){
        tree[at].rmax=tree[rat].rmax;
        tree[at].rst=tree[rat].rst;
    }
    else{
        tree[at].rmax=tree[lat].rmax+tree[rat].sum;
        tree[at].rst=tree[lat].rst;
    }
    //rmax
    tree[at].mmax=tree[lat].mmax;
    tree[at].mst=tree[lat].mst,tree[at].med=tree[lat].med;
    if (tree[rat].mmax>tree[at].mmax){
        tree[at].mmax=tree[rat].mmax;
        tree[at].mst=tree[rat].mst,tree[at].med=tree[rat].med;
    }
    long long v=tree[lat].rmax+tree[rat].lmax;
    int st=tree[lat].rst,ed=tree[rat].led;
    if (v>tree[at].mmax||(tree[at].mmax==v&&(st<tree[at].mst||(st==tree[at].mst&&ed<tree[at].med)))){
        tree[at].mmax=v;
        tree[at].mst=st,tree[at].med=ed;
    }
    //mmax
    /*printf("%d-%d sum %I64d:\n",l,r,tree[at].sum);
    printf("lmax %d-%d %I64d\n",l,tree[at].led,tree[at].lmax);
    printf("rmax %d-%d %I64d\n",tree[at].rst,r,tree[at].rmax);
    printf("mmax %d-%d %I64d\n",tree[at].mst,tree[at].med,tree[at].mmax);*/
}
void search(int at,int l,int r,int dl,int dr){
    if (l>=dl&&r<=dr){
        update(tree[at].mmax,tree[at].mst,tree[at].med,ans,ast,aed);
        update(f1+tree[at].lmax,f1st,tree[at].led,ans,ast,aed);
        f1=f1+tree[at].sum,f1ed=r;
        update(tree[at].rmax,tree[at].rst,r,f1,f1st,f1ed);
        update(f1,f1st,f1ed,ans,ast,aed);
        return;
    }
    int mid=(l+r)/2;
    if (mid>=dl)
        search(2*at,l,mid,dl,dr);
    if (mid+1<=dr)
        search(2*at+1,mid+1,r,dl,dr);
}
int main()
{
    int n,m,t=0,l,r;
    while (scanf("%d %d",&n,&m)==2){
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        build(1,0,n-1);
        printf("Case %d:\n",++t);
        for (int i=0;i<m;i++){
            scanf("%d %d",&l,&r);
            ans=-10000000000000LL;
            l--,r--;
            f1=0,f1st=l;
            search(1,0,n-1,l,r);
            printf("%d %d %lld\n",ast+1,aed+1,ans);
        }
    }
    return 0;
}
