#include <cstdio>

struct Heap{
    int a[50000],num;
    void up(int x){
        int f=x>>1,v=a[x];
        while (f>=1&&a[f]<v)
            a[x]=a[f],x=f,f>>=1;
        a[x]=v;
    }
    void down(int x){
        int s=x<<1,v=a[x];
        while (s<=num){
            if (s<num&&a[s+1]>a[s])
                s++;
            if (a[s]<=v)
                break;
            a[x]=a[s],x=s,s<<=1;
        }
        a[x]=v;
    }
    void insert(int v){
        a[++num]=v;
        up(num);
    }
    void init(){
        num=0;
    }
    void pop(){
        a[1]=a[num--];
        down(1);
    }
} heap;
int input(){
    char c=getchar();
    while (c!='-'&&(c>'9'||c<'0')) c=getchar();
    bool negative=(c=='-');
    int x=(negative)?0:c-48;
    c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return (negative)?-x:x;
}
int main()
{
    int cases,n,m,tmp,v;
    cases=input();
    for (int t=1;t<=cases;t++){
        printf("Case %d:\n",t);
        n=input(),m=input();
        heap.init();
        for (int i=0;i<n;i++)
            heap.insert(input());
        for (int i=0;i<m;i++){
            tmp=input();
            if (tmp==1)
                heap.insert(input());
            else{
                if (heap.num)
                    printf("Max: %d\n",heap.a[1]),heap.pop();
                else
                    puts("It's empty!");
            }
        }
        if (heap.num==0)
            puts("It's empty!");
        else{
            bool first=true;
            while (heap.num){
                if (first) first=false;
                else putchar(' ');
                printf("%d",heap.a[1]);
                heap.pop();
            }
            puts("");
        }
    }
}
