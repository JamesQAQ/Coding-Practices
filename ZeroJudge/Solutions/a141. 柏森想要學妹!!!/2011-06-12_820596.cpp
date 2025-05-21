#include <cstdio>

int path[1000][1000],tk[1000][1000];
void print_path(int l,int r){
    if (tk[l][r]){
        print_path(l,tk[l][r]);
        printf("%d->",tk[l][r]);
        print_path(tk[l][r],r);
    }
}
int main()
{
    int cases,n,m,a,b,w,t=0;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                path[i][j]=tk[i][j]=0;
        for (int i=0;i<m;i++)
            scanf("%d %d %d",&a,&b,&w),path[a][b]=path[b][a]=w;
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (path[i][k]*path[k][j]!=0)
                        if (path[i][j]==0||path[i][j]>path[i][k]+path[k][j])
                            path[i][j]=path[i][k]+path[k][j],tk[i][j]=k;
        for (int i=1;i<=n;i++)
            path[i][i]=tk[i][i]=0;
        scanf("%d",&m);
        for (int i=1;i<=m;i++){
            t++;
            scanf("%d %d",&a,&b);
            printf("Case#%d:\n%d->%d:%d\nPath:%d->",t,a,b,path[a][b],a);
            print_path(a,b);
            printf("%d\n",b);
        }
    }
    puts("GO!! MICHAEL!!Wish you can get your girlfriend!!!");
    return 0;
}
