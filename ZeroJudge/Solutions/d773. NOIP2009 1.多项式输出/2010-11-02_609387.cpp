#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int n;
   while (cin>>n)
   {
      int temp;
      cin>>temp;
      if (temp==-1)
         cout<<"-";
      else if (temp!=1)
         cout<<temp;
      cout<<"x^"<<n;
      for (int i=1;i<=n;i++)
      {
         cin>>temp;
         if (temp==0)
            continue;
         if (temp<0)
            cout<<"-";
         else
            cout<<"+";
         if (abs(temp)!=1||i==n)
            cout<<abs(temp);
         if (i<n)
            cout<<"x";
         if (i<n-1)
            cout<<"^"<<n-i;
      }
      cout<<endl;
   }
   return 0;
}
