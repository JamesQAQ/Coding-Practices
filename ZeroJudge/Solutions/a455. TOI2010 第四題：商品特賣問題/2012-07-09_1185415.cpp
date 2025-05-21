#include <cstdio>
#include <algorithm>

int m,box[50],boxsum=0,a[1001],b[50],sum[1001],mid,space;
bool dfs(int x,int d){
    //printf("dfs %d %d %d\n",x,d,notspace);
    if (x==-1)
        return true;
    if (boxsum-space<sum[mid-1])
        return false;
    for (int i=m-1;i>=d;i--)
        if (b[i]>=a[x]){
            b[i]-=a[x];
            if (b[i]<a[0])
                space+=b[i];
            if (a[x]==a[x-1]){
                if (dfs(x-1,i))
                    return true;
            }
            else if (dfs(x-1,0))
                return true;
            if (b[i]<a[0])
                space-=b[i];
            b[i]+=a[x];
        }            
    return false;
}
int main()
{
    int n;
    scanf("%d %d",&m,&n);
    for (int i=0;i<m;i++)
        scanf("%d",&box[i]),boxsum+=box[i];
    std::stable_sort(box,box+m);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::stable_sort(a,a+n);
    sum[0]=a[0];
    for (int i=1;i<n;i++)
        sum[i]=sum[i-1]+a[i];
    int l=0,r=n;
    while (l<=r){
        mid=(l+r)/2;
        space=0;
        for (int i=0;i<m;i++)
            b[i]=box[i];
        if (dfs(mid-1,0))
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",r);
    //while (1);
}
