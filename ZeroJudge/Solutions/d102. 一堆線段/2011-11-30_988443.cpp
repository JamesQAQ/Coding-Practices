#include <cstdio>
#include <algorithm>

char s[1000];
int a[100],n,dp[1000002];
int main()
{
    int x,maxx;
    while (gets(s)){
        x=n=maxx=0;
        for (int i=0;s[i];i++){
            if (s[i]>='0'&&s[i]<='9')
                x=x*10+s[i]-48;
            else
                a[n++]=x,maxx=((maxx>x)?maxx:x),x=0;
        }
        a[n++]=x;
        maxx=((maxx>x)?maxx:x);
        if (a[0]==0)
            break;
        std::stable_sort(a,a+n);
        dp[0]=1;
        for (int i=1;i<=maxx+1;i++)
            dp[i]=0;
        int ans=0;
        for (int i=0;i<n;i++){
            ans+=dp[maxx+1];
            dp[maxx+1]<<=1;
            for (int j=maxx;j>=0;j--){
                if (j>a[i])
                    ans+=dp[j];
                if (a[i]+j>maxx)
                    dp[maxx+1]+=dp[j];
                else
                    dp[a[i]+j]+=dp[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
