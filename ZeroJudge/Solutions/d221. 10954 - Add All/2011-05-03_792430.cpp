#include <cstdio>
#include <iostream>
using namespace std;

struct Heap{
   int num;
   long long h[5001];
   void up(int x){
      int f=x>>1;
      while (f>=1&&h[f]>h[x]){
         swap(h[f],h[x]);
         x=f;
         f>>=1;
      }
   }
   void down(int x){
      int s=x<<1;
      while (s<=num){
         if (s<num&&h[s]>h[s+1])
            s++;
         if (h[s]>=h[x])
            break;
         swap(h[s],h[x]);
         x=s;
         s<<=1;
      }
   }
   void del(int x){
      swap(h[x],h[num]);
      num--;
      up(x);
      down(x);
   }
   void insert(long long v){
      num++;
      h[num]=v;
      up(num);
   }
   void make(){
      for (int i=num>>1;i>=1;i--)
         down(i);
   }
}heap;
int main()
{
   while (scanf("%d",&heap.num)){
      if (heap.num==0)
         break;
      for (int i=1;i<=heap.num;i++)
         scanf("%lld",&heap.h[i]);
      heap.make();
      long long ans=0;
      while (heap.num>1){
         int s=2;
         if (s<heap.num&&heap.h[s]>heap.h[s+1])
            s++;
         long long temp=heap.h[1]+heap.h[s];
         ans+=temp;
         heap.del(1);
         heap.del(1);
         heap.insert(temp);
      }
      printf("%lld\n",ans);
   }
   return 0;
}
