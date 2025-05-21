#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)){
        if (n==-1)
            break;
        int ans=0,v=(n+1)*5;
        while (v){
            int tmp=(v-1)/5+1;
            v-=tmp;
            ans++;
        }
        printf("%d\n",ans);
    }
}
