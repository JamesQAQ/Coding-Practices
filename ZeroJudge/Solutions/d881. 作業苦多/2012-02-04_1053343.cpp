#include <cstdio>

int main()
{
    int d;
    while (scanf("%d",&d)==1){
        int tmp=1,sum=1,allsum=0;
        for (int i=0;i<50;i++)
            allsum+=sum,sum+=tmp,tmp+=d;
        printf("%d\n",allsum);
    }
}
