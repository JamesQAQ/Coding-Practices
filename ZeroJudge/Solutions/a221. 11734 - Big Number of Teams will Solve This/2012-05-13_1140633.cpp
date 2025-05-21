#include <cstdio>
#include <cstring>

bool PE(char a[],char b[]){
    char c[101],d[101];
    int lenc=0,lend=0;
    for (int i=0;a[i];i++)
        if (a[i]!=' ')
            c[lenc++]=a[i];
    c[lenc]=0;
    for (int i=0;b[i];i++)
        if (b[i]!=' ')
            d[lend++]=b[i];
    d[lend]=0;
    return strcmp(c,d)==0;
}
int main()
{
    int cases;
    char a[101],b[101];
    scanf("%d",&cases);
    gets(a);
    for (int t=1;t<=cases;t++){
        gets(a),gets(b);
        printf("Case %d: ",t);
        if (strcmp(a,b)==0)
            puts("Yes");
        else if (PE(a,b))
            puts("Output Format Error");
        else
            puts("Wrong Answer");
    }
}
