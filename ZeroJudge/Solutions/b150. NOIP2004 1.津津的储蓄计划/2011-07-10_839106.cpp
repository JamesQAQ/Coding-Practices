#include <cstdio>

int test(int a[]){
    int sum=0,save=0;
    for (int i=0;i<12;i++){
        sum+=300-a[i];
        if (sum<0)
            return -i-1;
        save+=(sum/100)*120;
        sum%=100;
    }
    return sum+save;
}
int main()
{
    int a[12];
    while (scanf("%d",&a[0])==1){
        for (int i=1;i<12;i++)
            scanf("%d",&a[i]);
        printf("%d\n",test(a));
    }
    return 0;
}
