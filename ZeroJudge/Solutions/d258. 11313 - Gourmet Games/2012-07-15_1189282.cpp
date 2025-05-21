#include <cstdio>

void work(int n,int m){
    int now=n,cnt=0;
    while (1){
        cnt+=now/m;
        now=now/m+now%m;
        if (now==1){
            printf("%d\n",cnt);
            return;
        }
        if (now<m){
            puts("cannot do this");
            return;
        }
    }
}
int main()
{
    int cases,n,m;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        work(n,m);
    }
}
