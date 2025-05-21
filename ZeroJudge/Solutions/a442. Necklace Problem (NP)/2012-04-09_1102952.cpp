#include <cstdio>
#include <cstring>

char s[20010],p[10010];
int len,f[10010];
void count_f(){
    int k=f[0]=-1;
    for (int i=1;i<len;i++){
        while (k!=-1&&p[k+1]!=p[i])
            k=f[k];
        if (p[k+1]==p[i])
            k++;
        f[i]=k;
    }
}
bool ok(){
    for (int i=0;i<len;i++)
        s[i+len]=s[i];
    count_f();
    int k=-1;
    for (int i=0;i<2*len;i++){
        while (k!=-1&&p[k+1]!=s[i])
            k=f[k];
        if (p[k+1]==s[i])
            k++;
        if (k==len-1)
            return true;
    }
    k=-1;
    for (int i=2*len-1;i>=0;i--){
        while (k!=-1&&p[k+1]!=s[i])
            k=f[k];
        if (p[k+1]==s[i])
            k++;
        if (k==len-1)
            return true;
    }
    return false;
}
int main()
{
    int n;
    while (scanf("%s %s",s,p)==2){
        len=strlen(s);
        puts((ok())?"same":"difference");
    }
}
