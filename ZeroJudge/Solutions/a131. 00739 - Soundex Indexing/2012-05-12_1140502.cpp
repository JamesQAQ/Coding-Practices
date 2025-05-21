#include <cstdio>
#include <cstring>

int main()
{
    puts("NAME                     SOUNDEX CODE");
    char s[30],S[6][10]={"BPFV","CSKGJQXZ","DT","L","MN","R"};
    int v[256]={};
    for (int i=0;i<6;i++)
        for (int j=0;S[i][j];j++)
            v[S[i][j]]=i+1;
    while (scanf("%s",s)!=EOF){
        printf("         %s",s);
        int len=strlen(s);
        for (int i=0;i<25-len;i++)
            putchar(' ');
        putchar(s[0]);
        int b[3]={},cnt=0;
        for (int i=0;s[i];i++){
            if (v[s[i]]&&i&&v[s[i]]!=v[s[i-1]])
                b[cnt++]=v[s[i]];
            if (cnt==3)
                break;
        }
        for (int i=0;i<3;i++)
            printf("%d",b[i]);
        puts("");
    }
    puts("                   END OF OUTPUT");
}
