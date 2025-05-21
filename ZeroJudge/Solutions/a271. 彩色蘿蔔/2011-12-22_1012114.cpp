#include <cstdio>

char s[10000];
int t,a[5],m,n;
void work(){
    int d=0;
    for (int i=0;s[i];i++)
        if (s[i]>='0'&&s[i]<='4'){
            m-=d;
            if (m<=0){
                puts("bye~Rabbit");
                return;
            }
            m+=a[s[i]-48];
            if (s[i]==52)
                d+=n;
            if (m<=0){
                puts("bye~Rabbit");
                return;
            }
        }
    printf("%dg\n",m);
}
int main()
{
    scanf("%d",&t);
    a[0]=0;
    while (t--){
        for (int i=1;i<=4;i++)
            scanf("%d",&a[i]);
        a[3]=-a[3],a[4]=-a[4];
        scanf("%d %d",&n,&m);
        gets(s);
        gets(s);
        work();
    }
}
