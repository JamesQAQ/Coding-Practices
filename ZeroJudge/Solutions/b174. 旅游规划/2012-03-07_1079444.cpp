#include <cstdio>
#include <vector> 

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
std::vector <int> path[200000];
int son1[200000],son2[200000];
struct Stack_son {int x,f,i;} stack_son[200000];
void dfs_son(int X,int F){
    int top=1;
    stack_son[0].x=X,stack_son[0].f=F,stack_son[0].i=0;
    while (top){
        Stack_son *p=&stack_son[top-1];
        if (p->i==0)
            son1[p->x]=son2[p->x]=0;
        if (p->i){
            int to=path[p->x][p->i-1];
            if (to!=p->f){
                if (son1[to]+1>=son1[p->x])
                    son2[p->x]=son1[p->x],son1[p->x]=son1[to]+1;
                else if (son1[to]+1>son2[p->x])
                    son2[p->x]=son1[to]+1;
            }
        }
        if (p->i==path[p->x].size()){
            top--;
            continue;
        }
        int to=path[p->x][p->i];
        if (to!=p->f){
            (p+1)->i=0;
            (p+1)->x=to;
            (p+1)->f=p->x;
            top++;
        }
        p->i++;
    }
}
int d[200000],maxx=0;
struct Stack_dp{int x,f,head,i;} stack_dp[200000];
void dp(int X,int F,int Head){
    int top=1;
    stack_dp[0].x=X,stack_dp[0].f=F,stack_dp[0].head=Head,stack_dp[0].i=0;
    while (top){
        Stack_dp *p=&stack_dp[top-1];
        if (p->i==0){
            d[p->x]=son1[p->x]+((p->head>son2[p->x])?p->head:son2[p->x]);
            if (d[p->x]>maxx) maxx=d[p->x];
        }
        if (p->i==path[p->x].size()){
            top--;
            continue;
        }
        int to=path[p->x][p->i];
        if (to!=p->f){
            int son=(son1[p->x]==son1[to]+1)?son2[p->x]:son1[p->x];
            int v=((p->head>son)?p->head:son)+1;
            (p+1)->i=0;
            (p+1)->x=to;
            (p+1)->f=p->x;
            (p+1)->head=v;
            top++;
        }
        p->i++;
    }
}
int main()
{
    int n=input(),a,b;
    for (int i=0;i<n-1;i++){
        a=input(),b=input();
        path[a].push_back(b);
        path[b].push_back(a);
    }
    dfs_son(0,-1);
    dp(0,-1,0);
    for (int i=0;i<n;i++)
        if (d[i]==maxx)
            printf("%d\n",i);
}
