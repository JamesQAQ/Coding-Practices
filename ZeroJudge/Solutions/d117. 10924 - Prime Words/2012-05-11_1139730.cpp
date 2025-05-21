#include <cstdio>

bool p[2001]={};
void sieve(){
    p[1]=p[2]=true;
    for (int i=3;i<2000;i+=2)
        p[i]=true;
    for (int i=3;i<50;i+=2)
        if (p[i])
            for (int j=i*i;j<2000;j+=2*i)
                p[j]=false;
}
int cnt(char s[]){
    int sum=0;
    for (int i=0;s[i];i++){
        if (s[i]<='z'&&s[i]>='a')
            sum+=s[i]-'a'+1;
        else
            sum+=s[i]-'A'+27;
    }
    return sum;
}
int main()
{
    sieve();
    char s[30];
    while (scanf("%s",s)==1)
        puts(p[cnt(s)]?"It is a prime word.":"It is not a prime word.");
}
