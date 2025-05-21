#include <iostream>
#include <cstdio>
using namespace std;

int abs(int x){
    return (x<0)?-x:x;
}
int n,star=-1;
struct Node {int pointl,pointr,l,r;} tree[100001];
int dfs(int x,int d){
    int l_l,l_r,r_l,r_r,l=tree[x].pointl,r=tree[x].pointr,sum_l=0,sum_r=0;
    if (l==-1){
        l_l=l_r=d;
        if (star!=-1&&abs(star-d)>1)
                return -1;
        else
            star=d;
    }
    else{
        sum_l=dfs(l,d+1);
        if (sum_l==-1)
            return -1;
        l_l=tree[l].l;
        l_r=tree[l].r;
    }
    if (r==-1)
        r_l=r_r=d;
    else{
        sum_r=dfs(r,d+1);
        if (sum_r==-1)
            return -1;
        r_l=tree[r].l;
        r_r=tree[r].r;
    }
    if (l_r<r_l){
        sum_l++;
        swap(l_l,r_l);
        swap(l_r,r_r);
    }
    if (l_r==r_l||l_r-r_l==1){
        if (l_l-r_r>1)
            return -1;
        tree[x].l=l_l;
        tree[x].r=r_r;
        return sum_l+sum_r;
    }
    else
        return -1;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d %d",&tree[i].pointl,&tree[i].pointr);
    printf("%d\n",dfs(1,0));
    //system("pause");
    return 0;
}
