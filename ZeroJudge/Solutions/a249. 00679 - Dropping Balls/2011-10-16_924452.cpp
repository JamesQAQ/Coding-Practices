#include <cstdio>

int main()
{
    int pow2[21],d,num,cases,ans;
    pow2[0]=1;
    for (int i=1;i<=20;i++)
        pow2[i]=pow2[i-1]*2;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&d,&num);
        num--;
        num%=pow2[d-1];
        ans=pow2[d-1];
        for (int i=0,j=1;j<=num;i++,j<<=1)
            if (j&num)
                ans+=pow2[d-2-i];
        printf("%d\n",ans);
    }
    return 0;
}
