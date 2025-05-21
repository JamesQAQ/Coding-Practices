#include <cstdio>

void print(int x){
    int a[13]={},num=0;
    while (x){
        a[num++]=x&1;
        x>>=1;
    }
    for (int i=12;i>=0;i--)
        printf("%d",a[i]);
}
int main()
{
    int cases,a,b;
    char c;
    scanf("%d",&cases);
    while (cases--){
        scanf("%X %c %X",&a,&c,&b);
        print(a),printf(" %c ",c),print(b);
        printf(" = %d\n",(c=='+')?a+b:a-b);
    }
}
