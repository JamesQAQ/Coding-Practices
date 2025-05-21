#include <cstdio>

int cnt[1001][256],m;
int get(int x){
    int sum=0;
    for (int i=32;i<128;i++)
        if (cnt[x][i]%m)
            return i;
    return 0;
}
int main()
{
    int n;
    char s[1001];
    while (scanf("%d %d",&n,&m),n+m){
        int all=(n*m)-1;
        getchar();
        for (int i=0;i<1000;i++)
            for (int j=32;j<128;j++)
                cnt[i][j]=0;
        while (all--){
            gets(s);
            for (int i=0;s[i];i++)
                cnt[i][s[i]]++;
        }
        for (int i=0;i<1000;i++){
            int v=get(i);
            if (v==0)
                break;
            putchar(v);
        }            
        puts("");
    }
}
