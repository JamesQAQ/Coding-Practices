#include <cstdio>

int c,dp[1001],deque[1000],value[1000],l,r;
void zero_one(int v,int w){
    for (int i=c;i>=v;i--)
        if (dp[i-v]+w>dp[i])
            dp[i]=dp[i-v]+w;
}
void complete(int v,int w){
    for (int i=v;i<=c;i++)
        if (dp[i-v]+w>dp[i])
            dp[i]=dp[i-v]+w;
}
void multipack(int v,int w,int f){
    for (int d=0;d<v;d++){
        l=r=0;
        for (int i=0;i<=(c-d)/v;i++){
            int temp=dp[i*v+d]-i*w;
            while (l!=r&&temp>value[r-1])
                r--;
            deque[r]=i,value[r++]=temp;
            if (deque[l]<i-f)
                l++;
            dp[i*v+d]=value[l]+i*w;
        }
    }
}
int main()
{
    int n,v,w,f;
    scanf("%d %d",&n,&c);
    for (int i=0;i<=c;i++)
        dp[i]=0;
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&v,&w,&f);
        if (f==1)
            zero_one(w,v);
        else if (f==-1)
            complete(w,v);
        else if (f!=0)
            multipack(w,v,f);
    }
    printf("%d\n",dp[c]);
    return 0;
}
