#include <cstdio>

int bigger[400000];
void create(int l,int r,int at){
    bigger[at]=0;
    if (l==r)
        return;
    int mid=(l+r)/2;
    create(l,mid,2*at);
    create(mid+1,r,2*at+1);
}
int search(int l,int r,int at,int x){
    if (l==r)
        return bigger[at];
    int mid=(l+r)/2;
    if (x<=mid)
        return search(l,mid,2*at,x)+bigger[at];
    else{
        bigger[2*at]++;
        return search(mid+1,r,2*at+1,x)+bigger[at];
    }
}
int main()
{
    int n,temp;
    while (scanf("%d",&n)==1){
        create(1,n,1);
        for (int i=0;i<n;i++){
            scanf("%d",&temp);
            printf("%d\n",search(1,n,1,temp)+1);
        }
    }
    return 0;
}
