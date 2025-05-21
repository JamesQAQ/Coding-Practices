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
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int n,cases;
    cases=input();
    while (cases--){
        n=input();
        for (int i=0;i<n;i++)
            a[i]=input(),p[i]=&a[i];    
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
