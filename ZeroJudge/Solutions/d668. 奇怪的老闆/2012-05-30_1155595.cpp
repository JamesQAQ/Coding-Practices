#include <cstdio>

int a[50001],Max,Min;
int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
struct Node{
    int maxx,mini;
} tree[200000];
void init(int at,int l,int r){
    if (l==r){
        tree[at].maxx=tree[at].mini=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(2*at,l,mid);
    init(2*at+1,mid+1,r);
    tree[at].maxx=max(tree[2*at].maxx,tree[2*at+1].maxx);
    tree[at].mini=min(tree[2*at].mini,tree[2*at+1].mini);
}
int A,B;
void search(int at,int l,int r){
    if (A<=l&&r<=B){
        Max=max(Max,tree[at].maxx);
        Min=min(Min,tree[at].mini);
        return;
    }
    int mid=(l+r)/2;
    if (A<=mid)
        search(2*at,l,mid);
    if (B>=mid+1)
        search(2*at+1,mid+1,r);
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init(1,1,n);
    for (int i=0;i<q;i++){
        scanf("%d %d",&A,&B);
        Max=0,Min=2147483647;
        search(1,1,n);
        printf("%d\n",Max-Min);
    }
}
