#include <cstdio>
#include <cmath>

int limit=500,tmp[600],tmpnum,d=10;
struct BigNumber{
    int a[600],num;
    int init(){
        num=1,a[0]=1;
    }
    void check(){
        for (int i=0;i<num-1;i++)
            if (a[i]>=d){
                a[i+1]+=a[i]/d;
                a[i]%=d;
            }
        while (a[num-1]>=d){
            a[num]=a[num-1]/d;
            a[num-1]%=d;
            if (num==limit)
                break;
            num++;
        }
    }
    void two(){
        for (int i=0;i<num;i++)
            a[i]<<=1;
        check();
    }
    void operator *=(BigNumber b){
        tmpnum=num+b.num-1;
        if (tmpnum>limit) tmpnum=limit;
        for (int i=0;i<tmpnum;i++)
            tmp[i]=0;
        for (int i=0;i<num;i++)
            for (int j=0;j<b.num;j++)
                if (i+j<limit)
                    tmp[i+j]+=a[i]*b.a[j];
        for (int i=0;i<tmpnum;i++)
            a[i]=tmp[i];
        num=tmpnum;
        check();
    }
} ans;
void work(int p){
    ans.init();
    for (int i=1<<22;i>0;i>>=1)
        if (i<p){
            ans*=ans;
            if (i&p)
                ans.two();
        }
    ans.a[0]--;
    int cnt=0;
    for (int i=499;i>=0;i--){
        printf("%d",(i>=ans.num)?0:ans.a[i]);
        cnt++;
        if (cnt==50)
            puts(""),cnt=0;
    }
}
int main()
{
    int p;
    scanf("%d",&p);
    printf("%d\n",(int)(log10(2.0)*p)+1);
    work(p);
}
