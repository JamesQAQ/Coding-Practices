#include <cstdio>

int main()
{
    int cases,n;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        int i=1,sum=0;
        while (n){
            n-=i,sum++;
            if (n&i)
                n-=i,sum++;
            i<<=1;
        }
        printf("%d\n",sum);
    }
}
