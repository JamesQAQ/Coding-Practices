#include <cstdio>
#include <queue>

std::queue <int> Q[10001];
int a[1000000],at[10001],oo=2147483647;
bool inheap[10001];
void swap(int &l,int &r){
    l^=r^=l^=r;
}
struct Heap{
    int v[101],num;
    void change(int l,int r){
        swap(v[l],v[r]);
        swap(at[v[l]],at[v[r]]);
    }
    bool cmp(int l,int r){
        int A=(Q[v[l]].empty())?oo:Q[v[l]].front(),B=(Q[v[r]].empty())?oo:Q[v[r]].front();
        return A>B;
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&cmp(s+1,s))
                s++;
            if (cmp(x,s))
                break;
            change(x,s);
            x=s,s<<=1;
        }
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&cmp(x,f)){
            change(x,f);
            x=f,f>>=1;
        }
    }
    void update(int x){
        up(x);
        down(x);
    }
    void insert(int value){
        inheap[value]=true;
        v[++num]=value;
        at[value]=num;
        up(num);
    }
    void pop(){
        inheap[v[1]]=false;
        change(1,num);
        num--;
        down(1);
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
    int cases,n,m;
    cases=input();
    while (cases--){
        n=input(),m=input();
        for (int i=0;i<n;i++){
            a[i]=input();
            inheap[a[i]]=false;
            Q[a[i]].push(i);
        }
        int ans=0;
        heap.num=0;
        for (int i=0;i<n;i++){
            Q[a[i]].pop();
            if (inheap[a[i]])
                heap.update(at[a[i]]);
            else if (heap.num<m)
                heap.insert(a[i]);
            else{
                ans++;
                heap.pop();
                heap.insert(a[i]);
            }
        }
        printf("%d\n",ans);
    }
}
