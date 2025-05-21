#include <cstdio>

struct Node {int l,r;} check[200000];
long long sumv[200001];
int sumn[200001],n,m;
int w[200001],v[200001];

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
long long judge(int W){
    long long sum=0;
    sumv[0]=0,sumn[0]=0;
    for (int i=1;i<=n;i++)
        sumn[i]=sumn[i-1]+(w[i]>=W),sumv[i]=sumv[i-1]+((w[i]>=W)?v[i]:0);
    for (int i=0;i<m;i++){
        int l=check[i].l,r=check[i].r;
        sum+=(sumv[r]-sumv[l-1])*(sumn[r]-sumn[l-1]);
    }
    return sum;
}
int main()
{
    int l=2147483647,r=0;
    long long s;
    scanf("%d %d %lld",&n,&m,&s);
    for (int i=1;i<=n;i++){
        w[i]=input(),v[i]=input();
        if (w[i]<l) l=w[i];
        if (w[i]>r) r=w[i];
    }
    for (int i=0;i<m;i++)
        check[i].l=input(),check[i].r=input();
    while (l<=r){
        int mid=(l+r)/2;
        long long J=judge(mid);
        if (J>s)
            l=mid+1;
        else if (J<s)
            r=mid-1;
        else{
            l=mid;
            break;
        }
    }
    long long v1=s-judge(l),v2=judge(l-1)-s;
    printf("%lld\n",(v1<v2)?v1:v2);
}
