#include <cstdio>
#include <iostream>

struct Node {int a[12][12][12];} dp[2],*pre,*now;
char map[12][51];
int r,c,t,s[3],num;

int abs(int x){
    return (x<0)?-x:x;
}
void empty(Node &x){
    for (int i=1;i<=r-2;i++)
        for (int j=i+1;j<=r-1;j++)
            for (int k=j+1;k<=r;k++)
                x.a[i][j][k]=-1;
}
int main()
{
    pre=&dp[0],now=&dp[1];
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&r,&c);
        for (int i=0;i<c;i++)
            map[0][i]=map[r+1][i]='#';
        for (int i=1;i<=r;i++)
            scanf("%s",map[i]);
        num=0;
        for (int i=1;i<=r;i++)
            if (map[i][c-1]=='C')
                s[num++]=i;
        empty(*pre);
        pre->a[s[0]][s[1]][s[2]]=0;
        for (int l=c-1;l>0;l--){
            bool found=false;
            empty(*now);
            for (int i=1;i<=r-2;i++)
                for (int j=i+1;j<=r-1;j++)
                    for (int k=j+1;k<=r;k++)
                        if (pre->a[i][j][k]!=-1){
                            found=true;
                            int v=pre->a[i][j][k];
                            for (int ii=-1;ii<=1;ii++)
                                if (map[i+ii][l-1]!='#')
                                    for (int jj=-1;jj<=1;jj++)
                                        if (map[j+jj][l-1]!='#')
                                            for (int kk=-1;kk<=1;kk++)
                                                if (map[k+kk][l-1]!='#'){
                                                    int p=v+abs(ii)+abs(jj)+abs(kk),*d=&now->a[i+ii][j+jj][k+kk];
                                                    if (*d==-1||*d>p)
                                                        *d=p;
                                                }
                        }
            std::swap(pre,now);
            if (!found)
                break;
        }
        int ans=-1;
        for (int i=1;i<=r-2;i++)
            for (int j=i+1;j<=r-1;j++)
                for (int k=j+1;k<=r;k++)
                    if (pre->a[i][j][k]!=-1&&(ans==-1||ans>pre->a[i][j][k]))
                        ans=pre->a[i][j][k];
        if (ans==-1)
            puts("Impossible");
        else
            printf("%d\n",ans+3*c);
    }
    return 0;
}
