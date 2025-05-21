#include <cstdio>
#include <cstring>

char s[1000001];
int len;
bool ok(int x){
    for (int i=0;i<x;i++){
        char c=s[i];
        for (int j=x+i;j<len;j+=x)
            if (s[j]!=c)
                return false;
    }
    return true;
}
int main()
{
    while (scanf("%s",s)){
        len=strlen(s);
        if (s[0]=='.'&&len==1)
            break;
        for (int i=1;i<=len;i++)
            if (len%i==0&&ok(i)){
                printf("%d\n",len/i);
                break;
            }
    }
}
