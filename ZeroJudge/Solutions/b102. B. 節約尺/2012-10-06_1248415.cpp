#include <cstdio>

bool appear[401];
int n,a[20];
bool ok(int sum){
    bool mark=true;
    for (int i=0;i<n;i++)
        if (a[i]!=1)
            mark=false;
    if (mark)
        return false;
    for (int i=1;i<=sum;i++)
        if (!appear[i])
            return false;
    return true;
}
int main()
{
    while (scanf("%d",&n),n){
        int sum=0;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]),sum+=a[i];
        for (int i=1;i<=sum;i++)
            appear[i]=false;
        for (int i=0;i<n;i++){
            int tmp=0;
            for (int j=i;j<n;j++)
                tmp+=a[j],appear[tmp]=true;
        }
        puts((ok(sum))?"YES":"NO");
    }
}
