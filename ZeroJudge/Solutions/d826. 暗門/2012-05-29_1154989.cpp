#include <cstdio>

int p[100001];
int Abs(int x){
    return (x<0)?-x:x;
}
int main()
{
    int n,m,ans,tmp;
    while (scanf("%d %d",&n,&m)==2){
        ans=0;
        for (int i=1;i<=n;i++)
            p[i]=0;
        for (int i=0;i<m;i++)
            scanf("%d",&tmp),p[tmp]++;
        int v=m/n;
        for (int i=1;i<n;i++){
            int need=v-p[i];
            p[i+1]-=need;
            ans+=Abs(need);
        }
        printf("%d\n",ans);
    }    
}
