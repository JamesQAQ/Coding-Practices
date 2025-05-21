#include <cstdio>

int get(char s[]){
    int x=0;
    for (int i=0;s[i];i++)
        x=(x<<3)+s[i]-48;
    return x;
}
int main()
{
    int cases;
    char sa[100],sb[100];
    scanf("%d",&cases);
    while (cases--){
        scanf("%s %s",sa,sb);
        printf("%X\n",get(sa)+get(sb));
    }
}
