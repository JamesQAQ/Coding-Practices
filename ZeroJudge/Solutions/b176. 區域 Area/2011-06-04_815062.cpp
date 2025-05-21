#include <cstdio>
using namespace std;

int main()
{
    int n,m,a[100][100];
    while (scanf("%d %d",&n,&m)==2){
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        int ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                int limit=m;
                for (int k=i;k<n;k++)
                    for (int l=j;l<limit;l++){
                        if ((k-i>0&&a[k][l]<=a[k-1][l])||(l-j>0&&a[k][l]<=a[k][l-1])){
                            limit=l;
                            break;
                        }
                        int p=(k-i+1)*(l-j+1);
                        if (p>ans)
                            ans=p;
                     }
            }
        printf("%d\n",ans);
    }
    return 0;
}
