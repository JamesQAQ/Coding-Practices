#include <cstdio>

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int num,n,cnt;
    while (n=input()){
        num=0;
        while (n>0){
            if (n&1) num++,n>>=1;
            else     break;
        }
        printf("%d\n",num);
    }
}
