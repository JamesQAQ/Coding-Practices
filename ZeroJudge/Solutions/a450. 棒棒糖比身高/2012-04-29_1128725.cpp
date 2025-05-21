#include <cstdio>
#include <algorithm>

int n,a[1000000];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int searchleft(int x){
    int l=0,r=n-1,mid;
    while (l<=r){
        mid=(l+r)/2;
        if (a[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return r;
}
int searchright(int x){
    int l=0,r=n-1,mid;
    while (l<=r){
        mid=(l+r)/2;
        if (a[mid]<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    return r;
}
int main()
{
    int q,l,r;
    n=input(),q=input();
    for (int i=0;i<n;i++)
        a[i]=input();
    std::stable_sort(a,a+n);
    for (int i=0;i<q;i++){
        l=searchleft(input()),r=searchright(input());
        if (r-l<=0)
            puts("The candies are too short");
        else
            printf("%d\n",r-l);
    }
    //while (1);
}
