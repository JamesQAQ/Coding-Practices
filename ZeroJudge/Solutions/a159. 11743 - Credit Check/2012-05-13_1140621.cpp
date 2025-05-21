#include <cstdio>

int value(int x){
    return (x>=10)?x/10+x%10:x;
}
int main()
{
    int cases;
    char s[5];
    scanf("%d",&cases);
    while (cases--){
        int sum=0;
        for (int i=0;i<4;i++){
            scanf("%s",s);
            for (int j=0;j<4;j++)
                sum+=((j&1)?value(s[j]-48):value(2*(s[j]-48)));
        }
        puts((sum%10==0)?"Valid":"Invalid");
    }
}
