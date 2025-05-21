#include <cstdio>

int Abs(int x){
return (x<0)?-x:x;
}
int main()
{
    char s[8];
    while (scanf("%s",s)==1){
        for (int i=0;i<6;i++)
            printf("%d",Abs(s[i+1]-s[i]));
        puts("");
    }
    return 0;
}
