#include <cstdio>
#include <algorithm>

int n,k,a[10000],b[10000],c[10000];
long long d[10000];
bool ok(long long m){
    int i;
    for (i=0;i<n;i++)
        d[i]=(long long)a[i]+(long long)m*b[i];
    std::stable_sort(d,d+n);
    int at=0;
    for (i=0;i<k;i++){
        long long v=c[i];
        while (at<n&&d[at]<=v)
            at++;
        if (at==n)
            return false;
        at++;
    }
    return true;
}
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int cases,maxx=150000000;
    cases=input();
    while (cases--){
        n=input(),k=input();
        for (int i=0;i<n;i++)
            a[i]=input(),b[i]=input();
        for (int i=0;i<n;i++)
            c[i]=input();
        std::stable_sort(c,c+n);
        int l=0,r=maxx,mid;
        while (l<=r){
            mid=(l+r)/2;
            if (ok(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        if (l==maxx+1)
            puts("-1");
        else
            printf("%d\n",l);
    }
    return 0;
}
