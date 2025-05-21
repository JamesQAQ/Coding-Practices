#include <iostream>
using namespace std;

unsigned int a[1000000];
int main()
{
   int n;
   while (cin>>n)
   {
      for (int i=0;i<n;i++)
         cin>>a[i];
      stable_sort(a,a+n);
      cout<<a[0];
      for (int i=1;i<n;i++)
         cout<<" "<<a[i];
   }
   return 0;
}
