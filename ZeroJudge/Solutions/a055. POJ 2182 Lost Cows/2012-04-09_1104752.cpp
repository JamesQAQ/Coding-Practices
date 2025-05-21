#include <cstdio>

int c[80001],ans[80001],tree[400000];
void init(int at,int l,int r){
    tree[at]=r-l+1;
    if (l==r)
        return;
    int mid=(l+r)/2;
    init(2*at,l,mid);
    init(2*at+1,mid+1,r);
}
int find(int at,int l,int r,int k){
    tree[at]--;
    if (l==r)
        return l;
    int mid=(l+r)/2;
    if (k<=tree[2*at]) return find(2*at,l,mid,k);
    else return find(2*at+1,mid+1,r,k-tree[2*at]);
}
int main()
{
    int n;
    scanf("%d",&n);
    c[1]=0;
    for (int i=2;i<=n;i++)
        scanf("%d",&c[i]);
    init(1,1,n);
    for (int i=n;i>=1;i--)
        ans[i]=find(1,1,n,c[i]+1);
    for (int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}
