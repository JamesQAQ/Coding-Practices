#include <cstdio>
#include <iostream>
using namespace std;

struct Heap{
    int v[1000],num;
    /*void up(int x){
        int f=x>>1;
        while (f>=1&&v[f]<v[x]){
            swap(v[f],v[x]);
            x=f;
            f>>=1;
        }
    }*/
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&v[s+1]<v[s])
                s++;
            if (v[s]>=v[x])
                break;
            swap(v[s],v[x]);
            x=s;
            s<<=1;
        }
    }
    void pop(){
        printf("%d ",v[1]);
        swap(v[1],v[num]);
        num--;
        down(1);
    }
    void sort(){
        while (num>1)
            pop();
        printf("%d\n",v[num]);
    }
    void create(){
        for (int i=num>>1;i>=1;i--)
            down(i);
    }
}heap;
int main()
{
    while (scanf("%d",&heap.num)==1){
        for (int i=1;i<=heap.num;i++)
            scanf("%d",&heap.v[i]);
        heap.create();
        heap.sort();
    }
    return 0;
}
