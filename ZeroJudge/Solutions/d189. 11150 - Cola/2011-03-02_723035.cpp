#include <iostream>
using namespace std;

int main()
{
   int n,ans;
   while (cin>>n)
   {
      ans=n;
      while (n>2)
      {
         int d=n%3;
         n/=3;
         ans+=n;
         n+=d;
      }
      if (n==2)
         ans++;
      cout<<ans<<endl;
   }
   return 0;
}
