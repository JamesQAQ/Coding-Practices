#include <cstdio>
#include <cstring>

char p[11],s[1000001];
int lenp,lens,f[11];
void get(char S[],int &len){
    gets(S);
    len=strlen(S);
    for (int i=0;i<len;i++)
        if (S[i]>='A'&&S[i]<='Z')
            S[i]=S[i]-'A'+'a';
}
void F_count(){
    int k=f[0]=-1;
    for (int i=1;i<lenp;i++){
        while (k>=0&&p[k+1]!=p[i])
            k=f[k];
        if (p[k+1]==p[i])
            k++;
        f[i]=k;
    }
}
bool ok(int x){
    if (x<0||x>=lens)
        return true;
    return s[x]==' ';
}
int main()
{
    get(p,lenp);get(s,lens);
    F_count();
    int cnt=0,at,k=-1;
    for (int i=0;i<lens;i++){
        while (k>=0&&p[k+1]!=s[i])
            k=f[k];
        if (p[k+1]==s[i])
            k++;
        if (k==lenp-1&&ok(i+1)&&ok(i-lenp)){
            cnt++;
            if (cnt==1)
                at=i-lenp+1;
            k=f[k];
        }
    }
    if (cnt)
        printf("%d %d\n",cnt,at);
    else
        puts("-1");
}
