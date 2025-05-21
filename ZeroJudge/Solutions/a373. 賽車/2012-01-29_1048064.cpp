#include <cstdio>
#include <iostream>
struct Node {int x,v;} car[250100];
struct List {int left,righ;} list[250100];
struct Value {int v1,v2;} v[250100];
double key[250100];
int n,a[250100],b[250100],ans=0,at[250100];
int input(){
    char c=getchar();
    while (c>'9'||c<'0')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c<='9'&&c>='0'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
void merge(int l,int mid,int r){
    for (int i=l;i<=mid;i++)
        b[i]=a[i];
    for (int i=mid+1;i<=r;i++)
        b[i]=a[i];
    int atl=l,atr=mid+1;
    for (int i=l;i<=r;i++){
        if (atl==mid+1)
            a[i]=b[atr++];
        else if (atr==r+1)
            a[i]=b[atl++];
        else if (b[atl]<=b[atr])
            a[i]=b[atl++];
        else{
            ans=(ans+mid+1-atl)%1000000;
            a[i]=b[atr++];
        }
    }
}
void merge_sort(int l,int r){
    if (l==r)
        return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}
struct Heap {
    int num,no[250100];
    bool compar(int i,int j){//i>j
        if (v[i].v1*v[j].v2>v[i].v2*v[j].v1)
            return true;
        if (v[i].v1*v[j].v2<v[i].v2*v[j].v1)
            return false;
        return key[i]>key[j];
    }
    void change(int i,int j){
        std::swap(no[i],no[j]);
        std::swap(at[no[i]],at[no[j]]);
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&compar(no[f],no[x])){
            change(f,x);
            x=f;
            f>>=1;
        }
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&compar(no[s],no[s+1]))
                s++;
            if (compar(no[s],no[x]))
                break;
            change(s,x);
            x=s;
            s<<=1;
        }
    }
    void insert(int x){
        no[++num]=x;
        at[x]=num;
        up(num);
    }
    void update(int x){
        up(x);
        down(x);
    }
    void del(int x){
        change(x,num);
        at[no[num]]=0;
        num--;
        update(x);
    }
}heap;
void build(int x){
    int y=list[x].righ;
    v[x].v1=car[y].x-car[x].x,v[x].v2=car[x].v-car[y].v;
    key[x]=(double)v[x].v1/v[x].v2*car[x].v+car[x].x;
    if (v[x].v2<=0||v[x].v1<=0){
        if (at[x])
            heap.del(at[x]);
    }
    else if (at[x])
        heap.update(at[x]);
    else
        heap.insert(x);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        car[i].x=input();
        car[i].v=input();
    }
    for (int i=1;i<=n;i++)
        a[i]=car[i].v;
    merge_sort(1,n);
    printf("%d\n",ans);
    car[0].x=car[0].v=-1;
    car[n+1].x=1000001,car[n+1].v=101;
    for (int i=0;i<=n+1;i++)
        list[i].left=i-1,list[i].righ=i+1;
    heap.num=0;
    for (int i=0;i<=n;i++){
        if (car[i].v>car[i+1].v){
            v[i].v1=car[i+1].x-car[i].x,v[i].v2=car[i].v-car[i+1].v;
            key[i]=(double)v[i].v1/v[i].v2*car[i].v+car[i].x;
            heap.insert(i);
        }
        else
            at[i]=0;
    }
    for (int i=0;i<10000;i++){
        if (heap.num==0)
            break;
        printf("%d %d\n",heap.no[1],list[heap.no[1]].righ);
        int A=heap.no[1],X=list[A].left,B=list[A].righ,C=list[B].righ;
        list[X].righ=B,list[B].left=X;
        list[B].righ=A,list[A].left=B;
        list[A].righ=C,list[C].left=A;
        heap.del(1);
        build(X);
        build(A);
    }
}
