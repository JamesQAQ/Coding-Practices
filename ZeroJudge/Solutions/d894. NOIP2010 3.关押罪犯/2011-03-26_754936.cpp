#include <iostream>
#include <algorithm>
using namespace std;
int n,m,AB[20001],boss[20001],unlike[20001]={};
struct EDGE {int x,y,w;} edge[100000];
bool cmp(EDGE i,EDGE j){
    return i.w>j.w;
}
int find(int x){
    return (x==boss[x])?x:boss[x]=find(boss[x]);
}
void combin(int x,int y){
    if (x==0||y==0) return;
    boss[find(x)]=find(y);
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
        scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].w);
    for (int i=1;i<=n;i++)
        boss[i]=i;
    stable_sort(edge,edge+m,cmp);
    int ans=0;
    while (ans<m){
        int x=edge[ans].x,y=edge[ans].y;
        if (find(x)==find(y)) break;
        combin(x,unlike[y]);
        combin(y,unlike[x]);
        unlike[x]=y;
        unlike[y]=x;
        ans++;
    }
    if (ans==m) puts("0");
    else printf("%d\n",edge[ans].w);
    //system("pause");
    return 0;
}
