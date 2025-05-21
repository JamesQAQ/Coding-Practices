#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int n,match[200],num[200];
bool ok[200][200],v[200];
double eps=1e-6;
bool ppt(int aa,int bb){
   long long a=(long long)aa,b=(long long)bb,sum=a*a+b*b;
   //printf("%I64d %I64d %I64d\n",a,b,sum);
   double cc=sqrt(sum)+eps;
   long long c=(long long)cc;
   return sum==c*c;
}
bool find(int x){
   for (int i=0;i<n;i++)
      if (ok[x][i]&&!v[i]){
         v[i]=1;
         if (match[i]==-1||find(match[i])){
            match[i]=x;
            return true;
         }
      }
   return false;
}
int gcd(int m,int n){
   if (n>m)
      swap(n,m);
   while (n!=0){
      m%=n;
      swap(n,m);
   }
   return m;
}
int main()
{
   while (scanf("%d",&n)==1){
      for (int i=0;i<n;i++)
         scanf("%d",&num[i]);
      for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
            ok[i][j]=0;
      for (int i=0;i<n;i++)
         for (int j=i+1;j<n;j++)
            if (((long long)num[i]*(long long)num[j])%2==0&&gcd(num[i],num[j])==1&&ppt(num[i],num[j])){
               //printf("%d %d\n",num[i],num[j]); 
               ok[i][j]=ok[j][i]=1;
            }
      for (int i=0;i<n;i++)
         match[i]=-1;
      int ans=0;
      for (int i=0;i<n;i++)
         if (num[i]%2){
            for (int j=0;j<n;j++)
               v[j]=0;
            if (find(i))
               ans++;
         }
      printf("%d\n",ans);
   }   
   return 0;
}
