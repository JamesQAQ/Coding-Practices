#include <cstdio>
#include <cstring>
using namespace std;
struct Node {int mini,maxx;} dp[51][51];
int op[50],num;
char s[500];
bool v[51][51];
void update(int x,int y,int value){
    if (!v[x][y]){
        dp[x][y].mini=dp[x][y].maxx=value;
        v[x][y]=1;
    }
    else{
        dp[x][y].mini<?=value;
        dp[x][y].maxx>?=value;
    }
}
int count(int a,int b,int c){
    return (c=='+')?a+b:((c=='-')?a-b:a*b);
}
int main()
{
    while (scanf("%s",s)!=EOF){
    int len=strlen(s);
    s[len]='x';
    len++;
    int sum=0,at=0;
    num=0;
    while (at<len){
        if (s[at]<='9'&&s[at]>='0')
            sum=sum*10+s[at]-48;
        else{
            dp[num][num].mini=dp[num][num].maxx=sum;
            op[num++]=s[at];
            sum=0;
        }
        at++;
    }
    for (int i=0;i<=num;i++)
        for (int j=0;j<=num;j++)
         v[i][j]=0;
    for (int k=1;k<num;k++)
        for (int i=0;i+k<num;i++)
            for (int j=i;j<i+k;j++){
                update(i,i+k,count(dp[i][j].mini,dp[j+1][i+k].mini,op[j]));
                update(i,i+k,count(dp[i][j].mini,dp[j+1][i+k].maxx,op[j]));
                update(i,i+k,count(dp[i][j].maxx,dp[j+1][i+k].mini,op[j]));
                update(i,i+k,count(dp[i][j].maxx,dp[j+1][i+k].maxx,op[j]));
            }
    printf("%d\n",dp[0][num-1].maxx);
    }
    return 0;
}
