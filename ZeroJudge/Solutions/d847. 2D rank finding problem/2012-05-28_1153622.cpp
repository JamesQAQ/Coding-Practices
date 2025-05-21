#include <cstdio>
#include <algorithm>

struct Node {int x,y,no;} node[10000];
int ans[10000],tree[1001],o[1001]={},tag=0;
bool cmp(Node i,Node j){
    if (i.y<j.y)
        return true;
    if (i.y>j.y)
        return false;
    return i.x>j.x;
}
int search(int x){
    int sum=0;
    while (x>0){
        if (o[x]==tag)
            sum+=tree[x];
        x-=x&(-x);
    }
    return sum;
}
void insert(int x){
    while (x<=1000){
        if (o[x]!=tag)
            o[x]=tag,tree[x]=0;
        tree[x]++;
        x+=x&(-x);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%d %d",&node[i].x,&node[i].y),node[i].no=i;
        std::stable_sort(node,node+n,cmp);
        tag++;
        for (int i=0;i<n;i++){
            ans[node[i].no]=search(node[i].x-1);
            insert(node[i].x);
        }
        for (int i=0;i<n;i++)
            printf("%d\n",ans[i]);
    }
}
