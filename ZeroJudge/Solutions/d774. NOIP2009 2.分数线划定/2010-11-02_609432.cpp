#include <iostream>
#include <algorithm>
using namespace std;

int k[5000],s[5000],n,m,t[5000];
bool cmp(int i,int j)
{
   if (s[i]>s[j]) return 1;
   if (s[i]<s[j]) return 0;
   if (k[i]<k[j]) return 1;
   return 0;
}
int main()
{
   while (cin>>n>>m)
   {
      for (int i=0;i<n;i++)
      {
         cin>>k[i]>>s[i];
         t[i]=i;
      }
      stable_sort(t,t+n,cmp);
      m=(int)(1.5*m);
      cout<<s[t[m-1]]<<" ";
      int d=m;
      while (s[t[m-1]]==s[t[d]])
         d++;
      cout<<d<<endl;
      for (int i=0;i<d;i++)
         cout<<k[t[i]]<<" "<<s[t[i]]<<endl;
   }   
   return 0;
}
