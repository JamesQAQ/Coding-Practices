#include <cstdio>

void dfs(int x){
    if (x==0)
        putchar('0');
    else if (x==2)
        putchar('2');
    else{
        bool first=true;
        for (int i=30,j=1<<30;i>=0;i--,j>>=1)
            if (j&x){
                if (first) first=false;
                else putchar('+');
                putchar('2');
                if (i!=1){
                    putchar('(');
                    dfs(i);
                    putchar(')');
                }
            }
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
        dfs(n),puts("");
}
