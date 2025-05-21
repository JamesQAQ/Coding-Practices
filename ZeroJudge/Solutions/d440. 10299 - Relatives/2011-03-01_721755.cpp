#include <iostream>
using namespace std;

int d[1000],dnum,n;
int dfs(int x,int nb,int negative)
{
   int sum=0;
   for (int i=x;i<dnum;i++)
      sum+=n/(d[i]*nb)*negative+dfs(i+1,d[i]*nb,-negative);
   return sum;
}
int main()
{
   bool p[31623]={};
   int prime[20000]={2},pnum=1;
   for (int i=3;i<31623;i+=2)
      p[i]=1;
   for (int i=3;i<31623;i+=2)
      if (p[i])
      {
         prime[pnum++]=i;
         for (int j=i*3;j<31623;j+=2*i)
            p[j]=0;
      }
   while (cin>>n)
   {
      if (n==0)
         break;
      if (n==1)
      {
         cout<<"0"<<endl;
         continue;
      }
      dnum=0;
      int i=0,temp=n;
      while (temp!=1&&i<pnum)
      {
         if (temp%prime[i]==0)
         {
            d[dnum++]=prime[i];
            temp/=prime[i];
            while (temp%prime[i]==0)
               temp/=prime[i];
         }
         i++;
      }
      if (temp!=1)
         d[dnum++]=temp;
      cout<<n-dfs(0,1,1)<<endl;
   }
   return 0;
}
