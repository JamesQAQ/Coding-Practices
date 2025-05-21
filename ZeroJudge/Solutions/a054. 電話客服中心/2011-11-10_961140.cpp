#include <cstdio>

int main()
{
    int cnt[26]={1,0,9,8,7,6,5,4,9,3,2,2,1,0,8,9,8,7,6,5,4,3,1,3,2,0};
    char s[10];
    while (scanf("%s",s)==1){
        int sum=0;
        for (int i=0;i<8;i++)
            sum+=(s[i]-48)*(8-i);
        sum%=10;
        for (int i=0;i<26;i++)
            if ((10-((sum+cnt[i])%10))%10==s[8]-48)
                printf("%c",i+'A');
        puts("");
    }
    return 0;
}
