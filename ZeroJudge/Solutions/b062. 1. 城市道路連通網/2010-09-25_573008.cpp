#include <iostream>
#include <stdio.h>
using namespace std;

int map[33][33]={0};
int m,maxlen,sum,end;
int main()
{
    int start;
    while (scanf("%d",&m)==1)
    {
        char s[50];
        int dp[52][33][33]={0};
        for (int i=0;i<m;i++)
        {
            scanf("%s",&s);
            for (int j=0;j<m;j++)
            {
                map[i][j]=s[j]-48;
                dp[1][i][j]=s[j]-48;
            }
        }
        scanf("%d",&start); start--;
        scanf("%d",&end); end--;
        scanf("%d",&maxlen);
        for (int l=1;l<=maxlen;l++)
            for (int a=0;a<m;a++)
                for (int b=0;b<m;b++)
                    for (int c=0;c<m;c++)
                        if (map[a][c]==1)
                            dp[l][a][b]=dp[l][a][b]+dp[l-1][c][b];
        sum=0;
        for (int i=1;i<=maxlen;i++)
            sum+=dp[i][start][end];
        printf("%d\n",sum);
    }
    return 0;
}
