#include <cstdio>
#include <string.h>

int main()
{
    char s[20000];
    int n;
    while (scanf("%s",s)!=EOF){
        scanf("%d",&n);
        int len=strlen(s),x=1;
        long long sum=0;
        for (int i=n-1;i>=0;i--){
            if (len-1-i>=0)
                sum=sum*10+s[len-1-i]-48;
            x<<=1;
        }
        (sum%x)?printf("可惡!!算了這麼久%s竟然無法被2的%d次整除\n",s,n):printf("YA!!終於算出%s可被2的%d次整除了!!\n",s,n);
    }
    return 0;
}
