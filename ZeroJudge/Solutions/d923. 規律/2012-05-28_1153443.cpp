#include <cstdio>

long long d[2][2]={{0,2},{3,1}};
long long dfs(long long x,long long y){
    long long l=(x>y)?x:y;
    if (l<2)
        return d[x][y]+1;
    long long i=1;
    while ((i<<1)<=l)
        i<<=1;
    return dfs(x%i,y%i)+d[x/i][y/i]*i*i;                
}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    x--,y--;
    printf("%lld\n",dfs(x,y));
}
