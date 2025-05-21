#include <cstdio>
#include <vector>

long long ans=0;
struct Node {int to,w;} tmp;
std::vector <Node> path[1000001];
int sum[1000001],n;
struct Stack {int x,f,i;} stack[1000000];
int Abs(int x){
    return (x<0)?-x:x;
}
void dfs(int X,int F){
    int top=1;
    stack[0].x=X,stack[0].f=F,stack[0].i=0;
    while (top){
        Stack *p=&stack[top-1];
        if (p->i){
            int to=path[p->x][p->i-1].to;
            if (p->f!=to){
                ans+=(long long)Abs(n-2*sum[to])*path[p->x][p->i-1].w;
                sum[p->x]+=sum[to];
            }
        }
        if (p->i==0)
            sum[p->x]=1;
        if (p->i==path[p->x].size()){
            top--;
            continue;
        }
        int to=path[p->x][p->i].to;
        if (to!=p->f){
            (p+1)->x=to;
            (p+1)->f=p->x;
            (p+1)->i=0;
            top++;
        }
        p->i++;
    }
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
    int a;
    n=input();
    for (int i=0;i<n-1;i++){
        a=input(),tmp.to=input(),tmp.w=input();
        path[a].push_back(tmp);
        tmp.to^=a^=tmp.to^=a;
        path[a].push_back(tmp);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    
}
