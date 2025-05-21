#include <cstdio>

int main()
{
    int n,temp;
    while (scanf("%d",&n)==1){
        int cnt[3]={};
        for (int i=0;i<n;i++){
            scanf("%d",&temp);
            cnt[temp%3]++;
        }
        printf("%d %d %d\n",cnt[0],cnt[1],cnt[2]);
    }
    return 0;
}
