#include <cstdio>
#include <iostream>
using namespace std;

char map[501][502]={};
int n,ans,sqr[502][502],kit[4][502][502];
int main()
{
    char *p;
    while (scanf("%d",&n)==1){
        ans=0;
        for (int i=1;i<=n;i++)
            p=map[i]+1,scanf("%s",p);
        for (int i=0;i<=n+1;i++)
            sqr[0][i]=kit[0][0][i]=kit[1][0][i]=0;
        for (int i=1;i<=n;i++){
            sqr[i][0]=0;
            for (int j=1;j<=n;j++){
                (map[i][j]=='.')?sqr[i][j]=0:sqr[i][j]=min(sqr[i-1][j],min(sqr[i-1][j-1],sqr[i][j-1]))+1;
                if (sqr[i][j]>1)
                    ans+=sqr[i][j]-1;
            }
        }
        for (int i=1;i<=n;i++){
            kit[0][i][0]=0;
            for (int j=1;j<=n;j++)
                (map[i][j]=='.')?kit[0][i][j]=0:kit[0][i][j]=min(kit[0][i-1][j],kit[0][i][j-1])+1;
        }
        for (int i=1;i<=n;i++){
            kit[1][i][n+1]=0;
            for (int j=n;j>=0;j--)
                (map[i][j]=='.')?kit[1][i][j]=0:kit[1][i][j]=min(kit[1][i-1][j],kit[1][i][j+1])+1;
        }
        for (int i=0;i<=n+1;i++)
            kit[2][n+1][i]=kit[3][n+1][i]=0;
        for (int i=n;i>=1;i--){
            kit[2][i][0]=0;
            for (int j=1;j<=n;j++)
                (map[i][j]=='.')?kit[2][i][j]=0:kit[2][i][j]=min(kit[2][i+1][j],kit[2][i][j-1])+1;
        }
        for (int i=n;i>=1;i--){
            kit[3][i][0]=0;
            for (int j=n;j>=1;j--)
                (map[i][j]=='.')?kit[3][i][j]=0:kit[3][i][j]=min(kit[3][i+1][j],kit[3][i][j+1])+1;
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<n;j++){
                int temp=min(min(kit[0][i][j],kit[1][i][j]),min(kit[2][i][j],kit[3][i][j]));
                if (temp>1)
                    ans+=temp-1;
            }
        printf("%d\n",ans);
    }
    return 0;
}
