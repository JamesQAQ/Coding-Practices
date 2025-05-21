#include <cstdio>

bool p[10001]={},pp[1001]={};
int prime[1228],pnum=0;
int main()
{
    for (int i=3;i<10000;i+=2)
        p[i]=true;
    for (int i=3;i<10000;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<10000;j+=2*i)
                p[j]=false;
        }
    int a,b;
    while (scanf("%d %d",&a,&b)==2){
        int ans=0;
        if (a<=2&&b>=2)
            ans++;
        if (a%2==0)
            a++;
        if (a==1)
            a=3;
        if (b%2==0)
            b--;
        for (int i=0;i<=b-a;i+=2)
            pp[i]=true;
        for (int i=0;i<pnum;i++){
            int x=prime[i];
            if (x>b)
                break;
            int start=(x-(a%x))%x;
            for (int j=(start+a==x)?start+x:start;j<=b-a;j+=x)
                pp[j]=false;
        }
        for (int i=0;i<=b-a;i+=2)
            if (pp[i])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
