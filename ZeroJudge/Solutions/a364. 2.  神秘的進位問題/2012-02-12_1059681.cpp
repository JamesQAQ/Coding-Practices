#include <cstdio>

int c[3][100]={},num[3],pow__10[4],ans;
void C(){
    pow__10[0]=1;
    for (int i=1;i<=3;i++)
        pow__10[i]=pow__10[i-1]*10;
    for (int i=0;i<2;i++){
        int v=1,maxx=0;
        for (int j=3-i;v<=500;j++){
            maxx=j;
            c[i][j]=v;
            v*=(j+1);
            if (j-3+i>0)
                v/=(j-2+i);
        }
        num[i]=maxx;
        c[i][maxx+1]=v;
    }
}
int dis(int x){
    if (x<10)
        return 1;
    if (x<100)
        return 2;
    return 3;
}
int main()
{
    C();
    int m,n;
    scanf("%d",&m);
    while (m--){
        scanf("%d",&n);
        ans=0;
        for (int i=0;i<2;i++){
            int j;
            for (j=3-i-1;c[i][j]<=n;j++);
            j--;
            n-=c[i][j];
            ans=ans*pow__10[dis(j)]+j;
        }
        ans=ans*pow__10[dis(n)]+n;
        printf("%d\n",ans);
    }
}
