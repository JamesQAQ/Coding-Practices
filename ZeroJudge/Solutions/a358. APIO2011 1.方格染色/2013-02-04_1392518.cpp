#include <cstdio>

int boss[400001];
bool appear[400001];
long long mod=1000000000;
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int find(int x){
    return (boss[x]==x)?x:boss[x]=find(boss[x]);
}
void combin(int a,int b){
    int bossa=find(a),bossb=find(b);
    if (bossa!=bossb)
        boss[bossb]=bossa;
}
long long pow2(int x){
    long long ans=1;
    for (int i=1<<20;i>0;i>>=1){
        ans=(ans*ans)%mod;
        if (i&x){
            ans=ans*2;
            if (ans>=mod)
                ans-=mod;
        }
    }
    return ans;
}
int main()
{
    int n,m,k,a,b,c;
    n=input(),m=input(),k=input();
    for (int i=1;i<=2*(n+m);i++)
        boss[i]=i;
    for (int i=0;i<k;i++){
        a=input(),b=input(),c=input();
        if ((a&1)&&(b&1)){
            if (c){
                combin(a,b+n);
                combin(a+n+m,b+n+n+m);
            }
            else{
                combin(a,b+n+n+m);
                combin(b+n,a+n+m);
            }
        }
        else{
            if (c){
                combin(a,b+n+n+m);
                combin(b+n,a+n+m);
            }
            else{
                combin(a,b+n);
                combin(a+n+m,b+n+n+m);
            }
        }
    }
    bool fail=false;
    for (int i=1;i<=n;i++)
        if (find(i)==find(i+n+m)){
            fail=true;
            break;
        }
    if (fail){
        puts("0");
        return 0;
    }
    for (int i=n+1;i<=n+m;i++)
        if (find(i)==find(i+n+m)){
            fail=true;
            break;
        }
    if (fail){
        puts("0");
        return 0;
    }
    int cnt=0;
    for (int i=1;i<=2*(n+m);i++){
        int bossi=find(i);
        if (!appear[bossi]){
            appear[bossi]=true;
            cnt++;
        }
    }
    cnt=cnt/2-1;
    printf("%lld\n",pow2(cnt));
}
