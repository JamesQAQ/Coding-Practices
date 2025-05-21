#include <cstdio>
#include <algorithm>

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
struct Heap {
    int a[30001],num;
    void up(int x){
        int f=x>>1,v=a[x];
        while (f>=1&&a[f]>v)
            a[x]=a[f],x=f,f>>=1;
        a[x]=v;
    }
    void down(int x){
        int s=x<<1,v=a[x];
        while (s<=num){
            if (s<num&&a[s+1]<a[s])
                s++;
            if (a[s]>v)
                break;
            a[x]=a[s],x=s,s<<=1;
        }
        a[x]=v;
    }
    void pop(){
        a[1]=a[num--];
        down(1);
    }
    void push(int v){
        a[++num]=v;
        up(num);
    }
} heap;
struct Node {int a,b;} s[30000];
bool cmp(Node i,Node j){
    return i.b<j.b;
}
int main()
{
    int n,y,a,b,top;
    while (scanf("%d %d",&n,&y)==2){
        int maxx=0,cnt=0;
        top=0;
        for (int i=0;i<n;i++){
            a=input(),b=input();
            if (b-a<=y)
                s[top].a=a,s[top++].b=b;
        }
        std::stable_sort(s,s+top,cmp);
        int at=0;
        heap.num=0;
        for (int i=1;i<=100000;i++){
            while (heap.num&&heap.a[1]<i)
                heap.pop();
            while (at<top&&s[at].b<=i+y){
                heap.push(s[at].a);
                at++;
            }
            if (heap.num>maxx)
                maxx=heap.num,cnt=0;
            if (heap.num==maxx)
                cnt++;
        }
        printf("%d %d\n",cnt,maxx);
    }
}
