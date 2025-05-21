#include <iostream>
using namespace std;

int p[1000000],sum[1000000];
int search(int x){
   return (x==p[x])?x:p[x]=search(p[x]);
}
int main()
{
   int n,m,a,b;
   while (scanf("%d %d",&n,&m)==2){
      for (int i=0;i<n;i++){
         sum[i]=1;
         p[i]=i;
      }
      for (int i=0;i<m;i++){
         scanf("%d %d",&a,&b);
         int bossa=search(a),bossb=search(b);
         if (bossa!=bossb){
            sum[bossa]+=sum[bossb];
            p[bossb]=bossa;
            sum[bossb]=0;
         }
      }
      int ans=0;
      for (int i=0;i<n;i++)
         ans=max(ans,sum[i]);
      printf("%d\n",ans);
   }
   return 0;
}
