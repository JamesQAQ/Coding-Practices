#include <cstdio>

int main()
{
    int m[8],r[4];
    for (int i=0;i<8;i++)
        scanf("%d",&m[i]);
    int n,a,b,c;
    scanf("%d",&n);
    char s[10];
    for (int i=0;i<n;i++){
        scanf("%s",s);
        if (s[0]=='L'){
            scanf("%d %d",&a,&b);
            r[a]=m[b];
        }
        else if (s[0]=='S'){
            scanf("%d %d",&a,&b);
            m[a]=r[b];
        }
        else if (s[0]=='A'){
            scanf("%d %d %d",&a,&b,&c);
            r[a]=r[b]+r[c];
        }
        else{
            scanf("%d %d",&a,&b);
            r[a]=r[b];
        }
    }
    printf("%d\n%d\n",r[0],m[0]);
}
