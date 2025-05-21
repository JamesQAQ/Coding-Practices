#include <cstdio>

int main()
{
    long long A[100],B[100],intmax=(long long)1<<32;
    A[0]=0,B[0]=0;
    for (int i=1;A[i-1]<=intmax&&B[i-1]<=intmax;i++){
        A[i]=0,B[i]=1;
        A[i]+=B[i-1];
        B[i]+=A[i-1]+B[i-1];
    }
    int n;
    while (scanf("%d",&n),n>=0)
        printf("%lld %lld\n",B[n],A[n]+B[n]+1);
}
