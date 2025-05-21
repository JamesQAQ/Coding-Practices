#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

int n,fat,at,f,num,dp[2][200][200],d[200][200],MAX=2147483647;
void update(int now,int a,int b,int v){
    if (a>b)
        swap(a,b);
    if (v<dp[now][a][b])
        dp[now][a][b]=v;
}
int main()
{
    string s;
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&d[i][j]),dp[0][i][j]=MAX;
        getline(cin,s);
        getline(cin,s);
        stringstream ss(s);
        ss>>at,at--;
        num=0;
        dp[0][0][1]=d[2][at];
        dp[0][1][2]=d[0][at];
        dp[0][0][2]=d[1][at];
        fat=at;
        while (ss>>at){
            at--,num++;
            int f=(num-1)%2,now=num%2;
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    dp[now][i][j]=MAX;
            for (int i=0;i<n;i++)
                for (int j=i+1;j<n;j++)
                    if (dp[f][i][j]!=MAX){
                        update(now,i,j,dp[f][i][j]+d[fat][at]);
                        update(now,i,fat,dp[f][i][j]+d[j][at]);
                        update(now,fat,j,dp[f][i][j]+d[i][at]);
                    }
            fat=at;
        }
        int ans=MAX,now=num%2;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (dp[now][i][j]<ans)
                    ans=dp[now][i][j];
        printf("%d\n",ans);
    }
    return 0;
}
