#include <cstdio>

int main()
{
    int cases,n;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++){
        scanf("%d",&n);
        int up=0,low=0,f,tmp;
        scanf("%d",&f);
        for (int i=1;i<n;i++){
            scanf("%d",&tmp);
            if (tmp>f) up++;
            if (tmp<f) low++;
            f=tmp;
        }
        printf("Case %d: %d %d\n",t,up,low);
    }
}
