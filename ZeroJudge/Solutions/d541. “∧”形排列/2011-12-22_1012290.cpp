#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1){
        int ans=1;
        n--;
        if (n<0){
            puts("0");
            continue;
        }
        for (int i=30,j=1<<30;i>=0;i--,j>>=1){
            ans=((long long)ans*ans)%1234567;
            if (j&n){
                ans+=ans;
                if (ans>=1234567)
                    ans-=1234567;
            }
        }
        printf("%d\n",ans);
    }
}
