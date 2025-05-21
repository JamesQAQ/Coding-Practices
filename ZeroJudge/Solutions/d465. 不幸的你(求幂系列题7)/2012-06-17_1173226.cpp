#include <cstdio>

int mod=10000;
int tmpnum,safe=10,cut[4]={1,10,100,1000};
long long tmp[100000];
struct Node{
    int num;
    long long a[100000];
    void get(int v){
        num=0;
        while (v){
            a[num++]=v%mod;
            v/=mod;
        }
    }
    void check(){
        for (int i=0;i<num;i++)
            if (a[i]>=mod){
                a[i+1]+=a[i]/mod;
                a[i]%=mod;
            }
        while (a[num-1]==0)
            num--;
    }
    void operator *=(Node b){
        tmpnum=num+b.num+safe;
        for (int i=0;i<tmpnum;i++)
            tmp[i]=0;
        for (int i=0;i<num;i++)
            for (int j=0;j<b.num;j++)
                tmp[i+j]+=a[i]*b.a[j];
        for (int i=0;i<tmpnum;i++)
            a[i]=tmp[i];
        num=tmpnum;
        check();
    }
    void print(int I,int k){
        int at=1,st;
        for (int i=3;i>=0;i--)
            if (a[num-1]>=cut[i]){
                st=i;
                break;
            }
        for (int i=st;i>=0;i--){
            int v=a[num-1]/cut[i];
            if (at>=I+k)
                return;
            if (at>=I)
                printf("%d",v);
            a[num-1]-=v*cut[i];
            at++;
        }
        for (int i=num-2;i>=0;i--)
            for (int j=3;j>=0;j--){
                int v=a[i]/cut[j];
                if (at>=I+k)
                    return;
                if (at>=I)
                    printf("%d",v);
                a[i]-=v*cut[j];
                at++;
            }
    }
    void init(){
        a[0]=1;
        num=1;
    }
} ans,a;

int main()
{
    int v,n,l,r;
    while (scanf("%d %d %d %d",&v,&n,&l,&r)==4){
        a.get(v);
        ans.init();
        for (int i=1<<15;i>0;i>>=1){
            ans*=ans;
            if (i&n)
                ans*=a;
        }
        ans.print(l,r);
        puts("");
        //ans.print();
    }
}
