#include <cstdio>
#include <algorithm>

struct Node {int l,r;} data[100],temp;
bool cmp(Node i,Node j){
    return i.l<j.l;
}
int main()
{
    int l,m;
    while (scanf("%d %d",&l,&m)==2){
        for (int i=0;i<m;i++)
            scanf("%d %d",&data[i].l,&data[i].r);
        int ans=l+1;
        std::stable_sort(data,data+m,cmp);
        temp=data[0];
        for (int i=1;i<m;i++){
            if (data[i].l>temp.r){
                ans-=temp.r-temp.l+1;
                temp=data[i];
            }
            else if (data[i].r>temp.r)
                temp.r=data[i].r;
        }
        ans-=temp.r-temp.l+1;
        printf("%d\n",ans);
    }
    return 0;
}
