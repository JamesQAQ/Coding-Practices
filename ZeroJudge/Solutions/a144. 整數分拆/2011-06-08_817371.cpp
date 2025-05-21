#include <cstdio>

int a[100],num;
char s[10000000];
void insert(int x){
    if (x>=10){
        s[num++]=x/10+48;
        s[num++]=x%10+48;
    }
    else
        s[num++]=x+48;
}
void dfs(int sum,int x,int d){
    if (sum==0){
        insert(a[0]);
        for (int i=1;i<x;i++){
            s[num++]=' ';
            insert(a[i]);
        }
        s[num++]='\n';
        return;
    }
    for (int i=d;i>=1;i--){
        a[x]=i;
        dfs(sum-i,x+1,(sum-i<i)?sum-i:i);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        num=0;
        dfs(n,0,n);
        s[num++]='\0';
        printf("%s",s);
    }
    return 0;
}
