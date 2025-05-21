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
    int n,k,m,car[2001],w[2001],tmp;
    n=input(),k=input(),m=input();
    car[0]=0,w[0]=0;
    for (int i=1;i<=n;i++){
        car[i]=2001;
        tmp=input();
        if (tmp>m)
            continue;
        for (int j=i;j>=1;j--){
            int tmpcar=car[j-1],tmpw=w[j-1];
            if (tmpw+tmp>m) tmpcar++,tmpw=tmp;
            else tmpw+=tmp;
            if (tmpcar<car[j]||(tmpcar==car[j]&&tmpw<w[j]))
                car[j]=tmpcar,w[j]=tmpw;
        }
    }
    for (int i=n;i>=0;i--)
        if (car[i]<k){
            printf("%d\n",i);
            break;
        }
}
