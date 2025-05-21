#include <cstdio>
#include <cstring>

int main()
{
    char s[20];
    scanf("%s",s);
    if (s[0]=='-')
        putchar('-');
    int len=strlen(s),i=len-1;
    bool zero=true;
    while (s[i]=='0'&&i>=0)
        i--;
    while (i>=0){
        if (s[i]!='-'){
            zero=false;
            putchar(s[i]);
        }
        i--;
    }
    if (zero)
        putchar('0');
    puts("");
}
