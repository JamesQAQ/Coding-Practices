#include <cstdio>

bool nochar(char c){
    return !((c<='z'&&c>='a')||(c<='Z'&&c>='A'));
}
int main()
{
    char s[10000];
    while (gets(s)!=NULL){
        bool big=true;
        for (int i=0;s[i];i++){
            if (big&&s[i]<='z'&&s[i]>='a')
                s[i]=s[i]-'a'+'A',big=false;
            if (s[i]=='.'||s[i]=='!'||s[i]=='?')
                big=true;
            if (s[i]=='i'&&(i==0||nochar(s[i-1])&&nochar(s[i+1])))
                s[i]='I';
        }
        puts(s);
    }
}
