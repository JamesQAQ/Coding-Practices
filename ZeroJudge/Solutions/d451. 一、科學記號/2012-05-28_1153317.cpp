#include <cstdio>

void build(char S[],char s[]){
    int cnt=0;
    for (int i=0;S[i];i++)
        if (S[i]!=',')
            s[cnt++]=S[i];
    s[cnt]=0;
}
int getnode(char s[]){
    int i;
    for (i=0;s[i];i++)
        if (s[i]=='.')
            return i;
    return i;
}
int getst(char s[]){
    for (int i=0;s[i];i++)
        if (s[i]!='.'&&s[i]!='0')
            return i;
}
int ans[10001],tag;
void getans(char s[],int st,int n){
    int cnt=0,i;
    for (i=st;s[i]&&cnt<=n;i++)
        if (s[i]!='.')
            ans[cnt++]=s[i]-48;
    for (;cnt<=n;cnt++)
        ans[cnt++]=0;
    if (ans[n]>=5)
        ans[n-1]++;
    for (int i=n-1;i>0;i--)
        if (ans[i]>=10){
            ans[i]-=10;
            ans[i-1]++;
        }
    if (ans[0]>=10){
        tag++;
        ans[0]-=10;
        putchar('1');
        if (n>2)
            putchar('.');
        for (int i=0;i<n-1;i++)
            printf("%d",ans[i]);
    }
    else{
        printf("%d",ans[0]);
        if (n>1)
            putchar('.');
        for (int i=1;i<n;i++)
            printf("%d",ans[i]);
    }
}
int main()
{
    char S[10001],s[10001];
    int cases,n;
    scanf("%d",&cases);
    while (cases--){
        scanf("%s %d",S,&n);
        build(S,s);
        int node=getnode(s),st=getst(s);
        tag=0;
        getans(s,st,n);
        printf("x10(%d)\n",(node-st>0)?node-st-1+tag:node-st+tag);
    }
}
