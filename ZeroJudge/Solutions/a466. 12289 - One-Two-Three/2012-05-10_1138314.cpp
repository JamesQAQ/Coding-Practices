#include <cstdio>
#include <cstring>

int cnt(char a[],char b[]){
    int sum=0;
    for (int i=0;a[i]&&b[i];i++)
        if (a[i]!=b[i])
            sum++;
    return sum;
}

int main()
{
    char s[3][6]={"one","two","three"},S[6];
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%s",S);
        int len=strlen(S);
        if (len==5)
            puts("3");
        else{
            if (cnt(S,s[0])<=1)
                puts("1");
            else
                puts("2");
        }
    }
}
