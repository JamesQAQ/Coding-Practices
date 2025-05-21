#include <cstdio>

// 0 : number  1 : +  2 : *
int len,isp[128],icp[128],num,top,mod=10007;
char s[100001],stack[100001],se[220000];
int dp[100001][2],dpnum;
int main()
{
    isp['+']=icp['+']=1;
    isp['*']=icp['*']=2;
    isp['(']=0;icp['(']=3;
    scanf("%d %s",&len,s);
    num=0;
    for (int i=0;i<len;i++){
        if (s[i]=='+'||s[i]=='*'){
            if (i&&s[i-1]!=')')
                se[num++]='_';
            else if (i==0)
                se[num++]='_';
        }
        else if (s[i]==')'&&s[i-1]!=')')
            se[num++]='_';
        if (s[i]==')'){
            while (stack[top-1]!='(')
                se[num++]=stack[top-1],top--;
            top--;
        }
        else{
            while (top&&isp[stack[top-1]]>icp[s[i]])
                se[num++]=stack[top-1],top--;
            stack[top++]=s[i];
        }
    }
    if (s[len-1]!=')')
        se[num++]='_';
    while (top)
        se[num++]=stack[top-1],top--;
    dpnum=0;
    for (int i=0;i<num;i++){
        if (se[i]=='_')
            dp[dpnum][0]=1,dp[dpnum][1]=1,dpnum++;
        else if (se[i]=='+'){
            dpnum--;
            int zero=(dp[dpnum-1][0]*dp[dpnum][0])%mod;
            int one=(dp[dpnum-1][0]*dp[dpnum][1]+dp[dpnum-1][1]*dp[dpnum][0]+dp[dpnum-1][1]*dp[dpnum][1])%mod;
            dp[dpnum-1][0]=zero,dp[dpnum-1][1]=one;
        }
        else{
            dpnum--;
            int one=(dp[dpnum-1][1]*dp[dpnum][1])%mod;
            int zero=(dp[dpnum-1][0]*dp[dpnum][1]+dp[dpnum-1][1]*dp[dpnum][0]+dp[dpnum-1][0]*dp[dpnum][0])%mod;
            dp[dpnum-1][0]=zero,dp[dpnum-1][1]=one;
        }
    }
    printf("%d\n",dp[0][0]);
}
