#include <cstdio>
#include <cstring>

char s[20];
int n,L[12],R[12];
void del(int x){
    R[L[x]]=R[x];
    L[R[x]]=L[x];
}
void insert(int a,int x){
    L[x]=a,R[x]=R[a];
    L[R[a]]=x,R[a]=x;
}
void print(){
    int at=R[0];
    while (at!=n+1)
        putchar(s[at-1]),at=R[at];
    puts("");
}
void dfs(int x){
    //printf("dfs %d\n",x);
    if (x==n+1){
        print();
        return;
    }
    int at=0;
    while (at!=n+1){
        insert(at,x);
        dfs(x+1);
        del(x);
        at=R[at];
    }
}
int main()
{
    while (scanf("%s",s)==1){
        n=strlen(s);
        R[0]=n+1;
        L[n+1]=0;
        dfs(1);
    }
}
