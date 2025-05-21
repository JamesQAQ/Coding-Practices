#include <cstdio>

int main()
{
    int cases,n,a,b,sum,mini;
    scanf("%d",&cases);
    for (int i=1;i<=cases;i++){
        scanf("%d",&n);
        sum=0;
        mini=2147483647;
        for (int j=0;j<n;j++){
            scanf("%d %d",&a,&b);
            a=a*60+b;
            if (a<mini)
                mini=a;
            sum+=a;
        }
        sum/=n;
        printf("Track %d:\n",i);
        printf("Best Lap: %d minute(s) %d second(s).\n",mini/60,mini%60);
        printf("Average: %d minute(s) %d second(s).\n\n",sum/60,sum%60);
    }
}
