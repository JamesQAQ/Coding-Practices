#include <cstdio>

int main()
{
    char s[10001],a[3];
    int cases;
    scanf("%d",&cases);
    getchar();
    while (cases--){
        gets(s);
        gets(a);
        int l,r;
        bool p=true;
        for (int i=0;s[i];i++){
            if (s[i]==a[0])
                l=i;
            if (s[i]==a[1])
                r=i;
        }
        if (l>r)
            l^=r^=l^=r;
        for (int i=0;s[i];i++)
            if (i<=l||i>=r)
                putchar(s[i]);
        puts("");
        for (int i=l+1;i<=r-1;i++)
            putchar(s[i]);
        puts("");
    }
}
