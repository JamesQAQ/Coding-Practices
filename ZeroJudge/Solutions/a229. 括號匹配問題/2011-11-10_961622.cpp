#include <cstdio>

char s[27];
int n;
void dfs(int x,int l,int r){
    if (r>l||l>n)
        return;
    if (x==2*n){
        printf("%s\n",s);
        return;
    }
    s[x]='(';
    dfs(x+1,l+1,r);
    s[x]=')';
    dfs(x+1,l,r+1);
}
int main()
{
    while (scanf("%d",&n)==1){
        s[2*n]='\0';
        dfs(0,0,0);
    }
    return 0;
}
