#include <cstdio>

int L[100002],R[100002],at[100002];
long long value[100002];
void swap(int &a,int &b){
    a^=b^=a^=b;
}
struct Heap{
    int a[100002],num;
    void change(int i,int j){
        swap(a[i],a[j]);
        swap(at[a[i]],at[a[j]]);
    }
    void init(){
        num=0;
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&value[a[x]]<value[a[f]]){
            change(x,f);
            x=f,f>>=1;
        }
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&value[a[s+1]]<value[a[s]])
                s++;
            if (value[a[x]]<=value[a[s]])
                break;
            change(x,s);
            x=s,s<<=1;
        }
    }
    void insert(int x){
        a[++num]=x;
        at[x]=num;
        up(num);
    }
    void del(int x){
        change(x,num);
        num--;
        if (x>num)
            return;
        up(x);
        down(x);
    }
} heap;
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int N,K,location[100002];
    N=input(),K=input();
    for (int i=1;i<=N;i++)
        location[i]=input();
    heap.init();
    for (int i=1;i<N;i++)
        value[i]=location[i+1]-location[i];
    value[0]=2147483647;
    value[N]=2147483647;
    for (int i=0;i<=N;i++){
        L[i]=i-1,R[i]=i+1;
        heap.insert(i);
    }
    int ans=0;
    while (K--){
        int x=heap.a[1],l=L[x],r=R[x];
        ans+=value[x];
        heap.del(at[x]);
        heap.del(at[r]);
        value[l]+=value[r]-value[x];
        R[l]=R[r];
        L[R[r]]=l;
        heap.up(at[l]);
        heap.down(at[l]);
    }
    printf("%d\n",ans);
}
