#include <cstdio>

int a[1000001],tree[4000000];
bool tag=false;
int cnt(long long x){
    if (x>1000000)
        return 1+cnt((x&1)?3*x+1:x/2);
    if (a[x]==0)
        a[x]=1+cnt((x&1)?3*x+1:x/2);
    return a[x];
}
int max(int a,int b){
    return (a>b)?a:b;
}
void build(int at,int l,int r){
    if (l==r){
        tree[at]=cnt(l);
        return;
    }
    int mid=(l+r)/2;
    build(at<<1,l,mid),build((at<<1)+1,mid+1,r);
    tree[at]=max(tree[at<<1],tree[(at<<1)+1]);
}
int maxx;
void search(int at,int l,int r,int dl,int dr){
    if (l>=dl&&r<=dr){
        if (tree[at]>maxx)
            maxx=tree[at];
        return;
    }
    int mid=(l+r)/2;
    if (mid>=dl)
        search(at<<1,l,mid,dl,dr);
    if (mid+1<=dr)
        search((at<<1)+1,mid+1,r,dl,dr);
}
int main()
{
    a[1]=1;
    build(1,1,1000000);
    int dl,dr,Ol,Or;
    while (scanf("%d %d",&dl,&dr)==2){
        maxx=0;
        Ol=dl,Or=dr;
        if (dl>dr)
            dl^=dr^=dl^=dr;
        search(1,1,1000000,dl,dr);
        printf("%d %d %d\n",Ol,Or,maxx);
    }
}
