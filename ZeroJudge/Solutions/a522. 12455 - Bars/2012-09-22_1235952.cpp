#include <cstdio>

int main()
{
    int cases,n,num,tmp;
    scanf("%d",&cases);
    bool ok[1001];
    while (cases--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            ok[i]=false;
        ok[0]=true;
        scanf("%d",&num);
        for (int i=0;i<num;i++){
            scanf("%d",&tmp);
            for (int j=n;j>=tmp;j--)
                ok[j]|=ok[j-tmp];
        }
        puts((ok[n])?"YES":"NO");
    }
}
