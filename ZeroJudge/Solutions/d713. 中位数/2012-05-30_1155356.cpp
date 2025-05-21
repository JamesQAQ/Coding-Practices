#include <cstdio>
#include <algorithm>

int a[200000],n=0,*p[200000],tree[800000]={},d[200000];
bool cmp(int *i,int *j){
    return (*i)<(*j);
}
void insert(int at,int l,int r,int x){
    tree[at]++;
    if (l==r)
        return;
    int mid=(l+r)/2;
    if (x<=mid)
        insert(2*at,l,mid,x);
    if (x>=mid+1)
        insert(2*at+1,mid+1,r,x);
}
int search(int at,int l,int r,int k){
    if (l==r)
        return d[l];
    int mid=(l+r)/2;
    if (tree[2*at]>=k)
        return search(2*at,l,mid,k);
    else
        return search(2*at+1,mid+1,r,k-tree[2*at]);
}
int main()
{
    while (scanf("%d",&a[n])==1)
        p[n]=&a[n],n++;
    std::stable_sort(p,p+n,cmp);
    for (int i=0;i<n;i++)
        d[i]=(*p[i]),(*p[i])=i;
    for (int i=0;i<n;i++){
        insert(1,0,n-1,a[i]);
        if (i&1)
            printf("%d\n",(search(1,0,n-1,i/2+1)+search(1,0,n-1,(i+1)/2+1))/2);
        else
            printf("%d\n",search(1,0,n-1,(i+1)/2+1));
    }
    //while (1);
}
