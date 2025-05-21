#include <cstdio>

bool first[100],one;
int st[100],cnt[100],len;
char now[100];
void dfs(int x){
    if (x==len){
        one=true;
        puts(now);
        return;
    }
    int d=0;
    if (first[x])
        d=st[x],first[x]=false;
    for (;d<26;d++)
        if (cnt[d]){
            cnt[d]--;
            now[x]=d+'a';
            dfs(x+1);
            if (one)
                return;
            cnt[d]++;
        }
}
int main()
{
    char s[100];
    while (scanf("%s",s),s[0]!='#'){
        int i;
        for (i=0;i<26;i++)
            cnt[i]=0;
        for (i=0;s[i];i++){
            int v=s[i]-'a';
            cnt[v]++,st[i]=v,first[i]=true;
        }
        st[i-1]++;
        now[i]=0;
        one=false;
        len=i;
        dfs(0);
        if (!one)
            puts("No Successor");
    }
}
