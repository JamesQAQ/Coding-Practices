#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int dp[2][1001],*pre,*now,mini,ans,MAX=2147483647;
int main()
{
    pre=dp[0];
    now=dp[1];
    int U,L,u[1001],l[1001];
    while (scanf("%d %d",&U,&L)==2){
        for (int i=0;i<U;i++)
            scanf("%d",&u[i]);
        for (int i=0;i<L;i++)
            scanf("%d",&l[i]);
        for (int i=0;i<U;i++)
            pre[i]=0;
        mini=0;
        for (int i=0;i<U;i++){
            for (int j=i;j<=L-U+i;j++){
                now[j]=mini+abs(u[i]-l[j]);
                mini=min(mini,pre[j]);
            }
            mini=now[i];
            swap(pre,now);
        }
        mini=MAX;
        for (int i=U-1;i<L;i++)
            mini=min(mini,pre[i]);
        printf("%d\n",mini);
    }
    return 0;
}
