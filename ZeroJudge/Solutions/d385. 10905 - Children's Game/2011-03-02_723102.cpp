#include <iostream>
#include <algorithm>
using namespace std;

string s[50];
int gcd(int m,int n)
{
   if (m<n)
      swap(m,n);
   int temp;
   while (n!=0)
   {
      m%=n;
      temp=m;
      m=n;
      n=temp;
   }
   return m;
}
bool cmp(string a,string b)
{
   int lena=a.length(),lenb=b.length(),mini=lena*lenb/gcd(lena,lenb);
   for (int i=0;i<mini;i++)
   {
      if (a[i%lena]>b[i%lenb])
         return 1;
      if (a[i%lena]<b[i%lenb])
         return 0;
   }
   return 1;
}
int main()
{
   int n;
   while (cin>>n)
   {
      if (n==0)
         break;
      for (int i=0;i<n;i++)
         cin>>s[i];
      stable_sort(s,s+n,cmp);
      for (int i=0;i<n;i++)
         cout<<s[i];
      cout<<endl;
   }
   return 0;
}
