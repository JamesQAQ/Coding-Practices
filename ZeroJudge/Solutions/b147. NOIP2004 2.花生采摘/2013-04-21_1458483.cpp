#include <cstdio>
#include <algorithm>

int abs(int x){
    return (x<0)?-x:x;
}
struct Node{
    int x,y,v;
} a[900];
bool cmp(Node i,Node j){
    return i.v>j.v;
}
int main()
{
    int n,m,t,tmp,num=0;
    scanf("%d %d %d",&n,&m,&t);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            scanf("%d",&tmp);
            if (tmp>0){
                a[num].x=i;
                a[num].y=j;
                a[num].v=tmp;
                num++;
            }
        }
    std::stable_sort(a,a+num,cmp);
    int ans=0;
    int x=a[0].x,y=a[0].y;
    t-=abs(a[0].x-(-1));
    t--;
    if (t>=abs((-1)-x))
        ans+=a[0].v;
    for (int i=1;i<num;i++){
    	//printf("%d\n",t);
        t-=abs(a[i].x-x)+abs(a[i].y-y);
        t--;
        x=a[i].x,y=a[i].y;
        if (t>=abs(x-(-1)))
            ans+=a[i].v;
        else
            break;
    }
    printf("%d\n",ans);
}
