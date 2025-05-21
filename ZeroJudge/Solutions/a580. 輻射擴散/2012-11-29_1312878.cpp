#include <cstdio>
#include <algorithm>

struct Node{
    int x,y;
} node[20000],A,B;
struct Dist{
    int a,b;
} dist[20000];
int distance(Node a,Node b){
    int x=a.x-b.x,y=a.y-b.y;
    return x*x+y*y;
}
bool cmp(Dist i,Dist j){
    return i.a<j.a;
}
struct Quer{
    int ra,rb,no;
} query[20000];
bool cmpq(Quer i,Quer j){
    return i.ra<j.ra;
}
int *bptr[40000],ptrnum;
bool cmpptr(int *i,int *j){
    return (*i)<(*j);
}
int tree[50000],ans[20000];
void update(int x,int n){
    while (x<=n){
        tree[x]++;
        x+=x&(-x);
    }
}
int search(int x,int n){
    int sum=0;
    while (x>=1){
        sum+=tree[x];
        x-=x&(-x);
    }
    return sum;
}
int main()
{
    int n,m,cases=0;
    while (scanf("%d",&n),n){
        for (int i=0;i<n;i++)
            scanf("%d %d",&node[i].x,&node[i].y);
        scanf("%d %d",&A.x,&A.y);
        scanf("%d %d",&B.x,&B.y);
        ptrnum=0;
        for (int i=0;i<n;i++){
            dist[i].a=distance(node[i],A);
            dist[i].b=distance(node[i],B);
            bptr[ptrnum++]=&dist[i].b;
        }
        std::stable_sort(dist,dist+n,cmp);
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            scanf("%d %d",&query[i].ra,&query[i].rb);
            query[i].ra*=query[i].ra;
            query[i].rb*=query[i].rb;
            query[i].no=i;
            bptr[ptrnum++]=&query[i].rb;
        }
        std::stable_sort(query,query+m,cmpq);
        std::stable_sort(bptr,bptr+ptrnum,cmpptr);
        int f=-1,num=1;
        for (int i=0;i<ptrnum;i++){
            if (f!=(*bptr[i])){
                f=(*bptr[i]);
                num++;
            }
            (*bptr[i])=num-1;
        }
        num--;
        for (int i=1;i<=num;i++)
            tree[i]=0;
        int at=0;
        for (int i=0;i<m;i++){
            while (at<n&&dist[at].a<=query[i].ra)
                update(dist[at].b,num),at++;
            ans[query[i].no]=search(query[i].rb,num);
        }
        printf("Case %d:\n",++cases);
        for (int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
}
