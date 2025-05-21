#include <cstdio>

int a[2],num=0;
void get(char s[]){
    bool one=false;
    int x=0;
    for (int i=0;s[i];i++)
        if (s[i]<='9'&&s[i]>='0'){
            int x=0;
            while (s[i]&&s[i]<='9'&&s[i]>='0')
                x=x*10+s[i]-48,i++;
            a[num++]=x;
        }
}
int main()
{
    char s[10000];
    while (scanf("%s",s)==1){
        get(s);
        if (num==2)
            break;
    }
    printf("%d %d %lld\n",a[0],a[1],(long long)a[0]+a[1]);
}
