#include <cstdio>
struct Node {int a,b,c;} f[200000],v[200000];
int num=0,cnt[1000001]={},ans[1000001];
bool use[1000001]={};
int gcd(int m,int n){
    while ((m%=n)&&(n%=m));
    return (m==0)?n:m;
}
struct Heap{
    int num,a[200000];
    void down(int x){
        int s=x<<1,value=a[x];
        while (s<=num){
            if (s<num&&v[a[s]].c>v[a[s+1]].c)
                s++;
            if (v[a[s]].c>=v[value].c)
                break;
            a[x]=a[s];
            x=s;
            s<<=1;
        }
        a[x]=value;
    }
} heap;
int main()
{
    int p,n;
    for (int i=1;(i+1)*(i+1)+i*i<=1000000;i++)
        for (int j=i+1;(p=i*i+j*j)<=1000000;j+=2){
            if (gcd(i,j)>1)
                continue;
            cnt[p]++;
            f[num].c=p,f[num].a=2*i*j,f[num].b=j*j-i*i;
            num++;
        }
    for (int i=2;i<=1000000;i++)
        cnt[i]+=cnt[i-1];
    heap.num=num;
    for (int i=0;i<num;i++)
        heap.a[i+1]=i,v[i]=f[i];
    for (int i=num/2;i>0;i--)
        heap.down(i);
    int sum=0;
    for (int i=1;i<=1000000;i++){
        while (v[heap.a[1]].c==i){
            int top=heap.a[1];
            if (!use[v[top].a])
                sum++,use[v[top].a]=true;
            if (!use[v[top].b])
                sum++,use[v[top].b]=true;
            if (!use[v[top].c])
                sum++,use[v[top].c]=true;
            v[top].a+=f[top].a;
            v[top].b+=f[top].b;
            v[top].c+=f[top].c;
            heap.down(1);
        }
        ans[i]=i-sum;
    }
    while (scanf("%d",&n)==1)
        printf("%d %d\n",cnt[n],ans[n]);
    return 0;
}
