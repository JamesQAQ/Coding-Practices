#include <cstdio>
#include <algorithm>

int n,k,a[100001],t[100001],sum[100001];
bool cmp(int i,int j){
    if (sum[i]<sum[j]) return true;
    if (sum[i]>sum[j]) return false;
    return i<j;
}
int input(){
    char c=getchar();
    while (c!='-'&&(c>'9'||c<'0')) c=getchar();
    bool negative=(c=='-');
    int x=(negative)?0:c-48;
    c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return (negative)?-x:x;
}
int search(int v){
    int l=0,r=n-1,mid;
    while (l<=r){
        mid=(l+r)/2;
        if (sum[t[mid]]>=v)
            r=mid-1;
        else
            l=mid+1;
    }
    if (sum[t[l]]!=v)
        return -1;
    return t[l];
}
int main()
{
    while (scanf("%d",&n),n){
        for (int i=1;i<=n;i++)
            a[i]=input();
        k=input();
        for (int i=1;i<=n;i++){
            t[i]=i,sum[i]=((long long)sum[i-1]+a[i])%k;
            if (sum[i]<0)
                sum[i]+=k;
        }
        sum[0]=0,t[0]=0;
        std::stable_sort(t,t+n+1,cmp);
        int ansx=-1,ansy;
        for (int i=1;i<=n;i++){
            int L=search(sum[t[i]])+1;
            if (L==0)
                continue;
            if (L<=t[i]){
                if (ansx==-1||(L<ansx||(L==ansx&&t[i]<ansy)))
                    ansx=L,ansy=t[i];
            }
        }
        if (ansx==-1)
            puts("no solutions.");
        else
            printf("%d %d\n",ansx,ansy);
    }
}
