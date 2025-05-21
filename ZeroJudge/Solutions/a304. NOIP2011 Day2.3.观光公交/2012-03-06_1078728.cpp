#include <cstdio>

struct Node {int t,a,b;} people[10000];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int n,m,k,t,a,b,wait[1001]={},enter[1001],ans=0,g[1001],sum[1001]={},d[1001];
    n=input(),m=input(),k=input();
    for (int i=1;i<n;i++)
        d[i]=input();
    for (int i=0;i<m;i++){
        people[i].t=input(),people[i].a=input(),people[i].b=input();
        if (people[i].t>wait[people[i].a]) wait[people[i].a]=people[i].t;
        sum[people[i].b]++;
    }
    for (int i=2;i<=n;i++)
        sum[i]+=sum[i-1];
    enter[1]=0;
    for (int i=2;i<=n;i++)
        enter[i]=d[i-1]+((enter[i-1]>wait[i-1])?enter[i-1]:wait[i-1]);
    g[n-1]=n,g[n]=n;
    for (int i=n-2;i>=1;i--)
        g[i]=(enter[i+1]>wait[i+1])?g[i+1]:i+1;
    for (int t=0;t<k;t++){
        int at=-1,maxx;
        for (int i=1;i<n;i++)
            if (d[i]>0&&(at==-1||maxx<sum[g[i]]-sum[i])){
                at=i;
                maxx=sum[g[i]]-sum[i];
            }
        if (at==-1)
            break;
        d[at]--;
        for (int i=at+1;i<=g[at];i++)
            enter[i]=d[i-1]+((enter[i-1]>wait[i-1])?enter[i-1]:wait[i-1]);
        for (int i=g[at]-1;i>=at;i--)
            g[i]=(enter[i+1]>wait[i+1])?g[i+1]:i+1;
    }
    for (int i=0;i<m;i++)
        ans+=enter[people[i].b]-people[i].t;
    printf("%d\n",ans);
}
