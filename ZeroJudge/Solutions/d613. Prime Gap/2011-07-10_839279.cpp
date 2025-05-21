#include <cstdio>

bool p[1300000]={};//1140
int prime[1000000],pnum=1,n;
int search(){
    int l=0,r=pnum,mid;
    while (l<=r){
        mid=(l+r)/2;
        if (n>prime[mid]) l=mid+1;
        else if (n<prime[mid]) r=mid-1;
        else return 0;
    }
    return prime[l]-prime[l-1];
}
int main()
{
    prime[0]=2;
    for (int i=3;i<1300000;i+=2)
        p[i]=true;
    for (int i=3;i<1140;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<1300000;j+=2*i)
                p[j]=false;
        }
    for (int i=1141;i<1300000;i+=2)
        if (p[i])
            prime[pnum++]=i;
    while (scanf("%d",&n),n)
        printf("%d\n",search());
    return 0;
}
