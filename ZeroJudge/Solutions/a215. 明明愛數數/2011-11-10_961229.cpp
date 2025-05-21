#include <cstdio>

int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)==2){
        int sum=n,i;
        for (i=1;sum<=m;i++)
            sum+=n+i;
        printf("%d\n",i);
    }
    return 0;
}
