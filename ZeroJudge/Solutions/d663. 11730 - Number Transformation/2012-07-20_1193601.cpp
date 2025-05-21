#include <cstdio>

int d[101][1001],Q[1000];
int prime[1000]={2},pnum=1;
bool p[1001];
void sieve(){
    for (int i=3;i<=1000;i+=2)
        p[i]=true;
    for (int i=3;i<=1000;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<=1000;j+=2*i)
                p[j]=false;
        }
}
void BFS(int k){
    //printf("BFS %d\n",k);
    int l=0,r=1;
    Q[0]=k;
    d[k][k]=0;
    while (l<r){
        int x=Q[l++],tmpx=x;
        //printf("to %d\n",x);
        //getchar();
        for (int i=0;prime[i]<x&&i<pnum;i++)
            if (x%prime[i]==0){
                int xx=x+prime[i];
                if (xx<=1000&&d[k][xx]==-1){
                    d[k][xx]=d[k][x]+1;
                    Q[r++]=xx;
                }
            }
    }
}
int main()
{
    sieve();
    for (int i=1;i<=100;i++){
        for (int j=1;j<=1000;j++)
            d[i][j]=-1;
    }
    for (int i=1;i<=100;i++)
        BFS(i);//,getchar();
    int st,ed,t=0;
    while (scanf("%d %d",&st,&ed),st+ed)
        printf("Case %d: %d\n",++t,d[st][ed]);
}
