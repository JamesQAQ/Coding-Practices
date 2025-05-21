#include <cstdio>

int mini[10000001],way[10000001];
bool use[10000001]={};
void dfs(int n,int &Min,int &Way){
    if (n<=10000000&&use[n])
        Min=mini[n],Way=way[n];
    else{
        Min=2147483647,Way=0;
        for (int i=1;(long long)i*i<=n;i++)
            if (n%i==0){
                int tMin,tWay,p=n/i;
                if (p!=n){
                    dfs(p,tMin,tWay);
                    if (tMin+i<Min)
                        Min=tMin+i,Way=tWay;
                    else if (tMin+i==Min)
                        Way+=tWay;
                }
                if (p!=i){
                    dfs(i,tMin,tWay);
                    if (tMin+p<Min)
                        Min=tMin+p,Way=tWay;
                    else if (tMin+p==Min)
                        Way+=tWay;
                }
            }
        if (n<=10000000)
            use[n]=true,mini[n]=Min,way[n]=Way;
    }
}
int main()
{
    mini[1]=0,way[1]=1,use[1]=true;
    int n,Min,Way;
    while (scanf("%d",&n)==1){
        dfs(n,Min,Way);
        printf("min : %d\nway : %d\n",Min,Way);
    }
}
