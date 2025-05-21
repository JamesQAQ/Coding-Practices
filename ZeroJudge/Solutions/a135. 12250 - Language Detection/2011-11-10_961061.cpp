#include <cstdio>
#include <cstring>
char S[6][13]={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
char name[6][8]={"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
int Slen[6]={5,4,5,7,4,12};

int check(char s[],int len){
    for (int i=0;i<6;i++){
        if (len!=Slen[i])
            continue;
        int j=0;
        for (;j<len;j++)
            if (s[j]!=S[i][j])
                break;
        if (j==len)
            return i;
    }
    return -1;
}
int main()
{
    int t=0;
    char s[15];
    while (scanf("%s",s)){
        int len=strlen(s);
        if (len==1&&s[0]=='#')
            break;
        int p=p=check(s,len);
        printf("Case %d: ",++t);
        (p==-1)?puts("UNKNOWN"):printf("%s\n",name[p]);
    }
    return 0;
}
