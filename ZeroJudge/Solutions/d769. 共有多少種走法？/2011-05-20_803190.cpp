#include <cstdio>

int n,path[50][50];
void same(int a[50][50],int b[50][50]){
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            a[i][j]=b[i][j];
}
void count(int k,int a[50][50]){
    int at=1<<24;
    while (at>0){
        if (at&k)
            break;
        at>>=1;
    }
    same(a,path);
    at>>=1;
    while (at>0){
        int t[50][50];
        same(t,a);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                int temp=0;
                for (int k=0;k<n;k++)
                    temp+=t[i][k]*t[k][j];
                a[i][j]=temp%5281;
            }
        if (at&k){
            same(t,a);
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++){
                    int temp=0;
                    for (int k=0;k<n;k++)
                        temp+=t[i][k]*path[k][j];
                    a[i][j]=temp%5281;
                }
        }
        at>>=1;
    }
}
int main()
{
    int k,q,a,b,s;
    while (scanf("%d %d",&n,&k)==2){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                path[i][j]=0;
        while (scanf("%d %d %d",&a,&b,&s)){
            if (a==0)
                break;
            path[a-1][b-1]+=s%5281;
        }
        int ans[50][50];
        count(k,ans);
        scanf("%d",&q);
        for (int i=0;i<q;i++){
            scanf("%d %d",&a,&b),a--,b--;
            printf("%d\n",ans[a][b]);
        }
    }
    return 0;
}
