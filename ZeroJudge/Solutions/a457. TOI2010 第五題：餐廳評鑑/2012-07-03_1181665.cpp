#include <cstdio>
#include <algorithm>

struct score{int a,b;} rst[100000],*p[100000];
int tree[100001]={},cnt=0,*pp[100000];
bool cmp(score *i,score *j){
    if ((i->a)!=(j->a))
        return (i->a)<(j->a);
    return (i->b)<(j->b);
}
bool cmp2(int *i,int *j){
    return (*i)<(*j);
}
int query(int x){
    int sum=0;
    while (x>0){
        sum+=tree[x];
        x-=x&(-x);
    }
    return sum;
}
void update(int x){
    while (x<=cnt){
        tree[x]++;
        x+=x&(-x);
    }
}
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int k,m;
    k=input(),m=input();
    for (int i=0;i<k;i++)
        rst[i].a=input();
    for (int i=0;i<k;i++)
        rst[i].b=input(),p[i]=&rst[i];
    std::stable_sort(p,p+k,cmp);
    for (int i=0;i<k;i++)
        pp[i]=&rst[i].b;
    std::stable_sort(pp,pp+k,cmp2);
    int f=-1;
    for (int i=0;i<k;i++){
        if ((*pp[i])!=f){
            f=(*pp[i]);
            cnt++;
        }
        (*pp[i])=cnt;
    }
    long long ans=0;
    for (int i=k-1;i>=0;i--){
        ans+=(long long)query((p[i]->b)-1);
        update(p[i]->b);
    }
    printf("%lld\n",ans);
    //while (1);
}
