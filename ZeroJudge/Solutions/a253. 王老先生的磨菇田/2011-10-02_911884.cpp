#include <cstdio>

int main()
{
    int sum[101]={};
    int n,s;
    while (scanf("%d",&n)==1){
        if (n==-1)
            continue;
        scanf("%d",&s);
        sum[n]+=s;
    }
    for (int i=0;i<101;i++)
        if (sum[i])
            printf("%d %d\n",i,sum[i]);
    return 0;
}
