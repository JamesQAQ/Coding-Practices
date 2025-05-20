#include <iostream>
using namespace std;

int a[100][100],n,m;
bool found,use[101];
bool ok(int x,int y,int p)
{
    for (int i=0;i<p;i++)
    {
        for (int j=1;j<=p;j++)
            use[j]=0;
        for (int j=0;j<p;j++)
        {
            int num=a[x+i][y+j];
            if (!use[num])
                use[num]=1;
            else
                return 0;
        }
    }
    for (int i=0;i<p;i++)
    {
        for (int j=1;j<=p;j++)
            use[j]=0;
        for (int j=0;j<p;j++)
        {
            int num=a[x+j][y+i];
            if (!use[num])
                use[num]=1;
            else
                return 0;
        }
    }
    return 1;
}
void check()
{
    int p=min(n,m);
    for (int i=2;i<=p;i++)
    {
        int sum=0;
        for (int j=0;j<=n-i;j++)
            for (int k=0;k<=m-i;k++)
                if (ok(j,k,i))
                    sum++;
        if (sum>0)
        {
            printf("%dx%d P-square: appear %d time(s).\n",i,i,sum);
            found=1;
        }
    }
}
int main()
{
    int cases;
    while (scanf("%d",&cases)!=EOF)
        for (int t=0;t<cases;t++)
        {
            printf("Page #%d:\n",t+1);
            scanf("%d",&n);
            scanf("%d",&m);
            for (int i=0;i<n;i++)
                for (int j=0;j<m;j++)
                    scanf("%d",&a[i][j]);
            found=0;
            check();
            if (!found)
                puts("No P-square exists.");
        }        
    return 0;
}
