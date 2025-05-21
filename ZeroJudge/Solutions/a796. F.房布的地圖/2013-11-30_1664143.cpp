#include <stdio.h>
#define MAX 101

bool path[MAX][MAX]={};
int sum[MAX]={};

int main()
{
    int n,m,r;
    scanf("%d %d",&n,&m);
    if (m>((n*(n-1))/2))
        printf("%d\n",1/0);
    for (int i=1;i<=n;i++)
        sum[i]=0;
    int k,a,b;
    for (int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        path[a][b]=path[b][a]=true;
        sum[a]++,sum[b]++;
    }
    scanf("%d",&r);
    for (int i=0;i<r;i++){
        scanf("%d",&k);
        if (k==1){
            scanf("%d",&a);
            printf("%d\n",sum[a]);
        }
        else{
            scanf("%d %d",&a,&b);
            puts((path[a][b])?"Yes":"No");
        }
    }
}
