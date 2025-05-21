#include <cstdio>
#include <cmath>
#include <algorithm>

int sum[100001],shift=2;
double s,d[3];
double area(double a,double b,double c){
    d[0]=a,d[1]=b,d[2]=c;
    std::stable_sort(d,d+3);
    if (d[0]+d[1]<=d[2])
        return .0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    int cases,n,tmp;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        sum[0]=0;
        for (int i=1;i<=n;i++)
            scanf("%d",&tmp),sum[i]=sum[i-1]+tmp;
        s=(double)sum[n]/2;
        double limit=sum[n]/3;
        int st,ed;
        for (int i=1;i<=n;i++)
            if (sum[i]>limit){
                st=i;
                break;
            }
        for (int i=n;i>=1;i--)
            if (sum[n]-sum[i-1]>limit){
                ed=i;
                break;
            }
        double ans=.0;
        for (int i=st-shift;i<=st+shift;i++)
            for (int j=ed-shift;j<=ed+shift;j++)
                if (i<j-1){
                    double v=area(sum[i],sum[j-1]-sum[i],sum[n]-sum[j-1]);
                    if (v>ans)
                        ans=v;
                }
        printf("%.2lf\n",ans);
    }
}
