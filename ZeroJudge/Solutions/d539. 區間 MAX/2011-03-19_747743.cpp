#include <iostream>
#include <cmath>
using namespace std;

int pow2[19]={1},dp[500000][19];
int search(int n)
{
    return (int)(log((double)n)/log(2.0));
}
int input(){
     char a;
     int x;
     while(a=getchar())
             if(a!=' '&&a!='\n')break;
        x=a-'0';
        while(a=getchar()){
             if(a==' '||a=='\n')return x;
             x=x*10+a-'0';
        }
}  
int main()
{
    for (int i=1;i<=18;i++)
        pow2[i]=pow2[i-1]*2;
    int n,m,a,b,e;
    n=input();
    for (int i=0;i<n;i++)
        dp[i][0]=input();
    e=search(n);
    for (int j=1;j<=e;j++)
        for (int i=0;i+pow2[j]-1<n;i++)
            dp[i][j]=max(dp[i][j-1],dp[i+pow2[j-1]][j-1]);
    m=input();
    for (int i=0;i<m;i++)
    {
        a=input();
        b=input();
        if (a>b)
            swap(a,b);
        a--;
        b--;
        e=search(b-a+1);
        printf("%d\n",max(dp[a][e],dp[b-pow2[e]+1][e]));
    }
    return 0;
}
