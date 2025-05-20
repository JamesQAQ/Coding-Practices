#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    bool prime[1001]={};
    prime[1]=1;
    prime[2]=1;
    for (int i=3;i<1001;i+=2)
        prime[i]=1;
    for (int i=3;i*i<1001;i+=2)
        if (prime[i])
            for (int j=3*i;j<1001;j+=2*i)
                prime[j]=0;
    int n,c;
    while (scanf("%d %d",&n,&c)!=EOF)
    {
        printf("%d %d: ",n,c);
        int num=0,ans[200];
        for (int i=1;i<=n;i++)
            if (prime[i])
            {
                ans[num]=i;
                num++;
            }
        int d=(num%2==1)?(num-c*2+1)/2:(num-c*2)/2;
        if (d<0)
            for (int i=0;i<num;i++)
                printf("%d ",ans[i]);
        else
            for (int i=d;i<num-d;i++)
                printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
