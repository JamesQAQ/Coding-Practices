#include <iostream>
using namespace std;

int main()
{
   int a[7490]={1},coin[5]={1,5,10,25,50};
   for (int i=0;i<5;i++)
      for (int j=coin[i];j<7490;j++)
         a[j]+=a[j-coin[i]];
   int n;
   while (cin>>n)
      cout<<a[n]<<endl;
   return 0;
}
