#include <cstdio>
#include <algorithm>
#include <queue>

int a[1000000],*p[1000000],num;
struct Node {
    int v;
    Node *next;
    int front(){
        return next->v;
    }
    void pop(){
        next=next->next;
    }
} Q[2000000];
bool cmp(int *i,int *j){
    return (*i)<(*j);
}
int main()
{
    int n,cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]),p[i]=&a[i];    
        std::stable_sort(p,p+n,cmp);
        int f=-1,cnt=0;
        for (int i=0;i<n;i++){
            if (f!=(*p[i])){
                f=(*p[i]);
                cnt++;
            }
            (*p[i])=cnt-1;
        }
        for (int i=0;i<cnt;i++)
            Q[i].next=NULL;
        num=cnt;
        for (int i=n-1;i>=0;i--){
            Q[num].v=i;
            Q[num].next=Q[a[i]].next;
            Q[a[i]].next=&Q[num];
            num++;
        }
        int ans=1,L=0;
        for (int i=1;i<n;i++){
            int v=Q[a[i]].front();
            if (v<i){
                Q[a[i]].pop();
                if (v+1>L)
                    L=v+1;
            }
            if (i-L+1>ans)
                ans=i-L+1;
        }
        printf("%d\n",ans);
    }
}
