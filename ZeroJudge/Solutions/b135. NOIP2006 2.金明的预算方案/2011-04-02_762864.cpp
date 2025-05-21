#include <iostream>
using namespace std;

int main()
{
    bool use[61]={};
    int n,m,dp[32001]={},v[61],w[61],q,num[61]={},p[61][2];
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d %d %d",&w[i],&v[i],&q);
        v[i]*=w[i];
        if (q!=0){
            use[i]=1;
            p[q][num[q]++]=i;
        }
    }
    for (int i=1;i<=m;i++)
        if (!use[i]){
            int ww=w[i],ww1,ww2,ww12,vv=v[i],vv1,vv2,vv12,temp1=-1,temp2=-1;
            if (num[i]>0){
                temp1=p[i][0];
                ww1=ww+w[temp1];
                vv1=vv+v[temp1];
            }
            if (num[i]>1){
                temp2=p[i][1];
                ww2=ww+w[temp2];
                vv2=vv+v[temp2];
                ww12=ww1+w[temp2];
                vv12=vv1+v[temp2];
            }
            for (int j=n;j>=ww;j--){
                dp[j]=max(dp[j],dp[j-ww]+vv);
                if (temp1!=-1)
                    if (j>=ww1)
                        dp[j]=max(dp[j],dp[j-ww1]+vv1);
                if (temp2!=-1){
                    if (j>=ww2)
                        dp[j]=max(dp[j],dp[j-ww2]+vv2);
                    if (j>=ww12)
                        dp[j]=max(dp[j],dp[j-ww12]+vv12);
                }
            }
        }
    printf("%d\n",dp[n]);
    return 0;
}
