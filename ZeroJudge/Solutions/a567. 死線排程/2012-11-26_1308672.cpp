#include <cstdio>
#include <algorithm>

void swap(int &a,int &b){
    int tmp=a;a=b;b=tmp;
}
struct Homework{
    int d,p;
} hw[10000];
bool cmp(Homework i,Homework j){
    return i.d>j.d;
}
struct Heap{
    int a[200000],num;
    void init(){
        num=0;
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&a[f]<a[x]){
            swap(a[x],a[f]);
            x=f,f>>=1;
        }
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&a[s+1]>a[s])
                s++;
            if (a[s]<=a[x])
                break;
            swap(a[s],a[x]);
            x=s,s<<=1;
        }
    }
    void pop(){
        swap(a[1],a[num]);
        num--;
        down(1);
    }
    void push(int x){
        a[++num]=x;
        up(num);
    }
} heap;
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%d %d",&hw[i].d,&hw[i].p);
        std::stable_sort(hw,hw+n,cmp);
        int at=0,ans=0;
        heap.init();
        for (int i=10000;i>=1;i--){
            while (at<n&&i<=hw[at].d){
                heap.push(hw[at].p);
                at++;
            }
            if (heap.num){
                ans+=heap.a[1];
                heap.pop();
            }
        }
        printf("%d\n",ans);
    }
}
