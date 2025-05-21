#include <cstdio>
#include <algorithm>

long long extended_gcd(long long a,long long b,long long &i,long long &j){
    if (b==0){
        i=1,j=0;
        return a;
    }
    long long g=extended_gcd(b,a%b,j,i);
    j=j-(a/b)*i;
    return g;
}
long long abs(long long x){
    return (x<0)?-x:x;
}
long long ans[100000];
int num;
int main()
{
    int m;
    scanf("%d",&m);
    num=0;
    for (long long i=1;i*i<=m;i++)
        if (m%i==0){
            long long a=i,b=m/i,I,J;
            long long g=extended_gcd(a,b,I,J);
            if (g>2)
                continue;
            if (g==1)
                I*=2,J*=2;
            long long da=b/g,db=a/g;
            long long ti=I,tj=J;
            while ((abs(ti)*a+abs(tj)*b)/2<=m){
                ans[num++]=(abs(ti)*a+abs(tj)*b)/2;
                ti+=da,tj-=db;
            }
            ti=I,tj=J;
            while ((abs(ti)*a+abs(tj)*b)/2<=m){
                ans[num++]=(abs(ti)*a+abs(tj)*b)/2;
                ti-=da,tj+=db;
            }
        }
    std::stable_sort(ans,ans+num);
    long long f=-1;
    int cnt=0;
    for (int i=0;i<num;i++)
        if (f!=ans[i]){
            cnt++;
            f=ans[i];
        }
    printf("%d\n",cnt);
    f=-1;
    for (int i=0;i<num;i++)
        if (f!=ans[i]){
            f=ans[i];
            printf("%lld\n",f);
        }
    //scanf(" ");
}
