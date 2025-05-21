#include <cstdio>

bool p[31622]={};
int prime[31622],pnum;
void sieve(){
    pnum=1,prime[0]=2;
    for (int i=3;i<31622;i+=2)
        p[i]=true;
    for (int i=3;i<31622;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<31622;j+=2*i)
                p[j]=false;
        }
}
int get(int x){
    int sum=1;
    for (int i=0;i<pnum&&prime[i]<=x;i++)
        if (x%prime[i]==0){
            int tmp=0;
            while (x%prime[i]==0)
                x/=prime[i],tmp++;
            sum*=tmp+1;
        }
    if (x!=1)
        sum<<=1;
    return sum;
}
int main()
{
    sieve();
    int cases,L,R;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&L,&R);
        int ans=-1,maxx;
        for (int i=L;i<=R;i++){
            int v=get(i);
            if (ans==-1||v>maxx)
                ans=i,maxx=v;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,R,ans,maxx);
    }
}
