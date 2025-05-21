#include <cstdio>

unsigned int get(char s[]){
    unsigned x=0;
    for (int i=0;s[i];i++){
        //printf("%d %c\n",i,s[i]);
        x=x*2+(s[i]=='1');
        //printf("x %u\n",x);
    }
    //printf("return %u\n",x);
    return x;
}
void print(unsigned int x){
    //printf("%u\n",x);
    unsigned int i=(unsigned int)1<<31;
    while (i>0)
        putchar((x&i)?'1':'0'),i>>=1;
    puts("");
}
int main()
{
    unsigned int a,b;
    char s[100];
    while (scanf("%s",s)==1){
        puts(s);
        a=get(s);
        scanf("%s",s);
        b=get(s);
        puts(s);
        puts("---------------------------------");
        print(a+b);
        puts("****End of Data******************");
    }
}
