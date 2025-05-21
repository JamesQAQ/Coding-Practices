#include <cstdio>

long long R[2000],C[2000];
long long input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return (long long)x;
}
int main()
{
    int cases,n,m;
    long long tmp;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            R[i]=0;
        for (int i=0;i<m;i++)
            C[i]=0;
        long long sum=0,all=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                tmp=input();
                all+=tmp;
                sum+=tmp*(i+j);
                R[i]+=tmp;
                C[j]+=tmp;
            }
        long long ans=-1;
        int ansx,ansy;
        long long unum=0,dnum=all;
        for (int i=0;i<n;i++){
            long long tmpsum=sum;
            long long lnum=0,rnum=all;
            for (int j=0;j<m;j++){
                if (ans==-1||tmpsum<ans)
                    ans=tmpsum,ansx=i+1,ansy=j+1;
                lnum+=C[j];
                rnum-=C[j];
                tmpsum-=rnum;
                tmpsum+=lnum;
            }
            unum+=R[i];
            dnum-=R[i];
            sum-=dnum;
            sum+=unum;
        }
        printf("%d %d\n%lld\n",ansx,ansy,ans*100);
    }
}
/*
9
3 4
4 2 0 1
0 1 1 0
1 0 0 3
*/
