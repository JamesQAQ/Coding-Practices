#include <cstdio>

inline unsigned long long pow3(unsigned long long x){
    return x*x*x;
}
inline void work(unsigned long long n){
    int l=1,r=2642245,mid;
    while (l<=r){
        mid=(l+r)/2;
        unsigned long long v=pow3(mid);
        if (v>n)
            r=mid-1;
        else if (v<n)
            l=mid+1;
        else{
            printf("%d\n",mid);
            return;
        }
    }
}
int main()
{
    unsigned long long n;
    while (scanf("%llu",&n)==1)
        work(n);
}
