#include <cstdio>

int p,q,Q;
long long ans;
bool found;
void dfs(int x,long long sum,int a,int b){
    if (x==p){
        if (sum%Q==0){
            ans=sum;
            found=true;
        }
        return;
    }
    dfs(x+1,sum*10+a,a,b);
    if (found)
        return;
    dfs(x+1,sum*10+b,a,b);
    if (found)
        return;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++){
        scanf("%d %d",&p,&q);
        Q=(1<<q);
        printf("Case %d:",t);
        long long ans1,ans2;
        ans=-1,found=false,dfs(0,0,1,2),ans1=ans;
        if (ans==-1)
            puts(" impossible");
        else{
            found=false,dfs(0,0,2,1),ans2=ans;
            if (ans1==ans2)
                printf(" %lld\n",ans1);
            else{
                putchar(' ');
                printf("%lld",ans1);
                putchar(' ');
                printf("%lld\n",ans2);
            }
        }
    }
}
